#ifndef __PS2_H__
#define __PS2_H__
#include <Arduino.h>


class PS2
{  
    uint8_t key_x_pin,key_y_pin,key_sw_pin;
    public:
    enum key_state_t
    {   
        key_idle,
        key_up,
        key_down,
        key_left,
        key_right,
        key_press
    };

    struct key_value_t
    {
        uint16_t x_value;
        uint16_t y_value;
        int sw_value;
    };
    
    key_state_t key_state;
    PS2(uint8_t x_pin,uint8_t y_pin,uint8_t sw_pin);

    void begin();
    key_state_t get_key_state();
    
    private:
    uint16_t xdefault_value;
    uint16_t ydefault_value;
    uint16_t diff_value;
    key_value_t read_key_value();
    void set_default_key_value();
    

};
#endif