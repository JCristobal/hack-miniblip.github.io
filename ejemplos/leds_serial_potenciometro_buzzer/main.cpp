// potenciometro controla la matriz 
// y buzzer al mismo tiempo envia por 
// el puerto serie

#include "mbed.h"
#include "neopixel.h"
#include "USBSerial.h"

// Matrix led output pin
#define MATRIX_PIN P0_9
#define NLEDS 25


AnalogIn   ain(P0_22);

unsigned int counter = 0;   
USBSerial serial;

neopixel::Pixel buffer[NLEDS];
PwmOut speaker(P0_8);


void setPixel(uint32_t posicion, uint8_t red, uint8_t green, uint8_t blue) {
  buffer[posicion].red=red;
  buffer[posicion].green=green;
  buffer[posicion].blue=blue;
}


int main()
{
    // Turn off miniblip buzzer
    speaker=0.0;

    serial.printf("Hello world!\n");    
    while(true) {   
        float pot = ain.read() * 100.0f;
        serial.printf("mini blip is alive for %i seconds.\n", counter);
        serial.printf("Pot: %3.3f%%\n", pot);
        counter++;  
    
        neopixel::PixelArray array(MATRIX_PIN);
        for(int i=0;i<NLEDS;i++) {
            setPixel(i, pot, 0, 0);
        }
        
        float note=500+(pot);
        speaker.period(1.0/note);           
        speaker = 50.0;
        
        array.update(buffer, NLEDS);
        //wait(1);    

    }
    
    //
//    // Create a temporary DigitalIn so we can configure the pull-down resistor.
//    DigitalIn(DATA_PIN, PullDown);
//
//    // The pixel array control class.
//    neopixel::PixelArray array(DATA_PIN);
//
//    uint32_t offset = 0;
//    uint32_t i = 1;
//    while (1) {
//        array.update(generate, 64, offset++);
//        
//        //Play Sound
//        float note=500+(i*100);
//        speaker.period(1.0/note);           
//        //speaker = float(i)/50.0;
//        
//        i++;
//        if (i>10) i=1;
//        // Rainbow delay
//        wait_ms(100);
//    }
}


