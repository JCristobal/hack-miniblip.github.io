# Haciendo una pausa

       wait_ms(100); // Milisegundos


# Defines de los pines

    #define MATRIX_PIN P0_9
    #define LDR_PIN P0_16
    #define SPEAKER_PIN P0_8
    #define POTENCIOMETER_PIN P0_22
    #define BUTTON_PIN P0_23
    #define RESET_PIN P0_1

    #define NLEDS 25

# Sonidos

    PwmOut speaker(SPEAKER_PIN); // el P0_8
    float note=440;
    speaker.period(1.0/note);  // Usamos el periodo, inverso de la frecuencia          
    speaker = 50.0;  // establecemos el volumen


# Lectura de valores analógicos

## Potenciometro

    AnalogIn   ain(POTENCIOMETER_PIN);
    float valorPot=ain.read();

# Escritura por el puerto serie

    // Importamos la librería USBDevice
    #include "USBSerial.h"

    USBSerial serial;

    serial.printf("Hello world!\n");

    // Podemos usar el ejemplo en python ./ejemplos/leds_serial_potenciometro_buzzer/pythonserial.py 
# Botones

    // Definimos el pin como entrada
    DigitalIn pushbutton(BUTTON_PIN);

    // Definimos el pin como PWM
    PwmOut speaker(P0_8);

    while(true){

      if(pushbutton){ // Al pulsar suena
          speaker=10.0;
      }else{
          speaker=0.0;    
      }
    }
