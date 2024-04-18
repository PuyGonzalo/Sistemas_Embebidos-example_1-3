#include "mbed.h"
#include "arm_book_lib.h"

int main()
{
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
            printf("Detector de gas\n");
            printf("gasDetector: %d\n", gasDetector.read());
            printf("%s\n", " ");
            printf("Detector de Temperatura\n");
            printf("overTempDetector: %d\n", overTempDetector.read());
            alarmState = ON;
            printf("alarmLed: %d\n", alarmLed.read());
        }

        alarmLed = alarmState;

        if ( alarmOffButton ) {
            alarmState = OFF;
            printf("%s\n", " ");
            printf("alarmLed: %d\n", alarmLed.read());
        }
    }
}