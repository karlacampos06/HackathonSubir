
#include  <Servo.h>

int Leds[]={2,4,6,8,10,12};

Servo servo1;
Servo servo2;
Servo servo3;
Servo servo4;
Servo servo5;
Servo servo6;

void led1()
{
digitalWrite(Leds[5], HIGH);

}

void led2()
{
digitalWrite(Leds[4], HIGH);
}

void led3()
{
digitalWrite(Leds[3], HIGH);
}

void led4()
{
digitalWrite(Leds[2], HIGH);
}

void led5()
{
digitalWrite(Leds[1], HIGH);
}

void led6()
{
digitalWrite(Leds[0], HIGH);
}

void apagadoLeds()
{
//delay(3000);// tiempo de espera de leds encendidos

digitalWrite(Leds[0],LOW);
//servo1.attach(3);
digitalWrite(Leds[1],LOW);
digitalWrite(Leds[2],LOW);
digitalWrite(Leds[3],LOW);
digitalWrite(Leds[4],LOW);
digitalWrite(Leds[5],LOW);


//servo2.attach(5);
//servo3.attach(7);
//servo4.attach(9);
//servo5.attach(11);
//servo6.attach(13);

delay(750);// tiempo de espera de leds apagados
}

void setup()
{
for(int i = 0; i <= 5; i++ )
{
pinMode(Leds[i], OUTPUT);
}
servo1.attach(3);
servo2.attach(5);
servo3.attach(7);
servo4.attach(9);
servo5.attach(11);
servo6.attach(13);
{
// servo1.attach(1);
//  servo2.attach(2);
//  servo3.attach(3);
//  servo4.attach(4);
//  servo5.attach(5):
//  servo6.attach(6);
}

Serial.begin(115200);
}



