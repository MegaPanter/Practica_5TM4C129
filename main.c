#include "lib/include.h"
int x;
int i;
int main(void)

{
    volatile uint16_t freq;
     freq=1250;

    uint16_t Result[3];
    uint16_t duty[3];
    Configurar_PLL();  
    Configura_Reg_ADC0();
    Configurar_UART0();
    Configura_Reg_PWM1(50);


    while(1)
    {
         //llamada a la conversion por procesador
     
       
    ADC0_InSeq2(Result,duty);
        PWM0->_1_CMPA = duty[1];
        delayms(10);
        PWM0->_1_CMPB = duty[2];
        delayms(10);
        PWM0->_0_CMPA = duty[0];          
      
       
}

}