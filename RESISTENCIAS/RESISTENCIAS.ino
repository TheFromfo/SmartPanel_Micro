//Aquí almacenamos los datos recogidos del LDR:
int valorLDTR = 0;
int valorLDTL = 0;
int valorLDBR = 0;
int valorLDBL = 0;

//Y que pin analógico conectarmos el LDR
int pinLDTR = A0;
int pinLDTL = A1;
int pinLDBL = A2;
int pinLDBR = A3;

void setup()
{

//inicializamos monitor serie para visualizar valores de LDR
Serial.begin(1200);

}

void loop()
{
//Guardamos el valor leido en una variable
//IMPORTANTE UTILIZAR EL SERIAL PARA VER LOS VALORES Y COMPROBAR QUE RECIBE VALORES BUENOS

valorLDTR = analogRead(pinLDTR);
//Serial.print("ValorLDTR: ");
///Serial.println(valorLDTR);

valorLDTL = analogRead(pinLDTL);
//Serial.print("ValorLDTL: ");
//Se/rial.println(valorLDTL);

valorLDBL = analogRead(pinLDBL);
//Serial.print("ValorLDBL: ");
//Serial.println(valorLDBL);

valorLDBR = analogRead(pinLDBR);
//Serial.print("ValorLDBR: ");
//Serial.println(valorLDBR);

String datos = "A:" + String(valorLDTR) + " B:" + String(valorLDTL) + " C:" + String(valorLDBR) + " D:" + String(valorLDBL);
Serial.println(datos); 

}
