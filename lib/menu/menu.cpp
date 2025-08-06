#include "menu.h"


MENU::MENU(MENU::key_table* tables,U8G2SSD1306UI::ui_element_t* menu_ui_elements,uint8_t elements_length){
    menu_tables=tables;
    ui_elements=menu_ui_elements;
    elements_len=elements_length;
}

void MENU::menu_begin(){
    
}

void MENU::menu_control(PS2::key_state_t &key_current_state){
    if(key_current_state==last_key_state) return;
    switch (key_current_state)
    {
    case PS2::key_up:func_index = menu_tables[func_index].up;  break;
    case PS2::key_down:func_index = menu_tables[func_index].down; break;
    case PS2::key_left:func_index = menu_tables[func_index].left; break;
    case PS2::key_right:func_index = menu_tables[func_index].right; break;
    case PS2::key_press:func_index = menu_tables[func_index].enter; break;
    }
    last_key_state=key_current_state;

}

void MENU::menu_proc(){
    
    if (func_index != last_index)
    {   
        current_operation_index = menu_tables[func_index].current_operation;
        
        last_index = func_index;
    }
    for(uint8_t i=0;i<elements_len;i++){
            if(ui_elements[i].id==func_index){
                
                (*current_operation_index)(&ui_elements[i]);//执行当前操作函数
            }
        }
}

void MENU::s_menu_proc(){
        s_instance->menu_proc();
    }
