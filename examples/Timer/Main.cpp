#include <timer.h>
#include <gpio.h>

using namespace stm32f4;
using namespace timer;
using namespace gpio;

typedef timer_t<1> tim_a;
typedef timer_t<5> tim_b;

typedef output_t<PD13> led_a;
typedef output_t<PD12> led_b;

extern "C" void ISR_TIM1_UP_TIM10(void)
{
    tim_a::clear_uif();
    led_a::toggle();
}

extern "C" void ISR_TIM5(void)
{
    tim_b::clear_uif();
    led_b::toggle();
}

int main()
{
    tim_a::setup(100, 65535);
    tim_a::update_interrupt_enable();

    tim_b::setup(120, 65535);
    tim_b::update_interrupt_enable();

    led_a::setup();
    led_b::setup();

    cpsie();

    for (;;);
}

