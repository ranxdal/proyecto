#include<Servo.h>
//Asignación de puertos del arduino..               
Servo servomeca; //servo
int MotorD = 2;  //motor
int infra = 7;   //receptor infrarrojo
//variables globales
int valor = 0;  //almacenamiento y lectura del infrarrojo
char a;         //almcenamiento y lectura puerto serial
int b = 5;
void setup() {
	//inicio del puerto serial
	Serial.begin(9600);
	//declaracion de entradas y salidas
	pinMode(MotorD, OUTPUT);
	pinMode(infra, INPUT);
	servomeca.attach(3);
    Serial.print(" ");
    Serial.println("Banda Transportadora Grupo No.2:");
    Serial.println("1. c para arrancar la banda.");
    Serial.println("2. v para detener la banda");
    Serial.println("3. n para abrir la caja.");
}


void loop() {
    valor = digitalRead(infra);
    if (Serial.available() > 0) {
        a = Serial.read();
        switch (a) {
        case 'c':
        digitalWrite(MotorD, 1);
        b = 1;
        break;
        case 'v':
        digitalWrite(MotorD, 0);
        b = 5;
        break;
        case 'n':
        servomeca.write(360);
      	delay(450);
      	servomeca.write(90);
        delay(500);
        servomeca.write(0);
        delay(450);
        servomeca.write(90);
        delay(500);
	      break;
        }

    }
    if (valor == 0) {
        digitalWrite(MotorD, 0);
        a = 'c';
    }if (valor == 1 && a == 'c') {
        digitalWrite(MotorD,1);
}
}