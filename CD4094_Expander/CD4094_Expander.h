#ifndef _CD4094_EXPANDER_H
#define _CD4094_EXPANDER_H

#include <Arduino.h>

class CD4094_Expander
{
public:
   enum SETBIT_ERROR
   {
      SET_BIT_ERROR = 0,
      SET_BIT_OK
   };
   enum SETBYTE_ERROR
   {
      SET_BYTE_ERROR = 0,
      SET_BYTE_OK
   };

   CD4094_Expander(byte Qtd, int STR, int D, int CLK, int OE);

   SETBIT_ERROR setBit(byte POS, byte value);
   SETBYTE_ERROR setByte(byte POS, byte value);
   void dataWrite();
   void enableOE();
   void disableOE();
   void PulseClock();

private:
   byte Dados[];
   byte Qtde;
   int pinOE = 255;
   int pinSTR = 255;
   int pinD = 255;
   int pinCLK = 255;
};

#endif