#include <Servo.h> 

Servo w1;
Servo w2;
int LAM = 2;
int LAH = 3;
int LBM = 4;
int LBH = 5;
int LCM = 6;
int LCH = 7;

int LW1M = 11;
int LW1K = 12;
int LW1H = 13;

int LW2M = 8;
int LW2K = 9;
int LW2H = 10;

int TCA1 = 14;
int TCA2 = 15;
int TCB1 = 16;
int TCB2 = 17;
int TCC1 = 18;
int TCC2 = 19;

const int RELAY = 30;

//-----------------------------------

int RTCA1;
int RTCA2;
int RTCB1;
int RTCB2;
int RTCC1;
int RTCC2;

int S00 = 100;

int SRAC_PRESS = 900;
int SRCA_PRESS = 910;
int SRBC_PRESS = 920;
int SRCB_PRESS = 930;

int NO_PRESS = 904;

int state = S00;

int input = NO_PRESS;

int SetRouteButton = 0;

//----------------------------------

//String SLAM = "LA MERAH|";
//String SLAH = "LA HIJAU|";
//String SLBM = "LB MERAH|";
//String SLBH = "LB HIJAU|";
//String SLCM = "LC MERAH|";
//String SLCH = "LC HIJAU|";
//
//String SLW1M = "LW1 MERAH|";
//String SLW1K = "LW1 KUNING|";
//String SLW1H = "LW1 HIJAU|";
//
//String SLW2M = "LW2 MERAH|";
//String SLW2K = "LW2 KUNING|";
//String SLW2H = "LW2 HIJAU|";
//
//String SW1N = "W1 NORMAL|";
//String SW1R = "W1 REVERSE|";
//String SW2N = "W2 NORMAL|";
//String SW2R = "W1 REVERSE|";
//
//
//String STCA1ON = "TCA1 ON|";
//String STCA1OFF = "TCA1 OFF|";
//String STCA2ON = "TCA2 ON|";
//String STCA2OFF = "TCA2 OFF|";
//String STCB1ON = "TCB1 ON|";
//String STCB1OFF = "TCB1 OFF|";
//String STCB2ON = "TCB2 ON|";
//String STCB2OFF = "TCB2 OFF|";
//String STCC1ON = "TCC1 ON|";
//String STCC1OFF = "TCC1 OFF|";
//String STCC2ON = "TCC2 ON|";
//String STCC2OFF = "TCC2 OFF|";
//--------------
String SLA = "LA MERAH|";
String SLB = "LB MERAH|";
String SLC = "LC MERAH|";

String SLW1 = "LW1 MERAH|";
String SLW2 = "LW2 MERAH|";

String SW1 = "W1 NORMAL|";
String SW2 = "W2 NORMAL|";

String STCA1 = "TCA1 OFF|";
String STCA2 = "TCA2 OFF|";
String STCB1 = "TCB1 OFF|";
String STCB2 = "TCB2 OFF|";
String STCC1 = "TCC1 OFF|";
String STCC2 = "TCC2 OFF|";


void setup() {

  Serial.begin(9600);

  pinMode(TCA1, INPUT);
  pinMode(TCA2, INPUT);
  pinMode(TCB1, INPUT);
  pinMode(TCB2, INPUT);
  pinMode(TCC1, INPUT);
  pinMode(TCC2, INPUT);

  pinMode(LAM, OUTPUT);
  pinMode(LAH, OUTPUT);
  pinMode(LBM, OUTPUT);
  pinMode(LBH, OUTPUT);
  pinMode(LCM, OUTPUT);
  pinMode(LCH, OUTPUT);

  pinMode(LW1M, OUTPUT);
  pinMode(LW1H, OUTPUT);
  pinMode(LW1K, OUTPUT);
  pinMode(LW2M, OUTPUT);
  pinMode(LW2H, OUTPUT);
  pinMode(LW2K, OUTPUT);

  pinMode(RELAY, OUTPUT);
  w1.attach(24);
  w2.attach(25);
  
}

 

