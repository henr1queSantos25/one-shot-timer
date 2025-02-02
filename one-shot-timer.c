#include <stdio.h> 
#include "pico/stdlib.h"
#include "pico/time.h"  

const uint LED_GREEN = 11;
const uint LED_BLUE = 12; 
const uint LED_RED = 13; 
const uint BUTTON = 5;  

#define intervalo 3000

bool volatile emProgresso = false;
void initLEDs();
void setLEDs(bool r, bool g, bool b);

int64_t desligados(alarm_id_t id, void *user_data);
int64_t um_ligado(alarm_id_t id, void *user_data);
int64_t dois_ligados(alarm_id_t id, void *user_data);
int64_t tres_ligados(alarm_id_t id, void *user_data);

int main() {

    stdio_init_all();
    initLEDs();

    gpio_init(BUTTON);
    gpio_set_dir(BUTTON, GPIO_IN);
    gpio_pull_up(BUTTON);

   
    while (true) {

        if(!gpio_get(BUTTON) && !emProgresso){
            sleep_ms(50);
            if(!gpio_get(BUTTON)){
                emProgresso = true;
                add_alarm_in_ms(1, tres_ligados, NULL, false);
            }
        }

        sleep_ms(10);

    }


    return 0;
}

void initLEDs(){
    gpio_init(LED_RED);
    gpio_set_dir(LED_RED, GPIO_OUT);
    gpio_init(LED_GREEN);
    gpio_set_dir(LED_GREEN, GPIO_OUT);
    gpio_init(LED_BLUE);
    gpio_set_dir(LED_BLUE, GPIO_OUT);
}

void setLEDs(bool r, bool g, bool b){
    gpio_put(LED_RED, r);
    gpio_put(LED_GREEN, g);
    gpio_put(LED_BLUE, b);
}

int64_t tres_ligados(alarm_id_t id, void *user_data) {
    setLEDs(1, 1, 1);
    add_alarm_in_ms(3000, dois_ligados, NULL, false);
    return 0;
}

int64_t dois_ligados(alarm_id_t id, void *user_data) {
    setLEDs(1, 0, 1);
    add_alarm_in_ms(3000, um_ligado, NULL, false);
    return 0;
}

int64_t um_ligado(alarm_id_t id, void *user_data) {
    setLEDs(1, 0, 0);
    add_alarm_in_ms(3000, desligados, NULL, false);
    return 0;
}

int64_t desligados(alarm_id_t id, void *user_data) {
    setLEDs(0, 0, 0);
    emProgresso = false;
    return 0;
}



