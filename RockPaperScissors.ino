#include <Servo.h>
Servo ring_pinkie;
Servo middle;
Servo index;
Servo thumb;
int servoAngle = 0; 
int x;

void setup() {
  Serial.begin(9600); 
  Serial.setTimeout(1);
  ring_pinkie.attach(11);
  middle.attach(6);
  index.attach(10);
  thumb.attach(9);
}

void loop() {


if(Serial.available() > 0){


  // char data = Serial.read();
  // char str[2];
  // str[0] = data;
  // str[1] = '\0';
  // Serial.print(str);

  x = Serial.readString().toInt();
  // Serial.print(x + 1);

    
  if(x == 3){
    ring_pinkie.write(180);
    middle.write(180);
    index.write(0);
    thumb.write(0);
    delay(800);
  }
  else if(x == 2){
    ring_pinkie.write(0);
    middle.write(0);
    index.write(180);
    thumb.write(180);
    delay(800);
  }
  else if(x == 1){
    ring_pinkie.write(180);
    middle.write(0);
    index.write(180);
    thumb.write(0);
    delay(800);
  }
  else if(x == 0){
    ring_pinkie.write(180);
    middle.write(0);
    index.write(0);
    thumb.write(0);
    delay(800);
  }
  else{
      Serial.println("Invalid commands");
  }

}
}