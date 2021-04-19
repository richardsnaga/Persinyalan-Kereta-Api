#include <Servo.h> 

Servo w1;
Servo w2;
int LAM = 0;
int LAH = 1;
int LBM = 2;
int LBH = 3;
int LCM = 4;
int LCH = 5;

int LW1M = 79;
int LW1K = 10;
int LW1H = 11;

int LW2M = 6;
int LW2K = 7;
int LW2H = 8;

int TCA1 = 14;
int TCA2 = 15;
int TCB1 = 16;
int TCB2 = 17;
int TCC1 = 18;
int TCC2 = 19;

int RTCA1;
int RTCA2;
int RTCB1;
int RTCB2;
int RTCC1;
int RTCC2;

int S00 = 100;
int S10 = 110;
int S11 = 111;
int S12 = 112;

int SRAC_PRESS = 900;
int SRCA_PRESS = 910;
int SRBC_PRESS = 920;
int SRCB_PRESS = 930;

int NO_PRESS = 904;

char a[5]={1,2,3,4,5};
int state = S00;

int input = NO_PRESS;

int SetRouteButton = 1;

void setup() {

  //initialize digital pin 13 as an output.
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
  w1.attach(9);
  w2.attach(35);
  
}

 

// the loop function runs over and over again forever

void loop() {
//  w1.write(0);
  RTCA1 = digitalRead(TCA1);
  RTCA2 = digitalRead(TCA2);
  RTCB1 = digitalRead(TCB1);
  RTCB2 = digitalRead(TCB2);
  RTCC1 = digitalRead(TCC1);
  RTCC2 = digitalRead(TCC2);

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
    //---------------------------------------------------- TOMBOL DITEKAN
    if (input==SRAC_PRESS) {
      if(RTCC1==HIGH&&RTCA2==HIGH) {
        w1.write(90);
        state = 110;
      }
      else {
        state = 100;
      }
    }
    else if(input==SRCA_PRESS){
      if(RTCA1==HIGH&&RTCC2==HIGH) {
      state = 210;
      }
      else {
        state = 100;
      }
    }
    else if(input==SRBC_PRESS){
      if(RTCC2==HIGH&&RTCB2==HIGH) {
      state = 310;
      }
      else {
        state = 100;
      }
    }
    else if(input==SRCB_PRESS){
      if(RTCB2==HIGH&&RTCC1==HIGH) {
      state = 410;
      }
      else {
        state = 100;
      }
    }
    break;
    
   
    //-------------------------------------------------------------------------------------------STATE SRAC
    case 110:
    w1.write(0);
    if (RTCA1==LOW) {
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
    w1.write(0); 
    if (RTCA2==LOW&&RTCA1==HIGH) {
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
    if (RTCC1==LOW&&RTCA2==HIGH&&RTCA1==HIGH) {
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
      delay(1000); 
      state = 100;
    }
    else {
      state = 112;
    }
    break;

    //-------------------------------------------------------------------------------------------STATE SRCA
    case 210:
    if (RTCC1==LOW) {
      state = 211;
    }
    else {
      state = 210;
    }
    break;

    case 211:
    digitalWrite(LAM, HIGH); 
    digitalWrite(LAH, HIGH);
    digitalWrite(LBM, LOW); 
    digitalWrite(LBH, LOW);
    digitalWrite(LCM, LOW);  
    digitalWrite(LCH, HIGH);
    
    digitalWrite(LW1M, HIGH); 
    digitalWrite(LW1K, LOW); 
    digitalWrite(LW1H, LOW);
    digitalWrite(LW2M, HIGH); 
    digitalWrite(LW2K, LOW); 
    digitalWrite(LW2H, LOW);   
    if (RTCC2==LOW&&RTCC1==HIGH) {
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
    if (RTCA1==LOW&&RTCC2==HIGH&&RTCC1==HIGH) {
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
      delay(1000); 
      state = 100;
    }
    else {
      state = 212;
    }
    break;

    //-------------------------------------------------------------------------------------------STATE SRBC
    case 310:
    if (RTCB1==LOW) {
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
    if (RTCB2==LOW&&RTCB1==HIGH) {
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
    digitalWrite(LW2K, LOW); 
    digitalWrite(LW2H, HIGH);
    if (RTCC1==LOW&&RTCB2==HIGH&&RTCB1==HIGH) {
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
      delay(1000); 
      state = 100;
    }
    else {
      state = 112;
    }
    break;

    //-------------------------------------------------------------------------------------------STATE SRCB
   case 410:
    if (RTCC1==LOW) {
      state = 411;
    }
    else {
      state = 410;
    }
    break;

    case 411:
    digitalWrite(LAM, HIGH); 
    digitalWrite(LAH, HIGH);
    digitalWrite(LBM, LOW); 
    digitalWrite(LBH, LOW);
    digitalWrite(LCM, LOW);  
    digitalWrite(LCH, HIGH);
    
    digitalWrite(LW1M, HIGH); 
    digitalWrite(LW1K, LOW); 
    digitalWrite(LW1H, LOW);
    digitalWrite(LW2M, HIGH); 
    digitalWrite(LW2K, LOW); 
    digitalWrite(LW2H, LOW);   
    if (RTCC2==LOW&&RTCC1==HIGH) {
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
    digitalWrite(LW1K, LOW); 
    digitalWrite(LW1H, HIGH);
    digitalWrite(LW2M, HIGH); 
    digitalWrite(LW2K, LOW); 
    digitalWrite(LW2H, LOW); 
    if (RTCB1==LOW&&RTCC2==HIGH&&RTCC1==HIGH) {
      digitalWrite(LAM, HIGH); 
      digitalWrite(LAH, LOW);
      digitalWrite(LBM, HIGH); 
      digitalWrite(LBH, LOW);
      digitalWrite(LCM, HIGH);  
      digitalWrite(LCH, LOW);
      
      digitalWrite(LW1M, LOW); 
      digitalWrite(LW1K, HIGH); 
      digitalWrite(LW1H, LOW);
      digitalWrite(LW2M, LOW); 
      digitalWrite(LW2K, HIGH); 
      digitalWrite(LW2H, LOW); 
      delay(1000); 
      state = 100;
    }
    else {
      state = 412;
    }
    break;
  }
}
