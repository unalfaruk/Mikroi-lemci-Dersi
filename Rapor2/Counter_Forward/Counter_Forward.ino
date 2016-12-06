//Buton ve LED pinlerini belirtelim.
const int  buttonPin = 2;

// Algoritma için değişkenler belirtelim
int buttonPushCounter = 0;   // Sayaç
int buttonState = 0;         // Butonun şimdiki durumu
int lastButtonState = 0;     // Butonun bir önceki durumu
int basamakSayaci;
int otelenenSayi;

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
    if (buttonState == HIGH && buttonPushCounter<=15) {
      
      //Eğer butondan gelen değer varsa
      //Sayacı artır
      buttonPushCounter++;
      
      // Şimdi geldik BCD den Binary sisteme çevirmeye.
      // Bunun için "Left/Right Shift Operator" ve bit seviyesinde karşılaştırma yapan
      // "&" operatörünü kullanacağız.
      // Left/Right Shift operatörü için YouTube'de güzel bir video var.
      // https://www.youtube.com/watch?v=BKzB6gdRyIM&t=185s
      
        
      // Bizim örneğimizde sadece 4 bit yeterli olacağı için döngüyü 4 defa döndürmemiz yetecek,
      // Shift yani kaydırma işlemi ve ardından karşılaştırma işlemi yaparak
      // Sayının binary karşılığında hangi basamaklarda 1 rakamı var tespit edeceğiz.       
      for(basamakSayaci=3;basamakSayaci>=0;basamakSayaci--){
        
        // Sayıyı binary olarak öteleyelim ve yeni bir değişkene atalım.
        otelenenSayi = buttonPushCounter>>basamakSayaci;
        
        // otelenenSayi değişkeninin "&" işlemi kullanarak 1 yani 0001 ile çarpalım
        // Öteleme işlemini şunun için yaptık:
        // Her basamağı öteleyerek en sağa alıyoruz, ve en sağdaki değer 1 se bunu tespit edip
        // Hafızada tutuyoruz.          
        if(otelenenSayi & 1){
          basamaklar[basamakSayaci]=1;
        }else{
          basamaklar[basamakSayaci]=0;
        }
        
        //ledleriYak() fonksiyonumuz çalışsın.
        ledleriYak();

      
      }
            
    // Eğer butondan gelen değer yoksa, yani butona basılmamış ise
    // Butondan elimizi çekiyoruz durumu olarak da düşünebilirsiniz
    // Buton açık duruma geçiyor
    // Veya başka ihtimaller varsa onları da dahil ediyoruz. 
    } else {
      // Hiç bir şey yapmayacağız
      // Boş bırakalım.
    }
    // 50 milisaniye bekletelim
    // Art arda basıldığına oluşabilecek çakışma ihtimalleri için
    delay(50);
  }
  
  // Butonun son durumunu değişkenimizde tutalım
  // Her döngüde bir önceki durumla karşılaştırdığımız için lazım oluyor
  lastButtonState = buttonState;
}









