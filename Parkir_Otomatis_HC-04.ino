/*
 * project kang parkir otomatis
 * last edited : 3 Oktober 2020
 * create by : IDNmakerspace Algorithma Factory
 */

//mendefinisikan penggunaan pin
 #define pinecho 10
 #define pintrigger 11
 #define pinbuzzer 12

 //definisi penggunaan databyte
int jarakmin = 10;
long durasi, jarak;
 
void setup() {
  //definisi komunikasi rate serial
  Serial.begin(9600);

  //pemberian fungsi pada pin
  pinMode(pinecho, INPUT);
  pinMode(pintrigger, OUTPUT);
  pinMode(pinbuzzer, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(pintrigger, LOW);
  delayMicroseconds(2);
  digitalWrite(pintrigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(pintrigger, LOW);

  //menampilaknhasi dari pinecho
  durasi = pulseIn(pinecho, HIGH);

  //fungsi untuk mendapatkan nilai jarak
  jarak = durasi/58.2;

  //menampilkan data pada serial monitor
  Serial.print("data jarak : ");
  Serial.println(jarak);

  //membuat logika pada program untuk sistem parkir
  //buzzer berbunyi ketika jarak sama dengan atau kurang dari 10 cm 
  if(jarak <= 10)
  {
    digitalWrite(pinbuzzer, HIGH);
    Serial.println("stop");
    delay(1000);
  }

  //selain memenuhi syarat if diatas maka buzzer mati
  else
  {
    digitalWrite(pinbuzzer, LOW);
    Serial.println("masih aman");
    delay(1000);
  }
}
