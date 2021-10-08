#ifndef ADS1299_h
#define ADS1299_h
#include <Arduino.h>
#include <SPI.h>

//SPI Configuration
#define ADS1299_SPICLOCK (1000000u)
#define ADS1299_SPIBITORDER MSBFIRST
#define ADS1299_SPIDATAMODE SPI_MODE0

//Command mode ADS1299
#define ADS1299_RREG 0x20

class ADS1299
{
private:
    //Pin ESP32 for ADS1299
    struct
    {
        byte SS = 22;
    } pin;

    //Register Address ADS1299
    enum Register_Address : byte
    {
        IDREG = 0x00
    };

public:
    //Command Information ADS1299
    struct
    {
        byte totalRegister = 0;
        byte command = 0;
        byte registerAddress = 0;
    } infoCommand;
    
    //Inisialisasi ADS1299
    void begin(); //Using default Pin ss
    void begin(byte pinSS); //Using Custom Pin ss
    
    //Get ID ADS1299
    byte getID();
    
    //Read Single Register ADS1299
    byte readRegister(byte registerAddress);
    
    //Read Numbers of Register ADS1299
    void readRegister(byte registerAddress, byte numberRegister, byte *Data);
};
#endif