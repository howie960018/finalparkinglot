#include <BluetoothSerial.h>
#include <Servo.h>

static const int servo1Pin=4;

Servo servo1;
BluetoothSerial BT;


void setup() {
  
  Serial.begin(115200);
  pinMode(12,OUTPUT);
  pinMode(14,OUTPUT);
  pinMode(27,OUTPUT);
  pinMode(26,OUTPUT);
  servo1.attach(servo1Pin);
  BT.begin("Howie");

}

void loop() {

  while(BT.available()){
   String BTdata=BT.readString();

   
    if(BTdata=="001")
        digitalWrite(14,HIGH);
    else  
        digitalWrite(14,LOW);
     
    
    if(BTdata=="002")
      digitalWrite(27,HIGH);    
    else 
      digitalWrite(27,LOW);
    
     
    if(BTdata=="003")
       digitalWrite(12,HIGH);     
    else 
       digitalWrite(12,LOW);       
      
      
    if(BTdata.substring(0,4)=="open")
      servo1.write(60);
    else 
      servo1.write(160);


 
    if(BTdata.substring(4,7)=="001")
        digitalWrite(14,HIGH);
    else  
        digitalWrite(14,LOW);
     
    
    if(BTdata.substring(4,7)=="002")
      digitalWrite(27,HIGH);    
    else 
      digitalWrite(27,LOW);
    
     
    if(BTdata.substring(4,7)=="003")
       digitalWrite(12,HIGH);     
    else 
       digitalWrite(12,LOW);   
       
   Serial.print(BTdata);
 
  }

}


//"value1":"車牌:ATG2906車位:002車主:曾浩儀"
