// my_hal.cpp
#include <U8g2lib.h>
#include "my_hal.h"

void MyHAL::_delay(unsigned long _mill)
{
    delayMicroseconds(_mill * 1000);
}

void MyHAL::_u8g2_init()
{
    // esp32 硬件SPI
    u8g2_Setup_ssd1306_128x64_noname_f(&canvasBuffer, U8G2_R0, u8x8_byte_arduino_hw_spi, u8x8_gpio_and_delay_arduino);
    u8x8_SetPin_4Wire_HW_SPI((u8x8_t *)&canvasBuffer, /* cs=*/5, /* dc=*/16, /* reset=*/17);
    u8g2_InitDisplay(&canvasBuffer);
    u8g2_ClearBuffer(&canvasBuffer);
    u8g2_SetPowerSave(&canvasBuffer, 0);
    u8g2_SetFontMode(&canvasBuffer, 1);      /*字体模式选择*/
    u8g2_SetFontDirection(&canvasBuffer, 0); /*字体方向选择*/
    u8g2_SetFont(&canvasBuffer, u8g2_font_wqy12_t_gb2312);
}

void MyHAL::_screenOn()
{
    u8g2_SetPowerSave(&canvasBuffer, 0);
}
void MyHAL::_screenOff()
{
    u8g2_SetPowerSave(&canvasBuffer, 1);
}
void *MyHAL::_getCanvasBuffer()
{
    return u8g2_GetBufferPtr(&canvasBuffer);
}
uint8_t MyHAL::_getBufferTileHeight()
{
    return u8g2_GetBufferTileHeight(&canvasBuffer);
}
uint8_t MyHAL::_getBufferTileWidth()
{
    return u8g2_GetBufferTileWidth(&canvasBuffer);
}

void MyHAL::_canvasClear()
{
    u8g2_ClearBuffer(&canvasBuffer);
}

void MyHAL::_canvasUpdate()
{
    u8g2_SendBuffer(&canvasBuffer);
}
void MyHAL::_setFont(const uint8_t *_font)
{
    u8g2_SetFontMode(&canvasBuffer, 1);      /*字体模式选择*/
    u8g2_SetFontDirection(&canvasBuffer, 0); /*字体方向选择*/
    u8g2_SetFont(&canvasBuffer, _font);
}

uint8_t MyHAL::_getFontWidth(std::string &_text)
{
    return u8g2_GetUTF8Width(&canvasBuffer, _text.c_str());
}
uint8_t MyHAL::_getFontHeight()
{
    return u8g2_GetMaxCharHeight(&canvasBuffer);
}

void MyHAL::_setDrawType(uint8_t _type)
{
    u8g2_SetDrawColor(&canvasBuffer, _type);
}

void MyHAL::_drawPixel(float _x, float _y)
{
    u8g2_DrawPixel(&canvasBuffer, (int16_t)std::round(_x), (int16_t)std::round(_y));
}

void MyHAL::_drawEnglish(float _x, float _y, const std::string &_text)
{
    u8g2_DrawUTF8(&canvasBuffer, (int16_t)std::round(_x), (int16_t)std::round(_y), _text.c_str());
    // u8g2_DrawStr(&canvasBuffer, (int16_t)std::round(_x), (int16_t)std::round(_y), _text.c_str());
}

void MyHAL::_drawChinese(float _x, float _y, const std::string &_text)
{
    u8g2_DrawUTF8(&canvasBuffer, (int16_t)std::round(_x), (int16_t)std::round(_y), _text.c_str());
}

void MyHAL::_drawBMP(float _x, float _y, float _w, float _h, const uint8_t *_bitMap)
{
    u8g2_DrawXBMP(&canvasBuffer, (int16_t)std::round(_x), (int16_t)std::round(_y), (int16_t)std::round(_w), (int16_t)std::round(_h), _bitMap);
}

void MyHAL::_drawBox(float _x, float _y, float _w, float _h)
{
    u8g2_DrawBox(&canvasBuffer, (int16_t)std::round(_x), (int16_t)std::round(_y), (uint8_t)std::round(_w), (uint8_t)std::round(_h));
}

void MyHAL::_drawRBox(float _x, float _y, float _w, float _h, float _r)
{
    u8g2_DrawRBox(&canvasBuffer, (int16_t)std::round(_x), (int16_t)std::round(_y), (uint8_t)std::round(_w), (uint8_t)std::round(_h), (uint8_t)std::round(_r));
}

void MyHAL::_drawFrame(float _x, float _y, float _w, float _h)
{
    u8g2_DrawFrame(&canvasBuffer, (int16_t)std::round(_x), (int16_t)std::round(_y), (uint8_t)std::round(_w), (uint8_t)std::round(_h));
}

void MyHAL::_drawRFrame(float _x, float _y, float _w, float _h, float _r)
{
    u8g2_DrawRFrame(&canvasBuffer, (int16_t)std::round(_x), (int16_t)std::round(_y), (uint8_t)std::round(_w), (uint8_t)std::round(_h), (uint8_t)std::round(_r));
}

void MyHAL::_drawHLine(float _x, float _y, float _l)
{
    u8g2_DrawHLine(&canvasBuffer, (int16_t)std::round(_x), (int16_t)std::round(_y), (uint8_t)std::round(_l));
}

void MyHAL::_drawVLine(float _x, float _y, float _h)
{
    u8g2_DrawVLine(&canvasBuffer, (int16_t)std::round(_x), (int16_t)std::round(_y), (uint8_t)std::round(_h));
}

void MyHAL::_drawVDottedLine(float _x, float _y, float _h)
{
    for (unsigned char i = 0; i < (unsigned char)std::round(_h); i++)
    {
        if (i % 8 == 0 | (i - 1) % 8 == 0 | (i - 2) % 8 == 0)
            continue;
        u8g2_DrawPixel(&canvasBuffer, (int16_t)std::round(_x), (int16_t)std::round(_y) + i);
    }
}

void MyHAL::_drawHDottedLine(float _x, float _y, float _l)
{
    for (unsigned char i = 0; i < _l; i++)
    {
        if (i % 8 == 0 | (i - 1) % 8 == 0 | (i - 2) % 8 == 0)
            continue;
        u8g2_DrawPixel(&canvasBuffer, (int16_t)std::round(_x) + i, (int16_t)std::round(_y));
    }
}

unsigned long MyHAL::_getRandomSeed()
{
    return random(0, 100);
}