// the loop function runs over and over again forever

void loop() {
//  digitalWrite(RELAY,HIGH);
  RTCA1 = digitalRead(TCA1);
  RTCA2 = digitalRead(TCA2);
  RTCB1 = digitalRead(TCB1);
  RTCB2 = digitalRead(TCB2);
  RTCC1 = digitalRead(TCC1);
  RTCC2 = digitalRead(TCC2);

  if(Serial.available()>0){
    SetRouteButton = Serial.read();
    if(SetRouteButton==1){
      input = SRAC_PRESS;
    }
    else if(SetRouteButton==2){
      input = SRCA_PRESS;
    }
    else if(SetRouteButton==3){
      input = SRBC_PRESS;
    }
    else if(SetRouteButton==4){
      input = SRCB_PRESS;
    }
    else {
      digitalWrite(LAM, HIGH); 
      digitalWrite(LAH, LOW);
      digitalWrite(LBM, HIGH); 
      digitalWrite(LBH, LOW);
      digitalWrite(LCM, HIGH);  
      digitalWrite(LCH, LOW);
  
      digitalWrite(LW1M, HIGH); 
      digitalWrite(LW1K, LOW); 
      digitalWrite(LW1H, LOW);
      digitalWrite(LW2M, HIGH); 
      digitalWrite(LW2K, LOW); 
      digitalWrite(LW2H, LOW);
  
      w1.write(0);
      w2.write(0);
  
      Serial.print(SLA);
      Serial.print(SLB);
      Serial.print(SLC);
  
      Serial.print(SLW1);
      Serial.print(SLW2);

      Serial.print(SW1);
      Serial.print(SW2);

      Serial.print(STCA1);
      Serial.print(STCA2);
      Serial.print(STCB1);
      Serial.print(STCB2);
      Serial.print(STCC1);
      Serial.print(STCC2);
    }
    
    
  }
  fsm();
  
}

