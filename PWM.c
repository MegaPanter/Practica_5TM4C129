
#include "lib/include.h"

extern void Configura_Reg_PWM1(volatile uint16_t freq)
{
    SYSCTL->RCGCPWM |= (1<<0 ); /*Enable reloj de modulo PWM1 pag 354*/
    SYSCTL->RCGCGPIO |= (1<<5); /*Enable reloj de GPIO Puerto F pag 340 pin 5*/
   // GPIOF->AFSEL |= (1<<3)|(1<<2)|(1<<1); /*Control de registros ya sea por GPIO o Otros Pag 672*/
    GPIOF_AHB->AFSEL |= (1<<2);
    GPIOF_AHB->PCTL |= (GPIOF_AHB->PCTL&0xFFFFF0FF) | 0x00000600; /*Combinado con la tabla Pag 1351 y el registro PCTL le digo que es pwm Pag 689*/
    GPIOF_AHB->DEN |= (1<<2); /* para decirle si es digital o no Pag 682*/
    PWM0->CC = (1<<8)|(0x3<<0);  /*Enable o Disable Divisor  Pag 1747*/
    //PWM0->_0_CTL = (0<<0);
    PWM0->_1_CTL = (0<<0); /*Bloqueo y desbloqueo*/
    // PWM0->_1_GENB = 0x0000080C; /*Registro de las acciones del pwm Pag 1285*/
    PWM0->_1_GENA = (0X3<<2)|(0X2<<6)|(0x1<<0); /*Registro de las acciones del pwm Pag 1282*/
    // PWM0->_0_GENB = 0x0000008C;//PWM5
    PWM0->_1_LOAD = 62500;/*cuentas=fclk/fpwm  para 1khz cuentas = (16,000,000/1000)*/
    //PWM0->_0_LOAD = 16000;
    PWM0->_1_CMPB = 2500;
    PWM0->_1_CMPA = 57813;
   //PWM0->_0_CMPA = 4000;
    PWM0->_1_CTL = (1<<0)|(0<<1);// Se activa el generador 3
    //PWM0->_0_CTL = (1<<0);// Se activa el generador 2
    PWM0->ENABLE =  (1<<2) ; /*habilitar el bloque pa que pase Pag 1247*/
}
 extern void delayms(int i)
{
    int a,b;
    for(a=0;a<i;a++)
    for(b=0;b<3180;b++)
    {}
    

}