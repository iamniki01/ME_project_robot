

#define enA 9
#define in1 4
#define in2 5
#define enB 10
#define in3 6
#define in4 7

int turn = 100;
int motorSpeedA = 10;
int motorSpeedB = 10;
int motorSpeed = 150;


void setup() {
  Serial.begin(9600);
  Serial.flush();
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
}


  void loop() {
    String input = "";
    while (Serial.available()) {
      input += (char)Serial.read();
      delay(5);
      
    }

    if (input == "n") {
      stp();
    }
    else if (input == "F") {
      fwd();
    }
    else if (input == "R") {
      rev();
    }
    else if (input.indexOf("TL") > -1) {
      lft();
    }
    else if (input.indexOf("TR") > -1) {
      rght();
      
    }
    else if (input != "") {
      motorSpeed = input.toInt();
    }
  }
 void fwd(){
    analogWrite(enA, motorSpeed);
    analogWrite(enB, motorSpeed);
    // Set Motor A forwarward
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    // Set Motor B forward
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    // Convert the declining Y-axis readings for going backward from 470 to 0 into 0 to 255 value for the PWM signal for increasing the motor speed
    
  }
  void rev(){
    analogWrite(enA, motorSpeed);
    analogWrite(enB, motorSpeed);
    // Set Motor A backward
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    // Set Motor B backward
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    // Convert the declining Y-axis readings for going backward from 470 to 0 into 0 to 255 value for the PWM signal for increasing the motor speed
    
  }
  
    void lft(){
    analogWrite(enA, motorSpeed - turn);
    analogWrite(enB, motorSpeed + turn);
    // Set Motor A left
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    // Set Motor B left
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    }

   void rght() {
    analogWrite(enA, motorSpeed + turn);
    analogWrite(enB, motorSpeed - turn);
    // Set Motor A backward
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    // Set Motor B backward
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
   }
   void stp() {
    analogWrite(enA, 0);
    analogWrite(enB, 0);
    // Set Motor A backward
    digitalWrite(in1, HIGH);
    digitalWrite(in2, HIGH);
    // Set Motor B backward
    digitalWrite(in3, HIGH);
    digitalWrite(in4, HIGH);
   }
   
