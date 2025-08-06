#include "tools.h"


bool Timer(uint32_t interval)
{
    static uint32_t lastTime = 0;
    if (millis() - lastTime >= interval) {
        lastTime = millis();
        return true;
    }
    return false;
}

// 寻找I2C设备
// 该函数扫描I2C总线上的设备地址，并打印出找到的设备
// 如果没有找到设备，则打印"No I2C devices found"
// 如果找到设备，则打印每个设备的地址
//需要Serial.begin();与 Wire.begin(); 在setup()中调用
void FoundWire(){
    byte error, address;
    int nDevices;
    Serial.println("Scanning...");
    nDevices = 0;
    for(address = 1; address < 127; address++ ) {
        Wire.beginTransmission(address);
        error = Wire.endTransmission();
        if (error == 0) {
        Serial.print("I2C device found at address 0x");
        if (address<16) {
            Serial.print("0");
        }
        Serial.println(address,HEX);
        nDevices++;
        }
        else if (error==4) {
        Serial.print("Unknow error at address 0x");
        if (address<16) {
            Serial.print("0");
        }
        Serial.println(address,HEX);
        }    
    }
    if (nDevices == 0) {
        Serial.println("No I2C devices found\n");
    }
    else {
        Serial.println("done\n");
    }
    delay(5000);  
}
