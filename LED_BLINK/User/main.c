#include "debug.h"

#define LED_PIN GPIO_Pin_6

void LED_init(void){
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);
    GPIO_InitTypeDef GPIO_InitStructure = {0};
    GPIO_InitStructure.GPIO_Pin = LED_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

    GPIO_Init(GPIOD, &GPIO_InitStructure);
}

int main(void)
{
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
    SystemCoreClockUpdate();
    Delay_Init();

    LED_init();

    while(1){
        GPIO_WriteBit(GPIOD, LED_PIN, Bit_SET);
        Delay_Ms(500);
        GPIO_WriteBit(GPIOD, LED_PIN, Bit_RESET);
        Delay_Ms(500);
    }
}
