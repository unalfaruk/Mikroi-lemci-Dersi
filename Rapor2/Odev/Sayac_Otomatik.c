// PE0 pinini giriş olarak alıyoruz.
GPIO_Digital_Input(&GPIO_PORTE_AHB_DATA_BITS, _GPIO_PINMASK_0); 
// Çıkışları ayarlıyoruz, port port.
GPIO_Digital_Output(&GPIO_PORTA_AHB, _GPIO_PINMASK_ALL);
GPIO_Digital_Output(&GPIO_PORTB_AHB, _GPIO_PINMASK_ALL);
GPIO_Digital_Output(&GPIO_PORTC_AHB, _GPIO_PINMASK_ALL);
GPIO_Digital_Output(&GPIO_PORTD_AHB, _GPIO_PINMASK_ALL);

// Portlarda çıkış varsa iptal ediyoruz.
GPIO_PORTA_AHB_DATA = 0;
GPIO_PORTB_AHB_DATA = 0;
GPIO_PORTC_AHB_DATA = 0;
GPIO_PORTD_AHB_DATA = 0;

// Değişkenleri belirliyoruz
//c: basamak sayacı
//k: öteleme sonucu elde edilen binary sayı
unsigned int c,k,bcd=0;
// Dizi açtık, basamakları tutmak için.
int status[4],donguYonu;

void led() {
  // Ana fonksiyondan çağırıp portlara çıkış verdiğimiz fonksiyon
  GPIO_PORTA_AHB_DATA = status[3];
  GPIO_PORTB_AHB_DATA = status[2];
  GPIO_PORTC_AHB_DATA = status[1];
  GPIO_PORTD_AHB_DATA = status[0];
}

void sayaciArttir() {
  
  bcd++;
  for(c=3;c>=0;c--){
    k = bcd>>c;
    if(k & 1){
      status[c]=1;
    }else{
      status[c]=0;
    }
    led();
  }
}

void sayaciAzalt() {
  
  bcd--;
  for(c=3;c>=0;c--){
    k = bcd>>c;
    if(k & 1){
      status[c]=1;
    }else{
      status[c]=0;
    }
    led();
  }
  
}

void main() {  
  
  
    if (Button(&GPIO_PORTE_AHB_DATA, 0, 1, 1)) // PE0 pininden giriş var mı kontrol edelim
    {
	      if(bcd==0){
	        donguYonu=1; //artıracak
	      }else if(bcd==15){
	        donguYonu=0; //azaltacak
	      }
	      //Döngü yönüne göre fonksiyon çağırıyoruz.

	      if(donguYonu==1){
	        sayaciArtir();            
	      }else{
	        sayaciAzalt();
	      }                           //Döngü koşulu.
    }   


}