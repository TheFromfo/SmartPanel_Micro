#include <Servo.h> // include Servo library

Servo vertical; // vertical servo

int servov = 45; // 90; // stand vertical servo

int servovLimitHigh = 170;
int servovLimitLow = 10;

//Aquí almacenamos los datos recogidos del LDR:
int valorLDTR = 0;
int valorLDTL = 0;
int valorLDBR = 0;
int valorLDBL = 0;

// LDR pin connections
// name = analogpin;

int pinLDRBL = A0; //LDR top left - BOTTOM LEFT <--- BDG

int pinLDRBR = A1; //LDR top rigt - BOTTOM RIGHT

int pinLDRTL = A2; //LDR down left - TOP LEFT

int pinLDRTR = A3; //ldr down rigt - TOP RIGHT

void setup()
{ Serial.begin(1200);

// servo connections

// name.attacht(pin);

vertical.attach(9);

vertical.write(45);

delay(3000);

}

void loop()
{ 

valorLDTR = analogRead(pinLDRTR);

valorLDTL =  analogRead(pinLDRTL);

valorLDBL = analogRead(pinLDRBL);

valorLDBR = analogRead(pinLDRBR);


int lt = analogRead(pinLDRTL); // top left

int rt = analogRead(pinLDRTR); // top right

int lb = analogRead(pinLDRBL); // down left

int rb = analogRead(pinLDRBR); // down right

// int dtime = analogRead(4)/20; // read potentiometers

 //int tol = analogRead(5)/4;

int avgtop = (lt + rt) / 2; // average value top

int avgbot= (lb + rb) / 2; // average value down

int dtime = 10; int tol = 50;

int dvert = avgtop - avgbot; // check the diffirence of up and down 

String datos = "TR:" + String(valorLDTR) + " TL:" + String(valorLDTL) + " BR:" + String(valorLDBR) + " BL:" + String(valorLDBL) + " PromTOP: " + String(avgtop) + " PromBot: " + String(avgbot) ;
Serial.println(datos); 


if (-1*tol > dvert || dvert > tol) // check if the diffirence is in the tolerance else change vertical angle

{

if (avgtop > avgbot)

{

servov = ++servov;

if (servov > servovLimitHigh)

{

servov = servovLimitHigh;

}

}

else if (avgtop < avgbot)

{

servov= --servov;

if (servov < servovLimitLow)

{

servov = servovLimitLow;

}

}

vertical.write(servov);

} }
