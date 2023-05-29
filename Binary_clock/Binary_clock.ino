/*
Binary Clock Using Leds 

Written by Luis Bernardo Ambrosi Rincón Gallardo
*/

int cont_led[]={11,10,9,8};
int hsm_led[]={7,6,5};
int hour_led[]={4,3,2,12};
byte cont = 2;
byte hsm = 1;
byte hour = 9;
byte pm = 0;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
 for(int pin_1 = 0;pin_1<4;pin_1++){
  pinMode(cont_led[pin_1],OUTPUT);
  byte bit_1 = bitRead(cont, pin_1);
  digitalWrite(cont_led[pin_1],bit_1);
  }
  for(int pin_2 = 0;pin_2<3;pin_2++){
  pinMode(hsm_led[pin_2],OUTPUT);
  byte bit_2 = bitRead(hsm, pin_2);
  digitalWrite(hsm_led[pin_2],bit_2);
  }
 
  for(int pin = 0;pin<4;pin++){
  pinMode(hour_led[pin],OUTPUT);
  byte bit_3 = bitRead(hour, pin);
  digitalWrite(hour_led[pin],bit_3);
    }
//Serial.print(hour);
//Serial.print(hsm);
//Serial.print(cont);
//Serial.print(pm);
//Serial.println();  
}

void loop() {

    for (int bit = 3; bit >= 0; bit--)
  {
    byte bitValue = bitRead(cont, bit);
    digitalWrite(cont_led[bit],bitValue);
  } 
  delay(60000);
  cont++;
  if(cont>9)
  {
    cont = 0;
    hsm++;
      if(hsm > 5)
    {
      hsm = 0;
      hour ++;
      if(hour == 12)
      {
        pm = !pm;
        Serial.print("pm: ");
        Serial.print(pm);
      }
      if(hour > 12)
      {
        hour = 1;
      }
      for(int bit_2 = 3;bit_2 >= 0; bit_2--)
      {
        byte bit_hourValue = bitRead(hour, bit_2);
        digitalWrite(hour_led[bit_2],bit_hourValue);
      }
    }

    for(int bit_1 = 2;bit_1 >= 0; bit_1--)
    {
      byte bit_hsmValue = bitRead(hsm, bit_1);
      digitalWrite(hsm_led[bit_1],bit_hsmValue);
    }
  
  }

 
  
  



}
