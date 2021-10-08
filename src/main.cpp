#include <Arduino.h>
#include <SPI.h>
#include <ADS1299.h>

ADS1299 ads;

void setup()
{
  //SPI Initialitation
  SPI.begin();

  //ADS Initialitation
  ads.begin(); //Default ss pin
  // ads.begin(22); //Custom ss pin
  
  //Reset ADS
  ads.reset();

  //Serial Initialitation
  Serial.begin(115200);

  byte res;
  byte infoCommand;
  byte infoRegisterAddress;
  byte infoTotalRegister;
  byte resData[2];

  //Program mengambil data ID Alat
  Serial.println("\n\nProgram mengambil ID Alat");
  res = ads.getID();
  infoCommand = ads.infoCommand.command;
  infoRegisterAddress = ads.infoCommand.registerAddress;
  infoTotalRegister = ads.infoCommand.totalRegister;
  Serial.print("Device ID:\t\t");
  Serial.println(res);
  Serial.print("Command :\t\t");
  Serial.println(infoCommand, BIN);
  Serial.print("register address :\t");
  Serial.println(infoRegisterAddress, HEX);
  Serial.print("total register :\t");
  Serial.println(infoTotalRegister);
  Serial.println("\n");

  //Program mengambil 1 data register
  byte addressRegisterUji = 0x00;
  Serial.println("Program mengambil 1 data register");
  res = ads.readRegister(addressRegisterUji);
  infoCommand = ads.infoCommand.command;
  infoRegisterAddress = ads.infoCommand.registerAddress;
  infoTotalRegister = ads.infoCommand.totalRegister;
  Serial.print("Data Register:\t\t");
  Serial.println(res);
  Serial.print("Command :\t\t");
  Serial.println(infoCommand, BIN);
  Serial.print("register address :\t");
  Serial.println(infoRegisterAddress, HEX);
  Serial.print("total register :\t");
  Serial.println(infoTotalRegister);
  Serial.println("\n");

  //Program mengambil multiple data register
  addressRegisterUji = 0x00;
  Serial.println("Program mengambil multiple data register");
  ads.readRegister(addressRegisterUji, 2, resData);
  infoCommand = ads.infoCommand.command;
  infoRegisterAddress = ads.infoCommand.registerAddress;
  infoTotalRegister = ads.infoCommand.totalRegister;
  Serial.print("Data Register:\t\t");
  for (int iter = 0; iter < 2; iter++)
  {
    Serial.print(resData[iter]);
    Serial.print("\t");
  }
  Serial.print("\nCommand :\t\t");
  Serial.println(infoCommand, BIN);
  Serial.print("register address :\t");
  Serial.println(infoRegisterAddress, HEX);
  Serial.print("total register :\t");
  Serial.println(infoTotalRegister);
  Serial.println("\n");
}

void loop()
{
}