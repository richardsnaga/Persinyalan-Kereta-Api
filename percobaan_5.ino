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
int Habisdari;
int i = 0;

//----------------------------------

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
  
  if(Serial.available()>0&&state==100){
    SetRouteButton = Serial.read();
    if(Habisdari!=SetRouteButton){
      if(Habisdari==1&&SetRouteButton==3||Habisdari==2&&SetRouteButton==3||Habisdari==2&&SetRouteButton==4||Habisdari==3&&SetRouteButton==1||Habisdari==4&&SetRouteButton==1||Habisdari==4&&SetRouteButton==2){
        //Habisdari==AC&&SetRouteButton==BC||Habisdari==CA&&SetRouteButton==BC||Habisdari==CA&&SetRouteButton==CB||Habisdari==BC&&SetRouteButton==AC||Habisdari==CB&&SetRouteButton==AC||Habisdari==CB&&SetRouteButton==CA
        SetRouteButton = 0;
      }
      else{
        blt();
      }
    }
   }
   else if(Serial.read()>0&&state!=100) {
    SetRouteButton = 0;
   }
   else{
    SetRouteButton = 0;    
   }
  fsm();
}

void blt(){
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
    delay(1000);
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
      STCC1 = "TCC1 OFF|";
      STCA2 = "TCA2 OFF|";
      if(RTCC1==HIGH&&RTCA2==HIGH) {
        Serial.print(STCC1);
        Serial.print(STCA2);
        w2.attach(25);
        w2.write(120);
        w1.attach(24);
        w1.write(45);
        state = 110;
      }
      else {
        state = 100;
      }
    }
    else if(input==SRCA_PRESS){
      STCA1 = "TCA1 OFF|";
      STCC2 = "TCC2 OFF|";
      
      if(RTCA1==HIGH&&RTCC2==HIGH) {
        Serial.print(STCA1);
        Serial.print(STCC2);
        w1.attach(24);
        w1.write(120);
        w2.attach(25);
        w2.write(45);
        state = 210;
      }
      else {
        state = 100;
      }
    }
    else if(input==SRBC_PRESS){
      STCC1 = "TCC1 OFF|";
      STCB2 = "TCB2 OFF|";
      
      if(RTCC1==HIGH&&RTCB2==HIGH) {
        Serial.print(STCC1);
        Serial.print(STCB2);
        w1.attach(24);
        w1.write(120);
        w2.attach(25);
        w2.write(45);
        state = 310;
      }
      else {
        state = 100;
      }
    }
    else if(input==SRCB_PRESS){
      STCB1 = "TCB1 OFF|";
      STCC2 = "TCC2 OFF|";
      
      if(RTCB2==HIGH&&RTCC2==HIGH) {
        Serial.print(STCB1);
        Serial.print(STCC2);
        w2.attach(25);
        w2.write(120);
        w1.attach(24);
        w1.write(45);
        state = 410;
      }
      else {
        state = 100;
      }
    }
    break;
    
   
    //-------------------------------------------------------------------------------------------STATE SRAC
    case 110:
    STCA1 = "TCA1 ON|";
    
    if (RTCA1==LOW) {
      Serial.print(STCA1);
      state = 111;
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
    

    STCA2 = "TCA2 ON|";
    STCA1 = "TCA1 OFF|";
    
    if (RTCA2==LOW&&RTCA1==HIGH) {
      w2.detach();
      w1.detach();
      Serial.print(STCA2);
      Serial.print(STCA1);
      state = 112;
      
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

    STCC1 = "TCC1 ON|";
    STCA2 = "TCA2 OFF|";
    STCA1 = "TCA1 OFF|";
    
    if (RTCC1==LOW&&RTCA2==HIGH&&RTCA1==HIGH) {
      Serial.print(STCC1);
      Serial.print(STCA2);
      Serial.print(STCA1);
      Habisdari = 1;
      input = NO_PRESS;
      state = 100;
    }
    else {
      state = 112;
    }
    break;

    //-------------------------------------------------------------------------------------------STATE SRCA
    case 210:
    STCC1 = "TCC1 ON|";
    
    if (RTCC1==LOW) {
      Serial.print(STCC1);
      state = 211;
      
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
    
    STCC2 = "TCC2 ON|";
    STCC1 = "TCC1 OFF|";
    
    if (RTCC2==LOW&&RTCC1==HIGH) {
      w2.detach();
      w1.detach();
      Serial.print(STCC2);
      Serial.print(STCC1);
      state = 212;
    
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
    STCA1 = "TCA1 ON|";
    STCC2 = "TCC2 OFF|";
    STCC1 = "TCC1 OFF|";
    
    if (RTCA1==LOW&&RTCC2==HIGH&&RTCC1==HIGH) {
      Serial.print(STCA1);
      Serial.print(STCC2);
      Serial.print(STCC1);
      Habisdari = 2;
      input = NO_PRESS;
      state = 100;
    }
    else {
      state = 212;
    }
    break;

    //-------------------------------------------------------------------------------------------STATE SRBC
    case 310:
    STCB1 = "TCB1 ON|";
    
    if (RTCB1==LOW) {
      Serial.print(STCB1);
      state = 311;
      
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
    
    if (RTCB2==LOW&&RTCB1==HIGH) {
      w2.detach();
      w1.detach();
      Serial.print(STCB2);
      Serial.print(STCB1);
      state = 312;
      
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
    
    if (RTCC1==LOW&&RTCB2==HIGH&&RTCB1==HIGH) {
      Serial.print(STCC1);
      Serial.print(STCB2);
      Serial.print(STCB1);
      Habisdari = 3;
      input = NO_PRESS;
      state = 100;
    }
    else {
      state = 312;
    }
    break;

    //-------------------------------------------------------------------------------------------STATE SRCB
   case 410:
   STCC1 = "TCC1 ON|";
   
    if (RTCC1==LOW) {
      Serial.print(STCC1);
      state = 411;
      
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
    
    if (RTCC2==LOW&&RTCC1==HIGH) {
      w2.detach();
      w1.detach();
      Serial.print(STCC2);
      Serial.print(STCC1);
      state = 412;
      
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
    
    if (RTCB1==LOW&&RTCC2==HIGH&&RTCC1==HIGH) {
      Serial.print(STCB1);
      Serial.print(STCC2);
      Serial.print(STCC1);
      Habisdari = 4;
      input = NO_PRESS;
      state = 100;
    }
    else {
      state = 412;
    }
    break;
  }
}
