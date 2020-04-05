#ifndef _CD4051_EXPANDER_H
#define _CD4051_EXPANDER_H

#include <Arduino.h> 
 
class CD4051_Expander
{
   public:    
      CD4051_Expander(int SEL_A,int SEL_B, int SEL_C, int INH);
      void selectInput(byte Pos); 
      void enableINH();
      void disableINH();
   private:
      int pinSEL_A = 255;
      int pinSEL_B = 255;
      int pinSEL_C = 255;
      int pinINH = 255;
}; 
 
#endif