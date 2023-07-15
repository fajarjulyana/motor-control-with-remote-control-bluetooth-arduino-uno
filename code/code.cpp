/*
coded by Fajar Julyana

*/
#include <SoftwareSerial.h>
#include <AFMotor.h>

SoftwareSerial btSerial(A0, A1);
AF_DCMotor banKiriAtas(1); 
AF_DCMotor banKiriBawah(2);
AF_DCMotor banKananBawah(3); 
AF_DCMotor banKananAtas(4); 
int Aturkecepatan = 155; //Pengatur kecepatan
char intruksi; 

void setup() 
{       
  //Serial.begin(9600); //Atur baud rate ke modul Serial USB Anda
  btSerial.begin(9600);  //Atur baud rate ke modul Serial Bluetooth Anda
}
 void maju()
{
  banKiriAtas.setSpeed(Aturkecepatan); //Tentukan kecepatan maksimum
  banKiriAtas.run(FORWARD); //memutar motor searah jarum jam
  banKiriBawah.setSpeed(Aturkecepatan); //Tentukan kecepatan maksimum
  banKiriBawah.run(FORWARD); //memutar motor searah jarum jam
  banKananAtas.setSpeed(Aturkecepatan); //Tentukan kecepatan maksimum
  banKananAtas.run(FORWARD); //memutar motor searah jarum jam
  banKananBawah.setSpeed(Aturkecepatan); //Tentukan kecepatan maksimum
  banKananBawah.run(FORWARD); //memutar motor searah jarum jam
}

void mundur()
{
  banKiriAtas.setSpeed(Aturkecepatan); //Tentukan kecepatan maksimum
  banKiriAtas.run(BACKWARD); //memutar motor melawan arah jarum jam
  banKiriBawah.setSpeed(Aturkecepatan); //Tentukan kecepatan maksimum
  banKiriBawah.run(BACKWARD); //memutar motor melawan arah jarum jam
  banKananAtas.setSpeed(Aturkecepatan); //Tentukan kecepatan maksimum
  banKananAtas.run(BACKWARD); //memutar motor melawan arah jarum jam
  banKananBawah.setSpeed(Aturkecepatan); //Tentukan kecepatan maksimum
  banKananBawah.run(BACKWARD); //memutar motor melawan arah jarum jam

}

void BelokKanan()
{
  banKiriAtas.setSpeed(Aturkecepatan); //Tentukan kecepatan maksimum
  banKiriAtas.run(FORWARD); //memutar motor searah jarum jam
  banKiriBawah.setSpeed(Aturkecepatan); //Tentukan kecepatan maksimum
  banKiriBawah.run(FORWARD); //memutar motor searah jarum jam
  banKananAtas.setSpeed(Aturkecepatan); //Tentukan kecepatan maksimum
  banKananAtas.run(BACKWARD); //memutar motor melawan arah jarum jam
  banKananBawah.setSpeed(Aturkecepatan); //Tentukan kecepatan maksimum
  banKananBawah.run(BACKWARD); //memutar motor melawan arah jarum jam

}

void BelokKiri()
{
  banKiriAtas.setSpeed(Aturkecepatan); //Tentukan kecepatan maksimum
  banKiriAtas.run(BACKWARD); //memutar motor melawan arah jarum jam
  banKiriBawah.setSpeed(Aturkecepatan); //Tentukan kecepatan maksimum
  banKiriBawah.run(BACKWARD); //memutar motor melawan arah jarum jam
  banKananAtas.setSpeed(Aturkecepatan); //Tentukan kecepatan maksimum
  banKananAtas.run(FORWARD); //memutar motor searah jarum jam
  banKananBawah.setSpeed(Aturkecepatan); //Tentukan kecepatan maksimum
  banKananBawah.run(FORWARD); //memutar motor searah jarum jam

}

void Berhenti()
{
  banKiriAtas.setSpeed(0);
  banKiriAtas.run(RELEASE); //Mematikan banKiriAtas
  banKananBawah.setSpeed(0); //Tentukan kecepatan maksimum
  banKananBawah.run(RELEASE); //Mematikan banKananBawah
  banKiriBawah.setSpeed(0); //Tentukan kecepatan maksimum
  banKiriBawah.run(RELEASE); //Mematikan banKiriBawah
  banKananAtas.setSpeed(0); //Tentukan kecepatan maksimum
  banKananAtas.run(RELEASE); //Mematikan banKananAtas
}
void loop(){
     if(btSerial.available() > 0){ 
    intruksi = btSerial.read(); 
     Berhenti();
     Serial.println(intruksi);
    switch(intruksi){
    case 'F':  
      maju();
      break;
    case 'B':  
       mundur();
      break;
    case 'L':  
      BelokKiri();
      break;
    case 'R':
      BelokKanan();
      break;
    }
  } 
}