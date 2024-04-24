#include "mbed.h"
#include "arm_book_lib.h"

#define ORIGINAL_CODE
//#define MODIFIED_CODE

int main()
{
#ifdef ORIGINAL_CODE

    DigitalIn gasDetector(D2);
    DigitalIn overTempDetector(D3);
    DigitalIn alarmOffButton(BUTTON1);

    DigitalOut alarmLed(LED1);

    gasDetector.mode(PullDown);
    overTempDetector.mode(PullDown);

    alarmLed = OFF;

    bool alarmState = OFF;

    while (true) {

        if ( gasDetector || overTempDetector ) {
            printf("\nDetector de gas\n");
            printf("gasDetector: %d\n", gasDetector.read());
            printf("\n\nDetector de Temperatura\n");
            printf("overTempDetector: %d\n", overTempDetector.read());
            alarmState = ON;
            printf("alarmLed: %d\n", alarmLed.read());
        }

        alarmLed = alarmState;

        if ( alarmOffButton ) {
            alarmState = OFF;
            printf("\nalarmLed: %d\n", alarmLed.read());
        }
    }

#elif defined MODIFIED_CODE
    //!< @note En esta seccion coloco el codigo modificado. En este caso, voy a modificar el codigo original para realizar el manejo de gasDetector, overTempDetector y alarmLed sin C++

    gpio_t gasDetector;
    gpio_init_in(&gasDetector, D2);

    gpio_t overTempDetector;
    gpio_init_in(&overTempDetector, D3);

    gpio_t alarmOffButton;
    gpio_init_in(&alarmOffButton, BUTTON1);


    gpio_t alarmLed;
    gpio_init_out(&alarmLed, LED1);

    gpio_mode(&gasDetector, PullDown);

    gpio_mode(&overTempDetector, PullDown);

    gpio_write(&alarmLed, OFF);

    bool alarmState = OFF;

    while (true) 
    {
        if ( gpio_read(&gasDetector) || gpio_read(&overTempDetector) ) 
        {
            printf("\nDetector de gas\n");
            printf("gasDetector = %d\n", gpio_read(&gasDetector));
            printf("\n\nDetector de Temperatura\n");
            printf("overTempDetector = %d\n", gpio_read(&overTempDetector));
            printf("\n\nEstado de la alarma:\n");

            alarmState = ON;

            if (alarmState){
                printf("alarmState = ON\n");
            } else printf("alarmState = OFF\n");
        }

        gpio_write(&alarmLed, alarmState);

        if ( gpio_read(&alarmOffButton) ) 
        {
            printf("\nDetector de gas\n");
            printf("gasDetector = %d\n", gpio_read(&gasDetector));
            printf("\n\nDetector de Temperatura\n");
            printf("overTempDetector = %d\n", gpio_read(&overTempDetector));
            printf("\n\nEstado de la alarma:\n");
            
            alarmState = OFF;

            if (alarmState){
                printf("alarmState = ON\n");
            } else printf("alarmState = OFF\n");
        }
    }
    
#endif
}