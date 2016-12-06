//Buton pinini tanımla.
const int buttonPin = 7;
//Led pinini tanımla.
const int ledPin =  13; 

//Butonun durumunu tuttuğumuz bir değişken oluştur. 
int buttonState = 0;

void setup() {
  //Led pinini çıkış olarak ayarla.
  pinMode(ledPin, OUTPUT);
  //Buton pinini giriş olarak ayarla.
  pinMode(buttonPin, INPUT);
}

void loop() {
  //Butondan gelen dijital veriyi oku.
  //Burada buton pinine topraktan geliniyorsa 0;
  //Herhangi bir gerilimden geliniyorsa 1 sonucu döner.
  buttonState = digitalRead(buttonPin);

  //Buton durumunu kontrol edelim.
  //Buton aktifse yani gerilimden pine değer geliyorsa,
  if (buttonState == HIGH) {
    //Pine çıkış ver.
    digitalWrite(ledPin, HIGH);
  } else {
    //Pine topraktan değer geliyorsa ledi söndür.
    digitalWrite(ledPin, LOW);
  }
}
