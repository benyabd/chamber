#include <NewPing.h>
#define TRIGGER_PIN 2
#define ECHO_PIN    4
#define MAX_DISTANCE 200

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

int jarak=0;
void setup() {
  pinMode(2, OUTPUT);
  Serial.begin(9600); //untuk membaca/menampilkan pembacaan
  
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(50); //jeda pembacaan ping sensor, idealnya sekitar 29ms
  jarak=sonar.ping_cm();    //variabel pembacaan kita simpan di variable jarak
  if(jarak==0)          //handle error zero
  jarak=50;
  if(jarak<10){
    Serial.print("Semprot");
    digitalWrite(2, HIGH);
    delay(5000);
    digitalWrite(2, LOW);
    delay(5000);
  }
  if(jarak>10){
    Serial.print("Close");
    digitalWrite(2, LOW);
  }
  Serial.print("jarak =");
  Serial.print(jarak);
  Serial.println("cm");
}
