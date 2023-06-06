# CarroCIDI
Es una implementación en Arduino que permite controlar el movimiento de un vehículo utilizando un puente H y un sensor ultrasónico. La funcionalidad principal del código incluye:

Control de movimiento: El código permite controlar el vehículo para moverse hacia adelante, hacia atrás, hacia la izquierda, hacia la derecha y detenerse. Esto se logra mediante el control de los pines del puente H que controlan los motores del vehículo.

Medición de distancia: Utilizando un sensor ultrasónico, el código es capaz de medir la distancia entre el vehículo y un objeto cercano. Esto se logra mediante la biblioteca NewPing, que facilita las mediciones de distancia utilizando el sensor ultrasónico.

Modo automático: El código también incluye un modo automático en el que el vehículo puede operar de forma autónoma. Cuando se activa el modo automático, el vehículo se moverá hacia adelante hasta que detecte un objeto a una distancia de 10 cm utilizando el sensor ultrasónico. En ese momento, el vehículo se detendrá y cambiará de dirección, permitiendo evitar obstáculos y continuar su recorrido.

Interacción a través de la comunicación serial: El código se comunica con una fuente externa (por ejemplo, una computadora) a través de la comunicación serial. Esto permite enviar comandos de movimiento al vehículo y recibir información sobre la distancia medida por el sensor ultrasónico.

En resumen, el código proporcionado permite controlar el movimiento de un vehículo utilizando un puente H y un sensor ultrasónico. Además, incluye un modo automático que permite al vehículo evitar obstáculos y cambiar de dirección de forma autónoma. Esta funcionalidad es útil en aplicaciones de robótica y vehículos autónomos.
