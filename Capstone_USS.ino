#include "SR04.h"
#define FTRIG_PIN 12 //declare front USS trig pin (input)
#define FECHO_PIN 11 //declare front USS echo pin (output)
#define RTRIG_PIN 10 //declare right USS trig pin
#define RECHO_PIN 9  //declare right USS echo pin
#define LTRIG_PIN 7  //declare left  USS trig pin
#define LECHO_PIN 6  //declare left  USS echo pin
#define BTRIG_PIN 5  //declare back  USS trig pin
#define BECHO_PIN 4  //declare back  USS echo pin
SR04 Fsr04 = SR04(FECHO_PIN,FTRIG_PIN); //initiate front USS
SR04 Rsr04 = SR04(RECHO_PIN,RTRIG_PIN); //initiate right USS
SR04 Lsr04 = SR04(LECHO_PIN,LTRIG_PIN); //initiate Left  USS
SR04 Bsr04 = SR04(BECHO_PIN,BTRIG_PIN); //initiate back  USS
long a; //create front measurement variable
long b; //create right measurement variable
long c; //create left  measurement variable
long d; //create back  measurement variable


void setup() {
   Serial.begin(9600);
   delay(1000);
}

void loop() {
  
       
   a=Fsr04.Distance(); //calculate distance in cm
   b=Rsr04.Distance(); //calculate distance in cm
   c=Lsr04.Distance(); //calculate distance in cm
   d=Bsr04.Distance(); //calculate distance in cm
      
   if (a <= 5)
   {
      Serial.println("DANGER FRONT");
   }
   else if (b <= 5)
   {
      Serial.println("DANGER RIGHT");
   }
   else if (c <= 5)
   {
      Serial.println("DANGER LEFT");
   }
   else if (d <= 5)
   {
      Serial.println("DANGER BACK");
   }
   else
   {
       //FRONT
       //Serial.print(a); //debug
       if (a <= 40) //set distance to wall detection
       {
           Serial.println();
           Serial.println("WALL DETECTED FRONT");
       }
       else
       {
          Serial.println();
          Serial.println("CLEAR FRONT");
       }
       //delay(1000);
       //RIGHT
       
       //Serial.print(b); //debug
       if (b <= 40) //set distance to wall detection
       {
           Serial.println("WALL DETECTED RIGHT");
       }
       else
       {
          Serial.println("CLEAR RIGHT");
       }
       //delay(1000);
       
       //LEFT
       
       //Serial.print(c); //debug
       if (c <= 40) //set distance to wall detection
       {
           Serial.println("WALL DETECTED LEFT");
       }
       else
       {
          Serial.println("CLEAR LEFT");
       }
       //delay(1000);
      
       //BACK
       
       //Serial.print(d); //debug
       if (d <= 40) //set distance to wall detection
       {
           Serial.println("WALL DETECTED BACK");
       }
       else
       {
          Serial.println("CLEAR BACK");
       }
       delay(1000);
   }
   
}
