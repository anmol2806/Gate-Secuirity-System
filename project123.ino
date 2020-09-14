#include <WiFi.h>
#include <WiFiClient.h>
#include <Temboo.h>
#include "TembooAccount.h" // Contains Temboo account information
#include <Wire.h>
WiFiClient client;
int maxCalls = 1;
int calls = 1;  

void data_con(int x)
{ 
  int y,i,j=2;
  for(i=0;i<=7;i++)
  {y=x;
  y=y>>i;
  y&=0x01;
  if (y==0)
  {digitalWrite(j+i, LOW);
}
else
{digitalWrite (j+i, HIGH);
}}}
void com_w(int x)
{ digitalWrite(27,LOW);
  digitalWrite(28,LOW);
  data_con(x);
  digitalWrite(29,HIGH);
  delay(2);
  digitalWrite(29,LOW);
  delay(200);
}
void data_w(int x)
{ digitalWrite(27,HIGH);
  digitalWrite(28,LOW);
  data_con(x);
  digitalWrite(29,HIGH);
  delay(2);
  digitalWrite(29,LOW);
  delay(1000);
}
void setup() {
                    Serial.begin(9600);
    int wifiStatus = WL_IDLE_STATUS;
  // Determine if the WiFi Shield is present
  Serial.print("\n\nShield:");
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("FAIL");
    // If there's no WiFi shield, stop here
    while(true);
  }

  Serial.println("OK");
  // Try to connect to the local WiFi network
  while(wifiStatus != WL_CONNECTED) {
    Serial.print("WiFi:");
    wifiStatus = WiFi.begin(WIFI_SSID,WIFI_PASSWORD);
    if (wifiStatus == WL_CONNECTED) {
      Serial.println("OK");
    } else {
      Serial.println("FAIL");
    }
    delay(5000);
  }

  Serial.println("Setup complete.\n");
     pinMode(27,OUTPUT);
  pinMode(28,OUTPUT);
  pinMode(29,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(19,INPUT_PULLUP);
  pinMode(11,INPUT_PULLUP);
  com_w(0x38);
  com_w(0x0F);
  com_w(0x01);
  com_w(0x80);
  com_w(0x06);
 
} 

void loop() {
   int master=0;
  int bell=0;
   master=digitalRead(19);
   if (master==1)
   {
      bell=digitalRead(11);
         while(digitalRead(11)==HIGH)
                       {
                          data_w('W');
                          data_w('A');
                          data_w('I');
                          data_w('T');
                          data_w(' ');
                          data_w('I');
                          data_w('^');
                          data_w('M');
                          data_w(' ');
                          data_w('C');                        
                          data_w('O');
                          data_w('M');
                          data_w('I');
                          data_w('N');
                          data_w('G');
while(calls <= maxCalls) {
    
              Serial.println("Sending Away SMS" + String(calls++));
              TembooChoreo SendSMSChoreo(client);
              SendSMSChoreo.begin();
              SendSMSChoreo.setAccountName(TEMBOO_ACCOUNT);
              SendSMSChoreo.setAppKeyName(TEMBOO_APP_KEY_NAME);
              SendSMSChoreo.setAppKey(TEMBOO_APP_KEY);
              String AuthTokenValue = "ba3eae39941982eeeca02ff0fe43ba9e";
              SendSMSChoreo.addInput("AuthToken", AuthTokenValue);
              String ToValue = "+917009611925";
              SendSMSChoreo.addInput("To", ToValue);
               String FromValue = "+12565703592";
              SendSMSChoreo.addInput("From", FromValue);
              String BodyValue = "Someone is waiting at the door....";
              SendSMSChoreo.addInput("Body", BodyValue);
              String AccountSIDValue = "ACbdf84d906898f46a09017463bb4d406a";
              SendSMSChoreo.addInput("AccountSID", AccountSIDValue);
              SendSMSChoreo.setChoreo("/Library/Twilio/SMSMessages/SendSMS");
              SendSMSChoreo.run(901, USE_SSL);
    
                        while(SendSMSChoreo.available()) {
                                 char c = SendSMSChoreo.read();
                                  Serial.print(c);
                                  }
               SendSMSChoreo.close();
                }
                        delay(10000);
                        com_w(0x01); 
                    Serial.println("\nWaiting...\n");
                    delay(3000);     
         }  }

         else
           {
                  digitalRead(19);
                       while(digitalRead(11)==HIGH)
                            { 
                               data_w('C');
                               data_w('A');
                               data_w('L');
                               data_w('L');
                               data_w(':');
                               data_w('7');
                               data_w('0');
                               data_w('8');
                               data_w('7');
                               data_w('8');
                               data_w('8');
                               data_w('2');
                               data_w('2');
                               data_w('2');
                               data_w('6');
                                if (calls <= maxCalls) {
    
              Serial.println("Sending Away SMS" + String(calls++));
              TembooChoreo SendSMSChoreo(client);
              SendSMSChoreo.begin();
              SendSMSChoreo.setAccountName(TEMBOO_ACCOUNT);
              SendSMSChoreo.setAppKeyName(TEMBOO_APP_KEY_NAME);
              SendSMSChoreo.setAppKey(TEMBOO_APP_KEY);
              String AuthTokenValue = "ba3eae39941982eeeca02ff0fe43ba9e";
              SendSMSChoreo.addInput("AuthToken", AuthTokenValue);
              String ToValue = "+917009611925";
              SendSMSChoreo.addInput("To", ToValue);
               String FromValue = "+12565703592";
              SendSMSChoreo.addInput("From", FromValue);
              String BodyValue = "Someone ringed the doorbell...";
              SendSMSChoreo.addInput("Body", BodyValue);
              String AccountSIDValue = "ACbdf84d906898f46a09017463bb4d406a";
              SendSMSChoreo.addInput("AccountSID", AccountSIDValue);
              SendSMSChoreo.setChoreo("/Library/Twilio/SMSMessages/SendSMS");
              SendSMSChoreo.run(901, USE_SSL);
    
                        while(SendSMSChoreo.available()) {
                                 char c = SendSMSChoreo.read();
                                  Serial.print(c);
                                  }
               SendSMSChoreo.close();
                }
                           delay(10000);
                        com_w(0x01);
                    Serial.println("\nWaiting...\n");
                    delay(3000);     
                               
                            }
           }
   }
TembooAccount.h
#define TEMBOO_ACCOUNT "987654321anmol"  // your Temboo account name 
#define TEMBOO_APP_KEY_NAME "cc3200"  // your Temboo app name
#define TEMBOO_APP_KEY  "W380aMqZyV1PvQ5cjqbMf271ojA3k5eh"  // your Temboo app key

#define WIFI_SSID "REDMI"
#define WIFI_PASSWORD "12345678"
