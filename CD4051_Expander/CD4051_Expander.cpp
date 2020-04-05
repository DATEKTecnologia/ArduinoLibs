#include "CD4051_Expander.h"

CD4051_Expander::CD4051_Expander(int SEL_A,int SEL_B, int SEL_C, int INH){
   pinMode(SEL_A, OUTPUT);
   pinMode(SEL_B, OUTPUT);
   pinMode(SEL_C, OUTPUT);
   pinMode(INH, OUTPUT);
   pinSEL_A = SEL_A;
   pinSEL_B = SEL_B;
   pinSEL_C = SEL_C;
   pinINH = INH;
}

void CD4051_Expander::selectInput(int Pos){
   digitalWrite(pinSEL_A,((Pos&0X01)==0X01));
   digitalWrite(pinSEL_B,((Pos&0X02)==0X02));
   digitalWrite(pinSEL_C,((Pos&0X04)==0X04));
}

void CD4051_Expander::enableINH(){
  digitalWrite(pinINH,1); 
}
   
void CD4051_Expander::disableINH(){
   digitalWrite(pinINH,0); 
}
