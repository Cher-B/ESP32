
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "led_strip.h"
#include "sdkconfig.h"

//selecting LED to blink
#define PIN 2

static void blinkIt()
{
    gpio_pad_select_gpio(PIN);
    gpio_set_direction(PIN, GPIO_MODE_OUTPUT);
    int isON = 0;
    while (true)
    {   // Set the output as signal isON
        gpio_set_level(PIN, isON);
        // A delay of 2 second
        vTaskDelay(2000 / portTICK_PERIOD_MS);
        
        printf("\nTurning the LED ");
        isON == true ? printf("ON") : printf("OFF");
        // change the value of signal
        isON = !isON;
    }
}

void app_main(void)
{
    blinkIt();
}