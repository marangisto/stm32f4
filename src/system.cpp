#include <stm32f4.h>

#if defined(STM32F411)
using namespace stm32f411;
#endif

namespace stm32f4
{

void sys_tick::delay_ms(uint32_t ms)
{
    uint32_t now = ms_counter, then = now + ms;

    while (ms_counter >= now && ms_counter < then)
        ;   // busy wait
}

void sys_tick::init(uint32_t n)
{
    using namespace stm32f4;
    typedef stk_t _;

    ms_counter = 0;                                     // start new epoq
    STK.CTRL = _::CTRL_RESET_VALUE;                     // reset controls
    STK.LOAD = n - 1;                                   // reload value
    STK.VAL = _::VAL_RESET_VALUE;                       // current counter value
    STK.CTRL |= BV(_::CTRL_CLKSOURCE);                  // systick clock source
    STK.CTRL |= BV(_::CTRL_ENABLE) | BV(_::CTRL_TICKINT);  // enable counter & interrupts
}

volatile uint32_t sys_tick::ms_counter = 0;

inline void sys_tick_init(uint32_t n) { sys_tick::init(n); }
inline void sys_tick_update() { ++sys_tick::ms_counter; } // N.B. wraps in 49 days!
}

extern "C" void SysTick_HDLR()
{
    stm32f4::sys_tick_update();
}

extern "C" void system_init(void)
{
    using namespace stm32f4;
    typedef rcc_t _;

    // reset clock control registers

    RCC.CR = _::CR_RESET_VALUE;
    RCC.CFGR = _::CFGR_RESET_VALUE;
    RCC.CIR = _::CIR_RESET_VALUE;

    // set system clock to HSI-PLL 100MHz

    constexpr uint8_t wait_states = 0x3;    // 3 wait-states for 100MHz at 2.7-3.3V

    FLASH.ACR = BV(flash_t::ACR_PRFTEN) | (wait_states << flash_t::ACR_LATENCY);
    while (((FLASH.ACR >> flash_t::ACR_LATENCY) & 0xf) != wait_states); // wait to take effect

    enum pllP_t { pllP_2 = 0x0, pllP_4 = 0x1, pllP_6 = 0x2, pllP_8 = 0x3 };

    // fVCO = hs[ei] * pllN / pllM                      // must be 100MHz - 400MHz
    // fSYS = fVCO / pllP                               // <= 100MHz
    // fUSB = fVCO / pllQ                               // <= 48MHz

    // pllN = 200, pllM = 8, pllP = 4, pllQ = 9, fSYS = 1.0e8, fUSB = 4.4445e7

    constexpr uint16_t pllN = 200;                      // 9 bits, valid range [50..432]
    constexpr uint8_t pllM = 8;                         // 6 bits, valid range [2..63]
    constexpr pllP_t pllP = pllP_4;                     // 2 bits, enum range [2, 4, 6, 8]
    constexpr uint8_t pllQ = 9;                         // 4 bits, valid range [2..15]

    uint32_t pllcfgr = (0x0 << _::PLLCFGR_PLLSRC)       // 0 = HSI, 1 = HSE
                     | (pllN << _::PLLCFGR_PLLN0)
                     | (pllM << _::PLLCFGR_PLLM0)
                     | (pllP << _::PLLCFGR_PLLP0)
                     | (pllQ << _::PLLCFGR_PLLQ0)
                     ;

    RCC.PLLCFGR = pllcfgr;
    RCC.CR |= BV(_::CR_PLLON);                          // enable PLL
    while (!(RCC.CR & _::CR_PLLRDY));                   // wait for PLL to be ready
    RCC.CFGR |= (0x2 << _::CFGR_SW0);                   // select PLL as system clock
    while (((RCC.CFGR >> _::CFGR_SWS0) & 0x3) != 0x2);  // wait for PLL as system clock

    // initialize sys-tick for milli-second counts

    stm32f4::sys_tick_init(60000);
}

