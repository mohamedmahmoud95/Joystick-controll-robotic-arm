#include <Servo.h>    //loading the servo library
int basePos= 0; int rightPos = 0; int leftPos = 0; int gripperPos = 0;  //positions of Servo motors


Servo baseServo; //create a servo object
Servo rightServo;
Servo leftServo;
Servo gripperServo;

int x = 8 ;  //delay to change motor rotation speed
int b,r,l,g ;    // base motor and right motor positions
int pot1=A1; int pot2=A2, pot3=A3, pot4 = A4; //connections of potentiometers
int v1 , v2, v3 , v4 ;   //values of potentiometers
int counter = 0, state=0, laststate=0;

void setup() {
pinMode(2,INPUT_PULLUP); //setting pin 2 as an input pin
//pullup is for the pullup resistor
Serial.begin(9600);
baseServo.attach(3); //servo connection (to a PWM pin)
rightServo.attach(5);
leftServo.attach(6);
gripperServo.attach(9);

leftServo.write(5); //set the start position to angle 5

}
 
void loop() {  
  int state = digitalRead(2);
if(state !=laststate)
{
if (state==HIGH)
{
  counter++;
  Serial.println(counter);
}
else
{counter= counter;}
laststate=state;

}
if(counter%2==0)
gripperServo.write(15);  //close the gripper
else if (counter%2!=0)
gripperServo.write(100); //open the gripper

v1 = analogRead ( pot1 );
Serial.print("the is v1: ");
Serial.println(v1); //to print the range of values of pot 1 , you may remove it.
b = map ( v1 , 0 , 1014 , 10 , 170);
if (basePos<b)
{
  for ( ; basePos<b ; basePos++)
  {
    baseServo.write( basePos );
    delay(x); 
  } 

  
}
if (basePos>b)
{
  for ( ; basePos>b ; basePos--)
  {
    baseServo.write( basePos );
    delay(x); 
  } 
}

v2 = analogRead ( pot2 );
r = map ( v2 , 0 , 1014 , 170 , 10);
if (rightPos<r)
{
  for ( ; rightPos<r ; rightPos++)
  {
    rightServo.write( rightPos );

    delay(x); 
  }
  
}
if (rightPos>r)
{
  for ( ; rightPos>r ; rightPos--)
  {
    rightServo.write( rightPos );

    delay(x); 
  }
}



v3 = analogRead ( pot3 );
Serial.println(v3);
l = map ( v3 , 0 , 1014 , 10 , 170);
if (leftPos<l)
{
  for ( ; leftPos<l ; leftPos++)
  {
    leftServo.write( leftPos );
    delay(x); 
  } 

  
}
if (leftPos>l)
{
  for ( ; leftPos>l ; leftPos--)
  {
    leftServo.write( leftPos );
    delay(x); 
  } 
}


v4 = analogRead ( pot4);
Serial.print("the is v4: ");
Serial.println(v4); //to print the range of values of pot 1 , you may remove it.
g = map ( v4 , 0 , 1014 , 10 , 170);
if (gripperPos<g)
{
  for ( ; gripperPos<g ; gripperPos++)
  {
    gripperServo.write( gripperPos );
    delay(x); 
  } 

  
}
if (gripperPos>b)
{
  for ( ; gripperPos>g ; gripperPos--)
  {
    gripperServo.write( gripperPos );
    delay(x); 
  } 
}


}