void loop()
{
if(Serial.available() >= 0)


{
int informacion = Serial.read();

switch(informacion)
{
case'a':
led1();
  servo1.write(180);
  delay(2000);
  servo1.write(90);
  apagadoLeds();
  delay(2000);
break;

case'b':
led1();
led2();
 servo1.write(180);
 servo2.write(180);
  delay(2000);
 servo1.write(90);
 servo2.write(90);
 apagadoLeds();
  delay(2000);
break;

case'c':
led1();
led4();
 servo1.write(180);
 servo4.write(180);
  delay(2000);
 servo1.write(90);
 servo4.write(90);
 apagadoLeds();
  delay(2000);
break;

case'd':
led1();
led4();
led5();
 servo1.write(180);
 servo4.write(180);
 servo5.write(180);
  delay(2000);
 servo1.write(90);
 servo4.write(90);
 servo5.write(90);
 apagadoLeds();
  delay(2000);
break;

case'e':
led1();
led5();
 servo1.write(180);
 servo5.write(180);
  delay(2000);
 servo1.write(90);
 servo5.write(90);
 apagadoLeds();
  delay(2000);
break;

case'f':
led1();
led2();
led4();
 servo1.write(180);
 servo2.write(180);
 servo4.write(180);
  delay(2000);
 servo1.write(90);
 servo2.write(90);
 servo4.write(90);
 apagadoLeds();
  delay(2000);
break;

case'g':
led1();
led2();
led4();
led5();
 servo1.write(180);
 servo2.write(180);
 servo4.write(180);
 servo5.write(180);
  delay(2000);
 servo1.write(90);
 servo2.write(90);
 servo4.write(90);
 servo5.write(90);
 apagadoLeds();
  delay(2000);
break;

case'h':
led1();
led2();
led5();
 servo1.write(180);
 servo2.write(180);
 servo5.write(180);
  delay(2000);
 servo1.write(90);
 servo2.write(90);
 servo5.write(90);
 apagadoLeds();
  delay(2000);
break;

case'i':
led2();
led4();
 servo2.write(180);
 servo4.write(180);
  delay(2000);
 servo2.write(90);
 servo4.write(90);
 apagadoLeds();
  delay(2000);
break;

case'j':
led2();
led4();
led5();
 servo2.write(180);
 servo4.write(180);
 servo5.write(180);
  delay(2000);
 servo2.write(90);
 servo4.write(90);
 servo5.write(90);
 apagadoLeds();
  delay(2000);
break;

case'k':
led1();
led3();
 servo1.write(180);
 servo3.write(180);
  delay(2000);
 servo1.write(90);
 servo3.write(90);
 apagadoLeds();
  delay(2000);
break;

case'l':
led1();
led2();
led3();
 servo1.write(180);
 servo2.write(180);
 servo3.write(180);
  delay(2000);
 servo1.write(90);
 servo2.write(90);
 servo3.write(90);
 apagadoLeds();
  delay(2000);
break;

case'm':
led1();
led3();
led4();
 servo1.write(180);
 servo3.write(180);
 servo4.write(180);
  delay(2000);
 servo1.write(90);
 servo3.write(90);
 servo4.write(90);
 apagadoLeds();
  delay(2000);
break;

case'n':
led1();
led3();
led4();
led5();
 servo1.write(180);
 servo3.write(180);
 servo4.write(180);
 servo5.write(180);
  delay(2000);
 servo1.write(90);
 servo3.write(90);
 servo4.write(90);
 servo5.write(90);
 apagadoLeds();
  delay(2000);
break;

case'ñ':
led1();
led2();
led4();
led5();
led6();
 servo1.write(180);
 servo2.write(180);
 servo4.write(180);
 servo5.write(180);
 servo6.write(180);
  delay(2000);
 servo1.write(90);
 servo2.write(90);
 servo4.write(90);
 servo5.write(90);
 servo6.write(90);
 apagadoLeds();
  delay(2000);
break;

case'o':
led1();
led3();
led5();
 servo1.write(180);
 servo3.write(180);
 servo5.write(180);
  delay(2000);
 servo1.write(90);
 servo3.write(90);
 servo5.write(90);
 apagadoLeds();
  delay(2000);
break;

case'p':
led1();
led2();
led3();
led4();
 servo1.write(180);
 servo2.write(180);
 servo3.write(180);
 servo4.write(180);
  delay(2000);
 servo1.write(90);
 servo2.write(90);
 servo3.write(90);
 servo4.write(90);
 apagadoLeds();
  delay(2000);
break;

case'q':
led1();
led2();
led3();
led4();
led5();
servo1.write(180);
 servo2.write(180);
 servo3.write(180);
 servo4.write(180);
 servo5.write(180);
   delay(2000);
 servo1.write(90);
 servo2.write(90);
 servo3.write(90);
 servo4.write(90);
 servo5.write(90);
 apagadoLeds();
  delay(2000);
break;

case'r':
led1();
led2();
led3();
led5();
 servo1.write(180);
 servo2.write(180);
 servo3.write(180);
 servo5.write(180);
   delay(2000);
 servo1.write(90);
 servo2.write(90);
 servo3.write(90);
 servo5.write(90);
 apagadoLeds();
  delay(2000);
break;

case's':
led2();
led3();
led4();
 servo2.write(180);
 servo3.write(180);
 servo4.write(180);
  delay(2000);
 servo2.write(90);
 servo3.write(90);
 servo4.write(90);
 apagadoLeds();
  delay(2000);
break;

case't':
led2();
led3();
led4();
led5();
 servo2.write(180);
 servo3.write(180);
 servo4.write(180);
 servo5.write(180);
  delay(2000);
 servo2.write(90);
 servo3.write(90);
 servo4.write(90);
 servo5.write(90);
 apagadoLeds();
  delay(2000);
break;

case'u':
led1();
led3();
led6();
 servo1.write(180);
 servo3.write(180);
 servo6.write(180);
  delay(2000);
 servo1.write(90);
 servo3.write(90);
 servo6.write(90);
 apagadoLeds();
  delay(2000);
break;

case'v':
led1();
led2();
led3();
led6();
 servo1.write(180);
 servo2.write(180);
 servo3.write(180);
 servo6.write(180);
  delay(2000);
 servo1.write(90);
 servo2.write(90);
 servo3.write(90);
 servo6.write(90);
 apagadoLeds();
  delay(2000);
break;

case'w':
led2();
led4();
led5();
led6();
 servo2.write(180);
 servo4.write(180);
 servo5.write(180);
 servo6.write(180);
  delay(2000);
 servo2.write(90);
 servo4.write(90);
 servo5.write(90);
 servo6.write(90);
 apagadoLeds();
  delay(2000);
break;

case'x':
led1();
led3();
led4();
led6();
 servo1.write(180);
 servo3.write(180);
 servo4.write(180);
 servo6.write(180);
  delay(2000);
 servo1.write(90);
 servo3.write(90);
 servo4.write(90);
 servo6.write(90);
 apagadoLeds(); 
  delay(2000);
break;

case'y':
led1();
led3();
led4();
led5();
led6();
 servo1.write(180);
 servo3.write(180);
 servo4.write(180);
 servo5.write(180);
 servo6.write(180);
  delay(2000);
 servo1.write(90);
 servo3.write(90);
 servo4.write(90);
 servo5.write(90);
 servo6.write(90);
 apagadoLeds();
  delay(2000);
break;

case'z':
led1();
led3();
led5();
led6();
 servo1.write(180);
 servo3.write(180);
 servo5.write(180);
 servo6.write(180);
  delay(2000);
 servo1.write(90);
 servo3.write(90);
 servo5.write(90);
 servo6.write(90);
 apagadoLeds();
  delay(2000);
break;

default:
break;

}//FIN del switch(informacion)
}//FIN del if(Serial.available() &gt; 0)

}
