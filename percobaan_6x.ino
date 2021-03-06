#include <Servo.h> 

Servo w1;
Servo w2;
int LAM = 2;
int LAH = 3;
int LBM = 4;
int LBH = 5;
int LCM = 6;
int LCH = 7;

int LW1M = 10;
int LW1K = 11;
int LW1H = 12;

int LW2M = 35;
int LW2K = 37;
int LW2H = 39;

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
String SetRouteButton2;

int Habisdari;

int ENA = 13;
int IN1 = 45;
int IN2 = 44;
int motorspeed = 255;

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

  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
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
    Serial.flush();
   }
   else{
    SetRouteButton = 0;    
    Serial.flush();
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
    
    if(w1.read()==10){
      SW1 = "W1 REVERSE|";
    }
    else{
      SW1 = "W1 NORMAL|";
    }
    if(w2.read()==18){
      SW1 = "W2 NORMAL|";
    }
    else{
      SW1 = "W2 REVERSE|";
    }
    Serial.print(SW1);
    Serial.print(SW2);

    Serial.print(STCA1);
    Serial.print(STCA2);
    Serial.print(STCB1);
    Serial.print(STCB2);
    Serial.print(STCC1);
    Serial.print(STCC2);

    //motorspeed=200;
    //    analogWrite(ENA, motorspeed);
    //    digitalWrite(IN1, LOW);
    //    digitalWrite(IN2, HIGH);
    //    delay(5000);
//    lambat();
    stopp();
//    digitalWrite(RELAY, HIGH);

    //---------------------------------------------------- TOMBOL DITEKAN
    if (input==SRAC_PRESS) {
      if(RTCC1==HIGH&&RTCA2==HIGH) {
        STCC1 = "TCC1 OFF|";
        STCA2 = "TCA2 OFF|";
        SW1 = "W1 REVERSE|";
        SW2 = "W2 NORMAL|";
        Serial.print(STCC1);
        Serial.print(STCA2);
        w2.attach(9);
        w2.write(18);
        w1.attach(8);
        w1.write(10);  
        state = 110;
        delay(1000);
      }
      else {
        state = 100;
      }
    }
    else if(input==SRCA_PRESS){
      if(RTCA1==HIGH&&RTCC2==HIGH) {
        STCA1 = "TCA1 OFF|";
        STCC2 = "TCC2 OFF|";
        SW1 = "W1 NORMAL|";
        SW2 = "W2 REVERSE|";
        Serial.print(STCA1);
        Serial.print(STCC2);
        w1.attach(8);
        w1.write(30);
        w2.attach(9);
        w2.write(0);
        state = 210;
        delay(1000);
      }
      else {
        state = 100;
      }
    }
    else if(input==SRBC_PRESS){
      if(RTCC1==HIGH&&RTCB2==HIGH) {
        STCC1 = "TCC1 OFF|";
        STCB2 = "TCB2 OFF|";
        SW1 = "W1 NORMAL|";
        SW2 = "W2 REVERSE|";
        Serial.print(STCC1);
        Serial.print(STCB2);
        Serial.print(SW1);
        Serial.print(SW2);
        w1.attach(8);
        w1.write(30);
        w2.attach(9);
        w2.write(0);
        state = 310;
        delay(1000);
      }
      else {
        state = 100;
      }
    }
    else if(input==SRCB_PRESS){
      if(RTCB2==HIGH&&RTCC2==HIGH) {
        STCB1 = "TCB1 OFF|";
        STCC2 = "TCC2 OFF|";
        SW1 = "W1 REVERSE|";
        SW2 = "W2 NORMAL|";
        Serial.print(STCB1);
        Serial.print(STCC2);
        Serial.print(SW1);
        Serial.print(SW2);
        w2.attach(9);
        w2.write(18);
        w1.attach(8);
        w1.write(10);  
        state = 410;
        delay(1000);
      }
      else {
        state = 100;
      }
    }
    else {
      state = 100;
    }
    break;
    
   
    //-------------------------------------------------------------------------------------------STATE SRAC
    case 110:
      if (RTCA1==LOW) {
        STCA1 = "TCA1 ON|";
        Serial.print(STCA1);
  
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
        
        Serial.print(SW1);
        Serial.print(SW2);
        
        SLA = "LA HIJAU|";
        Serial.print(SLA);
        state = 111;
      }
      else {
        
        state = 110;
      }
    break;
    

    case 111:
      lambat();
      if (RTCA2==LOW&&RTCA1==HIGH) {
        STCA2 = "TCA2 ON|";
        STCA1 = "TCA1 OFF|";
        w2.detach();
        w1.detach();
        Serial.print(STCA2);
        Serial.print(STCA1);
  
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
        digitalWrite(RELAY, LOW);
        cepat();
        delay(4000);
        state = 112;
      }
      else {
        state = 111;
      }
    break;

    case 112:
      lambat();
      if (RTCC1==LOW&&RTCA2==HIGH&&RTCA1==HIGH) {
        STCC1 = "TCC1 ON|";
        STCA2 = "TCA2 OFF|";
        STCA1 = "TCA1 OFF|";
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
    if (RTCC1==LOW) {
      STCC1 = "TCC1 ON|";
      Serial.print(STCC1);

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
      
      Serial.print(SW1);
      Serial.print(SW2);
        
      SLC = "LC HIJAU|";
      Serial.print(SLC);
     
      state = 211;
    }
    else {
      state = 210;
    }
    break;

    case 211:
      lambat();
      if (RTCC2==LOW&&RTCC1==HIGH) {
        STCC2 = "TCC2 ON|";
        STCC1 = "TCC1 OFF|";
        Serial.print(STCC2);
        Serial.print(STCC1);
  
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
        cepat();
        delay(4000);
        state = 212;
      
      }
      else {
        
        state = 211;
      }
    break;

    case 212:
      lambat();
      if (RTCA1==LOW&&RTCC2==HIGH&&RTCC1==HIGH) {
        STCA1 = "TCA1 ON|";
        STCC2 = "TCC2 OFF|";
        STCC1 = "TCC1 OFF|";
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
    if (RTCB1==LOW) {
      STCB1 = "TCB1 ON|";
      Serial.print(STCB1);
        
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
      Serial.print(SLB);
      state = 311;
      
    }
    else {
      state = 310;
    }
    break;

    case 311:
      lambat();
      if (RTCB2==LOW&&RTCB1==HIGH) {
        STCB2 = "TCB2 ON|";
        STCB1 = "TCB1 OFF|";      
        w2.detach();
        w1.detach();
        Serial.print(STCB2);
        Serial.print(STCB1);
        
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
        cepat();
        delay(3000);
        state = 312;
      }
      else {
        state = 311;
      }
    break;

    case 312:
      lambat();
      if (RTCC1==LOW&&RTCB2==HIGH&&RTCB1==HIGH) {
        STCC1 = "TCC1 ON|";
        STCB2 = "TCB2 OFF|";
        STCB1 = "TCB1 OFF|";
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
    if (RTCC1==LOW) {
      STCC1 = "TCC1 ON|";
      Serial.print(STCC1);
      
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
      state = 411;
    }
    else {
      state = 410;
    }
    break;

    case 411:
      lambat();
      if (RTCC2==LOW&&RTCC1==HIGH) {
        STCC2 = "TCC2 ON|";
        STCC1 = "TCC1 OFF|";
        w2.detach();
        w1.detach();
        Serial.print(STCC2);
        Serial.print(STCC1);
        
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
        cepat();
        delay(3000);
        state = 412;      
      }
      else {
        state = 411;
      }
    break;

    case 412:
      lambat();
      if (RTCB1==LOW&&RTCC2==HIGH&&RTCC1==HIGH) {
        STCB1 = "TCB1 ON|";
        STCC2 = "TCC2 OFF|";
        STCC1 = "TCB1 OFF|";
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

void lambat(){
  digitalWrite(RELAY, LOW);
  analogWrite(ENA, 200);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);  
}

void cepat(){
  digitalWrite(RELAY, LOW);
  analogWrite(ENA, 255);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);  
}
void stopp(){
  digitalWrite(RELAY, HIGH);
  analogWrite(ENA, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);  
}
