//Buton ve LED pinlerini belirtelim.
const int  buttonPin = 2;

// Algoritma için değişkenler belirtelim
int buttonPushCounter = 0;   // Sayaç
int buttonState = 0;         // Butonun şimdiki durumu
int lastButtonState = 0;     // Butonun bir önceki durumu
int basamakSayaci;
int otelenenSayi;
int sonİslem;

int basamaklar[4];

void setup() {
  
  //Çıkış ve giriş pinlerini belirtelim.
  pinMode(buttonPin, INPUT);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
}

void ledleriYak() {
  
  // Bu fonksiyonu void loop() altından çağıracağız,
  // Basamak değerlerini tutmuştuk şimdi bunları lede aktarıyoruz
  digitalWrite(13, basamaklar[0]);
  digitalWrite(12, basamaklar[1]);
  digitalWrite(11, basamaklar[2]);
  digitalWrite(10, basamaklar[3]);  
}

void sayaciArttir() {
  
  buttonPushCounter++;
  for(basamakSayaci=3;basamakSayaci>=0;basamakSayaci--){
    otelenenSayi = buttonPushCounter>>basamakSayaci;
    if(otelenenSayi & 1){
      basamaklar[basamakSayaci]=1;
    }else{
      basamaklar[basamakSayaci]=0;
    }
    ledleriYak();
  }
}

void sayaciAzalt() {
  
  buttonPushCounter--;
  for(basamakSayaci=3;basamakSayaci>=0;basamakSayaci--){
    otelenenSayi = buttonPushCounter>>basamakSayaci;
    if(otelenenSayi & 1){
      basamaklar[basamakSayaci]=1;
    }else{
      basamaklar[basamakSayaci]=0;
    }
    ledleriYak();
  }
  
}

void loop() {
  
  // Butonun şimdiki durumunu okuyalım. Açık mı kapalı mı?
  buttonState = digitalRead(buttonPin);

  // Butonun şimdiki durumunu eski durumuyla karşılaştırıyoruz.
  // Buton eski haliyle aynı değeri vermiyorsa butona dokunulmuştur.
  if (buttonState != lastButtonState) {
    
    // Butonda değişiklik oldu ama hangi durumdan hangi duruma geçti
    // İletimdeyken iletimden çıktıysa hiçbir şey yapmayacağız
    // Bizim için önemli olan iletimde değildeyken, iletime geçmesi durumu
    // Yani butona basılması.
    if (buttonState == HIGH) {

      // Butondan gelen değer 15 den küçükse sayaç 15 e kadar artacak;
      // Butondan gelen değer 15 ise sayaç 0 a kadar azalmaya başlayacak.
      // Her 15 te bir döngü tersine dönmeli
      // İlk 15 te artırıp, sonraki 15 te azaltmalı
      // Farklı algoirtmalar ile kontrol edebilirsiniz, ben şöyle düşündüm:
      // Buton değeri 0 ve 15 e geldiğinde döngü yönü değişsin

          if(buttonPushCounter==0){
            donguYonu=1; //artıracak
          }else if(buttonPushCounter==15){
            donguYonu=0; //azaltacak
          }
          //Döngü yönüne göre fonksiyon çağırıyoruz.

          if(donguYonu==1){
            sayaciArtir();            
          }else{
            sayaciAzalt();
          }          
      
    } else {
    }
    delay(50);
  }
  
  // Butonun son durumunu değişkenimizde tutalım
  // Her döngüde bir önceki durumla karşılaştırdığımız için lazım oluyor
  lastButtonState = buttonState;
}









