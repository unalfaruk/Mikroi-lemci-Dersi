void setup() { 
  //LED bağlanan bacakları çıkış olarak ayarla.
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  //i değişkeni belirleyelim.
  int i;
}

void loop() {
  //LED pinlerini döngüye alıyoruz.
  for(i=10;i<=13;i++){
    //Her döngüde tüm LED leri söndürelim.
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    //Döngü sonunda sıradaki LED i yakalım.
    digitalWrite(i, HIGH);
    //Bekleyelim.
    delay(2000);
  }
  //En sağdaki LED yandıktan sonra şimdi sola doğru sırayla yakalım.
  //En sağdaki pin zaten yanıyor olduğu için bir solundaki LED den başlayalım
  //En soldaki LED üstteki döngüye girdiğinde yanıyor olacağından bu döngüde o LED i de yakmayalım.
  //En sol ve sağdaki ledlerin diğer ledlere göre uzun süre yanması problem değilse bu ayarları
  //yapmanıza gerek yok  
  for(i=12;i>=11;i--){
    //Her döngüde tüm LED leri söndürelim.
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    //Döngü sonunda sıradaki LED i yakalım.
    digitalWrite(i, HIGH);
    //Bekleyelim.
    delay(2000);
  }              
}
