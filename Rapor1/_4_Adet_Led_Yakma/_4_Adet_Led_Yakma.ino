void setup() { 
  //LED bağlanan bacakları çıkış olarak ayarla.
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() {
  //LED leri yak.  
  digitalWrite(13, HIGH); 
  digitalWrite(12, HIGH);  
  digitalWrite(11, HIGH);  
  digitalWrite(10, HIGH); 
  //Bekleme süresini ayarla
  delay(2000);
  //LED leri söndür.                  
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(11, LOW);
  digitalWrite(10, LOW);
  //Bekleme süresini ayarla. 
  delay(2000);                      
}
