#ifndef __MENU_H__
#define __MENU_H__
#include <Arduino.h>
#include <ps2.h>
#include <ui.h>


class MENU
{
    public:
        uint8_t func_index=0;
        uint8_t last_index=1;
        struct key_table
        {
            uint8_t current;
            uint8_t left;
            uint8_t right;
            uint8_t up;
            uint8_t down;
            uint8_t enter;
            void (*current_operation)(U8G2SSD1306UI::ui_element_t*);
        };
    MENU(MENU::key_table* tables,U8G2SSD1306UI::ui_element_t* ui_elements,uint8_t elements_len);
    void menu_begin();
    void menu_control(PS2::key_state_t& key_state);
    static void s_menu_proc();

    private:
    static MENU* s_instance;
    void (*current_operation_index)(U8G2SSD1306UI::ui_element_t*);
    key_table* menu_tables;
    U8G2SSD1306UI::ui_element_t* ui_elements;
    uint8_t elements_len;
    PS2::key_state_t last_key_state;

    void menu_proc();

};



#endif