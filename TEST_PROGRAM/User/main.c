#include "debug.h"

#define LED1 GPIO_Pin_0
#define LED2 GPIO_Pin_1
#define LED3 GPIO_Pin_2
#define LED4 GPIO_Pin_3
#define LED5 GPIO_Pin_4

uint16_t leds[5] = {LED1, LED2, LED3, LED4, LED5};

void LED_init(void){
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE);
    GPIO_InitTypeDef GPIO_InitStructure = {0};
    GPIO_InitStructure.GPIO_Pin = 0;

    for(int i = 0; i < 5; i++){
        GPIO_InitStructure.GPIO_Pin |= leds[i];
    }

    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;

    GPIO_Init(GPIOC, &GPIO_InitStructure);
}

int main(void)
{
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);
    SystemCoreClockUpdate();
    Delay_Init();

    LED_init();

    uint8_t count = 0;


    while(1)
    {
        int n = count;
        int i = 4;
        int temp = 0;
        while (n > 0 && i >= 0) {
            // Storing remainder when n is divided by 2
            // binaryNum[i] = n % 2;
            temp = n % 2;
            GPIO_WriteBit(GPIOC, leds[i], temp);
            n = n / 2;
            i--;
        }
        count++;
        Delay_Ms(1000);
    }
}
