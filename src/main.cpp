#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include <DHT_U.h>

LiquidCrystal_I2C lcd(0x27,20,4);

#define DHTPIN 14
#define DHTTYPE DHT22

unsigned long tempo;
unsigned long auxilio;

unsigned long tempo2;
unsigned long auxilio2;

float tempAn;
float umiAn;

bool alt1;
bool alt2;

int led1 = 15;
int led2 = 2;
int led3 = 13;

bool valor = true;
bool valor2 = true;
bool valor3 = true;

int brilho;
int brilho2;
int brilho3;


DHT dht(DHTPIN, DHTTYPE);

void setup() {
  lcd.init();                     
  lcd.backlight();
  Serial.begin(115200);
  dht.begin();

  Serial.begin(115200);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);

  lcd.setCursor(0,0);
  lcd.print("Umidade:");

  lcd.setCursor(0,1);
  lcd.print("Temperatura: ");

  float u = dht.readHumidity();

  float temp = dht.readTemperature();

  lcd.setCursor(8,0);
  lcd.print(u);

  lcd.setCursor(12,1);
  lcd.print(temp);
}

void loop() {
    // float u = dht.readHumidity();

    // float temp = dht.readTemperature();
    // tempo = millis();

    // if(temp != tempAn){
    //   tempo = millis();
    //   alt1 = true;
    // }

    // if(alt1 && tempAn != temp){
    //   if(tempo - auxilio >= 3000){
    //     lcd.setCursor(8,0);
    //     lcd.print(umiAn);
    //     auxilio = tempo;
    //     alt1 = false;
    //   }
    // }
    

    // if(u != umiAn){
    //   tempo2 = millis();
    //   alt2 = true;
    // }

    // if(u != umiAn && alt2){
    //   if(tempo2 - auxilio2 >= 3000){
    //     lcd.setCursor(12,1);
    //     lcd.print(tempAn);
    //     auxilio2 = tempo2;
    //     alt2 = false;
    //   }
    // }
    

    
    // tempAn = temp;
    // umiAn = u;








// tempo = millis();

// if (tempo - auxilio >= 200)
// {
//   auxilio = tempo;
  
//   if (valor) {
//     brilho = brilho + 51;
//     if (brilho >= 255) {
//       brilho = 255; 
//     }


//     if(valor2 && brilho == 255){
//       brilho2 = brilho2 + 51;
//       if(brilho2 >= 255){
//         brilho2 = 255;
//       }
//     }


//     if(valor3 && brilho2 == 255){
//       brilho3 = brilho3 + 51;
//       if(brilho3 >= 255){
//         brilho3 = 255;
//         valor = false;
//         valor2 = false;
//         valor3 = false;
//           }
//         }
//   }


//   if(!valor3) {
//     brilho3 = brilho3 - 51;
//     if (brilho3 <= 0) {
//       brilho3 = 0;  
//     }


//     if(!valor2 && brilho3 == 0){
//       brilho2 = brilho2 - 51;
//       if(brilho2 <= 0){
//         brilho2 = 0;
//       }
//     }


//       if(!valor && brilho2 == 0){
//         brilho = brilho - 51;
//         if(brilho <= 0){
//           brilho = 0;
//           valor = true;
//           valor2 = true;
//           valor3 = true;
//         }
//       }
    
  
//   }

// Serial.println(brilho);
// analogWrite(led1,brilho);
// analogWrite(led2,brilho2);
// analogWrite(led3,brilho3);

//     }





  tempo = millis();
  
  if(tempo - auxilio >= 2000){
    auxilio = tempo;
    float u = dht.readHumidity();
    float temp = dht.readTemperature();

    Serial.print("Umidade: ");
    Serial.println(u);

    Serial.print("Temperatura: ");
    Serial.println(temp);


    if(u <= 64.40){
      analogWrite(led2, 51);
    }
    else if(u > 64.40 && u <= 65.40 ){
      analogWrite(led2, 102);
    }
    else if(u > 65.40 && u <= 66.40 ){
      analogWrite(led2, 153);
    }
    else if(u > 66.40 && u <= 67.40 ){
      analogWrite(led2, 204);
    }
    else if(u > 67.40 ){
      analogWrite(led2, 255);
    }


    if(temp <= 26.10){
      analogWrite(led3, 51);
    }
    else if(temp > 26.10 && temp <= 26.30 ){
      analogWrite(led3, 102);
    }
    else if(temp > 26.30 && temp <= 26.60 ){
      analogWrite(led3, 153);
    }
    else if(temp > 26.60 && temp <= 26.90 ){
      analogWrite(led3, 204);
    }
    else if(temp > 26.90 ){
      analogWrite(led3, 255);
    }
  }
  }