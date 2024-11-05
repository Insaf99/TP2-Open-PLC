# TP2-Open-PLC

# El objetivo del programa es monitorear y alertar sobre inclinaciones peligrosas en una grúa torre, garantizando la seguridad en una obra de construcción de altura. Este sistema detecta inclinaciones en los ejes X (lado a lado) y Y (adelante-atrás) mediante sensores, activando alarmas visuales para indicar la duración de la inclinación. Cuando el sistema detecta inclinaciones prolongadas, activa LEDs de alerta que indican precaución (LED amarillo) o peligro crítico (LED rojo), permitiendo a los operadores tomar acciones preventivas o de emergencia.

# Descripción General del Funcionamiento del Programa:
Detección de Inclinación: Los sensores de inclinación en los ejes X e Y envían una señal cuando detectan una inclinación que supera un umbral seguro. Estas señales activan la lógica del sistema en Ladder Diagram.
Temporización y Control de Alarmas: Una vez que se detecta una inclinación, un temporizador en el programa comienza a contar el tiempo de inclinación. Si la inclinación persiste durante 5 segundos, se activa el LED amarillo como señal de precaución. Si la inclinación continúa por 10 segundos mas, se activa también el LED rojo, indicando un peligro crítico.
Reinicio del Sistema: Cuando ambos sensores indican que la grúa ha vuelto a una posición segura, el temporizador se reinicia automáticamente, y los LEDs se apagan para volver al estado inicial de monitoreo.

Funcionamiento:
Lectura de Sensores (Entradas):
Cada sensor de inclinación, uno para el eje X y otro para el eje Y, está conectado a una entrada digital del controlador.
En LD, se crea una línea de contactos para cada sensor de inclinación. Si cualquiera de estos contactos cierra el circuito (indicando una inclinación detectada), se activa el temporizador.

Activación de Temporizadores:
Una vez que uno de los sensores detecta inclinación, se activa un temporizador TON (temporizador a la conexión). Este temporizador empieza a contar el tiempo de inclinación.
Se utilizan dos temporizadores en paralelo:
Temporizador de Precaución (5 segundos): Activa el LED amarillo si la inclinación supera los 5 segundos.
Temporizador de Peligro (15 segundos): Activa el LED rojo si la inclinación supera los 15 segundos.
Condiciones para la Alerta (Salidas):
LED de Precaución (5 segundos): Si el primer temporizador alcanza 5 segundos, LD activa la bobina correspondiente al LED amarillo.
LED de Peligro (15 segundos): Si el segundo temporizador alcanza 15 segundos, LD activa la bobina del LED rojo, indicando una situación crítica.
Reinicio del Sistema:
En LD, se define una condición de reinicio para el sistema. Si ambos sensores indican que la grúa ha vuelto a su posición vertical (es decir, ambos contactos están abiertos), los temporizadores se reinician y las salidas (LEDs) se apagan, volviendo al estado de monitoreo.

# Descripción Detallada de Cada Bloque o Grupo de Bloques y su Interacción
Bloque de Lectura de Sensores (Entradas)
Función: Este bloque lee el estado de los sensores de inclinación en los ejes X y Y. Cada sensor está representado como un contacto en Ladder Diagram.
Interacción: Cuando uno de los sensores detecta una inclinación que excede el umbral seguro (contacto cerrado), activa los bloques de temporización. Si ambos contactos están abiertos (sin inclinación), no hay activación de temporizadores ni de alertas.
Bloques de Temporización (TON - Temporizador a la Conexión)
Temporizador de Precaución (5 segundos):
Función: Este temporizador comienza a contar cuando se activa la señal de inclinación. Si la inclinación persiste por más de 5 segundos, el temporizador completa su ciclo.
Interacción: Al completar los 5 segundos, activa el siguiente bloque que controla el LED amarillo (indicador de precaución).
Temporizador de Peligro (15 segundos):
Función: Similar al temporizador de precaución, este cuenta 15 segundos a partir de la detección de inclinación. Si se mantiene la inclinación por 15 segundos, el ciclo del temporizador se completa.
Interacción: Al cumplirse los 15 segundos, activa el bloque que enciende el LED rojo (indicador de peligro).
Bloques de Salida para Activación de LEDs (Salidas)
LED Amarillo (Precaución):
Función: Representado por una bobina en Ladder Diagram, este bloque controla el encendido del LED amarillo. Se activa cuando el temporizador de 5 segundos completa su ciclo.
Interacción: Proporciona una alerta visual de precaución al operador, indicando que la inclinación ha persistido por un tiempo prolongado (5 segundos).
LED Rojo (Peligro):
Función: Este bloque controla el encendido del LED rojo, el cual se activa una vez que el temporizador de 15 segundos completa su ciclo.
Interacción: Indica una situación crítica y demanda una acción inmediata por parte del operador, pues la inclinación se ha mantenido por un tiempo de alto riesgo.
Bloque de Reinicio del Sistema
Función: Este bloque monitorea el estado de ambos sensores. Si ambos sensores indican que la grúa ha vuelto a su posición segura (ambos contactos abiertos), los temporizadores y LEDs se reinician.
Interacción: Al detectar que ambos sensores están abiertos (sin inclinación), este bloque restablece los temporizadores y apaga los LEDs, volviendo al estado de monitoreo inicial del sistema
