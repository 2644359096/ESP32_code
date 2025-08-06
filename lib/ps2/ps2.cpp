#include "ps2.h"



PS2::PS2(uint8_t x_pin,uint8_t y_pin,uint8_t sw_pin){
    key_x_pin=x_pin;
    key_y_pin=y_pin;
    key_sw_pin=sw_pin;
    
}

void PS2::begin(){
    pinMode(key_sw_pin,INPUT_PULLUP);
    set_default_key_value();
    // digitalWrite(key_sw_pin,HIGH);
}


PS2::key_value_t PS2::read_key_value(){
    return {analogRead(key_x_pin),analogRead(key_y_pin),digitalRead(key_sw_pin)};
}
void PS2::set_default_key_value(){
    key_value_t key_value=read_key_value();
    xdefault_value=key_value.x_value/100*100;
    ydefault_value=key_value.y_value/100*100;
    diff_value=(xdefault_value+ydefault_value)/4;
}

PS2::key_state_t PS2::get_key_state(){
    key_value_t current_value=read_key_value();
    if (current_value.sw_value==0) return key_press;
    else if (current_value.x_value-xdefault_value<-diff_value) return key_right;
    else if (current_value.y_value-ydefault_value>diff_value) return key_down;
    else if (current_value.y_value-ydefault_value<-diff_value) return key_up;
    else if (current_value.x_value-xdefault_value>diff_value) return key_left;
    else return key_idle;
    

}