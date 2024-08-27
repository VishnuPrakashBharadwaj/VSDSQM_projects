#include "debug.h"

#define R_PIN GPIO_Pin_3
#define G_PIN GPIO_Pin_4
#define B_PIN GPIO_Pin_5


void LEDS_init(void){
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);
    GPIO_InitTypeDef GPIO_InitStructure = {0};
    GPIO_InitStructure.GPIO_Pin = R_PIN | G_PIN | B_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

    GPIO_Init(GPIOD, &GPIO_InitStructure);
}

int main(void)
{
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
    SystemCoreClockUpdate();
    Delay_Init();
    LEDS_init();

    // loop
    while(1){
        GPIO_WriteBit(GPIOD, R_PIN, Bit_SET);
        GPIO_WriteBit(GPIOD, G_PIN | B_PIN, Bit_RESET);
        Delay_Ms(500);
        GPIO_WriteBit(GPIOD, G_PIN, Bit_SET);
        GPIO_WriteBit(GPIOD, R_PIN | B_PIN, Bit_RESET);
        Delay_Ms(500);
        GPIO_WriteBit(GPIOD, B_PIN, Bit_SET);
        GPIO_WriteBit(GPIOD, R_PIN | G_PIN, Bit_RESET);
        Delay_Ms(500);

        GPIO_WriteBit(GPIOD, R_PIN, Bit_RESET);
        GPIO_WriteBit(GPIOD, G_PIN | B_PIN, Bit_SET);
        Delay_Ms(500);
        GPIO_WriteBit(GPIOD, G_PIN, Bit_RESET);
        GPIO_WriteBit(GPIOD, R_PIN | B_PIN, Bit_SET);
        Delay_Ms(500);
        GPIO_WriteBit(GPIOD, B_PIN, Bit_RESET);
        GPIO_WriteBit(GPIOD, R_PIN | G_PIN, Bit_SET);
        Delay_Ms(500);
    }
}
