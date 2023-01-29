
#include "lib/include.h"

extern void Configura_Reg_PWM1(volatile uint16_t freq)
{
     //habilitar el reloj del modulo del periferico 
    SYSCTL->RCGCPWM |= (1<<0 );
    //habilitar el reloj de los puertos 
    SYSCTL->RCGCGPIO |= (1<<5)|(1<<4); 
    //alternate function todo pin perteneciente a un periferico necesita activar su funcion alterna
    GPIOF_AHB->AFSEL |= (1<<3)|(1<<2)|(1<<1); 
    //mascara para asegurar que no haya nada dentro del registro
    GPIOF_AHB->PCTL |= (GPIOF_AHB->PCTL&0xFFFF000F) | 0x00006660; 
    //habilitar modo digital
    GPIOF_AHB->DEN |= (1<<3)|(1<<2)|(1<<1); 
    //habilitar el divisor del reloj 
    PWM0->CC = (1<<8)|(0x3<<0);
    //apagar el modulo generador 1
    PWM0->_1_CTL = (0<<0); 
    //CONFIG PWM0 GENERADOR 1A//////////////////////////////////////
    //configuracion pwm gen1A cuenta abajo 
    PWM0->_1_GENA |= (0X2<<2)|(0X3<<6)|(0x0<<0); 
    /*cuentas=fclk/fpwm  para 1khz cuentas = (16,000,000/1000)*/
    PWM0->_1_LOAD = 62500;
    PWM0->_1_CMPB = 2500;
    PWM0->_1_CMPA = 57813;
    //habiilitar el generador y el modo cuenta abajo
    PWM0->_1_CTL = (1<<0)|(0<<1);
    //////////////////////////////////////////////////////////////////
    
    //CONFIG PWM0 GENERADOR 1B//////////////////////////////////////
    PWM0->_1_GENB |= (0X2<<2)|(0X3<<10)|(0x0<<0);
    PWM0->_1_CTL = (1<<0)|(0<<1); 
   //CONFIG PWM0 GENERADOR 0B//////////////////////////////////////
    PWM0->_0_CTL = (0<<0);
    PWM0->_0_GENB |= (0X2<<2)|(0X3<<6)|(0x0<<0);
    PWM0->_0_LOAD = 62500;
    PWM0->_0_CMPB = 2500;
    PWM0->_0_CMPA = 57813;
    PWM0->_0_CTL = (1<<0)|(0<<1);
    
   //habilitar los generadores deseados
    PWM0->ENABLE =  (1<<2)|(1<<1)|(1<<3) ; 
}
 extern void delayms(int i)
{
    int a,b;
    for(a=0;a<i;a++)
    for(b=0;b<3180;b++)
    {}
    

}