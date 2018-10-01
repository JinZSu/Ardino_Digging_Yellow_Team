String incomingByte = "";

void setup() {
 // put your setup code here, to run once:
 //Serial1.begin(9600);
 Serial.begin(9600);
 pinMode(3,OUTPUT);
 pinMode(4,OUTPUT);
 pinMode(8,OUTPUT);
 digitalWrite(3,HIGH);
 digitalWrite(4, HIGH);
}

/* Ports where N is the number
* N->DN
*/

//
//8 is ultrasonic

void loop() {
 // put your main code here, to run repeatedly:
 if (Serial.available() > 0) {
   // read the incoming byte:
   incomingByte = Serial.readString();
   if(incomingByte=="w"){
     digitalWrite(3, HIGH);
   }
   if(incomingByte=="a"){
     digitalWrite(4, LOW);
   }
   if(incomingByte=="s"){
     digitalWrite(3, LOW);
   }
   if(incomingByte=="d"){
     digitalWrite(4, HIGH);
   }
     if(incomingByte=="Tokyo_Drift_Left"){
     digitalWrite(4, HIGH);
     //Front Wheel Stop
     //Increase Power
     //Left Turn Power
   }
   if(incomingByte=="Tokyo_Drift_Right"){
     digitalWrite(3, HIGH);
     //Front Wheel Stop
     //Increase Power
     //Right Turn Power
   }
   Serial.println(incomingByte);
 }
}
