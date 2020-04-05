#include "CD4094_Expander.h"
byte Dados[10];

CD4094_Expander::CD4094_Expander(byte Qtd, int STR, int D, int CLK, int OE)
{

   Qtde = ((Qtd < 1) ? 1 : ((Qtd > 10) ? 10 : Qtd));

   pinMode(STR, OUTPUT);
   pinMode(D, OUTPUT);
   pinMode(CLK, OUTPUT);
   pinMode(OE, OUTPUT);
   pinSTR = STR;
   pinD = D;
   pinCLK = CLK;
   pinOE = OE;
}

CD4094_Expander::SETBIT_ERROR CD4094_Expander::setBit(byte POS, byte value)
{
   if (POS <= Qtde * 8)
   {
      int loc = POS / 8;
      int posi = POS % 8;
      if (value)
      {
         Dados[loc] |= 1 << posi;
      }
      else
      {
         Dados[loc] &= ~(1 << posi);
      }
      return CD4094_Expander::SET_BIT_OK;
   }
   return CD4094_Expander::SET_BIT_ERROR;
}

CD4094_Expander::SETBYTE_ERROR CD4094_Expander::setByte(byte POS, byte value)
{
   if (POS <= Qtde)
   {
      Dados[POS] = value;
      return CD4094_Expander::SET_BYTE_OK;
   }
   return CD4094_Expander::SET_BYTE_ERROR;
}
void CD4094_Expander::PulseClock(void)
{
   digitalWrite(pinCLK, LOW);
   delayMicroseconds(20);
   digitalWrite(pinCLK, HIGH);
   delayMicroseconds(50);
   digitalWrite(pinCLK, LOW);
}

void CD4094_Expander::dataWrite()
{
   digitalWrite(pinSTR, 1);
   for (int a = 0; a < Qtde; a++)
   {
      for (int b = 0; b < 8; b++)
      {
         digitalWrite(pinD, ((Dados[a] & (1 << b)) == (1 << b)));
         PulseClock();
      }
   }
   digitalWrite(pinSTR, 0);
}

void CD4094_Expander::enableOE()
{
   digitalWrite(pinOE, 1);
}

void CD4094_Expander::disableOE()
{
   digitalWrite(pinOE, 0);
}
