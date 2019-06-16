#pragma once

#include <stm32f4.h>

namespace stm32f4
{

namespace timer
{

using namespace device;

template<int TN> struct timer_traits {};

template<> struct timer_traits<1>
{
    typedef tim1_t T;
    static inline T& TIM() { return TIM1; }
    static inline void rcc_enable() { RCC.APB2ENR |= BV(rcc_t::APB2ENR_TIM1EN); }
    static inline void nvic_enable() { NVIC.ISER0 |= BV(ISR::TIM1_UP_TIM10); }
};

template<> struct timer_traits<2>
{
    typedef tim2_t T;
    static inline T& TIM() { return TIM2; }
    static inline void rcc_enable() { RCC.APB1ENR |= BV(rcc_t::APB1ENR_TIM2EN); }
    static inline void nvic_enable() { NVIC.ISER0 |= BV(ISR::TIM2); }
};

template<> struct timer_traits<3>
{
    typedef tim3_t T;
    static inline T& TIM() { return TIM3; }
    static inline void rcc_enable() { RCC.APB1ENR |= BV(rcc_t::APB1ENR_TIM3EN); }
    static inline void nvic_enable() { NVIC.ISER0 |= BV(ISR::TIM3); }
};

template<> struct timer_traits<4>
{
    typedef tim4_t T;
    static inline T& TIM() { return TIM4; }
    static inline void rcc_enable() { RCC.APB1ENR |= BV(rcc_t::APB1ENR_TIM4EN); }
    static inline void nvic_enable() { NVIC.ISER0 |= BV(ISR::TIM4); }
};

template<> struct timer_traits<5>
{
    typedef tim5_t T;
    static inline T& TIM() { return TIM5; }
    static inline void rcc_enable() { RCC.APB1ENR |= BV(rcc_t::APB1ENR_TIM5EN); }
    static inline void nvic_enable() { NVIC.ISER1 |= BV(ISR::TIM5 - 32); } // N.B. offset!
};

template<> struct timer_traits<9>
{
    typedef tim9_t T;
    static inline T& TIM() { return TIM9; }
    static inline void rcc_enable() { RCC.APB2ENR |= BV(rcc_t::APB2ENR_TIM9EN); }
    static inline void nvic_enable() { NVIC.ISER0 |= BV(ISR::TIM1_BRK_TIM9); }
};

template<> struct timer_traits<10>
{
    typedef tim10_t T;
    static inline T& TIM() { return TIM10; }
    static inline void rcc_enable() { RCC.APB2ENR |= BV(rcc_t::APB2ENR_TIM10EN); }
    static inline void nvic_enable() { NVIC.ISER0 |= BV(ISR::TIM1_UP_TIM10); }
};

template<> struct timer_traits<11>
{
    typedef tim11_t T;
    static inline T& TIM() { return TIM11; }
    static inline void rcc_enable() { RCC.APB2ENR |= BV(rcc_t::APB2ENR_TIM11EN); }
    static inline void nvic_enable() { NVIC.ISER0 |= BV(ISR::TIM1_TRG_COM_TIM11); }
};

template<int TN>
class timer_t
{
public:
    static inline void setup(uint16_t psc, uint16_t arr)
    {
        timer_traits<TN>::rcc_enable();
        TIM().CR1 = _::CR1_RESET_VALUE;
        TIM().PSC = psc;
        TIM().ARR = arr;
        TIM().CR1 |= BV(_::CR1_ARPE);
        TIM().CR1 |= BV(_::CR1_CEN);
    }

    static inline void update_interrupt_enable()
    {
        TIM().DIER |= BV(_::DIER_UIE);
        timer_traits<TN>::nvic_enable();
    }

    static inline volatile bool uif()
    {
        return (TIM().SR & BV(_::SR_UIF)) != 0;
    }

    static inline volatile void clear_uif()
    {
        TIM().SR &= ~BV(_::SR_UIF);
    }

    static inline volatile uint32_t cnt()
    {
        return TIM().CNT;
    }

private:
    static inline typename timer_traits<TN>::T& TIM() { return timer_traits<TN>::TIM(); }
    typedef typename timer_traits<TN>::T _;
};

}

}

