#ifndef __UI_H__
#define __UI_H__
#include <Arduino.h>
#include <U8g2lib.h>
#include <tools.h>
#include <game.h>

class Game;
class Bullet;
class Rock;
class Plane;

class U8G2SSD1306UI
{   
    
    uint8_t font_width,font_height;
    uint8_t screen_width,screen_height;
    uint8_t game_screen_width=90;
    Rect game_screen_rect;
    public:
        
        struct ui_element_t
        {   
            uint8_t id;
            uint16_t x;
            uint16_t y;
            uint16_t w;
            uint16_t h;

        };

        struct ui_list_t
        {
            const char* str;
            byte str_len;
        };
        enum ui_layout
        {
            CENTER,
            MIDLEFT,
            MIDRIGHT,
            MIDTOP,
            MIDBUTTOM,
            TOPLEFT,
            BUTTOMLEFT,
            TOPRIGHT,
            BUTTOMRIGHT
        };
        ui_element_t* current_ui_element;

        explicit U8G2SSD1306UI(U8G2_SSD1306_128X64_NONAME_1_HW_I2C& u8g2):u8g2_class(u8g2){}
        // U8G2SSD1306UI(U8G2_SSD1306_128X64_NONAME_1_HW_I2C* u8g2,Game* game);
        void ui_begin(PS2& ps2);
        void ui_update(void_func_t* funcs,uint8_t funcs_num);
        void set_list(ui_list_t* list,uint8_t list_length);
        void set_current_ui_element(ui_element_t* ui_element);

        //静态桥接——静态桥接函数
        static void s_draw_logo(U8G2SSD1306UI::ui_element_t* current_ui_element){s_instance->set_current_ui_element(current_ui_element);s_instance->draw_logo();}
        static void s_draw_menu_start(U8G2SSD1306UI::ui_element_t* current_ui_element){s_instance->set_current_ui_element(current_ui_element);s_instance->draw_menu_start();}
        static void s_draw_menu_help(U8G2SSD1306UI::ui_element_t* current_ui_element){s_instance->set_current_ui_element(current_ui_element);s_instance->draw_menu_help();}
        static void s_draw_menu_top_score(U8G2SSD1306UI::ui_element_t* current_ui_element){s_instance->set_current_ui_element(current_ui_element);s_instance->draw_menu_top_score();}
        static void s_draw_menu_back_logo(U8G2SSD1306UI::ui_element_t* current_ui_element){s_instance->set_current_ui_element(current_ui_element);s_instance->draw_menu_back_logo();}
        static void s_draw_game_ui(U8G2SSD1306UI::ui_element_t* current_ui_element){s_instance->set_current_ui_element(current_ui_element);s_instance->draw_game_ui();}
        static void s_draw_game_back_memu(U8G2SSD1306UI::ui_element_t* current_ui_element){s_instance->set_current_ui_element(current_ui_element);s_instance->draw_game_back_memu();}
        static void s_draw_help_context(U8G2SSD1306UI::ui_element_t* current_ui_element){s_instance->set_current_ui_element(current_ui_element);s_instance->draw_help_context();}
        static void s_draw_help_back_menu(U8G2SSD1306UI::ui_element_t* current_ui_element){s_instance->set_current_ui_element(current_ui_element);s_instance->draw_help_back_menu();}
        static void s_draw_top_ui(U8G2SSD1306UI::ui_element_t* current_ui_element){s_instance->set_current_ui_element(current_ui_element);s_instance->draw_top_ui();}
        static void s_draw_top_back_menu(U8G2SSD1306UI::ui_element_t* current_ui_element){s_instance->set_current_ui_element(current_ui_element);s_instance->draw_top_back_menu();}

    private:
        //静态桥接——静态指针
        static  U8G2SSD1306UI* s_instance;
        U8G2_SSD1306_128X64_NONAME_1_HW_I2C& u8g2_class;
        Game game_class;
        

        ui_list_t* ui_list;
        uint8_t ui_list_length;
        int  set_offset_vlaue(short *val,short *target_val,uint8_t speed);
        void set_ui_layout(ui_layout layout);
        void draw_list();
        //第一级：logo界面
        void draw_logo();                       //id:0  L:0,R:0,U:0,D:0,E:1

        //第二级：菜单界面
        void draw_menu_start();                 //id:1  L:4,R:2,U:4,D:2,E:5
        void draw_menu_help();                  //id:2  L:1,R:3,U:1,D:3,E:7
        void draw_menu_top_score();             //id:3  L:2,R:4,U:2,D:4,E:9
        void draw_menu_back_logo();             //id:4  L:3,R:1,U:3,D:1,E:0

        //第三级：1.游戏界面 2.帮助界面 3.排名界面 
        //1.游戏界面
        void draw_game_ui();                    //id:5  L:5,R:5,U:5,D:5,E:6
        void draw_game_back_memu();             //id:6  L:5,R:5,U:5,D:5,E:1
        //2.帮助界面                
        void draw_help_context();               //id:7  L:8,R:8,U:7,D:7,E:8
        void draw_help_back_menu();             //id:8  L:7,R:7,U:8,D:8,E:1
        //3.排名界面
        void draw_top_ui();                     //id:9  L:10,R:10,U:9,D:9,E:10
        void draw_top_back_menu();              //id:10 L:9,R:9,U:10,D:10,E:1
};

#endif