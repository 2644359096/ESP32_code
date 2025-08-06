#ifndef __TOOLS_H__
#define __TOOLS_H__ 
#include <Arduino.h>
#include <Wire.h>
template <typename list_t, size_t N>
uint8_t get_list_length(list_t (&list)[N]) {
    return N;
}
bool Timer(uint32_t interval);
void FoundWire();

typedef void (*func_t)();
struct void_func_t
{
    func_t func;
    uint8_t len;
    uint8_t args[];
};
#endif