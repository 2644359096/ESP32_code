#ifndef __GAME_H__
#define __GAME_H__
#include <Arduino.h>
#include <U8g2lib.h>
#include <ps2.h>
#include <tools.h>

struct Rect {
  int16_t x, y, w, h;
  int16_t left=x;
  int16_t right=x+w;
  int16_t top=y;
  int16_t bottom=y+h;
  bool hit(const Rect& r) const {
    return !(x + w < r.x || r.x + r.w < x || y + h < r.y || r.y + r.h < y);
  }
};

/*---------------- 子弹 ----------------*/
class Bullet {
    public:
        Bullet(){};
        Rect rect{0, 0, 3, 3};
        bool alive = false;
        void spawn(int16_t px, int16_t py);
        void update();
        void draw(U8G2_SSD1306_128X64_NONAME_1_HW_I2C& u8g2) const;
    };

/*---------------- 陨石 ----------------*/
class Rock {
    public:
        Rock(){};
        Rect rect{0, 0, 6, 6};
        bool alive = false;
        void begin(Rect game_screen);
        void spawn();
        void update();
        void draw(U8G2_SSD1306_128X64_NONAME_1_HW_I2C& u8g2) const;
    private:
        Rect game_screen_rect;
    };


/*---------------- 飞机 ----------------*/
class Plane {
    public:
        boolean alive = true;
        Plane(){}
        void begin(PS2& ps2,Rect screen);
        Rect rect{56, 56, 16, 8};
        void plane_control();
        void update();
        void draw(U8G2_SSD1306_128X64_NONAME_1_HW_I2C& u8g2) const;
    private:
        PS2* ps2_class;
        Rect game_screen_rect;
        
};




/*---------------- 游戏管理 ----------------*/
class Game {
    uint16_t score = 0;
    static const uint8_t bullet_cnt_max = 2;
    uint8_t nextIdx = 0;
    Rect screen_rect;
    public:
        
        Game(){};
        void begin(Rect screen,Rect game_screen,PS2& ps2);
        void spawn_bullets();
        void update_bullets();
        void draw_bullets(U8G2_SSD1306_128X64_NONAME_1_HW_I2C& u8g2) const;
        void collision();
        void draw_game_over(U8G2_SSD1306_128X64_NONAME_1_HW_I2C& u8g2);
        void update();
        void draw(U8G2_SSD1306_128X64_NONAME_1_HW_I2C& u8g2);
        void loop(U8G2_SSD1306_128X64_NONAME_1_HW_I2C& u8g2);
    private:
        boolean is_game_over=false;
        Bullet bullet;
        Rock rock;
        Plane plane;
        Rect game_screen_rect;
        Bullet bullets[bullet_cnt_max];
};
#endif