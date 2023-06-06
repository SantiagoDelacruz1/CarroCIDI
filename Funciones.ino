char recibirComando() {
  // Esperar la recepción de datos desde la comunicación serial
  while (!Serial.available());
  
  // Leer el comando recibido
  char comando = Serial.read();

  // Devolver el comando recibido
  return comando;
}

int medirDistancia() {
  // Realizar una medición de distancia utilizando el sensor ultrasónico
  unsigned int distancia = sonar.ping_cm();

  // Devolver la distancia medida en centímetros
  return distancia;
}

void moverAdelante() {
  digitalWrite(motorPin1, HIGH);  // Establecer el pin 1 en alto
  digitalWrite(motorPin2, LOW);   // Establecer el pin 2 en bajo
  // Aquí puedes ajustar la velocidad del motor utilizando PWM en el pin de control 1 del puente H
  analogWrite(motorPin1, 255);
}

void moverAtras() {
  digitalWrite(motorPin1, LOW);   // Establecer el pin 1 en bajo
  digitalWrite(motorPin2, HIGH);  // Establecer el pin 2 en alto
  // Aquí puedes ajustar la velocidad del motor utilizando PWM en el pin de control 2 del puente H
  analogWrite(motorPin2, 255);
}

void moverIzquierda() {
  digitalWrite(motorPin1, LOW);   // Establecer el pin 1 en bajo
  digitalWrite(motorPin2, HIGH);  // Establecer el pin 2 en alto
  // Aquí puedes ajustar la velocidad del motor izquierdo utilizando PWM en el pin de control 2 del puente H
  analogWrite(motorPin2, 100);
}

void moverDerecha() {
  digitalWrite(motorPin1, HIGH);  // Establecer el pin 1 en alto
  digitalWrite(motorPin2, LOW);   // Establecer el pin 2 en bajo
  // Aquí puedes ajustar la velocidad del motor derecho utilizando PWM en el pin de control 1 del puente H
  analogWrite(motorPin1, 100);
}

void frenar() {
  digitalWrite(motorPin1, LOW);   // Establecer el pin 1 en bajo
  digitalWrite(motorPin2, LOW);   // Establecer el pin 2 en bajo
}

void activarModoAutomatico() {
  modoAutomatico = true;
}

void cambiarDireccion() {
  // Detener el movimiento actual
  frenar();
  delay(1000);  // Esperar 1 segundo antes de cambiar de dirección

  // Realizar cambio de dirección girando 180 grados
  moverAtras();  // Retroceder
  delay(1000);   // Esperar 1 segundo mientras retrocede

  // Girar hacia la nueva dirección
  moverDerecha();  // Girar a la derecha
  delay(1000);    // Esperar 1 segundo mientras gira

  // Continuar el movimiento en la nueva dirección
  moverAdelante();  // Avanzar hacia la nueva dirección
}