void fsm(){
  switch(state){
    case 100:
    digitalWrite(LAM, HIGH); 
    digitalWrite(LAH, LOW);
    digitalWrite(LBM, HIGH); 
    digitalWrite(LBH, LOW);
    digitalWrite(LCM, HIGH);  
    digitalWrite(LCH, LOW);

    digitalWrite(LW1M, HIGH); 
    digitalWrite(LW1K, LOW); 
    digitalWrite(LW1H, LOW);
    digitalWrite(LW2M, HIGH); 
    digitalWrite(LW2K, LOW); 
    digitalWrite(LW2H, LOW);

    
    SLA = "LA MERAH|";
    SLB = "LB MERAH|";
    SLC = "LC MERAH|";

    SLW1 = "LW1 MERAH|";
    SLW2 = "LW2 MERAH|";
    
    Serial.print(SLA);
    Serial.print(SLB);
    Serial.print(SLC);

    Serial.print(SLW1);
    Serial.print(SLW2);

    Serial.print(SW1);
    Serial.print(SW2);

    Serial.print(STCA1);
    Serial.print(STCA2);
    Serial.print(STCB1);
    Serial.print(STCB2);
    Serial.print(STCC1);
    Serial.print(STCC2);

    //---------------------------------------------------- TOMBOL DITEKAN
    if (input==SRAC_PRESS) {
      //JANGAN LUPA HAPUSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSSS
      RTCC1 = HIGH;
      RTCA2 = HIGH;
      STCC1 = "TCC1 OFF|";
      STCA2 = "TCA2 OFF|";
      delay(3000);
      if(RTCC1==HIGH&&RTCA2==HIGH) {
        Serial.print(STCC1);
        Serial.print(STCA2);
        state = 110;
      }
      else {
        state = 100;
      }
    }
    else if(input==SRCA_PRESS){
      RTCA1 = HIGH;
      RTCC2 = HIGH;
      STCA1 = "TCA1 OFF|";
      STCC2 = "TCC2 OFF|";
      delay(3000);
      if(RTCA1==HIGH&&RTCC2==HIGH) {
        Serial.print(STCA1);
        Serial.print(STCC2);
        state = 210;
      }
      else {
        state = 100;
      }
    }
    else if(input==SRBC_PRESS){
      RTCC1 = HIGH;
      RTCB2 = HIGH;
      STCC1 = "TCC1 OFF|";
      STCB2 = "TCB2 OFF|";
      delay(3000);
      if(RTCC1==HIGH&&RTCB2==HIGH) {
        Serial.print(STCC1);
        Serial.print(STCB2);
        state = 310;
      }
      else {
        state = 100;
      }
    }
    else if(input==SRCB_PRESS){
      RTCB2 = HIGH;
      RTCC2 = HIGH;
      STCB1 = "TCB1 OFF|";
      STCC2 = "TCC2 OFF|";
      delay(3000);
      if(RTCB2==HIGH&&RTCC2==HIGH) {
        Serial.print(STCB1);
        Serial.print(STCC2);
        state = 410;
      }
      else {
        state = 100;
      }
    }
    break;
    
   
    //-------------------------------------------------------------------------------------------STATE SRAC
    case 110:
    RTCA1 = LOW;
    STCA1 = "TCA1 ON|";
    delay(3000);
    if (RTCA1==LOW) {
      Serial.print(STCA1);
      state = 111;
      delay(3000);
    }
    else {
      state = 110;
    }
    break;

    case 111:
    digitalWrite(LAM, LOW); 
    digitalWrite(LAH, HIGH);
    digitalWrite(LBM, HIGH); 
    digitalWrite(LBH, LOW);
    digitalWrite(LCM, HIGH);  
    digitalWrite(LCH, LOW);

    digitalWrite(LW1M, HIGH); 
    digitalWrite(LW1K, LOW); 
    digitalWrite(LW1H, LOW);
    digitalWrite(LW2M, HIGH); 
    digitalWrite(LW2K, LOW); 
    digitalWrite(LW2H, LOW);
    
    SLA = "LA HIJAU|";
    Serial.print(SLA);
    

    RTCA2 = LOW;
    RTCA1 = HIGH;
    STCA2 = "TCA2 ON|";
    STCA1 = "TCA1 OFF|";
    delay(3000);
    if (RTCA2==LOW&&RTCA1==HIGH) {
      Serial.print(STCA2);
      Serial.print(STCA1);
      state = 112;
      delay(3000);
    }
    else {
      state = 111;
    }
    break;

    case 112:
    digitalWrite(LAM, HIGH); 
    digitalWrite(LAH, LOW);
    digitalWrite(LBM, HIGH); 
    digitalWrite(LBH, LOW);
    digitalWrite(LCM, HIGH);  
    digitalWrite(LCH, LOW);

    digitalWrite(LW1M, HIGH); 
    digitalWrite(LW1K, LOW); 
    digitalWrite(LW1H, LOW);
    digitalWrite(LW2M, LOW); 
    digitalWrite(LW2K, LOW); 
    digitalWrite(LW2H, HIGH);
    
    SLA = "LA MERAH|";
    SLW2 = "LW2 HIJAU|";
    Serial.print(SLA);
    
    Serial.print(SLW2);

    RTCC1 = LOW;
    RTCA2 = HIGH;
    RTCA1 = HIGH;
    STCC1 = "TCC1 ON|";
    STCA2 = "TCA2 OFF|";
    STCA1 = "TCA1 OFF|";
    delay(3000);
    if (RTCC1==LOW&&RTCA2==HIGH&&RTCA1==HIGH) {
      Serial.print(STCC1);
      Serial.print(STCA2);
      Serial.print(STCA1);
      state = 100;
      delay(3000);
    }
    else {
      state = 112;
    }
    break;

    //-------------------------------------------------------------------------------------------STATE SRCA
    case 210:
    RTCC1 = LOW;
    STCC1 = "TCC1 ON|";
    delay(3000);
    if (RTCC1==LOW) {
      Serial.print(STCC1);
      state = 211;
    delay(3000);
    }
    else {
      state = 210;
    }
    break;

    case 211:
    digitalWrite(LAM, HIGH); 
    digitalWrite(LAH, LOW);
    digitalWrite(LBM, HIGH); 
    digitalWrite(LBH, LOW);
    digitalWrite(LCM, LOW);  
    digitalWrite(LCH, HIGH);
    
    digitalWrite(LW1M, HIGH); 
    digitalWrite(LW1K, LOW); 
    digitalWrite(LW1H, LOW);
    digitalWrite(LW2M, HIGH); 
    digitalWrite(LW2K, LOW); 
    digitalWrite(LW2H, LOW);
    
    SLC = "LC HIJAU|";
    Serial.print(SLC);
    
    RTCC2 = LOW;
    RTCC1 = HIGH;
    STCC2 = "TCC2 ON|";
    STCC1 = "TCC1 OFF|";
    delay(3000);
    if (RTCC2==LOW&&RTCC1==HIGH) {
      Serial.print(STCC2);
      Serial.print(STCC1);
      state = 212;
    delay(3000);
    }
    else {
      state = 211;
    }
    break;

    case 212:
    digitalWrite(LAM, HIGH); 
    digitalWrite(LAH, LOW);
    digitalWrite(LBM, HIGH); 
    digitalWrite(LBH, LOW);
    digitalWrite(LCM, HIGH);  
    digitalWrite(LCH, LOW);
    
    digitalWrite(LW1M, LOW); 
    digitalWrite(LW1K, LOW); 
    digitalWrite(LW1H, HIGH);
    digitalWrite(LW2M, HIGH); 
    digitalWrite(LW2K, LOW); 
    digitalWrite(LW2H, LOW);

    SLC = "LC MERAH|";
    SLW1 = "LW11 HIJAU|";
    Serial.print(SLC);
    Serial.print(SLW1);
    RTCA1 = LOW;
    RTCC2 = HIGH;
    RTCC1 = HIGH;
    STCA1 = "TCA1 ON|";
    STCC2 = "TCC2 OFF|";
    STCC1 = "TCC1 OFF|";
    delay(3000);
    if (RTCA1==LOW&&RTCC2==HIGH&&RTCC1==HIGH) {
      Serial.print(STCA1);
      Serial.print(STCC2);
      Serial.print(STCC1);
      state = 100;
      delay(3000);
    }
    else {
      state = 212;
    }
    break;

    //-------------------------------------------------------------------------------------------STATE SRBC
    case 310:
    STCB1 = "TCB1 ON|";
    RTCB1 = LOW;
    delay(3000);
    if (RTCB1==LOW) {
      Serial.print(STCB1);
      state = 311;
      delay(3000);
    }
    else {
      state = 310;
    }
    break;

    case 311:
    digitalWrite(LAM, HIGH); 
    digitalWrite(LAH, LOW);
    digitalWrite(LBM, LOW); 
    digitalWrite(LBH, HIGH);
    digitalWrite(LCM, HIGH);  
    digitalWrite(LCH, LOW);

    digitalWrite(LW1M, HIGH); 
    digitalWrite(LW1K, LOW); 
    digitalWrite(LW1H, LOW);
    digitalWrite(LW2M, HIGH); 
    digitalWrite(LW2K, LOW); 
    digitalWrite(LW2H, LOW);  

    SLB = "LB HIJAU|";
    SW2 = "W2 REVERSE|";
    Serial.print(SLB);
    Serial.print(SW2);
    
    STCB2 = "TCB2 ON|";
    STCB1 = "TCB1 OFF|";
    RTCB2 = LOW;
    RTCB1 = HIGH;
    delay(3000);
    if (RTCB2==LOW&&RTCB1==HIGH) {
      Serial.print(STCB2);
      Serial.print(STCB1);
      state = 312;
      delay(3000);
    }
    else {
      state = 311;
    }
    break;

    case 312:
    digitalWrite(LAM, HIGH); 
    digitalWrite(LAH, LOW);
    digitalWrite(LBM, HIGH); 
    digitalWrite(LBH, LOW);
    digitalWrite(LCM, HIGH);  
    digitalWrite(LCH, LOW);

    digitalWrite(LW1M, HIGH); 
    digitalWrite(LW1K, LOW); 
    digitalWrite(LW1H, LOW);
    digitalWrite(LW2M, LOW); 
    digitalWrite(LW2K, HIGH); 
    digitalWrite(LW2H, LOW);

    SLB = "LB MERAH|";
    SLW2 = "LW2 KUNING|";
    Serial.print(SLB);
    Serial.print(SLW2);
    
    STCC1 = "TCC1 ON|";
    STCB2 = "TCB2 OFF|";
    STCB1 = "TCB1 OFF|";
    RTCC1 = LOW;
    RTCB2 = HIGH;
    RTCB1 = HIGH;
    delay(3000);
    if (RTCC1==LOW&&RTCB2==HIGH&&RTCB1==HIGH) {
      Serial.print(STCC1);
      Serial.print(STCB2);
      Serial.print(STCB1);
      state = 100;
      delay(3000);
    }
    else {
      state = 312;
    }
    break;

    //-------------------------------------------------------------------------------------------STATE SRCB
   case 410:
   STCC1 = "TCC1 ON|";
   RTCC1 = LOW;
   delay(3000);
    if (RTCC1==LOW) {
      Serial.print(STCC1);
      state = 411;
      delay(3000);
    }
    else {
      state = 410;
    }
    break;

    case 411:
    digitalWrite(LAM, HIGH); 
    digitalWrite(LAH, LOW);
    digitalWrite(LBM, HIGH); 
    digitalWrite(LBH, LOW);
    digitalWrite(LCM, LOW);  
    digitalWrite(LCH, HIGH);
    
    digitalWrite(LW1M, HIGH); 
    digitalWrite(LW1K, LOW); 
    digitalWrite(LW1H, LOW);
    digitalWrite(LW2M, HIGH); 
    digitalWrite(LW2K, LOW); 
    digitalWrite(LW2H, LOW);   
    
    SLC = "LC HIJAU|";
    SW1 = "W1 REVERSE|";
    Serial.print(SLC);
    Serial.print(SW1);
    
    STCC2 = "TCC2 ON|";
    STCC1 = "TCC1 OFF|";
    RTCC2 = LOW;
    RTCC1 = HIGH;
    delay(3000);
    if (RTCC2==LOW&&RTCC1==HIGH) {
      Serial.print(STCC2);
      Serial.print(STCC1);
      state = 412;
      delay(3000);
    }
    else {
      state = 411;
    }
    break;

    case 412:
    digitalWrite(LAM, HIGH); 
    digitalWrite(LAH, LOW);
    digitalWrite(LBM, HIGH); 
    digitalWrite(LBH, LOW);
    digitalWrite(LCM, HIGH);  
    digitalWrite(LCH, LOW);
    
    digitalWrite(LW1M, LOW); 
    digitalWrite(LW1K, HIGH); 
    digitalWrite(LW1H, LOW);
    digitalWrite(LW2M, HIGH); 
    digitalWrite(LW2K, LOW); 
    digitalWrite(LW2H, LOW);

    SLC = "LC MERAH|";
    SLW1 = "LW1 KUNING|";
    Serial.print(SLC);
    Serial.print(SLW1);

    STCB1 = "TCB1 ON|";
    STCC2 = "TCC2 OFF|";
    STCC1 = "TCB1 OFF|";
    RTCB1 = LOW;
    RTCC2 = HIGH;
    RTCC1 = HIGH;
    delay(3000);
    if (RTCB1==LOW&&RTCC2==HIGH&&RTCC1==HIGH) {
      Serial.print(STCB1);
      Serial.print(STCC2);
      Serial.print(STCC1);
      state = 100;
      delay(3000);
    }
    else {
      state = 412;
    }
    break;
  }
}
