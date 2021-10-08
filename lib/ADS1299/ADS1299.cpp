#include "ADS1299.h"

byte ADS1299::readRegister(byte registerAddress)
{
    //SPI transaction
    SPI.beginTransaction(SPISettings(ADS1299_SPICLOCK, ADS1299_SPIBITORDER, ADS1299_SPIDATAMODE));
    digitalWrite(pin.SS, LOW);
    SPI.transfer(registerAddress | ADS1299_RREG);
    SPI.transfer(0x00);
    byte dat = SPI.transfer(0);
    digitalWrite(pin.SS, HIGH);
    SPI.endTransaction();

    //Get Info Command
    infoCommand.command = ADS1299_RREG;
    infoCommand.registerAddress = registerAddress;
    infoCommand.totalRegister = 1;
    return dat;
}

void ADS1299::readRegister(byte registerAddress, byte numberRegister, byte *data)
{
    //SPI transaction
    SPI.beginTransaction(SPISettings(ADS1299_SPICLOCK, ADS1299_SPIBITORDER, ADS1299_SPIDATAMODE));
    digitalWrite(pin.SS, LOW);
    SPI.transfer(registerAddress | ADS1299_RREG);
    SPI.transfer(numberRegister - 1);
    for (int iter = 0; iter < numberRegister; iter++)
    {
        data[iter] = SPI.transfer(0);
    }
    digitalWrite(pin.SS, HIGH);

    //Get Info Command
    infoCommand.command = ADS1299_RREG;
    infoCommand.registerAddress = registerAddress;
    infoCommand.totalRegister = numberRegister;
    SPI.endTransaction();
}

void ADS1299::begin()
{
    pinMode(pin.SS, OUTPUT);
}
void ADS1299::begin(byte pinSS)
{
    pin.SS = pinSS;
    pinMode(pin.SS, OUTPUT);
}

byte ADS1299::getID()
{
    return readRegister(IDREG);
}