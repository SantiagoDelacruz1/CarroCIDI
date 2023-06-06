#include <NewPing.h>

// Definición de pines del puente H
const int motorPin1 = 2;  // Pin de control 1 del puente H
const int motorPin2 = 3;  // Pin de control 2 del puente H

// Definición de pines del sensor ultrasónico
const int trigPin = 4;    // Pin de salida del trigger del sensor ultrasónico
const int echoPin = 5;    // Pin de entrada del eco del sensor ultrasónico

// Definición del objeto del sensor ultrasónico
NewPing sonar(trigPin, echoPin);

// Modo automático activado o desactivado
bool modoAutomatico = false;

void setup() {
  // Configuración de pines de salida
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);

  // Inicialización de comunicación serial
  Serial.begin(9600);
}

void loop() {
  // Recibir el comando de movimiento desde la comunicación serial
  char comando = recibirComando();

  // Realizar acciones basadas en el comando recibido
  if (comando == 'F') {
    moverAdelante();
  } else if (comando == 'B') {
    moverAtras();
  } else if (comando == 'L') {
    moverIzquierda();
  } else if (comando == 'R') {
    moverDerecha();
  } else if (comando == 'S') {
    frenar();
  } else if (comando == 'A') {
    activarModoAutomatico();
  }

  // Modo automático activo
  if (modoAutomatico) {
    // Medir la distancia utilizando el sensor ultrasónico
    int distancia = medirDistancia();

    // Realizar acciones basadas en la distancia medida
    if (distancia <= 10) {
      // Si la distancia es menor o igual a 10 cm, detenerse y cambiar de dirección
      frenar();
      delay(1000);  // Esperar 1 segundo antes de cambiar de dirección
      cambiarDireccion();
    }
  }

  delay(100);  // Pequeña pausa entre iteraciones
}




