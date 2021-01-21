#include <SoftwareSerial.h> //Library for Communication of GSM module with arduino
#include <LiquidCrystal.h>  //Library for Lcd display
String inputString = "";         
String S1 = "OFF";          //Default state of switch 1
String S2 = "OFF";          //Default state of switch 2       
String S3 = "OFF";          //Default state of switch 3
String S4 = "OFF";          //Default state of switch 4
String S5 = "OFF";          //Default state of switch 5
String S6 = "OFF";          //Default state of switch 6
String S7 = "OFF";          //Default state of switch 7
String S8 = "OFF";          //Default state of switch 8
boolean stringComplete = false; 
String incomingString =""; //String variable for store incoming message from gsm.
int startIndex = 0;
int endIndex = 0;
int s1 = 6;   //Pin D6 define for switch 1 in arduino.
int s2 = 7;   //Pin D7 define for switch 2 in arduino.
int s3 = 8;   //Pin D8 define for switch 3 in arduino.
int s4 = 9;   //Pin D9 define for switch 4 in arduino.
int s5 = 10;  //Pin D10 define for switch 5 in arduino.
int s6 = A3;  //Pin A3 define for switch 6 in arduino.
int s7 = A0;  //Pin A0 define for switch 7 in arduino.
int s8 = A1;  //Pin A1 define for switch 8 in arduino.
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2; // pin defining for lcd.
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void setup() {
  Serial.begin(9600); // Baud rate for Serial Monitor.
lcd.begin(16,2);        // Defining pins for outputs and inputs.
   pinMode(s1, OUTPUT);
   pinMode(s2, OUTPUT);
   pinMode(s3, OUTPUT);
   pinMode(s4, OUTPUT);
   pinMode(s5, OUTPUT);
   pinMode(s6, OUTPUT);
   pinMode(s7, OUTPUT);
   pinMode(s8, OUTPUT);
   digitalWrite(s1,HIGH); // Default States for switches "OFF".
   digitalWrite(s2,HIGH);
   digitalWrite(s3,HIGH);
   digitalWrite(s4,HIGH);
   digitalWrite(s5,HIGH);
   digitalWrite(s6,HIGH);
   digitalWrite(s7,HIGH);
   digitalWrite(s8,HIGH);
  lcd.setCursor(5,0);  //Printing a message on lcd display.
  lcd.print("WELCOME");
  delay(3000);
  lcd.clear();
  lcd.setCursor(5,0);
  lcd.print("PROJECT");
  lcd.setCursor(1,1);
  lcd.print("HOME AUTOMATION");
  delay(3000);
  lcd.clear();
  lcd.setCursor(4,0);
  lcd.print("MADE BY - ");
  lcd.setCursor(2,1);
  lcd.print("HARSHIT SAGAR");
  delay(3000);

  lcd.clear();
  lcd.setCursor(1,0); // Printing a default states of switches on lcd.
      lcd.print("S1  S2  S3  S4");
      lcd.setCursor(1,1);
      lcd.print("OFF");
      lcd.setCursor(5,1);
      lcd.print("OFF");
      lcd.setCursor(9,1);
      lcd.print("OFF");
      lcd.setCursor(13,1);
      lcd.print("OFF");
      delay(1000);
      lcd.clear();
  lcd.setCursor(1,0);
      lcd.print("S5  S6  S7  S8");
      lcd.setCursor(1,1);
      lcd.print("OFF");
      lcd.setCursor(5,1);
      lcd.print("OFF");
      lcd.setCursor(9,1);
      lcd.print("OFF");
      lcd.setCursor(13,1);
      lcd.print("OFF");
      delay(1000);
  inputString.reserve(200);
  Serial.print("AT+CMGF=1\r");// Printing a message on serial monitor for gsm module.
                              // AT+CMGF at command is used to select the operating mode of the GSM/GPRS modem.   
  delay(1000);
  Serial.print("AT+CMGDA=\""); // AT+CMGDA command is used to delete all SMS messages.

  Serial.println("DEL ALL\"");
  delay(1000);
  Serial.print("AT+CMGS=\"+91827xxxxxxx\"\r"); // AT+CMGS=\"+xxxxxxxxxxxx is used for send sms to xxxxxxxxxx mobile number.    
  delay(1000);
  Serial.print("HARSHIT SAGAR YOUR DEVICE IS CONNECTED NOW YOU CAN USE IT.\r"); // Message to send for confirmation that device is connected.
  delay(1000);
  Serial.write(0x1A);
  delay(1000);
  Serial.print("AT+CNMI=2,2,0,0,0\r"); 
  delay(1000);
}
void loop() // After this loop will start. 
{ 
  lcd.clear();
lcd.setCursor(0,0); // Printing the present status of all switches in lcd.
lcd.print(" S1  S2  S3  S4");
lcd.setCursor(1,1);
lcd.print(S1);
lcd.setCursor(5,1);
lcd.print(S2);
lcd.setCursor(9,1);
lcd.print(S3);
lcd.setCursor(13,1);
lcd.print(S4);
delay(1000);
lcd.clear();
lcd.setCursor(0,0);
lcd.print(" S5  S6  S7  S8");
lcd.setCursor(1,1);
lcd.print(S5);
lcd.setCursor(5,1);
lcd.print(S6);
lcd.setCursor(9,1);
lcd.print(S7);
lcd.setCursor(13,1);
lcd.print(S8);
delay(1000);

  if (stringComplete && inputString!="") {  // To check received message from gsm.
    inputString.toLowerCase();



    if(inputString=="@s1 on#") // Condition for ON switch 1.  

    {

      digitalWrite(s1, LOW); 
      S1="ON";
      Serial.print("AT+CMGS=\"+91827xxxxxxx\"\r"); // After Switch ON the Switch 1 it will execute a message for confirmation that switch 1 is ON.    



  delay(500);

  Serial.print("SWITCH-1 IS ON\r");  // Message to send. 

  delay(500);

  Serial.write(0x1A);

  delay(500);



  Serial.print("AT+CNMI=2,2,0,0,0\r"); 

  delay(500);

      

    }

    else if(inputString=="@s1 off#") // Condition for OFF switch 1. 

    {

      digitalWrite(s1,HIGH); 
      S1="OFF";
      Serial.print("AT+CMGS=\"+91827xxxxxxx\"\r");    // After Switch ON the Switch 1 it will execute a message for confirmation that switch 1 is OFF.



  delay(500);

  Serial.print("SWITCH-1 IS OFF\r");  // Message to send. 

  delay(500);

  Serial.write(0x1A);

  delay(500);



  Serial.print("AT+CNMI=2,2,0,0,0\r"); 

  delay(500);

    }
    else if(inputString=="@s2 on#")

    {

      digitalWrite(s2, LOW); 
      S2="ON";
      Serial.print("AT+CMGS=\"+91827xxxxxxx\"\r");    



  delay(500);

  Serial.print("SWITCH-2 IS ON\r");   

  delay(500);

  Serial.write(0x1A);

  delay(500);



  Serial.print("AT+CNMI=2,2,0,0,0\r"); 

  delay(500);

    }

    else if(inputString=="@s2 off#")

    {

      digitalWrite(s2,HIGH); 
      S2="OFF";
      Serial.print("AT+CMGS=\"+91827xxxxxxx\"\r");    



  delay(500);

  Serial.print("SWITCH-2 IS OFF\r");   

  delay(500);

  Serial.write(0x1A);

  delay(500);



  Serial.print("AT+CNMI=2,2,0,0,0\r"); 

  delay(500);

    }
    else if(inputString=="@s3 on#")

    {

      digitalWrite(s3, LOW); 
      S3="ON";
      Serial.print("AT+CMGS=\"+91827xxxxxxx\"\r");    



  delay(500);

  Serial.print("SWITCH-3 IS ON\r");   

  delay(500);

  Serial.write(0x1A);

  delay(500);



  Serial.print("AT+CNMI=2,2,0,0,0\r"); 

  delay(500);

    }

    else if(inputString=="@s3 off#")

    {

      digitalWrite(s3,HIGH); 
      S3="OFF";
      Serial.print("AT+CMGS=\"+91827xxxxxxx\"\r");    



  delay(500);

  Serial.print("SWITCH-3 IS OFF\r");   

  delay(500);

  Serial.write(0x1A);

  delay(500);



  Serial.print("AT+CNMI=2,2,0,0,0\r"); 

  delay(500);

    }
    else if(inputString=="@s4 on#")

    {

      digitalWrite(s4, LOW); 
      S4="ON";
      Serial.print("AT+CMGS=\"+91827xxxxxxx\"\r");    



  delay(500);

  Serial.print("SWITCH-4 IS ON\r");   

  delay(500);

  Serial.write(0x1A);

  delay(500);



  Serial.print("AT+CNMI=2,2,0,0,0\r"); 

  delay(500);

    }

    else if(inputString=="@s4 off#")

    {

      digitalWrite(s4, HIGH); 
      S4="OFF";
      Serial.print("AT+CMGS=\"+91827xxxxxxx\"\r");    



  delay(500);

  Serial.print("SWITCH-4 IS OFF\r");   

  delay(500);

  Serial.write(0x1A);

  delay(500);



  Serial.print("AT+CNMI=2,2,0,0,0\r"); 

  delay(500);

    }
    else if(inputString=="@s5 on#")

    {

      digitalWrite(s5, LOW); 
      S5="ON";
      Serial.print("AT+CMGS=\"+91827xxxxxxx\"\r");    



  delay(500);

  Serial.print("SWITCH-5 IS ON\r");  

  delay(500);

  Serial.write(0x1A);

  delay(500);



  Serial.print("AT+CNMI=2,2,0,0,0\r"); 

  delay(500);

    }

    else if(inputString=="@s5 off#")

    {

      digitalWrite(s5,HIGH); 
      S5="OFF";
      Serial.print("AT+CMGS=\"+91827xxxxxxx\"\r");    



  delay(500);

  Serial.print("SWITCH-5 IS OFF\r");   

  delay(500);

  Serial.write(0x1A);

  delay(500);



  Serial.print("AT+CNMI=2,2,0,0,0\r"); 

  delay(500);

    }
    else if(inputString=="@s6 on#")

    {

      analogWrite(s6,0); 
      S6="ON";
      Serial.print("AT+CMGS=\"+91827xxxxxxx\"\r");    



  delay(500);

  Serial.print("SWITCH-6 IS ON\r");   

  delay(500);

  Serial.write(0x1A);

  delay(500);



  Serial.print("AT+CNMI=2,2,0,0,0\r"); 

  delay(500);

    }

    else if(inputString=="@s6 off#")

    {

      analogWrite(s6,1023); 
      S6="OFF";
      Serial.print("AT+CMGS=\"+91827xxxxxxx\"\r");    



  delay(500);

  Serial.print("SWITCH-6 IS OFF\r");   

  delay(500);

  Serial.write(0x1A);

  delay(500);



  Serial.print("AT+CNMI=2,2,0,0,0\r"); 

  delay(500);

    }
    else if(inputString=="@s7 on#")

    {

      analogWrite(s7,0); 
      S7="ON";
      Serial.print("AT+CMGS=\"+91827xxxxxxx\"\r");    



  delay(500);

  Serial.print("SWITCH-7 IS ON\r");   

  delay(500);

  Serial.write(0x1A);

  delay(500);



  Serial.print("AT+CNMI=2,2,0,0,0\r"); 

  delay(500);

    }

    else if(inputString=="@s7 off#")

    {

      analogWrite(s7,1023); 
      S7="OFF";
      Serial.print("AT+CMGS=\"+91827xxxxxxx\"\r");    



  delay(500);

  Serial.print("SWITCH-7 IS OFF\r");   

  delay(500);

  Serial.write(0x1A);

  delay(500);



  Serial.print("AT+CNMI=2,2,0,0,0\r"); 

  delay(500);

    }
    else if(inputString=="@s8 on#")

    {

      analogWrite(s8,0); 
      S8="ON";
      Serial.print("AT+CMGS=\"+91827xxxxxxx\"\r");    



  delay(500);

  Serial.print("SWITCH-8 IS ON\r");   
  

  delay(500);

  Serial.write(0x1A);

  delay(500);



  Serial.print("AT+CNMI=2,2,0,0,0\r"); 

  delay(500);

    }

    else if(inputString=="@s8 off#")

    {

      analogWrite(s8,1023); 
      S8="OFF";
      Serial.print("AT+CMGS=\"+91827xxxxxxx\"\r");   


  delay(500);

  Serial.print("SWITCH-8 IS OFF\r");   

  delay(500);

  Serial.write(0x1A);

  delay(500);



  Serial.print("AT+CNMI=2,2,0,0,0\r"); 

  delay(500);

    }
    else if(inputString=="@all off#") // Condition for Switch OFF all switches.

    {

      digitalWrite(s1, HIGH); 
      S1="OFF";
      
      digitalWrite(s2, HIGH); 
      S2="OFF";
      digitalWrite(s3, HIGH); 
      S3="OFF";
      digitalWrite(s4, HIGH); 
      S4="OFF";
      digitalWrite(s5, HIGH); 
      S5="OFF";
      digitalWrite(s6, HIGH); 
      S6="OFF";
      digitalWrite(s7, HIGH); 
      S7="OFF";
      digitalWrite(s8, HIGH); 
      S8="OFF";
      Serial.print("AT+CMGS=\"+91827xxxxxxx\"\r");   


  delay(500);

  Serial.print("ALL SWITCHES ARE OFF\r");   
  delay(500);

  Serial.write(0x1A);

  delay(500);



  Serial.print("AT+CNMI=2,2,0,0,0\r"); 

  delay(500);

    }
    else if(inputString=="@all on#") // Condition for Switch ON all switches.

    {

      digitalWrite(s1, LOW); 
      S1="ON";
      digitalWrite(s2, LOW); 
      S2="ON";
      digitalWrite(s3, LOW); 
      S3="ON";
      digitalWrite(s4, LOW); 
      S4="ON";
      digitalWrite(s5, LOW); 
      S5="ON";
      digitalWrite(s6, LOW); 
      S6="ON";
      digitalWrite(s7, LOW); 
      S7="ON";
      digitalWrite(s8, LOW); 
      S8="ON";
      Serial.print("AT+CMGS=\"+91827xxxxxxx\"\r"); // After Switch ON all Switches it will execute a message for confirmation that all switches are ON.



  delay(500);

  Serial.print("ALL SWITCHES ARE ON\r");   // Message to send.

  delay(500);

  Serial.write(0x1A);

  delay(500);



  Serial.print("AT+CNMI=2,2,0,0,0\r"); 

  delay(500);

    }
    else if(inputString=="@status#") // Condition for get status that which switch is ON or which switch is OFF.

    {

     
      Serial.print("AT+CMGS=\"+91827xxxxxxx\"\r");    // It will send a message of the status of a given mobile number. 



  delay(500);
  Serial.print("        STATUS   "); // Message to send.
  Serial.print("\nSWITCH-1 IS ");
  Serial.print(S1);
  Serial.print("\nSWITCH-2 IS ");
  Serial.print(S2);
   Serial.print("\nSWITCH-3 IS ");
  Serial.print(S3);
  Serial.print("\nSWITCH-4 IS ");
  Serial.print(S4);
   Serial.print("\nSWITCH-5 IS ");
  Serial.print(S5);
  Serial.print("\nSWITCH-6 IS ");
  Serial.print(S6);
   Serial.print("\nSWITCH-7 IS ");
  Serial.print(S7);
  Serial.print("\nSWITCH-8 IS ");
  Serial.print(S8);
  Serial.print("\r");
     

  delay(500);

  Serial.write(0x1A);

  delay(500);



  Serial.print("AT+CNMI=2,2,0,0,0\r"); 

  delay(500);

    }

   Serial.print("AT+CMGDA=\""); 

   Serial.println("DEL ALL\"");

   delay(1000);



   inputString = "";

   stringComplete = false;

  }

}



void serialEvent() 

{

   if(stringComplete == false)

   { 

        incomingString = Serial.readString();

        if(incomingString!="")

        {

          startIndex = incomingString.indexOf("@");

          endIndex = incomingString.indexOf("#");



          if(startIndex>0 && endIndex>0)

          {

             inputString = incomingString.substring(startIndex,endIndex+1);

             stringComplete = true;

          }

   }

}
}
