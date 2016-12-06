GPIO_Digital_Input(&GPIO_PORTE_AHB_DATA_BITS, _GPIO_PINMASK_0);
GPIO_Digital_Output(&GPIO_PORTA_AHB, _GPIO_PINMASK_ALL);
GPIO_Digital_Output(&GPIO_PORTB_AHB, _GPIO_PINMASK_ALL);
GPIO_Digital_Output(&GPIO_PORTC_AHB, _GPIO_PINMASK_ALL);
GPIO_Digital_Output(&GPIO_PORTD_AHB, _GPIO_PINMASK_ALL);

// Clear ports
GPIO_PORTA_AHB_DATA = 0;
GPIO_PORTB_AHB_DATA = 0;
GPIO_PORTC_AHB_DATA = 0;
GPIO_PORTD_AHB_DATA = 0;

int sayi=0,kalan=5,bolum,sayac=3;
int dizi[4];


void main() {

    if (Button(&GPIO_PORTE_AHB_DATA, 0, 1, 1))
    {
           sayi++;
        do {
          if(kalan==5)
          {
              kalan=sayi%2;
              bolum=sayi/2;
              dizi[sayac]=kalan;
              sayac--;
          }else{
              kalan=bolum%2;
              bolum=bolum/2;
              dizi[sayac]=kalan;
              sayac--;
          }


        } while(bolum>=1 && sayi<=15);

            GPIO_PORTA_AHB_DATA = dizi[0];
            GPIO_PORTB_AHB_DATA = dizi[1];
            GPIO_PORTC_AHB_DATA = dizi[2];
            GPIO_PORTD_AHB_DATA = dizi[3];
   }
  
}