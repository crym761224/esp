// Zinguo.h
#ifdef USE_ZINGUO

#ifndef _ZINGUO_h
#define _ZINGUO_h

#include "arduino.h"
#include <ESP8266WebServer.h>
#include <Ticker.h>
#include "Module.h"
#include "ZinguoConfig.pb.h"

#define MODULE_CFG_VERSION 2001 //2001 - 2500

#define twi_sda 4                                //SDA引脚IO定义,for sc09a
#define twi_scl 5                                //SCL引脚IO定义,for sc09a
#define SDA_LOW() (GPES = (1 << twi_sda))        //SDA置LOW,for sc09a
#define SDA_HIGH() (GPEC = (1 << twi_sda))       //SDA置HIGH,for sc09a
#define SCL_LOW() (GPES = (1 << twi_scl))        //SCL置LOW,for sc09a
#define SCL_HIGH() (GPEC = (1 << twi_scl))       //SCL置HIGH,for sc09a
#define SDA_READ() ((GPI & (1 << twi_sda)) != 0) //SDA读内容,for sc09a
#define SCL_READ() ((GPI & (1 << twi_scl)) != 0) //SCL读内容,for sc09a
#define CON_ADDR 0x81                            //0x40(器件地址)+0x01(读取)=0x81,for sc09a

#define PIN_DATA 14  // 74HC595数据:旧GPIO13，新GPIO14
#define PIN_LOAD 12  // 74HC595锁存：旧GPIO14，新GPIO12
#define PIN_CLOCK 13 // 74HC595时钟：旧GPIO0，新GPIO13
#define PIN_BEEP 9   // 风铃器Beep

#define KEY_LIGHT 1       // 照明,Q
#define KEY_VENTILATION 2 // 换气,Q
#define KEY_CLOSE_ALL 3   // 全关
#define KEY_WARM_2 6      // 取暖2,R
#define KEY_BLOW 7        // 吹风,Q
#define KEY_WARM_1 8      // 取暖1,R

const char HASS_DISCOVER_ZINGUO[] PROGMEM =
    "{\"name\":\"%s_%s\","
    "\"cmd_t\":\"%s\","
    "\"stat_t\":\"%s\","
    "\"pl_off\":\"OFF\","
    "\"pl_on\":\"ON\","
    "\"avty_t\":\"%s\","
    "\"pl_avail\":\"online\","
    "\"pl_not_avail\":\"offline\"}";

class Zinguo : public Module
{
private:
    ZinguoConfigMessage config;
    //数码管0~9,Fix For New
    const unsigned char DigitNUM[10] = {0x81, 0x9F, 0xA2, 0x92, 0x9C, 0xD0, 0xC0, 0x9B, 0x80, 0x90};

    // 定义2个字节的Key缓存
    unsigned short touchKey = 0x0000;
    // 控制缓冲区 0温度
    float controlTemp = 0x00;
    // 控制缓冲区 2输出端子
    unsigned char controlPin = 0x1C;
    // 控制缓冲区 3LED缓冲
    unsigned char controlLED = 0x00;
    // 控制缓冲区 4输出缓冲
    unsigned char controlOut = 0x00;
    // 延时关闭吹风时间 127 不关闭
    int8_t closeBlowTime = 127;
    // 开启风暖的时间
    unsigned int warmTime = 0;
    // 开启换气的时间
    unsigned int ventilationTime = 0;
    // Mqtt传温度
    boolean mqttTemp = false;

    Ticker *schTicker;
    void beepBeep(char i);
    void convertTemp();
    void dispCtrl();
    unsigned short getKey();
    void analysisKey(unsigned short code);

    // 照明 Key1
    void switchLight(boolean isOn, bool isBeep = true);
    // 换气 Key2
    void switchVentilation(boolean isOn, bool isBeep = true);
    // 取暖1 Key8
    void switchWarm1(boolean isOn, bool isBeep = true);
    // 取暖2 Key6
    void switchWarm2(boolean isOn, bool isBeep = true);
    // 吹风 Key7
    void switchBlow(boolean isOn, bool isBeep = true);
    void switchBlowReal(boolean isOn, bool isBeep = true);
    // 全关 Key3
    void switchCloseAll(boolean isOn, bool isBeep = true);

    void httpDo(ESP8266WebServer *server);
    void httpSetting(ESP8266WebServer *server);

public:
    void init();
    String getModuleName();
    String getModuleCNName();
    bool moduleLed();

    void loop();
    void perSecondDo();

    void readConfig();
    void resetConfig();
    void saveConfig();

    void mqttCallback(String topicStr, String str);
    void mqttConnected();
    void mqttDiscovery(boolean isEnable = true);

    void httpAdd(ESP8266WebServer *server);
    void httpHtml(ESP8266WebServer *server);
    String httpGetStatus(ESP8266WebServer *server);
};
#endif

#endif