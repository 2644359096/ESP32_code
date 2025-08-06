// #include <Arduino.h>     
// #include <U8g2lib.h>
// #include <Wire.h>
// #include <tools.h>
// #include <ps2.h>
// #include <ui.h>
// #include <menu.h>
// #include <game.h>

// U8G2_SSD1306_128X64_NONAME_1_HW_I2C u8g2(U8G2_R0, /* clock=*/ 16, /* data=*/ 17, /* reset=*/ U8X8_PIN_NONE);

// U8G2SSD1306UI::ui_list_t text_list[]={
//       {"abc",3},
//       {"app",3},
//       {"china",5},
//       {"apple",5},
//       {"server",6}
//     };

// U8G2SSD1306UI::ui_element_t ui_elements[]={
//   {.id=0,.x=0,.y=0,.w=128,.h=64},
//   {.id=1,.x=0,.y=0,.w=64,.h=64},
//   {.id=2,.x=0,.y=0,.w=64,.h=64},
//   {.id=3,.x=0,.y=0,.w=64,.h=64},
//   {.id=4,.x=0,.y=0,.w=64,.h=64},
//   {.id=5,.x=0,.y=0,.w=128,.h=64},
//   {.id=6,.x=0,.y=0,.w=64,.h=64},
//   {.id=7,.x=0,.y=0,.w=64,.h=64},
//   {.id=8,.x=0,.y=0,.w=64,.h=64},
//   {.id=9,.x=0,.y=0,.w=64,.h=64},
//   {.id=10,.x=0,.y=0,.w=64,.h=64},
// };
// /* 定义并赋值全局指针 */
// U8G2SSD1306UI ui(u8g2);
// U8G2SSD1306UI* U8G2SSD1306UI::s_instance = &ui;

// MENU::key_table tables[]={
//     {.current=0,.left=0,.right=0,.up=0,.down=0,.enter=1,.current_operation=ui.s_draw_logo},
//     {.current=1,.left=4,.right=2,.up=4,.down=2,.enter=5,.current_operation=ui.s_draw_menu_start},
//     {.current=2,.left=1,.right=3,.up=1,.down=3,.enter=7,.current_operation=ui.s_draw_menu_help},
//     {.current=3,.left=2,.right=4,.up=2,.down=4,.enter=9,.current_operation=ui.s_draw_menu_top_score},
//     {.current=4,.left=3,.right=1,.up=3,.down=1,.enter=0,.current_operation=ui.s_draw_menu_back_logo},
//     {.current=5,.left=5,.right=5,.up=5,.down=5,.enter=6,.current_operation=ui.s_draw_game_ui},
//     {.current=6,.left=5,.right=5,.up=5,.down=5,.enter=1,.current_operation=ui.s_draw_game_back_memu},
//     {.current=7,.left=8,.right=8,.up=7,.down=7,.enter=8,.current_operation=ui.s_draw_help_context},
//     {.current=8,.left=7,.right=7,.up=8,.down=8,.enter=1,.current_operation=ui.s_draw_help_back_menu},
//     {.current=9,.left=10,.right=10,.up=9,.down=9,.enter=10,.current_operation=ui.s_draw_top_ui},
//     {.current=10,.left=9,.right=9,.up=10,.down=10,.enter=1,.current_operation=ui.s_draw_top_back_menu},
// };
// MENU menu(tables,ui_elements,11);
// MENU* MENU::s_instance=&menu;

// #define KEY_X_PIN 2
// #define KEY_Y_PIN 15
// #define KEY_SW_PIN 4

// PS2 my_ps2(KEY_X_PIN,KEY_Y_PIN,KEY_SW_PIN);
// void setup(){
//     Serial.begin(115200);
//     my_ps2.begin();
//     Wire.begin();
//     ui.ui_begin(my_ps2);
//     menu.menu_begin();
//     ui.set_list(text_list,5);
//     ui.set_current_ui_element(&ui_elements[0]);

// }

// void_func_t funcs[]={
//   {.func=menu.s_menu_proc}
// };
// void loop(){
//   PS2::key_state_t key_state = my_ps2.get_key_state();
//   menu.menu_control(key_state);
//   ui.ui_update(funcs,1);
//   delay(200);
// }
// main.cpp
#include <Arduino.h>
#include "my_hal.h"
#include "astra_rocket.h"
#include "astra_logo.h"

void setup()
{
 // put your setup code here, to run once:
  astraCoreInit();
}

void loop()
{
  // put your main code here, to run repeatedly:
  astraLauncher->update();
}