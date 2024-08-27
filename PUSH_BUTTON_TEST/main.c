#include "debug.h"

#define PUSH_BUTTON_PIN GPIO_Pin_3
#define LED_PIN         GPIO_Pin_6

void gpios_init(){
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);

    GPIO_InitTypeDef GPIO_InitStructure = {0};
    //Configuration for GPIO Input on PD3
    GPIO_InitStructure.GPIO_Pin = PUSH_BUTTON_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOD, &GPIO_InitStructure);

    //Configuration for GPIO Input on PD6
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

    gpios_init();

    uint8_t button_state = 0;

    while(1)
    {
        button_state = GPIO_ReadInputDataBit(GPIOD, PUSH_BUTTON_PIN);

        GPIO_WriteBit(GPIOD, LED_PIN, !button_state);
        Delay_Ms(10);
    }
}
