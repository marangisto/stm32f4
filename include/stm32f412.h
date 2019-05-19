#pragma once

#include <stdint.h>

////
//
//    STM32F412
//
//       schema-version : 1.1
//       vendor         : 
//       series         : 
//       device-version : 1.1
//       address-unit   : 8 bits
//       device-width   : 32
//       device-size    : 32
//
////

namespace stm32f412
{

template<int N> class reserved_t { private: uint32_t m_pad[N]; };

////
//
//    ADC common registers
//
////

struct adc_common_t
{
    volatile uint32_t    CSR;                  // [Read-only] ADC Common status register
    volatile uint32_t    CCR;                  // [Read-write] ADC common control register

    static const uint8_t CSR_OVR3 = 21;            // Overrun flag of ADC3
    static const uint8_t CSR_STRT3 = 20;           // Regular channel Start flag of ADC 3
    static const uint8_t CSR_JSTRT3 = 19;          // Injected channel Start flag of ADC 3
    static const uint8_t CSR_JEOC3 = 18;           // Injected channel end of conversion of ADC 3
    static const uint8_t CSR_EOC3 = 17;            // End of conversion of ADC 3
    static const uint8_t CSR_AWD3 = 16;            // Analog watchdog flag of ADC 3
    static const uint8_t CSR_OVR2 = 13;            // Overrun flag of ADC 2
    static const uint8_t CSR_STRT2 = 12;           // Regular channel Start flag of ADC 2
    static const uint8_t CSR_JSTRT2 = 11;          // Injected channel Start flag of ADC 2
    static const uint8_t CSR_JEOC2 = 10;           // Injected channel end of conversion of ADC 2
    static const uint8_t CSR_EOC2 = 9;             // End of conversion of ADC 2
    static const uint8_t CSR_AWD2 = 8;             // Analog watchdog flag of ADC 2
    static const uint8_t CSR_OVR1 = 5;             // Overrun flag of ADC 1
    static const uint8_t CSR_STRT1 = 4;            // Regular channel Start flag of ADC 1
    static const uint8_t CSR_JSTRT1 = 3;           // Injected channel Start flag of ADC 1
    static const uint8_t CSR_JEOC1 = 2;            // Injected channel end of conversion of ADC 1
    static const uint8_t CSR_EOC1 = 1;             // End of conversion of ADC 1
    static const uint8_t CSR_AWD1 = 0;             // Analog watchdog flag of ADC 1
    static const uint32_t CSR_RESET_VALUE = 0x0;

    static const uint8_t CCR_TSVREFE = 23;         // Temperature sensor and VREFINT enable
    static const uint8_t CCR_VBATE = 22;           // VBAT enable
    static const uint8_t CCR_ADCPRE = 16;          // ADC prescaler (2 bits)
    static const uint8_t CCR_DMA = 14;             // Direct memory access mode for multi ADC mode (2 bits)
    static const uint8_t CCR_DDS = 13;             // DMA disable selection for multi-ADC mode
    static const uint8_t CCR_DELAY = 8;            // Delay between 2 sampling phases (4 bits)
    static const uint32_t CCR_RESET_VALUE = 0x0;
};

static adc_common_t& ADC_Common = *reinterpret_cast<adc_common_t*>(0x40012300);


////
//
//    Analog-to-digital converter
//
////

struct adc1_t
{
    volatile uint32_t    SR;                   // [Read-write] status register
    volatile uint32_t    CR1;                  // [Read-write] control register 1
    volatile uint32_t    CR2;                  // [Read-write] control register 2
    volatile uint32_t    SMPR1;                // [Read-write] sample time register 1
    volatile uint32_t    SMPR2;                // [Read-write] sample time register 2
    volatile uint32_t    JOFR1;                // [Read-write] injected channel data offset register x
    volatile uint32_t    JOFR2;                // [Read-write] injected channel data offset register x
    volatile uint32_t    JOFR3;                // [Read-write] injected channel data offset register x
    volatile uint32_t    JOFR4;                // [Read-write] injected channel data offset register x
    volatile uint32_t    HTR;                  // [Read-write] watchdog higher threshold register
    volatile uint32_t    LTR;                  // [Read-write] watchdog lower threshold register
    volatile uint32_t    SQR1;                 // [Read-write] regular sequence register 1
    volatile uint32_t    SQR2;                 // [Read-write] regular sequence register 2
    volatile uint32_t    SQR3;                 // [Read-write] regular sequence register 3
    volatile uint32_t    JSQR;                 // [Read-write] injected sequence register
    volatile uint32_t    JDR1;                 // [Read-only] injected data register x
    volatile uint32_t    JDR2;                 // [Read-only] injected data register x
    volatile uint32_t    JDR3;                 // [Read-only] injected data register x
    volatile uint32_t    JDR4;                 // [Read-only] injected data register x
    volatile uint32_t    DR;                   // [Read-only] regular data register

    static const uint8_t SR_OVR = 5;              // Overrun
    static const uint8_t SR_STRT = 4;             // Regular channel start flag
    static const uint8_t SR_JSTRT = 3;            // Injected channel start flag
    static const uint8_t SR_JEOC = 2;             // Injected channel end of conversion
    static const uint8_t SR_EOC = 1;              // Regular channel end of conversion
    static const uint8_t SR_AWD = 0;              // Analog watchdog flag
    static const uint32_t SR_RESET_VALUE = 0x0;

    static const uint8_t CR1_OVRIE = 26;           // Overrun interrupt enable
    static const uint8_t CR1_RES = 24;             // Resolution (2 bits)
    static const uint8_t CR1_AWDEN = 23;           // Analog watchdog enable on regular channels
    static const uint8_t CR1_JAWDEN = 22;          // Analog watchdog enable on injected channels
    static const uint8_t CR1_DISCNUM = 13;         // Discontinuous mode channel count (3 bits)
    static const uint8_t CR1_JDISCEN = 12;         // Discontinuous mode on injected channels
    static const uint8_t CR1_DISCEN = 11;          // Discontinuous mode on regular channels
    static const uint8_t CR1_JAUTO = 10;           // Automatic injected group conversion
    static const uint8_t CR1_AWDSGL = 9;           // Enable the watchdog on a single channel in scan mode
    static const uint8_t CR1_SCAN = 8;             // Scan mode
    static const uint8_t CR1_JEOCIE = 7;           // Interrupt enable for injected channels
    static const uint8_t CR1_AWDIE = 6;            // Analog watchdog interrupt enable
    static const uint8_t CR1_EOCIE = 5;            // Interrupt enable for EOC
    static const uint8_t CR1_AWDCH = 0;            // Analog watchdog channel select bits (5 bits)
    static const uint32_t CR1_RESET_VALUE = 0x0;

    static const uint8_t CR2_SWSTART = 30;         // Start conversion of regular channels
    static const uint8_t CR2_EXTEN = 28;           // External trigger enable for regular channels (2 bits)
    static const uint8_t CR2_EXTSEL = 24;          // External event select for regular group (4 bits)
    static const uint8_t CR2_JSWSTART = 22;        // Start conversion of injected channels
    static const uint8_t CR2_JEXTEN = 20;          // External trigger enable for injected channels (2 bits)
    static const uint8_t CR2_JEXTSEL = 16;         // External event select for injected group (4 bits)
    static const uint8_t CR2_ALIGN = 11;           // Data alignment
    static const uint8_t CR2_EOCS = 10;            // End of conversion selection
    static const uint8_t CR2_DDS = 9;              // DMA disable selection (for single ADC mode)
    static const uint8_t CR2_DMA = 8;              // Direct memory access mode (for single ADC mode)
    static const uint8_t CR2_CONT = 1;             // Continuous conversion
    static const uint8_t CR2_ADON = 0;             // A/D Converter ON / OFF
    static const uint32_t CR2_RESET_VALUE = 0x0;

    static const uint8_t SMPR1_SMPx_x = 0;           // Sample time bits (32 bits)
    static const uint32_t SMPR1_RESET_VALUE = 0x0;

    static const uint8_t SMPR2_SMPx_x = 0;           // Sample time bits (32 bits)
    static const uint32_t SMPR2_RESET_VALUE = 0x0;

    static const uint8_t JOFR1_JOFFSET1 = 0;         // Data offset for injected channel x (12 bits)
    static const uint32_t JOFR1_RESET_VALUE = 0x0;

    static const uint8_t JOFR2_JOFFSET2 = 0;         // Data offset for injected channel x (12 bits)
    static const uint32_t JOFR2_RESET_VALUE = 0x0;

    static const uint8_t JOFR3_JOFFSET3 = 0;         // Data offset for injected channel x (12 bits)
    static const uint32_t JOFR3_RESET_VALUE = 0x0;

    static const uint8_t JOFR4_JOFFSET4 = 0;         // Data offset for injected channel x (12 bits)
    static const uint32_t JOFR4_RESET_VALUE = 0x0;

    static const uint8_t HTR_HT = 0;               // Analog watchdog higher threshold (12 bits)
    static const uint32_t HTR_RESET_VALUE = 0xfff;

    static const uint8_t LTR_LT = 0;               // Analog watchdog lower threshold (12 bits)
    static const uint32_t LTR_RESET_VALUE = 0x0;

    static const uint8_t SQR1_L = 20;               // Regular channel sequence length (4 bits)
    static const uint8_t SQR1_SQ16 = 15;            // 16th conversion in regular sequence (5 bits)
    static const uint8_t SQR1_SQ15 = 10;            // 15th conversion in regular sequence (5 bits)
    static const uint8_t SQR1_SQ14 = 5;             // 14th conversion in regular sequence (5 bits)
    static const uint8_t SQR1_SQ13 = 0;             // 13th conversion in regular sequence (5 bits)
    static const uint32_t SQR1_RESET_VALUE = 0x0;

    static const uint8_t SQR2_SQ12 = 25;            // 12th conversion in regular sequence (5 bits)
    static const uint8_t SQR2_SQ11 = 20;            // 11th conversion in regular sequence (5 bits)
    static const uint8_t SQR2_SQ10 = 15;            // 10th conversion in regular sequence (5 bits)
    static const uint8_t SQR2_SQ9 = 10;             // 9th conversion in regular sequence (5 bits)
    static const uint8_t SQR2_SQ8 = 5;              // 8th conversion in regular sequence (5 bits)
    static const uint8_t SQR2_SQ7 = 0;              // 7th conversion in regular sequence (5 bits)
    static const uint32_t SQR2_RESET_VALUE = 0x0;

    static const uint8_t SQR3_SQ6 = 25;             // 6th conversion in regular sequence (5 bits)
    static const uint8_t SQR3_SQ5 = 20;             // 5th conversion in regular sequence (5 bits)
    static const uint8_t SQR3_SQ4 = 15;             // 4th conversion in regular sequence (5 bits)
    static const uint8_t SQR3_SQ3 = 10;             // 3rd conversion in regular sequence (5 bits)
    static const uint8_t SQR3_SQ2 = 5;              // 2nd conversion in regular sequence (5 bits)
    static const uint8_t SQR3_SQ1 = 0;              // 1st conversion in regular sequence (5 bits)
    static const uint32_t SQR3_RESET_VALUE = 0x0;

    static const uint8_t JSQR_JL = 20;              // Injected sequence length (2 bits)
    static const uint8_t JSQR_JSQ4 = 15;            // 4th conversion in injected sequence (5 bits)
    static const uint8_t JSQR_JSQ3 = 10;            // 3rd conversion in injected sequence (5 bits)
    static const uint8_t JSQR_JSQ2 = 5;             // 2nd conversion in injected sequence (5 bits)
    static const uint8_t JSQR_JSQ1 = 0;             // 1st conversion in injected sequence (5 bits)
    static const uint32_t JSQR_RESET_VALUE = 0x0;

    static const uint8_t JDR1_JDATA = 0;            // Injected data (16 bits)
    static const uint32_t JDR1_RESET_VALUE = 0x0;

    static const uint8_t JDR2_JDATA = 0;            // Injected data (16 bits)
    static const uint32_t JDR2_RESET_VALUE = 0x0;

    static const uint8_t JDR3_JDATA = 0;            // Injected data (16 bits)
    static const uint32_t JDR3_RESET_VALUE = 0x0;

    static const uint8_t JDR4_JDATA = 0;            // Injected data (16 bits)
    static const uint32_t JDR4_RESET_VALUE = 0x0;

    static const uint8_t DR_DATA = 0;             // Regular data (16 bits)
    static const uint32_t DR_RESET_VALUE = 0x0;
};

static adc1_t& ADC1 = *reinterpret_cast<adc1_t*>(0x40012000);


////
//
//    Cryptographic processor
//
////

struct crc_t
{
    volatile uint32_t    DR;                   // [Read-write] Data register
    volatile uint32_t    IDR;                  // [Read-write] Independent Data register
    volatile uint32_t    CR;                   // [Write-only] Control register

    static const uint8_t DR_DR = 0;               // Data Register (32 bits)
    static const uint32_t DR_RESET_VALUE = 0xffffffff;

    static const uint8_t IDR_IDR = 0;              // Independent Data register (8 bits)
    static const uint32_t IDR_RESET_VALUE = 0x0;

    static const uint8_t CR_CR = 0;               // Control regidter
    static const uint32_t CR_RESET_VALUE = 0x0;
};

static crc_t& CRC = *reinterpret_cast<crc_t*>(0x40023000);


////
//
//    Debug support
//
////

struct dbg_t
{
    volatile uint32_t    DBGMCU_IDCODE;        // [Read-only] IDCODE
    volatile uint32_t    DBGMCU_CR;            // [Read-write] Control Register
    volatile uint32_t    DBGMCU_APB1_FZ;       // [Read-write] Debug MCU APB1 Freeze registe
    volatile uint32_t    DBGMCU_APB2_FZ;       // [Read-write] Debug MCU APB2 Freeze registe

    static const uint8_t DBGMCU_IDCODE_DEV_ID = 0;           // DEV_ID (12 bits)
    static const uint8_t DBGMCU_IDCODE_REV_ID = 16;          // REV_ID (16 bits)
    static const uint32_t DBGMCU_IDCODE_RESET_VALUE = 0x10006411;

    static const uint8_t DBGMCU_CR_DBG_SLEEP = 0;        // DBG_SLEEP
    static const uint8_t DBGMCU_CR_DBG_STOP = 1;         // DBG_STOP
    static const uint8_t DBGMCU_CR_DBG_STANDBY = 2;      // DBG_STANDBY
    static const uint8_t DBGMCU_CR_TRACE_IOEN = 5;       // TRACE_IOEN
    static const uint8_t DBGMCU_CR_TRACE_MODE = 6;       // TRACE_MODE (2 bits)
    static const uint32_t DBGMCU_CR_RESET_VALUE = 0x0;

    static const uint8_t DBGMCU_APB1_FZ_DBG_TIM2_STOP = 0;    // DBG_TIM2_STOP
    static const uint8_t DBGMCU_APB1_FZ_DBG_TIM3_STOP = 1;    // DBG_TIM3 _STOP
    static const uint8_t DBGMCU_APB1_FZ_DBG_TIM4_STOP = 2;    // DBG_TIM4_STOP
    static const uint8_t DBGMCU_APB1_FZ_DBG_TIM5_STOP = 3;    // DBG_TIM5_STOP
    static const uint8_t DBGMCU_APB1_FZ_DBG_RTC_Stop = 10;    // RTC stopped when Core is halted
    static const uint8_t DBGMCU_APB1_FZ_DBG_WWDG_STOP = 11;   // DBG_WWDG_STOP
    static const uint8_t DBGMCU_APB1_FZ_DBG_IWDEG_STOP = 12;  // DBG_IWDEG_STOP
    static const uint8_t DBGMCU_APB1_FZ_DBG_I2C1_SMBUS_TIMEOUT = 21;// DBG_J2C1_SMBUS_TIMEOUT
    static const uint8_t DBGMCU_APB1_FZ_DBG_I2C2_SMBUS_TIMEOUT = 22;// DBG_J2C2_SMBUS_TIMEOUT
    static const uint8_t DBGMCU_APB1_FZ_DBG_I2C3SMBUS_TIMEOUT = 23;// DBG_J2C3SMBUS_TIMEOUT
    static const uint32_t DBGMCU_APB1_FZ_RESET_VALUE = 0x0;

    static const uint8_t DBGMCU_APB2_FZ_DBG_TIM1_STOP = 0;    // TIM1 counter stopped when core is halted
    static const uint8_t DBGMCU_APB2_FZ_DBG_TIM9_STOP = 16;   // TIM9 counter stopped when core is halted
    static const uint8_t DBGMCU_APB2_FZ_DBG_TIM10_STOP = 17;  // TIM10 counter stopped when core is halted
    static const uint8_t DBGMCU_APB2_FZ_DBG_TIM11_STOP = 18;  // TIM11 counter stopped when core is halted
    static const uint32_t DBGMCU_APB2_FZ_RESET_VALUE = 0x0;
};

static dbg_t& DBG = *reinterpret_cast<dbg_t*>(0xe0042000);


////
//
//    External interrupt/event controller
//
////

struct exti_t
{
    volatile uint32_t    IMR;                  // [Read-write] Interrupt mask register (EXTI_IMR)
    volatile uint32_t    EMR;                  // [Read-write] Event mask register (EXTI_EMR)
    volatile uint32_t    RTSR;                 // [Read-write] Rising Trigger selection register (EXTI_RTSR)
    volatile uint32_t    FTSR;                 // [Read-write] Falling Trigger selection register (EXTI_FTSR)
    volatile uint32_t    SWIER;                // [Read-write] Software interrupt event register (EXTI_SWIER)
    volatile uint32_t    PR;                   // [Read-write] Pending register (EXTI_PR)

    static const uint8_t IMR_MR0 = 0;              // Interrupt Mask on line 0
    static const uint8_t IMR_MR1 = 1;              // Interrupt Mask on line 1
    static const uint8_t IMR_MR2 = 2;              // Interrupt Mask on line 2
    static const uint8_t IMR_MR3 = 3;              // Interrupt Mask on line 3
    static const uint8_t IMR_MR4 = 4;              // Interrupt Mask on line 4
    static const uint8_t IMR_MR5 = 5;              // Interrupt Mask on line 5
    static const uint8_t IMR_MR6 = 6;              // Interrupt Mask on line 6
    static const uint8_t IMR_MR7 = 7;              // Interrupt Mask on line 7
    static const uint8_t IMR_MR8 = 8;              // Interrupt Mask on line 8
    static const uint8_t IMR_MR9 = 9;              // Interrupt Mask on line 9
    static const uint8_t IMR_MR10 = 10;            // Interrupt Mask on line 10
    static const uint8_t IMR_MR11 = 11;            // Interrupt Mask on line 11
    static const uint8_t IMR_MR12 = 12;            // Interrupt Mask on line 12
    static const uint8_t IMR_MR13 = 13;            // Interrupt Mask on line 13
    static const uint8_t IMR_MR14 = 14;            // Interrupt Mask on line 14
    static const uint8_t IMR_MR15 = 15;            // Interrupt Mask on line 15
    static const uint8_t IMR_MR16 = 16;            // Interrupt Mask on line 16
    static const uint8_t IMR_MR17 = 17;            // Interrupt Mask on line 17
    static const uint8_t IMR_MR18 = 18;            // Interrupt Mask on line 18
    static const uint8_t IMR_MR19 = 19;            // Interrupt Mask on line 19
    static const uint8_t IMR_MR20 = 20;            // Interrupt Mask on line 20
    static const uint8_t IMR_MR21 = 21;            // Interrupt Mask on line 21
    static const uint8_t IMR_MR22 = 22;            // Interrupt Mask on line 22
    static const uint32_t IMR_RESET_VALUE = 0x0;

    static const uint8_t EMR_MR0 = 0;              // Event Mask on line 0
    static const uint8_t EMR_MR1 = 1;              // Event Mask on line 1
    static const uint8_t EMR_MR2 = 2;              // Event Mask on line 2
    static const uint8_t EMR_MR3 = 3;              // Event Mask on line 3
    static const uint8_t EMR_MR4 = 4;              // Event Mask on line 4
    static const uint8_t EMR_MR5 = 5;              // Event Mask on line 5
    static const uint8_t EMR_MR6 = 6;              // Event Mask on line 6
    static const uint8_t EMR_MR7 = 7;              // Event Mask on line 7
    static const uint8_t EMR_MR8 = 8;              // Event Mask on line 8
    static const uint8_t EMR_MR9 = 9;              // Event Mask on line 9
    static const uint8_t EMR_MR10 = 10;            // Event Mask on line 10
    static const uint8_t EMR_MR11 = 11;            // Event Mask on line 11
    static const uint8_t EMR_MR12 = 12;            // Event Mask on line 12
    static const uint8_t EMR_MR13 = 13;            // Event Mask on line 13
    static const uint8_t EMR_MR14 = 14;            // Event Mask on line 14
    static const uint8_t EMR_MR15 = 15;            // Event Mask on line 15
    static const uint8_t EMR_MR16 = 16;            // Event Mask on line 16
    static const uint8_t EMR_MR17 = 17;            // Event Mask on line 17
    static const uint8_t EMR_MR18 = 18;            // Event Mask on line 18
    static const uint8_t EMR_MR19 = 19;            // Event Mask on line 19
    static const uint8_t EMR_MR20 = 20;            // Event Mask on line 20
    static const uint8_t EMR_MR21 = 21;            // Event Mask on line 21
    static const uint8_t EMR_MR22 = 22;            // Event Mask on line 22
    static const uint32_t EMR_RESET_VALUE = 0x0;

    static const uint8_t RTSR_TR0 = 0;              // Rising trigger event configuration of line 0
    static const uint8_t RTSR_TR1 = 1;              // Rising trigger event configuration of line 1
    static const uint8_t RTSR_TR2 = 2;              // Rising trigger event configuration of line 2
    static const uint8_t RTSR_TR3 = 3;              // Rising trigger event configuration of line 3
    static const uint8_t RTSR_TR4 = 4;              // Rising trigger event configuration of line 4
    static const uint8_t RTSR_TR5 = 5;              // Rising trigger event configuration of line 5
    static const uint8_t RTSR_TR6 = 6;              // Rising trigger event configuration of line 6
    static const uint8_t RTSR_TR7 = 7;              // Rising trigger event configuration of line 7
    static const uint8_t RTSR_TR8 = 8;              // Rising trigger event configuration of line 8
    static const uint8_t RTSR_TR9 = 9;              // Rising trigger event configuration of line 9
    static const uint8_t RTSR_TR10 = 10;            // Rising trigger event configuration of line 10
    static const uint8_t RTSR_TR11 = 11;            // Rising trigger event configuration of line 11
    static const uint8_t RTSR_TR12 = 12;            // Rising trigger event configuration of line 12
    static const uint8_t RTSR_TR13 = 13;            // Rising trigger event configuration of line 13
    static const uint8_t RTSR_TR14 = 14;            // Rising trigger event configuration of line 14
    static const uint8_t RTSR_TR15 = 15;            // Rising trigger event configuration of line 15
    static const uint8_t RTSR_TR16 = 16;            // Rising trigger event configuration of line 16
    static const uint8_t RTSR_TR17 = 17;            // Rising trigger event configuration of line 17
    static const uint8_t RTSR_TR18 = 18;            // Rising trigger event configuration of line 18
    static const uint8_t RTSR_TR19 = 19;            // Rising trigger event configuration of line 19
    static const uint8_t RTSR_TR20 = 20;            // Rising trigger event configuration of line 20
    static const uint8_t RTSR_TR21 = 21;            // Rising trigger event configuration of line 21
    static const uint8_t RTSR_TR22 = 22;            // Rising trigger event configuration of line 22
    static const uint32_t RTSR_RESET_VALUE = 0x0;

    static const uint8_t FTSR_TR0 = 0;              // Falling trigger event configuration of line 0
    static const uint8_t FTSR_TR1 = 1;              // Falling trigger event configuration of line 1
    static const uint8_t FTSR_TR2 = 2;              // Falling trigger event configuration of line 2
    static const uint8_t FTSR_TR3 = 3;              // Falling trigger event configuration of line 3
    static const uint8_t FTSR_TR4 = 4;              // Falling trigger event configuration of line 4
    static const uint8_t FTSR_TR5 = 5;              // Falling trigger event configuration of line 5
    static const uint8_t FTSR_TR6 = 6;              // Falling trigger event configuration of line 6
    static const uint8_t FTSR_TR7 = 7;              // Falling trigger event configuration of line 7
    static const uint8_t FTSR_TR8 = 8;              // Falling trigger event configuration of line 8
    static const uint8_t FTSR_TR9 = 9;              // Falling trigger event configuration of line 9
    static const uint8_t FTSR_TR10 = 10;            // Falling trigger event configuration of line 10
    static const uint8_t FTSR_TR11 = 11;            // Falling trigger event configuration of line 11
    static const uint8_t FTSR_TR12 = 12;            // Falling trigger event configuration of line 12
    static const uint8_t FTSR_TR13 = 13;            // Falling trigger event configuration of line 13
    static const uint8_t FTSR_TR14 = 14;            // Falling trigger event configuration of line 14
    static const uint8_t FTSR_TR15 = 15;            // Falling trigger event configuration of line 15
    static const uint8_t FTSR_TR16 = 16;            // Falling trigger event configuration of line 16
    static const uint8_t FTSR_TR17 = 17;            // Falling trigger event configuration of line 17
    static const uint8_t FTSR_TR18 = 18;            // Falling trigger event configuration of line 18
    static const uint8_t FTSR_TR19 = 19;            // Falling trigger event configuration of line 19
    static const uint8_t FTSR_TR20 = 20;            // Falling trigger event configuration of line 20
    static const uint8_t FTSR_TR21 = 21;            // Falling trigger event configuration of line 21
    static const uint8_t FTSR_TR22 = 22;            // Falling trigger event configuration of line 22
    static const uint32_t FTSR_RESET_VALUE = 0x0;

    static const uint8_t SWIER_SWIER0 = 0;           // Software Interrupt on line 0
    static const uint8_t SWIER_SWIER1 = 1;           // Software Interrupt on line 1
    static const uint8_t SWIER_SWIER2 = 2;           // Software Interrupt on line 2
    static const uint8_t SWIER_SWIER3 = 3;           // Software Interrupt on line 3
    static const uint8_t SWIER_SWIER4 = 4;           // Software Interrupt on line 4
    static const uint8_t SWIER_SWIER5 = 5;           // Software Interrupt on line 5
    static const uint8_t SWIER_SWIER6 = 6;           // Software Interrupt on line 6
    static const uint8_t SWIER_SWIER7 = 7;           // Software Interrupt on line 7
    static const uint8_t SWIER_SWIER8 = 8;           // Software Interrupt on line 8
    static const uint8_t SWIER_SWIER9 = 9;           // Software Interrupt on line 9
    static const uint8_t SWIER_SWIER10 = 10;         // Software Interrupt on line 10
    static const uint8_t SWIER_SWIER11 = 11;         // Software Interrupt on line 11
    static const uint8_t SWIER_SWIER12 = 12;         // Software Interrupt on line 12
    static const uint8_t SWIER_SWIER13 = 13;         // Software Interrupt on line 13
    static const uint8_t SWIER_SWIER14 = 14;         // Software Interrupt on line 14
    static const uint8_t SWIER_SWIER15 = 15;         // Software Interrupt on line 15
    static const uint8_t SWIER_SWIER16 = 16;         // Software Interrupt on line 16
    static const uint8_t SWIER_SWIER17 = 17;         // Software Interrupt on line 17
    static const uint8_t SWIER_SWIER18 = 18;         // Software Interrupt on line 18
    static const uint8_t SWIER_SWIER19 = 19;         // Software Interrupt on line 19
    static const uint8_t SWIER_SWIER20 = 20;         // Software Interrupt on line 20
    static const uint8_t SWIER_SWIER21 = 21;         // Software Interrupt on line 21
    static const uint8_t SWIER_SWIER22 = 22;         // Software Interrupt on line 22
    static const uint32_t SWIER_RESET_VALUE = 0x0;

    static const uint8_t PR_PR0 = 0;              // Pending bit 0
    static const uint8_t PR_PR1 = 1;              // Pending bit 1
    static const uint8_t PR_PR2 = 2;              // Pending bit 2
    static const uint8_t PR_PR3 = 3;              // Pending bit 3
    static const uint8_t PR_PR4 = 4;              // Pending bit 4
    static const uint8_t PR_PR5 = 5;              // Pending bit 5
    static const uint8_t PR_PR6 = 6;              // Pending bit 6
    static const uint8_t PR_PR7 = 7;              // Pending bit 7
    static const uint8_t PR_PR8 = 8;              // Pending bit 8
    static const uint8_t PR_PR9 = 9;              // Pending bit 9
    static const uint8_t PR_PR10 = 10;            // Pending bit 10
    static const uint8_t PR_PR11 = 11;            // Pending bit 11
    static const uint8_t PR_PR12 = 12;            // Pending bit 12
    static const uint8_t PR_PR13 = 13;            // Pending bit 13
    static const uint8_t PR_PR14 = 14;            // Pending bit 14
    static const uint8_t PR_PR15 = 15;            // Pending bit 15
    static const uint8_t PR_PR16 = 16;            // Pending bit 16
    static const uint8_t PR_PR17 = 17;            // Pending bit 17
    static const uint8_t PR_PR18 = 18;            // Pending bit 18
    static const uint8_t PR_PR19 = 19;            // Pending bit 19
    static const uint8_t PR_PR20 = 20;            // Pending bit 20
    static const uint8_t PR_PR21 = 21;            // Pending bit 21
    static const uint8_t PR_PR22 = 22;            // Pending bit 22
    static const uint32_t PR_RESET_VALUE = 0x0;
};

static exti_t& EXTI = *reinterpret_cast<exti_t*>(0x40013c00);


////
//
//    FLASH
//
////

struct flash_t
{
    volatile uint32_t    ACR;                  // Flash access control register
    volatile uint32_t    KEYR;                 // [Write-only] Flash key register
    volatile uint32_t    OPTKEYR;              // [Write-only] Flash option key register
    volatile uint32_t    SR;                   // Status register
    volatile uint32_t    CR;                   // [Read-write] Control register
    volatile uint32_t    OPTCR;                // [Read-write] Flash option control register

    static const uint8_t ACR_LATENCY = 0;          // Latency (3 bits), Read-write
    static const uint8_t ACR_PRFTEN = 8;           // Prefetch enable, Read-write
    static const uint8_t ACR_ICEN = 9;             // Instruction cache enable, Read-write
    static const uint8_t ACR_DCEN = 10;            // Data cache enable, Read-write
    static const uint8_t ACR_ICRST = 11;           // Instruction cache reset, Write-only
    static const uint8_t ACR_DCRST = 12;           // Data cache reset, Read-write
    static const uint32_t ACR_RESET_VALUE = 0x0;

    static const uint8_t KEYR_KEY = 0;              // FPEC key (32 bits)
    static const uint32_t KEYR_RESET_VALUE = 0x0;

    static const uint8_t OPTKEYR_OPTKEY = 0;           // Option byte key (32 bits)
    static const uint32_t OPTKEYR_RESET_VALUE = 0x0;

    static const uint8_t SR_EOP = 0;              // End of operation, Read-write
    static const uint8_t SR_OPERR = 1;            // Operation error, Read-write
    static const uint8_t SR_WRPERR = 4;           // Write protection error, Read-write
    static const uint8_t SR_PGAERR = 5;           // Programming alignment error, Read-write
    static const uint8_t SR_PGPERR = 6;           // Programming parallelism error, Read-write
    static const uint8_t SR_PGSERR = 7;           // Programming sequence error, Read-write
    static const uint8_t SR_BSY = 16;             // Busy, Read-only
    static const uint32_t SR_RESET_VALUE = 0x0;

    static const uint8_t CR_PG = 0;               // Programming
    static const uint8_t CR_SER = 1;              // Sector Erase
    static const uint8_t CR_MER = 2;              // Mass Erase
    static const uint8_t CR_SNB = 3;              // Sector number (4 bits)
    static const uint8_t CR_PSIZE = 8;            // Program size (2 bits)
    static const uint8_t CR_STRT = 16;            // Start
    static const uint8_t CR_EOPIE = 24;           // End of operation interrupt enable
    static const uint8_t CR_ERRIE = 25;           // Error interrupt enable
    static const uint8_t CR_LOCK = 31;            // Lock
    static const uint32_t CR_RESET_VALUE = 0x80000000;

    static const uint8_t OPTCR_OPTLOCK = 0;          // Option lock
    static const uint8_t OPTCR_OPTSTRT = 1;          // Option start
    static const uint8_t OPTCR_BOR_LEV = 2;          // BOR reset Level (2 bits)
    static const uint8_t OPTCR_WDG_SW = 5;           // WDG_SW User option bytes
    static const uint8_t OPTCR_nRST_STOP = 6;        // nRST_STOP User option bytes
    static const uint8_t OPTCR_nRST_STDBY = 7;       // nRST_STDBY User option bytes
    static const uint8_t OPTCR_RDP = 8;              // Read protect (8 bits)
    static const uint8_t OPTCR_nWRP = 16;            // Not write protect (12 bits)
    static const uint32_t OPTCR_RESET_VALUE = 0x14;
};

static flash_t& FLASH = *reinterpret_cast<flash_t*>(0x40023c00);


////
//
//    Independent watchdog
//
////

struct iwdg_t
{
    volatile uint32_t    KR;                   // [Write-only] Key register
    volatile uint32_t    PR;                   // [Read-write] Prescaler register
    volatile uint32_t    RLR;                  // [Read-write] Reload register
    volatile uint32_t    SR;                   // [Read-only] Status register

    static const uint8_t KR_KEY = 0;              // Key value (16 bits)
    static const uint32_t KR_RESET_VALUE = 0x0;

    static const uint8_t PR_PR = 0;               // Prescaler divider (3 bits)
    static const uint32_t PR_RESET_VALUE = 0x0;

    static const uint8_t RLR_RL = 0;               // Watchdog counter reload value (12 bits)
    static const uint32_t RLR_RESET_VALUE = 0xfff;

    static const uint8_t SR_RVU = 1;              // Watchdog counter reload value update
    static const uint8_t SR_PVU = 0;              // Watchdog prescaler value update
    static const uint32_t SR_RESET_VALUE = 0x0;
};

static iwdg_t& IWDG = *reinterpret_cast<iwdg_t*>(0x40003000);


////
//
//    Power control
//
////

struct pwr_t
{
    volatile uint32_t    CR;                   // [Read-write] power control register
    volatile uint32_t    CSR;                  // power control/status register

    static const uint8_t CR_VOS = 14;             // Regulator voltage scaling output selection (2 bits)
    static const uint8_t CR_ADCDC1 = 13;          // ADCDC1
    static const uint8_t CR_FPDS = 9;             // Flash power down in Stop mode
    static const uint8_t CR_DBP = 8;              // Disable backup domain write protection
    static const uint8_t CR_PLS = 5;              // PVD level selection (3 bits)
    static const uint8_t CR_PVDE = 4;             // Power voltage detector enable
    static const uint8_t CR_CSBF = 3;             // Clear standby flag
    static const uint8_t CR_CWUF = 2;             // Clear wakeup flag
    static const uint8_t CR_PDDS = 1;             // Power down deepsleep
    static const uint8_t CR_LPDS = 0;             // Low-power deep sleep
    static const uint32_t CR_RESET_VALUE = 0x0;

    static const uint8_t CSR_WUF = 0;              // Wakeup flag, Read-only
    static const uint8_t CSR_SBF = 1;              // Standby flag, Read-only
    static const uint8_t CSR_PVDO = 2;             // PVD output, Read-only
    static const uint8_t CSR_BRR = 3;              // Backup regulator ready, Read-only
    static const uint8_t CSR_EWUP = 8;             // Enable WKUP pin, Read-write
    static const uint8_t CSR_BRE = 9;              // Backup regulator enable, Read-write
    static const uint8_t CSR_VOSRDY = 14;          // Regulator voltage scaling output selection ready bit, Read-write
    static const uint32_t CSR_RESET_VALUE = 0x0;
};

static pwr_t& PWR = *reinterpret_cast<pwr_t*>(0x40007000);


////
//
//    Reset and clock control
//
////

struct rcc_t
{
    volatile uint32_t    CR;                   // clock control register
    volatile uint32_t    PLLCFGR;              // [Read-write] PLL configuration register
    volatile uint32_t    CFGR;                 // clock configuration register
    volatile uint32_t    CIR;                  // clock interrupt register
    volatile uint32_t    AHB1RSTR;             // [Read-write] AHB1 peripheral reset register
    volatile uint32_t    AHB2RSTR;             // [Read-write] AHB2 peripheral reset register
    reserved_t<2>        _0;
    volatile uint32_t    APB1RSTR;             // [Read-write] APB1 peripheral reset register
    volatile uint32_t    APB2RSTR;             // [Read-write] APB2 peripheral reset register
    reserved_t<2>        _1;
    volatile uint32_t    AHB1ENR;              // [Read-write] AHB1 peripheral clock register
    volatile uint32_t    AHB2ENR;              // [Read-write] AHB2 peripheral clock enable register
    reserved_t<2>        _2;
    volatile uint32_t    APB1ENR;              // [Read-write] APB1 peripheral clock enable register
    volatile uint32_t    APB2ENR;              // [Read-write] APB2 peripheral clock enable register
    reserved_t<2>        _3;
    volatile uint32_t    AHB1LPENR;            // [Read-write] AHB1 peripheral clock enable in low power mode register
    volatile uint32_t    AHB2LPENR;            // [Read-write] AHB2 peripheral clock enable in low power mode register
    reserved_t<2>        _4;
    volatile uint32_t    APB1LPENR;            // [Read-write] APB1 peripheral clock enable in low power mode register
    volatile uint32_t    APB2LPENR;            // [Read-write] APB2 peripheral clock enabled in low power mode register
    reserved_t<2>        _5;
    volatile uint32_t    BDCR;                 // Backup domain control register
    volatile uint32_t    CSR;                  // clock control &amp; status register
    reserved_t<2>        _6;
    volatile uint32_t    SSCGR;                // [Read-write] spread spectrum clock generation register
    volatile uint32_t    PLLI2SCFGR;           // [Read-write] PLLI2S configuration register

    static const uint8_t CR_PLLI2SRDY = 27;       // PLLI2S clock ready flag, Read-only
    static const uint8_t CR_PLLI2SON = 26;        // PLLI2S enable, Read-write
    static const uint8_t CR_PLLRDY = 25;          // Main PLL (PLL) clock ready flag, Read-only
    static const uint8_t CR_PLLON = 24;           // Main PLL (PLL) enable, Read-write
    static const uint8_t CR_CSSON = 19;           // Clock security system enable, Read-write
    static const uint8_t CR_HSEBYP = 18;          // HSE clock bypass, Read-write
    static const uint8_t CR_HSERDY = 17;          // HSE clock ready flag, Read-only
    static const uint8_t CR_HSEON = 16;           // HSE clock enable, Read-write
    static const uint8_t CR_HSICAL = 8;           // Internal high-speed clock calibration (8 bits), Read-only
    static const uint8_t CR_HSITRIM = 3;          // Internal high-speed clock trimming (5 bits), Read-write
    static const uint8_t CR_HSIRDY = 1;           // Internal high-speed clock ready flag, Read-only
    static const uint8_t CR_HSION = 0;            // Internal high-speed clock enable, Read-write
    static const uint32_t CR_RESET_VALUE = 0x83;

    static const uint8_t PLLCFGR_PLLQ3 = 27;           // Main PLL (PLL) division factor for USB OTG FS, SDIO and random number generator clocks
    static const uint8_t PLLCFGR_PLLQ2 = 26;           // Main PLL (PLL) division factor for USB OTG FS, SDIO and random number generator clocks
    static const uint8_t PLLCFGR_PLLQ1 = 25;           // Main PLL (PLL) division factor for USB OTG FS, SDIO and random number generator clocks
    static const uint8_t PLLCFGR_PLLQ0 = 24;           // Main PLL (PLL) division factor for USB OTG FS, SDIO and random number generator clocks
    static const uint8_t PLLCFGR_PLLSRC = 22;          // Main PLL(PLL) and audio PLL (PLLI2S) entry clock source
    static const uint8_t PLLCFGR_PLLP1 = 17;           // Main PLL (PLL) division factor for main system clock
    static const uint8_t PLLCFGR_PLLP0 = 16;           // Main PLL (PLL) division factor for main system clock
    static const uint8_t PLLCFGR_PLLN8 = 14;           // Main PLL (PLL) multiplication factor for VCO
    static const uint8_t PLLCFGR_PLLN7 = 13;           // Main PLL (PLL) multiplication factor for VCO
    static const uint8_t PLLCFGR_PLLN6 = 12;           // Main PLL (PLL) multiplication factor for VCO
    static const uint8_t PLLCFGR_PLLN5 = 11;           // Main PLL (PLL) multiplication factor for VCO
    static const uint8_t PLLCFGR_PLLN4 = 10;           // Main PLL (PLL) multiplication factor for VCO
    static const uint8_t PLLCFGR_PLLN3 = 9;            // Main PLL (PLL) multiplication factor for VCO
    static const uint8_t PLLCFGR_PLLN2 = 8;            // Main PLL (PLL) multiplication factor for VCO
    static const uint8_t PLLCFGR_PLLN1 = 7;            // Main PLL (PLL) multiplication factor for VCO
    static const uint8_t PLLCFGR_PLLN0 = 6;            // Main PLL (PLL) multiplication factor for VCO
    static const uint8_t PLLCFGR_PLLM5 = 5;            // Division factor for the main PLL (PLL) and audio PLL (PLLI2S) input clock
    static const uint8_t PLLCFGR_PLLM4 = 4;            // Division factor for the main PLL (PLL) and audio PLL (PLLI2S) input clock
    static const uint8_t PLLCFGR_PLLM3 = 3;            // Division factor for the main PLL (PLL) and audio PLL (PLLI2S) input clock
    static const uint8_t PLLCFGR_PLLM2 = 2;            // Division factor for the main PLL (PLL) and audio PLL (PLLI2S) input clock
    static const uint8_t PLLCFGR_PLLM1 = 1;            // Division factor for the main PLL (PLL) and audio PLL (PLLI2S) input clock
    static const uint8_t PLLCFGR_PLLM0 = 0;            // Division factor for the main PLL (PLL) and audio PLL (PLLI2S) input clock
    static const uint32_t PLLCFGR_RESET_VALUE = 0x24003010;

    static const uint8_t CFGR_MCO2 = 30;            // Microcontroller clock output 2 (2 bits), Read-write
    static const uint8_t CFGR_MCO2PRE = 27;         // MCO2 prescaler (3 bits), Read-write
    static const uint8_t CFGR_MCO1PRE = 24;         // MCO1 prescaler (3 bits), Read-write
    static const uint8_t CFGR_I2SSRC = 23;          // I2S clock selection, Read-write
    static const uint8_t CFGR_MCO1 = 21;            // Microcontroller clock output 1 (2 bits), Read-write
    static const uint8_t CFGR_RTCPRE = 16;          // HSE division factor for RTC clock (5 bits), Read-write
    static const uint8_t CFGR_PPRE2 = 13;           // APB high-speed prescaler (APB2) (3 bits), Read-write
    static const uint8_t CFGR_PPRE1 = 10;           // APB Low speed prescaler (APB1) (3 bits), Read-write
    static const uint8_t CFGR_HPRE = 4;             // AHB prescaler (4 bits), Read-write
    static const uint8_t CFGR_SWS1 = 3;             // System clock switch status, Read-only
    static const uint8_t CFGR_SWS0 = 2;             // System clock switch status, Read-only
    static const uint8_t CFGR_SW1 = 1;              // System clock switch, Read-write
    static const uint8_t CFGR_SW0 = 0;              // System clock switch, Read-write
    static const uint32_t CFGR_RESET_VALUE = 0x0;

    static const uint8_t CIR_CSSC = 23;            // Clock security system interrupt clear, Write-only
    static const uint8_t CIR_PLLI2SRDYC = 21;      // PLLI2S ready interrupt clear, Write-only
    static const uint8_t CIR_PLLRDYC = 20;         // Main PLL(PLL) ready interrupt clear, Write-only
    static const uint8_t CIR_HSERDYC = 19;         // HSE ready interrupt clear, Write-only
    static const uint8_t CIR_HSIRDYC = 18;         // HSI ready interrupt clear, Write-only
    static const uint8_t CIR_LSERDYC = 17;         // LSE ready interrupt clear, Write-only
    static const uint8_t CIR_LSIRDYC = 16;         // LSI ready interrupt clear, Write-only
    static const uint8_t CIR_PLLI2SRDYIE = 13;     // PLLI2S ready interrupt enable, Read-write
    static const uint8_t CIR_PLLRDYIE = 12;        // Main PLL (PLL) ready interrupt enable, Read-write
    static const uint8_t CIR_HSERDYIE = 11;        // HSE ready interrupt enable, Read-write
    static const uint8_t CIR_HSIRDYIE = 10;        // HSI ready interrupt enable, Read-write
    static const uint8_t CIR_LSERDYIE = 9;         // LSE ready interrupt enable, Read-write
    static const uint8_t CIR_LSIRDYIE = 8;         // LSI ready interrupt enable, Read-write
    static const uint8_t CIR_CSSF = 7;             // Clock security system interrupt flag, Read-only
    static const uint8_t CIR_PLLI2SRDYF = 5;       // PLLI2S ready interrupt flag, Read-only
    static const uint8_t CIR_PLLRDYF = 4;          // Main PLL (PLL) ready interrupt flag, Read-only
    static const uint8_t CIR_HSERDYF = 3;          // HSE ready interrupt flag, Read-only
    static const uint8_t CIR_HSIRDYF = 2;          // HSI ready interrupt flag, Read-only
    static const uint8_t CIR_LSERDYF = 1;          // LSE ready interrupt flag, Read-only
    static const uint8_t CIR_LSIRDYF = 0;          // LSI ready interrupt flag, Read-only
    static const uint32_t CIR_RESET_VALUE = 0x0;

    static const uint8_t AHB1RSTR_GPIOARST = 0;         // IO port A reset
    static const uint8_t AHB1RSTR_GPIOBRST = 1;         // IO port B reset
    static const uint8_t AHB1RSTR_GPIOCRST = 2;         // IO port C reset
    static const uint8_t AHB1RSTR_GPIODRST = 3;         // IO port D reset
    static const uint8_t AHB1RSTR_GPIOERST = 4;         // IO port E reset
    static const uint8_t AHB1RSTR_GPIOFRST = 5;         // IO port F reset
    static const uint8_t AHB1RSTR_GPIOGRST = 6;         // IO port G reset
    static const uint8_t AHB1RSTR_GPIOHRST = 7;         // IO port H reset
    static const uint8_t AHB1RSTR_CRCRST = 12;          // CRC reset
    static const uint8_t AHB1RSTR_DMA1RST = 21;         // DMA2 reset
    static const uint8_t AHB1RSTR_DMA2RST = 22;         // DMA2 reset
    static const uint32_t AHB1RSTR_RESET_VALUE = 0x0;

    static const uint8_t AHB2RSTR_OTGFSRST = 7;         // USB OTG FS module reset
    static const uint8_t AHB2RSTR_RNGRST = 6;           // RNGRST
    static const uint32_t AHB2RSTR_RESET_VALUE = 0x0;

    static const uint8_t APB1RSTR_TIM2RST = 0;          // TIM2 reset
    static const uint8_t APB1RSTR_TIM3RST = 1;          // TIM3 reset
    static const uint8_t APB1RSTR_TIM4RST = 2;          // TIM4 reset
    static const uint8_t APB1RSTR_TIM5RST = 3;          // TIM5 reset
    static const uint8_t APB1RSTR_TIM6RST = 4;          // TIM6RST
    static const uint8_t APB1RSTR_TIM7RST = 5;          // TIM7RST
    static const uint8_t APB1RSTR_TIM12RST = 6;         // TIM12RST
    static const uint8_t APB1RSTR_TIM13RST = 7;         // TIM13RST
    static const uint8_t APB1RSTR_TIM14RST = 8;         // TIM14RST
    static const uint8_t APB1RSTR_WWDGRST = 11;         // Window watchdog reset
    static const uint8_t APB1RSTR_SPI2RST = 14;         // SPI 2 reset
    static const uint8_t APB1RSTR_SPI3RST = 15;         // SPI 3 reset
    static const uint8_t APB1RSTR_UART2RST = 17;        // USART 2 reset
    static const uint8_t APB1RSTR_USART3RST = 18;       // USART3RST
    static const uint8_t APB1RSTR_I2C1RST = 21;         // I2C 1 reset
    static const uint8_t APB1RSTR_I2C2RST = 22;         // I2C 2 reset
    static const uint8_t APB1RSTR_I2C3RST = 23;         // I2C3 reset
    static const uint8_t APB1RSTR_I2C4RST = 24;         // I2C4RST
    static const uint8_t APB1RSTR_CAN1RST = 25;         // CAN1RST
    static const uint8_t APB1RSTR_CAN2RST = 26;         // CAN2RST
    static const uint8_t APB1RSTR_PWRRST = 28;          // Power interface reset
    static const uint32_t APB1RSTR_RESET_VALUE = 0x0;

    static const uint8_t APB2RSTR_TIM1RST = 0;          // TIM1 reset
    static const uint8_t APB2RSTR_TIM8RST = 1;          // TIM8RST
    static const uint8_t APB2RSTR_USART1RST = 4;        // USART1 reset
    static const uint8_t APB2RSTR_USART6RST = 5;        // USART6 reset
    static const uint8_t APB2RSTR_ADCRST = 8;           // ADC interface reset (common to all ADCs)
    static const uint8_t APB2RSTR_SDIORST = 11;         // SDIO reset
    static const uint8_t APB2RSTR_SPI1RST = 12;         // SPI 1 reset
    static const uint8_t APB2RSTR_SYSCFGRST = 14;       // System configuration controller reset
    static const uint8_t APB2RSTR_TIM9RST = 16;         // TIM9 reset
    static const uint8_t APB2RSTR_TIM10RST = 17;        // TIM10 reset
    static const uint8_t APB2RSTR_TIM11RST = 18;        // TIM11 reset
    static const uint8_t APB2RSTR_DFSDMRST = 24;        // DFSDMRST
    static const uint32_t APB2RSTR_RESET_VALUE = 0x0;

    static const uint8_t AHB1ENR_GPIOAEN = 0;          // IO port A clock enable
    static const uint8_t AHB1ENR_GPIOBEN = 1;          // IO port B clock enable
    static const uint8_t AHB1ENR_GPIOCEN = 2;          // IO port C clock enable
    static const uint8_t AHB1ENR_GPIODEN = 3;          // IO port D clock enable
    static const uint8_t AHB1ENR_GPIOEEN = 4;          // IO port E clock enable
    static const uint8_t AHB1ENR_GPIOFEN = 5;          // IO port F clock enable
    static const uint8_t AHB1ENR_GPIOGEN = 6;          // IO port G clock enable
    static const uint8_t AHB1ENR_GPIOHEN = 7;          // IO port H clock enable
    static const uint8_t AHB1ENR_CRCEN = 12;           // CRC clock enable
    static const uint8_t AHB1ENR_DMA1EN = 21;          // DMA1 clock enable
    static const uint8_t AHB1ENR_DMA2EN = 22;          // DMA2 clock enable
    static const uint32_t AHB1ENR_RESET_VALUE = 0x100000;

    static const uint8_t AHB2ENR_OTGFSEN = 7;          // USB OTG FS clock enable
    static const uint8_t AHB2ENR_RNGEN = 6;            // RNGEN
    static const uint32_t AHB2ENR_RESET_VALUE = 0x0;

    static const uint8_t APB1ENR_TIM2EN = 0;           // TIM2 clock enable
    static const uint8_t APB1ENR_TIM3EN = 1;           // TIM3 clock enable
    static const uint8_t APB1ENR_TIM4EN = 2;           // TIM4 clock enable
    static const uint8_t APB1ENR_TIM5EN = 3;           // TIM5 clock enable
    static const uint8_t APB1ENR_TIM6EN = 4;           // TIM6EN
    static const uint8_t APB1ENR_TIM7EN = 5;           // TIM7EN
    static const uint8_t APB1ENR_TIM12EN = 6;          // TIM12EN
    static const uint8_t APB1ENR_TIM13EN = 7;          // TIM13EN
    static const uint8_t APB1ENR_TIM14EN = 8;          // TIM14EN
    static const uint8_t APB1ENR_WWDGEN = 11;          // Window watchdog clock enable
    static const uint8_t APB1ENR_SPI2EN = 14;          // SPI2 clock enable
    static const uint8_t APB1ENR_SPI3EN = 15;          // SPI3 clock enable
    static const uint8_t APB1ENR_USART2EN = 17;        // USART 2 clock enable
    static const uint8_t APB1ENR_USART3EN = 18;        // USART3EN
    static const uint8_t APB1ENR_I2C1EN = 21;          // I2C1 clock enable
    static const uint8_t APB1ENR_I2C2EN = 22;          // I2C2 clock enable
    static const uint8_t APB1ENR_I2C3EN = 23;          // I2C3 clock enable
    static const uint8_t APB1ENR_I2C4EN = 24;          // I2C4EN
    static const uint8_t APB1ENR_CAN1EN = 25;          // CAN1EN
    static const uint8_t APB1ENR_CAN2EN = 26;          // CAN2EN
    static const uint8_t APB1ENR_PWREN = 28;           // Power interface clock enable
    static const uint32_t APB1ENR_RESET_VALUE = 0x0;

    static const uint8_t APB2ENR_TIM1EN = 0;           // TIM1 clock enable
    static const uint8_t APB2ENR_TIM8EN = 1;           // TIM8EN
    static const uint8_t APB2ENR_USART1EN = 4;         // USART1 clock enable
    static const uint8_t APB2ENR_USART6EN = 5;         // USART6 clock enable
    static const uint8_t APB2ENR_ADC1EN = 8;           // ADC1 clock enable
    static const uint8_t APB2ENR_SDIOEN = 11;          // SDIO clock enable
    static const uint8_t APB2ENR_SPI1EN = 12;          // SPI1 clock enable
    static const uint8_t APB2ENR_SPI4EN = 13;          // SPI4 clock enable
    static const uint8_t APB2ENR_SYSCFGEN = 14;        // System configuration controller clock enable
    static const uint8_t APB2ENR_TIM9EN = 16;          // TIM9 clock enable
    static const uint8_t APB2ENR_TIM10EN = 17;         // TIM10 clock enable
    static const uint8_t APB2ENR_TIM11EN = 18;         // TIM11 clock enable
    static const uint8_t APB2ENR_DFSDMEN = 24;         // DFSDMEN
    static const uint32_t APB2ENR_RESET_VALUE = 0x0;

    static const uint8_t AHB1LPENR_GPIOALPEN = 0;        // IO port A clock enable during sleep mode
    static const uint8_t AHB1LPENR_GPIOBLPEN = 1;        // IO port B clock enable during Sleep mode
    static const uint8_t AHB1LPENR_GPIOCLPEN = 2;        // IO port C clock enable during Sleep mode
    static const uint8_t AHB1LPENR_GPIODLPEN = 3;        // IO port D clock enable during Sleep mode
    static const uint8_t AHB1LPENR_GPIOELPEN = 4;        // IO port E clock enable during Sleep mode
    static const uint8_t AHB1LPENR_GPIOFLPEN = 5;        // IO port F clock enable during sleep mode
    static const uint8_t AHB1LPENR_GPIOGLPEN = 6;        // IO port G clock enable during sleep mode
    static const uint8_t AHB1LPENR_GPIOHLPEN = 7;        // IO port H clock enable during Sleep mode
    static const uint8_t AHB1LPENR_CRCLPEN = 12;         // CRC clock enable during Sleep mode
    static const uint8_t AHB1LPENR_FLITFLPEN = 15;       // Flash interface clock enable during Sleep mode
    static const uint8_t AHB1LPENR_SRAM1LPEN = 16;       // SRAM 1interface clock enable during Sleep mode
    static const uint8_t AHB1LPENR_DMA1LPEN = 21;        // DMA1 clock enable during Sleep mode
    static const uint8_t AHB1LPENR_DMA2LPEN = 22;        // DMA2 clock enable during Sleep mode
    static const uint32_t AHB1LPENR_RESET_VALUE = 0x7e6791ff;

    static const uint8_t AHB2LPENR_OTGFSLPEN = 7;        // USB OTG FS clock enable during Sleep mode
    static const uint8_t AHB2LPENR_RNGLPEN = 6;          // RNGLPEN
    static const uint32_t AHB2LPENR_RESET_VALUE = 0xf1;

    static const uint8_t APB1LPENR_TIM2LPEN = 0;         // TIM2 clock enable during Sleep mode
    static const uint8_t APB1LPENR_TIM3LPEN = 1;         // TIM3 clock enable during Sleep mode
    static const uint8_t APB1LPENR_TIM4LPEN = 2;         // TIM4 clock enable during Sleep mode
    static const uint8_t APB1LPENR_TIM5LPEN = 3;         // TIM5 clock enable during Sleep mode
    static const uint8_t APB1LPENR_TIM6LPEN = 4;         // TIM6LPEN
    static const uint8_t APB1LPENR_TIM7LPEN = 5;         // TIM7LPEN
    static const uint8_t APB1LPENR_TIM12LPEN = 6;        // TIM12LPEN
    static const uint8_t APB1LPENR_TIM13LPEN = 7;        // TIM13LPEN
    static const uint8_t APB1LPENR_TIM14LPEN = 8;        // TIM14LPEN
    static const uint8_t APB1LPENR_WWDGLPEN = 11;        // Window watchdog clock enable during Sleep mode
    static const uint8_t APB1LPENR_SPI2LPEN = 14;        // SPI2 clock enable during Sleep mode
    static const uint8_t APB1LPENR_SPI3LPEN = 15;        // SPI3 clock enable during Sleep mode
    static const uint8_t APB1LPENR_USART2LPEN = 17;      // USART2 clock enable during Sleep mode
    static const uint8_t APB1LPENR_USART3LPEN = 18;      // USART3LPEN
    static const uint8_t APB1LPENR_I2C1LPEN = 21;        // I2C1 clock enable during Sleep mode
    static const uint8_t APB1LPENR_I2C2LPEN = 22;        // I2C2 clock enable during Sleep mode
    static const uint8_t APB1LPENR_I2C3LPEN = 23;        // I2C3 clock enable during Sleep mode
    static const uint8_t APB1LPENR_I2C4LPEN = 24;        // I2C4LPEN
    static const uint8_t APB1LPENR_CAN1LPEN = 25;        // CAN1LPEN
    static const uint8_t APB1LPENR_CAN2LPEN = 26;        // CAN2LPEN
    static const uint8_t APB1LPENR_PWRLPEN = 28;         // Power interface clock enable during Sleep mode
    static const uint32_t APB1LPENR_RESET_VALUE = 0x36fec9ff;

    static const uint8_t APB2LPENR_TIM1LPEN = 0;         // TIM1 clock enable during Sleep mode
    static const uint8_t APB2LPENR_TIM8LPEN = 1;         // TIM8LPEN
    static const uint8_t APB2LPENR_USART1LPEN = 4;       // USART1 clock enable during Sleep mode
    static const uint8_t APB2LPENR_USART6LPEN = 5;       // USART6 clock enable during Sleep mode
    static const uint8_t APB2LPENR_ADC1LPEN = 8;         // ADC1 clock enable during Sleep mode
    static const uint8_t APB2LPENR_SDIOLPEN = 11;        // SDIO clock enable during Sleep mode
    static const uint8_t APB2LPENR_SPI1LPEN = 12;        // SPI 1 clock enable during Sleep mode
    static const uint8_t APB2LPENR_SPI4LPEN = 13;        // SPI4 clock enable during Sleep mode
    static const uint8_t APB2LPENR_SYSCFGLPEN = 14;      // System configuration controller clock enable during Sleep mode
    static const uint8_t APB2LPENR_TIM9LPEN = 16;        // TIM9 clock enable during sleep mode
    static const uint8_t APB2LPENR_TIM10LPEN = 17;       // TIM10 clock enable during Sleep mode
    static const uint8_t APB2LPENR_TIM11LPEN = 18;       // TIM11 clock enable during Sleep mode
    static const uint8_t APB2LPENR_DFSDMLPEN = 24;       // DFSDMLPEN
    static const uint32_t APB2LPENR_RESET_VALUE = 0x75f33;

    static const uint8_t BDCR_BDRST = 16;           // Backup domain software reset, Read-write
    static const uint8_t BDCR_RTCEN = 15;           // RTC clock enable, Read-write
    static const uint8_t BDCR_RTCSEL1 = 9;          // RTC clock source selection, Read-write
    static const uint8_t BDCR_RTCSEL0 = 8;          // RTC clock source selection, Read-write
    static const uint8_t BDCR_LSEBYP = 2;           // External low-speed oscillator bypass, Read-write
    static const uint8_t BDCR_LSERDY = 1;           // External low-speed oscillator ready, Read-only
    static const uint8_t BDCR_LSEON = 0;            // External low-speed oscillator enable, Read-write
    static const uint32_t BDCR_RESET_VALUE = 0x0;

    static const uint8_t CSR_LPWRRSTF = 31;        // Low-power reset flag, Read-write
    static const uint8_t CSR_WWDGRSTF = 30;        // Window watchdog reset flag, Read-write
    static const uint8_t CSR_WDGRSTF = 29;         // Independent watchdog reset flag, Read-write
    static const uint8_t CSR_SFTRSTF = 28;         // Software reset flag, Read-write
    static const uint8_t CSR_PORRSTF = 27;         // POR/PDR reset flag, Read-write
    static const uint8_t CSR_PADRSTF = 26;         // PIN reset flag, Read-write
    static const uint8_t CSR_BORRSTF = 25;         // BOR reset flag, Read-write
    static const uint8_t CSR_RMVF = 24;            // Remove reset flag, Read-write
    static const uint8_t CSR_LSIRDY = 1;           // Internal low-speed oscillator ready, Read-only
    static const uint8_t CSR_LSION = 0;            // Internal low-speed oscillator enable, Read-write
    static const uint32_t CSR_RESET_VALUE = 0xe000000;

    static const uint8_t SSCGR_SSCGEN = 31;          // Spread spectrum modulation enable
    static const uint8_t SSCGR_SPREADSEL = 30;       // Spread Select
    static const uint8_t SSCGR_INCSTEP = 13;         // Incrementation step (15 bits)
    static const uint8_t SSCGR_MODPER = 0;           // Modulation period (13 bits)
    static const uint32_t SSCGR_RESET_VALUE = 0x0;

    static const uint8_t PLLI2SCFGR_PLLI2SRx = 28;        // PLLI2S division factor for I2S clocks (3 bits)
    static const uint8_t PLLI2SCFGR_PLLI2SNx = 6;         // PLLI2S multiplication factor for VCO (9 bits)
    static const uint32_t PLLI2SCFGR_RESET_VALUE = 0x20003000;
};

static rcc_t& RCC = *reinterpret_cast<rcc_t*>(0x40023800);


////
//
//    Real-time clock
//
////

struct rtc_t
{
    volatile uint32_t    TR;                   // [Read-write] time register
    volatile uint32_t    DR;                   // [Read-write] date register
    volatile uint32_t    CR;                   // [Read-write] control register
    volatile uint32_t    ISR;                  // initialization and status register
    volatile uint32_t    PRER;                 // [Read-write] prescaler register
    volatile uint32_t    WUTR;                 // [Read-write] wakeup timer register
    volatile uint32_t    CALIBR;               // [Read-write] calibration register
    volatile uint32_t    ALRMAR;               // [Read-write] alarm A register
    volatile uint32_t    ALRMBR;               // [Read-write] alarm B register
    volatile uint32_t    WPR;                  // [Write-only] write protection register
    volatile uint32_t    SSR;                  // [Read-only] sub second register
    volatile uint32_t    SHIFTR;               // [Write-only] shift control register
    volatile uint32_t    TSTR;                 // [Read-only] time stamp time register
    volatile uint32_t    TSDR;                 // [Read-only] time stamp date register
    volatile uint32_t    TSSSR;                // [Read-only] timestamp sub second register
    volatile uint32_t    CALR;                 // [Read-write] calibration register
    volatile uint32_t    TAFCR;                // [Read-write] tamper and alternate function configuration register
    volatile uint32_t    ALRMASSR;             // [Read-write] alarm A sub second register
    volatile uint32_t    ALRMBSSR;             // [Read-write] alarm B sub second register
    reserved_t<1>        _0;
    volatile uint32_t    BKP0R;                // [Read-write] backup register
    volatile uint32_t    BKP1R;                // [Read-write] backup register
    volatile uint32_t    BKP2R;                // [Read-write] backup register
    volatile uint32_t    BKP3R;                // [Read-write] backup register
    volatile uint32_t    BKP4R;                // [Read-write] backup register
    volatile uint32_t    BKP5R;                // [Read-write] backup register
    volatile uint32_t    BKP6R;                // [Read-write] backup register
    volatile uint32_t    BKP7R;                // [Read-write] backup register
    volatile uint32_t    BKP8R;                // [Read-write] backup register
    volatile uint32_t    BKP9R;                // [Read-write] backup register
    volatile uint32_t    BKP10R;               // [Read-write] backup register
    volatile uint32_t    BKP11R;               // [Read-write] backup register
    volatile uint32_t    BKP12R;               // [Read-write] backup register
    volatile uint32_t    BKP13R;               // [Read-write] backup register
    volatile uint32_t    BKP14R;               // [Read-write] backup register
    volatile uint32_t    BKP15R;               // [Read-write] backup register
    volatile uint32_t    BKP16R;               // [Read-write] backup register
    volatile uint32_t    BKP17R;               // [Read-write] backup register
    volatile uint32_t    BKP18R;               // [Read-write] backup register
    volatile uint32_t    BKP19R;               // [Read-write] backup register

    static const uint8_t TR_PM = 22;              // AM/PM notation
    static const uint8_t TR_HT = 20;              // Hour tens in BCD format (2 bits)
    static const uint8_t TR_HU = 16;              // Hour units in BCD format (4 bits)
    static const uint8_t TR_MNT = 12;             // Minute tens in BCD format (3 bits)
    static const uint8_t TR_MNU = 8;              // Minute units in BCD format (4 bits)
    static const uint8_t TR_ST = 4;               // Second tens in BCD format (3 bits)
    static const uint8_t TR_SU = 0;               // Second units in BCD format (4 bits)
    static const uint32_t TR_RESET_VALUE = 0x0;

    static const uint8_t DR_YT = 20;              // Year tens in BCD format (4 bits)
    static const uint8_t DR_YU = 16;              // Year units in BCD format (4 bits)
    static const uint8_t DR_WDU = 13;             // Week day units (3 bits)
    static const uint8_t DR_MT = 12;              // Month tens in BCD format
    static const uint8_t DR_MU = 8;               // Month units in BCD format (4 bits)
    static const uint8_t DR_DT = 4;               // Date tens in BCD format (2 bits)
    static const uint8_t DR_DU = 0;               // Date units in BCD format (4 bits)
    static const uint32_t DR_RESET_VALUE = 0x2101;

    static const uint8_t CR_COE = 23;             // Calibration output enable
    static const uint8_t CR_OSEL = 21;            // Output selection (2 bits)
    static const uint8_t CR_POL = 20;             // Output polarity
    static const uint8_t CR_COSEL = 19;           // Calibration Output selection
    static const uint8_t CR_BKP = 18;             // Backup
    static const uint8_t CR_SUB1H = 17;           // Subtract 1 hour (winter time change)
    static const uint8_t CR_ADD1H = 16;           // Add 1 hour (summer time change)
    static const uint8_t CR_TSIE = 15;            // Time-stamp interrupt enable
    static const uint8_t CR_WUTIE = 14;           // Wakeup timer interrupt enable
    static const uint8_t CR_ALRBIE = 13;          // Alarm B interrupt enable
    static const uint8_t CR_ALRAIE = 12;          // Alarm A interrupt enable
    static const uint8_t CR_TSE = 11;             // Time stamp enable
    static const uint8_t CR_WUTE = 10;            // Wakeup timer enable
    static const uint8_t CR_ALRBE = 9;            // Alarm B enable
    static const uint8_t CR_ALRAE = 8;            // Alarm A enable
    static const uint8_t CR_DCE = 7;              // Coarse digital calibration enable
    static const uint8_t CR_FMT = 6;              // Hour format
    static const uint8_t CR_BYPSHAD = 5;          // Bypass the shadow registers
    static const uint8_t CR_REFCKON = 4;          // Reference clock detection enable (50 or 60 Hz)
    static const uint8_t CR_TSEDGE = 3;           // Time-stamp event active edge
    static const uint8_t CR_WCKSEL = 0;           // Wakeup clock selection (3 bits)
    static const uint32_t CR_RESET_VALUE = 0x0;

    static const uint8_t ISR_ALRAWF = 0;           // Alarm A write flag, Read-only
    static const uint8_t ISR_ALRBWF = 1;           // Alarm B write flag, Read-only
    static const uint8_t ISR_WUTWF = 2;            // Wakeup timer write flag, Read-only
    static const uint8_t ISR_SHPF = 3;             // Shift operation pending, Read-write
    static const uint8_t ISR_INITS = 4;            // Initialization status flag, Read-only
    static const uint8_t ISR_RSF = 5;              // Registers synchronization flag, Read-write
    static const uint8_t ISR_INITF = 6;            // Initialization flag, Read-only
    static const uint8_t ISR_INIT = 7;             // Initialization mode, Read-write
    static const uint8_t ISR_ALRAF = 8;            // Alarm A flag, Read-write
    static const uint8_t ISR_ALRBF = 9;            // Alarm B flag, Read-write
    static const uint8_t ISR_WUTF = 10;            // Wakeup timer flag, Read-write
    static const uint8_t ISR_TSF = 11;             // Time-stamp flag, Read-write
    static const uint8_t ISR_TSOVF = 12;           // Time-stamp overflow flag, Read-write
    static const uint8_t ISR_TAMP1F = 13;          // Tamper detection flag, Read-write
    static const uint8_t ISR_TAMP2F = 14;          // TAMPER2 detection flag, Read-write
    static const uint8_t ISR_RECALPF = 16;         // Recalibration pending Flag, Read-only
    static const uint32_t ISR_RESET_VALUE = 0x7;

    static const uint8_t PRER_PREDIV_A = 16;        // Asynchronous prescaler factor (7 bits)
    static const uint8_t PRER_PREDIV_S = 0;         // Synchronous prescaler factor (15 bits)
    static const uint32_t PRER_RESET_VALUE = 0x7f00ff;

    static const uint8_t WUTR_WUT = 0;              // Wakeup auto-reload value bits (16 bits)
    static const uint32_t WUTR_RESET_VALUE = 0xffff;

    static const uint8_t CALIBR_DCS = 7;              // Digital calibration sign
    static const uint8_t CALIBR_DC = 0;               // Digital calibration (5 bits)
    static const uint32_t CALIBR_RESET_VALUE = 0x0;

    static const uint8_t ALRMAR_MSK4 = 31;            // Alarm A date mask
    static const uint8_t ALRMAR_WDSEL = 30;           // Week day selection
    static const uint8_t ALRMAR_DT = 28;              // Date tens in BCD format (2 bits)
    static const uint8_t ALRMAR_DU = 24;              // Date units or day in BCD format (4 bits)
    static const uint8_t ALRMAR_MSK3 = 23;            // Alarm A hours mask
    static const uint8_t ALRMAR_PM = 22;              // AM/PM notation
    static const uint8_t ALRMAR_HT = 20;              // Hour tens in BCD format (2 bits)
    static const uint8_t ALRMAR_HU = 16;              // Hour units in BCD format (4 bits)
    static const uint8_t ALRMAR_MSK2 = 15;            // Alarm A minutes mask
    static const uint8_t ALRMAR_MNT = 12;             // Minute tens in BCD format (3 bits)
    static const uint8_t ALRMAR_MNU = 8;              // Minute units in BCD format (4 bits)
    static const uint8_t ALRMAR_MSK1 = 7;             // Alarm A seconds mask
    static const uint8_t ALRMAR_ST = 4;               // Second tens in BCD format (3 bits)
    static const uint8_t ALRMAR_SU = 0;               // Second units in BCD format (4 bits)
    static const uint32_t ALRMAR_RESET_VALUE = 0x0;

    static const uint8_t ALRMBR_MSK4 = 31;            // Alarm B date mask
    static const uint8_t ALRMBR_WDSEL = 30;           // Week day selection
    static const uint8_t ALRMBR_DT = 28;              // Date tens in BCD format (2 bits)
    static const uint8_t ALRMBR_DU = 24;              // Date units or day in BCD format (4 bits)
    static const uint8_t ALRMBR_MSK3 = 23;            // Alarm B hours mask
    static const uint8_t ALRMBR_PM = 22;              // AM/PM notation
    static const uint8_t ALRMBR_HT = 20;              // Hour tens in BCD format (2 bits)
    static const uint8_t ALRMBR_HU = 16;              // Hour units in BCD format (4 bits)
    static const uint8_t ALRMBR_MSK2 = 15;            // Alarm B minutes mask
    static const uint8_t ALRMBR_MNT = 12;             // Minute tens in BCD format (3 bits)
    static const uint8_t ALRMBR_MNU = 8;              // Minute units in BCD format (4 bits)
    static const uint8_t ALRMBR_MSK1 = 7;             // Alarm B seconds mask
    static const uint8_t ALRMBR_ST = 4;               // Second tens in BCD format (3 bits)
    static const uint8_t ALRMBR_SU = 0;               // Second units in BCD format (4 bits)
    static const uint32_t ALRMBR_RESET_VALUE = 0x0;

    static const uint8_t WPR_KEY = 0;              // Write protection key (8 bits)
    static const uint32_t WPR_RESET_VALUE = 0x0;

    static const uint8_t SSR_SS = 0;               // Sub second value (16 bits)
    static const uint32_t SSR_RESET_VALUE = 0x0;

    static const uint8_t SHIFTR_ADD1S = 31;           // Add one second
    static const uint8_t SHIFTR_SUBFS = 0;            // Subtract a fraction of a second (15 bits)
    static const uint32_t SHIFTR_RESET_VALUE = 0x0;

    static const uint8_t TSTR_PM = 22;              // AM/PM notation
    static const uint8_t TSTR_HT = 20;              // Hour tens in BCD format (2 bits)
    static const uint8_t TSTR_HU = 16;              // Hour units in BCD format (4 bits)
    static const uint8_t TSTR_MNT = 12;             // Minute tens in BCD format (3 bits)
    static const uint8_t TSTR_MNU = 8;              // Minute units in BCD format (4 bits)
    static const uint8_t TSTR_ST = 4;               // Second tens in BCD format (3 bits)
    static const uint8_t TSTR_SU = 0;               // Second units in BCD format (4 bits)
    static const uint32_t TSTR_RESET_VALUE = 0x0;

    static const uint8_t TSDR_WDU = 13;             // Week day units (3 bits)
    static const uint8_t TSDR_MT = 12;              // Month tens in BCD format
    static const uint8_t TSDR_MU = 8;               // Month units in BCD format (4 bits)
    static const uint8_t TSDR_DT = 4;               // Date tens in BCD format (2 bits)
    static const uint8_t TSDR_DU = 0;               // Date units in BCD format (4 bits)
    static const uint32_t TSDR_RESET_VALUE = 0x0;

    static const uint8_t TSSSR_SS = 0;               // Sub second value (16 bits)
    static const uint32_t TSSSR_RESET_VALUE = 0x0;

    static const uint8_t CALR_CALP = 15;            // Increase frequency of RTC by 488.5 ppm
    static const uint8_t CALR_CALW8 = 14;           // Use an 8-second calibration cycle period
    static const uint8_t CALR_CALW16 = 13;          // Use a 16-second calibration cycle period
    static const uint8_t CALR_CALM = 0;             // Calibration minus (9 bits)
    static const uint32_t CALR_RESET_VALUE = 0x0;

    static const uint8_t TAFCR_ALARMOUTTYPE = 18;    // AFO_ALARM output type
    static const uint8_t TAFCR_TSINSEL = 17;         // TIMESTAMP mapping
    static const uint8_t TAFCR_TAMP1INSEL = 16;      // TAMPER1 mapping
    static const uint8_t TAFCR_TAMPPUDIS = 15;       // TAMPER pull-up disable
    static const uint8_t TAFCR_TAMPPRCH = 13;        // Tamper precharge duration (2 bits)
    static const uint8_t TAFCR_TAMPFLT = 11;         // Tamper filter count (2 bits)
    static const uint8_t TAFCR_TAMPFREQ = 8;         // Tamper sampling frequency (3 bits)
    static const uint8_t TAFCR_TAMPTS = 7;           // Activate timestamp on tamper detection event
    static const uint8_t TAFCR_TAMP2TRG = 4;         // Active level for tamper 2
    static const uint8_t TAFCR_TAMP2E = 3;           // Tamper 2 detection enable
    static const uint8_t TAFCR_TAMPIE = 2;           // Tamper interrupt enable
    static const uint8_t TAFCR_TAMP1TRG = 1;         // Active level for tamper 1
    static const uint8_t TAFCR_TAMP1E = 0;           // Tamper 1 detection enable
    static const uint32_t TAFCR_RESET_VALUE = 0x0;

    static const uint8_t ALRMASSR_MASKSS = 24;          // Mask the most-significant bits starting at this bit (4 bits)
    static const uint8_t ALRMASSR_SS = 0;               // Sub seconds value (15 bits)
    static const uint32_t ALRMASSR_RESET_VALUE = 0x0;

    static const uint8_t ALRMBSSR_MASKSS = 24;          // Mask the most-significant bits starting at this bit (4 bits)
    static const uint8_t ALRMBSSR_SS = 0;               // Sub seconds value (15 bits)
    static const uint32_t ALRMBSSR_RESET_VALUE = 0x0;

    static const uint8_t BKP0R_BKP = 0;              // BKP (32 bits)
    static const uint32_t BKP0R_RESET_VALUE = 0x0;

    static const uint8_t BKP1R_BKP = 0;              // BKP (32 bits)
    static const uint32_t BKP1R_RESET_VALUE = 0x0;

    static const uint8_t BKP2R_BKP = 0;              // BKP (32 bits)
    static const uint32_t BKP2R_RESET_VALUE = 0x0;

    static const uint8_t BKP3R_BKP = 0;              // BKP (32 bits)
    static const uint32_t BKP3R_RESET_VALUE = 0x0;

    static const uint8_t BKP4R_BKP = 0;              // BKP (32 bits)
    static const uint32_t BKP4R_RESET_VALUE = 0x0;

    static const uint8_t BKP5R_BKP = 0;              // BKP (32 bits)
    static const uint32_t BKP5R_RESET_VALUE = 0x0;

    static const uint8_t BKP6R_BKP = 0;              // BKP (32 bits)
    static const uint32_t BKP6R_RESET_VALUE = 0x0;

    static const uint8_t BKP7R_BKP = 0;              // BKP (32 bits)
    static const uint32_t BKP7R_RESET_VALUE = 0x0;

    static const uint8_t BKP8R_BKP = 0;              // BKP (32 bits)
    static const uint32_t BKP8R_RESET_VALUE = 0x0;

    static const uint8_t BKP9R_BKP = 0;              // BKP (32 bits)
    static const uint32_t BKP9R_RESET_VALUE = 0x0;

    static const uint8_t BKP10R_BKP = 0;              // BKP (32 bits)
    static const uint32_t BKP10R_RESET_VALUE = 0x0;

    static const uint8_t BKP11R_BKP = 0;              // BKP (32 bits)
    static const uint32_t BKP11R_RESET_VALUE = 0x0;

    static const uint8_t BKP12R_BKP = 0;              // BKP (32 bits)
    static const uint32_t BKP12R_RESET_VALUE = 0x0;

    static const uint8_t BKP13R_BKP = 0;              // BKP (32 bits)
    static const uint32_t BKP13R_RESET_VALUE = 0x0;

    static const uint8_t BKP14R_BKP = 0;              // BKP (32 bits)
    static const uint32_t BKP14R_RESET_VALUE = 0x0;

    static const uint8_t BKP15R_BKP = 0;              // BKP (32 bits)
    static const uint32_t BKP15R_RESET_VALUE = 0x0;

    static const uint8_t BKP16R_BKP = 0;              // BKP (32 bits)
    static const uint32_t BKP16R_RESET_VALUE = 0x0;

    static const uint8_t BKP17R_BKP = 0;              // BKP (32 bits)
    static const uint32_t BKP17R_RESET_VALUE = 0x0;

    static const uint8_t BKP18R_BKP = 0;              // BKP (32 bits)
    static const uint32_t BKP18R_RESET_VALUE = 0x0;

    static const uint8_t BKP19R_BKP = 0;              // BKP (32 bits)
    static const uint32_t BKP19R_RESET_VALUE = 0x0;
};

static rtc_t& RTC = *reinterpret_cast<rtc_t*>(0x40002800);


////
//
//    Secure digital input/output interface
//
////

struct sdio_t
{
    volatile uint32_t    POWER;                // [Read-write] power control register
    volatile uint32_t    CLKCR;                // [Read-write] SDI clock control register
    volatile uint32_t    ARG;                  // [Read-write] argument register
    volatile uint32_t    CMD;                  // [Read-write] command register
    volatile uint32_t    RESPCMD;              // [Read-only] command response register
    volatile uint32_t    RESP1;                // [Read-only] response 1..4 register
    volatile uint32_t    RESP2;                // [Read-only] response 1..4 register
    volatile uint32_t    RESP3;                // [Read-only] response 1..4 register
    volatile uint32_t    RESP4;                // [Read-only] response 1..4 register
    volatile uint32_t    DTIMER;               // [Read-write] data timer register
    volatile uint32_t    DLEN;                 // [Read-write] data length register
    volatile uint32_t    DCTRL;                // [Read-write] data control register
    volatile uint32_t    DCOUNT;               // [Read-only] data counter register
    volatile uint32_t    STA;                  // [Read-only] status register
    volatile uint32_t    ICR;                  // [Read-write] interrupt clear register
    volatile uint32_t    MASK;                 // [Read-write] mask register
    reserved_t<2>        _0;
    volatile uint32_t    FIFOCNT;              // [Read-only] FIFO counter register
    reserved_t<13>       _1;
    volatile uint32_t    FIFO;                 // [Read-write] data FIFO register

    static const uint8_t POWER_PWRCTRL = 0;          // PWRCTRL (2 bits)
    static const uint32_t POWER_RESET_VALUE = 0x0;

    static const uint8_t CLKCR_HWFC_EN = 14;         // HW Flow Control enable
    static const uint8_t CLKCR_NEGEDGE = 13;         // SDIO_CK dephasing selection bit
    static const uint8_t CLKCR_WIDBUS = 11;          // Wide bus mode enable bit (2 bits)
    static const uint8_t CLKCR_BYPASS = 10;          // Clock divider bypass enable bit
    static const uint8_t CLKCR_PWRSAV = 9;           // Power saving configuration bit
    static const uint8_t CLKCR_CLKEN = 8;            // Clock enable bit
    static const uint8_t CLKCR_CLKDIV = 0;           // Clock divide factor (8 bits)
    static const uint32_t CLKCR_RESET_VALUE = 0x0;

    static const uint8_t ARG_CMDARG = 0;           // Command argument (32 bits)
    static const uint32_t ARG_RESET_VALUE = 0x0;

    static const uint8_t CMD_CE_ATACMD = 14;       // CE-ATA command
    static const uint8_t CMD_nIEN = 13;            // not Interrupt Enable
    static const uint8_t CMD_ENCMDcompl = 12;      // Enable CMD completion
    static const uint8_t CMD_SDIOSuspend = 11;     // SD I/O suspend command
    static const uint8_t CMD_CPSMEN = 10;          // Command path state machine (CPSM) Enable bit
    static const uint8_t CMD_WAITPEND = 9;         // CPSM Waits for ends of data transfer (CmdPend internal signal).
    static const uint8_t CMD_WAITINT = 8;          // CPSM waits for interrupt request
    static const uint8_t CMD_WAITRESP = 6;         // Wait for response bits (2 bits)
    static const uint8_t CMD_CMDINDEX = 0;         // Command index (6 bits)
    static const uint32_t CMD_RESET_VALUE = 0x0;

    static const uint8_t RESPCMD_RESPCMD = 0;          // Response command index (6 bits)
    static const uint32_t RESPCMD_RESET_VALUE = 0x0;

    static const uint8_t RESP1_CARDSTATUS1 = 0;      // Card Status (32 bits)
    static const uint32_t RESP1_RESET_VALUE = 0x0;

    static const uint8_t RESP2_CARDSTATUS2 = 0;      // Card Status (32 bits)
    static const uint32_t RESP2_RESET_VALUE = 0x0;

    static const uint8_t RESP3_CARDSTATUS3 = 0;      // Card Status (32 bits)
    static const uint32_t RESP3_RESET_VALUE = 0x0;

    static const uint8_t RESP4_CARDSTATUS4 = 0;      // Card Status (32 bits)
    static const uint32_t RESP4_RESET_VALUE = 0x0;

    static const uint8_t DTIMER_DATATIME = 0;         // Data timeout period (32 bits)
    static const uint32_t DTIMER_RESET_VALUE = 0x0;

    static const uint8_t DLEN_DATALENGTH = 0;       // Data length value (25 bits)
    static const uint32_t DLEN_RESET_VALUE = 0x0;

    static const uint8_t DCTRL_SDIOEN = 11;          // SD I/O enable functions
    static const uint8_t DCTRL_RWMOD = 10;           // Read wait mode
    static const uint8_t DCTRL_RWSTOP = 9;           // Read wait stop
    static const uint8_t DCTRL_RWSTART = 8;          // Read wait start
    static const uint8_t DCTRL_DBLOCKSIZE = 4;       // Data block size (4 bits)
    static const uint8_t DCTRL_DMAEN = 3;            // DMA enable bit
    static const uint8_t DCTRL_DTMODE = 2;           // Data transfer mode selection 1: Stream or SDIO multibyte data transfer.
    static const uint8_t DCTRL_DTDIR = 1;            // Data transfer direction selection
    static const uint8_t DCTRL_DTEN = 0;             // DTEN
    static const uint32_t DCTRL_RESET_VALUE = 0x0;

    static const uint8_t DCOUNT_DATACOUNT = 0;        // Data count value (25 bits)
    static const uint32_t DCOUNT_RESET_VALUE = 0x0;

    static const uint8_t STA_CEATAEND = 23;        // CE-ATA command completion signal received for CMD61
    static const uint8_t STA_SDIOIT = 22;          // SDIO interrupt received
    static const uint8_t STA_RXDAVL = 21;          // Data available in receive FIFO
    static const uint8_t STA_TXDAVL = 20;          // Data available in transmit FIFO
    static const uint8_t STA_RXFIFOE = 19;         // Receive FIFO empty
    static const uint8_t STA_TXFIFOE = 18;         // Transmit FIFO empty
    static const uint8_t STA_RXFIFOF = 17;         // Receive FIFO full
    static const uint8_t STA_TXFIFOF = 16;         // Transmit FIFO full
    static const uint8_t STA_RXFIFOHF = 15;        // Receive FIFO half full: there are at least 8 words in the FIFO
    static const uint8_t STA_TXFIFOHE = 14;        // Transmit FIFO half empty: at least 8 words can be written into the FIFO
    static const uint8_t STA_RXACT = 13;           // Data receive in progress
    static const uint8_t STA_TXACT = 12;           // Data transmit in progress
    static const uint8_t STA_CMDACT = 11;          // Command transfer in progress
    static const uint8_t STA_DBCKEND = 10;         // Data block sent/received (CRC check passed)
    static const uint8_t STA_STBITERR = 9;         // Start bit not detected on all data signals in wide bus mode
    static const uint8_t STA_DATAEND = 8;          // Data end (data counter, SDIDCOUNT, is zero)
    static const uint8_t STA_CMDSENT = 7;          // Command sent (no response required)
    static const uint8_t STA_CMDREND = 6;          // Command response received (CRC check passed)
    static const uint8_t STA_RXOVERR = 5;          // Received FIFO overrun error
    static const uint8_t STA_TXUNDERR = 4;         // Transmit FIFO underrun error
    static const uint8_t STA_DTIMEOUT = 3;         // Data timeout
    static const uint8_t STA_CTIMEOUT = 2;         // Command response timeout
    static const uint8_t STA_DCRCFAIL = 1;         // Data block sent/received (CRC check failed)
    static const uint8_t STA_CCRCFAIL = 0;         // Command response received (CRC check failed)
    static const uint32_t STA_RESET_VALUE = 0x0;

    static const uint8_t ICR_CEATAENDC = 23;       // CEATAEND flag clear bit
    static const uint8_t ICR_SDIOITC = 22;         // SDIOIT flag clear bit
    static const uint8_t ICR_DBCKENDC = 10;        // DBCKEND flag clear bit
    static const uint8_t ICR_STBITERRC = 9;        // STBITERR flag clear bit
    static const uint8_t ICR_DATAENDC = 8;         // DATAEND flag clear bit
    static const uint8_t ICR_CMDSENTC = 7;         // CMDSENT flag clear bit
    static const uint8_t ICR_CMDRENDC = 6;         // CMDREND flag clear bit
    static const uint8_t ICR_RXOVERRC = 5;         // RXOVERR flag clear bit
    static const uint8_t ICR_TXUNDERRC = 4;        // TXUNDERR flag clear bit
    static const uint8_t ICR_DTIMEOUTC = 3;        // DTIMEOUT flag clear bit
    static const uint8_t ICR_CTIMEOUTC = 2;        // CTIMEOUT flag clear bit
    static const uint8_t ICR_DCRCFAILC = 1;        // DCRCFAIL flag clear bit
    static const uint8_t ICR_CCRCFAILC = 0;        // CCRCFAIL flag clear bit
    static const uint32_t ICR_RESET_VALUE = 0x0;

    static const uint8_t MASK_CEATAENDIE = 23;      // CE-ATA command completion signal received interrupt enable
    static const uint8_t MASK_SDIOITIE = 22;        // SDIO mode interrupt received interrupt enable
    static const uint8_t MASK_RXDAVLIE = 21;        // Data available in Rx FIFO interrupt enable
    static const uint8_t MASK_TXDAVLIE = 20;        // Data available in Tx FIFO interrupt enable
    static const uint8_t MASK_RXFIFOEIE = 19;       // Rx FIFO empty interrupt enable
    static const uint8_t MASK_TXFIFOEIE = 18;       // Tx FIFO empty interrupt enable
    static const uint8_t MASK_RXFIFOFIE = 17;       // Rx FIFO full interrupt enable
    static const uint8_t MASK_TXFIFOFIE = 16;       // Tx FIFO full interrupt enable
    static const uint8_t MASK_RXFIFOHFIE = 15;      // Rx FIFO half full interrupt enable
    static const uint8_t MASK_TXFIFOHEIE = 14;      // Tx FIFO half empty interrupt enable
    static const uint8_t MASK_RXACTIE = 13;         // Data receive acting interrupt enable
    static const uint8_t MASK_TXACTIE = 12;         // Data transmit acting interrupt enable
    static const uint8_t MASK_CMDACTIE = 11;        // Command acting interrupt enable
    static const uint8_t MASK_DBCKENDIE = 10;       // Data block end interrupt enable
    static const uint8_t MASK_STBITERRIE = 9;       // Start bit error interrupt enable
    static const uint8_t MASK_DATAENDIE = 8;        // Data end interrupt enable
    static const uint8_t MASK_CMDSENTIE = 7;        // Command sent interrupt enable
    static const uint8_t MASK_CMDRENDIE = 6;        // Command response received interrupt enable
    static const uint8_t MASK_RXOVERRIE = 5;        // Rx FIFO overrun error interrupt enable
    static const uint8_t MASK_TXUNDERRIE = 4;       // Tx FIFO underrun error interrupt enable
    static const uint8_t MASK_DTIMEOUTIE = 3;       // Data timeout interrupt enable
    static const uint8_t MASK_CTIMEOUTIE = 2;       // Command timeout interrupt enable
    static const uint8_t MASK_DCRCFAILIE = 1;       // Data CRC fail interrupt enable
    static const uint8_t MASK_CCRCFAILIE = 0;       // Command CRC fail interrupt enable
    static const uint32_t MASK_RESET_VALUE = 0x0;

    static const uint8_t FIFOCNT_FIFOCOUNT = 0;        // Remaining number of words to be written to or read from the FIFO. (24 bits)
    static const uint32_t FIFOCNT_RESET_VALUE = 0x0;

    static const uint8_t FIFO_FIFOData = 0;         // Receive and transmit FIFO data (32 bits)
    static const uint32_t FIFO_RESET_VALUE = 0x0;
};

static sdio_t& SDIO = *reinterpret_cast<sdio_t*>(0x40012c00);


////
//
//    System configuration controller
//
////

struct syscfg_t
{
    volatile uint32_t    MEMRM;                // [Read-write] memory remap register
    volatile uint32_t    PMC;                  // [Read-write] peripheral mode configuration register
    volatile uint32_t    EXTICR1;              // [Read-write] external interrupt configuration register 1
    volatile uint32_t    EXTICR2;              // [Read-write] external interrupt configuration register 2
    volatile uint32_t    EXTICR3;              // [Read-write] external interrupt configuration register 3
    volatile uint32_t    EXTICR4;              // [Read-write] external interrupt configuration register 4
    reserved_t<2>        _0;
    volatile uint32_t    CMPCR;                // [Read-only] Compensation cell control register
    reserved_t<2>        _1;
    volatile uint32_t    I2C_BUFOUT;           // [Read-write] I2C_BUFOUT

    static const uint8_t MEMRM_MEM_MODE = 0;         // MEM_MODE (2 bits)
    static const uint32_t MEMRM_RESET_VALUE = 0x0;

    static const uint8_t PMC_ADC1DC2 = 16;         // ADC1DC2
    static const uint32_t PMC_RESET_VALUE = 0x0;

    static const uint8_t EXTICR1_EXTI3 = 12;           // EXTI x configuration (x = 0 to 3) (4 bits)
    static const uint8_t EXTICR1_EXTI2 = 8;            // EXTI x configuration (x = 0 to 3) (4 bits)
    static const uint8_t EXTICR1_EXTI1 = 4;            // EXTI x configuration (x = 0 to 3) (4 bits)
    static const uint8_t EXTICR1_EXTI0 = 0;            // EXTI x configuration (x = 0 to 3) (4 bits)
    static const uint32_t EXTICR1_RESET_VALUE = 0x0;

    static const uint8_t EXTICR2_EXTI7 = 12;           // EXTI x configuration (x = 4 to 7) (4 bits)
    static const uint8_t EXTICR2_EXTI6 = 8;            // EXTI x configuration (x = 4 to 7) (4 bits)
    static const uint8_t EXTICR2_EXTI5 = 4;            // EXTI x configuration (x = 4 to 7) (4 bits)
    static const uint8_t EXTICR2_EXTI4 = 0;            // EXTI x configuration (x = 4 to 7) (4 bits)
    static const uint32_t EXTICR2_RESET_VALUE = 0x0;

    static const uint8_t EXTICR3_EXTI11 = 12;          // EXTI x configuration (x = 8 to 11) (4 bits)
    static const uint8_t EXTICR3_EXTI10 = 8;           // EXTI10 (4 bits)
    static const uint8_t EXTICR3_EXTI9 = 4;            // EXTI x configuration (x = 8 to 11) (4 bits)
    static const uint8_t EXTICR3_EXTI8 = 0;            // EXTI x configuration (x = 8 to 11) (4 bits)
    static const uint32_t EXTICR3_RESET_VALUE = 0x0;

    static const uint8_t EXTICR4_EXTI15 = 12;          // EXTI x configuration (x = 12 to 15) (4 bits)
    static const uint8_t EXTICR4_EXTI14 = 8;           // EXTI x configuration (x = 12 to 15) (4 bits)
    static const uint8_t EXTICR4_EXTI13 = 4;           // EXTI x configuration (x = 12 to 15) (4 bits)
    static const uint8_t EXTICR4_EXTI12 = 0;           // EXTI x configuration (x = 12 to 15) (4 bits)
    static const uint32_t EXTICR4_RESET_VALUE = 0x0;

    static const uint8_t CMPCR_READY = 8;            // READY
    static const uint8_t CMPCR_CMP_PD = 0;           // Compensation cell power-down
    static const uint32_t CMPCR_RESET_VALUE = 0x0;

    static const uint8_t I2C_BUFOUT_I2C4SCL = 0;          // I2C4SCL
    static const uint8_t I2C_BUFOUT_I2C4SDA = 1;          // I2C4SDA
    static const uint32_t I2C_BUFOUT_RESET_VALUE = 0x0;
};

static syscfg_t& SYSCFG = *reinterpret_cast<syscfg_t*>(0x40013800);


////
//
//    Advanced-timers
//
////

struct tim1_t
{
    volatile uint32_t    CR1;                  // [Read-write] control register 1
    volatile uint32_t    CR2;                  // [Read-write] control register 2
    volatile uint32_t    SMCR;                 // [Read-write] slave mode control register
    volatile uint32_t    DIER;                 // [Read-write] DMA/Interrupt enable register
    volatile uint32_t    SR;                   // [Read-write] status register
    volatile uint32_t    EGR;                  // [Write-only] event generation register
    volatile uint32_t    CCMR1;                // [Read-write] capture/compare mode register 1 (output mode)
    volatile uint32_t    CCMR2;                // [Read-write] capture/compare mode register 2 (output mode)
    volatile uint32_t    CCER;                 // [Read-write] capture/compare enable register
    volatile uint32_t    CNT;                  // [Read-write] counter
    volatile uint32_t    PSC;                  // [Read-write] prescaler
    volatile uint32_t    ARR;                  // [Read-write] auto-reload register
    volatile uint32_t    RCR;                  // [Read-write] repetition counter register
    volatile uint32_t    CCR1;                 // [Read-write] capture/compare register 1
    volatile uint32_t    CCR2;                 // [Read-write] capture/compare register 2
    volatile uint32_t    CCR3;                 // [Read-write] capture/compare register 3
    volatile uint32_t    CCR4;                 // [Read-write] capture/compare register 4
    volatile uint32_t    BDTR;                 // [Read-write] break and dead-time register
    volatile uint32_t    DCR;                  // [Read-write] DMA control register
    volatile uint32_t    DMAR;                 // [Read-write] DMA address for full transfer

    static const uint8_t CR1_CKD = 8;              // Clock division (2 bits)
    static const uint8_t CR1_ARPE = 7;             // Auto-reload preload enable
    static const uint8_t CR1_CMS = 5;              // Center-aligned mode selection (2 bits)
    static const uint8_t CR1_DIR = 4;              // Direction
    static const uint8_t CR1_OPM = 3;              // One-pulse mode
    static const uint8_t CR1_URS = 2;              // Update request source
    static const uint8_t CR1_UDIS = 1;             // Update disable
    static const uint8_t CR1_CEN = 0;              // Counter enable
    static const uint32_t CR1_RESET_VALUE = 0x0;

    static const uint8_t CR2_OIS4 = 14;            // Output Idle state 4
    static const uint8_t CR2_OIS3N = 13;           // Output Idle state 3
    static const uint8_t CR2_OIS3 = 12;            // Output Idle state 3
    static const uint8_t CR2_OIS2N = 11;           // Output Idle state 2
    static const uint8_t CR2_OIS2 = 10;            // Output Idle state 2
    static const uint8_t CR2_OIS1N = 9;            // Output Idle state 1
    static const uint8_t CR2_OIS1 = 8;             // Output Idle state 1
    static const uint8_t CR2_TI1S = 7;             // TI1 selection
    static const uint8_t CR2_MMS = 4;              // Master mode selection (3 bits)
    static const uint8_t CR2_CCDS = 3;             // Capture/compare DMA selection
    static const uint8_t CR2_CCUS = 2;             // Capture/compare control update selection
    static const uint8_t CR2_CCPC = 0;             // Capture/compare preloaded control
    static const uint32_t CR2_RESET_VALUE = 0x0;

    static const uint8_t SMCR_ETP = 15;             // External trigger polarity
    static const uint8_t SMCR_ECE = 14;             // External clock enable
    static const uint8_t SMCR_ETPS = 12;            // External trigger prescaler (2 bits)
    static const uint8_t SMCR_ETF = 8;              // External trigger filter (4 bits)
    static const uint8_t SMCR_MSM = 7;              // Master/Slave mode
    static const uint8_t SMCR_TS = 4;               // Trigger selection (3 bits)
    static const uint8_t SMCR_SMS = 0;              // Slave mode selection (3 bits)
    static const uint32_t SMCR_RESET_VALUE = 0x0;

    static const uint8_t DIER_TDE = 14;             // Trigger DMA request enable
    static const uint8_t DIER_COMDE = 13;           // COM DMA request enable
    static const uint8_t DIER_CC4DE = 12;           // Capture/Compare 4 DMA request enable
    static const uint8_t DIER_CC3DE = 11;           // Capture/Compare 3 DMA request enable
    static const uint8_t DIER_CC2DE = 10;           // Capture/Compare 2 DMA request enable
    static const uint8_t DIER_CC1DE = 9;            // Capture/Compare 1 DMA request enable
    static const uint8_t DIER_UDE = 8;              // Update DMA request enable
    static const uint8_t DIER_BIE = 7;              // Break interrupt enable
    static const uint8_t DIER_TIE = 6;              // Trigger interrupt enable
    static const uint8_t DIER_COMIE = 5;            // COM interrupt enable
    static const uint8_t DIER_CC4IE = 4;            // Capture/Compare 4 interrupt enable
    static const uint8_t DIER_CC3IE = 3;            // Capture/Compare 3 interrupt enable
    static const uint8_t DIER_CC2IE = 2;            // Capture/Compare 2 interrupt enable
    static const uint8_t DIER_CC1IE = 1;            // Capture/Compare 1 interrupt enable
    static const uint8_t DIER_UIE = 0;              // Update interrupt enable
    static const uint32_t DIER_RESET_VALUE = 0x0;

    static const uint8_t SR_CC4OF = 12;           // Capture/Compare 4 overcapture flag
    static const uint8_t SR_CC3OF = 11;           // Capture/Compare 3 overcapture flag
    static const uint8_t SR_CC2OF = 10;           // Capture/compare 2 overcapture flag
    static const uint8_t SR_CC1OF = 9;            // Capture/Compare 1 overcapture flag
    static const uint8_t SR_BIF = 7;              // Break interrupt flag
    static const uint8_t SR_TIF = 6;              // Trigger interrupt flag
    static const uint8_t SR_COMIF = 5;            // COM interrupt flag
    static const uint8_t SR_CC4IF = 4;            // Capture/Compare 4 interrupt flag
    static const uint8_t SR_CC3IF = 3;            // Capture/Compare 3 interrupt flag
    static const uint8_t SR_CC2IF = 2;            // Capture/Compare 2 interrupt flag
    static const uint8_t SR_CC1IF = 1;            // Capture/compare 1 interrupt flag
    static const uint8_t SR_UIF = 0;              // Update interrupt flag
    static const uint32_t SR_RESET_VALUE = 0x0;

    static const uint8_t EGR_BG = 7;               // Break generation
    static const uint8_t EGR_TG = 6;               // Trigger generation
    static const uint8_t EGR_COMG = 5;             // Capture/Compare control update generation
    static const uint8_t EGR_CC4G = 4;             // Capture/compare 4 generation
    static const uint8_t EGR_CC3G = 3;             // Capture/compare 3 generation
    static const uint8_t EGR_CC2G = 2;             // Capture/compare 2 generation
    static const uint8_t EGR_CC1G = 1;             // Capture/compare 1 generation
    static const uint8_t EGR_UG = 0;               // Update generation
    static const uint32_t EGR_RESET_VALUE = 0x0;

    static const uint8_t CCMR1_CC1S = 0;             // Capture/Compare 1 selection (2 bits)
    static const uint8_t CCMR1_CC2S = 8;             // Capture/Compare 2 selection (2 bits)
    static const uint8_t CCMR1_IC1F = 4;             // Input capture 1 filter (4 bits)
    static const uint8_t CCMR1_IC2F = 12;            // Input capture 2 filter (4 bits)
    static const uint8_t CCMR1_IC2PCS = 10;          // Input capture 2 prescaler (2 bits)
    static const uint8_t CCMR1_ICPCS = 2;            // Input capture 1 prescaler (2 bits)
    static const uint8_t CCMR1_OC1CE = 7;            // Output Compare 1 clear enable
    static const uint8_t CCMR1_OC1FE = 2;            // Output Compare 1 fast enable
    static const uint8_t CCMR1_OC1M = 4;             // Output Compare 1 mode (3 bits)
    static const uint8_t CCMR1_OC1PE = 3;            // Output Compare 1 preload enable
    static const uint8_t CCMR1_OC2CE = 15;           // Output Compare 2 clear enable
    static const uint8_t CCMR1_OC2FE = 10;           // Output Compare 2 fast enable
    static const uint8_t CCMR1_OC2M = 12;            // Output Compare 2 mode (3 bits)
    static const uint8_t CCMR1_OC2PE = 11;           // Output Compare 2 preload enable
    static const uint32_t CCMR1_RESET_VALUE = 0x0;

    static const uint8_t CCMR2_CC3S = 0;             // Capture/Compare 3 selection (2 bits)
    static const uint8_t CCMR2_CC4S = 8;             // Capture/Compare 4 selection (2 bits)
    static const uint8_t CCMR2_IC3F = 4;             // Input capture 3 filter (4 bits)
    static const uint8_t CCMR2_IC3PSC = 2;           // Input capture 3 prescaler (2 bits)
    static const uint8_t CCMR2_IC4F = 12;            // Input capture 4 filter (4 bits)
    static const uint8_t CCMR2_IC4PSC = 10;          // Input capture 4 prescaler (2 bits)
    static const uint8_t CCMR2_OC3CE = 7;            // Output compare 3 clear enable
    static const uint8_t CCMR2_OC3FE = 2;            // Output compare 3 fast enable
    static const uint8_t CCMR2_OC3M = 4;             // Output compare 3 mode (3 bits)
    static const uint8_t CCMR2_OC3PE = 3;            // Output compare 3 preload enable
    static const uint8_t CCMR2_OC4CE = 15;           // Output compare 4 clear enable
    static const uint8_t CCMR2_OC4FE = 10;           // Output compare 4 fast enable
    static const uint8_t CCMR2_OC4M = 12;            // Output compare 4 mode (3 bits)
    static const uint8_t CCMR2_OC4PE = 11;           // Output compare 4 preload enable
    static const uint32_t CCMR2_RESET_VALUE = 0x0;

    static const uint8_t CCER_CC4P = 13;            // Capture/Compare 3 output Polarity
    static const uint8_t CCER_CC4E = 12;            // Capture/Compare 4 output enable
    static const uint8_t CCER_CC3NP = 11;           // Capture/Compare 3 output Polarity
    static const uint8_t CCER_CC3NE = 10;           // Capture/Compare 3 complementary output enable
    static const uint8_t CCER_CC3P = 9;             // Capture/Compare 3 output Polarity
    static const uint8_t CCER_CC3E = 8;             // Capture/Compare 3 output enable
    static const uint8_t CCER_CC2NP = 7;            // Capture/Compare 2 output Polarity
    static const uint8_t CCER_CC2NE = 6;            // Capture/Compare 2 complementary output enable
    static const uint8_t CCER_CC2P = 5;             // Capture/Compare 2 output Polarity
    static const uint8_t CCER_CC2E = 4;             // Capture/Compare 2 output enable
    static const uint8_t CCER_CC1NP = 3;            // Capture/Compare 1 output Polarity
    static const uint8_t CCER_CC1NE = 2;            // Capture/Compare 1 complementary output enable
    static const uint8_t CCER_CC1P = 1;             // Capture/Compare 1 output Polarity
    static const uint8_t CCER_CC1E = 0;             // Capture/Compare 1 output enable
    static const uint32_t CCER_RESET_VALUE = 0x0;

    static const uint8_t CNT_CNT = 0;              // counter value (16 bits)
    static const uint32_t CNT_RESET_VALUE = 0x0;

    static const uint8_t PSC_PSC = 0;              // Prescaler value (16 bits)
    static const uint32_t PSC_RESET_VALUE = 0x0;

    static const uint8_t ARR_ARR = 0;              // Auto-reload value (16 bits)
    static const uint32_t ARR_RESET_VALUE = 0x0;

    static const uint8_t RCR_REP = 0;              // Repetition counter value (8 bits)
    static const uint32_t RCR_RESET_VALUE = 0x0;

    static const uint8_t CCR1_CCR1 = 0;             // Capture/Compare 1 value (16 bits)
    static const uint32_t CCR1_RESET_VALUE = 0x0;

    static const uint8_t CCR2_CCR2 = 0;             // Capture/Compare 2 value (16 bits)
    static const uint32_t CCR2_RESET_VALUE = 0x0;

    static const uint8_t CCR3_CCR3 = 0;             // Capture/Compare value (16 bits)
    static const uint32_t CCR3_RESET_VALUE = 0x0;

    static const uint8_t CCR4_CCR4 = 0;             // Capture/Compare value (16 bits)
    static const uint32_t CCR4_RESET_VALUE = 0x0;

    static const uint8_t BDTR_MOE = 15;             // Main output enable
    static const uint8_t BDTR_AOE = 14;             // Automatic output enable
    static const uint8_t BDTR_BKP = 13;             // Break polarity
    static const uint8_t BDTR_BKE = 12;             // Break enable
    static const uint8_t BDTR_OSSR = 11;            // Off-state selection for Run mode
    static const uint8_t BDTR_OSSI = 10;            // Off-state selection for Idle mode
    static const uint8_t BDTR_LOCK = 8;             // Lock configuration (2 bits)
    static const uint8_t BDTR_DTG = 0;              // Dead-time generator setup (8 bits)
    static const uint32_t BDTR_RESET_VALUE = 0x0;

    static const uint8_t DCR_DBL = 8;              // DMA burst length (5 bits)
    static const uint8_t DCR_DBA = 0;              // DMA base address (5 bits)
    static const uint32_t DCR_RESET_VALUE = 0x0;

    static const uint8_t DMAR_DMAB = 0;             // DMA register for burst accesses (16 bits)
    static const uint32_t DMAR_RESET_VALUE = 0x0;
};

static tim1_t& TIM1 = *reinterpret_cast<tim1_t*>(0x40010000);


////
//
//    Advanced-timers
//
////

struct tim8_t
{
    volatile uint32_t    CR1;                  // [Read-write] control register 1
    volatile uint32_t    CR2;                  // [Read-write] control register 2
    volatile uint32_t    SMCR;                 // [Read-write] slave mode control register
    volatile uint32_t    DIER;                 // [Read-write] DMA/Interrupt enable register
    volatile uint32_t    SR;                   // [Read-write] status register
    volatile uint32_t    EGR;                  // [Write-only] event generation register
    volatile uint32_t    CCMR1;                // [Read-write] capture/compare mode register 1 (output mode)
    volatile uint32_t    CCMR2;                // [Read-write] capture/compare mode register 2 (output mode)
    volatile uint32_t    CCER;                 // [Read-write] capture/compare enable register
    volatile uint32_t    CNT;                  // [Read-write] counter
    volatile uint32_t    PSC;                  // [Read-write] prescaler
    volatile uint32_t    ARR;                  // [Read-write] auto-reload register
    volatile uint32_t    RCR;                  // [Read-write] repetition counter register
    volatile uint32_t    CCR1;                 // [Read-write] capture/compare register 1
    volatile uint32_t    CCR2;                 // [Read-write] capture/compare register 2
    volatile uint32_t    CCR3;                 // [Read-write] capture/compare register 3
    volatile uint32_t    CCR4;                 // [Read-write] capture/compare register 4
    volatile uint32_t    BDTR;                 // [Read-write] break and dead-time register
    volatile uint32_t    DCR;                  // [Read-write] DMA control register
    volatile uint32_t    DMAR;                 // [Read-write] DMA address for full transfer

    static const uint8_t CR1_CKD = 8;              // Clock division (2 bits)
    static const uint8_t CR1_ARPE = 7;             // Auto-reload preload enable
    static const uint8_t CR1_CMS = 5;              // Center-aligned mode selection (2 bits)
    static const uint8_t CR1_DIR = 4;              // Direction
    static const uint8_t CR1_OPM = 3;              // One-pulse mode
    static const uint8_t CR1_URS = 2;              // Update request source
    static const uint8_t CR1_UDIS = 1;             // Update disable
    static const uint8_t CR1_CEN = 0;              // Counter enable
    static const uint32_t CR1_RESET_VALUE = 0x0;

    static const uint8_t CR2_OIS4 = 14;            // Output Idle state 4
    static const uint8_t CR2_OIS3N = 13;           // Output Idle state 3
    static const uint8_t CR2_OIS3 = 12;            // Output Idle state 3
    static const uint8_t CR2_OIS2N = 11;           // Output Idle state 2
    static const uint8_t CR2_OIS2 = 10;            // Output Idle state 2
    static const uint8_t CR2_OIS1N = 9;            // Output Idle state 1
    static const uint8_t CR2_OIS1 = 8;             // Output Idle state 1
    static const uint8_t CR2_TI1S = 7;             // TI1 selection
    static const uint8_t CR2_MMS = 4;              // Master mode selection (3 bits)
    static const uint8_t CR2_CCDS = 3;             // Capture/compare DMA selection
    static const uint8_t CR2_CCUS = 2;             // Capture/compare control update selection
    static const uint8_t CR2_CCPC = 0;             // Capture/compare preloaded control
    static const uint32_t CR2_RESET_VALUE = 0x0;

    static const uint8_t SMCR_ETP = 15;             // External trigger polarity
    static const uint8_t SMCR_ECE = 14;             // External clock enable
    static const uint8_t SMCR_ETPS = 12;            // External trigger prescaler (2 bits)
    static const uint8_t SMCR_ETF = 8;              // External trigger filter (4 bits)
    static const uint8_t SMCR_MSM = 7;              // Master/Slave mode
    static const uint8_t SMCR_TS = 4;               // Trigger selection (3 bits)
    static const uint8_t SMCR_SMS = 0;              // Slave mode selection (3 bits)
    static const uint32_t SMCR_RESET_VALUE = 0x0;

    static const uint8_t DIER_TDE = 14;             // Trigger DMA request enable
    static const uint8_t DIER_COMDE = 13;           // COM DMA request enable
    static const uint8_t DIER_CC4DE = 12;           // Capture/Compare 4 DMA request enable
    static const uint8_t DIER_CC3DE = 11;           // Capture/Compare 3 DMA request enable
    static const uint8_t DIER_CC2DE = 10;           // Capture/Compare 2 DMA request enable
    static const uint8_t DIER_CC1DE = 9;            // Capture/Compare 1 DMA request enable
    static const uint8_t DIER_UDE = 8;              // Update DMA request enable
    static const uint8_t DIER_BIE = 7;              // Break interrupt enable
    static const uint8_t DIER_TIE = 6;              // Trigger interrupt enable
    static const uint8_t DIER_COMIE = 5;            // COM interrupt enable
    static const uint8_t DIER_CC4IE = 4;            // Capture/Compare 4 interrupt enable
    static const uint8_t DIER_CC3IE = 3;            // Capture/Compare 3 interrupt enable
    static const uint8_t DIER_CC2IE = 2;            // Capture/Compare 2 interrupt enable
    static const uint8_t DIER_CC1IE = 1;            // Capture/Compare 1 interrupt enable
    static const uint8_t DIER_UIE = 0;              // Update interrupt enable
    static const uint32_t DIER_RESET_VALUE = 0x0;

    static const uint8_t SR_CC4OF = 12;           // Capture/Compare 4 overcapture flag
    static const uint8_t SR_CC3OF = 11;           // Capture/Compare 3 overcapture flag
    static const uint8_t SR_CC2OF = 10;           // Capture/compare 2 overcapture flag
    static const uint8_t SR_CC1OF = 9;            // Capture/Compare 1 overcapture flag
    static const uint8_t SR_BIF = 7;              // Break interrupt flag
    static const uint8_t SR_TIF = 6;              // Trigger interrupt flag
    static const uint8_t SR_COMIF = 5;            // COM interrupt flag
    static const uint8_t SR_CC4IF = 4;            // Capture/Compare 4 interrupt flag
    static const uint8_t SR_CC3IF = 3;            // Capture/Compare 3 interrupt flag
    static const uint8_t SR_CC2IF = 2;            // Capture/Compare 2 interrupt flag
    static const uint8_t SR_CC1IF = 1;            // Capture/compare 1 interrupt flag
    static const uint8_t SR_UIF = 0;              // Update interrupt flag
    static const uint32_t SR_RESET_VALUE = 0x0;

    static const uint8_t EGR_BG = 7;               // Break generation
    static const uint8_t EGR_TG = 6;               // Trigger generation
    static const uint8_t EGR_COMG = 5;             // Capture/Compare control update generation
    static const uint8_t EGR_CC4G = 4;             // Capture/compare 4 generation
    static const uint8_t EGR_CC3G = 3;             // Capture/compare 3 generation
    static const uint8_t EGR_CC2G = 2;             // Capture/compare 2 generation
    static const uint8_t EGR_CC1G = 1;             // Capture/compare 1 generation
    static const uint8_t EGR_UG = 0;               // Update generation
    static const uint32_t EGR_RESET_VALUE = 0x0;

    static const uint8_t CCMR1_CC1S = 0;             // Capture/Compare 1 selection (2 bits)
    static const uint8_t CCMR1_CC2S = 8;             // Capture/Compare 2 selection (2 bits)
    static const uint8_t CCMR1_IC1F = 4;             // Input capture 1 filter (4 bits)
    static const uint8_t CCMR1_IC2F = 12;            // Input capture 2 filter (4 bits)
    static const uint8_t CCMR1_IC2PCS = 10;          // Input capture 2 prescaler (2 bits)
    static const uint8_t CCMR1_ICPCS = 2;            // Input capture 1 prescaler (2 bits)
    static const uint8_t CCMR1_OC1CE = 7;            // Output Compare 1 clear enable
    static const uint8_t CCMR1_OC1FE = 2;            // Output Compare 1 fast enable
    static const uint8_t CCMR1_OC1M = 4;             // Output Compare 1 mode (3 bits)
    static const uint8_t CCMR1_OC1PE = 3;            // Output Compare 1 preload enable
    static const uint8_t CCMR1_OC2CE = 15;           // Output Compare 2 clear enable
    static const uint8_t CCMR1_OC2FE = 10;           // Output Compare 2 fast enable
    static const uint8_t CCMR1_OC2M = 12;            // Output Compare 2 mode (3 bits)
    static const uint8_t CCMR1_OC2PE = 11;           // Output Compare 2 preload enable
    static const uint32_t CCMR1_RESET_VALUE = 0x0;

    static const uint8_t CCMR2_CC3S = 0;             // Capture/Compare 3 selection (2 bits)
    static const uint8_t CCMR2_CC4S = 8;             // Capture/Compare 4 selection (2 bits)
    static const uint8_t CCMR2_IC3F = 4;             // Input capture 3 filter (4 bits)
    static const uint8_t CCMR2_IC3PSC = 2;           // Input capture 3 prescaler (2 bits)
    static const uint8_t CCMR2_IC4F = 12;            // Input capture 4 filter (4 bits)
    static const uint8_t CCMR2_IC4PSC = 10;          // Input capture 4 prescaler (2 bits)
    static const uint8_t CCMR2_OC3CE = 7;            // Output compare 3 clear enable
    static const uint8_t CCMR2_OC3FE = 2;            // Output compare 3 fast enable
    static const uint8_t CCMR2_OC3M = 4;             // Output compare 3 mode (3 bits)
    static const uint8_t CCMR2_OC3PE = 3;            // Output compare 3 preload enable
    static const uint8_t CCMR2_OC4CE = 15;           // Output compare 4 clear enable
    static const uint8_t CCMR2_OC4FE = 10;           // Output compare 4 fast enable
    static const uint8_t CCMR2_OC4M = 12;            // Output compare 4 mode (3 bits)
    static const uint8_t CCMR2_OC4PE = 11;           // Output compare 4 preload enable
    static const uint32_t CCMR2_RESET_VALUE = 0x0;

    static const uint8_t CCER_CC4P = 13;            // Capture/Compare 3 output Polarity
    static const uint8_t CCER_CC4E = 12;            // Capture/Compare 4 output enable
    static const uint8_t CCER_CC3NP = 11;           // Capture/Compare 3 output Polarity
    static const uint8_t CCER_CC3NE = 10;           // Capture/Compare 3 complementary output enable
    static const uint8_t CCER_CC3P = 9;             // Capture/Compare 3 output Polarity
    static const uint8_t CCER_CC3E = 8;             // Capture/Compare 3 output enable
    static const uint8_t CCER_CC2NP = 7;            // Capture/Compare 2 output Polarity
    static const uint8_t CCER_CC2NE = 6;            // Capture/Compare 2 complementary output enable
    static const uint8_t CCER_CC2P = 5;             // Capture/Compare 2 output Polarity
    static const uint8_t CCER_CC2E = 4;             // Capture/Compare 2 output enable
    static const uint8_t CCER_CC1NP = 3;            // Capture/Compare 1 output Polarity
    static const uint8_t CCER_CC1NE = 2;            // Capture/Compare 1 complementary output enable
    static const uint8_t CCER_CC1P = 1;             // Capture/Compare 1 output Polarity
    static const uint8_t CCER_CC1E = 0;             // Capture/Compare 1 output enable
    static const uint32_t CCER_RESET_VALUE = 0x0;

    static const uint8_t CNT_CNT = 0;              // counter value (16 bits)
    static const uint32_t CNT_RESET_VALUE = 0x0;

    static const uint8_t PSC_PSC = 0;              // Prescaler value (16 bits)
    static const uint32_t PSC_RESET_VALUE = 0x0;

    static const uint8_t ARR_ARR = 0;              // Auto-reload value (16 bits)
    static const uint32_t ARR_RESET_VALUE = 0x0;

    static const uint8_t RCR_REP = 0;              // Repetition counter value (8 bits)
    static const uint32_t RCR_RESET_VALUE = 0x0;

    static const uint8_t CCR1_CCR1 = 0;             // Capture/Compare 1 value (16 bits)
    static const uint32_t CCR1_RESET_VALUE = 0x0;

    static const uint8_t CCR2_CCR2 = 0;             // Capture/Compare 2 value (16 bits)
    static const uint32_t CCR2_RESET_VALUE = 0x0;

    static const uint8_t CCR3_CCR3 = 0;             // Capture/Compare value (16 bits)
    static const uint32_t CCR3_RESET_VALUE = 0x0;

    static const uint8_t CCR4_CCR4 = 0;             // Capture/Compare value (16 bits)
    static const uint32_t CCR4_RESET_VALUE = 0x0;

    static const uint8_t BDTR_MOE = 15;             // Main output enable
    static const uint8_t BDTR_AOE = 14;             // Automatic output enable
    static const uint8_t BDTR_BKP = 13;             // Break polarity
    static const uint8_t BDTR_BKE = 12;             // Break enable
    static const uint8_t BDTR_OSSR = 11;            // Off-state selection for Run mode
    static const uint8_t BDTR_OSSI = 10;            // Off-state selection for Idle mode
    static const uint8_t BDTR_LOCK = 8;             // Lock configuration (2 bits)
    static const uint8_t BDTR_DTG = 0;              // Dead-time generator setup (8 bits)
    static const uint32_t BDTR_RESET_VALUE = 0x0;

    static const uint8_t DCR_DBL = 8;              // DMA burst length (5 bits)
    static const uint8_t DCR_DBA = 0;              // DMA base address (5 bits)
    static const uint32_t DCR_RESET_VALUE = 0x0;

    static const uint8_t DMAR_DMAB = 0;             // DMA register for burst accesses (16 bits)
    static const uint32_t DMAR_RESET_VALUE = 0x0;
};

static tim8_t& TIM8 = *reinterpret_cast<tim8_t*>(0x40010400);


////
//
//    General-purpose-timers
//
////

struct tim10_t
{
    volatile uint32_t    CR1;                  // [Read-write] control register 1
    reserved_t<2>        _0;
    volatile uint32_t    DIER;                 // [Read-write] DMA/Interrupt enable register
    volatile uint32_t    SR;                   // [Read-write] status register
    volatile uint32_t    EGR;                  // [Write-only] event generation register
    volatile uint32_t    CCMR1;                // [Read-write] capture/compare mode register 1 (output mode)
    reserved_t<1>        _1;
    volatile uint32_t    CCER;                 // [Read-write] capture/compare enable register
    volatile uint32_t    CNT;                  // [Read-write] counter
    volatile uint32_t    PSC;                  // [Read-write] prescaler
    volatile uint32_t    ARR;                  // [Read-write] auto-reload register
    reserved_t<1>        _2;
    volatile uint32_t    CCR1;                 // [Read-write] capture/compare register 1

    static const uint8_t CR1_CKD = 8;              // Clock division (2 bits)
    static const uint8_t CR1_ARPE = 7;             // Auto-reload preload enable
    static const uint8_t CR1_URS = 2;              // Update request source
    static const uint8_t CR1_UDIS = 1;             // Update disable
    static const uint8_t CR1_CEN = 0;              // Counter enable
    static const uint32_t CR1_RESET_VALUE = 0x0;

    static const uint8_t DIER_CC1IE = 1;            // Capture/Compare 1 interrupt enable
    static const uint8_t DIER_UIE = 0;              // Update interrupt enable
    static const uint32_t DIER_RESET_VALUE = 0x0;

    static const uint8_t SR_CC1OF = 9;            // Capture/Compare 1 overcapture flag
    static const uint8_t SR_CC1IF = 1;            // Capture/compare 1 interrupt flag
    static const uint8_t SR_UIF = 0;              // Update interrupt flag
    static const uint32_t SR_RESET_VALUE = 0x0;

    static const uint8_t EGR_CC1G = 1;             // Capture/compare 1 generation
    static const uint8_t EGR_UG = 0;               // Update generation
    static const uint32_t EGR_RESET_VALUE = 0x0;

    static const uint8_t CCMR1_CC1S = 0;             // Capture/Compare 1 selection (2 bits)
    static const uint8_t CCMR1_IC1F = 4;             // Input capture 1 filter (4 bits)
    static const uint8_t CCMR1_ICPCS = 2;            // Input capture 1 prescaler (2 bits)
    static const uint8_t CCMR1_OC1FE = 2;            // Output Compare 1 fast enable
    static const uint8_t CCMR1_OC1M = 4;             // Output Compare 1 mode (3 bits)
    static const uint8_t CCMR1_OC1PE = 3;            // Output Compare 1 preload enable
    static const uint32_t CCMR1_RESET_VALUE = 0x0;

    static const uint8_t CCER_CC1NP = 3;            // Capture/Compare 1 output Polarity
    static const uint8_t CCER_CC1P = 1;             // Capture/Compare 1 output Polarity
    static const uint8_t CCER_CC1E = 0;             // Capture/Compare 1 output enable
    static const uint32_t CCER_RESET_VALUE = 0x0;

    static const uint8_t CNT_CNT = 0;              // counter value (16 bits)
    static const uint32_t CNT_RESET_VALUE = 0x0;

    static const uint8_t PSC_PSC = 0;              // Prescaler value (16 bits)
    static const uint32_t PSC_RESET_VALUE = 0x0;

    static const uint8_t ARR_ARR = 0;              // Auto-reload value (16 bits)
    static const uint32_t ARR_RESET_VALUE = 0x0;

    static const uint8_t CCR1_CCR1 = 0;             // Capture/Compare 1 value (16 bits)
    static const uint32_t CCR1_RESET_VALUE = 0x0;
};

static tim10_t& TIM10 = *reinterpret_cast<tim10_t*>(0x40014400);


////
//
//    General-purpose-timers
//
////

struct tim11_t
{
    volatile uint32_t    CR1;                  // [Read-write] control register 1
    reserved_t<2>        _0;
    volatile uint32_t    DIER;                 // [Read-write] DMA/Interrupt enable register
    volatile uint32_t    SR;                   // [Read-write] status register
    volatile uint32_t    EGR;                  // [Write-only] event generation register
    volatile uint32_t    CCMR1;                // [Read-write] capture/compare mode register 1 (output mode)
    reserved_t<1>        _1;
    volatile uint32_t    CCER;                 // [Read-write] capture/compare enable register
    volatile uint32_t    CNT;                  // [Read-write] counter
    volatile uint32_t    PSC;                  // [Read-write] prescaler
    volatile uint32_t    ARR;                  // [Read-write] auto-reload register
    reserved_t<1>        _2;
    volatile uint32_t    CCR1;                 // [Read-write] capture/compare register 1
    reserved_t<6>        _3;
    volatile uint32_t    OR;                   // [Read-write] option register

    static const uint8_t CR1_CKD = 8;              // Clock division (2 bits)
    static const uint8_t CR1_ARPE = 7;             // Auto-reload preload enable
    static const uint8_t CR1_URS = 2;              // Update request source
    static const uint8_t CR1_UDIS = 1;             // Update disable
    static const uint8_t CR1_CEN = 0;              // Counter enable
    static const uint32_t CR1_RESET_VALUE = 0x0;

    static const uint8_t DIER_CC1IE = 1;            // Capture/Compare 1 interrupt enable
    static const uint8_t DIER_UIE = 0;              // Update interrupt enable
    static const uint32_t DIER_RESET_VALUE = 0x0;

    static const uint8_t SR_CC1OF = 9;            // Capture/Compare 1 overcapture flag
    static const uint8_t SR_CC1IF = 1;            // Capture/compare 1 interrupt flag
    static const uint8_t SR_UIF = 0;              // Update interrupt flag
    static const uint32_t SR_RESET_VALUE = 0x0;

    static const uint8_t EGR_CC1G = 1;             // Capture/compare 1 generation
    static const uint8_t EGR_UG = 0;               // Update generation
    static const uint32_t EGR_RESET_VALUE = 0x0;

    static const uint8_t CCMR1_CC1S = 0;             // Capture/Compare 1 selection (2 bits)
    static const uint8_t CCMR1_IC1F = 4;             // Input capture 1 filter (4 bits)
    static const uint8_t CCMR1_ICPCS = 2;            // Input capture 1 prescaler (2 bits)
    static const uint8_t CCMR1_OC1FE = 2;            // Output Compare 1 fast enable
    static const uint8_t CCMR1_OC1M = 4;             // Output Compare 1 mode (3 bits)
    static const uint8_t CCMR1_OC1PE = 3;            // Output Compare 1 preload enable
    static const uint32_t CCMR1_RESET_VALUE = 0x0;

    static const uint8_t CCER_CC1NP = 3;            // Capture/Compare 1 output Polarity
    static const uint8_t CCER_CC1P = 1;             // Capture/Compare 1 output Polarity
    static const uint8_t CCER_CC1E = 0;             // Capture/Compare 1 output enable
    static const uint32_t CCER_RESET_VALUE = 0x0;

    static const uint8_t CNT_CNT = 0;              // counter value (16 bits)
    static const uint32_t CNT_RESET_VALUE = 0x0;

    static const uint8_t PSC_PSC = 0;              // Prescaler value (16 bits)
    static const uint32_t PSC_RESET_VALUE = 0x0;

    static const uint8_t ARR_ARR = 0;              // Auto-reload value (16 bits)
    static const uint32_t ARR_RESET_VALUE = 0x0;

    static const uint8_t CCR1_CCR1 = 0;             // Capture/Compare 1 value (16 bits)
    static const uint32_t CCR1_RESET_VALUE = 0x0;

    static const uint8_t OR_RMP = 0;              // Input 1 remapping capability (2 bits)
    static const uint32_t OR_RESET_VALUE = 0x0;
};

static tim11_t& TIM11 = *reinterpret_cast<tim11_t*>(0x40014800);


////
//
//    General purpose timers
//
////

struct tim2_t
{
    volatile uint32_t    CR1;                  // [Read-write] control register 1
    volatile uint32_t    CR2;                  // [Read-write] control register 2
    volatile uint32_t    SMCR;                 // [Read-write] slave mode control register
    volatile uint32_t    DIER;                 // [Read-write] DMA/Interrupt enable register
    volatile uint32_t    SR;                   // [Read-write] status register
    volatile uint32_t    EGR;                  // [Write-only] event generation register
    volatile uint32_t    CCMR1;                // [Read-write] capture/compare mode register 1 (output mode)
    volatile uint32_t    CCMR2;                // [Read-write] capture/compare mode register 2 (output mode)
    volatile uint32_t    CCER;                 // [Read-write] capture/compare enable register
    volatile uint32_t    CNT;                  // [Read-write] counter
    volatile uint32_t    PSC;                  // [Read-write] prescaler
    volatile uint32_t    ARR;                  // [Read-write] auto-reload register
    reserved_t<1>        _0;
    volatile uint32_t    CCR1;                 // [Read-write] capture/compare register 1
    volatile uint32_t    CCR2;                 // [Read-write] capture/compare register 2
    volatile uint32_t    CCR3;                 // [Read-write] capture/compare register 3
    volatile uint32_t    CCR4;                 // [Read-write] capture/compare register 4
    reserved_t<1>        _1;
    volatile uint32_t    DCR;                  // [Read-write] DMA control register
    volatile uint32_t    DMAR;                 // [Read-write] DMA address for full transfer
    volatile uint32_t    OR;                   // [Read-write] TIM5 option register

    static const uint8_t CR1_CKD = 8;              // Clock division (2 bits)
    static const uint8_t CR1_ARPE = 7;             // Auto-reload preload enable
    static const uint8_t CR1_CMS = 5;              // Center-aligned mode selection (2 bits)
    static const uint8_t CR1_DIR = 4;              // Direction
    static const uint8_t CR1_OPM = 3;              // One-pulse mode
    static const uint8_t CR1_URS = 2;              // Update request source
    static const uint8_t CR1_UDIS = 1;             // Update disable
    static const uint8_t CR1_CEN = 0;              // Counter enable
    static const uint32_t CR1_RESET_VALUE = 0x0;

    static const uint8_t CR2_TI1S = 7;             // TI1 selection
    static const uint8_t CR2_MMS = 4;              // Master mode selection (3 bits)
    static const uint8_t CR2_CCDS = 3;             // Capture/compare DMA selection
    static const uint32_t CR2_RESET_VALUE = 0x0;

    static const uint8_t SMCR_ETP = 15;             // External trigger polarity
    static const uint8_t SMCR_ECE = 14;             // External clock enable
    static const uint8_t SMCR_ETPS = 12;            // External trigger prescaler (2 bits)
    static const uint8_t SMCR_ETF = 8;              // External trigger filter (4 bits)
    static const uint8_t SMCR_MSM = 7;              // Master/Slave mode
    static const uint8_t SMCR_TS = 4;               // Trigger selection (3 bits)
    static const uint8_t SMCR_SMS = 0;              // Slave mode selection (3 bits)
    static const uint32_t SMCR_RESET_VALUE = 0x0;

    static const uint8_t DIER_TDE = 14;             // Trigger DMA request enable
    static const uint8_t DIER_CC4DE = 12;           // Capture/Compare 4 DMA request enable
    static const uint8_t DIER_CC3DE = 11;           // Capture/Compare 3 DMA request enable
    static const uint8_t DIER_CC2DE = 10;           // Capture/Compare 2 DMA request enable
    static const uint8_t DIER_CC1DE = 9;            // Capture/Compare 1 DMA request enable
    static const uint8_t DIER_UDE = 8;              // Update DMA request enable
    static const uint8_t DIER_TIE = 6;              // Trigger interrupt enable
    static const uint8_t DIER_CC4IE = 4;            // Capture/Compare 4 interrupt enable
    static const uint8_t DIER_CC3IE = 3;            // Capture/Compare 3 interrupt enable
    static const uint8_t DIER_CC2IE = 2;            // Capture/Compare 2 interrupt enable
    static const uint8_t DIER_CC1IE = 1;            // Capture/Compare 1 interrupt enable
    static const uint8_t DIER_UIE = 0;              // Update interrupt enable
    static const uint32_t DIER_RESET_VALUE = 0x0;

    static const uint8_t SR_CC4OF = 12;           // Capture/Compare 4 overcapture flag
    static const uint8_t SR_CC3OF = 11;           // Capture/Compare 3 overcapture flag
    static const uint8_t SR_CC2OF = 10;           // Capture/compare 2 overcapture flag
    static const uint8_t SR_CC1OF = 9;            // Capture/Compare 1 overcapture flag
    static const uint8_t SR_TIF = 6;              // Trigger interrupt flag
    static const uint8_t SR_CC4IF = 4;            // Capture/Compare 4 interrupt flag
    static const uint8_t SR_CC3IF = 3;            // Capture/Compare 3 interrupt flag
    static const uint8_t SR_CC2IF = 2;            // Capture/Compare 2 interrupt flag
    static const uint8_t SR_CC1IF = 1;            // Capture/compare 1 interrupt flag
    static const uint8_t SR_UIF = 0;              // Update interrupt flag
    static const uint32_t SR_RESET_VALUE = 0x0;

    static const uint8_t EGR_TG = 6;               // Trigger generation
    static const uint8_t EGR_CC4G = 4;             // Capture/compare 4 generation
    static const uint8_t EGR_CC3G = 3;             // Capture/compare 3 generation
    static const uint8_t EGR_CC2G = 2;             // Capture/compare 2 generation
    static const uint8_t EGR_CC1G = 1;             // Capture/compare 1 generation
    static const uint8_t EGR_UG = 0;               // Update generation
    static const uint32_t EGR_RESET_VALUE = 0x0;

    static const uint8_t CCMR1_CC1S = 0;             // CC1S (2 bits)
    static const uint8_t CCMR1_CC2S = 8;             // CC2S (2 bits)
    static const uint8_t CCMR1_IC1F = 4;             // Input capture 1 filter (4 bits)
    static const uint8_t CCMR1_IC2F = 12;            // Input capture 2 filter (4 bits)
    static const uint8_t CCMR1_IC2PCS = 10;          // Input capture 2 prescaler (2 bits)
    static const uint8_t CCMR1_ICPCS = 2;            // Input capture 1 prescaler (2 bits)
    static const uint8_t CCMR1_OC1CE = 7;            // OC1CE
    static const uint8_t CCMR1_OC1FE = 2;            // OC1FE
    static const uint8_t CCMR1_OC1M = 4;             // OC1M (3 bits)
    static const uint8_t CCMR1_OC1PE = 3;            // OC1PE
    static const uint8_t CCMR1_OC2CE = 15;           // OC2CE
    static const uint8_t CCMR1_OC2FE = 10;           // OC2FE
    static const uint8_t CCMR1_OC2M = 12;            // OC2M (3 bits)
    static const uint8_t CCMR1_OC2PE = 11;           // OC2PE
    static const uint32_t CCMR1_RESET_VALUE = 0x0;

    static const uint8_t CCMR2_CC3S = 0;             // CC3S (2 bits)
    static const uint8_t CCMR2_CC4S = 8;             // CC4S (2 bits)
    static const uint8_t CCMR2_IC3F = 4;             // Input capture 3 filter (4 bits)
    static const uint8_t CCMR2_IC3PSC = 2;           // Input capture 3 prescaler (2 bits)
    static const uint8_t CCMR2_IC4F = 12;            // Input capture 4 filter (4 bits)
    static const uint8_t CCMR2_IC4PSC = 10;          // Input capture 4 prescaler (2 bits)
    static const uint8_t CCMR2_O24CE = 15;           // O24CE
    static const uint8_t CCMR2_OC3CE = 7;            // OC3CE
    static const uint8_t CCMR2_OC3FE = 2;            // OC3FE
    static const uint8_t CCMR2_OC3M = 4;             // OC3M (3 bits)
    static const uint8_t CCMR2_OC3PE = 3;            // OC3PE
    static const uint8_t CCMR2_OC4FE = 10;           // OC4FE
    static const uint8_t CCMR2_OC4M = 12;            // OC4M (3 bits)
    static const uint8_t CCMR2_OC4PE = 11;           // OC4PE
    static const uint32_t CCMR2_RESET_VALUE = 0x0;

    static const uint8_t CCER_CC4NP = 15;           // Capture/Compare 4 output Polarity
    static const uint8_t CCER_CC4P = 13;            // Capture/Compare 3 output Polarity
    static const uint8_t CCER_CC4E = 12;            // Capture/Compare 4 output enable
    static const uint8_t CCER_CC3NP = 11;           // Capture/Compare 3 output Polarity
    static const uint8_t CCER_CC3P = 9;             // Capture/Compare 3 output Polarity
    static const uint8_t CCER_CC3E = 8;             // Capture/Compare 3 output enable
    static const uint8_t CCER_CC2NP = 7;            // Capture/Compare 2 output Polarity
    static const uint8_t CCER_CC2P = 5;             // Capture/Compare 2 output Polarity
    static const uint8_t CCER_CC2E = 4;             // Capture/Compare 2 output enable
    static const uint8_t CCER_CC1NP = 3;            // Capture/Compare 1 output Polarity
    static const uint8_t CCER_CC1P = 1;             // Capture/Compare 1 output Polarity
    static const uint8_t CCER_CC1E = 0;             // Capture/Compare 1 output enable
    static const uint32_t CCER_RESET_VALUE = 0x0;

    static const uint8_t CNT_CNT_H = 16;           // High counter value (16 bits)
    static const uint8_t CNT_CNT_L = 0;            // Low counter value (16 bits)
    static const uint32_t CNT_RESET_VALUE = 0x0;

    static const uint8_t PSC_PSC = 0;              // Prescaler value (16 bits)
    static const uint32_t PSC_RESET_VALUE = 0x0;

    static const uint8_t ARR_ARR_H = 16;           // High Auto-reload value (16 bits)
    static const uint8_t ARR_ARR_L = 0;            // Low Auto-reload value (16 bits)
    static const uint32_t ARR_RESET_VALUE = 0x0;

    static const uint8_t CCR1_CCR1_H = 16;          // High Capture/Compare 1 value (16 bits)
    static const uint8_t CCR1_CCR1_L = 0;           // Low Capture/Compare 1 value (16 bits)
    static const uint32_t CCR1_RESET_VALUE = 0x0;

    static const uint8_t CCR2_CCR2_H = 16;          // High Capture/Compare 2 value (16 bits)
    static const uint8_t CCR2_CCR2_L = 0;           // Low Capture/Compare 2 value (16 bits)
    static const uint32_t CCR2_RESET_VALUE = 0x0;

    static const uint8_t CCR3_CCR3_H = 16;          // High Capture/Compare value (16 bits)
    static const uint8_t CCR3_CCR3_L = 0;           // Low Capture/Compare value (16 bits)
    static const uint32_t CCR3_RESET_VALUE = 0x0;

    static const uint8_t CCR4_CCR4_H = 16;          // High Capture/Compare value (16 bits)
    static const uint8_t CCR4_CCR4_L = 0;           // Low Capture/Compare value (16 bits)
    static const uint32_t CCR4_RESET_VALUE = 0x0;

    static const uint8_t DCR_DBL = 8;              // DMA burst length (5 bits)
    static const uint8_t DCR_DBA = 0;              // DMA base address (5 bits)
    static const uint32_t DCR_RESET_VALUE = 0x0;

    static const uint8_t DMAR_DMAB = 0;             // DMA register for burst accesses (16 bits)
    static const uint32_t DMAR_RESET_VALUE = 0x0;

    static const uint8_t OR_ITR1_RMP = 10;        // Timer Input 4 remap (2 bits)
    static const uint32_t OR_RESET_VALUE = 0x0;
};

static tim2_t& TIM2 = *reinterpret_cast<tim2_t*>(0x40000000);


////
//
//    General purpose timers
//
////

struct tim3_t
{
    volatile uint32_t    CR1;                  // [Read-write] control register 1
    volatile uint32_t    CR2;                  // [Read-write] control register 2
    volatile uint32_t    SMCR;                 // [Read-write] slave mode control register
    volatile uint32_t    DIER;                 // [Read-write] DMA/Interrupt enable register
    volatile uint32_t    SR;                   // [Read-write] status register
    volatile uint32_t    EGR;                  // [Write-only] event generation register
    volatile uint32_t    CCMR1;                // [Read-write] capture/compare mode register 1 (output mode)
    volatile uint32_t    CCMR2;                // [Read-write] capture/compare mode register 2 (output mode)
    volatile uint32_t    CCER;                 // [Read-write] capture/compare enable register
    volatile uint32_t    CNT;                  // [Read-write] counter
    volatile uint32_t    PSC;                  // [Read-write] prescaler
    volatile uint32_t    ARR;                  // [Read-write] auto-reload register
    reserved_t<1>        _0;
    volatile uint32_t    CCR1;                 // [Read-write] capture/compare register 1
    volatile uint32_t    CCR2;                 // [Read-write] capture/compare register 2
    volatile uint32_t    CCR3;                 // [Read-write] capture/compare register 3
    volatile uint32_t    CCR4;                 // [Read-write] capture/compare register 4
    reserved_t<1>        _1;
    volatile uint32_t    DCR;                  // [Read-write] DMA control register
    volatile uint32_t    DMAR;                 // [Read-write] DMA address for full transfer

    static const uint8_t CR1_CKD = 8;              // Clock division (2 bits)
    static const uint8_t CR1_ARPE = 7;             // Auto-reload preload enable
    static const uint8_t CR1_CMS = 5;              // Center-aligned mode selection (2 bits)
    static const uint8_t CR1_DIR = 4;              // Direction
    static const uint8_t CR1_OPM = 3;              // One-pulse mode
    static const uint8_t CR1_URS = 2;              // Update request source
    static const uint8_t CR1_UDIS = 1;             // Update disable
    static const uint8_t CR1_CEN = 0;              // Counter enable
    static const uint32_t CR1_RESET_VALUE = 0x0;

    static const uint8_t CR2_TI1S = 7;             // TI1 selection
    static const uint8_t CR2_MMS = 4;              // Master mode selection (3 bits)
    static const uint8_t CR2_CCDS = 3;             // Capture/compare DMA selection
    static const uint32_t CR2_RESET_VALUE = 0x0;

    static const uint8_t SMCR_ETP = 15;             // External trigger polarity
    static const uint8_t SMCR_ECE = 14;             // External clock enable
    static const uint8_t SMCR_ETPS = 12;            // External trigger prescaler (2 bits)
    static const uint8_t SMCR_ETF = 8;              // External trigger filter (4 bits)
    static const uint8_t SMCR_MSM = 7;              // Master/Slave mode
    static const uint8_t SMCR_TS = 4;               // Trigger selection (3 bits)
    static const uint8_t SMCR_SMS = 0;              // Slave mode selection (3 bits)
    static const uint32_t SMCR_RESET_VALUE = 0x0;

    static const uint8_t DIER_TDE = 14;             // Trigger DMA request enable
    static const uint8_t DIER_CC4DE = 12;           // Capture/Compare 4 DMA request enable
    static const uint8_t DIER_CC3DE = 11;           // Capture/Compare 3 DMA request enable
    static const uint8_t DIER_CC2DE = 10;           // Capture/Compare 2 DMA request enable
    static const uint8_t DIER_CC1DE = 9;            // Capture/Compare 1 DMA request enable
    static const uint8_t DIER_UDE = 8;              // Update DMA request enable
    static const uint8_t DIER_TIE = 6;              // Trigger interrupt enable
    static const uint8_t DIER_CC4IE = 4;            // Capture/Compare 4 interrupt enable
    static const uint8_t DIER_CC3IE = 3;            // Capture/Compare 3 interrupt enable
    static const uint8_t DIER_CC2IE = 2;            // Capture/Compare 2 interrupt enable
    static const uint8_t DIER_CC1IE = 1;            // Capture/Compare 1 interrupt enable
    static const uint8_t DIER_UIE = 0;              // Update interrupt enable
    static const uint32_t DIER_RESET_VALUE = 0x0;

    static const uint8_t SR_CC4OF = 12;           // Capture/Compare 4 overcapture flag
    static const uint8_t SR_CC3OF = 11;           // Capture/Compare 3 overcapture flag
    static const uint8_t SR_CC2OF = 10;           // Capture/compare 2 overcapture flag
    static const uint8_t SR_CC1OF = 9;            // Capture/Compare 1 overcapture flag
    static const uint8_t SR_TIF = 6;              // Trigger interrupt flag
    static const uint8_t SR_CC4IF = 4;            // Capture/Compare 4 interrupt flag
    static const uint8_t SR_CC3IF = 3;            // Capture/Compare 3 interrupt flag
    static const uint8_t SR_CC2IF = 2;            // Capture/Compare 2 interrupt flag
    static const uint8_t SR_CC1IF = 1;            // Capture/compare 1 interrupt flag
    static const uint8_t SR_UIF = 0;              // Update interrupt flag
    static const uint32_t SR_RESET_VALUE = 0x0;

    static const uint8_t EGR_TG = 6;               // Trigger generation
    static const uint8_t EGR_CC4G = 4;             // Capture/compare 4 generation
    static const uint8_t EGR_CC3G = 3;             // Capture/compare 3 generation
    static const uint8_t EGR_CC2G = 2;             // Capture/compare 2 generation
    static const uint8_t EGR_CC1G = 1;             // Capture/compare 1 generation
    static const uint8_t EGR_UG = 0;               // Update generation
    static const uint32_t EGR_RESET_VALUE = 0x0;

    static const uint8_t CCMR1_CC1S = 0;             // CC1S (2 bits)
    static const uint8_t CCMR1_CC2S = 8;             // CC2S (2 bits)
    static const uint8_t CCMR1_IC1F = 4;             // Input capture 1 filter (4 bits)
    static const uint8_t CCMR1_IC2F = 12;            // Input capture 2 filter (4 bits)
    static const uint8_t CCMR1_IC2PCS = 10;          // Input capture 2 prescaler (2 bits)
    static const uint8_t CCMR1_ICPCS = 2;            // Input capture 1 prescaler (2 bits)
    static const uint8_t CCMR1_OC1CE = 7;            // OC1CE
    static const uint8_t CCMR1_OC1FE = 2;            // OC1FE
    static const uint8_t CCMR1_OC1M = 4;             // OC1M (3 bits)
    static const uint8_t CCMR1_OC1PE = 3;            // OC1PE
    static const uint8_t CCMR1_OC2CE = 15;           // OC2CE
    static const uint8_t CCMR1_OC2FE = 10;           // OC2FE
    static const uint8_t CCMR1_OC2M = 12;            // OC2M (3 bits)
    static const uint8_t CCMR1_OC2PE = 11;           // OC2PE
    static const uint32_t CCMR1_RESET_VALUE = 0x0;

    static const uint8_t CCMR2_CC3S = 0;             // CC3S (2 bits)
    static const uint8_t CCMR2_CC4S = 8;             // CC4S (2 bits)
    static const uint8_t CCMR2_IC3F = 4;             // Input capture 3 filter (4 bits)
    static const uint8_t CCMR2_IC3PSC = 2;           // Input capture 3 prescaler (2 bits)
    static const uint8_t CCMR2_IC4F = 12;            // Input capture 4 filter (4 bits)
    static const uint8_t CCMR2_IC4PSC = 10;          // Input capture 4 prescaler (2 bits)
    static const uint8_t CCMR2_O24CE = 15;           // O24CE
    static const uint8_t CCMR2_OC3CE = 7;            // OC3CE
    static const uint8_t CCMR2_OC3FE = 2;            // OC3FE
    static const uint8_t CCMR2_OC3M = 4;             // OC3M (3 bits)
    static const uint8_t CCMR2_OC3PE = 3;            // OC3PE
    static const uint8_t CCMR2_OC4FE = 10;           // OC4FE
    static const uint8_t CCMR2_OC4M = 12;            // OC4M (3 bits)
    static const uint8_t CCMR2_OC4PE = 11;           // OC4PE
    static const uint32_t CCMR2_RESET_VALUE = 0x0;

    static const uint8_t CCER_CC4NP = 15;           // Capture/Compare 4 output Polarity
    static const uint8_t CCER_CC4P = 13;            // Capture/Compare 3 output Polarity
    static const uint8_t CCER_CC4E = 12;            // Capture/Compare 4 output enable
    static const uint8_t CCER_CC3NP = 11;           // Capture/Compare 3 output Polarity
    static const uint8_t CCER_CC3P = 9;             // Capture/Compare 3 output Polarity
    static const uint8_t CCER_CC3E = 8;             // Capture/Compare 3 output enable
    static const uint8_t CCER_CC2NP = 7;            // Capture/Compare 2 output Polarity
    static const uint8_t CCER_CC2P = 5;             // Capture/Compare 2 output Polarity
    static const uint8_t CCER_CC2E = 4;             // Capture/Compare 2 output enable
    static const uint8_t CCER_CC1NP = 3;            // Capture/Compare 1 output Polarity
    static const uint8_t CCER_CC1P = 1;             // Capture/Compare 1 output Polarity
    static const uint8_t CCER_CC1E = 0;             // Capture/Compare 1 output enable
    static const uint32_t CCER_RESET_VALUE = 0x0;

    static const uint8_t CNT_CNT_H = 16;           // High counter value (16 bits)
    static const uint8_t CNT_CNT_L = 0;            // Low counter value (16 bits)
    static const uint32_t CNT_RESET_VALUE = 0x0;

    static const uint8_t PSC_PSC = 0;              // Prescaler value (16 bits)
    static const uint32_t PSC_RESET_VALUE = 0x0;

    static const uint8_t ARR_ARR_H = 16;           // High Auto-reload value (16 bits)
    static const uint8_t ARR_ARR_L = 0;            // Low Auto-reload value (16 bits)
    static const uint32_t ARR_RESET_VALUE = 0x0;

    static const uint8_t CCR1_CCR1_H = 16;          // High Capture/Compare 1 value (16 bits)
    static const uint8_t CCR1_CCR1_L = 0;           // Low Capture/Compare 1 value (16 bits)
    static const uint32_t CCR1_RESET_VALUE = 0x0;

    static const uint8_t CCR2_CCR2_H = 16;          // High Capture/Compare 2 value (16 bits)
    static const uint8_t CCR2_CCR2_L = 0;           // Low Capture/Compare 2 value (16 bits)
    static const uint32_t CCR2_RESET_VALUE = 0x0;

    static const uint8_t CCR3_CCR3_H = 16;          // High Capture/Compare value (16 bits)
    static const uint8_t CCR3_CCR3_L = 0;           // Low Capture/Compare value (16 bits)
    static const uint32_t CCR3_RESET_VALUE = 0x0;

    static const uint8_t CCR4_CCR4_H = 16;          // High Capture/Compare value (16 bits)
    static const uint8_t CCR4_CCR4_L = 0;           // Low Capture/Compare value (16 bits)
    static const uint32_t CCR4_RESET_VALUE = 0x0;

    static const uint8_t DCR_DBL = 8;              // DMA burst length (5 bits)
    static const uint8_t DCR_DBA = 0;              // DMA base address (5 bits)
    static const uint32_t DCR_RESET_VALUE = 0x0;

    static const uint8_t DMAR_DMAB = 0;             // DMA register for burst accesses (16 bits)
    static const uint32_t DMAR_RESET_VALUE = 0x0;
};

static tim3_t& TIM3 = *reinterpret_cast<tim3_t*>(0x40000400);


////
//
//    General purpose timers
//
////

struct tim4_t
{
    volatile uint32_t    CR1;                  // [Read-write] control register 1
    volatile uint32_t    CR2;                  // [Read-write] control register 2
    volatile uint32_t    SMCR;                 // [Read-write] slave mode control register
    volatile uint32_t    DIER;                 // [Read-write] DMA/Interrupt enable register
    volatile uint32_t    SR;                   // [Read-write] status register
    volatile uint32_t    EGR;                  // [Write-only] event generation register
    volatile uint32_t    CCMR1;                // [Read-write] capture/compare mode register 1 (output mode)
    volatile uint32_t    CCMR2;                // [Read-write] capture/compare mode register 2 (output mode)
    volatile uint32_t    CCER;                 // [Read-write] capture/compare enable register
    volatile uint32_t    CNT;                  // [Read-write] counter
    volatile uint32_t    PSC;                  // [Read-write] prescaler
    volatile uint32_t    ARR;                  // [Read-write] auto-reload register
    reserved_t<1>        _0;
    volatile uint32_t    CCR1;                 // [Read-write] capture/compare register 1
    volatile uint32_t    CCR2;                 // [Read-write] capture/compare register 2
    volatile uint32_t    CCR3;                 // [Read-write] capture/compare register 3
    volatile uint32_t    CCR4;                 // [Read-write] capture/compare register 4
    reserved_t<1>        _1;
    volatile uint32_t    DCR;                  // [Read-write] DMA control register
    volatile uint32_t    DMAR;                 // [Read-write] DMA address for full transfer

    static const uint8_t CR1_CKD = 8;              // Clock division (2 bits)
    static const uint8_t CR1_ARPE = 7;             // Auto-reload preload enable
    static const uint8_t CR1_CMS = 5;              // Center-aligned mode selection (2 bits)
    static const uint8_t CR1_DIR = 4;              // Direction
    static const uint8_t CR1_OPM = 3;              // One-pulse mode
    static const uint8_t CR1_URS = 2;              // Update request source
    static const uint8_t CR1_UDIS = 1;             // Update disable
    static const uint8_t CR1_CEN = 0;              // Counter enable
    static const uint32_t CR1_RESET_VALUE = 0x0;

    static const uint8_t CR2_TI1S = 7;             // TI1 selection
    static const uint8_t CR2_MMS = 4;              // Master mode selection (3 bits)
    static const uint8_t CR2_CCDS = 3;             // Capture/compare DMA selection
    static const uint32_t CR2_RESET_VALUE = 0x0;

    static const uint8_t SMCR_ETP = 15;             // External trigger polarity
    static const uint8_t SMCR_ECE = 14;             // External clock enable
    static const uint8_t SMCR_ETPS = 12;            // External trigger prescaler (2 bits)
    static const uint8_t SMCR_ETF = 8;              // External trigger filter (4 bits)
    static const uint8_t SMCR_MSM = 7;              // Master/Slave mode
    static const uint8_t SMCR_TS = 4;               // Trigger selection (3 bits)
    static const uint8_t SMCR_SMS = 0;              // Slave mode selection (3 bits)
    static const uint32_t SMCR_RESET_VALUE = 0x0;

    static const uint8_t DIER_TDE = 14;             // Trigger DMA request enable
    static const uint8_t DIER_CC4DE = 12;           // Capture/Compare 4 DMA request enable
    static const uint8_t DIER_CC3DE = 11;           // Capture/Compare 3 DMA request enable
    static const uint8_t DIER_CC2DE = 10;           // Capture/Compare 2 DMA request enable
    static const uint8_t DIER_CC1DE = 9;            // Capture/Compare 1 DMA request enable
    static const uint8_t DIER_UDE = 8;              // Update DMA request enable
    static const uint8_t DIER_TIE = 6;              // Trigger interrupt enable
    static const uint8_t DIER_CC4IE = 4;            // Capture/Compare 4 interrupt enable
    static const uint8_t DIER_CC3IE = 3;            // Capture/Compare 3 interrupt enable
    static const uint8_t DIER_CC2IE = 2;            // Capture/Compare 2 interrupt enable
    static const uint8_t DIER_CC1IE = 1;            // Capture/Compare 1 interrupt enable
    static const uint8_t DIER_UIE = 0;              // Update interrupt enable
    static const uint32_t DIER_RESET_VALUE = 0x0;

    static const uint8_t SR_CC4OF = 12;           // Capture/Compare 4 overcapture flag
    static const uint8_t SR_CC3OF = 11;           // Capture/Compare 3 overcapture flag
    static const uint8_t SR_CC2OF = 10;           // Capture/compare 2 overcapture flag
    static const uint8_t SR_CC1OF = 9;            // Capture/Compare 1 overcapture flag
    static const uint8_t SR_TIF = 6;              // Trigger interrupt flag
    static const uint8_t SR_CC4IF = 4;            // Capture/Compare 4 interrupt flag
    static const uint8_t SR_CC3IF = 3;            // Capture/Compare 3 interrupt flag
    static const uint8_t SR_CC2IF = 2;            // Capture/Compare 2 interrupt flag
    static const uint8_t SR_CC1IF = 1;            // Capture/compare 1 interrupt flag
    static const uint8_t SR_UIF = 0;              // Update interrupt flag
    static const uint32_t SR_RESET_VALUE = 0x0;

    static const uint8_t EGR_TG = 6;               // Trigger generation
    static const uint8_t EGR_CC4G = 4;             // Capture/compare 4 generation
    static const uint8_t EGR_CC3G = 3;             // Capture/compare 3 generation
    static const uint8_t EGR_CC2G = 2;             // Capture/compare 2 generation
    static const uint8_t EGR_CC1G = 1;             // Capture/compare 1 generation
    static const uint8_t EGR_UG = 0;               // Update generation
    static const uint32_t EGR_RESET_VALUE = 0x0;

    static const uint8_t CCMR1_CC1S = 0;             // CC1S (2 bits)
    static const uint8_t CCMR1_CC2S = 8;             // CC2S (2 bits)
    static const uint8_t CCMR1_IC1F = 4;             // Input capture 1 filter (4 bits)
    static const uint8_t CCMR1_IC2F = 12;            // Input capture 2 filter (4 bits)
    static const uint8_t CCMR1_IC2PCS = 10;          // Input capture 2 prescaler (2 bits)
    static const uint8_t CCMR1_ICPCS = 2;            // Input capture 1 prescaler (2 bits)
    static const uint8_t CCMR1_OC1CE = 7;            // OC1CE
    static const uint8_t CCMR1_OC1FE = 2;            // OC1FE
    static const uint8_t CCMR1_OC1M = 4;             // OC1M (3 bits)
    static const uint8_t CCMR1_OC1PE = 3;            // OC1PE
    static const uint8_t CCMR1_OC2CE = 15;           // OC2CE
    static const uint8_t CCMR1_OC2FE = 10;           // OC2FE
    static const uint8_t CCMR1_OC2M = 12;            // OC2M (3 bits)
    static const uint8_t CCMR1_OC2PE = 11;           // OC2PE
    static const uint32_t CCMR1_RESET_VALUE = 0x0;

    static const uint8_t CCMR2_CC3S = 0;             // CC3S (2 bits)
    static const uint8_t CCMR2_CC4S = 8;             // CC4S (2 bits)
    static const uint8_t CCMR2_IC3F = 4;             // Input capture 3 filter (4 bits)
    static const uint8_t CCMR2_IC3PSC = 2;           // Input capture 3 prescaler (2 bits)
    static const uint8_t CCMR2_IC4F = 12;            // Input capture 4 filter (4 bits)
    static const uint8_t CCMR2_IC4PSC = 10;          // Input capture 4 prescaler (2 bits)
    static const uint8_t CCMR2_O24CE = 15;           // O24CE
    static const uint8_t CCMR2_OC3CE = 7;            // OC3CE
    static const uint8_t CCMR2_OC3FE = 2;            // OC3FE
    static const uint8_t CCMR2_OC3M = 4;             // OC3M (3 bits)
    static const uint8_t CCMR2_OC3PE = 3;            // OC3PE
    static const uint8_t CCMR2_OC4FE = 10;           // OC4FE
    static const uint8_t CCMR2_OC4M = 12;            // OC4M (3 bits)
    static const uint8_t CCMR2_OC4PE = 11;           // OC4PE
    static const uint32_t CCMR2_RESET_VALUE = 0x0;

    static const uint8_t CCER_CC4NP = 15;           // Capture/Compare 4 output Polarity
    static const uint8_t CCER_CC4P = 13;            // Capture/Compare 3 output Polarity
    static const uint8_t CCER_CC4E = 12;            // Capture/Compare 4 output enable
    static const uint8_t CCER_CC3NP = 11;           // Capture/Compare 3 output Polarity
    static const uint8_t CCER_CC3P = 9;             // Capture/Compare 3 output Polarity
    static const uint8_t CCER_CC3E = 8;             // Capture/Compare 3 output enable
    static const uint8_t CCER_CC2NP = 7;            // Capture/Compare 2 output Polarity
    static const uint8_t CCER_CC2P = 5;             // Capture/Compare 2 output Polarity
    static const uint8_t CCER_CC2E = 4;             // Capture/Compare 2 output enable
    static const uint8_t CCER_CC1NP = 3;            // Capture/Compare 1 output Polarity
    static const uint8_t CCER_CC1P = 1;             // Capture/Compare 1 output Polarity
    static const uint8_t CCER_CC1E = 0;             // Capture/Compare 1 output enable
    static const uint32_t CCER_RESET_VALUE = 0x0;

    static const uint8_t CNT_CNT_H = 16;           // High counter value (16 bits)
    static const uint8_t CNT_CNT_L = 0;            // Low counter value (16 bits)
    static const uint32_t CNT_RESET_VALUE = 0x0;

    static const uint8_t PSC_PSC = 0;              // Prescaler value (16 bits)
    static const uint32_t PSC_RESET_VALUE = 0x0;

    static const uint8_t ARR_ARR_H = 16;           // High Auto-reload value (16 bits)
    static const uint8_t ARR_ARR_L = 0;            // Low Auto-reload value (16 bits)
    static const uint32_t ARR_RESET_VALUE = 0x0;

    static const uint8_t CCR1_CCR1_H = 16;          // High Capture/Compare 1 value (16 bits)
    static const uint8_t CCR1_CCR1_L = 0;           // Low Capture/Compare 1 value (16 bits)
    static const uint32_t CCR1_RESET_VALUE = 0x0;

    static const uint8_t CCR2_CCR2_H = 16;          // High Capture/Compare 2 value (16 bits)
    static const uint8_t CCR2_CCR2_L = 0;           // Low Capture/Compare 2 value (16 bits)
    static const uint32_t CCR2_RESET_VALUE = 0x0;

    static const uint8_t CCR3_CCR3_H = 16;          // High Capture/Compare value (16 bits)
    static const uint8_t CCR3_CCR3_L = 0;           // Low Capture/Compare value (16 bits)
    static const uint32_t CCR3_RESET_VALUE = 0x0;

    static const uint8_t CCR4_CCR4_H = 16;          // High Capture/Compare value (16 bits)
    static const uint8_t CCR4_CCR4_L = 0;           // Low Capture/Compare value (16 bits)
    static const uint32_t CCR4_RESET_VALUE = 0x0;

    static const uint8_t DCR_DBL = 8;              // DMA burst length (5 bits)
    static const uint8_t DCR_DBA = 0;              // DMA base address (5 bits)
    static const uint32_t DCR_RESET_VALUE = 0x0;

    static const uint8_t DMAR_DMAB = 0;             // DMA register for burst accesses (16 bits)
    static const uint32_t DMAR_RESET_VALUE = 0x0;
};

static tim4_t& TIM4 = *reinterpret_cast<tim4_t*>(0x40000800);


////
//
//    General-purpose-timers
//
////

struct tim5_t
{
    volatile uint32_t    CR1;                  // [Read-write] control register 1
    volatile uint32_t    CR2;                  // [Read-write] control register 2
    volatile uint32_t    SMCR;                 // [Read-write] slave mode control register
    volatile uint32_t    DIER;                 // [Read-write] DMA/Interrupt enable register
    volatile uint32_t    SR;                   // [Read-write] status register
    volatile uint32_t    EGR;                  // [Write-only] event generation register
    volatile uint32_t    CCMR1;                // [Read-write] capture/compare mode register 1 (output mode)
    volatile uint32_t    CCMR2;                // [Read-write] capture/compare mode register 2 (output mode)
    volatile uint32_t    CCER;                 // [Read-write] capture/compare enable register
    volatile uint32_t    CNT;                  // [Read-write] counter
    volatile uint32_t    PSC;                  // [Read-write] prescaler
    volatile uint32_t    ARR;                  // [Read-write] auto-reload register
    reserved_t<1>        _0;
    volatile uint32_t    CCR1;                 // [Read-write] capture/compare register 1
    volatile uint32_t    CCR2;                 // [Read-write] capture/compare register 2
    volatile uint32_t    CCR3;                 // [Read-write] capture/compare register 3
    volatile uint32_t    CCR4;                 // [Read-write] capture/compare register 4
    reserved_t<1>        _1;
    volatile uint32_t    DCR;                  // [Read-write] DMA control register
    volatile uint32_t    DMAR;                 // [Read-write] DMA address for full transfer
    volatile uint32_t    OR;                   // [Read-write] TIM5 option register

    static const uint8_t CR1_CKD = 8;              // Clock division (2 bits)
    static const uint8_t CR1_ARPE = 7;             // Auto-reload preload enable
    static const uint8_t CR1_CMS = 5;              // Center-aligned mode selection (2 bits)
    static const uint8_t CR1_DIR = 4;              // Direction
    static const uint8_t CR1_OPM = 3;              // One-pulse mode
    static const uint8_t CR1_URS = 2;              // Update request source
    static const uint8_t CR1_UDIS = 1;             // Update disable
    static const uint8_t CR1_CEN = 0;              // Counter enable
    static const uint32_t CR1_RESET_VALUE = 0x0;

    static const uint8_t CR2_TI1S = 7;             // TI1 selection
    static const uint8_t CR2_MMS = 4;              // Master mode selection (3 bits)
    static const uint8_t CR2_CCDS = 3;             // Capture/compare DMA selection
    static const uint32_t CR2_RESET_VALUE = 0x0;

    static const uint8_t SMCR_ETP = 15;             // External trigger polarity
    static const uint8_t SMCR_ECE = 14;             // External clock enable
    static const uint8_t SMCR_ETPS = 12;            // External trigger prescaler (2 bits)
    static const uint8_t SMCR_ETF = 8;              // External trigger filter (4 bits)
    static const uint8_t SMCR_MSM = 7;              // Master/Slave mode
    static const uint8_t SMCR_TS = 4;               // Trigger selection (3 bits)
    static const uint8_t SMCR_SMS = 0;              // Slave mode selection (3 bits)
    static const uint32_t SMCR_RESET_VALUE = 0x0;

    static const uint8_t DIER_TDE = 14;             // Trigger DMA request enable
    static const uint8_t DIER_CC4DE = 12;           // Capture/Compare 4 DMA request enable
    static const uint8_t DIER_CC3DE = 11;           // Capture/Compare 3 DMA request enable
    static const uint8_t DIER_CC2DE = 10;           // Capture/Compare 2 DMA request enable
    static const uint8_t DIER_CC1DE = 9;            // Capture/Compare 1 DMA request enable
    static const uint8_t DIER_UDE = 8;              // Update DMA request enable
    static const uint8_t DIER_TIE = 6;              // Trigger interrupt enable
    static const uint8_t DIER_CC4IE = 4;            // Capture/Compare 4 interrupt enable
    static const uint8_t DIER_CC3IE = 3;            // Capture/Compare 3 interrupt enable
    static const uint8_t DIER_CC2IE = 2;            // Capture/Compare 2 interrupt enable
    static const uint8_t DIER_CC1IE = 1;            // Capture/Compare 1 interrupt enable
    static const uint8_t DIER_UIE = 0;              // Update interrupt enable
    static const uint32_t DIER_RESET_VALUE = 0x0;

    static const uint8_t SR_CC4OF = 12;           // Capture/Compare 4 overcapture flag
    static const uint8_t SR_CC3OF = 11;           // Capture/Compare 3 overcapture flag
    static const uint8_t SR_CC2OF = 10;           // Capture/compare 2 overcapture flag
    static const uint8_t SR_CC1OF = 9;            // Capture/Compare 1 overcapture flag
    static const uint8_t SR_TIF = 6;              // Trigger interrupt flag
    static const uint8_t SR_CC4IF = 4;            // Capture/Compare 4 interrupt flag
    static const uint8_t SR_CC3IF = 3;            // Capture/Compare 3 interrupt flag
    static const uint8_t SR_CC2IF = 2;            // Capture/Compare 2 interrupt flag
    static const uint8_t SR_CC1IF = 1;            // Capture/compare 1 interrupt flag
    static const uint8_t SR_UIF = 0;              // Update interrupt flag
    static const uint32_t SR_RESET_VALUE = 0x0;

    static const uint8_t EGR_TG = 6;               // Trigger generation
    static const uint8_t EGR_CC4G = 4;             // Capture/compare 4 generation
    static const uint8_t EGR_CC3G = 3;             // Capture/compare 3 generation
    static const uint8_t EGR_CC2G = 2;             // Capture/compare 2 generation
    static const uint8_t EGR_CC1G = 1;             // Capture/compare 1 generation
    static const uint8_t EGR_UG = 0;               // Update generation
    static const uint32_t EGR_RESET_VALUE = 0x0;

    static const uint8_t CCMR1_CC1S = 0;             // CC1S (2 bits)
    static const uint8_t CCMR1_CC2S = 8;             // CC2S (2 bits)
    static const uint8_t CCMR1_IC1F = 4;             // Input capture 1 filter (4 bits)
    static const uint8_t CCMR1_IC2F = 12;            // Input capture 2 filter (4 bits)
    static const uint8_t CCMR1_IC2PCS = 10;          // Input capture 2 prescaler (2 bits)
    static const uint8_t CCMR1_ICPCS = 2;            // Input capture 1 prescaler (2 bits)
    static const uint8_t CCMR1_OC1CE = 7;            // OC1CE
    static const uint8_t CCMR1_OC1FE = 2;            // OC1FE
    static const uint8_t CCMR1_OC1M = 4;             // OC1M (3 bits)
    static const uint8_t CCMR1_OC1PE = 3;            // OC1PE
    static const uint8_t CCMR1_OC2CE = 15;           // OC2CE
    static const uint8_t CCMR1_OC2FE = 10;           // OC2FE
    static const uint8_t CCMR1_OC2M = 12;            // OC2M (3 bits)
    static const uint8_t CCMR1_OC2PE = 11;           // OC2PE
    static const uint32_t CCMR1_RESET_VALUE = 0x0;

    static const uint8_t CCMR2_CC3S = 0;             // CC3S (2 bits)
    static const uint8_t CCMR2_CC4S = 8;             // CC4S (2 bits)
    static const uint8_t CCMR2_IC3F = 4;             // Input capture 3 filter (4 bits)
    static const uint8_t CCMR2_IC3PSC = 2;           // Input capture 3 prescaler (2 bits)
    static const uint8_t CCMR2_IC4F = 12;            // Input capture 4 filter (4 bits)
    static const uint8_t CCMR2_IC4PSC = 10;          // Input capture 4 prescaler (2 bits)
    static const uint8_t CCMR2_O24CE = 15;           // O24CE
    static const uint8_t CCMR2_OC3CE = 7;            // OC3CE
    static const uint8_t CCMR2_OC3FE = 2;            // OC3FE
    static const uint8_t CCMR2_OC3M = 4;             // OC3M (3 bits)
    static const uint8_t CCMR2_OC3PE = 3;            // OC3PE
    static const uint8_t CCMR2_OC4FE = 10;           // OC4FE
    static const uint8_t CCMR2_OC4M = 12;            // OC4M (3 bits)
    static const uint8_t CCMR2_OC4PE = 11;           // OC4PE
    static const uint32_t CCMR2_RESET_VALUE = 0x0;

    static const uint8_t CCER_CC4NP = 15;           // Capture/Compare 4 output Polarity
    static const uint8_t CCER_CC4P = 13;            // Capture/Compare 3 output Polarity
    static const uint8_t CCER_CC4E = 12;            // Capture/Compare 4 output enable
    static const uint8_t CCER_CC3NP = 11;           // Capture/Compare 3 output Polarity
    static const uint8_t CCER_CC3P = 9;             // Capture/Compare 3 output Polarity
    static const uint8_t CCER_CC3E = 8;             // Capture/Compare 3 output enable
    static const uint8_t CCER_CC2NP = 7;            // Capture/Compare 2 output Polarity
    static const uint8_t CCER_CC2P = 5;             // Capture/Compare 2 output Polarity
    static const uint8_t CCER_CC2E = 4;             // Capture/Compare 2 output enable
    static const uint8_t CCER_CC1NP = 3;            // Capture/Compare 1 output Polarity
    static const uint8_t CCER_CC1P = 1;             // Capture/Compare 1 output Polarity
    static const uint8_t CCER_CC1E = 0;             // Capture/Compare 1 output enable
    static const uint32_t CCER_RESET_VALUE = 0x0;

    static const uint8_t CNT_CNT_H = 16;           // High counter value (16 bits)
    static const uint8_t CNT_CNT_L = 0;            // Low counter value (16 bits)
    static const uint32_t CNT_RESET_VALUE = 0x0;

    static const uint8_t PSC_PSC = 0;              // Prescaler value (16 bits)
    static const uint32_t PSC_RESET_VALUE = 0x0;

    static const uint8_t ARR_ARR_H = 16;           // High Auto-reload value (16 bits)
    static const uint8_t ARR_ARR_L = 0;            // Low Auto-reload value (16 bits)
    static const uint32_t ARR_RESET_VALUE = 0x0;

    static const uint8_t CCR1_CCR1_H = 16;          // High Capture/Compare 1 value (16 bits)
    static const uint8_t CCR1_CCR1_L = 0;           // Low Capture/Compare 1 value (16 bits)
    static const uint32_t CCR1_RESET_VALUE = 0x0;

    static const uint8_t CCR2_CCR2_H = 16;          // High Capture/Compare 2 value (16 bits)
    static const uint8_t CCR2_CCR2_L = 0;           // Low Capture/Compare 2 value (16 bits)
    static const uint32_t CCR2_RESET_VALUE = 0x0;

    static const uint8_t CCR3_CCR3_H = 16;          // High Capture/Compare value (16 bits)
    static const uint8_t CCR3_CCR3_L = 0;           // Low Capture/Compare value (16 bits)
    static const uint32_t CCR3_RESET_VALUE = 0x0;

    static const uint8_t CCR4_CCR4_H = 16;          // High Capture/Compare value (16 bits)
    static const uint8_t CCR4_CCR4_L = 0;           // Low Capture/Compare value (16 bits)
    static const uint32_t CCR4_RESET_VALUE = 0x0;

    static const uint8_t DCR_DBL = 8;              // DMA burst length (5 bits)
    static const uint8_t DCR_DBA = 0;              // DMA base address (5 bits)
    static const uint32_t DCR_RESET_VALUE = 0x0;

    static const uint8_t DMAR_DMAB = 0;             // DMA register for burst accesses (16 bits)
    static const uint32_t DMAR_RESET_VALUE = 0x0;

    static const uint8_t OR_IT4_RMP = 6;          // Timer Input 4 remap (2 bits)
    static const uint32_t OR_RESET_VALUE = 0x0;
};

static tim5_t& TIM5 = *reinterpret_cast<tim5_t*>(0x40000c00);


////
//
//    General purpose timers
//
////

struct tim9_t
{
    volatile uint32_t    CR1;                  // [Read-write] control register 1
    volatile uint32_t    CR2;                  // [Read-write] control register 2
    volatile uint32_t    SMCR;                 // [Read-write] slave mode control register
    volatile uint32_t    DIER;                 // [Read-write] DMA/Interrupt enable register
    volatile uint32_t    SR;                   // [Read-write] status register
    volatile uint32_t    EGR;                  // [Write-only] event generation register
    volatile uint32_t    CCMR1;                // [Read-write] capture/compare mode register 1 (output mode)
    reserved_t<1>        _0;
    volatile uint32_t    CCER;                 // [Read-write] capture/compare enable register
    volatile uint32_t    CNT;                  // [Read-write] counter
    volatile uint32_t    PSC;                  // [Read-write] prescaler
    volatile uint32_t    ARR;                  // [Read-write] auto-reload register
    reserved_t<1>        _1;
    volatile uint32_t    CCR1;                 // [Read-write] capture/compare register 1
    volatile uint32_t    CCR2;                 // [Read-write] capture/compare register 2

    static const uint8_t CR1_CKD = 8;              // Clock division (2 bits)
    static const uint8_t CR1_ARPE = 7;             // Auto-reload preload enable
    static const uint8_t CR1_OPM = 3;              // One-pulse mode
    static const uint8_t CR1_URS = 2;              // Update request source
    static const uint8_t CR1_UDIS = 1;             // Update disable
    static const uint8_t CR1_CEN = 0;              // Counter enable
    static const uint32_t CR1_RESET_VALUE = 0x0;

    static const uint8_t CR2_MMS = 4;              // Master mode selection (3 bits)
    static const uint32_t CR2_RESET_VALUE = 0x0;

    static const uint8_t SMCR_MSM = 7;              // Master/Slave mode
    static const uint8_t SMCR_TS = 4;               // Trigger selection (3 bits)
    static const uint8_t SMCR_SMS = 0;              // Slave mode selection (3 bits)
    static const uint32_t SMCR_RESET_VALUE = 0x0;

    static const uint8_t DIER_TIE = 6;              // Trigger interrupt enable
    static const uint8_t DIER_CC2IE = 2;            // Capture/Compare 2 interrupt enable
    static const uint8_t DIER_CC1IE = 1;            // Capture/Compare 1 interrupt enable
    static const uint8_t DIER_UIE = 0;              // Update interrupt enable
    static const uint32_t DIER_RESET_VALUE = 0x0;

    static const uint8_t SR_CC2OF = 10;           // Capture/compare 2 overcapture flag
    static const uint8_t SR_CC1OF = 9;            // Capture/Compare 1 overcapture flag
    static const uint8_t SR_TIF = 6;              // Trigger interrupt flag
    static const uint8_t SR_CC2IF = 2;            // Capture/Compare 2 interrupt flag
    static const uint8_t SR_CC1IF = 1;            // Capture/compare 1 interrupt flag
    static const uint8_t SR_UIF = 0;              // Update interrupt flag
    static const uint32_t SR_RESET_VALUE = 0x0;

    static const uint8_t EGR_TG = 6;               // Trigger generation
    static const uint8_t EGR_CC2G = 2;             // Capture/compare 2 generation
    static const uint8_t EGR_CC1G = 1;             // Capture/compare 1 generation
    static const uint8_t EGR_UG = 0;               // Update generation
    static const uint32_t EGR_RESET_VALUE = 0x0;

    static const uint8_t CCMR1_CC1S = 0;             // Capture/Compare 1 selection (2 bits)
    static const uint8_t CCMR1_CC2S = 8;             // Capture/Compare 2 selection (2 bits)
    static const uint8_t CCMR1_IC1F = 4;             // Input capture 1 filter (3 bits)
    static const uint8_t CCMR1_IC2F = 12;            // Input capture 2 filter (3 bits)
    static const uint8_t CCMR1_IC2PCS = 10;          // Input capture 2 prescaler (2 bits)
    static const uint8_t CCMR1_ICPCS = 2;            // Input capture 1 prescaler (2 bits)
    static const uint8_t CCMR1_OC1FE = 2;            // Output Compare 1 fast enable
    static const uint8_t CCMR1_OC1M = 4;             // Output Compare 1 mode (3 bits)
    static const uint8_t CCMR1_OC1PE = 3;            // Output Compare 1 preload enable
    static const uint8_t CCMR1_OC2FE = 10;           // Output Compare 2 fast enable
    static const uint8_t CCMR1_OC2M = 12;            // Output Compare 2 mode (3 bits)
    static const uint8_t CCMR1_OC2PE = 11;           // Output Compare 2 preload enable
    static const uint32_t CCMR1_RESET_VALUE = 0x0;

    static const uint8_t CCER_CC2NP = 7;            // Capture/Compare 2 output Polarity
    static const uint8_t CCER_CC2P = 5;             // Capture/Compare 2 output Polarity
    static const uint8_t CCER_CC2E = 4;             // Capture/Compare 2 output enable
    static const uint8_t CCER_CC1NP = 3;            // Capture/Compare 1 output Polarity
    static const uint8_t CCER_CC1P = 1;             // Capture/Compare 1 output Polarity
    static const uint8_t CCER_CC1E = 0;             // Capture/Compare 1 output enable
    static const uint32_t CCER_RESET_VALUE = 0x0;

    static const uint8_t CNT_CNT = 0;              // counter value (16 bits)
    static const uint32_t CNT_RESET_VALUE = 0x0;

    static const uint8_t PSC_PSC = 0;              // Prescaler value (16 bits)
    static const uint32_t PSC_RESET_VALUE = 0x0;

    static const uint8_t ARR_ARR = 0;              // Auto-reload value (16 bits)
    static const uint32_t ARR_RESET_VALUE = 0x0;

    static const uint8_t CCR1_CCR1 = 0;             // Capture/Compare 1 value (16 bits)
    static const uint32_t CCR1_RESET_VALUE = 0x0;

    static const uint8_t CCR2_CCR2 = 0;             // Capture/Compare 2 value (16 bits)
    static const uint32_t CCR2_RESET_VALUE = 0x0;
};

static tim9_t& TIM9 = *reinterpret_cast<tim9_t*>(0x40014000);


////
//
//    Universal synchronous asynchronous receiver transmitter
//
////

struct usart1_t
{
    volatile uint32_t    SR;                   // Status register
    volatile uint32_t    DR;                   // [Read-write] Data register
    volatile uint32_t    BRR;                  // [Read-write] Baud rate register
    volatile uint32_t    CR1;                  // [Read-write] Control register 1
    volatile uint32_t    CR2;                  // [Read-write] Control register 2
    volatile uint32_t    CR3;                  // [Read-write] Control register 3
    volatile uint32_t    GTPR;                 // [Read-write] Guard time and prescaler register

    static const uint8_t SR_CTS = 9;              // CTS flag, Read-write
    static const uint8_t SR_LBD = 8;              // LIN break detection flag, Read-write
    static const uint8_t SR_TXE = 7;              // Transmit data register empty, Read-only
    static const uint8_t SR_TC = 6;               // Transmission complete, Read-write
    static const uint8_t SR_RXNE = 5;             // Read data register not empty, Read-write
    static const uint8_t SR_IDLE = 4;             // IDLE line detected, Read-only
    static const uint8_t SR_ORE = 3;              // Overrun error, Read-only
    static const uint8_t SR_NF = 2;               // Noise detected flag, Read-only
    static const uint8_t SR_FE = 1;               // Framing error, Read-only
    static const uint8_t SR_PE = 0;               // Parity error, Read-only
    static const uint32_t SR_RESET_VALUE = 0xc00000;

    static const uint8_t DR_DR = 0;               // Data value (9 bits)
    static const uint32_t DR_RESET_VALUE = 0x0;

    static const uint8_t BRR_DIV_Mantissa = 4;     // mantissa of USARTDIV (12 bits)
    static const uint8_t BRR_DIV_Fraction = 0;     // fraction of USARTDIV (4 bits)
    static const uint32_t BRR_RESET_VALUE = 0x0;

    static const uint8_t CR1_OVER8 = 15;           // Oversampling mode
    static const uint8_t CR1_UE = 13;              // USART enable
    static const uint8_t CR1_M = 12;               // Word length
    static const uint8_t CR1_WAKE = 11;            // Wakeup method
    static const uint8_t CR1_PCE = 10;             // Parity control enable
    static const uint8_t CR1_PS = 9;               // Parity selection
    static const uint8_t CR1_PEIE = 8;             // PE interrupt enable
    static const uint8_t CR1_TXEIE = 7;            // TXE interrupt enable
    static const uint8_t CR1_TCIE = 6;             // Transmission complete interrupt enable
    static const uint8_t CR1_RXNEIE = 5;           // RXNE interrupt enable
    static const uint8_t CR1_IDLEIE = 4;           // IDLE interrupt enable
    static const uint8_t CR1_TE = 3;               // Transmitter enable
    static const uint8_t CR1_RE = 2;               // Receiver enable
    static const uint8_t CR1_RWU = 1;              // Receiver wakeup
    static const uint8_t CR1_SBK = 0;              // Send break
    static const uint32_t CR1_RESET_VALUE = 0x0;

    static const uint8_t CR2_LINEN = 14;           // LIN mode enable
    static const uint8_t CR2_STOP = 12;            // STOP bits (2 bits)
    static const uint8_t CR2_CLKEN = 11;           // Clock enable
    static const uint8_t CR2_CPOL = 10;            // Clock polarity
    static const uint8_t CR2_CPHA = 9;             // Clock phase
    static const uint8_t CR2_LBCL = 8;             // Last bit clock pulse
    static const uint8_t CR2_LBDIE = 6;            // LIN break detection interrupt enable
    static const uint8_t CR2_LBDL = 5;             // lin break detection length
    static const uint8_t CR2_ADD = 0;              // Address of the USART node (4 bits)
    static const uint32_t CR2_RESET_VALUE = 0x0;

    static const uint8_t CR3_ONEBIT = 11;          // One sample bit method enable
    static const uint8_t CR3_CTSIE = 10;           // CTS interrupt enable
    static const uint8_t CR3_CTSE = 9;             // CTS enable
    static const uint8_t CR3_RTSE = 8;             // RTS enable
    static const uint8_t CR3_DMAT = 7;             // DMA enable transmitter
    static const uint8_t CR3_DMAR = 6;             // DMA enable receiver
    static const uint8_t CR3_SCEN = 5;             // Smartcard mode enable
    static const uint8_t CR3_NACK = 4;             // Smartcard NACK enable
    static const uint8_t CR3_HDSEL = 3;            // Half-duplex selection
    static const uint8_t CR3_IRLP = 2;             // IrDA low-power
    static const uint8_t CR3_IREN = 1;             // IrDA mode enable
    static const uint8_t CR3_EIE = 0;              // Error interrupt enable
    static const uint32_t CR3_RESET_VALUE = 0x0;

    static const uint8_t GTPR_GT = 8;               // Guard time value (8 bits)
    static const uint8_t GTPR_PSC = 0;              // Prescaler value (8 bits)
    static const uint32_t GTPR_RESET_VALUE = 0x0;
};

static usart1_t& USART1 = *reinterpret_cast<usart1_t*>(0x40011000);


////
//
//    Universal synchronous asynchronous receiver transmitter
//
////

struct usart2_t
{
    volatile uint32_t    SR;                   // Status register
    volatile uint32_t    DR;                   // [Read-write] Data register
    volatile uint32_t    BRR;                  // [Read-write] Baud rate register
    volatile uint32_t    CR1;                  // [Read-write] Control register 1
    volatile uint32_t    CR2;                  // [Read-write] Control register 2
    volatile uint32_t    CR3;                  // [Read-write] Control register 3
    volatile uint32_t    GTPR;                 // [Read-write] Guard time and prescaler register

    static const uint8_t SR_CTS = 9;              // CTS flag, Read-write
    static const uint8_t SR_LBD = 8;              // LIN break detection flag, Read-write
    static const uint8_t SR_TXE = 7;              // Transmit data register empty, Read-only
    static const uint8_t SR_TC = 6;               // Transmission complete, Read-write
    static const uint8_t SR_RXNE = 5;             // Read data register not empty, Read-write
    static const uint8_t SR_IDLE = 4;             // IDLE line detected, Read-only
    static const uint8_t SR_ORE = 3;              // Overrun error, Read-only
    static const uint8_t SR_NF = 2;               // Noise detected flag, Read-only
    static const uint8_t SR_FE = 1;               // Framing error, Read-only
    static const uint8_t SR_PE = 0;               // Parity error, Read-only
    static const uint32_t SR_RESET_VALUE = 0xc00000;

    static const uint8_t DR_DR = 0;               // Data value (9 bits)
    static const uint32_t DR_RESET_VALUE = 0x0;

    static const uint8_t BRR_DIV_Mantissa = 4;     // mantissa of USARTDIV (12 bits)
    static const uint8_t BRR_DIV_Fraction = 0;     // fraction of USARTDIV (4 bits)
    static const uint32_t BRR_RESET_VALUE = 0x0;

    static const uint8_t CR1_OVER8 = 15;           // Oversampling mode
    static const uint8_t CR1_UE = 13;              // USART enable
    static const uint8_t CR1_M = 12;               // Word length
    static const uint8_t CR1_WAKE = 11;            // Wakeup method
    static const uint8_t CR1_PCE = 10;             // Parity control enable
    static const uint8_t CR1_PS = 9;               // Parity selection
    static const uint8_t CR1_PEIE = 8;             // PE interrupt enable
    static const uint8_t CR1_TXEIE = 7;            // TXE interrupt enable
    static const uint8_t CR1_TCIE = 6;             // Transmission complete interrupt enable
    static const uint8_t CR1_RXNEIE = 5;           // RXNE interrupt enable
    static const uint8_t CR1_IDLEIE = 4;           // IDLE interrupt enable
    static const uint8_t CR1_TE = 3;               // Transmitter enable
    static const uint8_t CR1_RE = 2;               // Receiver enable
    static const uint8_t CR1_RWU = 1;              // Receiver wakeup
    static const uint8_t CR1_SBK = 0;              // Send break
    static const uint32_t CR1_RESET_VALUE = 0x0;

    static const uint8_t CR2_LINEN = 14;           // LIN mode enable
    static const uint8_t CR2_STOP = 12;            // STOP bits (2 bits)
    static const uint8_t CR2_CLKEN = 11;           // Clock enable
    static const uint8_t CR2_CPOL = 10;            // Clock polarity
    static const uint8_t CR2_CPHA = 9;             // Clock phase
    static const uint8_t CR2_LBCL = 8;             // Last bit clock pulse
    static const uint8_t CR2_LBDIE = 6;            // LIN break detection interrupt enable
    static const uint8_t CR2_LBDL = 5;             // lin break detection length
    static const uint8_t CR2_ADD = 0;              // Address of the USART node (4 bits)
    static const uint32_t CR2_RESET_VALUE = 0x0;

    static const uint8_t CR3_ONEBIT = 11;          // One sample bit method enable
    static const uint8_t CR3_CTSIE = 10;           // CTS interrupt enable
    static const uint8_t CR3_CTSE = 9;             // CTS enable
    static const uint8_t CR3_RTSE = 8;             // RTS enable
    static const uint8_t CR3_DMAT = 7;             // DMA enable transmitter
    static const uint8_t CR3_DMAR = 6;             // DMA enable receiver
    static const uint8_t CR3_SCEN = 5;             // Smartcard mode enable
    static const uint8_t CR3_NACK = 4;             // Smartcard NACK enable
    static const uint8_t CR3_HDSEL = 3;            // Half-duplex selection
    static const uint8_t CR3_IRLP = 2;             // IrDA low-power
    static const uint8_t CR3_IREN = 1;             // IrDA mode enable
    static const uint8_t CR3_EIE = 0;              // Error interrupt enable
    static const uint32_t CR3_RESET_VALUE = 0x0;

    static const uint8_t GTPR_GT = 8;               // Guard time value (8 bits)
    static const uint8_t GTPR_PSC = 0;              // Prescaler value (8 bits)
    static const uint32_t GTPR_RESET_VALUE = 0x0;
};

static usart2_t& USART2 = *reinterpret_cast<usart2_t*>(0x40004400);


////
//
//    Universal synchronous asynchronous receiver transmitter
//
////

struct usart6_t
{
    volatile uint32_t    SR;                   // Status register
    volatile uint32_t    DR;                   // [Read-write] Data register
    volatile uint32_t    BRR;                  // [Read-write] Baud rate register
    volatile uint32_t    CR1;                  // [Read-write] Control register 1
    volatile uint32_t    CR2;                  // [Read-write] Control register 2
    volatile uint32_t    CR3;                  // [Read-write] Control register 3
    volatile uint32_t    GTPR;                 // [Read-write] Guard time and prescaler register

    static const uint8_t SR_CTS = 9;              // CTS flag, Read-write
    static const uint8_t SR_LBD = 8;              // LIN break detection flag, Read-write
    static const uint8_t SR_TXE = 7;              // Transmit data register empty, Read-only
    static const uint8_t SR_TC = 6;               // Transmission complete, Read-write
    static const uint8_t SR_RXNE = 5;             // Read data register not empty, Read-write
    static const uint8_t SR_IDLE = 4;             // IDLE line detected, Read-only
    static const uint8_t SR_ORE = 3;              // Overrun error, Read-only
    static const uint8_t SR_NF = 2;               // Noise detected flag, Read-only
    static const uint8_t SR_FE = 1;               // Framing error, Read-only
    static const uint8_t SR_PE = 0;               // Parity error, Read-only
    static const uint32_t SR_RESET_VALUE = 0xc00000;

    static const uint8_t DR_DR = 0;               // Data value (9 bits)
    static const uint32_t DR_RESET_VALUE = 0x0;

    static const uint8_t BRR_DIV_Mantissa = 4;     // mantissa of USARTDIV (12 bits)
    static const uint8_t BRR_DIV_Fraction = 0;     // fraction of USARTDIV (4 bits)
    static const uint32_t BRR_RESET_VALUE = 0x0;

    static const uint8_t CR1_OVER8 = 15;           // Oversampling mode
    static const uint8_t CR1_UE = 13;              // USART enable
    static const uint8_t CR1_M = 12;               // Word length
    static const uint8_t CR1_WAKE = 11;            // Wakeup method
    static const uint8_t CR1_PCE = 10;             // Parity control enable
    static const uint8_t CR1_PS = 9;               // Parity selection
    static const uint8_t CR1_PEIE = 8;             // PE interrupt enable
    static const uint8_t CR1_TXEIE = 7;            // TXE interrupt enable
    static const uint8_t CR1_TCIE = 6;             // Transmission complete interrupt enable
    static const uint8_t CR1_RXNEIE = 5;           // RXNE interrupt enable
    static const uint8_t CR1_IDLEIE = 4;           // IDLE interrupt enable
    static const uint8_t CR1_TE = 3;               // Transmitter enable
    static const uint8_t CR1_RE = 2;               // Receiver enable
    static const uint8_t CR1_RWU = 1;              // Receiver wakeup
    static const uint8_t CR1_SBK = 0;              // Send break
    static const uint32_t CR1_RESET_VALUE = 0x0;

    static const uint8_t CR2_LINEN = 14;           // LIN mode enable
    static const uint8_t CR2_STOP = 12;            // STOP bits (2 bits)
    static const uint8_t CR2_CLKEN = 11;           // Clock enable
    static const uint8_t CR2_CPOL = 10;            // Clock polarity
    static const uint8_t CR2_CPHA = 9;             // Clock phase
    static const uint8_t CR2_LBCL = 8;             // Last bit clock pulse
    static const uint8_t CR2_LBDIE = 6;            // LIN break detection interrupt enable
    static const uint8_t CR2_LBDL = 5;             // lin break detection length
    static const uint8_t CR2_ADD = 0;              // Address of the USART node (4 bits)
    static const uint32_t CR2_RESET_VALUE = 0x0;

    static const uint8_t CR3_ONEBIT = 11;          // One sample bit method enable
    static const uint8_t CR3_CTSIE = 10;           // CTS interrupt enable
    static const uint8_t CR3_CTSE = 9;             // CTS enable
    static const uint8_t CR3_RTSE = 8;             // RTS enable
    static const uint8_t CR3_DMAT = 7;             // DMA enable transmitter
    static const uint8_t CR3_DMAR = 6;             // DMA enable receiver
    static const uint8_t CR3_SCEN = 5;             // Smartcard mode enable
    static const uint8_t CR3_NACK = 4;             // Smartcard NACK enable
    static const uint8_t CR3_HDSEL = 3;            // Half-duplex selection
    static const uint8_t CR3_IRLP = 2;             // IrDA low-power
    static const uint8_t CR3_IREN = 1;             // IrDA mode enable
    static const uint8_t CR3_EIE = 0;              // Error interrupt enable
    static const uint32_t CR3_RESET_VALUE = 0x0;

    static const uint8_t GTPR_GT = 8;               // Guard time value (8 bits)
    static const uint8_t GTPR_PSC = 0;              // Prescaler value (8 bits)
    static const uint32_t GTPR_RESET_VALUE = 0x0;
};

static usart6_t& USART6 = *reinterpret_cast<usart6_t*>(0x40011400);


////
//
//    Universal synchronous asynchronous receiver transmitter
//
////

struct usart3_t
{
    volatile uint32_t    SR;                   // Status register
    volatile uint32_t    DR;                   // [Read-write] Data register
    volatile uint32_t    BRR;                  // [Read-write] Baud rate register
    volatile uint32_t    CR1;                  // [Read-write] Control register 1
    volatile uint32_t    CR2;                  // [Read-write] Control register 2
    volatile uint32_t    CR3;                  // [Read-write] Control register 3
    volatile uint32_t    GTPR;                 // [Read-write] Guard time and prescaler register

    static const uint8_t SR_CTS = 9;              // CTS flag, Read-write
    static const uint8_t SR_LBD = 8;              // LIN break detection flag, Read-write
    static const uint8_t SR_TXE = 7;              // Transmit data register empty, Read-only
    static const uint8_t SR_TC = 6;               // Transmission complete, Read-write
    static const uint8_t SR_RXNE = 5;             // Read data register not empty, Read-write
    static const uint8_t SR_IDLE = 4;             // IDLE line detected, Read-only
    static const uint8_t SR_ORE = 3;              // Overrun error, Read-only
    static const uint8_t SR_NF = 2;               // Noise detected flag, Read-only
    static const uint8_t SR_FE = 1;               // Framing error, Read-only
    static const uint8_t SR_PE = 0;               // Parity error, Read-only
    static const uint32_t SR_RESET_VALUE = 0xc00000;

    static const uint8_t DR_DR = 0;               // Data value (9 bits)
    static const uint32_t DR_RESET_VALUE = 0x0;

    static const uint8_t BRR_DIV_Mantissa = 4;     // mantissa of USARTDIV (12 bits)
    static const uint8_t BRR_DIV_Fraction = 0;     // fraction of USARTDIV (4 bits)
    static const uint32_t BRR_RESET_VALUE = 0x0;

    static const uint8_t CR1_OVER8 = 15;           // Oversampling mode
    static const uint8_t CR1_UE = 13;              // USART enable
    static const uint8_t CR1_M = 12;               // Word length
    static const uint8_t CR1_WAKE = 11;            // Wakeup method
    static const uint8_t CR1_PCE = 10;             // Parity control enable
    static const uint8_t CR1_PS = 9;               // Parity selection
    static const uint8_t CR1_PEIE = 8;             // PE interrupt enable
    static const uint8_t CR1_TXEIE = 7;            // TXE interrupt enable
    static const uint8_t CR1_TCIE = 6;             // Transmission complete interrupt enable
    static const uint8_t CR1_RXNEIE = 5;           // RXNE interrupt enable
    static const uint8_t CR1_IDLEIE = 4;           // IDLE interrupt enable
    static const uint8_t CR1_TE = 3;               // Transmitter enable
    static const uint8_t CR1_RE = 2;               // Receiver enable
    static const uint8_t CR1_RWU = 1;              // Receiver wakeup
    static const uint8_t CR1_SBK = 0;              // Send break
    static const uint32_t CR1_RESET_VALUE = 0x0;

    static const uint8_t CR2_LINEN = 14;           // LIN mode enable
    static const uint8_t CR2_STOP = 12;            // STOP bits (2 bits)
    static const uint8_t CR2_CLKEN = 11;           // Clock enable
    static const uint8_t CR2_CPOL = 10;            // Clock polarity
    static const uint8_t CR2_CPHA = 9;             // Clock phase
    static const uint8_t CR2_LBCL = 8;             // Last bit clock pulse
    static const uint8_t CR2_LBDIE = 6;            // LIN break detection interrupt enable
    static const uint8_t CR2_LBDL = 5;             // lin break detection length
    static const uint8_t CR2_ADD = 0;              // Address of the USART node (4 bits)
    static const uint32_t CR2_RESET_VALUE = 0x0;

    static const uint8_t CR3_ONEBIT = 11;          // One sample bit method enable
    static const uint8_t CR3_CTSIE = 10;           // CTS interrupt enable
    static const uint8_t CR3_CTSE = 9;             // CTS enable
    static const uint8_t CR3_RTSE = 8;             // RTS enable
    static const uint8_t CR3_DMAT = 7;             // DMA enable transmitter
    static const uint8_t CR3_DMAR = 6;             // DMA enable receiver
    static const uint8_t CR3_SCEN = 5;             // Smartcard mode enable
    static const uint8_t CR3_NACK = 4;             // Smartcard NACK enable
    static const uint8_t CR3_HDSEL = 3;            // Half-duplex selection
    static const uint8_t CR3_IRLP = 2;             // IrDA low-power
    static const uint8_t CR3_IREN = 1;             // IrDA mode enable
    static const uint8_t CR3_EIE = 0;              // Error interrupt enable
    static const uint32_t CR3_RESET_VALUE = 0x0;

    static const uint8_t GTPR_GT = 8;               // Guard time value (8 bits)
    static const uint8_t GTPR_PSC = 0;              // Prescaler value (8 bits)
    static const uint32_t GTPR_RESET_VALUE = 0x0;
};

static usart3_t& USART3 = *reinterpret_cast<usart3_t*>(0x40004800);


////
//
//    Window watchdog
//
////

struct wwdg_t
{
    volatile uint32_t    CR;                   // [Read-write] Control register
    volatile uint32_t    CFR;                  // [Read-write] Configuration register
    volatile uint32_t    SR;                   // [Read-write] Status register

    static const uint8_t CR_WDGA = 7;             // Activation bit
    static const uint8_t CR_T = 0;                // 7-bit counter (MSB to LSB) (7 bits)
    static const uint32_t CR_RESET_VALUE = 0x7f;

    static const uint8_t CFR_EWI = 9;              // Early wakeup interrupt
    static const uint8_t CFR_WDGTB1 = 8;           // Timer base
    static const uint8_t CFR_WDGTB0 = 7;           // Timer base
    static const uint8_t CFR_W = 0;                // 7-bit window value (7 bits)
    static const uint32_t CFR_RESET_VALUE = 0x7f;

    static const uint8_t SR_EWIF = 0;             // Early wakeup interrupt flag
    static const uint32_t SR_RESET_VALUE = 0x0;
};

static wwdg_t& WWDG = *reinterpret_cast<wwdg_t*>(0x40002c00);


////
//
//    DMA controller
//
////

struct dma2_t
{
    volatile uint32_t    LISR;                 // [Read-only] low interrupt status register
    volatile uint32_t    HISR;                 // [Read-only] high interrupt status register
    volatile uint32_t    LIFCR;                // [Write-only] low interrupt flag clear register
    volatile uint32_t    HIFCR;                // [Write-only] high interrupt flag clear register
    volatile uint32_t    S0CR;                 // [Read-write] stream x configuration register
    volatile uint32_t    S0NDTR;               // [Read-write] stream x number of data register
    volatile uint32_t    S0PAR;                // [Read-write] stream x peripheral address register
    volatile uint32_t    S0M0AR;               // [Read-write] stream x memory 0 address register
    volatile uint32_t    S0M1AR;               // [Read-write] stream x memory 1 address register
    volatile uint32_t    S0FCR;                // stream x FIFO control register
    volatile uint32_t    S1CR;                 // [Read-write] stream x configuration register
    volatile uint32_t    S1NDTR;               // [Read-write] stream x number of data register
    volatile uint32_t    S1PAR;                // [Read-write] stream x peripheral address register
    volatile uint32_t    S1M0AR;               // [Read-write] stream x memory 0 address register
    volatile uint32_t    S1M1AR;               // [Read-write] stream x memory 1 address register
    volatile uint32_t    S1FCR;                // stream x FIFO control register
    volatile uint32_t    S2CR;                 // [Read-write] stream x configuration register
    volatile uint32_t    S2NDTR;               // [Read-write] stream x number of data register
    volatile uint32_t    S2PAR;                // [Read-write] stream x peripheral address register
    volatile uint32_t    S2M0AR;               // [Read-write] stream x memory 0 address register
    volatile uint32_t    S2M1AR;               // [Read-write] stream x memory 1 address register
    volatile uint32_t    S2FCR;                // stream x FIFO control register
    volatile uint32_t    S3CR;                 // [Read-write] stream x configuration register
    volatile uint32_t    S3NDTR;               // [Read-write] stream x number of data register
    volatile uint32_t    S3PAR;                // [Read-write] stream x peripheral address register
    volatile uint32_t    S3M0AR;               // [Read-write] stream x memory 0 address register
    volatile uint32_t    S3M1AR;               // [Read-write] stream x memory 1 address register
    volatile uint32_t    S3FCR;                // stream x FIFO control register
    volatile uint32_t    S4CR;                 // [Read-write] stream x configuration register
    volatile uint32_t    S4NDTR;               // [Read-write] stream x number of data register
    volatile uint32_t    S4PAR;                // [Read-write] stream x peripheral address register
    volatile uint32_t    S4M0AR;               // [Read-write] stream x memory 0 address register
    volatile uint32_t    S4M1AR;               // [Read-write] stream x memory 1 address register
    volatile uint32_t    S4FCR;                // stream x FIFO control register
    volatile uint32_t    S5CR;                 // [Read-write] stream x configuration register
    volatile uint32_t    S5NDTR;               // [Read-write] stream x number of data register
    volatile uint32_t    S5PAR;                // [Read-write] stream x peripheral address register
    volatile uint32_t    S5M0AR;               // [Read-write] stream x memory 0 address register
    volatile uint32_t    S5M1AR;               // [Read-write] stream x memory 1 address register
    volatile uint32_t    S5FCR;                // stream x FIFO control register
    volatile uint32_t    S6CR;                 // [Read-write] stream x configuration register
    volatile uint32_t    S6NDTR;               // [Read-write] stream x number of data register
    volatile uint32_t    S6PAR;                // [Read-write] stream x peripheral address register
    volatile uint32_t    S6M0AR;               // [Read-write] stream x memory 0 address register
    volatile uint32_t    S6M1AR;               // [Read-write] stream x memory 1 address register
    volatile uint32_t    S6FCR;                // stream x FIFO control register
    volatile uint32_t    S7CR;                 // [Read-write] stream x configuration register
    volatile uint32_t    S7NDTR;               // [Read-write] stream x number of data register
    volatile uint32_t    S7PAR;                // [Read-write] stream x peripheral address register
    volatile uint32_t    S7M0AR;               // [Read-write] stream x memory 0 address register
    volatile uint32_t    S7M1AR;               // [Read-write] stream x memory 1 address register
    volatile uint32_t    S7FCR;                // stream x FIFO control register

    static const uint8_t LISR_TCIF3 = 27;           // Stream x transfer complete interrupt flag (x = 3..0)
    static const uint8_t LISR_HTIF3 = 26;           // Stream x half transfer interrupt flag (x=3..0)
    static const uint8_t LISR_TEIF3 = 25;           // Stream x transfer error interrupt flag (x=3..0)
    static const uint8_t LISR_DMEIF3 = 24;          // Stream x direct mode error interrupt flag (x=3..0)
    static const uint8_t LISR_FEIF3 = 22;           // Stream x FIFO error interrupt flag (x=3..0)
    static const uint8_t LISR_TCIF2 = 21;           // Stream x transfer complete interrupt flag (x = 3..0)
    static const uint8_t LISR_HTIF2 = 20;           // Stream x half transfer interrupt flag (x=3..0)
    static const uint8_t LISR_TEIF2 = 19;           // Stream x transfer error interrupt flag (x=3..0)
    static const uint8_t LISR_DMEIF2 = 18;          // Stream x direct mode error interrupt flag (x=3..0)
    static const uint8_t LISR_FEIF2 = 16;           // Stream x FIFO error interrupt flag (x=3..0)
    static const uint8_t LISR_TCIF1 = 11;           // Stream x transfer complete interrupt flag (x = 3..0)
    static const uint8_t LISR_HTIF1 = 10;           // Stream x half transfer interrupt flag (x=3..0)
    static const uint8_t LISR_TEIF1 = 9;            // Stream x transfer error interrupt flag (x=3..0)
    static const uint8_t LISR_DMEIF1 = 8;           // Stream x direct mode error interrupt flag (x=3..0)
    static const uint8_t LISR_FEIF1 = 6;            // Stream x FIFO error interrupt flag (x=3..0)
    static const uint8_t LISR_TCIF0 = 5;            // Stream x transfer complete interrupt flag (x = 3..0)
    static const uint8_t LISR_HTIF0 = 4;            // Stream x half transfer interrupt flag (x=3..0)
    static const uint8_t LISR_TEIF0 = 3;            // Stream x transfer error interrupt flag (x=3..0)
    static const uint8_t LISR_DMEIF0 = 2;           // Stream x direct mode error interrupt flag (x=3..0)
    static const uint8_t LISR_FEIF0 = 0;            // Stream x FIFO error interrupt flag (x=3..0)
    static const uint32_t LISR_RESET_VALUE = 0x0;

    static const uint8_t HISR_TCIF7 = 27;           // Stream x transfer complete interrupt flag (x=7..4)
    static const uint8_t HISR_HTIF7 = 26;           // Stream x half transfer interrupt flag (x=7..4)
    static const uint8_t HISR_TEIF7 = 25;           // Stream x transfer error interrupt flag (x=7..4)
    static const uint8_t HISR_DMEIF7 = 24;          // Stream x direct mode error interrupt flag (x=7..4)
    static const uint8_t HISR_FEIF7 = 22;           // Stream x FIFO error interrupt flag (x=7..4)
    static const uint8_t HISR_TCIF6 = 21;           // Stream x transfer complete interrupt flag (x=7..4)
    static const uint8_t HISR_HTIF6 = 20;           // Stream x half transfer interrupt flag (x=7..4)
    static const uint8_t HISR_TEIF6 = 19;           // Stream x transfer error interrupt flag (x=7..4)
    static const uint8_t HISR_DMEIF6 = 18;          // Stream x direct mode error interrupt flag (x=7..4)
    static const uint8_t HISR_FEIF6 = 16;           // Stream x FIFO error interrupt flag (x=7..4)
    static const uint8_t HISR_TCIF5 = 11;           // Stream x transfer complete interrupt flag (x=7..4)
    static const uint8_t HISR_HTIF5 = 10;           // Stream x half transfer interrupt flag (x=7..4)
    static const uint8_t HISR_TEIF5 = 9;            // Stream x transfer error interrupt flag (x=7..4)
    static const uint8_t HISR_DMEIF5 = 8;           // Stream x direct mode error interrupt flag (x=7..4)
    static const uint8_t HISR_FEIF5 = 6;            // Stream x FIFO error interrupt flag (x=7..4)
    static const uint8_t HISR_TCIF4 = 5;            // Stream x transfer complete interrupt flag (x=7..4)
    static const uint8_t HISR_HTIF4 = 4;            // Stream x half transfer interrupt flag (x=7..4)
    static const uint8_t HISR_TEIF4 = 3;            // Stream x transfer error interrupt flag (x=7..4)
    static const uint8_t HISR_DMEIF4 = 2;           // Stream x direct mode error interrupt flag (x=7..4)
    static const uint8_t HISR_FEIF4 = 0;            // Stream x FIFO error interrupt flag (x=7..4)
    static const uint32_t HISR_RESET_VALUE = 0x0;

    static const uint8_t LIFCR_CTCIF3 = 27;          // Stream x clear transfer complete interrupt flag (x = 3..0)
    static const uint8_t LIFCR_CHTIF3 = 26;          // Stream x clear half transfer interrupt flag (x = 3..0)
    static const uint8_t LIFCR_CTEIF3 = 25;          // Stream x clear transfer error interrupt flag (x = 3..0)
    static const uint8_t LIFCR_CDMEIF3 = 24;         // Stream x clear direct mode error interrupt flag (x = 3..0)
    static const uint8_t LIFCR_CFEIF3 = 22;          // Stream x clear FIFO error interrupt flag (x = 3..0)
    static const uint8_t LIFCR_CTCIF2 = 21;          // Stream x clear transfer complete interrupt flag (x = 3..0)
    static const uint8_t LIFCR_CHTIF2 = 20;          // Stream x clear half transfer interrupt flag (x = 3..0)
    static const uint8_t LIFCR_CTEIF2 = 19;          // Stream x clear transfer error interrupt flag (x = 3..0)
    static const uint8_t LIFCR_CDMEIF2 = 18;         // Stream x clear direct mode error interrupt flag (x = 3..0)
    static const uint8_t LIFCR_CFEIF2 = 16;          // Stream x clear FIFO error interrupt flag (x = 3..0)
    static const uint8_t LIFCR_CTCIF1 = 11;          // Stream x clear transfer complete interrupt flag (x = 3..0)
    static const uint8_t LIFCR_CHTIF1 = 10;          // Stream x clear half transfer interrupt flag (x = 3..0)
    static const uint8_t LIFCR_CTEIF1 = 9;           // Stream x clear transfer error interrupt flag (x = 3..0)
    static const uint8_t LIFCR_CDMEIF1 = 8;          // Stream x clear direct mode error interrupt flag (x = 3..0)
    static const uint8_t LIFCR_CFEIF1 = 6;           // Stream x clear FIFO error interrupt flag (x = 3..0)
    static const uint8_t LIFCR_CTCIF0 = 5;           // Stream x clear transfer complete interrupt flag (x = 3..0)
    static const uint8_t LIFCR_CHTIF0 = 4;           // Stream x clear half transfer interrupt flag (x = 3..0)
    static const uint8_t LIFCR_CTEIF0 = 3;           // Stream x clear transfer error interrupt flag (x = 3..0)
    static const uint8_t LIFCR_CDMEIF0 = 2;          // Stream x clear direct mode error interrupt flag (x = 3..0)
    static const uint8_t LIFCR_CFEIF0 = 0;           // Stream x clear FIFO error interrupt flag (x = 3..0)
    static const uint32_t LIFCR_RESET_VALUE = 0x0;

    static const uint8_t HIFCR_CTCIF7 = 27;          // Stream x clear transfer complete interrupt flag (x = 7..4)
    static const uint8_t HIFCR_CHTIF7 = 26;          // Stream x clear half transfer interrupt flag (x = 7..4)
    static const uint8_t HIFCR_CTEIF7 = 25;          // Stream x clear transfer error interrupt flag (x = 7..4)
    static const uint8_t HIFCR_CDMEIF7 = 24;         // Stream x clear direct mode error interrupt flag (x = 7..4)
    static const uint8_t HIFCR_CFEIF7 = 22;          // Stream x clear FIFO error interrupt flag (x = 7..4)
    static const uint8_t HIFCR_CTCIF6 = 21;          // Stream x clear transfer complete interrupt flag (x = 7..4)
    static const uint8_t HIFCR_CHTIF6 = 20;          // Stream x clear half transfer interrupt flag (x = 7..4)
    static const uint8_t HIFCR_CTEIF6 = 19;          // Stream x clear transfer error interrupt flag (x = 7..4)
    static const uint8_t HIFCR_CDMEIF6 = 18;         // Stream x clear direct mode error interrupt flag (x = 7..4)
    static const uint8_t HIFCR_CFEIF6 = 16;          // Stream x clear FIFO error interrupt flag (x = 7..4)
    static const uint8_t HIFCR_CTCIF5 = 11;          // Stream x clear transfer complete interrupt flag (x = 7..4)
    static const uint8_t HIFCR_CHTIF5 = 10;          // Stream x clear half transfer interrupt flag (x = 7..4)
    static const uint8_t HIFCR_CTEIF5 = 9;           // Stream x clear transfer error interrupt flag (x = 7..4)
    static const uint8_t HIFCR_CDMEIF5 = 8;          // Stream x clear direct mode error interrupt flag (x = 7..4)
    static const uint8_t HIFCR_CFEIF5 = 6;           // Stream x clear FIFO error interrupt flag (x = 7..4)
    static const uint8_t HIFCR_CTCIF4 = 5;           // Stream x clear transfer complete interrupt flag (x = 7..4)
    static const uint8_t HIFCR_CHTIF4 = 4;           // Stream x clear half transfer interrupt flag (x = 7..4)
    static const uint8_t HIFCR_CTEIF4 = 3;           // Stream x clear transfer error interrupt flag (x = 7..4)
    static const uint8_t HIFCR_CDMEIF4 = 2;          // Stream x clear direct mode error interrupt flag (x = 7..4)
    static const uint8_t HIFCR_CFEIF4 = 0;           // Stream x clear FIFO error interrupt flag (x = 7..4)
    static const uint32_t HIFCR_RESET_VALUE = 0x0;

    static const uint8_t S0CR_CHSEL = 25;           // Channel selection (3 bits)
    static const uint8_t S0CR_MBURST = 23;          // Memory burst transfer configuration (2 bits)
    static const uint8_t S0CR_PBURST = 21;          // Peripheral burst transfer configuration (2 bits)
    static const uint8_t S0CR_CT = 19;              // Current target (only in double buffer mode)
    static const uint8_t S0CR_DBM = 18;             // Double buffer mode
    static const uint8_t S0CR_PL = 16;              // Priority level (2 bits)
    static const uint8_t S0CR_PINCOS = 15;          // Peripheral increment offset size
    static const uint8_t S0CR_MSIZE = 13;           // Memory data size (2 bits)
    static const uint8_t S0CR_PSIZE = 11;           // Peripheral data size (2 bits)
    static const uint8_t S0CR_MINC = 10;            // Memory increment mode
    static const uint8_t S0CR_PINC = 9;             // Peripheral increment mode
    static const uint8_t S0CR_CIRC = 8;             // Circular mode
    static const uint8_t S0CR_DIR = 6;              // Data transfer direction (2 bits)
    static const uint8_t S0CR_PFCTRL = 5;           // Peripheral flow controller
    static const uint8_t S0CR_TCIE = 4;             // Transfer complete interrupt enable
    static const uint8_t S0CR_HTIE = 3;             // Half transfer interrupt enable
    static const uint8_t S0CR_TEIE = 2;             // Transfer error interrupt enable
    static const uint8_t S0CR_DMEIE = 1;            // Direct mode error interrupt enable
    static const uint8_t S0CR_EN = 0;               // Stream enable / flag stream ready when read low
    static const uint32_t S0CR_RESET_VALUE = 0x0;

    static const uint8_t S0NDTR_NDT = 0;              // Number of data items to transfer (16 bits)
    static const uint32_t S0NDTR_RESET_VALUE = 0x0;

    static const uint8_t S0PAR_PA = 0;               // Peripheral address (32 bits)
    static const uint32_t S0PAR_RESET_VALUE = 0x0;

    static const uint8_t S0M0AR_M0A = 0;              // Memory 0 address (32 bits)
    static const uint32_t S0M0AR_RESET_VALUE = 0x0;

    static const uint8_t S0M1AR_M1A = 0;              // Memory 1 address (used in case of Double buffer mode) (32 bits)
    static const uint32_t S0M1AR_RESET_VALUE = 0x0;

    static const uint8_t S0FCR_FEIE = 7;             // FIFO error interrupt enable, Read-write
    static const uint8_t S0FCR_FS = 3;               // FIFO status (3 bits), Read-only
    static const uint8_t S0FCR_DMDIS = 2;            // Direct mode disable, Read-write
    static const uint8_t S0FCR_FTH = 0;              // FIFO threshold selection (2 bits), Read-write
    static const uint32_t S0FCR_RESET_VALUE = 0x21;

    static const uint8_t S1CR_CHSEL = 25;           // Channel selection (3 bits)
    static const uint8_t S1CR_MBURST = 23;          // Memory burst transfer configuration (2 bits)
    static const uint8_t S1CR_PBURST = 21;          // Peripheral burst transfer configuration (2 bits)
    static const uint8_t S1CR_ACK = 20;             // ACK
    static const uint8_t S1CR_CT = 19;              // Current target (only in double buffer mode)
    static const uint8_t S1CR_DBM = 18;             // Double buffer mode
    static const uint8_t S1CR_PL = 16;              // Priority level (2 bits)
    static const uint8_t S1CR_PINCOS = 15;          // Peripheral increment offset size
    static const uint8_t S1CR_MSIZE = 13;           // Memory data size (2 bits)
    static const uint8_t S1CR_PSIZE = 11;           // Peripheral data size (2 bits)
    static const uint8_t S1CR_MINC = 10;            // Memory increment mode
    static const uint8_t S1CR_PINC = 9;             // Peripheral increment mode
    static const uint8_t S1CR_CIRC = 8;             // Circular mode
    static const uint8_t S1CR_DIR = 6;              // Data transfer direction (2 bits)
    static const uint8_t S1CR_PFCTRL = 5;           // Peripheral flow controller
    static const uint8_t S1CR_TCIE = 4;             // Transfer complete interrupt enable
    static const uint8_t S1CR_HTIE = 3;             // Half transfer interrupt enable
    static const uint8_t S1CR_TEIE = 2;             // Transfer error interrupt enable
    static const uint8_t S1CR_DMEIE = 1;            // Direct mode error interrupt enable
    static const uint8_t S1CR_EN = 0;               // Stream enable / flag stream ready when read low
    static const uint32_t S1CR_RESET_VALUE = 0x0;

    static const uint8_t S1NDTR_NDT = 0;              // Number of data items to transfer (16 bits)
    static const uint32_t S1NDTR_RESET_VALUE = 0x0;

    static const uint8_t S1PAR_PA = 0;               // Peripheral address (32 bits)
    static const uint32_t S1PAR_RESET_VALUE = 0x0;

    static const uint8_t S1M0AR_M0A = 0;              // Memory 0 address (32 bits)
    static const uint32_t S1M0AR_RESET_VALUE = 0x0;

    static const uint8_t S1M1AR_M1A = 0;              // Memory 1 address (used in case of Double buffer mode) (32 bits)
    static const uint32_t S1M1AR_RESET_VALUE = 0x0;

    static const uint8_t S1FCR_FEIE = 7;             // FIFO error interrupt enable, Read-write
    static const uint8_t S1FCR_FS = 3;               // FIFO status (3 bits), Read-only
    static const uint8_t S1FCR_DMDIS = 2;            // Direct mode disable, Read-write
    static const uint8_t S1FCR_FTH = 0;              // FIFO threshold selection (2 bits), Read-write
    static const uint32_t S1FCR_RESET_VALUE = 0x21;

    static const uint8_t S2CR_CHSEL = 25;           // Channel selection (3 bits)
    static const uint8_t S2CR_MBURST = 23;          // Memory burst transfer configuration (2 bits)
    static const uint8_t S2CR_PBURST = 21;          // Peripheral burst transfer configuration (2 bits)
    static const uint8_t S2CR_ACK = 20;             // ACK
    static const uint8_t S2CR_CT = 19;              // Current target (only in double buffer mode)
    static const uint8_t S2CR_DBM = 18;             // Double buffer mode
    static const uint8_t S2CR_PL = 16;              // Priority level (2 bits)
    static const uint8_t S2CR_PINCOS = 15;          // Peripheral increment offset size
    static const uint8_t S2CR_MSIZE = 13;           // Memory data size (2 bits)
    static const uint8_t S2CR_PSIZE = 11;           // Peripheral data size (2 bits)
    static const uint8_t S2CR_MINC = 10;            // Memory increment mode
    static const uint8_t S2CR_PINC = 9;             // Peripheral increment mode
    static const uint8_t S2CR_CIRC = 8;             // Circular mode
    static const uint8_t S2CR_DIR = 6;              // Data transfer direction (2 bits)
    static const uint8_t S2CR_PFCTRL = 5;           // Peripheral flow controller
    static const uint8_t S2CR_TCIE = 4;             // Transfer complete interrupt enable
    static const uint8_t S2CR_HTIE = 3;             // Half transfer interrupt enable
    static const uint8_t S2CR_TEIE = 2;             // Transfer error interrupt enable
    static const uint8_t S2CR_DMEIE = 1;            // Direct mode error interrupt enable
    static const uint8_t S2CR_EN = 0;               // Stream enable / flag stream ready when read low
    static const uint32_t S2CR_RESET_VALUE = 0x0;

    static const uint8_t S2NDTR_NDT = 0;              // Number of data items to transfer (16 bits)
    static const uint32_t S2NDTR_RESET_VALUE = 0x0;

    static const uint8_t S2PAR_PA = 0;               // Peripheral address (32 bits)
    static const uint32_t S2PAR_RESET_VALUE = 0x0;

    static const uint8_t S2M0AR_M0A = 0;              // Memory 0 address (32 bits)
    static const uint32_t S2M0AR_RESET_VALUE = 0x0;

    static const uint8_t S2M1AR_M1A = 0;              // Memory 1 address (used in case of Double buffer mode) (32 bits)
    static const uint32_t S2M1AR_RESET_VALUE = 0x0;

    static const uint8_t S2FCR_FEIE = 7;             // FIFO error interrupt enable, Read-write
    static const uint8_t S2FCR_FS = 3;               // FIFO status (3 bits), Read-only
    static const uint8_t S2FCR_DMDIS = 2;            // Direct mode disable, Read-write
    static const uint8_t S2FCR_FTH = 0;              // FIFO threshold selection (2 bits), Read-write
    static const uint32_t S2FCR_RESET_VALUE = 0x21;

    static const uint8_t S3CR_CHSEL = 25;           // Channel selection (3 bits)
    static const uint8_t S3CR_MBURST = 23;          // Memory burst transfer configuration (2 bits)
    static const uint8_t S3CR_PBURST = 21;          // Peripheral burst transfer configuration (2 bits)
    static const uint8_t S3CR_ACK = 20;             // ACK
    static const uint8_t S3CR_CT = 19;              // Current target (only in double buffer mode)
    static const uint8_t S3CR_DBM = 18;             // Double buffer mode
    static const uint8_t S3CR_PL = 16;              // Priority level (2 bits)
    static const uint8_t S3CR_PINCOS = 15;          // Peripheral increment offset size
    static const uint8_t S3CR_MSIZE = 13;           // Memory data size (2 bits)
    static const uint8_t S3CR_PSIZE = 11;           // Peripheral data size (2 bits)
    static const uint8_t S3CR_MINC = 10;            // Memory increment mode
    static const uint8_t S3CR_PINC = 9;             // Peripheral increment mode
    static const uint8_t S3CR_CIRC = 8;             // Circular mode
    static const uint8_t S3CR_DIR = 6;              // Data transfer direction (2 bits)
    static const uint8_t S3CR_PFCTRL = 5;           // Peripheral flow controller
    static const uint8_t S3CR_TCIE = 4;             // Transfer complete interrupt enable
    static const uint8_t S3CR_HTIE = 3;             // Half transfer interrupt enable
    static const uint8_t S3CR_TEIE = 2;             // Transfer error interrupt enable
    static const uint8_t S3CR_DMEIE = 1;            // Direct mode error interrupt enable
    static const uint8_t S3CR_EN = 0;               // Stream enable / flag stream ready when read low
    static const uint32_t S3CR_RESET_VALUE = 0x0;

    static const uint8_t S3NDTR_NDT = 0;              // Number of data items to transfer (16 bits)
    static const uint32_t S3NDTR_RESET_VALUE = 0x0;

    static const uint8_t S3PAR_PA = 0;               // Peripheral address (32 bits)
    static const uint32_t S3PAR_RESET_VALUE = 0x0;

    static const uint8_t S3M0AR_M0A = 0;              // Memory 0 address (32 bits)
    static const uint32_t S3M0AR_RESET_VALUE = 0x0;

    static const uint8_t S3M1AR_M1A = 0;              // Memory 1 address (used in case of Double buffer mode) (32 bits)
    static const uint32_t S3M1AR_RESET_VALUE = 0x0;

    static const uint8_t S3FCR_FEIE = 7;             // FIFO error interrupt enable, Read-write
    static const uint8_t S3FCR_FS = 3;               // FIFO status (3 bits), Read-only
    static const uint8_t S3FCR_DMDIS = 2;            // Direct mode disable, Read-write
    static const uint8_t S3FCR_FTH = 0;              // FIFO threshold selection (2 bits), Read-write
    static const uint32_t S3FCR_RESET_VALUE = 0x21;

    static const uint8_t S4CR_CHSEL = 25;           // Channel selection (3 bits)
    static const uint8_t S4CR_MBURST = 23;          // Memory burst transfer configuration (2 bits)
    static const uint8_t S4CR_PBURST = 21;          // Peripheral burst transfer configuration (2 bits)
    static const uint8_t S4CR_ACK = 20;             // ACK
    static const uint8_t S4CR_CT = 19;              // Current target (only in double buffer mode)
    static const uint8_t S4CR_DBM = 18;             // Double buffer mode
    static const uint8_t S4CR_PL = 16;              // Priority level (2 bits)
    static const uint8_t S4CR_PINCOS = 15;          // Peripheral increment offset size
    static const uint8_t S4CR_MSIZE = 13;           // Memory data size (2 bits)
    static const uint8_t S4CR_PSIZE = 11;           // Peripheral data size (2 bits)
    static const uint8_t S4CR_MINC = 10;            // Memory increment mode
    static const uint8_t S4CR_PINC = 9;             // Peripheral increment mode
    static const uint8_t S4CR_CIRC = 8;             // Circular mode
    static const uint8_t S4CR_DIR = 6;              // Data transfer direction (2 bits)
    static const uint8_t S4CR_PFCTRL = 5;           // Peripheral flow controller
    static const uint8_t S4CR_TCIE = 4;             // Transfer complete interrupt enable
    static const uint8_t S4CR_HTIE = 3;             // Half transfer interrupt enable
    static const uint8_t S4CR_TEIE = 2;             // Transfer error interrupt enable
    static const uint8_t S4CR_DMEIE = 1;            // Direct mode error interrupt enable
    static const uint8_t S4CR_EN = 0;               // Stream enable / flag stream ready when read low
    static const uint32_t S4CR_RESET_VALUE = 0x0;

    static const uint8_t S4NDTR_NDT = 0;              // Number of data items to transfer (16 bits)
    static const uint32_t S4NDTR_RESET_VALUE = 0x0;

    static const uint8_t S4PAR_PA = 0;               // Peripheral address (32 bits)
    static const uint32_t S4PAR_RESET_VALUE = 0x0;

    static const uint8_t S4M0AR_M0A = 0;              // Memory 0 address (32 bits)
    static const uint32_t S4M0AR_RESET_VALUE = 0x0;

    static const uint8_t S4M1AR_M1A = 0;              // Memory 1 address (used in case of Double buffer mode) (32 bits)
    static const uint32_t S4M1AR_RESET_VALUE = 0x0;

    static const uint8_t S4FCR_FEIE = 7;             // FIFO error interrupt enable, Read-write
    static const uint8_t S4FCR_FS = 3;               // FIFO status (3 bits), Read-only
    static const uint8_t S4FCR_DMDIS = 2;            // Direct mode disable, Read-write
    static const uint8_t S4FCR_FTH = 0;              // FIFO threshold selection (2 bits), Read-write
    static const uint32_t S4FCR_RESET_VALUE = 0x21;

    static const uint8_t S5CR_CHSEL = 25;           // Channel selection (3 bits)
    static const uint8_t S5CR_MBURST = 23;          // Memory burst transfer configuration (2 bits)
    static const uint8_t S5CR_PBURST = 21;          // Peripheral burst transfer configuration (2 bits)
    static const uint8_t S5CR_ACK = 20;             // ACK
    static const uint8_t S5CR_CT = 19;              // Current target (only in double buffer mode)
    static const uint8_t S5CR_DBM = 18;             // Double buffer mode
    static const uint8_t S5CR_PL = 16;              // Priority level (2 bits)
    static const uint8_t S5CR_PINCOS = 15;          // Peripheral increment offset size
    static const uint8_t S5CR_MSIZE = 13;           // Memory data size (2 bits)
    static const uint8_t S5CR_PSIZE = 11;           // Peripheral data size (2 bits)
    static const uint8_t S5CR_MINC = 10;            // Memory increment mode
    static const uint8_t S5CR_PINC = 9;             // Peripheral increment mode
    static const uint8_t S5CR_CIRC = 8;             // Circular mode
    static const uint8_t S5CR_DIR = 6;              // Data transfer direction (2 bits)
    static const uint8_t S5CR_PFCTRL = 5;           // Peripheral flow controller
    static const uint8_t S5CR_TCIE = 4;             // Transfer complete interrupt enable
    static const uint8_t S5CR_HTIE = 3;             // Half transfer interrupt enable
    static const uint8_t S5CR_TEIE = 2;             // Transfer error interrupt enable
    static const uint8_t S5CR_DMEIE = 1;            // Direct mode error interrupt enable
    static const uint8_t S5CR_EN = 0;               // Stream enable / flag stream ready when read low
    static const uint32_t S5CR_RESET_VALUE = 0x0;

    static const uint8_t S5NDTR_NDT = 0;              // Number of data items to transfer (16 bits)
    static const uint32_t S5NDTR_RESET_VALUE = 0x0;

    static const uint8_t S5PAR_PA = 0;               // Peripheral address (32 bits)
    static const uint32_t S5PAR_RESET_VALUE = 0x0;

    static const uint8_t S5M0AR_M0A = 0;              // Memory 0 address (32 bits)
    static const uint32_t S5M0AR_RESET_VALUE = 0x0;

    static const uint8_t S5M1AR_M1A = 0;              // Memory 1 address (used in case of Double buffer mode) (32 bits)
    static const uint32_t S5M1AR_RESET_VALUE = 0x0;

    static const uint8_t S5FCR_FEIE = 7;             // FIFO error interrupt enable, Read-write
    static const uint8_t S5FCR_FS = 3;               // FIFO status (3 bits), Read-only
    static const uint8_t S5FCR_DMDIS = 2;            // Direct mode disable, Read-write
    static const uint8_t S5FCR_FTH = 0;              // FIFO threshold selection (2 bits), Read-write
    static const uint32_t S5FCR_RESET_VALUE = 0x21;

    static const uint8_t S6CR_CHSEL = 25;           // Channel selection (3 bits)
    static const uint8_t S6CR_MBURST = 23;          // Memory burst transfer configuration (2 bits)
    static const uint8_t S6CR_PBURST = 21;          // Peripheral burst transfer configuration (2 bits)
    static const uint8_t S6CR_ACK = 20;             // ACK
    static const uint8_t S6CR_CT = 19;              // Current target (only in double buffer mode)
    static const uint8_t S6CR_DBM = 18;             // Double buffer mode
    static const uint8_t S6CR_PL = 16;              // Priority level (2 bits)
    static const uint8_t S6CR_PINCOS = 15;          // Peripheral increment offset size
    static const uint8_t S6CR_MSIZE = 13;           // Memory data size (2 bits)
    static const uint8_t S6CR_PSIZE = 11;           // Peripheral data size (2 bits)
    static const uint8_t S6CR_MINC = 10;            // Memory increment mode
    static const uint8_t S6CR_PINC = 9;             // Peripheral increment mode
    static const uint8_t S6CR_CIRC = 8;             // Circular mode
    static const uint8_t S6CR_DIR = 6;              // Data transfer direction (2 bits)
    static const uint8_t S6CR_PFCTRL = 5;           // Peripheral flow controller
    static const uint8_t S6CR_TCIE = 4;             // Transfer complete interrupt enable
    static const uint8_t S6CR_HTIE = 3;             // Half transfer interrupt enable
    static const uint8_t S6CR_TEIE = 2;             // Transfer error interrupt enable
    static const uint8_t S6CR_DMEIE = 1;            // Direct mode error interrupt enable
    static const uint8_t S6CR_EN = 0;               // Stream enable / flag stream ready when read low
    static const uint32_t S6CR_RESET_VALUE = 0x0;

    static const uint8_t S6NDTR_NDT = 0;              // Number of data items to transfer (16 bits)
    static const uint32_t S6NDTR_RESET_VALUE = 0x0;

    static const uint8_t S6PAR_PA = 0;               // Peripheral address (32 bits)
    static const uint32_t S6PAR_RESET_VALUE = 0x0;

    static const uint8_t S6M0AR_M0A = 0;              // Memory 0 address (32 bits)
    static const uint32_t S6M0AR_RESET_VALUE = 0x0;

    static const uint8_t S6M1AR_M1A = 0;              // Memory 1 address (used in case of Double buffer mode) (32 bits)
    static const uint32_t S6M1AR_RESET_VALUE = 0x0;

    static const uint8_t S6FCR_FEIE = 7;             // FIFO error interrupt enable, Read-write
    static const uint8_t S6FCR_FS = 3;               // FIFO status (3 bits), Read-only
    static const uint8_t S6FCR_DMDIS = 2;            // Direct mode disable, Read-write
    static const uint8_t S6FCR_FTH = 0;              // FIFO threshold selection (2 bits), Read-write
    static const uint32_t S6FCR_RESET_VALUE = 0x21;

    static const uint8_t S7CR_CHSEL = 25;           // Channel selection (3 bits)
    static const uint8_t S7CR_MBURST = 23;          // Memory burst transfer configuration (2 bits)
    static const uint8_t S7CR_PBURST = 21;          // Peripheral burst transfer configuration (2 bits)
    static const uint8_t S7CR_ACK = 20;             // ACK
    static const uint8_t S7CR_CT = 19;              // Current target (only in double buffer mode)
    static const uint8_t S7CR_DBM = 18;             // Double buffer mode
    static const uint8_t S7CR_PL = 16;              // Priority level (2 bits)
    static const uint8_t S7CR_PINCOS = 15;          // Peripheral increment offset size
    static const uint8_t S7CR_MSIZE = 13;           // Memory data size (2 bits)
    static const uint8_t S7CR_PSIZE = 11;           // Peripheral data size (2 bits)
    static const uint8_t S7CR_MINC = 10;            // Memory increment mode
    static const uint8_t S7CR_PINC = 9;             // Peripheral increment mode
    static const uint8_t S7CR_CIRC = 8;             // Circular mode
    static const uint8_t S7CR_DIR = 6;              // Data transfer direction (2 bits)
    static const uint8_t S7CR_PFCTRL = 5;           // Peripheral flow controller
    static const uint8_t S7CR_TCIE = 4;             // Transfer complete interrupt enable
    static const uint8_t S7CR_HTIE = 3;             // Half transfer interrupt enable
    static const uint8_t S7CR_TEIE = 2;             // Transfer error interrupt enable
    static const uint8_t S7CR_DMEIE = 1;            // Direct mode error interrupt enable
    static const uint8_t S7CR_EN = 0;               // Stream enable / flag stream ready when read low
    static const uint32_t S7CR_RESET_VALUE = 0x0;

    static const uint8_t S7NDTR_NDT = 0;              // Number of data items to transfer (16 bits)
    static const uint32_t S7NDTR_RESET_VALUE = 0x0;

    static const uint8_t S7PAR_PA = 0;               // Peripheral address (32 bits)
    static const uint32_t S7PAR_RESET_VALUE = 0x0;

    static const uint8_t S7M0AR_M0A = 0;              // Memory 0 address (32 bits)
    static const uint32_t S7M0AR_RESET_VALUE = 0x0;

    static const uint8_t S7M1AR_M1A = 0;              // Memory 1 address (used in case of Double buffer mode) (32 bits)
    static const uint32_t S7M1AR_RESET_VALUE = 0x0;

    static const uint8_t S7FCR_FEIE = 7;             // FIFO error interrupt enable, Read-write
    static const uint8_t S7FCR_FS = 3;               // FIFO status (3 bits), Read-only
    static const uint8_t S7FCR_DMDIS = 2;            // Direct mode disable, Read-write
    static const uint8_t S7FCR_FTH = 0;              // FIFO threshold selection (2 bits), Read-write
    static const uint32_t S7FCR_RESET_VALUE = 0x21;
};

static dma2_t& DMA2 = *reinterpret_cast<dma2_t*>(0x40026400);


////
//
//    DMA controller
//
////

struct dma1_t
{
    volatile uint32_t    LISR;                 // [Read-only] low interrupt status register
    volatile uint32_t    HISR;                 // [Read-only] high interrupt status register
    volatile uint32_t    LIFCR;                // [Write-only] low interrupt flag clear register
    volatile uint32_t    HIFCR;                // [Write-only] high interrupt flag clear register
    volatile uint32_t    S0CR;                 // [Read-write] stream x configuration register
    volatile uint32_t    S0NDTR;               // [Read-write] stream x number of data register
    volatile uint32_t    S0PAR;                // [Read-write] stream x peripheral address register
    volatile uint32_t    S0M0AR;               // [Read-write] stream x memory 0 address register
    volatile uint32_t    S0M1AR;               // [Read-write] stream x memory 1 address register
    volatile uint32_t    S0FCR;                // stream x FIFO control register
    volatile uint32_t    S1CR;                 // [Read-write] stream x configuration register
    volatile uint32_t    S1NDTR;               // [Read-write] stream x number of data register
    volatile uint32_t    S1PAR;                // [Read-write] stream x peripheral address register
    volatile uint32_t    S1M0AR;               // [Read-write] stream x memory 0 address register
    volatile uint32_t    S1M1AR;               // [Read-write] stream x memory 1 address register
    volatile uint32_t    S1FCR;                // stream x FIFO control register
    volatile uint32_t    S2CR;                 // [Read-write] stream x configuration register
    volatile uint32_t    S2NDTR;               // [Read-write] stream x number of data register
    volatile uint32_t    S2PAR;                // [Read-write] stream x peripheral address register
    volatile uint32_t    S2M0AR;               // [Read-write] stream x memory 0 address register
    volatile uint32_t    S2M1AR;               // [Read-write] stream x memory 1 address register
    volatile uint32_t    S2FCR;                // stream x FIFO control register
    volatile uint32_t    S3CR;                 // [Read-write] stream x configuration register
    volatile uint32_t    S3NDTR;               // [Read-write] stream x number of data register
    volatile uint32_t    S3PAR;                // [Read-write] stream x peripheral address register
    volatile uint32_t    S3M0AR;               // [Read-write] stream x memory 0 address register
    volatile uint32_t    S3M1AR;               // [Read-write] stream x memory 1 address register
    volatile uint32_t    S3FCR;                // stream x FIFO control register
    volatile uint32_t    S4CR;                 // [Read-write] stream x configuration register
    volatile uint32_t    S4NDTR;               // [Read-write] stream x number of data register
    volatile uint32_t    S4PAR;                // [Read-write] stream x peripheral address register
    volatile uint32_t    S4M0AR;               // [Read-write] stream x memory 0 address register
    volatile uint32_t    S4M1AR;               // [Read-write] stream x memory 1 address register
    volatile uint32_t    S4FCR;                // stream x FIFO control register
    volatile uint32_t    S5CR;                 // [Read-write] stream x configuration register
    volatile uint32_t    S5NDTR;               // [Read-write] stream x number of data register
    volatile uint32_t    S5PAR;                // [Read-write] stream x peripheral address register
    volatile uint32_t    S5M0AR;               // [Read-write] stream x memory 0 address register
    volatile uint32_t    S5M1AR;               // [Read-write] stream x memory 1 address register
    volatile uint32_t    S5FCR;                // stream x FIFO control register
    volatile uint32_t    S6CR;                 // [Read-write] stream x configuration register
    volatile uint32_t    S6NDTR;               // [Read-write] stream x number of data register
    volatile uint32_t    S6PAR;                // [Read-write] stream x peripheral address register
    volatile uint32_t    S6M0AR;               // [Read-write] stream x memory 0 address register
    volatile uint32_t    S6M1AR;               // [Read-write] stream x memory 1 address register
    volatile uint32_t    S6FCR;                // stream x FIFO control register
    volatile uint32_t    S7CR;                 // [Read-write] stream x configuration register
    volatile uint32_t    S7NDTR;               // [Read-write] stream x number of data register
    volatile uint32_t    S7PAR;                // [Read-write] stream x peripheral address register
    volatile uint32_t    S7M0AR;               // [Read-write] stream x memory 0 address register
    volatile uint32_t    S7M1AR;               // [Read-write] stream x memory 1 address register
    volatile uint32_t    S7FCR;                // stream x FIFO control register

    static const uint8_t LISR_TCIF3 = 27;           // Stream x transfer complete interrupt flag (x = 3..0)
    static const uint8_t LISR_HTIF3 = 26;           // Stream x half transfer interrupt flag (x=3..0)
    static const uint8_t LISR_TEIF3 = 25;           // Stream x transfer error interrupt flag (x=3..0)
    static const uint8_t LISR_DMEIF3 = 24;          // Stream x direct mode error interrupt flag (x=3..0)
    static const uint8_t LISR_FEIF3 = 22;           // Stream x FIFO error interrupt flag (x=3..0)
    static const uint8_t LISR_TCIF2 = 21;           // Stream x transfer complete interrupt flag (x = 3..0)
    static const uint8_t LISR_HTIF2 = 20;           // Stream x half transfer interrupt flag (x=3..0)
    static const uint8_t LISR_TEIF2 = 19;           // Stream x transfer error interrupt flag (x=3..0)
    static const uint8_t LISR_DMEIF2 = 18;          // Stream x direct mode error interrupt flag (x=3..0)
    static const uint8_t LISR_FEIF2 = 16;           // Stream x FIFO error interrupt flag (x=3..0)
    static const uint8_t LISR_TCIF1 = 11;           // Stream x transfer complete interrupt flag (x = 3..0)
    static const uint8_t LISR_HTIF1 = 10;           // Stream x half transfer interrupt flag (x=3..0)
    static const uint8_t LISR_TEIF1 = 9;            // Stream x transfer error interrupt flag (x=3..0)
    static const uint8_t LISR_DMEIF1 = 8;           // Stream x direct mode error interrupt flag (x=3..0)
    static const uint8_t LISR_FEIF1 = 6;            // Stream x FIFO error interrupt flag (x=3..0)
    static const uint8_t LISR_TCIF0 = 5;            // Stream x transfer complete interrupt flag (x = 3..0)
    static const uint8_t LISR_HTIF0 = 4;            // Stream x half transfer interrupt flag (x=3..0)
    static const uint8_t LISR_TEIF0 = 3;            // Stream x transfer error interrupt flag (x=3..0)
    static const uint8_t LISR_DMEIF0 = 2;           // Stream x direct mode error interrupt flag (x=3..0)
    static const uint8_t LISR_FEIF0 = 0;            // Stream x FIFO error interrupt flag (x=3..0)
    static const uint32_t LISR_RESET_VALUE = 0x0;

    static const uint8_t HISR_TCIF7 = 27;           // Stream x transfer complete interrupt flag (x=7..4)
    static const uint8_t HISR_HTIF7 = 26;           // Stream x half transfer interrupt flag (x=7..4)
    static const uint8_t HISR_TEIF7 = 25;           // Stream x transfer error interrupt flag (x=7..4)
    static const uint8_t HISR_DMEIF7 = 24;          // Stream x direct mode error interrupt flag (x=7..4)
    static const uint8_t HISR_FEIF7 = 22;           // Stream x FIFO error interrupt flag (x=7..4)
    static const uint8_t HISR_TCIF6 = 21;           // Stream x transfer complete interrupt flag (x=7..4)
    static const uint8_t HISR_HTIF6 = 20;           // Stream x half transfer interrupt flag (x=7..4)
    static const uint8_t HISR_TEIF6 = 19;           // Stream x transfer error interrupt flag (x=7..4)
    static const uint8_t HISR_DMEIF6 = 18;          // Stream x direct mode error interrupt flag (x=7..4)
    static const uint8_t HISR_FEIF6 = 16;           // Stream x FIFO error interrupt flag (x=7..4)
    static const uint8_t HISR_TCIF5 = 11;           // Stream x transfer complete interrupt flag (x=7..4)
    static const uint8_t HISR_HTIF5 = 10;           // Stream x half transfer interrupt flag (x=7..4)
    static const uint8_t HISR_TEIF5 = 9;            // Stream x transfer error interrupt flag (x=7..4)
    static const uint8_t HISR_DMEIF5 = 8;           // Stream x direct mode error interrupt flag (x=7..4)
    static const uint8_t HISR_FEIF5 = 6;            // Stream x FIFO error interrupt flag (x=7..4)
    static const uint8_t HISR_TCIF4 = 5;            // Stream x transfer complete interrupt flag (x=7..4)
    static const uint8_t HISR_HTIF4 = 4;            // Stream x half transfer interrupt flag (x=7..4)
    static const uint8_t HISR_TEIF4 = 3;            // Stream x transfer error interrupt flag (x=7..4)
    static const uint8_t HISR_DMEIF4 = 2;           // Stream x direct mode error interrupt flag (x=7..4)
    static const uint8_t HISR_FEIF4 = 0;            // Stream x FIFO error interrupt flag (x=7..4)
    static const uint32_t HISR_RESET_VALUE = 0x0;

    static const uint8_t LIFCR_CTCIF3 = 27;          // Stream x clear transfer complete interrupt flag (x = 3..0)
    static const uint8_t LIFCR_CHTIF3 = 26;          // Stream x clear half transfer interrupt flag (x = 3..0)
    static const uint8_t LIFCR_CTEIF3 = 25;          // Stream x clear transfer error interrupt flag (x = 3..0)
    static const uint8_t LIFCR_CDMEIF3 = 24;         // Stream x clear direct mode error interrupt flag (x = 3..0)
    static const uint8_t LIFCR_CFEIF3 = 22;          // Stream x clear FIFO error interrupt flag (x = 3..0)
    static const uint8_t LIFCR_CTCIF2 = 21;          // Stream x clear transfer complete interrupt flag (x = 3..0)
    static const uint8_t LIFCR_CHTIF2 = 20;          // Stream x clear half transfer interrupt flag (x = 3..0)
    static const uint8_t LIFCR_CTEIF2 = 19;          // Stream x clear transfer error interrupt flag (x = 3..0)
    static const uint8_t LIFCR_CDMEIF2 = 18;         // Stream x clear direct mode error interrupt flag (x = 3..0)
    static const uint8_t LIFCR_CFEIF2 = 16;          // Stream x clear FIFO error interrupt flag (x = 3..0)
    static const uint8_t LIFCR_CTCIF1 = 11;          // Stream x clear transfer complete interrupt flag (x = 3..0)
    static const uint8_t LIFCR_CHTIF1 = 10;          // Stream x clear half transfer interrupt flag (x = 3..0)
    static const uint8_t LIFCR_CTEIF1 = 9;           // Stream x clear transfer error interrupt flag (x = 3..0)
    static const uint8_t LIFCR_CDMEIF1 = 8;          // Stream x clear direct mode error interrupt flag (x = 3..0)
    static const uint8_t LIFCR_CFEIF1 = 6;           // Stream x clear FIFO error interrupt flag (x = 3..0)
    static const uint8_t LIFCR_CTCIF0 = 5;           // Stream x clear transfer complete interrupt flag (x = 3..0)
    static const uint8_t LIFCR_CHTIF0 = 4;           // Stream x clear half transfer interrupt flag (x = 3..0)
    static const uint8_t LIFCR_CTEIF0 = 3;           // Stream x clear transfer error interrupt flag (x = 3..0)
    static const uint8_t LIFCR_CDMEIF0 = 2;          // Stream x clear direct mode error interrupt flag (x = 3..0)
    static const uint8_t LIFCR_CFEIF0 = 0;           // Stream x clear FIFO error interrupt flag (x = 3..0)
    static const uint32_t LIFCR_RESET_VALUE = 0x0;

    static const uint8_t HIFCR_CTCIF7 = 27;          // Stream x clear transfer complete interrupt flag (x = 7..4)
    static const uint8_t HIFCR_CHTIF7 = 26;          // Stream x clear half transfer interrupt flag (x = 7..4)
    static const uint8_t HIFCR_CTEIF7 = 25;          // Stream x clear transfer error interrupt flag (x = 7..4)
    static const uint8_t HIFCR_CDMEIF7 = 24;         // Stream x clear direct mode error interrupt flag (x = 7..4)
    static const uint8_t HIFCR_CFEIF7 = 22;          // Stream x clear FIFO error interrupt flag (x = 7..4)
    static const uint8_t HIFCR_CTCIF6 = 21;          // Stream x clear transfer complete interrupt flag (x = 7..4)
    static const uint8_t HIFCR_CHTIF6 = 20;          // Stream x clear half transfer interrupt flag (x = 7..4)
    static const uint8_t HIFCR_CTEIF6 = 19;          // Stream x clear transfer error interrupt flag (x = 7..4)
    static const uint8_t HIFCR_CDMEIF6 = 18;         // Stream x clear direct mode error interrupt flag (x = 7..4)
    static const uint8_t HIFCR_CFEIF6 = 16;          // Stream x clear FIFO error interrupt flag (x = 7..4)
    static const uint8_t HIFCR_CTCIF5 = 11;          // Stream x clear transfer complete interrupt flag (x = 7..4)
    static const uint8_t HIFCR_CHTIF5 = 10;          // Stream x clear half transfer interrupt flag (x = 7..4)
    static const uint8_t HIFCR_CTEIF5 = 9;           // Stream x clear transfer error interrupt flag (x = 7..4)
    static const uint8_t HIFCR_CDMEIF5 = 8;          // Stream x clear direct mode error interrupt flag (x = 7..4)
    static const uint8_t HIFCR_CFEIF5 = 6;           // Stream x clear FIFO error interrupt flag (x = 7..4)
    static const uint8_t HIFCR_CTCIF4 = 5;           // Stream x clear transfer complete interrupt flag (x = 7..4)
    static const uint8_t HIFCR_CHTIF4 = 4;           // Stream x clear half transfer interrupt flag (x = 7..4)
    static const uint8_t HIFCR_CTEIF4 = 3;           // Stream x clear transfer error interrupt flag (x = 7..4)
    static const uint8_t HIFCR_CDMEIF4 = 2;          // Stream x clear direct mode error interrupt flag (x = 7..4)
    static const uint8_t HIFCR_CFEIF4 = 0;           // Stream x clear FIFO error interrupt flag (x = 7..4)
    static const uint32_t HIFCR_RESET_VALUE = 0x0;

    static const uint8_t S0CR_CHSEL = 25;           // Channel selection (3 bits)
    static const uint8_t S0CR_MBURST = 23;          // Memory burst transfer configuration (2 bits)
    static const uint8_t S0CR_PBURST = 21;          // Peripheral burst transfer configuration (2 bits)
    static const uint8_t S0CR_CT = 19;              // Current target (only in double buffer mode)
    static const uint8_t S0CR_DBM = 18;             // Double buffer mode
    static const uint8_t S0CR_PL = 16;              // Priority level (2 bits)
    static const uint8_t S0CR_PINCOS = 15;          // Peripheral increment offset size
    static const uint8_t S0CR_MSIZE = 13;           // Memory data size (2 bits)
    static const uint8_t S0CR_PSIZE = 11;           // Peripheral data size (2 bits)
    static const uint8_t S0CR_MINC = 10;            // Memory increment mode
    static const uint8_t S0CR_PINC = 9;             // Peripheral increment mode
    static const uint8_t S0CR_CIRC = 8;             // Circular mode
    static const uint8_t S0CR_DIR = 6;              // Data transfer direction (2 bits)
    static const uint8_t S0CR_PFCTRL = 5;           // Peripheral flow controller
    static const uint8_t S0CR_TCIE = 4;             // Transfer complete interrupt enable
    static const uint8_t S0CR_HTIE = 3;             // Half transfer interrupt enable
    static const uint8_t S0CR_TEIE = 2;             // Transfer error interrupt enable
    static const uint8_t S0CR_DMEIE = 1;            // Direct mode error interrupt enable
    static const uint8_t S0CR_EN = 0;               // Stream enable / flag stream ready when read low
    static const uint32_t S0CR_RESET_VALUE = 0x0;

    static const uint8_t S0NDTR_NDT = 0;              // Number of data items to transfer (16 bits)
    static const uint32_t S0NDTR_RESET_VALUE = 0x0;

    static const uint8_t S0PAR_PA = 0;               // Peripheral address (32 bits)
    static const uint32_t S0PAR_RESET_VALUE = 0x0;

    static const uint8_t S0M0AR_M0A = 0;              // Memory 0 address (32 bits)
    static const uint32_t S0M0AR_RESET_VALUE = 0x0;

    static const uint8_t S0M1AR_M1A = 0;              // Memory 1 address (used in case of Double buffer mode) (32 bits)
    static const uint32_t S0M1AR_RESET_VALUE = 0x0;

    static const uint8_t S0FCR_FEIE = 7;             // FIFO error interrupt enable, Read-write
    static const uint8_t S0FCR_FS = 3;               // FIFO status (3 bits), Read-only
    static const uint8_t S0FCR_DMDIS = 2;            // Direct mode disable, Read-write
    static const uint8_t S0FCR_FTH = 0;              // FIFO threshold selection (2 bits), Read-write
    static const uint32_t S0FCR_RESET_VALUE = 0x21;

    static const uint8_t S1CR_CHSEL = 25;           // Channel selection (3 bits)
    static const uint8_t S1CR_MBURST = 23;          // Memory burst transfer configuration (2 bits)
    static const uint8_t S1CR_PBURST = 21;          // Peripheral burst transfer configuration (2 bits)
    static const uint8_t S1CR_ACK = 20;             // ACK
    static const uint8_t S1CR_CT = 19;              // Current target (only in double buffer mode)
    static const uint8_t S1CR_DBM = 18;             // Double buffer mode
    static const uint8_t S1CR_PL = 16;              // Priority level (2 bits)
    static const uint8_t S1CR_PINCOS = 15;          // Peripheral increment offset size
    static const uint8_t S1CR_MSIZE = 13;           // Memory data size (2 bits)
    static const uint8_t S1CR_PSIZE = 11;           // Peripheral data size (2 bits)
    static const uint8_t S1CR_MINC = 10;            // Memory increment mode
    static const uint8_t S1CR_PINC = 9;             // Peripheral increment mode
    static const uint8_t S1CR_CIRC = 8;             // Circular mode
    static const uint8_t S1CR_DIR = 6;              // Data transfer direction (2 bits)
    static const uint8_t S1CR_PFCTRL = 5;           // Peripheral flow controller
    static const uint8_t S1CR_TCIE = 4;             // Transfer complete interrupt enable
    static const uint8_t S1CR_HTIE = 3;             // Half transfer interrupt enable
    static const uint8_t S1CR_TEIE = 2;             // Transfer error interrupt enable
    static const uint8_t S1CR_DMEIE = 1;            // Direct mode error interrupt enable
    static const uint8_t S1CR_EN = 0;               // Stream enable / flag stream ready when read low
    static const uint32_t S1CR_RESET_VALUE = 0x0;

    static const uint8_t S1NDTR_NDT = 0;              // Number of data items to transfer (16 bits)
    static const uint32_t S1NDTR_RESET_VALUE = 0x0;

    static const uint8_t S1PAR_PA = 0;               // Peripheral address (32 bits)
    static const uint32_t S1PAR_RESET_VALUE = 0x0;

    static const uint8_t S1M0AR_M0A = 0;              // Memory 0 address (32 bits)
    static const uint32_t S1M0AR_RESET_VALUE = 0x0;

    static const uint8_t S1M1AR_M1A = 0;              // Memory 1 address (used in case of Double buffer mode) (32 bits)
    static const uint32_t S1M1AR_RESET_VALUE = 0x0;

    static const uint8_t S1FCR_FEIE = 7;             // FIFO error interrupt enable, Read-write
    static const uint8_t S1FCR_FS = 3;               // FIFO status (3 bits), Read-only
    static const uint8_t S1FCR_DMDIS = 2;            // Direct mode disable, Read-write
    static const uint8_t S1FCR_FTH = 0;              // FIFO threshold selection (2 bits), Read-write
    static const uint32_t S1FCR_RESET_VALUE = 0x21;

    static const uint8_t S2CR_CHSEL = 25;           // Channel selection (3 bits)
    static const uint8_t S2CR_MBURST = 23;          // Memory burst transfer configuration (2 bits)
    static const uint8_t S2CR_PBURST = 21;          // Peripheral burst transfer configuration (2 bits)
    static const uint8_t S2CR_ACK = 20;             // ACK
    static const uint8_t S2CR_CT = 19;              // Current target (only in double buffer mode)
    static const uint8_t S2CR_DBM = 18;             // Double buffer mode
    static const uint8_t S2CR_PL = 16;              // Priority level (2 bits)
    static const uint8_t S2CR_PINCOS = 15;          // Peripheral increment offset size
    static const uint8_t S2CR_MSIZE = 13;           // Memory data size (2 bits)
    static const uint8_t S2CR_PSIZE = 11;           // Peripheral data size (2 bits)
    static const uint8_t S2CR_MINC = 10;            // Memory increment mode
    static const uint8_t S2CR_PINC = 9;             // Peripheral increment mode
    static const uint8_t S2CR_CIRC = 8;             // Circular mode
    static const uint8_t S2CR_DIR = 6;              // Data transfer direction (2 bits)
    static const uint8_t S2CR_PFCTRL = 5;           // Peripheral flow controller
    static const uint8_t S2CR_TCIE = 4;             // Transfer complete interrupt enable
    static const uint8_t S2CR_HTIE = 3;             // Half transfer interrupt enable
    static const uint8_t S2CR_TEIE = 2;             // Transfer error interrupt enable
    static const uint8_t S2CR_DMEIE = 1;            // Direct mode error interrupt enable
    static const uint8_t S2CR_EN = 0;               // Stream enable / flag stream ready when read low
    static const uint32_t S2CR_RESET_VALUE = 0x0;

    static const uint8_t S2NDTR_NDT = 0;              // Number of data items to transfer (16 bits)
    static const uint32_t S2NDTR_RESET_VALUE = 0x0;

    static const uint8_t S2PAR_PA = 0;               // Peripheral address (32 bits)
    static const uint32_t S2PAR_RESET_VALUE = 0x0;

    static const uint8_t S2M0AR_M0A = 0;              // Memory 0 address (32 bits)
    static const uint32_t S2M0AR_RESET_VALUE = 0x0;

    static const uint8_t S2M1AR_M1A = 0;              // Memory 1 address (used in case of Double buffer mode) (32 bits)
    static const uint32_t S2M1AR_RESET_VALUE = 0x0;

    static const uint8_t S2FCR_FEIE = 7;             // FIFO error interrupt enable, Read-write
    static const uint8_t S2FCR_FS = 3;               // FIFO status (3 bits), Read-only
    static const uint8_t S2FCR_DMDIS = 2;            // Direct mode disable, Read-write
    static const uint8_t S2FCR_FTH = 0;              // FIFO threshold selection (2 bits), Read-write
    static const uint32_t S2FCR_RESET_VALUE = 0x21;

    static const uint8_t S3CR_CHSEL = 25;           // Channel selection (3 bits)
    static const uint8_t S3CR_MBURST = 23;          // Memory burst transfer configuration (2 bits)
    static const uint8_t S3CR_PBURST = 21;          // Peripheral burst transfer configuration (2 bits)
    static const uint8_t S3CR_ACK = 20;             // ACK
    static const uint8_t S3CR_CT = 19;              // Current target (only in double buffer mode)
    static const uint8_t S3CR_DBM = 18;             // Double buffer mode
    static const uint8_t S3CR_PL = 16;              // Priority level (2 bits)
    static const uint8_t S3CR_PINCOS = 15;          // Peripheral increment offset size
    static const uint8_t S3CR_MSIZE = 13;           // Memory data size (2 bits)
    static const uint8_t S3CR_PSIZE = 11;           // Peripheral data size (2 bits)
    static const uint8_t S3CR_MINC = 10;            // Memory increment mode
    static const uint8_t S3CR_PINC = 9;             // Peripheral increment mode
    static const uint8_t S3CR_CIRC = 8;             // Circular mode
    static const uint8_t S3CR_DIR = 6;              // Data transfer direction (2 bits)
    static const uint8_t S3CR_PFCTRL = 5;           // Peripheral flow controller
    static const uint8_t S3CR_TCIE = 4;             // Transfer complete interrupt enable
    static const uint8_t S3CR_HTIE = 3;             // Half transfer interrupt enable
    static const uint8_t S3CR_TEIE = 2;             // Transfer error interrupt enable
    static const uint8_t S3CR_DMEIE = 1;            // Direct mode error interrupt enable
    static const uint8_t S3CR_EN = 0;               // Stream enable / flag stream ready when read low
    static const uint32_t S3CR_RESET_VALUE = 0x0;

    static const uint8_t S3NDTR_NDT = 0;              // Number of data items to transfer (16 bits)
    static const uint32_t S3NDTR_RESET_VALUE = 0x0;

    static const uint8_t S3PAR_PA = 0;               // Peripheral address (32 bits)
    static const uint32_t S3PAR_RESET_VALUE = 0x0;

    static const uint8_t S3M0AR_M0A = 0;              // Memory 0 address (32 bits)
    static const uint32_t S3M0AR_RESET_VALUE = 0x0;

    static const uint8_t S3M1AR_M1A = 0;              // Memory 1 address (used in case of Double buffer mode) (32 bits)
    static const uint32_t S3M1AR_RESET_VALUE = 0x0;

    static const uint8_t S3FCR_FEIE = 7;             // FIFO error interrupt enable, Read-write
    static const uint8_t S3FCR_FS = 3;               // FIFO status (3 bits), Read-only
    static const uint8_t S3FCR_DMDIS = 2;            // Direct mode disable, Read-write
    static const uint8_t S3FCR_FTH = 0;              // FIFO threshold selection (2 bits), Read-write
    static const uint32_t S3FCR_RESET_VALUE = 0x21;

    static const uint8_t S4CR_CHSEL = 25;           // Channel selection (3 bits)
    static const uint8_t S4CR_MBURST = 23;          // Memory burst transfer configuration (2 bits)
    static const uint8_t S4CR_PBURST = 21;          // Peripheral burst transfer configuration (2 bits)
    static const uint8_t S4CR_ACK = 20;             // ACK
    static const uint8_t S4CR_CT = 19;              // Current target (only in double buffer mode)
    static const uint8_t S4CR_DBM = 18;             // Double buffer mode
    static const uint8_t S4CR_PL = 16;              // Priority level (2 bits)
    static const uint8_t S4CR_PINCOS = 15;          // Peripheral increment offset size
    static const uint8_t S4CR_MSIZE = 13;           // Memory data size (2 bits)
    static const uint8_t S4CR_PSIZE = 11;           // Peripheral data size (2 bits)
    static const uint8_t S4CR_MINC = 10;            // Memory increment mode
    static const uint8_t S4CR_PINC = 9;             // Peripheral increment mode
    static const uint8_t S4CR_CIRC = 8;             // Circular mode
    static const uint8_t S4CR_DIR = 6;              // Data transfer direction (2 bits)
    static const uint8_t S4CR_PFCTRL = 5;           // Peripheral flow controller
    static const uint8_t S4CR_TCIE = 4;             // Transfer complete interrupt enable
    static const uint8_t S4CR_HTIE = 3;             // Half transfer interrupt enable
    static const uint8_t S4CR_TEIE = 2;             // Transfer error interrupt enable
    static const uint8_t S4CR_DMEIE = 1;            // Direct mode error interrupt enable
    static const uint8_t S4CR_EN = 0;               // Stream enable / flag stream ready when read low
    static const uint32_t S4CR_RESET_VALUE = 0x0;

    static const uint8_t S4NDTR_NDT = 0;              // Number of data items to transfer (16 bits)
    static const uint32_t S4NDTR_RESET_VALUE = 0x0;

    static const uint8_t S4PAR_PA = 0;               // Peripheral address (32 bits)
    static const uint32_t S4PAR_RESET_VALUE = 0x0;

    static const uint8_t S4M0AR_M0A = 0;              // Memory 0 address (32 bits)
    static const uint32_t S4M0AR_RESET_VALUE = 0x0;

    static const uint8_t S4M1AR_M1A = 0;              // Memory 1 address (used in case of Double buffer mode) (32 bits)
    static const uint32_t S4M1AR_RESET_VALUE = 0x0;

    static const uint8_t S4FCR_FEIE = 7;             // FIFO error interrupt enable, Read-write
    static const uint8_t S4FCR_FS = 3;               // FIFO status (3 bits), Read-only
    static const uint8_t S4FCR_DMDIS = 2;            // Direct mode disable, Read-write
    static const uint8_t S4FCR_FTH = 0;              // FIFO threshold selection (2 bits), Read-write
    static const uint32_t S4FCR_RESET_VALUE = 0x21;

    static const uint8_t S5CR_CHSEL = 25;           // Channel selection (3 bits)
    static const uint8_t S5CR_MBURST = 23;          // Memory burst transfer configuration (2 bits)
    static const uint8_t S5CR_PBURST = 21;          // Peripheral burst transfer configuration (2 bits)
    static const uint8_t S5CR_ACK = 20;             // ACK
    static const uint8_t S5CR_CT = 19;              // Current target (only in double buffer mode)
    static const uint8_t S5CR_DBM = 18;             // Double buffer mode
    static const uint8_t S5CR_PL = 16;              // Priority level (2 bits)
    static const uint8_t S5CR_PINCOS = 15;          // Peripheral increment offset size
    static const uint8_t S5CR_MSIZE = 13;           // Memory data size (2 bits)
    static const uint8_t S5CR_PSIZE = 11;           // Peripheral data size (2 bits)
    static const uint8_t S5CR_MINC = 10;            // Memory increment mode
    static const uint8_t S5CR_PINC = 9;             // Peripheral increment mode
    static const uint8_t S5CR_CIRC = 8;             // Circular mode
    static const uint8_t S5CR_DIR = 6;              // Data transfer direction (2 bits)
    static const uint8_t S5CR_PFCTRL = 5;           // Peripheral flow controller
    static const uint8_t S5CR_TCIE = 4;             // Transfer complete interrupt enable
    static const uint8_t S5CR_HTIE = 3;             // Half transfer interrupt enable
    static const uint8_t S5CR_TEIE = 2;             // Transfer error interrupt enable
    static const uint8_t S5CR_DMEIE = 1;            // Direct mode error interrupt enable
    static const uint8_t S5CR_EN = 0;               // Stream enable / flag stream ready when read low
    static const uint32_t S5CR_RESET_VALUE = 0x0;

    static const uint8_t S5NDTR_NDT = 0;              // Number of data items to transfer (16 bits)
    static const uint32_t S5NDTR_RESET_VALUE = 0x0;

    static const uint8_t S5PAR_PA = 0;               // Peripheral address (32 bits)
    static const uint32_t S5PAR_RESET_VALUE = 0x0;

    static const uint8_t S5M0AR_M0A = 0;              // Memory 0 address (32 bits)
    static const uint32_t S5M0AR_RESET_VALUE = 0x0;

    static const uint8_t S5M1AR_M1A = 0;              // Memory 1 address (used in case of Double buffer mode) (32 bits)
    static const uint32_t S5M1AR_RESET_VALUE = 0x0;

    static const uint8_t S5FCR_FEIE = 7;             // FIFO error interrupt enable, Read-write
    static const uint8_t S5FCR_FS = 3;               // FIFO status (3 bits), Read-only
    static const uint8_t S5FCR_DMDIS = 2;            // Direct mode disable, Read-write
    static const uint8_t S5FCR_FTH = 0;              // FIFO threshold selection (2 bits), Read-write
    static const uint32_t S5FCR_RESET_VALUE = 0x21;

    static const uint8_t S6CR_CHSEL = 25;           // Channel selection (3 bits)
    static const uint8_t S6CR_MBURST = 23;          // Memory burst transfer configuration (2 bits)
    static const uint8_t S6CR_PBURST = 21;          // Peripheral burst transfer configuration (2 bits)
    static const uint8_t S6CR_ACK = 20;             // ACK
    static const uint8_t S6CR_CT = 19;              // Current target (only in double buffer mode)
    static const uint8_t S6CR_DBM = 18;             // Double buffer mode
    static const uint8_t S6CR_PL = 16;              // Priority level (2 bits)
    static const uint8_t S6CR_PINCOS = 15;          // Peripheral increment offset size
    static const uint8_t S6CR_MSIZE = 13;           // Memory data size (2 bits)
    static const uint8_t S6CR_PSIZE = 11;           // Peripheral data size (2 bits)
    static const uint8_t S6CR_MINC = 10;            // Memory increment mode
    static const uint8_t S6CR_PINC = 9;             // Peripheral increment mode
    static const uint8_t S6CR_CIRC = 8;             // Circular mode
    static const uint8_t S6CR_DIR = 6;              // Data transfer direction (2 bits)
    static const uint8_t S6CR_PFCTRL = 5;           // Peripheral flow controller
    static const uint8_t S6CR_TCIE = 4;             // Transfer complete interrupt enable
    static const uint8_t S6CR_HTIE = 3;             // Half transfer interrupt enable
    static const uint8_t S6CR_TEIE = 2;             // Transfer error interrupt enable
    static const uint8_t S6CR_DMEIE = 1;            // Direct mode error interrupt enable
    static const uint8_t S6CR_EN = 0;               // Stream enable / flag stream ready when read low
    static const uint32_t S6CR_RESET_VALUE = 0x0;

    static const uint8_t S6NDTR_NDT = 0;              // Number of data items to transfer (16 bits)
    static const uint32_t S6NDTR_RESET_VALUE = 0x0;

    static const uint8_t S6PAR_PA = 0;               // Peripheral address (32 bits)
    static const uint32_t S6PAR_RESET_VALUE = 0x0;

    static const uint8_t S6M0AR_M0A = 0;              // Memory 0 address (32 bits)
    static const uint32_t S6M0AR_RESET_VALUE = 0x0;

    static const uint8_t S6M1AR_M1A = 0;              // Memory 1 address (used in case of Double buffer mode) (32 bits)
    static const uint32_t S6M1AR_RESET_VALUE = 0x0;

    static const uint8_t S6FCR_FEIE = 7;             // FIFO error interrupt enable, Read-write
    static const uint8_t S6FCR_FS = 3;               // FIFO status (3 bits), Read-only
    static const uint8_t S6FCR_DMDIS = 2;            // Direct mode disable, Read-write
    static const uint8_t S6FCR_FTH = 0;              // FIFO threshold selection (2 bits), Read-write
    static const uint32_t S6FCR_RESET_VALUE = 0x21;

    static const uint8_t S7CR_CHSEL = 25;           // Channel selection (3 bits)
    static const uint8_t S7CR_MBURST = 23;          // Memory burst transfer configuration (2 bits)
    static const uint8_t S7CR_PBURST = 21;          // Peripheral burst transfer configuration (2 bits)
    static const uint8_t S7CR_ACK = 20;             // ACK
    static const uint8_t S7CR_CT = 19;              // Current target (only in double buffer mode)
    static const uint8_t S7CR_DBM = 18;             // Double buffer mode
    static const uint8_t S7CR_PL = 16;              // Priority level (2 bits)
    static const uint8_t S7CR_PINCOS = 15;          // Peripheral increment offset size
    static const uint8_t S7CR_MSIZE = 13;           // Memory data size (2 bits)
    static const uint8_t S7CR_PSIZE = 11;           // Peripheral data size (2 bits)
    static const uint8_t S7CR_MINC = 10;            // Memory increment mode
    static const uint8_t S7CR_PINC = 9;             // Peripheral increment mode
    static const uint8_t S7CR_CIRC = 8;             // Circular mode
    static const uint8_t S7CR_DIR = 6;              // Data transfer direction (2 bits)
    static const uint8_t S7CR_PFCTRL = 5;           // Peripheral flow controller
    static const uint8_t S7CR_TCIE = 4;             // Transfer complete interrupt enable
    static const uint8_t S7CR_HTIE = 3;             // Half transfer interrupt enable
    static const uint8_t S7CR_TEIE = 2;             // Transfer error interrupt enable
    static const uint8_t S7CR_DMEIE = 1;            // Direct mode error interrupt enable
    static const uint8_t S7CR_EN = 0;               // Stream enable / flag stream ready when read low
    static const uint32_t S7CR_RESET_VALUE = 0x0;

    static const uint8_t S7NDTR_NDT = 0;              // Number of data items to transfer (16 bits)
    static const uint32_t S7NDTR_RESET_VALUE = 0x0;

    static const uint8_t S7PAR_PA = 0;               // Peripheral address (32 bits)
    static const uint32_t S7PAR_RESET_VALUE = 0x0;

    static const uint8_t S7M0AR_M0A = 0;              // Memory 0 address (32 bits)
    static const uint32_t S7M0AR_RESET_VALUE = 0x0;

    static const uint8_t S7M1AR_M1A = 0;              // Memory 1 address (used in case of Double buffer mode) (32 bits)
    static const uint32_t S7M1AR_RESET_VALUE = 0x0;

    static const uint8_t S7FCR_FEIE = 7;             // FIFO error interrupt enable, Read-write
    static const uint8_t S7FCR_FS = 3;               // FIFO status (3 bits), Read-only
    static const uint8_t S7FCR_DMDIS = 2;            // Direct mode disable, Read-write
    static const uint8_t S7FCR_FTH = 0;              // FIFO threshold selection (2 bits), Read-write
    static const uint32_t S7FCR_RESET_VALUE = 0x21;
};

static dma1_t& DMA1 = *reinterpret_cast<dma1_t*>(0x40026000);


////
//
//    General-purpose I/Os
//
////

struct gpioh_t
{
    volatile uint32_t    MODER;                // [Read-write] GPIO port mode register
    volatile uint32_t    OTYPER;               // [Read-write] GPIO port output type register
    volatile uint32_t    OSPEEDR;              // [Read-write] GPIO port output speed register
    volatile uint32_t    PUPDR;                // [Read-write] GPIO port pull-up/pull-down register
    volatile uint32_t    IDR;                  // [Read-only] GPIO port input data register
    volatile uint32_t    ODR;                  // [Read-write] GPIO port output data register
    volatile uint32_t    BSRR;                 // [Write-only] GPIO port bit set/reset register
    volatile uint32_t    LCKR;                 // [Read-write] GPIO port configuration lock register
    volatile uint32_t    AFRL;                 // [Read-write] GPIO alternate function low register
    volatile uint32_t    AFRH;                 // [Read-write] GPIO alternate function high register

    static const uint8_t MODER_MODER15 = 30;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER14 = 28;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER13 = 26;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER12 = 24;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER11 = 22;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER10 = 20;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER9 = 18;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER8 = 16;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER7 = 14;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER6 = 12;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER5 = 10;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER4 = 8;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER3 = 6;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER2 = 4;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER1 = 2;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER0 = 0;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint32_t MODER_RESET_VALUE = 0x0;

    static const uint8_t OTYPER_OT15 = 15;            // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT14 = 14;            // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT13 = 13;            // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT12 = 12;            // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT11 = 11;            // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT10 = 10;            // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT9 = 9;              // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT8 = 8;              // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT7 = 7;              // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT6 = 6;              // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT5 = 5;              // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT4 = 4;              // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT3 = 3;              // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT2 = 2;              // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT1 = 1;              // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT0 = 0;              // Port x configuration bits (y = 0..15)
    static const uint32_t OTYPER_RESET_VALUE = 0x0;

    static const uint8_t OSPEEDR_OSPEEDR15 = 30;       // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR14 = 28;       // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR13 = 26;       // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR12 = 24;       // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR11 = 22;       // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR10 = 20;       // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR9 = 18;        // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR8 = 16;        // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR7 = 14;        // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR6 = 12;        // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR5 = 10;        // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR4 = 8;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR3 = 6;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR2 = 4;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR1 = 2;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR0 = 0;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint32_t OSPEEDR_RESET_VALUE = 0x0;

    static const uint8_t PUPDR_PUPDR15 = 30;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR14 = 28;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR13 = 26;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR12 = 24;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR11 = 22;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR10 = 20;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR9 = 18;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR8 = 16;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR7 = 14;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR6 = 12;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR5 = 10;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR4 = 8;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR3 = 6;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR2 = 4;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR1 = 2;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR0 = 0;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint32_t PUPDR_RESET_VALUE = 0x0;

    static const uint8_t IDR_IDR15 = 15;           // Port input data (y = 0..15)
    static const uint8_t IDR_IDR14 = 14;           // Port input data (y = 0..15)
    static const uint8_t IDR_IDR13 = 13;           // Port input data (y = 0..15)
    static const uint8_t IDR_IDR12 = 12;           // Port input data (y = 0..15)
    static const uint8_t IDR_IDR11 = 11;           // Port input data (y = 0..15)
    static const uint8_t IDR_IDR10 = 10;           // Port input data (y = 0..15)
    static const uint8_t IDR_IDR9 = 9;             // Port input data (y = 0..15)
    static const uint8_t IDR_IDR8 = 8;             // Port input data (y = 0..15)
    static const uint8_t IDR_IDR7 = 7;             // Port input data (y = 0..15)
    static const uint8_t IDR_IDR6 = 6;             // Port input data (y = 0..15)
    static const uint8_t IDR_IDR5 = 5;             // Port input data (y = 0..15)
    static const uint8_t IDR_IDR4 = 4;             // Port input data (y = 0..15)
    static const uint8_t IDR_IDR3 = 3;             // Port input data (y = 0..15)
    static const uint8_t IDR_IDR2 = 2;             // Port input data (y = 0..15)
    static const uint8_t IDR_IDR1 = 1;             // Port input data (y = 0..15)
    static const uint8_t IDR_IDR0 = 0;             // Port input data (y = 0..15)
    static const uint32_t IDR_RESET_VALUE = 0x0;

    static const uint8_t ODR_ODR15 = 15;           // Port output data (y = 0..15)
    static const uint8_t ODR_ODR14 = 14;           // Port output data (y = 0..15)
    static const uint8_t ODR_ODR13 = 13;           // Port output data (y = 0..15)
    static const uint8_t ODR_ODR12 = 12;           // Port output data (y = 0..15)
    static const uint8_t ODR_ODR11 = 11;           // Port output data (y = 0..15)
    static const uint8_t ODR_ODR10 = 10;           // Port output data (y = 0..15)
    static const uint8_t ODR_ODR9 = 9;             // Port output data (y = 0..15)
    static const uint8_t ODR_ODR8 = 8;             // Port output data (y = 0..15)
    static const uint8_t ODR_ODR7 = 7;             // Port output data (y = 0..15)
    static const uint8_t ODR_ODR6 = 6;             // Port output data (y = 0..15)
    static const uint8_t ODR_ODR5 = 5;             // Port output data (y = 0..15)
    static const uint8_t ODR_ODR4 = 4;             // Port output data (y = 0..15)
    static const uint8_t ODR_ODR3 = 3;             // Port output data (y = 0..15)
    static const uint8_t ODR_ODR2 = 2;             // Port output data (y = 0..15)
    static const uint8_t ODR_ODR1 = 1;             // Port output data (y = 0..15)
    static const uint8_t ODR_ODR0 = 0;             // Port output data (y = 0..15)
    static const uint32_t ODR_RESET_VALUE = 0x0;

    static const uint8_t BSRR_BR15 = 31;            // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR14 = 30;            // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR13 = 29;            // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR12 = 28;            // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR11 = 27;            // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR10 = 26;            // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR9 = 25;             // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR8 = 24;             // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR7 = 23;             // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR6 = 22;             // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR5 = 21;             // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR4 = 20;             // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR3 = 19;             // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR2 = 18;             // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR1 = 17;             // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR0 = 16;             // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS15 = 15;            // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS14 = 14;            // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS13 = 13;            // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS12 = 12;            // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS11 = 11;            // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS10 = 10;            // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS9 = 9;              // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS8 = 8;              // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS7 = 7;              // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS6 = 6;              // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS5 = 5;              // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS4 = 4;              // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS3 = 3;              // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS2 = 2;              // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS1 = 1;              // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS0 = 0;              // Port x set bit y (y= 0..15)
    static const uint32_t BSRR_RESET_VALUE = 0x0;

    static const uint8_t LCKR_LCKK = 16;            // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK15 = 15;           // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK14 = 14;           // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK13 = 13;           // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK12 = 12;           // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK11 = 11;           // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK10 = 10;           // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK9 = 9;             // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK8 = 8;             // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK7 = 7;             // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK6 = 6;             // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK5 = 5;             // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK4 = 4;             // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK3 = 3;             // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK2 = 2;             // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK1 = 1;             // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK0 = 0;             // Port x lock bit y (y= 0..15)
    static const uint32_t LCKR_RESET_VALUE = 0x0;

    static const uint8_t AFRL_AFRL7 = 28;           // Alternate function selection for port x bit y (y = 0..7) (4 bits)
    static const uint8_t AFRL_AFRL6 = 24;           // Alternate function selection for port x bit y (y = 0..7) (4 bits)
    static const uint8_t AFRL_AFRL5 = 20;           // Alternate function selection for port x bit y (y = 0..7) (4 bits)
    static const uint8_t AFRL_AFRL4 = 16;           // Alternate function selection for port x bit y (y = 0..7) (4 bits)
    static const uint8_t AFRL_AFRL3 = 12;           // Alternate function selection for port x bit y (y = 0..7) (4 bits)
    static const uint8_t AFRL_AFRL2 = 8;            // Alternate function selection for port x bit y (y = 0..7) (4 bits)
    static const uint8_t AFRL_AFRL1 = 4;            // Alternate function selection for port x bit y (y = 0..7) (4 bits)
    static const uint8_t AFRL_AFRL0 = 0;            // Alternate function selection for port x bit y (y = 0..7) (4 bits)
    static const uint32_t AFRL_RESET_VALUE = 0x0;

    static const uint8_t AFRH_AFRH15 = 28;          // Alternate function selection for port x bit y (y = 8..15) (4 bits)
    static const uint8_t AFRH_AFRH14 = 24;          // Alternate function selection for port x bit y (y = 8..15) (4 bits)
    static const uint8_t AFRH_AFRH13 = 20;          // Alternate function selection for port x bit y (y = 8..15) (4 bits)
    static const uint8_t AFRH_AFRH12 = 16;          // Alternate function selection for port x bit y (y = 8..15) (4 bits)
    static const uint8_t AFRH_AFRH11 = 12;          // Alternate function selection for port x bit y (y = 8..15) (4 bits)
    static const uint8_t AFRH_AFRH10 = 8;           // Alternate function selection for port x bit y (y = 8..15) (4 bits)
    static const uint8_t AFRH_AFRH9 = 4;            // Alternate function selection for port x bit y (y = 8..15) (4 bits)
    static const uint8_t AFRH_AFRH8 = 0;            // Alternate function selection for port x bit y (y = 8..15) (4 bits)
    static const uint32_t AFRH_RESET_VALUE = 0x0;
};

static gpioh_t& GPIOH = *reinterpret_cast<gpioh_t*>(0x40021c00);


////
//
//    General-purpose I/Os
//
////

struct gpioe_t
{
    volatile uint32_t    MODER;                // [Read-write] GPIO port mode register
    volatile uint32_t    OTYPER;               // [Read-write] GPIO port output type register
    volatile uint32_t    OSPEEDR;              // [Read-write] GPIO port output speed register
    volatile uint32_t    PUPDR;                // [Read-write] GPIO port pull-up/pull-down register
    volatile uint32_t    IDR;                  // [Read-only] GPIO port input data register
    volatile uint32_t    ODR;                  // [Read-write] GPIO port output data register
    volatile uint32_t    BSRR;                 // [Write-only] GPIO port bit set/reset register
    volatile uint32_t    LCKR;                 // [Read-write] GPIO port configuration lock register
    volatile uint32_t    AFRL;                 // [Read-write] GPIO alternate function low register
    volatile uint32_t    AFRH;                 // [Read-write] GPIO alternate function high register

    static const uint8_t MODER_MODER15 = 30;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER14 = 28;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER13 = 26;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER12 = 24;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER11 = 22;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER10 = 20;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER9 = 18;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER8 = 16;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER7 = 14;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER6 = 12;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER5 = 10;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER4 = 8;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER3 = 6;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER2 = 4;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER1 = 2;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER0 = 0;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint32_t MODER_RESET_VALUE = 0x0;

    static const uint8_t OTYPER_OT15 = 15;            // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT14 = 14;            // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT13 = 13;            // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT12 = 12;            // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT11 = 11;            // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT10 = 10;            // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT9 = 9;              // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT8 = 8;              // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT7 = 7;              // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT6 = 6;              // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT5 = 5;              // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT4 = 4;              // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT3 = 3;              // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT2 = 2;              // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT1 = 1;              // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT0 = 0;              // Port x configuration bits (y = 0..15)
    static const uint32_t OTYPER_RESET_VALUE = 0x0;

    static const uint8_t OSPEEDR_OSPEEDR15 = 30;       // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR14 = 28;       // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR13 = 26;       // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR12 = 24;       // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR11 = 22;       // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR10 = 20;       // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR9 = 18;        // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR8 = 16;        // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR7 = 14;        // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR6 = 12;        // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR5 = 10;        // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR4 = 8;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR3 = 6;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR2 = 4;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR1 = 2;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR0 = 0;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint32_t OSPEEDR_RESET_VALUE = 0x0;

    static const uint8_t PUPDR_PUPDR15 = 30;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR14 = 28;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR13 = 26;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR12 = 24;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR11 = 22;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR10 = 20;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR9 = 18;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR8 = 16;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR7 = 14;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR6 = 12;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR5 = 10;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR4 = 8;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR3 = 6;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR2 = 4;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR1 = 2;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR0 = 0;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint32_t PUPDR_RESET_VALUE = 0x0;

    static const uint8_t IDR_IDR15 = 15;           // Port input data (y = 0..15)
    static const uint8_t IDR_IDR14 = 14;           // Port input data (y = 0..15)
    static const uint8_t IDR_IDR13 = 13;           // Port input data (y = 0..15)
    static const uint8_t IDR_IDR12 = 12;           // Port input data (y = 0..15)
    static const uint8_t IDR_IDR11 = 11;           // Port input data (y = 0..15)
    static const uint8_t IDR_IDR10 = 10;           // Port input data (y = 0..15)
    static const uint8_t IDR_IDR9 = 9;             // Port input data (y = 0..15)
    static const uint8_t IDR_IDR8 = 8;             // Port input data (y = 0..15)
    static const uint8_t IDR_IDR7 = 7;             // Port input data (y = 0..15)
    static const uint8_t IDR_IDR6 = 6;             // Port input data (y = 0..15)
    static const uint8_t IDR_IDR5 = 5;             // Port input data (y = 0..15)
    static const uint8_t IDR_IDR4 = 4;             // Port input data (y = 0..15)
    static const uint8_t IDR_IDR3 = 3;             // Port input data (y = 0..15)
    static const uint8_t IDR_IDR2 = 2;             // Port input data (y = 0..15)
    static const uint8_t IDR_IDR1 = 1;             // Port input data (y = 0..15)
    static const uint8_t IDR_IDR0 = 0;             // Port input data (y = 0..15)
    static const uint32_t IDR_RESET_VALUE = 0x0;

    static const uint8_t ODR_ODR15 = 15;           // Port output data (y = 0..15)
    static const uint8_t ODR_ODR14 = 14;           // Port output data (y = 0..15)
    static const uint8_t ODR_ODR13 = 13;           // Port output data (y = 0..15)
    static const uint8_t ODR_ODR12 = 12;           // Port output data (y = 0..15)
    static const uint8_t ODR_ODR11 = 11;           // Port output data (y = 0..15)
    static const uint8_t ODR_ODR10 = 10;           // Port output data (y = 0..15)
    static const uint8_t ODR_ODR9 = 9;             // Port output data (y = 0..15)
    static const uint8_t ODR_ODR8 = 8;             // Port output data (y = 0..15)
    static const uint8_t ODR_ODR7 = 7;             // Port output data (y = 0..15)
    static const uint8_t ODR_ODR6 = 6;             // Port output data (y = 0..15)
    static const uint8_t ODR_ODR5 = 5;             // Port output data (y = 0..15)
    static const uint8_t ODR_ODR4 = 4;             // Port output data (y = 0..15)
    static const uint8_t ODR_ODR3 = 3;             // Port output data (y = 0..15)
    static const uint8_t ODR_ODR2 = 2;             // Port output data (y = 0..15)
    static const uint8_t ODR_ODR1 = 1;             // Port output data (y = 0..15)
    static const uint8_t ODR_ODR0 = 0;             // Port output data (y = 0..15)
    static const uint32_t ODR_RESET_VALUE = 0x0;

    static const uint8_t BSRR_BR15 = 31;            // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR14 = 30;            // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR13 = 29;            // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR12 = 28;            // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR11 = 27;            // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR10 = 26;            // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR9 = 25;             // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR8 = 24;             // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR7 = 23;             // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR6 = 22;             // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR5 = 21;             // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR4 = 20;             // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR3 = 19;             // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR2 = 18;             // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR1 = 17;             // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR0 = 16;             // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS15 = 15;            // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS14 = 14;            // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS13 = 13;            // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS12 = 12;            // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS11 = 11;            // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS10 = 10;            // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS9 = 9;              // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS8 = 8;              // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS7 = 7;              // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS6 = 6;              // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS5 = 5;              // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS4 = 4;              // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS3 = 3;              // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS2 = 2;              // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS1 = 1;              // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS0 = 0;              // Port x set bit y (y= 0..15)
    static const uint32_t BSRR_RESET_VALUE = 0x0;

    static const uint8_t LCKR_LCKK = 16;            // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK15 = 15;           // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK14 = 14;           // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK13 = 13;           // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK12 = 12;           // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK11 = 11;           // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK10 = 10;           // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK9 = 9;             // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK8 = 8;             // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK7 = 7;             // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK6 = 6;             // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK5 = 5;             // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK4 = 4;             // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK3 = 3;             // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK2 = 2;             // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK1 = 1;             // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK0 = 0;             // Port x lock bit y (y= 0..15)
    static const uint32_t LCKR_RESET_VALUE = 0x0;

    static const uint8_t AFRL_AFRL7 = 28;           // Alternate function selection for port x bit y (y = 0..7) (4 bits)
    static const uint8_t AFRL_AFRL6 = 24;           // Alternate function selection for port x bit y (y = 0..7) (4 bits)
    static const uint8_t AFRL_AFRL5 = 20;           // Alternate function selection for port x bit y (y = 0..7) (4 bits)
    static const uint8_t AFRL_AFRL4 = 16;           // Alternate function selection for port x bit y (y = 0..7) (4 bits)
    static const uint8_t AFRL_AFRL3 = 12;           // Alternate function selection for port x bit y (y = 0..7) (4 bits)
    static const uint8_t AFRL_AFRL2 = 8;            // Alternate function selection for port x bit y (y = 0..7) (4 bits)
    static const uint8_t AFRL_AFRL1 = 4;            // Alternate function selection for port x bit y (y = 0..7) (4 bits)
    static const uint8_t AFRL_AFRL0 = 0;            // Alternate function selection for port x bit y (y = 0..7) (4 bits)
    static const uint32_t AFRL_RESET_VALUE = 0x0;

    static const uint8_t AFRH_AFRH15 = 28;          // Alternate function selection for port x bit y (y = 8..15) (4 bits)
    static const uint8_t AFRH_AFRH14 = 24;          // Alternate function selection for port x bit y (y = 8..15) (4 bits)
    static const uint8_t AFRH_AFRH13 = 20;          // Alternate function selection for port x bit y (y = 8..15) (4 bits)
    static const uint8_t AFRH_AFRH12 = 16;          // Alternate function selection for port x bit y (y = 8..15) (4 bits)
    static const uint8_t AFRH_AFRH11 = 12;          // Alternate function selection for port x bit y (y = 8..15) (4 bits)
    static const uint8_t AFRH_AFRH10 = 8;           // Alternate function selection for port x bit y (y = 8..15) (4 bits)
    static const uint8_t AFRH_AFRH9 = 4;            // Alternate function selection for port x bit y (y = 8..15) (4 bits)
    static const uint8_t AFRH_AFRH8 = 0;            // Alternate function selection for port x bit y (y = 8..15) (4 bits)
    static const uint32_t AFRH_RESET_VALUE = 0x0;
};

static gpioe_t& GPIOE = *reinterpret_cast<gpioe_t*>(0x40021000);


////
//
//    General-purpose I/Os
//
////

struct gpiod_t
{
    volatile uint32_t    MODER;                // [Read-write] GPIO port mode register
    volatile uint32_t    OTYPER;               // [Read-write] GPIO port output type register
    volatile uint32_t    OSPEEDR;              // [Read-write] GPIO port output speed register
    volatile uint32_t    PUPDR;                // [Read-write] GPIO port pull-up/pull-down register
    volatile uint32_t    IDR;                  // [Read-only] GPIO port input data register
    volatile uint32_t    ODR;                  // [Read-write] GPIO port output data register
    volatile uint32_t    BSRR;                 // [Write-only] GPIO port bit set/reset register
    volatile uint32_t    LCKR;                 // [Read-write] GPIO port configuration lock register
    volatile uint32_t    AFRL;                 // [Read-write] GPIO alternate function low register
    volatile uint32_t    AFRH;                 // [Read-write] GPIO alternate function high register

    static const uint8_t MODER_MODER15 = 30;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER14 = 28;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER13 = 26;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER12 = 24;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER11 = 22;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER10 = 20;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER9 = 18;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER8 = 16;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER7 = 14;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER6 = 12;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER5 = 10;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER4 = 8;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER3 = 6;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER2 = 4;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER1 = 2;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER0 = 0;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint32_t MODER_RESET_VALUE = 0x0;

    static const uint8_t OTYPER_OT15 = 15;            // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT14 = 14;            // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT13 = 13;            // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT12 = 12;            // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT11 = 11;            // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT10 = 10;            // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT9 = 9;              // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT8 = 8;              // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT7 = 7;              // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT6 = 6;              // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT5 = 5;              // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT4 = 4;              // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT3 = 3;              // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT2 = 2;              // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT1 = 1;              // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT0 = 0;              // Port x configuration bits (y = 0..15)
    static const uint32_t OTYPER_RESET_VALUE = 0x0;

    static const uint8_t OSPEEDR_OSPEEDR15 = 30;       // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR14 = 28;       // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR13 = 26;       // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR12 = 24;       // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR11 = 22;       // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR10 = 20;       // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR9 = 18;        // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR8 = 16;        // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR7 = 14;        // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR6 = 12;        // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR5 = 10;        // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR4 = 8;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR3 = 6;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR2 = 4;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR1 = 2;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR0 = 0;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint32_t OSPEEDR_RESET_VALUE = 0x0;

    static const uint8_t PUPDR_PUPDR15 = 30;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR14 = 28;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR13 = 26;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR12 = 24;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR11 = 22;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR10 = 20;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR9 = 18;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR8 = 16;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR7 = 14;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR6 = 12;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR5 = 10;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR4 = 8;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR3 = 6;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR2 = 4;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR1 = 2;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR0 = 0;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint32_t PUPDR_RESET_VALUE = 0x0;

    static const uint8_t IDR_IDR15 = 15;           // Port input data (y = 0..15)
    static const uint8_t IDR_IDR14 = 14;           // Port input data (y = 0..15)
    static const uint8_t IDR_IDR13 = 13;           // Port input data (y = 0..15)
    static const uint8_t IDR_IDR12 = 12;           // Port input data (y = 0..15)
    static const uint8_t IDR_IDR11 = 11;           // Port input data (y = 0..15)
    static const uint8_t IDR_IDR10 = 10;           // Port input data (y = 0..15)
    static const uint8_t IDR_IDR9 = 9;             // Port input data (y = 0..15)
    static const uint8_t IDR_IDR8 = 8;             // Port input data (y = 0..15)
    static const uint8_t IDR_IDR7 = 7;             // Port input data (y = 0..15)
    static const uint8_t IDR_IDR6 = 6;             // Port input data (y = 0..15)
    static const uint8_t IDR_IDR5 = 5;             // Port input data (y = 0..15)
    static const uint8_t IDR_IDR4 = 4;             // Port input data (y = 0..15)
    static const uint8_t IDR_IDR3 = 3;             // Port input data (y = 0..15)
    static const uint8_t IDR_IDR2 = 2;             // Port input data (y = 0..15)
    static const uint8_t IDR_IDR1 = 1;             // Port input data (y = 0..15)
    static const uint8_t IDR_IDR0 = 0;             // Port input data (y = 0..15)
    static const uint32_t IDR_RESET_VALUE = 0x0;

    static const uint8_t ODR_ODR15 = 15;           // Port output data (y = 0..15)
    static const uint8_t ODR_ODR14 = 14;           // Port output data (y = 0..15)
    static const uint8_t ODR_ODR13 = 13;           // Port output data (y = 0..15)
    static const uint8_t ODR_ODR12 = 12;           // Port output data (y = 0..15)
    static const uint8_t ODR_ODR11 = 11;           // Port output data (y = 0..15)
    static const uint8_t ODR_ODR10 = 10;           // Port output data (y = 0..15)
    static const uint8_t ODR_ODR9 = 9;             // Port output data (y = 0..15)
    static const uint8_t ODR_ODR8 = 8;             // Port output data (y = 0..15)
    static const uint8_t ODR_ODR7 = 7;             // Port output data (y = 0..15)
    static const uint8_t ODR_ODR6 = 6;             // Port output data (y = 0..15)
    static const uint8_t ODR_ODR5 = 5;             // Port output data (y = 0..15)
    static const uint8_t ODR_ODR4 = 4;             // Port output data (y = 0..15)
    static const uint8_t ODR_ODR3 = 3;             // Port output data (y = 0..15)
    static const uint8_t ODR_ODR2 = 2;             // Port output data (y = 0..15)
    static const uint8_t ODR_ODR1 = 1;             // Port output data (y = 0..15)
    static const uint8_t ODR_ODR0 = 0;             // Port output data (y = 0..15)
    static const uint32_t ODR_RESET_VALUE = 0x0;

    static const uint8_t BSRR_BR15 = 31;            // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR14 = 30;            // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR13 = 29;            // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR12 = 28;            // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR11 = 27;            // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR10 = 26;            // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR9 = 25;             // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR8 = 24;             // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR7 = 23;             // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR6 = 22;             // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR5 = 21;             // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR4 = 20;             // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR3 = 19;             // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR2 = 18;             // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR1 = 17;             // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR0 = 16;             // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS15 = 15;            // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS14 = 14;            // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS13 = 13;            // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS12 = 12;            // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS11 = 11;            // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS10 = 10;            // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS9 = 9;              // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS8 = 8;              // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS7 = 7;              // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS6 = 6;              // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS5 = 5;              // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS4 = 4;              // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS3 = 3;              // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS2 = 2;              // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS1 = 1;              // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS0 = 0;              // Port x set bit y (y= 0..15)
    static const uint32_t BSRR_RESET_VALUE = 0x0;

    static const uint8_t LCKR_LCKK = 16;            // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK15 = 15;           // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK14 = 14;           // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK13 = 13;           // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK12 = 12;           // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK11 = 11;           // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK10 = 10;           // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK9 = 9;             // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK8 = 8;             // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK7 = 7;             // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK6 = 6;             // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK5 = 5;             // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK4 = 4;             // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK3 = 3;             // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK2 = 2;             // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK1 = 1;             // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK0 = 0;             // Port x lock bit y (y= 0..15)
    static const uint32_t LCKR_RESET_VALUE = 0x0;

    static const uint8_t AFRL_AFRL7 = 28;           // Alternate function selection for port x bit y (y = 0..7) (4 bits)
    static const uint8_t AFRL_AFRL6 = 24;           // Alternate function selection for port x bit y (y = 0..7) (4 bits)
    static const uint8_t AFRL_AFRL5 = 20;           // Alternate function selection for port x bit y (y = 0..7) (4 bits)
    static const uint8_t AFRL_AFRL4 = 16;           // Alternate function selection for port x bit y (y = 0..7) (4 bits)
    static const uint8_t AFRL_AFRL3 = 12;           // Alternate function selection for port x bit y (y = 0..7) (4 bits)
    static const uint8_t AFRL_AFRL2 = 8;            // Alternate function selection for port x bit y (y = 0..7) (4 bits)
    static const uint8_t AFRL_AFRL1 = 4;            // Alternate function selection for port x bit y (y = 0..7) (4 bits)
    static const uint8_t AFRL_AFRL0 = 0;            // Alternate function selection for port x bit y (y = 0..7) (4 bits)
    static const uint32_t AFRL_RESET_VALUE = 0x0;

    static const uint8_t AFRH_AFRH15 = 28;          // Alternate function selection for port x bit y (y = 8..15) (4 bits)
    static const uint8_t AFRH_AFRH14 = 24;          // Alternate function selection for port x bit y (y = 8..15) (4 bits)
    static const uint8_t AFRH_AFRH13 = 20;          // Alternate function selection for port x bit y (y = 8..15) (4 bits)
    static const uint8_t AFRH_AFRH12 = 16;          // Alternate function selection for port x bit y (y = 8..15) (4 bits)
    static const uint8_t AFRH_AFRH11 = 12;          // Alternate function selection for port x bit y (y = 8..15) (4 bits)
    static const uint8_t AFRH_AFRH10 = 8;           // Alternate function selection for port x bit y (y = 8..15) (4 bits)
    static const uint8_t AFRH_AFRH9 = 4;            // Alternate function selection for port x bit y (y = 8..15) (4 bits)
    static const uint8_t AFRH_AFRH8 = 0;            // Alternate function selection for port x bit y (y = 8..15) (4 bits)
    static const uint32_t AFRH_RESET_VALUE = 0x0;
};

static gpiod_t& GPIOD = *reinterpret_cast<gpiod_t*>(0x40020c00);


////
//
//    General-purpose I/Os
//
////

struct gpioc_t
{
    volatile uint32_t    MODER;                // [Read-write] GPIO port mode register
    volatile uint32_t    OTYPER;               // [Read-write] GPIO port output type register
    volatile uint32_t    OSPEEDR;              // [Read-write] GPIO port output speed register
    volatile uint32_t    PUPDR;                // [Read-write] GPIO port pull-up/pull-down register
    volatile uint32_t    IDR;                  // [Read-only] GPIO port input data register
    volatile uint32_t    ODR;                  // [Read-write] GPIO port output data register
    volatile uint32_t    BSRR;                 // [Write-only] GPIO port bit set/reset register
    volatile uint32_t    LCKR;                 // [Read-write] GPIO port configuration lock register
    volatile uint32_t    AFRL;                 // [Read-write] GPIO alternate function low register
    volatile uint32_t    AFRH;                 // [Read-write] GPIO alternate function high register

    static const uint8_t MODER_MODER15 = 30;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER14 = 28;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER13 = 26;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER12 = 24;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER11 = 22;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER10 = 20;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER9 = 18;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER8 = 16;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER7 = 14;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER6 = 12;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER5 = 10;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER4 = 8;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER3 = 6;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER2 = 4;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER1 = 2;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER0 = 0;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint32_t MODER_RESET_VALUE = 0x0;

    static const uint8_t OTYPER_OT15 = 15;            // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT14 = 14;            // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT13 = 13;            // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT12 = 12;            // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT11 = 11;            // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT10 = 10;            // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT9 = 9;              // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT8 = 8;              // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT7 = 7;              // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT6 = 6;              // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT5 = 5;              // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT4 = 4;              // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT3 = 3;              // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT2 = 2;              // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT1 = 1;              // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT0 = 0;              // Port x configuration bits (y = 0..15)
    static const uint32_t OTYPER_RESET_VALUE = 0x0;

    static const uint8_t OSPEEDR_OSPEEDR15 = 30;       // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR14 = 28;       // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR13 = 26;       // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR12 = 24;       // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR11 = 22;       // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR10 = 20;       // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR9 = 18;        // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR8 = 16;        // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR7 = 14;        // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR6 = 12;        // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR5 = 10;        // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR4 = 8;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR3 = 6;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR2 = 4;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR1 = 2;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR0 = 0;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint32_t OSPEEDR_RESET_VALUE = 0x0;

    static const uint8_t PUPDR_PUPDR15 = 30;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR14 = 28;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR13 = 26;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR12 = 24;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR11 = 22;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR10 = 20;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR9 = 18;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR8 = 16;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR7 = 14;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR6 = 12;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR5 = 10;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR4 = 8;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR3 = 6;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR2 = 4;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR1 = 2;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR0 = 0;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint32_t PUPDR_RESET_VALUE = 0x0;

    static const uint8_t IDR_IDR15 = 15;           // Port input data (y = 0..15)
    static const uint8_t IDR_IDR14 = 14;           // Port input data (y = 0..15)
    static const uint8_t IDR_IDR13 = 13;           // Port input data (y = 0..15)
    static const uint8_t IDR_IDR12 = 12;           // Port input data (y = 0..15)
    static const uint8_t IDR_IDR11 = 11;           // Port input data (y = 0..15)
    static const uint8_t IDR_IDR10 = 10;           // Port input data (y = 0..15)
    static const uint8_t IDR_IDR9 = 9;             // Port input data (y = 0..15)
    static const uint8_t IDR_IDR8 = 8;             // Port input data (y = 0..15)
    static const uint8_t IDR_IDR7 = 7;             // Port input data (y = 0..15)
    static const uint8_t IDR_IDR6 = 6;             // Port input data (y = 0..15)
    static const uint8_t IDR_IDR5 = 5;             // Port input data (y = 0..15)
    static const uint8_t IDR_IDR4 = 4;             // Port input data (y = 0..15)
    static const uint8_t IDR_IDR3 = 3;             // Port input data (y = 0..15)
    static const uint8_t IDR_IDR2 = 2;             // Port input data (y = 0..15)
    static const uint8_t IDR_IDR1 = 1;             // Port input data (y = 0..15)
    static const uint8_t IDR_IDR0 = 0;             // Port input data (y = 0..15)
    static const uint32_t IDR_RESET_VALUE = 0x0;

    static const uint8_t ODR_ODR15 = 15;           // Port output data (y = 0..15)
    static const uint8_t ODR_ODR14 = 14;           // Port output data (y = 0..15)
    static const uint8_t ODR_ODR13 = 13;           // Port output data (y = 0..15)
    static const uint8_t ODR_ODR12 = 12;           // Port output data (y = 0..15)
    static const uint8_t ODR_ODR11 = 11;           // Port output data (y = 0..15)
    static const uint8_t ODR_ODR10 = 10;           // Port output data (y = 0..15)
    static const uint8_t ODR_ODR9 = 9;             // Port output data (y = 0..15)
    static const uint8_t ODR_ODR8 = 8;             // Port output data (y = 0..15)
    static const uint8_t ODR_ODR7 = 7;             // Port output data (y = 0..15)
    static const uint8_t ODR_ODR6 = 6;             // Port output data (y = 0..15)
    static const uint8_t ODR_ODR5 = 5;             // Port output data (y = 0..15)
    static const uint8_t ODR_ODR4 = 4;             // Port output data (y = 0..15)
    static const uint8_t ODR_ODR3 = 3;             // Port output data (y = 0..15)
    static const uint8_t ODR_ODR2 = 2;             // Port output data (y = 0..15)
    static const uint8_t ODR_ODR1 = 1;             // Port output data (y = 0..15)
    static const uint8_t ODR_ODR0 = 0;             // Port output data (y = 0..15)
    static const uint32_t ODR_RESET_VALUE = 0x0;

    static const uint8_t BSRR_BR15 = 31;            // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR14 = 30;            // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR13 = 29;            // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR12 = 28;            // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR11 = 27;            // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR10 = 26;            // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR9 = 25;             // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR8 = 24;             // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR7 = 23;             // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR6 = 22;             // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR5 = 21;             // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR4 = 20;             // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR3 = 19;             // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR2 = 18;             // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR1 = 17;             // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR0 = 16;             // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS15 = 15;            // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS14 = 14;            // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS13 = 13;            // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS12 = 12;            // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS11 = 11;            // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS10 = 10;            // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS9 = 9;              // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS8 = 8;              // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS7 = 7;              // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS6 = 6;              // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS5 = 5;              // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS4 = 4;              // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS3 = 3;              // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS2 = 2;              // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS1 = 1;              // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS0 = 0;              // Port x set bit y (y= 0..15)
    static const uint32_t BSRR_RESET_VALUE = 0x0;

    static const uint8_t LCKR_LCKK = 16;            // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK15 = 15;           // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK14 = 14;           // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK13 = 13;           // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK12 = 12;           // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK11 = 11;           // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK10 = 10;           // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK9 = 9;             // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK8 = 8;             // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK7 = 7;             // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK6 = 6;             // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK5 = 5;             // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK4 = 4;             // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK3 = 3;             // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK2 = 2;             // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK1 = 1;             // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK0 = 0;             // Port x lock bit y (y= 0..15)
    static const uint32_t LCKR_RESET_VALUE = 0x0;

    static const uint8_t AFRL_AFRL7 = 28;           // Alternate function selection for port x bit y (y = 0..7) (4 bits)
    static const uint8_t AFRL_AFRL6 = 24;           // Alternate function selection for port x bit y (y = 0..7) (4 bits)
    static const uint8_t AFRL_AFRL5 = 20;           // Alternate function selection for port x bit y (y = 0..7) (4 bits)
    static const uint8_t AFRL_AFRL4 = 16;           // Alternate function selection for port x bit y (y = 0..7) (4 bits)
    static const uint8_t AFRL_AFRL3 = 12;           // Alternate function selection for port x bit y (y = 0..7) (4 bits)
    static const uint8_t AFRL_AFRL2 = 8;            // Alternate function selection for port x bit y (y = 0..7) (4 bits)
    static const uint8_t AFRL_AFRL1 = 4;            // Alternate function selection for port x bit y (y = 0..7) (4 bits)
    static const uint8_t AFRL_AFRL0 = 0;            // Alternate function selection for port x bit y (y = 0..7) (4 bits)
    static const uint32_t AFRL_RESET_VALUE = 0x0;

    static const uint8_t AFRH_AFRH15 = 28;          // Alternate function selection for port x bit y (y = 8..15) (4 bits)
    static const uint8_t AFRH_AFRH14 = 24;          // Alternate function selection for port x bit y (y = 8..15) (4 bits)
    static const uint8_t AFRH_AFRH13 = 20;          // Alternate function selection for port x bit y (y = 8..15) (4 bits)
    static const uint8_t AFRH_AFRH12 = 16;          // Alternate function selection for port x bit y (y = 8..15) (4 bits)
    static const uint8_t AFRH_AFRH11 = 12;          // Alternate function selection for port x bit y (y = 8..15) (4 bits)
    static const uint8_t AFRH_AFRH10 = 8;           // Alternate function selection for port x bit y (y = 8..15) (4 bits)
    static const uint8_t AFRH_AFRH9 = 4;            // Alternate function selection for port x bit y (y = 8..15) (4 bits)
    static const uint8_t AFRH_AFRH8 = 0;            // Alternate function selection for port x bit y (y = 8..15) (4 bits)
    static const uint32_t AFRH_RESET_VALUE = 0x0;
};

static gpioc_t& GPIOC = *reinterpret_cast<gpioc_t*>(0x40020800);


////
//
//    General-purpose I/Os
//
////

struct gpiof_t
{
    volatile uint32_t    MODER;                // [Read-write] GPIO port mode register
    volatile uint32_t    OTYPER;               // [Read-write] GPIO port output type register
    volatile uint32_t    OSPEEDR;              // [Read-write] GPIO port output speed register
    volatile uint32_t    PUPDR;                // [Read-write] GPIO port pull-up/pull-down register
    volatile uint32_t    IDR;                  // [Read-only] GPIO port input data register
    volatile uint32_t    ODR;                  // [Read-write] GPIO port output data register
    volatile uint32_t    BSRR;                 // [Write-only] GPIO port bit set/reset register
    volatile uint32_t    LCKR;                 // [Read-write] GPIO port configuration lock register
    volatile uint32_t    AFRL;                 // [Read-write] GPIO alternate function low register
    volatile uint32_t    AFRH;                 // [Read-write] GPIO alternate function high register

    static const uint8_t MODER_MODER15 = 30;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER14 = 28;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER13 = 26;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER12 = 24;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER11 = 22;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER10 = 20;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER9 = 18;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER8 = 16;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER7 = 14;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER6 = 12;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER5 = 10;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER4 = 8;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER3 = 6;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER2 = 4;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER1 = 2;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER0 = 0;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint32_t MODER_RESET_VALUE = 0x0;

    static const uint8_t OTYPER_OT15 = 15;            // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT14 = 14;            // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT13 = 13;            // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT12 = 12;            // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT11 = 11;            // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT10 = 10;            // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT9 = 9;              // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT8 = 8;              // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT7 = 7;              // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT6 = 6;              // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT5 = 5;              // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT4 = 4;              // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT3 = 3;              // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT2 = 2;              // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT1 = 1;              // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT0 = 0;              // Port x configuration bits (y = 0..15)
    static const uint32_t OTYPER_RESET_VALUE = 0x0;

    static const uint8_t OSPEEDR_OSPEEDR15 = 30;       // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR14 = 28;       // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR13 = 26;       // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR12 = 24;       // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR11 = 22;       // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR10 = 20;       // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR9 = 18;        // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR8 = 16;        // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR7 = 14;        // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR6 = 12;        // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR5 = 10;        // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR4 = 8;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR3 = 6;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR2 = 4;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR1 = 2;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR0 = 0;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint32_t OSPEEDR_RESET_VALUE = 0x0;

    static const uint8_t PUPDR_PUPDR15 = 30;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR14 = 28;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR13 = 26;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR12 = 24;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR11 = 22;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR10 = 20;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR9 = 18;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR8 = 16;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR7 = 14;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR6 = 12;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR5 = 10;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR4 = 8;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR3 = 6;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR2 = 4;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR1 = 2;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR0 = 0;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint32_t PUPDR_RESET_VALUE = 0x0;

    static const uint8_t IDR_IDR15 = 15;           // Port input data (y = 0..15)
    static const uint8_t IDR_IDR14 = 14;           // Port input data (y = 0..15)
    static const uint8_t IDR_IDR13 = 13;           // Port input data (y = 0..15)
    static const uint8_t IDR_IDR12 = 12;           // Port input data (y = 0..15)
    static const uint8_t IDR_IDR11 = 11;           // Port input data (y = 0..15)
    static const uint8_t IDR_IDR10 = 10;           // Port input data (y = 0..15)
    static const uint8_t IDR_IDR9 = 9;             // Port input data (y = 0..15)
    static const uint8_t IDR_IDR8 = 8;             // Port input data (y = 0..15)
    static const uint8_t IDR_IDR7 = 7;             // Port input data (y = 0..15)
    static const uint8_t IDR_IDR6 = 6;             // Port input data (y = 0..15)
    static const uint8_t IDR_IDR5 = 5;             // Port input data (y = 0..15)
    static const uint8_t IDR_IDR4 = 4;             // Port input data (y = 0..15)
    static const uint8_t IDR_IDR3 = 3;             // Port input data (y = 0..15)
    static const uint8_t IDR_IDR2 = 2;             // Port input data (y = 0..15)
    static const uint8_t IDR_IDR1 = 1;             // Port input data (y = 0..15)
    static const uint8_t IDR_IDR0 = 0;             // Port input data (y = 0..15)
    static const uint32_t IDR_RESET_VALUE = 0x0;

    static const uint8_t ODR_ODR15 = 15;           // Port output data (y = 0..15)
    static const uint8_t ODR_ODR14 = 14;           // Port output data (y = 0..15)
    static const uint8_t ODR_ODR13 = 13;           // Port output data (y = 0..15)
    static const uint8_t ODR_ODR12 = 12;           // Port output data (y = 0..15)
    static const uint8_t ODR_ODR11 = 11;           // Port output data (y = 0..15)
    static const uint8_t ODR_ODR10 = 10;           // Port output data (y = 0..15)
    static const uint8_t ODR_ODR9 = 9;             // Port output data (y = 0..15)
    static const uint8_t ODR_ODR8 = 8;             // Port output data (y = 0..15)
    static const uint8_t ODR_ODR7 = 7;             // Port output data (y = 0..15)
    static const uint8_t ODR_ODR6 = 6;             // Port output data (y = 0..15)
    static const uint8_t ODR_ODR5 = 5;             // Port output data (y = 0..15)
    static const uint8_t ODR_ODR4 = 4;             // Port output data (y = 0..15)
    static const uint8_t ODR_ODR3 = 3;             // Port output data (y = 0..15)
    static const uint8_t ODR_ODR2 = 2;             // Port output data (y = 0..15)
    static const uint8_t ODR_ODR1 = 1;             // Port output data (y = 0..15)
    static const uint8_t ODR_ODR0 = 0;             // Port output data (y = 0..15)
    static const uint32_t ODR_RESET_VALUE = 0x0;

    static const uint8_t BSRR_BR15 = 31;            // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR14 = 30;            // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR13 = 29;            // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR12 = 28;            // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR11 = 27;            // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR10 = 26;            // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR9 = 25;             // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR8 = 24;             // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR7 = 23;             // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR6 = 22;             // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR5 = 21;             // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR4 = 20;             // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR3 = 19;             // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR2 = 18;             // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR1 = 17;             // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR0 = 16;             // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS15 = 15;            // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS14 = 14;            // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS13 = 13;            // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS12 = 12;            // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS11 = 11;            // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS10 = 10;            // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS9 = 9;              // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS8 = 8;              // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS7 = 7;              // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS6 = 6;              // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS5 = 5;              // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS4 = 4;              // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS3 = 3;              // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS2 = 2;              // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS1 = 1;              // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS0 = 0;              // Port x set bit y (y= 0..15)
    static const uint32_t BSRR_RESET_VALUE = 0x0;

    static const uint8_t LCKR_LCKK = 16;            // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK15 = 15;           // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK14 = 14;           // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK13 = 13;           // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK12 = 12;           // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK11 = 11;           // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK10 = 10;           // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK9 = 9;             // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK8 = 8;             // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK7 = 7;             // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK6 = 6;             // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK5 = 5;             // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK4 = 4;             // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK3 = 3;             // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK2 = 2;             // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK1 = 1;             // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK0 = 0;             // Port x lock bit y (y= 0..15)
    static const uint32_t LCKR_RESET_VALUE = 0x0;

    static const uint8_t AFRL_AFRL7 = 28;           // Alternate function selection for port x bit y (y = 0..7) (4 bits)
    static const uint8_t AFRL_AFRL6 = 24;           // Alternate function selection for port x bit y (y = 0..7) (4 bits)
    static const uint8_t AFRL_AFRL5 = 20;           // Alternate function selection for port x bit y (y = 0..7) (4 bits)
    static const uint8_t AFRL_AFRL4 = 16;           // Alternate function selection for port x bit y (y = 0..7) (4 bits)
    static const uint8_t AFRL_AFRL3 = 12;           // Alternate function selection for port x bit y (y = 0..7) (4 bits)
    static const uint8_t AFRL_AFRL2 = 8;            // Alternate function selection for port x bit y (y = 0..7) (4 bits)
    static const uint8_t AFRL_AFRL1 = 4;            // Alternate function selection for port x bit y (y = 0..7) (4 bits)
    static const uint8_t AFRL_AFRL0 = 0;            // Alternate function selection for port x bit y (y = 0..7) (4 bits)
    static const uint32_t AFRL_RESET_VALUE = 0x0;

    static const uint8_t AFRH_AFRH15 = 28;          // Alternate function selection for port x bit y (y = 8..15) (4 bits)
    static const uint8_t AFRH_AFRH14 = 24;          // Alternate function selection for port x bit y (y = 8..15) (4 bits)
    static const uint8_t AFRH_AFRH13 = 20;          // Alternate function selection for port x bit y (y = 8..15) (4 bits)
    static const uint8_t AFRH_AFRH12 = 16;          // Alternate function selection for port x bit y (y = 8..15) (4 bits)
    static const uint8_t AFRH_AFRH11 = 12;          // Alternate function selection for port x bit y (y = 8..15) (4 bits)
    static const uint8_t AFRH_AFRH10 = 8;           // Alternate function selection for port x bit y (y = 8..15) (4 bits)
    static const uint8_t AFRH_AFRH9 = 4;            // Alternate function selection for port x bit y (y = 8..15) (4 bits)
    static const uint8_t AFRH_AFRH8 = 0;            // Alternate function selection for port x bit y (y = 8..15) (4 bits)
    static const uint32_t AFRH_RESET_VALUE = 0x0;
};

static gpiof_t& GPIOF = *reinterpret_cast<gpiof_t*>(0x40021400);


////
//
//    General-purpose I/Os
//
////

struct gpiog_t
{
    volatile uint32_t    MODER;                // [Read-write] GPIO port mode register
    volatile uint32_t    OTYPER;               // [Read-write] GPIO port output type register
    volatile uint32_t    OSPEEDR;              // [Read-write] GPIO port output speed register
    volatile uint32_t    PUPDR;                // [Read-write] GPIO port pull-up/pull-down register
    volatile uint32_t    IDR;                  // [Read-only] GPIO port input data register
    volatile uint32_t    ODR;                  // [Read-write] GPIO port output data register
    volatile uint32_t    BSRR;                 // [Write-only] GPIO port bit set/reset register
    volatile uint32_t    LCKR;                 // [Read-write] GPIO port configuration lock register
    volatile uint32_t    AFRL;                 // [Read-write] GPIO alternate function low register
    volatile uint32_t    AFRH;                 // [Read-write] GPIO alternate function high register

    static const uint8_t MODER_MODER15 = 30;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER14 = 28;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER13 = 26;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER12 = 24;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER11 = 22;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER10 = 20;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER9 = 18;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER8 = 16;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER7 = 14;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER6 = 12;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER5 = 10;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER4 = 8;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER3 = 6;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER2 = 4;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER1 = 2;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER0 = 0;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint32_t MODER_RESET_VALUE = 0x0;

    static const uint8_t OTYPER_OT15 = 15;            // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT14 = 14;            // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT13 = 13;            // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT12 = 12;            // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT11 = 11;            // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT10 = 10;            // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT9 = 9;              // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT8 = 8;              // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT7 = 7;              // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT6 = 6;              // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT5 = 5;              // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT4 = 4;              // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT3 = 3;              // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT2 = 2;              // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT1 = 1;              // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT0 = 0;              // Port x configuration bits (y = 0..15)
    static const uint32_t OTYPER_RESET_VALUE = 0x0;

    static const uint8_t OSPEEDR_OSPEEDR15 = 30;       // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR14 = 28;       // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR13 = 26;       // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR12 = 24;       // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR11 = 22;       // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR10 = 20;       // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR9 = 18;        // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR8 = 16;        // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR7 = 14;        // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR6 = 12;        // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR5 = 10;        // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR4 = 8;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR3 = 6;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR2 = 4;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR1 = 2;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR0 = 0;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint32_t OSPEEDR_RESET_VALUE = 0x0;

    static const uint8_t PUPDR_PUPDR15 = 30;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR14 = 28;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR13 = 26;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR12 = 24;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR11 = 22;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR10 = 20;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR9 = 18;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR8 = 16;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR7 = 14;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR6 = 12;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR5 = 10;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR4 = 8;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR3 = 6;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR2 = 4;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR1 = 2;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR0 = 0;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint32_t PUPDR_RESET_VALUE = 0x0;

    static const uint8_t IDR_IDR15 = 15;           // Port input data (y = 0..15)
    static const uint8_t IDR_IDR14 = 14;           // Port input data (y = 0..15)
    static const uint8_t IDR_IDR13 = 13;           // Port input data (y = 0..15)
    static const uint8_t IDR_IDR12 = 12;           // Port input data (y = 0..15)
    static const uint8_t IDR_IDR11 = 11;           // Port input data (y = 0..15)
    static const uint8_t IDR_IDR10 = 10;           // Port input data (y = 0..15)
    static const uint8_t IDR_IDR9 = 9;             // Port input data (y = 0..15)
    static const uint8_t IDR_IDR8 = 8;             // Port input data (y = 0..15)
    static const uint8_t IDR_IDR7 = 7;             // Port input data (y = 0..15)
    static const uint8_t IDR_IDR6 = 6;             // Port input data (y = 0..15)
    static const uint8_t IDR_IDR5 = 5;             // Port input data (y = 0..15)
    static const uint8_t IDR_IDR4 = 4;             // Port input data (y = 0..15)
    static const uint8_t IDR_IDR3 = 3;             // Port input data (y = 0..15)
    static const uint8_t IDR_IDR2 = 2;             // Port input data (y = 0..15)
    static const uint8_t IDR_IDR1 = 1;             // Port input data (y = 0..15)
    static const uint8_t IDR_IDR0 = 0;             // Port input data (y = 0..15)
    static const uint32_t IDR_RESET_VALUE = 0x0;

    static const uint8_t ODR_ODR15 = 15;           // Port output data (y = 0..15)
    static const uint8_t ODR_ODR14 = 14;           // Port output data (y = 0..15)
    static const uint8_t ODR_ODR13 = 13;           // Port output data (y = 0..15)
    static const uint8_t ODR_ODR12 = 12;           // Port output data (y = 0..15)
    static const uint8_t ODR_ODR11 = 11;           // Port output data (y = 0..15)
    static const uint8_t ODR_ODR10 = 10;           // Port output data (y = 0..15)
    static const uint8_t ODR_ODR9 = 9;             // Port output data (y = 0..15)
    static const uint8_t ODR_ODR8 = 8;             // Port output data (y = 0..15)
    static const uint8_t ODR_ODR7 = 7;             // Port output data (y = 0..15)
    static const uint8_t ODR_ODR6 = 6;             // Port output data (y = 0..15)
    static const uint8_t ODR_ODR5 = 5;             // Port output data (y = 0..15)
    static const uint8_t ODR_ODR4 = 4;             // Port output data (y = 0..15)
    static const uint8_t ODR_ODR3 = 3;             // Port output data (y = 0..15)
    static const uint8_t ODR_ODR2 = 2;             // Port output data (y = 0..15)
    static const uint8_t ODR_ODR1 = 1;             // Port output data (y = 0..15)
    static const uint8_t ODR_ODR0 = 0;             // Port output data (y = 0..15)
    static const uint32_t ODR_RESET_VALUE = 0x0;

    static const uint8_t BSRR_BR15 = 31;            // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR14 = 30;            // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR13 = 29;            // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR12 = 28;            // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR11 = 27;            // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR10 = 26;            // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR9 = 25;             // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR8 = 24;             // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR7 = 23;             // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR6 = 22;             // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR5 = 21;             // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR4 = 20;             // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR3 = 19;             // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR2 = 18;             // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR1 = 17;             // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR0 = 16;             // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS15 = 15;            // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS14 = 14;            // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS13 = 13;            // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS12 = 12;            // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS11 = 11;            // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS10 = 10;            // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS9 = 9;              // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS8 = 8;              // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS7 = 7;              // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS6 = 6;              // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS5 = 5;              // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS4 = 4;              // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS3 = 3;              // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS2 = 2;              // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS1 = 1;              // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS0 = 0;              // Port x set bit y (y= 0..15)
    static const uint32_t BSRR_RESET_VALUE = 0x0;

    static const uint8_t LCKR_LCKK = 16;            // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK15 = 15;           // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK14 = 14;           // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK13 = 13;           // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK12 = 12;           // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK11 = 11;           // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK10 = 10;           // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK9 = 9;             // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK8 = 8;             // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK7 = 7;             // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK6 = 6;             // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK5 = 5;             // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK4 = 4;             // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK3 = 3;             // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK2 = 2;             // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK1 = 1;             // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK0 = 0;             // Port x lock bit y (y= 0..15)
    static const uint32_t LCKR_RESET_VALUE = 0x0;

    static const uint8_t AFRL_AFRL7 = 28;           // Alternate function selection for port x bit y (y = 0..7) (4 bits)
    static const uint8_t AFRL_AFRL6 = 24;           // Alternate function selection for port x bit y (y = 0..7) (4 bits)
    static const uint8_t AFRL_AFRL5 = 20;           // Alternate function selection for port x bit y (y = 0..7) (4 bits)
    static const uint8_t AFRL_AFRL4 = 16;           // Alternate function selection for port x bit y (y = 0..7) (4 bits)
    static const uint8_t AFRL_AFRL3 = 12;           // Alternate function selection for port x bit y (y = 0..7) (4 bits)
    static const uint8_t AFRL_AFRL2 = 8;            // Alternate function selection for port x bit y (y = 0..7) (4 bits)
    static const uint8_t AFRL_AFRL1 = 4;            // Alternate function selection for port x bit y (y = 0..7) (4 bits)
    static const uint8_t AFRL_AFRL0 = 0;            // Alternate function selection for port x bit y (y = 0..7) (4 bits)
    static const uint32_t AFRL_RESET_VALUE = 0x0;

    static const uint8_t AFRH_AFRH15 = 28;          // Alternate function selection for port x bit y (y = 8..15) (4 bits)
    static const uint8_t AFRH_AFRH14 = 24;          // Alternate function selection for port x bit y (y = 8..15) (4 bits)
    static const uint8_t AFRH_AFRH13 = 20;          // Alternate function selection for port x bit y (y = 8..15) (4 bits)
    static const uint8_t AFRH_AFRH12 = 16;          // Alternate function selection for port x bit y (y = 8..15) (4 bits)
    static const uint8_t AFRH_AFRH11 = 12;          // Alternate function selection for port x bit y (y = 8..15) (4 bits)
    static const uint8_t AFRH_AFRH10 = 8;           // Alternate function selection for port x bit y (y = 8..15) (4 bits)
    static const uint8_t AFRH_AFRH9 = 4;            // Alternate function selection for port x bit y (y = 8..15) (4 bits)
    static const uint8_t AFRH_AFRH8 = 0;            // Alternate function selection for port x bit y (y = 8..15) (4 bits)
    static const uint32_t AFRH_RESET_VALUE = 0x0;
};

static gpiog_t& GPIOG = *reinterpret_cast<gpiog_t*>(0x40021800);


////
//
//    General-purpose I/Os
//
////

struct gpiob_t
{
    volatile uint32_t    MODER;                // [Read-write] GPIO port mode register
    volatile uint32_t    OTYPER;               // [Read-write] GPIO port output type register
    volatile uint32_t    OSPEEDR;              // [Read-write] GPIO port output speed register
    volatile uint32_t    PUPDR;                // [Read-write] GPIO port pull-up/pull-down register
    volatile uint32_t    IDR;                  // [Read-only] GPIO port input data register
    volatile uint32_t    ODR;                  // [Read-write] GPIO port output data register
    volatile uint32_t    BSRR;                 // [Write-only] GPIO port bit set/reset register
    volatile uint32_t    LCKR;                 // [Read-write] GPIO port configuration lock register
    volatile uint32_t    AFRL;                 // [Read-write] GPIO alternate function low register
    volatile uint32_t    AFRH;                 // [Read-write] GPIO alternate function high register

    static const uint8_t MODER_MODER15 = 30;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER14 = 28;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER13 = 26;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER12 = 24;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER11 = 22;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER10 = 20;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER9 = 18;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER8 = 16;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER7 = 14;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER6 = 12;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER5 = 10;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER4 = 8;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER3 = 6;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER2 = 4;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER1 = 2;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER0 = 0;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint32_t MODER_RESET_VALUE = 0x280;

    static const uint8_t OTYPER_OT15 = 15;            // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT14 = 14;            // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT13 = 13;            // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT12 = 12;            // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT11 = 11;            // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT10 = 10;            // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT9 = 9;              // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT8 = 8;              // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT7 = 7;              // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT6 = 6;              // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT5 = 5;              // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT4 = 4;              // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT3 = 3;              // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT2 = 2;              // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT1 = 1;              // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT0 = 0;              // Port x configuration bits (y = 0..15)
    static const uint32_t OTYPER_RESET_VALUE = 0x0;

    static const uint8_t OSPEEDR_OSPEEDR15 = 30;       // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR14 = 28;       // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR13 = 26;       // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR12 = 24;       // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR11 = 22;       // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR10 = 20;       // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR9 = 18;        // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR8 = 16;        // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR7 = 14;        // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR6 = 12;        // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR5 = 10;        // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR4 = 8;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR3 = 6;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR2 = 4;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR1 = 2;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR0 = 0;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint32_t OSPEEDR_RESET_VALUE = 0xc0;

    static const uint8_t PUPDR_PUPDR15 = 30;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR14 = 28;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR13 = 26;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR12 = 24;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR11 = 22;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR10 = 20;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR9 = 18;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR8 = 16;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR7 = 14;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR6 = 12;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR5 = 10;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR4 = 8;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR3 = 6;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR2 = 4;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR1 = 2;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR0 = 0;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint32_t PUPDR_RESET_VALUE = 0x100;

    static const uint8_t IDR_IDR15 = 15;           // Port input data (y = 0..15)
    static const uint8_t IDR_IDR14 = 14;           // Port input data (y = 0..15)
    static const uint8_t IDR_IDR13 = 13;           // Port input data (y = 0..15)
    static const uint8_t IDR_IDR12 = 12;           // Port input data (y = 0..15)
    static const uint8_t IDR_IDR11 = 11;           // Port input data (y = 0..15)
    static const uint8_t IDR_IDR10 = 10;           // Port input data (y = 0..15)
    static const uint8_t IDR_IDR9 = 9;             // Port input data (y = 0..15)
    static const uint8_t IDR_IDR8 = 8;             // Port input data (y = 0..15)
    static const uint8_t IDR_IDR7 = 7;             // Port input data (y = 0..15)
    static const uint8_t IDR_IDR6 = 6;             // Port input data (y = 0..15)
    static const uint8_t IDR_IDR5 = 5;             // Port input data (y = 0..15)
    static const uint8_t IDR_IDR4 = 4;             // Port input data (y = 0..15)
    static const uint8_t IDR_IDR3 = 3;             // Port input data (y = 0..15)
    static const uint8_t IDR_IDR2 = 2;             // Port input data (y = 0..15)
    static const uint8_t IDR_IDR1 = 1;             // Port input data (y = 0..15)
    static const uint8_t IDR_IDR0 = 0;             // Port input data (y = 0..15)
    static const uint32_t IDR_RESET_VALUE = 0x0;

    static const uint8_t ODR_ODR15 = 15;           // Port output data (y = 0..15)
    static const uint8_t ODR_ODR14 = 14;           // Port output data (y = 0..15)
    static const uint8_t ODR_ODR13 = 13;           // Port output data (y = 0..15)
    static const uint8_t ODR_ODR12 = 12;           // Port output data (y = 0..15)
    static const uint8_t ODR_ODR11 = 11;           // Port output data (y = 0..15)
    static const uint8_t ODR_ODR10 = 10;           // Port output data (y = 0..15)
    static const uint8_t ODR_ODR9 = 9;             // Port output data (y = 0..15)
    static const uint8_t ODR_ODR8 = 8;             // Port output data (y = 0..15)
    static const uint8_t ODR_ODR7 = 7;             // Port output data (y = 0..15)
    static const uint8_t ODR_ODR6 = 6;             // Port output data (y = 0..15)
    static const uint8_t ODR_ODR5 = 5;             // Port output data (y = 0..15)
    static const uint8_t ODR_ODR4 = 4;             // Port output data (y = 0..15)
    static const uint8_t ODR_ODR3 = 3;             // Port output data (y = 0..15)
    static const uint8_t ODR_ODR2 = 2;             // Port output data (y = 0..15)
    static const uint8_t ODR_ODR1 = 1;             // Port output data (y = 0..15)
    static const uint8_t ODR_ODR0 = 0;             // Port output data (y = 0..15)
    static const uint32_t ODR_RESET_VALUE = 0x0;

    static const uint8_t BSRR_BR15 = 31;            // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR14 = 30;            // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR13 = 29;            // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR12 = 28;            // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR11 = 27;            // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR10 = 26;            // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR9 = 25;             // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR8 = 24;             // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR7 = 23;             // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR6 = 22;             // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR5 = 21;             // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR4 = 20;             // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR3 = 19;             // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR2 = 18;             // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR1 = 17;             // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR0 = 16;             // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS15 = 15;            // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS14 = 14;            // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS13 = 13;            // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS12 = 12;            // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS11 = 11;            // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS10 = 10;            // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS9 = 9;              // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS8 = 8;              // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS7 = 7;              // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS6 = 6;              // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS5 = 5;              // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS4 = 4;              // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS3 = 3;              // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS2 = 2;              // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS1 = 1;              // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS0 = 0;              // Port x set bit y (y= 0..15)
    static const uint32_t BSRR_RESET_VALUE = 0x0;

    static const uint8_t LCKR_LCKK = 16;            // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK15 = 15;           // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK14 = 14;           // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK13 = 13;           // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK12 = 12;           // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK11 = 11;           // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK10 = 10;           // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK9 = 9;             // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK8 = 8;             // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK7 = 7;             // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK6 = 6;             // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK5 = 5;             // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK4 = 4;             // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK3 = 3;             // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK2 = 2;             // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK1 = 1;             // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK0 = 0;             // Port x lock bit y (y= 0..15)
    static const uint32_t LCKR_RESET_VALUE = 0x0;

    static const uint8_t AFRL_AFRL7 = 28;           // Alternate function selection for port x bit y (y = 0..7) (4 bits)
    static const uint8_t AFRL_AFRL6 = 24;           // Alternate function selection for port x bit y (y = 0..7) (4 bits)
    static const uint8_t AFRL_AFRL5 = 20;           // Alternate function selection for port x bit y (y = 0..7) (4 bits)
    static const uint8_t AFRL_AFRL4 = 16;           // Alternate function selection for port x bit y (y = 0..7) (4 bits)
    static const uint8_t AFRL_AFRL3 = 12;           // Alternate function selection for port x bit y (y = 0..7) (4 bits)
    static const uint8_t AFRL_AFRL2 = 8;            // Alternate function selection for port x bit y (y = 0..7) (4 bits)
    static const uint8_t AFRL_AFRL1 = 4;            // Alternate function selection for port x bit y (y = 0..7) (4 bits)
    static const uint8_t AFRL_AFRL0 = 0;            // Alternate function selection for port x bit y (y = 0..7) (4 bits)
    static const uint32_t AFRL_RESET_VALUE = 0x0;

    static const uint8_t AFRH_AFRH15 = 28;          // Alternate function selection for port x bit y (y = 8..15) (4 bits)
    static const uint8_t AFRH_AFRH14 = 24;          // Alternate function selection for port x bit y (y = 8..15) (4 bits)
    static const uint8_t AFRH_AFRH13 = 20;          // Alternate function selection for port x bit y (y = 8..15) (4 bits)
    static const uint8_t AFRH_AFRH12 = 16;          // Alternate function selection for port x bit y (y = 8..15) (4 bits)
    static const uint8_t AFRH_AFRH11 = 12;          // Alternate function selection for port x bit y (y = 8..15) (4 bits)
    static const uint8_t AFRH_AFRH10 = 8;           // Alternate function selection for port x bit y (y = 8..15) (4 bits)
    static const uint8_t AFRH_AFRH9 = 4;            // Alternate function selection for port x bit y (y = 8..15) (4 bits)
    static const uint8_t AFRH_AFRH8 = 0;            // Alternate function selection for port x bit y (y = 8..15) (4 bits)
    static const uint32_t AFRH_RESET_VALUE = 0x0;
};

static gpiob_t& GPIOB = *reinterpret_cast<gpiob_t*>(0x40020400);


////
//
//    General-purpose I/Os
//
////

struct gpioa_t
{
    volatile uint32_t    MODER;                // [Read-write] GPIO port mode register
    volatile uint32_t    OTYPER;               // [Read-write] GPIO port output type register
    volatile uint32_t    OSPEEDR;              // [Read-write] GPIO port output speed register
    volatile uint32_t    PUPDR;                // [Read-write] GPIO port pull-up/pull-down register
    volatile uint32_t    IDR;                  // [Read-only] GPIO port input data register
    volatile uint32_t    ODR;                  // [Read-write] GPIO port output data register
    volatile uint32_t    BSRR;                 // [Write-only] GPIO port bit set/reset register
    volatile uint32_t    LCKR;                 // [Read-write] GPIO port configuration lock register
    volatile uint32_t    AFRL;                 // [Read-write] GPIO alternate function low register
    volatile uint32_t    AFRH;                 // [Read-write] GPIO alternate function high register

    static const uint8_t MODER_MODER15 = 30;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER14 = 28;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER13 = 26;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER12 = 24;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER11 = 22;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER10 = 20;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER9 = 18;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER8 = 16;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER7 = 14;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER6 = 12;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER5 = 10;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER4 = 8;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER3 = 6;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER2 = 4;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER1 = 2;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t MODER_MODER0 = 0;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint32_t MODER_RESET_VALUE = 0xa8000000;

    static const uint8_t OTYPER_OT15 = 15;            // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT14 = 14;            // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT13 = 13;            // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT12 = 12;            // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT11 = 11;            // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT10 = 10;            // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT9 = 9;              // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT8 = 8;              // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT7 = 7;              // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT6 = 6;              // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT5 = 5;              // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT4 = 4;              // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT3 = 3;              // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT2 = 2;              // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT1 = 1;              // Port x configuration bits (y = 0..15)
    static const uint8_t OTYPER_OT0 = 0;              // Port x configuration bits (y = 0..15)
    static const uint32_t OTYPER_RESET_VALUE = 0x0;

    static const uint8_t OSPEEDR_OSPEEDR15 = 30;       // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR14 = 28;       // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR13 = 26;       // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR12 = 24;       // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR11 = 22;       // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR10 = 20;       // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR9 = 18;        // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR8 = 16;        // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR7 = 14;        // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR6 = 12;        // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR5 = 10;        // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR4 = 8;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR3 = 6;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR2 = 4;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR1 = 2;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t OSPEEDR_OSPEEDR0 = 0;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint32_t OSPEEDR_RESET_VALUE = 0x0;

    static const uint8_t PUPDR_PUPDR15 = 30;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR14 = 28;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR13 = 26;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR12 = 24;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR11 = 22;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR10 = 20;         // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR9 = 18;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR8 = 16;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR7 = 14;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR6 = 12;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR5 = 10;          // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR4 = 8;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR3 = 6;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR2 = 4;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR1 = 2;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint8_t PUPDR_PUPDR0 = 0;           // Port x configuration bits (y = 0..15) (2 bits)
    static const uint32_t PUPDR_RESET_VALUE = 0x64000000;

    static const uint8_t IDR_IDR15 = 15;           // Port input data (y = 0..15)
    static const uint8_t IDR_IDR14 = 14;           // Port input data (y = 0..15)
    static const uint8_t IDR_IDR13 = 13;           // Port input data (y = 0..15)
    static const uint8_t IDR_IDR12 = 12;           // Port input data (y = 0..15)
    static const uint8_t IDR_IDR11 = 11;           // Port input data (y = 0..15)
    static const uint8_t IDR_IDR10 = 10;           // Port input data (y = 0..15)
    static const uint8_t IDR_IDR9 = 9;             // Port input data (y = 0..15)
    static const uint8_t IDR_IDR8 = 8;             // Port input data (y = 0..15)
    static const uint8_t IDR_IDR7 = 7;             // Port input data (y = 0..15)
    static const uint8_t IDR_IDR6 = 6;             // Port input data (y = 0..15)
    static const uint8_t IDR_IDR5 = 5;             // Port input data (y = 0..15)
    static const uint8_t IDR_IDR4 = 4;             // Port input data (y = 0..15)
    static const uint8_t IDR_IDR3 = 3;             // Port input data (y = 0..15)
    static const uint8_t IDR_IDR2 = 2;             // Port input data (y = 0..15)
    static const uint8_t IDR_IDR1 = 1;             // Port input data (y = 0..15)
    static const uint8_t IDR_IDR0 = 0;             // Port input data (y = 0..15)
    static const uint32_t IDR_RESET_VALUE = 0x0;

    static const uint8_t ODR_ODR15 = 15;           // Port output data (y = 0..15)
    static const uint8_t ODR_ODR14 = 14;           // Port output data (y = 0..15)
    static const uint8_t ODR_ODR13 = 13;           // Port output data (y = 0..15)
    static const uint8_t ODR_ODR12 = 12;           // Port output data (y = 0..15)
    static const uint8_t ODR_ODR11 = 11;           // Port output data (y = 0..15)
    static const uint8_t ODR_ODR10 = 10;           // Port output data (y = 0..15)
    static const uint8_t ODR_ODR9 = 9;             // Port output data (y = 0..15)
    static const uint8_t ODR_ODR8 = 8;             // Port output data (y = 0..15)
    static const uint8_t ODR_ODR7 = 7;             // Port output data (y = 0..15)
    static const uint8_t ODR_ODR6 = 6;             // Port output data (y = 0..15)
    static const uint8_t ODR_ODR5 = 5;             // Port output data (y = 0..15)
    static const uint8_t ODR_ODR4 = 4;             // Port output data (y = 0..15)
    static const uint8_t ODR_ODR3 = 3;             // Port output data (y = 0..15)
    static const uint8_t ODR_ODR2 = 2;             // Port output data (y = 0..15)
    static const uint8_t ODR_ODR1 = 1;             // Port output data (y = 0..15)
    static const uint8_t ODR_ODR0 = 0;             // Port output data (y = 0..15)
    static const uint32_t ODR_RESET_VALUE = 0x0;

    static const uint8_t BSRR_BR15 = 31;            // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR14 = 30;            // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR13 = 29;            // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR12 = 28;            // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR11 = 27;            // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR10 = 26;            // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR9 = 25;             // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR8 = 24;             // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR7 = 23;             // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR6 = 22;             // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR5 = 21;             // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR4 = 20;             // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR3 = 19;             // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR2 = 18;             // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR1 = 17;             // Port x reset bit y (y = 0..15)
    static const uint8_t BSRR_BR0 = 16;             // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS15 = 15;            // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS14 = 14;            // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS13 = 13;            // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS12 = 12;            // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS11 = 11;            // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS10 = 10;            // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS9 = 9;              // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS8 = 8;              // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS7 = 7;              // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS6 = 6;              // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS5 = 5;              // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS4 = 4;              // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS3 = 3;              // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS2 = 2;              // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS1 = 1;              // Port x set bit y (y= 0..15)
    static const uint8_t BSRR_BS0 = 0;              // Port x set bit y (y= 0..15)
    static const uint32_t BSRR_RESET_VALUE = 0x0;

    static const uint8_t LCKR_LCKK = 16;            // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK15 = 15;           // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK14 = 14;           // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK13 = 13;           // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK12 = 12;           // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK11 = 11;           // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK10 = 10;           // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK9 = 9;             // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK8 = 8;             // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK7 = 7;             // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK6 = 6;             // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK5 = 5;             // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK4 = 4;             // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK3 = 3;             // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK2 = 2;             // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK1 = 1;             // Port x lock bit y (y= 0..15)
    static const uint8_t LCKR_LCK0 = 0;             // Port x lock bit y (y= 0..15)
    static const uint32_t LCKR_RESET_VALUE = 0x0;

    static const uint8_t AFRL_AFRL7 = 28;           // Alternate function selection for port x bit y (y = 0..7) (4 bits)
    static const uint8_t AFRL_AFRL6 = 24;           // Alternate function selection for port x bit y (y = 0..7) (4 bits)
    static const uint8_t AFRL_AFRL5 = 20;           // Alternate function selection for port x bit y (y = 0..7) (4 bits)
    static const uint8_t AFRL_AFRL4 = 16;           // Alternate function selection for port x bit y (y = 0..7) (4 bits)
    static const uint8_t AFRL_AFRL3 = 12;           // Alternate function selection for port x bit y (y = 0..7) (4 bits)
    static const uint8_t AFRL_AFRL2 = 8;            // Alternate function selection for port x bit y (y = 0..7) (4 bits)
    static const uint8_t AFRL_AFRL1 = 4;            // Alternate function selection for port x bit y (y = 0..7) (4 bits)
    static const uint8_t AFRL_AFRL0 = 0;            // Alternate function selection for port x bit y (y = 0..7) (4 bits)
    static const uint32_t AFRL_RESET_VALUE = 0x0;

    static const uint8_t AFRH_AFRH15 = 28;          // Alternate function selection for port x bit y (y = 8..15) (4 bits)
    static const uint8_t AFRH_AFRH14 = 24;          // Alternate function selection for port x bit y (y = 8..15) (4 bits)
    static const uint8_t AFRH_AFRH13 = 20;          // Alternate function selection for port x bit y (y = 8..15) (4 bits)
    static const uint8_t AFRH_AFRH12 = 16;          // Alternate function selection for port x bit y (y = 8..15) (4 bits)
    static const uint8_t AFRH_AFRH11 = 12;          // Alternate function selection for port x bit y (y = 8..15) (4 bits)
    static const uint8_t AFRH_AFRH10 = 8;           // Alternate function selection for port x bit y (y = 8..15) (4 bits)
    static const uint8_t AFRH_AFRH9 = 4;            // Alternate function selection for port x bit y (y = 8..15) (4 bits)
    static const uint8_t AFRH_AFRH8 = 0;            // Alternate function selection for port x bit y (y = 8..15) (4 bits)
    static const uint32_t AFRH_RESET_VALUE = 0x0;
};

static gpioa_t& GPIOA = *reinterpret_cast<gpioa_t*>(0x40020000);


////
//
//    Inter-integrated circuit
//
////

struct i2c3_t
{
    volatile uint32_t    CR1;                  // [Read-write] Control register 1
    volatile uint32_t    CR2;                  // [Read-write] Control register 2
    volatile uint32_t    OAR1;                 // [Read-write] Own address register 1
    volatile uint32_t    OAR2;                 // [Read-write] Own address register 2
    volatile uint32_t    DR;                   // [Read-write] Data register
    volatile uint32_t    SR1;                  // Status register 1
    volatile uint32_t    SR2;                  // [Read-only] Status register 2
    volatile uint32_t    CCR;                  // [Read-write] Clock control register
    volatile uint32_t    TRISE;                // [Read-write] TRISE register

    static const uint8_t CR1_SWRST = 15;           // Software reset
    static const uint8_t CR1_ALERT = 13;           // SMBus alert
    static const uint8_t CR1_PEC = 12;             // Packet error checking
    static const uint8_t CR1_POS = 11;             // Acknowledge/PEC Position (for data reception)
    static const uint8_t CR1_ACK = 10;             // Acknowledge enable
    static const uint8_t CR1_STOP = 9;             // Stop generation
    static const uint8_t CR1_START = 8;            // Start generation
    static const uint8_t CR1_NOSTRETCH = 7;        // Clock stretching disable (Slave mode)
    static const uint8_t CR1_ENGC = 6;             // General call enable
    static const uint8_t CR1_ENPEC = 5;            // PEC enable
    static const uint8_t CR1_ENARP = 4;            // ARP enable
    static const uint8_t CR1_SMBTYPE = 3;          // SMBus type
    static const uint8_t CR1_SMBUS = 1;            // SMBus mode
    static const uint8_t CR1_PE = 0;               // Peripheral enable
    static const uint32_t CR1_RESET_VALUE = 0x0;

    static const uint8_t CR2_LAST = 12;            // DMA last transfer
    static const uint8_t CR2_DMAEN = 11;           // DMA requests enable
    static const uint8_t CR2_ITBUFEN = 10;         // Buffer interrupt enable
    static const uint8_t CR2_ITEVTEN = 9;          // Event interrupt enable
    static const uint8_t CR2_ITERREN = 8;          // Error interrupt enable
    static const uint8_t CR2_FREQ = 0;             // Peripheral clock frequency (6 bits)
    static const uint32_t CR2_RESET_VALUE = 0x0;

    static const uint8_t OAR1_ADDMODE = 15;         // Addressing mode (slave mode)
    static const uint8_t OAR1_ADD10 = 8;            // Interface address (2 bits)
    static const uint8_t OAR1_ADD7 = 1;             // Interface address (7 bits)
    static const uint8_t OAR1_ADD0 = 0;             // Interface address
    static const uint32_t OAR1_RESET_VALUE = 0x0;

    static const uint8_t OAR2_ADD2 = 1;             // Interface address (7 bits)
    static const uint8_t OAR2_ENDUAL = 0;           // Dual addressing mode enable
    static const uint32_t OAR2_RESET_VALUE = 0x0;

    static const uint8_t DR_DR = 0;               // 8-bit data register (8 bits)
    static const uint32_t DR_RESET_VALUE = 0x0;

    static const uint8_t SR1_SMBALERT = 15;        // SMBus alert, Read-write
    static const uint8_t SR1_TIMEOUT = 14;         // Timeout or Tlow error, Read-write
    static const uint8_t SR1_PECERR = 12;          // PEC Error in reception, Read-write
    static const uint8_t SR1_OVR = 11;             // Overrun/Underrun, Read-write
    static const uint8_t SR1_AF = 10;              // Acknowledge failure, Read-write
    static const uint8_t SR1_ARLO = 9;             // Arbitration lost (master mode), Read-write
    static const uint8_t SR1_BERR = 8;             // Bus error, Read-write
    static const uint8_t SR1_TxE = 7;              // Data register empty (transmitters), Read-only
    static const uint8_t SR1_RxNE = 6;             // Data register not empty (receivers), Read-only
    static const uint8_t SR1_STOPF = 4;            // Stop detection (slave mode), Read-only
    static const uint8_t SR1_ADD10 = 3;            // 10-bit header sent (Master mode), Read-only
    static const uint8_t SR1_BTF = 2;              // Byte transfer finished, Read-only
    static const uint8_t SR1_ADDR = 1;             // Address sent (master mode)/matched (slave mode), Read-only
    static const uint8_t SR1_SB = 0;               // Start bit (Master mode), Read-only
    static const uint32_t SR1_RESET_VALUE = 0x0;

    static const uint8_t SR2_PEC = 8;              // acket error checking register (8 bits)
    static const uint8_t SR2_DUALF = 7;            // Dual flag (Slave mode)
    static const uint8_t SR2_SMBHOST = 6;          // SMBus host header (Slave mode)
    static const uint8_t SR2_SMBDEFAULT = 5;       // SMBus device default address (Slave mode)
    static const uint8_t SR2_GENCALL = 4;          // General call address (Slave mode)
    static const uint8_t SR2_TRA = 2;              // Transmitter/receiver
    static const uint8_t SR2_BUSY = 1;             // Bus busy
    static const uint8_t SR2_MSL = 0;              // Master/slave
    static const uint32_t SR2_RESET_VALUE = 0x0;

    static const uint8_t CCR_F_S = 15;             // I2C master mode selection
    static const uint8_t CCR_DUTY = 14;            // Fast mode duty cycle
    static const uint8_t CCR_CCR = 0;              // Clock control register in Fast/Standard mode (Master mode) (12 bits)
    static const uint32_t CCR_RESET_VALUE = 0x0;

    static const uint8_t TRISE_TRISE = 0;            // Maximum rise time in Fast/Standard mode (Master mode) (6 bits)
    static const uint32_t TRISE_RESET_VALUE = 0x2;
};

static i2c3_t& I2C3 = *reinterpret_cast<i2c3_t*>(0x40005c00);


////
//
//    Inter-integrated circuit
//
////

struct i2c2_t
{
    volatile uint32_t    CR1;                  // [Read-write] Control register 1
    volatile uint32_t    CR2;                  // [Read-write] Control register 2
    volatile uint32_t    OAR1;                 // [Read-write] Own address register 1
    volatile uint32_t    OAR2;                 // [Read-write] Own address register 2
    volatile uint32_t    DR;                   // [Read-write] Data register
    volatile uint32_t    SR1;                  // Status register 1
    volatile uint32_t    SR2;                  // [Read-only] Status register 2
    volatile uint32_t    CCR;                  // [Read-write] Clock control register
    volatile uint32_t    TRISE;                // [Read-write] TRISE register

    static const uint8_t CR1_SWRST = 15;           // Software reset
    static const uint8_t CR1_ALERT = 13;           // SMBus alert
    static const uint8_t CR1_PEC = 12;             // Packet error checking
    static const uint8_t CR1_POS = 11;             // Acknowledge/PEC Position (for data reception)
    static const uint8_t CR1_ACK = 10;             // Acknowledge enable
    static const uint8_t CR1_STOP = 9;             // Stop generation
    static const uint8_t CR1_START = 8;            // Start generation
    static const uint8_t CR1_NOSTRETCH = 7;        // Clock stretching disable (Slave mode)
    static const uint8_t CR1_ENGC = 6;             // General call enable
    static const uint8_t CR1_ENPEC = 5;            // PEC enable
    static const uint8_t CR1_ENARP = 4;            // ARP enable
    static const uint8_t CR1_SMBTYPE = 3;          // SMBus type
    static const uint8_t CR1_SMBUS = 1;            // SMBus mode
    static const uint8_t CR1_PE = 0;               // Peripheral enable
    static const uint32_t CR1_RESET_VALUE = 0x0;

    static const uint8_t CR2_LAST = 12;            // DMA last transfer
    static const uint8_t CR2_DMAEN = 11;           // DMA requests enable
    static const uint8_t CR2_ITBUFEN = 10;         // Buffer interrupt enable
    static const uint8_t CR2_ITEVTEN = 9;          // Event interrupt enable
    static const uint8_t CR2_ITERREN = 8;          // Error interrupt enable
    static const uint8_t CR2_FREQ = 0;             // Peripheral clock frequency (6 bits)
    static const uint32_t CR2_RESET_VALUE = 0x0;

    static const uint8_t OAR1_ADDMODE = 15;         // Addressing mode (slave mode)
    static const uint8_t OAR1_ADD10 = 8;            // Interface address (2 bits)
    static const uint8_t OAR1_ADD7 = 1;             // Interface address (7 bits)
    static const uint8_t OAR1_ADD0 = 0;             // Interface address
    static const uint32_t OAR1_RESET_VALUE = 0x0;

    static const uint8_t OAR2_ADD2 = 1;             // Interface address (7 bits)
    static const uint8_t OAR2_ENDUAL = 0;           // Dual addressing mode enable
    static const uint32_t OAR2_RESET_VALUE = 0x0;

    static const uint8_t DR_DR = 0;               // 8-bit data register (8 bits)
    static const uint32_t DR_RESET_VALUE = 0x0;

    static const uint8_t SR1_SMBALERT = 15;        // SMBus alert, Read-write
    static const uint8_t SR1_TIMEOUT = 14;         // Timeout or Tlow error, Read-write
    static const uint8_t SR1_PECERR = 12;          // PEC Error in reception, Read-write
    static const uint8_t SR1_OVR = 11;             // Overrun/Underrun, Read-write
    static const uint8_t SR1_AF = 10;              // Acknowledge failure, Read-write
    static const uint8_t SR1_ARLO = 9;             // Arbitration lost (master mode), Read-write
    static const uint8_t SR1_BERR = 8;             // Bus error, Read-write
    static const uint8_t SR1_TxE = 7;              // Data register empty (transmitters), Read-only
    static const uint8_t SR1_RxNE = 6;             // Data register not empty (receivers), Read-only
    static const uint8_t SR1_STOPF = 4;            // Stop detection (slave mode), Read-only
    static const uint8_t SR1_ADD10 = 3;            // 10-bit header sent (Master mode), Read-only
    static const uint8_t SR1_BTF = 2;              // Byte transfer finished, Read-only
    static const uint8_t SR1_ADDR = 1;             // Address sent (master mode)/matched (slave mode), Read-only
    static const uint8_t SR1_SB = 0;               // Start bit (Master mode), Read-only
    static const uint32_t SR1_RESET_VALUE = 0x0;

    static const uint8_t SR2_PEC = 8;              // acket error checking register (8 bits)
    static const uint8_t SR2_DUALF = 7;            // Dual flag (Slave mode)
    static const uint8_t SR2_SMBHOST = 6;          // SMBus host header (Slave mode)
    static const uint8_t SR2_SMBDEFAULT = 5;       // SMBus device default address (Slave mode)
    static const uint8_t SR2_GENCALL = 4;          // General call address (Slave mode)
    static const uint8_t SR2_TRA = 2;              // Transmitter/receiver
    static const uint8_t SR2_BUSY = 1;             // Bus busy
    static const uint8_t SR2_MSL = 0;              // Master/slave
    static const uint32_t SR2_RESET_VALUE = 0x0;

    static const uint8_t CCR_F_S = 15;             // I2C master mode selection
    static const uint8_t CCR_DUTY = 14;            // Fast mode duty cycle
    static const uint8_t CCR_CCR = 0;              // Clock control register in Fast/Standard mode (Master mode) (12 bits)
    static const uint32_t CCR_RESET_VALUE = 0x0;

    static const uint8_t TRISE_TRISE = 0;            // Maximum rise time in Fast/Standard mode (Master mode) (6 bits)
    static const uint32_t TRISE_RESET_VALUE = 0x2;
};

static i2c2_t& I2C2 = *reinterpret_cast<i2c2_t*>(0x40005800);


////
//
//    Inter-integrated circuit
//
////

struct i2c1_t
{
    volatile uint32_t    CR1;                  // [Read-write] Control register 1
    volatile uint32_t    CR2;                  // [Read-write] Control register 2
    volatile uint32_t    OAR1;                 // [Read-write] Own address register 1
    volatile uint32_t    OAR2;                 // [Read-write] Own address register 2
    volatile uint32_t    DR;                   // [Read-write] Data register
    volatile uint32_t    SR1;                  // Status register 1
    volatile uint32_t    SR2;                  // [Read-only] Status register 2
    volatile uint32_t    CCR;                  // [Read-write] Clock control register
    volatile uint32_t    TRISE;                // [Read-write] TRISE register

    static const uint8_t CR1_SWRST = 15;           // Software reset
    static const uint8_t CR1_ALERT = 13;           // SMBus alert
    static const uint8_t CR1_PEC = 12;             // Packet error checking
    static const uint8_t CR1_POS = 11;             // Acknowledge/PEC Position (for data reception)
    static const uint8_t CR1_ACK = 10;             // Acknowledge enable
    static const uint8_t CR1_STOP = 9;             // Stop generation
    static const uint8_t CR1_START = 8;            // Start generation
    static const uint8_t CR1_NOSTRETCH = 7;        // Clock stretching disable (Slave mode)
    static const uint8_t CR1_ENGC = 6;             // General call enable
    static const uint8_t CR1_ENPEC = 5;            // PEC enable
    static const uint8_t CR1_ENARP = 4;            // ARP enable
    static const uint8_t CR1_SMBTYPE = 3;          // SMBus type
    static const uint8_t CR1_SMBUS = 1;            // SMBus mode
    static const uint8_t CR1_PE = 0;               // Peripheral enable
    static const uint32_t CR1_RESET_VALUE = 0x0;

    static const uint8_t CR2_LAST = 12;            // DMA last transfer
    static const uint8_t CR2_DMAEN = 11;           // DMA requests enable
    static const uint8_t CR2_ITBUFEN = 10;         // Buffer interrupt enable
    static const uint8_t CR2_ITEVTEN = 9;          // Event interrupt enable
    static const uint8_t CR2_ITERREN = 8;          // Error interrupt enable
    static const uint8_t CR2_FREQ = 0;             // Peripheral clock frequency (6 bits)
    static const uint32_t CR2_RESET_VALUE = 0x0;

    static const uint8_t OAR1_ADDMODE = 15;         // Addressing mode (slave mode)
    static const uint8_t OAR1_ADD10 = 8;            // Interface address (2 bits)
    static const uint8_t OAR1_ADD7 = 1;             // Interface address (7 bits)
    static const uint8_t OAR1_ADD0 = 0;             // Interface address
    static const uint32_t OAR1_RESET_VALUE = 0x0;

    static const uint8_t OAR2_ADD2 = 1;             // Interface address (7 bits)
    static const uint8_t OAR2_ENDUAL = 0;           // Dual addressing mode enable
    static const uint32_t OAR2_RESET_VALUE = 0x0;

    static const uint8_t DR_DR = 0;               // 8-bit data register (8 bits)
    static const uint32_t DR_RESET_VALUE = 0x0;

    static const uint8_t SR1_SMBALERT = 15;        // SMBus alert, Read-write
    static const uint8_t SR1_TIMEOUT = 14;         // Timeout or Tlow error, Read-write
    static const uint8_t SR1_PECERR = 12;          // PEC Error in reception, Read-write
    static const uint8_t SR1_OVR = 11;             // Overrun/Underrun, Read-write
    static const uint8_t SR1_AF = 10;              // Acknowledge failure, Read-write
    static const uint8_t SR1_ARLO = 9;             // Arbitration lost (master mode), Read-write
    static const uint8_t SR1_BERR = 8;             // Bus error, Read-write
    static const uint8_t SR1_TxE = 7;              // Data register empty (transmitters), Read-only
    static const uint8_t SR1_RxNE = 6;             // Data register not empty (receivers), Read-only
    static const uint8_t SR1_STOPF = 4;            // Stop detection (slave mode), Read-only
    static const uint8_t SR1_ADD10 = 3;            // 10-bit header sent (Master mode), Read-only
    static const uint8_t SR1_BTF = 2;              // Byte transfer finished, Read-only
    static const uint8_t SR1_ADDR = 1;             // Address sent (master mode)/matched (slave mode), Read-only
    static const uint8_t SR1_SB = 0;               // Start bit (Master mode), Read-only
    static const uint32_t SR1_RESET_VALUE = 0x0;

    static const uint8_t SR2_PEC = 8;              // acket error checking register (8 bits)
    static const uint8_t SR2_DUALF = 7;            // Dual flag (Slave mode)
    static const uint8_t SR2_SMBHOST = 6;          // SMBus host header (Slave mode)
    static const uint8_t SR2_SMBDEFAULT = 5;       // SMBus device default address (Slave mode)
    static const uint8_t SR2_GENCALL = 4;          // General call address (Slave mode)
    static const uint8_t SR2_TRA = 2;              // Transmitter/receiver
    static const uint8_t SR2_BUSY = 1;             // Bus busy
    static const uint8_t SR2_MSL = 0;              // Master/slave
    static const uint32_t SR2_RESET_VALUE = 0x0;

    static const uint8_t CCR_F_S = 15;             // I2C master mode selection
    static const uint8_t CCR_DUTY = 14;            // Fast mode duty cycle
    static const uint8_t CCR_CCR = 0;              // Clock control register in Fast/Standard mode (Master mode) (12 bits)
    static const uint32_t CCR_RESET_VALUE = 0x0;

    static const uint8_t TRISE_TRISE = 0;            // Maximum rise time in Fast/Standard mode (Master mode) (6 bits)
    static const uint32_t TRISE_RESET_VALUE = 0x2;
};

static i2c1_t& I2C1 = *reinterpret_cast<i2c1_t*>(0x40005400);


////
//
//    Serial peripheral interface
//
////

struct i2s2ext_t
{
    volatile uint32_t    CR1;                  // [Read-write] control register 1
    volatile uint32_t    CR2;                  // [Read-write] control register 2
    volatile uint32_t    SR;                   // status register
    volatile uint32_t    DR;                   // [Read-write] data register
    volatile uint32_t    CRCPR;                // [Read-write] CRC polynomial register
    volatile uint32_t    RXCRCR;               // [Read-only] RX CRC register
    volatile uint32_t    TXCRCR;               // [Read-only] TX CRC register
    volatile uint32_t    I2SCFGR;              // [Read-write] I2S configuration register
    volatile uint32_t    I2SPR;                // [Read-write] I2S prescaler register

    static const uint8_t CR1_BIDIMODE = 15;        // Bidirectional data mode enable
    static const uint8_t CR1_BIDIOE = 14;          // Output enable in bidirectional mode
    static const uint8_t CR1_CRCEN = 13;           // Hardware CRC calculation enable
    static const uint8_t CR1_CRCNEXT = 12;         // CRC transfer next
    static const uint8_t CR1_DFF = 11;             // Data frame format
    static const uint8_t CR1_RXONLY = 10;          // Receive only
    static const uint8_t CR1_SSM = 9;              // Software slave management
    static const uint8_t CR1_SSI = 8;              // Internal slave select
    static const uint8_t CR1_LSBFIRST = 7;         // Frame format
    static const uint8_t CR1_SPE = 6;              // SPI enable
    static const uint8_t CR1_BR = 3;               // Baud rate control (3 bits)
    static const uint8_t CR1_MSTR = 2;             // Master selection
    static const uint8_t CR1_CPOL = 1;             // Clock polarity
    static const uint8_t CR1_CPHA = 0;             // Clock phase
    static const uint32_t CR1_RESET_VALUE = 0x0;

    static const uint8_t CR2_TXEIE = 7;            // Tx buffer empty interrupt enable
    static const uint8_t CR2_RXNEIE = 6;           // RX buffer not empty interrupt enable
    static const uint8_t CR2_ERRIE = 5;            // Error interrupt enable
    static const uint8_t CR2_FRF = 4;              // Frame format
    static const uint8_t CR2_SSOE = 2;             // SS output enable
    static const uint8_t CR2_TXDMAEN = 1;          // Tx buffer DMA enable
    static const uint8_t CR2_RXDMAEN = 0;          // Rx buffer DMA enable
    static const uint32_t CR2_RESET_VALUE = 0x0;

    static const uint8_t SR_TIFRFE = 8;           // TI frame format error, Read-only
    static const uint8_t SR_BSY = 7;              // Busy flag, Read-only
    static const uint8_t SR_OVR = 6;              // Overrun flag, Read-only
    static const uint8_t SR_MODF = 5;             // Mode fault, Read-only
    static const uint8_t SR_CRCERR = 4;           // CRC error flag, Read-write
    static const uint8_t SR_UDR = 3;              // Underrun flag, Read-only
    static const uint8_t SR_CHSIDE = 2;           // Channel side, Read-only
    static const uint8_t SR_TXE = 1;              // Transmit buffer empty, Read-only
    static const uint8_t SR_RXNE = 0;             // Receive buffer not empty, Read-only
    static const uint32_t SR_RESET_VALUE = 0x2;

    static const uint8_t DR_DR = 0;               // Data register (16 bits)
    static const uint32_t DR_RESET_VALUE = 0x0;

    static const uint8_t CRCPR_CRCPOLY = 0;          // CRC polynomial register (16 bits)
    static const uint32_t CRCPR_RESET_VALUE = 0x7;

    static const uint8_t RXCRCR_RxCRC = 0;            // Rx CRC register (16 bits)
    static const uint32_t RXCRCR_RESET_VALUE = 0x0;

    static const uint8_t TXCRCR_TxCRC = 0;            // Tx CRC register (16 bits)
    static const uint32_t TXCRCR_RESET_VALUE = 0x0;

    static const uint8_t I2SCFGR_I2SMOD = 11;          // I2S mode selection
    static const uint8_t I2SCFGR_I2SE = 10;            // I2S Enable
    static const uint8_t I2SCFGR_I2SCFG = 8;           // I2S configuration mode (2 bits)
    static const uint8_t I2SCFGR_PCMSYNC = 7;          // PCM frame synchronization
    static const uint8_t I2SCFGR_I2SSTD = 4;           // I2S standard selection (2 bits)
    static const uint8_t I2SCFGR_CKPOL = 3;            // Steady state clock polarity
    static const uint8_t I2SCFGR_DATLEN = 1;           // Data length to be transferred (2 bits)
    static const uint8_t I2SCFGR_CHLEN = 0;            // Channel length (number of bits per audio channel)
    static const uint32_t I2SCFGR_RESET_VALUE = 0x0;

    static const uint8_t I2SPR_MCKOE = 9;            // Master clock output enable
    static const uint8_t I2SPR_ODD = 8;              // Odd factor for the prescaler
    static const uint8_t I2SPR_I2SDIV = 0;           // I2S Linear prescaler (8 bits)
    static const uint32_t I2SPR_RESET_VALUE = 0xa;
};

static i2s2ext_t& I2S2ext = *reinterpret_cast<i2s2ext_t*>(0x40003400);


////
//
//    Serial peripheral interface
//
////

struct i2s3ext_t
{
    volatile uint32_t    CR1;                  // [Read-write] control register 1
    volatile uint32_t    CR2;                  // [Read-write] control register 2
    volatile uint32_t    SR;                   // status register
    volatile uint32_t    DR;                   // [Read-write] data register
    volatile uint32_t    CRCPR;                // [Read-write] CRC polynomial register
    volatile uint32_t    RXCRCR;               // [Read-only] RX CRC register
    volatile uint32_t    TXCRCR;               // [Read-only] TX CRC register
    volatile uint32_t    I2SCFGR;              // [Read-write] I2S configuration register
    volatile uint32_t    I2SPR;                // [Read-write] I2S prescaler register

    static const uint8_t CR1_BIDIMODE = 15;        // Bidirectional data mode enable
    static const uint8_t CR1_BIDIOE = 14;          // Output enable in bidirectional mode
    static const uint8_t CR1_CRCEN = 13;           // Hardware CRC calculation enable
    static const uint8_t CR1_CRCNEXT = 12;         // CRC transfer next
    static const uint8_t CR1_DFF = 11;             // Data frame format
    static const uint8_t CR1_RXONLY = 10;          // Receive only
    static const uint8_t CR1_SSM = 9;              // Software slave management
    static const uint8_t CR1_SSI = 8;              // Internal slave select
    static const uint8_t CR1_LSBFIRST = 7;         // Frame format
    static const uint8_t CR1_SPE = 6;              // SPI enable
    static const uint8_t CR1_BR = 3;               // Baud rate control (3 bits)
    static const uint8_t CR1_MSTR = 2;             // Master selection
    static const uint8_t CR1_CPOL = 1;             // Clock polarity
    static const uint8_t CR1_CPHA = 0;             // Clock phase
    static const uint32_t CR1_RESET_VALUE = 0x0;

    static const uint8_t CR2_TXEIE = 7;            // Tx buffer empty interrupt enable
    static const uint8_t CR2_RXNEIE = 6;           // RX buffer not empty interrupt enable
    static const uint8_t CR2_ERRIE = 5;            // Error interrupt enable
    static const uint8_t CR2_FRF = 4;              // Frame format
    static const uint8_t CR2_SSOE = 2;             // SS output enable
    static const uint8_t CR2_TXDMAEN = 1;          // Tx buffer DMA enable
    static const uint8_t CR2_RXDMAEN = 0;          // Rx buffer DMA enable
    static const uint32_t CR2_RESET_VALUE = 0x0;

    static const uint8_t SR_TIFRFE = 8;           // TI frame format error, Read-only
    static const uint8_t SR_BSY = 7;              // Busy flag, Read-only
    static const uint8_t SR_OVR = 6;              // Overrun flag, Read-only
    static const uint8_t SR_MODF = 5;             // Mode fault, Read-only
    static const uint8_t SR_CRCERR = 4;           // CRC error flag, Read-write
    static const uint8_t SR_UDR = 3;              // Underrun flag, Read-only
    static const uint8_t SR_CHSIDE = 2;           // Channel side, Read-only
    static const uint8_t SR_TXE = 1;              // Transmit buffer empty, Read-only
    static const uint8_t SR_RXNE = 0;             // Receive buffer not empty, Read-only
    static const uint32_t SR_RESET_VALUE = 0x2;

    static const uint8_t DR_DR = 0;               // Data register (16 bits)
    static const uint32_t DR_RESET_VALUE = 0x0;

    static const uint8_t CRCPR_CRCPOLY = 0;          // CRC polynomial register (16 bits)
    static const uint32_t CRCPR_RESET_VALUE = 0x7;

    static const uint8_t RXCRCR_RxCRC = 0;            // Rx CRC register (16 bits)
    static const uint32_t RXCRCR_RESET_VALUE = 0x0;

    static const uint8_t TXCRCR_TxCRC = 0;            // Tx CRC register (16 bits)
    static const uint32_t TXCRCR_RESET_VALUE = 0x0;

    static const uint8_t I2SCFGR_I2SMOD = 11;          // I2S mode selection
    static const uint8_t I2SCFGR_I2SE = 10;            // I2S Enable
    static const uint8_t I2SCFGR_I2SCFG = 8;           // I2S configuration mode (2 bits)
    static const uint8_t I2SCFGR_PCMSYNC = 7;          // PCM frame synchronization
    static const uint8_t I2SCFGR_I2SSTD = 4;           // I2S standard selection (2 bits)
    static const uint8_t I2SCFGR_CKPOL = 3;            // Steady state clock polarity
    static const uint8_t I2SCFGR_DATLEN = 1;           // Data length to be transferred (2 bits)
    static const uint8_t I2SCFGR_CHLEN = 0;            // Channel length (number of bits per audio channel)
    static const uint32_t I2SCFGR_RESET_VALUE = 0x0;

    static const uint8_t I2SPR_MCKOE = 9;            // Master clock output enable
    static const uint8_t I2SPR_ODD = 8;              // Odd factor for the prescaler
    static const uint8_t I2SPR_I2SDIV = 0;           // I2S Linear prescaler (8 bits)
    static const uint32_t I2SPR_RESET_VALUE = 0xa;
};

static i2s3ext_t& I2S3ext = *reinterpret_cast<i2s3ext_t*>(0x40004000);


////
//
//    Serial peripheral interface
//
////

struct spi1_t
{
    volatile uint32_t    CR1;                  // [Read-write] control register 1
    volatile uint32_t    CR2;                  // [Read-write] control register 2
    volatile uint32_t    SR;                   // status register
    volatile uint32_t    DR;                   // [Read-write] data register
    volatile uint32_t    CRCPR;                // [Read-write] CRC polynomial register
    volatile uint32_t    RXCRCR;               // [Read-only] RX CRC register
    volatile uint32_t    TXCRCR;               // [Read-only] TX CRC register
    volatile uint32_t    I2SCFGR;              // [Read-write] I2S configuration register
    volatile uint32_t    I2SPR;                // [Read-write] I2S prescaler register

    static const uint8_t CR1_BIDIMODE = 15;        // Bidirectional data mode enable
    static const uint8_t CR1_BIDIOE = 14;          // Output enable in bidirectional mode
    static const uint8_t CR1_CRCEN = 13;           // Hardware CRC calculation enable
    static const uint8_t CR1_CRCNEXT = 12;         // CRC transfer next
    static const uint8_t CR1_DFF = 11;             // Data frame format
    static const uint8_t CR1_RXONLY = 10;          // Receive only
    static const uint8_t CR1_SSM = 9;              // Software slave management
    static const uint8_t CR1_SSI = 8;              // Internal slave select
    static const uint8_t CR1_LSBFIRST = 7;         // Frame format
    static const uint8_t CR1_SPE = 6;              // SPI enable
    static const uint8_t CR1_BR = 3;               // Baud rate control (3 bits)
    static const uint8_t CR1_MSTR = 2;             // Master selection
    static const uint8_t CR1_CPOL = 1;             // Clock polarity
    static const uint8_t CR1_CPHA = 0;             // Clock phase
    static const uint32_t CR1_RESET_VALUE = 0x0;

    static const uint8_t CR2_TXEIE = 7;            // Tx buffer empty interrupt enable
    static const uint8_t CR2_RXNEIE = 6;           // RX buffer not empty interrupt enable
    static const uint8_t CR2_ERRIE = 5;            // Error interrupt enable
    static const uint8_t CR2_FRF = 4;              // Frame format
    static const uint8_t CR2_SSOE = 2;             // SS output enable
    static const uint8_t CR2_TXDMAEN = 1;          // Tx buffer DMA enable
    static const uint8_t CR2_RXDMAEN = 0;          // Rx buffer DMA enable
    static const uint32_t CR2_RESET_VALUE = 0x0;

    static const uint8_t SR_TIFRFE = 8;           // TI frame format error, Read-only
    static const uint8_t SR_BSY = 7;              // Busy flag, Read-only
    static const uint8_t SR_OVR = 6;              // Overrun flag, Read-only
    static const uint8_t SR_MODF = 5;             // Mode fault, Read-only
    static const uint8_t SR_CRCERR = 4;           // CRC error flag, Read-write
    static const uint8_t SR_UDR = 3;              // Underrun flag, Read-only
    static const uint8_t SR_CHSIDE = 2;           // Channel side, Read-only
    static const uint8_t SR_TXE = 1;              // Transmit buffer empty, Read-only
    static const uint8_t SR_RXNE = 0;             // Receive buffer not empty, Read-only
    static const uint32_t SR_RESET_VALUE = 0x2;

    static const uint8_t DR_DR = 0;               // Data register (16 bits)
    static const uint32_t DR_RESET_VALUE = 0x0;

    static const uint8_t CRCPR_CRCPOLY = 0;          // CRC polynomial register (16 bits)
    static const uint32_t CRCPR_RESET_VALUE = 0x7;

    static const uint8_t RXCRCR_RxCRC = 0;            // Rx CRC register (16 bits)
    static const uint32_t RXCRCR_RESET_VALUE = 0x0;

    static const uint8_t TXCRCR_TxCRC = 0;            // Tx CRC register (16 bits)
    static const uint32_t TXCRCR_RESET_VALUE = 0x0;

    static const uint8_t I2SCFGR_I2SMOD = 11;          // I2S mode selection
    static const uint8_t I2SCFGR_I2SE = 10;            // I2S Enable
    static const uint8_t I2SCFGR_I2SCFG = 8;           // I2S configuration mode (2 bits)
    static const uint8_t I2SCFGR_PCMSYNC = 7;          // PCM frame synchronization
    static const uint8_t I2SCFGR_I2SSTD = 4;           // I2S standard selection (2 bits)
    static const uint8_t I2SCFGR_CKPOL = 3;            // Steady state clock polarity
    static const uint8_t I2SCFGR_DATLEN = 1;           // Data length to be transferred (2 bits)
    static const uint8_t I2SCFGR_CHLEN = 0;            // Channel length (number of bits per audio channel)
    static const uint32_t I2SCFGR_RESET_VALUE = 0x0;

    static const uint8_t I2SPR_MCKOE = 9;            // Master clock output enable
    static const uint8_t I2SPR_ODD = 8;              // Odd factor for the prescaler
    static const uint8_t I2SPR_I2SDIV = 0;           // I2S Linear prescaler (8 bits)
    static const uint32_t I2SPR_RESET_VALUE = 0xa;
};

static spi1_t& SPI1 = *reinterpret_cast<spi1_t*>(0x40013000);


////
//
//    Serial peripheral interface
//
////

struct spi2_t
{
    volatile uint32_t    CR1;                  // [Read-write] control register 1
    volatile uint32_t    CR2;                  // [Read-write] control register 2
    volatile uint32_t    SR;                   // status register
    volatile uint32_t    DR;                   // [Read-write] data register
    volatile uint32_t    CRCPR;                // [Read-write] CRC polynomial register
    volatile uint32_t    RXCRCR;               // [Read-only] RX CRC register
    volatile uint32_t    TXCRCR;               // [Read-only] TX CRC register
    volatile uint32_t    I2SCFGR;              // [Read-write] I2S configuration register
    volatile uint32_t    I2SPR;                // [Read-write] I2S prescaler register

    static const uint8_t CR1_BIDIMODE = 15;        // Bidirectional data mode enable
    static const uint8_t CR1_BIDIOE = 14;          // Output enable in bidirectional mode
    static const uint8_t CR1_CRCEN = 13;           // Hardware CRC calculation enable
    static const uint8_t CR1_CRCNEXT = 12;         // CRC transfer next
    static const uint8_t CR1_DFF = 11;             // Data frame format
    static const uint8_t CR1_RXONLY = 10;          // Receive only
    static const uint8_t CR1_SSM = 9;              // Software slave management
    static const uint8_t CR1_SSI = 8;              // Internal slave select
    static const uint8_t CR1_LSBFIRST = 7;         // Frame format
    static const uint8_t CR1_SPE = 6;              // SPI enable
    static const uint8_t CR1_BR = 3;               // Baud rate control (3 bits)
    static const uint8_t CR1_MSTR = 2;             // Master selection
    static const uint8_t CR1_CPOL = 1;             // Clock polarity
    static const uint8_t CR1_CPHA = 0;             // Clock phase
    static const uint32_t CR1_RESET_VALUE = 0x0;

    static const uint8_t CR2_TXEIE = 7;            // Tx buffer empty interrupt enable
    static const uint8_t CR2_RXNEIE = 6;           // RX buffer not empty interrupt enable
    static const uint8_t CR2_ERRIE = 5;            // Error interrupt enable
    static const uint8_t CR2_FRF = 4;              // Frame format
    static const uint8_t CR2_SSOE = 2;             // SS output enable
    static const uint8_t CR2_TXDMAEN = 1;          // Tx buffer DMA enable
    static const uint8_t CR2_RXDMAEN = 0;          // Rx buffer DMA enable
    static const uint32_t CR2_RESET_VALUE = 0x0;

    static const uint8_t SR_TIFRFE = 8;           // TI frame format error, Read-only
    static const uint8_t SR_BSY = 7;              // Busy flag, Read-only
    static const uint8_t SR_OVR = 6;              // Overrun flag, Read-only
    static const uint8_t SR_MODF = 5;             // Mode fault, Read-only
    static const uint8_t SR_CRCERR = 4;           // CRC error flag, Read-write
    static const uint8_t SR_UDR = 3;              // Underrun flag, Read-only
    static const uint8_t SR_CHSIDE = 2;           // Channel side, Read-only
    static const uint8_t SR_TXE = 1;              // Transmit buffer empty, Read-only
    static const uint8_t SR_RXNE = 0;             // Receive buffer not empty, Read-only
    static const uint32_t SR_RESET_VALUE = 0x2;

    static const uint8_t DR_DR = 0;               // Data register (16 bits)
    static const uint32_t DR_RESET_VALUE = 0x0;

    static const uint8_t CRCPR_CRCPOLY = 0;          // CRC polynomial register (16 bits)
    static const uint32_t CRCPR_RESET_VALUE = 0x7;

    static const uint8_t RXCRCR_RxCRC = 0;            // Rx CRC register (16 bits)
    static const uint32_t RXCRCR_RESET_VALUE = 0x0;

    static const uint8_t TXCRCR_TxCRC = 0;            // Tx CRC register (16 bits)
    static const uint32_t TXCRCR_RESET_VALUE = 0x0;

    static const uint8_t I2SCFGR_I2SMOD = 11;          // I2S mode selection
    static const uint8_t I2SCFGR_I2SE = 10;            // I2S Enable
    static const uint8_t I2SCFGR_I2SCFG = 8;           // I2S configuration mode (2 bits)
    static const uint8_t I2SCFGR_PCMSYNC = 7;          // PCM frame synchronization
    static const uint8_t I2SCFGR_I2SSTD = 4;           // I2S standard selection (2 bits)
    static const uint8_t I2SCFGR_CKPOL = 3;            // Steady state clock polarity
    static const uint8_t I2SCFGR_DATLEN = 1;           // Data length to be transferred (2 bits)
    static const uint8_t I2SCFGR_CHLEN = 0;            // Channel length (number of bits per audio channel)
    static const uint32_t I2SCFGR_RESET_VALUE = 0x0;

    static const uint8_t I2SPR_MCKOE = 9;            // Master clock output enable
    static const uint8_t I2SPR_ODD = 8;              // Odd factor for the prescaler
    static const uint8_t I2SPR_I2SDIV = 0;           // I2S Linear prescaler (8 bits)
    static const uint32_t I2SPR_RESET_VALUE = 0xa;
};

static spi2_t& SPI2 = *reinterpret_cast<spi2_t*>(0x40003800);


////
//
//    Serial peripheral interface
//
////

struct spi3_t
{
    volatile uint32_t    CR1;                  // [Read-write] control register 1
    volatile uint32_t    CR2;                  // [Read-write] control register 2
    volatile uint32_t    SR;                   // status register
    volatile uint32_t    DR;                   // [Read-write] data register
    volatile uint32_t    CRCPR;                // [Read-write] CRC polynomial register
    volatile uint32_t    RXCRCR;               // [Read-only] RX CRC register
    volatile uint32_t    TXCRCR;               // [Read-only] TX CRC register
    volatile uint32_t    I2SCFGR;              // [Read-write] I2S configuration register
    volatile uint32_t    I2SPR;                // [Read-write] I2S prescaler register

    static const uint8_t CR1_BIDIMODE = 15;        // Bidirectional data mode enable
    static const uint8_t CR1_BIDIOE = 14;          // Output enable in bidirectional mode
    static const uint8_t CR1_CRCEN = 13;           // Hardware CRC calculation enable
    static const uint8_t CR1_CRCNEXT = 12;         // CRC transfer next
    static const uint8_t CR1_DFF = 11;             // Data frame format
    static const uint8_t CR1_RXONLY = 10;          // Receive only
    static const uint8_t CR1_SSM = 9;              // Software slave management
    static const uint8_t CR1_SSI = 8;              // Internal slave select
    static const uint8_t CR1_LSBFIRST = 7;         // Frame format
    static const uint8_t CR1_SPE = 6;              // SPI enable
    static const uint8_t CR1_BR = 3;               // Baud rate control (3 bits)
    static const uint8_t CR1_MSTR = 2;             // Master selection
    static const uint8_t CR1_CPOL = 1;             // Clock polarity
    static const uint8_t CR1_CPHA = 0;             // Clock phase
    static const uint32_t CR1_RESET_VALUE = 0x0;

    static const uint8_t CR2_TXEIE = 7;            // Tx buffer empty interrupt enable
    static const uint8_t CR2_RXNEIE = 6;           // RX buffer not empty interrupt enable
    static const uint8_t CR2_ERRIE = 5;            // Error interrupt enable
    static const uint8_t CR2_FRF = 4;              // Frame format
    static const uint8_t CR2_SSOE = 2;             // SS output enable
    static const uint8_t CR2_TXDMAEN = 1;          // Tx buffer DMA enable
    static const uint8_t CR2_RXDMAEN = 0;          // Rx buffer DMA enable
    static const uint32_t CR2_RESET_VALUE = 0x0;

    static const uint8_t SR_TIFRFE = 8;           // TI frame format error, Read-only
    static const uint8_t SR_BSY = 7;              // Busy flag, Read-only
    static const uint8_t SR_OVR = 6;              // Overrun flag, Read-only
    static const uint8_t SR_MODF = 5;             // Mode fault, Read-only
    static const uint8_t SR_CRCERR = 4;           // CRC error flag, Read-write
    static const uint8_t SR_UDR = 3;              // Underrun flag, Read-only
    static const uint8_t SR_CHSIDE = 2;           // Channel side, Read-only
    static const uint8_t SR_TXE = 1;              // Transmit buffer empty, Read-only
    static const uint8_t SR_RXNE = 0;             // Receive buffer not empty, Read-only
    static const uint32_t SR_RESET_VALUE = 0x2;

    static const uint8_t DR_DR = 0;               // Data register (16 bits)
    static const uint32_t DR_RESET_VALUE = 0x0;

    static const uint8_t CRCPR_CRCPOLY = 0;          // CRC polynomial register (16 bits)
    static const uint32_t CRCPR_RESET_VALUE = 0x7;

    static const uint8_t RXCRCR_RxCRC = 0;            // Rx CRC register (16 bits)
    static const uint32_t RXCRCR_RESET_VALUE = 0x0;

    static const uint8_t TXCRCR_TxCRC = 0;            // Tx CRC register (16 bits)
    static const uint32_t TXCRCR_RESET_VALUE = 0x0;

    static const uint8_t I2SCFGR_I2SMOD = 11;          // I2S mode selection
    static const uint8_t I2SCFGR_I2SE = 10;            // I2S Enable
    static const uint8_t I2SCFGR_I2SCFG = 8;           // I2S configuration mode (2 bits)
    static const uint8_t I2SCFGR_PCMSYNC = 7;          // PCM frame synchronization
    static const uint8_t I2SCFGR_I2SSTD = 4;           // I2S standard selection (2 bits)
    static const uint8_t I2SCFGR_CKPOL = 3;            // Steady state clock polarity
    static const uint8_t I2SCFGR_DATLEN = 1;           // Data length to be transferred (2 bits)
    static const uint8_t I2SCFGR_CHLEN = 0;            // Channel length (number of bits per audio channel)
    static const uint32_t I2SCFGR_RESET_VALUE = 0x0;

    static const uint8_t I2SPR_MCKOE = 9;            // Master clock output enable
    static const uint8_t I2SPR_ODD = 8;              // Odd factor for the prescaler
    static const uint8_t I2SPR_I2SDIV = 0;           // I2S Linear prescaler (8 bits)
    static const uint32_t I2SPR_RESET_VALUE = 0xa;
};

static spi3_t& SPI3 = *reinterpret_cast<spi3_t*>(0x40003c00);


////
//
//    Serial peripheral interface
//
////

struct spi4_t
{
    volatile uint32_t    CR1;                  // [Read-write] control register 1
    volatile uint32_t    CR2;                  // [Read-write] control register 2
    volatile uint32_t    SR;                   // status register
    volatile uint32_t    DR;                   // [Read-write] data register
    volatile uint32_t    CRCPR;                // [Read-write] CRC polynomial register
    volatile uint32_t    RXCRCR;               // [Read-only] RX CRC register
    volatile uint32_t    TXCRCR;               // [Read-only] TX CRC register
    volatile uint32_t    I2SCFGR;              // [Read-write] I2S configuration register
    volatile uint32_t    I2SPR;                // [Read-write] I2S prescaler register

    static const uint8_t CR1_BIDIMODE = 15;        // Bidirectional data mode enable
    static const uint8_t CR1_BIDIOE = 14;          // Output enable in bidirectional mode
    static const uint8_t CR1_CRCEN = 13;           // Hardware CRC calculation enable
    static const uint8_t CR1_CRCNEXT = 12;         // CRC transfer next
    static const uint8_t CR1_DFF = 11;             // Data frame format
    static const uint8_t CR1_RXONLY = 10;          // Receive only
    static const uint8_t CR1_SSM = 9;              // Software slave management
    static const uint8_t CR1_SSI = 8;              // Internal slave select
    static const uint8_t CR1_LSBFIRST = 7;         // Frame format
    static const uint8_t CR1_SPE = 6;              // SPI enable
    static const uint8_t CR1_BR = 3;               // Baud rate control (3 bits)
    static const uint8_t CR1_MSTR = 2;             // Master selection
    static const uint8_t CR1_CPOL = 1;             // Clock polarity
    static const uint8_t CR1_CPHA = 0;             // Clock phase
    static const uint32_t CR1_RESET_VALUE = 0x0;

    static const uint8_t CR2_TXEIE = 7;            // Tx buffer empty interrupt enable
    static const uint8_t CR2_RXNEIE = 6;           // RX buffer not empty interrupt enable
    static const uint8_t CR2_ERRIE = 5;            // Error interrupt enable
    static const uint8_t CR2_FRF = 4;              // Frame format
    static const uint8_t CR2_SSOE = 2;             // SS output enable
    static const uint8_t CR2_TXDMAEN = 1;          // Tx buffer DMA enable
    static const uint8_t CR2_RXDMAEN = 0;          // Rx buffer DMA enable
    static const uint32_t CR2_RESET_VALUE = 0x0;

    static const uint8_t SR_TIFRFE = 8;           // TI frame format error, Read-only
    static const uint8_t SR_BSY = 7;              // Busy flag, Read-only
    static const uint8_t SR_OVR = 6;              // Overrun flag, Read-only
    static const uint8_t SR_MODF = 5;             // Mode fault, Read-only
    static const uint8_t SR_CRCERR = 4;           // CRC error flag, Read-write
    static const uint8_t SR_UDR = 3;              // Underrun flag, Read-only
    static const uint8_t SR_CHSIDE = 2;           // Channel side, Read-only
    static const uint8_t SR_TXE = 1;              // Transmit buffer empty, Read-only
    static const uint8_t SR_RXNE = 0;             // Receive buffer not empty, Read-only
    static const uint32_t SR_RESET_VALUE = 0x2;

    static const uint8_t DR_DR = 0;               // Data register (16 bits)
    static const uint32_t DR_RESET_VALUE = 0x0;

    static const uint8_t CRCPR_CRCPOLY = 0;          // CRC polynomial register (16 bits)
    static const uint32_t CRCPR_RESET_VALUE = 0x7;

    static const uint8_t RXCRCR_RxCRC = 0;            // Rx CRC register (16 bits)
    static const uint32_t RXCRCR_RESET_VALUE = 0x0;

    static const uint8_t TXCRCR_TxCRC = 0;            // Tx CRC register (16 bits)
    static const uint32_t TXCRCR_RESET_VALUE = 0x0;

    static const uint8_t I2SCFGR_I2SMOD = 11;          // I2S mode selection
    static const uint8_t I2SCFGR_I2SE = 10;            // I2S Enable
    static const uint8_t I2SCFGR_I2SCFG = 8;           // I2S configuration mode (2 bits)
    static const uint8_t I2SCFGR_PCMSYNC = 7;          // PCM frame synchronization
    static const uint8_t I2SCFGR_I2SSTD = 4;           // I2S standard selection (2 bits)
    static const uint8_t I2SCFGR_CKPOL = 3;            // Steady state clock polarity
    static const uint8_t I2SCFGR_DATLEN = 1;           // Data length to be transferred (2 bits)
    static const uint8_t I2SCFGR_CHLEN = 0;            // Channel length (number of bits per audio channel)
    static const uint32_t I2SCFGR_RESET_VALUE = 0x0;

    static const uint8_t I2SPR_MCKOE = 9;            // Master clock output enable
    static const uint8_t I2SPR_ODD = 8;              // Odd factor for the prescaler
    static const uint8_t I2SPR_I2SDIV = 0;           // I2S Linear prescaler (8 bits)
    static const uint32_t I2SPR_RESET_VALUE = 0xa;
};

static spi4_t& SPI4 = *reinterpret_cast<spi4_t*>(0x40013400);


////
//
//    Serial peripheral interface
//
////

struct spi5_t
{
    volatile uint32_t    CR1;                  // [Read-write] control register 1
    volatile uint32_t    CR2;                  // [Read-write] control register 2
    volatile uint32_t    SR;                   // status register
    volatile uint32_t    DR;                   // [Read-write] data register
    volatile uint32_t    CRCPR;                // [Read-write] CRC polynomial register
    volatile uint32_t    RXCRCR;               // [Read-only] RX CRC register
    volatile uint32_t    TXCRCR;               // [Read-only] TX CRC register
    volatile uint32_t    I2SCFGR;              // [Read-write] I2S configuration register
    volatile uint32_t    I2SPR;                // [Read-write] I2S prescaler register

    static const uint8_t CR1_BIDIMODE = 15;        // Bidirectional data mode enable
    static const uint8_t CR1_BIDIOE = 14;          // Output enable in bidirectional mode
    static const uint8_t CR1_CRCEN = 13;           // Hardware CRC calculation enable
    static const uint8_t CR1_CRCNEXT = 12;         // CRC transfer next
    static const uint8_t CR1_DFF = 11;             // Data frame format
    static const uint8_t CR1_RXONLY = 10;          // Receive only
    static const uint8_t CR1_SSM = 9;              // Software slave management
    static const uint8_t CR1_SSI = 8;              // Internal slave select
    static const uint8_t CR1_LSBFIRST = 7;         // Frame format
    static const uint8_t CR1_SPE = 6;              // SPI enable
    static const uint8_t CR1_BR = 3;               // Baud rate control (3 bits)
    static const uint8_t CR1_MSTR = 2;             // Master selection
    static const uint8_t CR1_CPOL = 1;             // Clock polarity
    static const uint8_t CR1_CPHA = 0;             // Clock phase
    static const uint32_t CR1_RESET_VALUE = 0x0;

    static const uint8_t CR2_TXEIE = 7;            // Tx buffer empty interrupt enable
    static const uint8_t CR2_RXNEIE = 6;           // RX buffer not empty interrupt enable
    static const uint8_t CR2_ERRIE = 5;            // Error interrupt enable
    static const uint8_t CR2_FRF = 4;              // Frame format
    static const uint8_t CR2_SSOE = 2;             // SS output enable
    static const uint8_t CR2_TXDMAEN = 1;          // Tx buffer DMA enable
    static const uint8_t CR2_RXDMAEN = 0;          // Rx buffer DMA enable
    static const uint32_t CR2_RESET_VALUE = 0x0;

    static const uint8_t SR_TIFRFE = 8;           // TI frame format error, Read-only
    static const uint8_t SR_BSY = 7;              // Busy flag, Read-only
    static const uint8_t SR_OVR = 6;              // Overrun flag, Read-only
    static const uint8_t SR_MODF = 5;             // Mode fault, Read-only
    static const uint8_t SR_CRCERR = 4;           // CRC error flag, Read-write
    static const uint8_t SR_UDR = 3;              // Underrun flag, Read-only
    static const uint8_t SR_CHSIDE = 2;           // Channel side, Read-only
    static const uint8_t SR_TXE = 1;              // Transmit buffer empty, Read-only
    static const uint8_t SR_RXNE = 0;             // Receive buffer not empty, Read-only
    static const uint32_t SR_RESET_VALUE = 0x2;

    static const uint8_t DR_DR = 0;               // Data register (16 bits)
    static const uint32_t DR_RESET_VALUE = 0x0;

    static const uint8_t CRCPR_CRCPOLY = 0;          // CRC polynomial register (16 bits)
    static const uint32_t CRCPR_RESET_VALUE = 0x7;

    static const uint8_t RXCRCR_RxCRC = 0;            // Rx CRC register (16 bits)
    static const uint32_t RXCRCR_RESET_VALUE = 0x0;

    static const uint8_t TXCRCR_TxCRC = 0;            // Tx CRC register (16 bits)
    static const uint32_t TXCRCR_RESET_VALUE = 0x0;

    static const uint8_t I2SCFGR_I2SMOD = 11;          // I2S mode selection
    static const uint8_t I2SCFGR_I2SE = 10;            // I2S Enable
    static const uint8_t I2SCFGR_I2SCFG = 8;           // I2S configuration mode (2 bits)
    static const uint8_t I2SCFGR_PCMSYNC = 7;          // PCM frame synchronization
    static const uint8_t I2SCFGR_I2SSTD = 4;           // I2S standard selection (2 bits)
    static const uint8_t I2SCFGR_CKPOL = 3;            // Steady state clock polarity
    static const uint8_t I2SCFGR_DATLEN = 1;           // Data length to be transferred (2 bits)
    static const uint8_t I2SCFGR_CHLEN = 0;            // Channel length (number of bits per audio channel)
    static const uint32_t I2SCFGR_RESET_VALUE = 0x0;

    static const uint8_t I2SPR_MCKOE = 9;            // Master clock output enable
    static const uint8_t I2SPR_ODD = 8;              // Odd factor for the prescaler
    static const uint8_t I2SPR_I2SDIV = 0;           // I2S Linear prescaler (8 bits)
    static const uint32_t I2SPR_RESET_VALUE = 0xa;
};

static spi5_t& SPI5 = *reinterpret_cast<spi5_t*>(0x40015000);


////
//
//    Nested Vectored Interrupt Controller
//
////

struct nvic_t
{
    volatile uint32_t    ISER0;                // [Read-write] Interrupt Set-Enable Register
    volatile uint32_t    ISER1;                // [Read-write] Interrupt Set-Enable Register
    volatile uint32_t    ISER2;                // [Read-write] Interrupt Set-Enable Register
    reserved_t<29>       _0;
    volatile uint32_t    ICER0;                // [Read-write] Interrupt Clear-Enable Register
    volatile uint32_t    ICER1;                // [Read-write] Interrupt Clear-Enable Register
    volatile uint32_t    ICER2;                // [Read-write] Interrupt Clear-Enable Register
    reserved_t<29>       _1;
    volatile uint32_t    ISPR0;                // [Read-write] Interrupt Set-Pending Register
    volatile uint32_t    ISPR1;                // [Read-write] Interrupt Set-Pending Register
    volatile uint32_t    ISPR2;                // [Read-write] Interrupt Set-Pending Register
    reserved_t<29>       _2;
    volatile uint32_t    ICPR0;                // [Read-write] Interrupt Clear-Pending Register
    volatile uint32_t    ICPR1;                // [Read-write] Interrupt Clear-Pending Register
    volatile uint32_t    ICPR2;                // [Read-write] Interrupt Clear-Pending Register
    reserved_t<29>       _3;
    volatile uint32_t    IABR0;                // [Read-only] Interrupt Active Bit Register
    volatile uint32_t    IABR1;                // [Read-only] Interrupt Active Bit Register
    volatile uint32_t    IABR2;                // [Read-only] Interrupt Active Bit Register
    reserved_t<61>       _4;
    volatile uint32_t    IPR0;                 // [Read-write] Interrupt Priority Register
    volatile uint32_t    IPR1;                 // [Read-write] Interrupt Priority Register
    volatile uint32_t    IPR2;                 // [Read-write] Interrupt Priority Register
    volatile uint32_t    IPR3;                 // [Read-write] Interrupt Priority Register
    volatile uint32_t    IPR4;                 // [Read-write] Interrupt Priority Register
    volatile uint32_t    IPR5;                 // [Read-write] Interrupt Priority Register
    volatile uint32_t    IPR6;                 // [Read-write] Interrupt Priority Register
    volatile uint32_t    IPR7;                 // [Read-write] Interrupt Priority Register
    volatile uint32_t    IPR8;                 // [Read-write] Interrupt Priority Register
    volatile uint32_t    IPR9;                 // [Read-write] Interrupt Priority Register
    volatile uint32_t    IPR10;                // [Read-write] Interrupt Priority Register
    volatile uint32_t    IPR11;                // [Read-write] Interrupt Priority Register
    volatile uint32_t    IPR12;                // [Read-write] Interrupt Priority Register
    volatile uint32_t    IPR13;                // [Read-write] Interrupt Priority Register
    volatile uint32_t    IPR14;                // [Read-write] Interrupt Priority Register
    volatile uint32_t    IPR15;                // [Read-write] Interrupt Priority Register
    volatile uint32_t    IPR16;                // [Read-write] Interrupt Priority Register
    volatile uint32_t    IPR17;                // [Read-write] Interrupt Priority Register
    volatile uint32_t    IPR18;                // [Read-write] Interrupt Priority Register
    volatile uint32_t    IPR19;                // [Read-write] Interrupt Priority Register

    static const uint8_t ISER0_SETENA = 0;           // SETENA (32 bits)
    static const uint32_t ISER0_RESET_VALUE = 0x0;

    static const uint8_t ISER1_SETENA = 0;           // SETENA (32 bits)
    static const uint32_t ISER1_RESET_VALUE = 0x0;

    static const uint8_t ISER2_SETENA = 0;           // SETENA (32 bits)
    static const uint32_t ISER2_RESET_VALUE = 0x0;

    static const uint8_t ICER0_CLRENA = 0;           // CLRENA (32 bits)
    static const uint32_t ICER0_RESET_VALUE = 0x0;

    static const uint8_t ICER1_CLRENA = 0;           // CLRENA (32 bits)
    static const uint32_t ICER1_RESET_VALUE = 0x0;

    static const uint8_t ICER2_CLRENA = 0;           // CLRENA (32 bits)
    static const uint32_t ICER2_RESET_VALUE = 0x0;

    static const uint8_t ISPR0_SETPEND = 0;          // SETPEND (32 bits)
    static const uint32_t ISPR0_RESET_VALUE = 0x0;

    static const uint8_t ISPR1_SETPEND = 0;          // SETPEND (32 bits)
    static const uint32_t ISPR1_RESET_VALUE = 0x0;

    static const uint8_t ISPR2_SETPEND = 0;          // SETPEND (32 bits)
    static const uint32_t ISPR2_RESET_VALUE = 0x0;

    static const uint8_t ICPR0_CLRPEND = 0;          // CLRPEND (32 bits)
    static const uint32_t ICPR0_RESET_VALUE = 0x0;

    static const uint8_t ICPR1_CLRPEND = 0;          // CLRPEND (32 bits)
    static const uint32_t ICPR1_RESET_VALUE = 0x0;

    static const uint8_t ICPR2_CLRPEND = 0;          // CLRPEND (32 bits)
    static const uint32_t ICPR2_RESET_VALUE = 0x0;

    static const uint8_t IABR0_ACTIVE = 0;           // ACTIVE (32 bits)
    static const uint32_t IABR0_RESET_VALUE = 0x0;

    static const uint8_t IABR1_ACTIVE = 0;           // ACTIVE (32 bits)
    static const uint32_t IABR1_RESET_VALUE = 0x0;

    static const uint8_t IABR2_ACTIVE = 0;           // ACTIVE (32 bits)
    static const uint32_t IABR2_RESET_VALUE = 0x0;

    static const uint8_t IPR0_IPR_N0 = 0;           // IPR_N0 (8 bits)
    static const uint8_t IPR0_IPR_N1 = 8;           // IPR_N1 (8 bits)
    static const uint8_t IPR0_IPR_N2 = 16;          // IPR_N2 (8 bits)
    static const uint8_t IPR0_IPR_N3 = 24;          // IPR_N3 (8 bits)
    static const uint32_t IPR0_RESET_VALUE = 0x0;

    static const uint8_t IPR1_IPR_N0 = 0;           // IPR_N0 (8 bits)
    static const uint8_t IPR1_IPR_N1 = 8;           // IPR_N1 (8 bits)
    static const uint8_t IPR1_IPR_N2 = 16;          // IPR_N2 (8 bits)
    static const uint8_t IPR1_IPR_N3 = 24;          // IPR_N3 (8 bits)
    static const uint32_t IPR1_RESET_VALUE = 0x0;

    static const uint8_t IPR2_IPR_N0 = 0;           // IPR_N0 (8 bits)
    static const uint8_t IPR2_IPR_N1 = 8;           // IPR_N1 (8 bits)
    static const uint8_t IPR2_IPR_N2 = 16;          // IPR_N2 (8 bits)
    static const uint8_t IPR2_IPR_N3 = 24;          // IPR_N3 (8 bits)
    static const uint32_t IPR2_RESET_VALUE = 0x0;

    static const uint8_t IPR3_IPR_N0 = 0;           // IPR_N0 (8 bits)
    static const uint8_t IPR3_IPR_N1 = 8;           // IPR_N1 (8 bits)
    static const uint8_t IPR3_IPR_N2 = 16;          // IPR_N2 (8 bits)
    static const uint8_t IPR3_IPR_N3 = 24;          // IPR_N3 (8 bits)
    static const uint32_t IPR3_RESET_VALUE = 0x0;

    static const uint8_t IPR4_IPR_N0 = 0;           // IPR_N0 (8 bits)
    static const uint8_t IPR4_IPR_N1 = 8;           // IPR_N1 (8 bits)
    static const uint8_t IPR4_IPR_N2 = 16;          // IPR_N2 (8 bits)
    static const uint8_t IPR4_IPR_N3 = 24;          // IPR_N3 (8 bits)
    static const uint32_t IPR4_RESET_VALUE = 0x0;

    static const uint8_t IPR5_IPR_N0 = 0;           // IPR_N0 (8 bits)
    static const uint8_t IPR5_IPR_N1 = 8;           // IPR_N1 (8 bits)
    static const uint8_t IPR5_IPR_N2 = 16;          // IPR_N2 (8 bits)
    static const uint8_t IPR5_IPR_N3 = 24;          // IPR_N3 (8 bits)
    static const uint32_t IPR5_RESET_VALUE = 0x0;

    static const uint8_t IPR6_IPR_N0 = 0;           // IPR_N0 (8 bits)
    static const uint8_t IPR6_IPR_N1 = 8;           // IPR_N1 (8 bits)
    static const uint8_t IPR6_IPR_N2 = 16;          // IPR_N2 (8 bits)
    static const uint8_t IPR6_IPR_N3 = 24;          // IPR_N3 (8 bits)
    static const uint32_t IPR6_RESET_VALUE = 0x0;

    static const uint8_t IPR7_IPR_N0 = 0;           // IPR_N0 (8 bits)
    static const uint8_t IPR7_IPR_N1 = 8;           // IPR_N1 (8 bits)
    static const uint8_t IPR7_IPR_N2 = 16;          // IPR_N2 (8 bits)
    static const uint8_t IPR7_IPR_N3 = 24;          // IPR_N3 (8 bits)
    static const uint32_t IPR7_RESET_VALUE = 0x0;

    static const uint8_t IPR8_IPR_N0 = 0;           // IPR_N0 (8 bits)
    static const uint8_t IPR8_IPR_N1 = 8;           // IPR_N1 (8 bits)
    static const uint8_t IPR8_IPR_N2 = 16;          // IPR_N2 (8 bits)
    static const uint8_t IPR8_IPR_N3 = 24;          // IPR_N3 (8 bits)
    static const uint32_t IPR8_RESET_VALUE = 0x0;

    static const uint8_t IPR9_IPR_N0 = 0;           // IPR_N0 (8 bits)
    static const uint8_t IPR9_IPR_N1 = 8;           // IPR_N1 (8 bits)
    static const uint8_t IPR9_IPR_N2 = 16;          // IPR_N2 (8 bits)
    static const uint8_t IPR9_IPR_N3 = 24;          // IPR_N3 (8 bits)
    static const uint32_t IPR9_RESET_VALUE = 0x0;

    static const uint8_t IPR10_IPR_N0 = 0;           // IPR_N0 (8 bits)
    static const uint8_t IPR10_IPR_N1 = 8;           // IPR_N1 (8 bits)
    static const uint8_t IPR10_IPR_N2 = 16;          // IPR_N2 (8 bits)
    static const uint8_t IPR10_IPR_N3 = 24;          // IPR_N3 (8 bits)
    static const uint32_t IPR10_RESET_VALUE = 0x0;

    static const uint8_t IPR11_IPR_N0 = 0;           // IPR_N0 (8 bits)
    static const uint8_t IPR11_IPR_N1 = 8;           // IPR_N1 (8 bits)
    static const uint8_t IPR11_IPR_N2 = 16;          // IPR_N2 (8 bits)
    static const uint8_t IPR11_IPR_N3 = 24;          // IPR_N3 (8 bits)
    static const uint32_t IPR11_RESET_VALUE = 0x0;

    static const uint8_t IPR12_IPR_N0 = 0;           // IPR_N0 (8 bits)
    static const uint8_t IPR12_IPR_N1 = 8;           // IPR_N1 (8 bits)
    static const uint8_t IPR12_IPR_N2 = 16;          // IPR_N2 (8 bits)
    static const uint8_t IPR12_IPR_N3 = 24;          // IPR_N3 (8 bits)
    static const uint32_t IPR12_RESET_VALUE = 0x0;

    static const uint8_t IPR13_IPR_N0 = 0;           // IPR_N0 (8 bits)
    static const uint8_t IPR13_IPR_N1 = 8;           // IPR_N1 (8 bits)
    static const uint8_t IPR13_IPR_N2 = 16;          // IPR_N2 (8 bits)
    static const uint8_t IPR13_IPR_N3 = 24;          // IPR_N3 (8 bits)
    static const uint32_t IPR13_RESET_VALUE = 0x0;

    static const uint8_t IPR14_IPR_N0 = 0;           // IPR_N0 (8 bits)
    static const uint8_t IPR14_IPR_N1 = 8;           // IPR_N1 (8 bits)
    static const uint8_t IPR14_IPR_N2 = 16;          // IPR_N2 (8 bits)
    static const uint8_t IPR14_IPR_N3 = 24;          // IPR_N3 (8 bits)
    static const uint32_t IPR14_RESET_VALUE = 0x0;

    static const uint8_t IPR15_IPR_N0 = 0;           // IPR_N0 (8 bits)
    static const uint8_t IPR15_IPR_N1 = 8;           // IPR_N1 (8 bits)
    static const uint8_t IPR15_IPR_N2 = 16;          // IPR_N2 (8 bits)
    static const uint8_t IPR15_IPR_N3 = 24;          // IPR_N3 (8 bits)
    static const uint32_t IPR15_RESET_VALUE = 0x0;

    static const uint8_t IPR16_IPR_N0 = 0;           // IPR_N0 (8 bits)
    static const uint8_t IPR16_IPR_N1 = 8;           // IPR_N1 (8 bits)
    static const uint8_t IPR16_IPR_N2 = 16;          // IPR_N2 (8 bits)
    static const uint8_t IPR16_IPR_N3 = 24;          // IPR_N3 (8 bits)
    static const uint32_t IPR16_RESET_VALUE = 0x0;

    static const uint8_t IPR17_IPR_N0 = 0;           // IPR_N0 (8 bits)
    static const uint8_t IPR17_IPR_N1 = 8;           // IPR_N1 (8 bits)
    static const uint8_t IPR17_IPR_N2 = 16;          // IPR_N2 (8 bits)
    static const uint8_t IPR17_IPR_N3 = 24;          // IPR_N3 (8 bits)
    static const uint32_t IPR17_RESET_VALUE = 0x0;

    static const uint8_t IPR18_IPR_N0 = 0;           // IPR_N0 (8 bits)
    static const uint8_t IPR18_IPR_N1 = 8;           // IPR_N1 (8 bits)
    static const uint8_t IPR18_IPR_N2 = 16;          // IPR_N2 (8 bits)
    static const uint8_t IPR18_IPR_N3 = 24;          // IPR_N3 (8 bits)
    static const uint32_t IPR18_RESET_VALUE = 0x0;

    static const uint8_t IPR19_IPR_N0 = 0;           // IPR_N0 (8 bits)
    static const uint8_t IPR19_IPR_N1 = 8;           // IPR_N1 (8 bits)
    static const uint8_t IPR19_IPR_N2 = 16;          // IPR_N2 (8 bits)
    static const uint8_t IPR19_IPR_N3 = 24;          // IPR_N3 (8 bits)
    static const uint32_t IPR19_RESET_VALUE = 0x0;
};

static nvic_t& NVIC = *reinterpret_cast<nvic_t*>(0xe000e100);


////
//
//    Digital filter for sigma delta modulators
//
////

struct dfsdm_t
{
    volatile uint32_t    CHCFG0R1;             // [Read-write] channel configuration y register
    volatile uint32_t    CHCFG0R2;             // [Read-write] channel configuration y register
    volatile uint32_t    AWSCD0R;              // [Read-write] analog watchdog and short-circuit detector register
    volatile uint32_t    CHWDAT0R;             // [Read-write] channel watchdog filter data register
    volatile uint32_t    CHDATIN0R;            // [Read-write] channel data input register
    reserved_t<3>        _0;
    volatile uint32_t    CHCFG1R1;             // [Read-write] CHCFG1R1
    volatile uint32_t    CHCFG1R2;             // [Read-write] CHCFG1R2
    volatile uint32_t    AWSCD1R;              // [Read-write] AWSCD1R
    volatile uint32_t    CHWDAT1R;             // [Read-write] CHWDAT1R
    volatile uint32_t    CHDATIN1R;            // [Read-write] CHDATIN1R
    reserved_t<3>        _1;
    volatile uint32_t    CHCFG2R1;             // [Read-write] CHCFG2R1
    volatile uint32_t    CHCFG2R2;             // [Read-write] CHCFG2R2
    volatile uint32_t    AWSCD2R;              // [Read-write] AWSCD2R
    volatile uint32_t    CHWDAT2R;             // [Read-write] CHWDAT2R
    volatile uint32_t    CHDATIN2R;            // [Read-write] CHDATIN2R
    reserved_t<3>        _2;
    volatile uint32_t    CHCFG3R1;             // [Read-write] CHCFG3R1
    volatile uint32_t    CHCFG3R2;             // [Read-write] CHCFG3R2
    volatile uint32_t    AWSCD3R;              // [Read-write] AWSCD3R
    volatile uint32_t    CHWDAT3R;             // [Read-write] CHWDAT3R
    volatile uint32_t    CHDATIN3R;            // [Read-write] CHDATIN3R
    reserved_t<3>        _3;
    volatile uint32_t    CHCFG4R1;             // [Read-write] CHCFG4R1
    volatile uint32_t    CHCFG4R2;             // [Read-write] CHCFG4R2
    volatile uint32_t    AWSCD4R;              // [Read-write] AWSCD4R
    volatile uint32_t    CHWDAT4R;             // [Read-write] CHWDAT4R
    volatile uint32_t    CHDATIN4R;            // [Read-write] CHDATIN4R
    reserved_t<3>        _4;
    volatile uint32_t    CHCFG5R1;             // [Read-write] CHCFG5R1
    volatile uint32_t    CHCFG5R2;             // [Read-write] CHCFG5R2
    volatile uint32_t    AWSCD5R;              // [Read-write] AWSCD5R
    volatile uint32_t    CHWDAT5R;             // [Read-write] CHWDAT5R
    volatile uint32_t    CHDATIN5R;            // [Read-write] CHDATIN5R
    reserved_t<3>        _5;
    volatile uint32_t    CHCFG6R1;             // [Read-write] CHCFG6R1
    volatile uint32_t    CHCFG6R2;             // [Read-write] CHCFG6R2
    volatile uint32_t    AWSCD6R;              // [Read-write] AWSCD6R
    volatile uint32_t    CHWDAT6R;             // [Read-write] CHWDAT6R
    volatile uint32_t    CHDATIN6R;            // [Read-write] CHDATIN6R
    reserved_t<3>        _6;
    volatile uint32_t    CHCFG7R1;             // [Read-write] CHCFG7R1
    volatile uint32_t    CHCFG7R2;             // [Read-write] CHCFG7R2
    volatile uint32_t    AWSCD7R;              // [Read-write] AWSCD7R
    volatile uint32_t    CHWDAT7R;             // [Read-write] CHWDAT7R
    volatile uint32_t    CHDATIN7R;            // [Read-write] CHDATIN7R
    reserved_t<3>        _7;
    volatile uint32_t    DFSDM0_CR1;           // [Read-write] control register 1
    volatile uint32_t    DFSDM0_CR2;           // [Read-write] control register 2
    volatile uint32_t    DFSDM0_ISR;           // [Read-only] interrupt and status register
    volatile uint32_t    DFSDM0_ICR;           // [Read-write] interrupt flag clear register
    volatile uint32_t    DFSDM0_JCHGR;         // [Read-write] injected channel group selection register
    volatile uint32_t    DFSDM0_FCR;           // [Read-write] filter control register
    volatile uint32_t    DFSDM0_JDATAR;        // [Read-only] data register for injected group
    volatile uint32_t    DFSDM0_RDATAR;        // [Read-only] data register for the regular channel
    volatile uint32_t    DFSDM0_AWHTR;         // [Read-write] analog watchdog high threshold register
    volatile uint32_t    DFSDM0_AWLTR;         // [Read-write] analog watchdog low threshold register
    volatile uint32_t    DFSDM0_AWSR;          // [Read-only] analog watchdog status register
    volatile uint32_t    DFSDM0_AWCFR;         // [Read-write] analog watchdog clear flag register
    volatile uint32_t    DFSDM0_EXMAX;         // [Read-only] Extremes detector maximum register
    volatile uint32_t    DFSDM0_EXMIN;         // [Read-only] Extremes detector minimum register
    volatile uint32_t    DFSDM0_CNVTIMR;       // [Read-only] conversion timer register
    reserved_t<49>       _8;
    volatile uint32_t    DFSDM1_CR1;           // [Read-write] control register 1
    volatile uint32_t    DFSDM1_CR2;           // [Read-write] control register 2
    volatile uint32_t    DFSDM1_ISR;           // [Read-only] interrupt and status register
    volatile uint32_t    DFSDM1_ICR;           // [Read-write] interrupt flag clear register
    volatile uint32_t    DFSDM1_JCHGR;         // [Read-write] injected channel group selection register
    volatile uint32_t    DFSDM1_FCR;           // [Read-write] filter control register
    volatile uint32_t    DFSDM1_JDATAR;        // [Read-only] data register for injected group
    volatile uint32_t    DFSDM1_RDATAR;        // [Read-only] data register for the regular channel
    volatile uint32_t    DFSDM1_AWHTR;         // [Read-write] analog watchdog high threshold register
    volatile uint32_t    DFSDM1_AWLTR;         // [Read-write] analog watchdog low threshold register
    volatile uint32_t    DFSDM1_AWSR;          // [Read-only] analog watchdog status register
    volatile uint32_t    DFSDM1_AWCFR;         // [Read-write] analog watchdog clear flag register
    volatile uint32_t    DFSDM1_EXMAX;         // [Read-only] Extremes detector maximum register
    volatile uint32_t    DFSDM1_EXMIN;         // [Read-only] Extremes detector minimum register
    volatile uint32_t    DFSDM1_CNVTIMR;       // [Read-only] conversion timer register
    reserved_t<49>       _9;
    volatile uint32_t    DFSDM2_CR1;           // [Read-write] control register 1
    volatile uint32_t    DFSDM2_CR2;           // [Read-write] control register 2
    volatile uint32_t    DFSDM2_ISR;           // [Read-only] interrupt and status register
    volatile uint32_t    DFSDM2_ICR;           // [Read-write] interrupt flag clear register
    volatile uint32_t    DFSDM2_JCHGR;         // [Read-write] injected channel group selection register
    volatile uint32_t    DFSDM2_FCR;           // [Read-write] filter control register
    volatile uint32_t    DFSDM2_JDATAR;        // [Read-only] data register for injected group
    volatile uint32_t    DFSDM2_RDATAR;        // [Read-only] data register for the regular channel
    volatile uint32_t    DFSDM2_AWHTR;         // [Read-write] analog watchdog high threshold register
    volatile uint32_t    DFSDM2_AWLTR;         // [Read-write] analog watchdog low threshold register
    volatile uint32_t    DFSDM2_AWSR;          // [Read-only] analog watchdog status register
    volatile uint32_t    DFSDM2_AWCFR;         // [Read-write] analog watchdog clear flag register
    volatile uint32_t    DFSDM2_EXMAX;         // [Read-only] Extremes detector maximum register
    volatile uint32_t    DFSDM2_EXMIN;         // [Read-only] Extremes detector minimum register
    volatile uint32_t    DFSDM2_CNVTIMR;       // [Read-only] conversion timer register
    reserved_t<49>       _10;
    volatile uint32_t    DFSDM3_CR1;           // [Read-write] control register 1
    volatile uint32_t    DFSDM3_CR2;           // [Read-write] control register 2
    volatile uint32_t    DFSDM3_ISR;           // [Read-only] interrupt and status register
    volatile uint32_t    DFSDM3_ICR;           // [Read-write] interrupt flag clear register
    volatile uint32_t    DFSDM3_JCHGR;         // [Read-write] injected channel group selection register
    volatile uint32_t    DFSDM3_FCR;           // [Read-write] filter control register
    volatile uint32_t    DFSDM3_JDATAR;        // [Read-only] data register for injected group
    volatile uint32_t    DFSDM3_RDATAR;        // [Read-only] data register for the regular channel
    volatile uint32_t    DFSDM3_AWHTR;         // [Read-write] analog watchdog high threshold register
    volatile uint32_t    DFSDM3_AWLTR;         // [Read-write] analog watchdog low threshold register
    volatile uint32_t    DFSDM3_AWSR;          // [Read-only] analog watchdog status register
    volatile uint32_t    DFSDM3_AWCFR;         // [Read-write] analog watchdog clear flag register
    volatile uint32_t    DFSDM3_EXMAX;         // [Read-only] Extremes detector maximum register
    volatile uint32_t    DFSDM3_EXMIN;         // [Read-only] Extremes detector minimum register
    volatile uint32_t    DFSDM3_CNVTIMR;       // [Read-only] conversion timer register

    static const uint8_t CHCFG0R1_DFSDMEN = 31;         // DFSDMEN
    static const uint8_t CHCFG0R1_CKOUTSRC = 30;        // CKOUTSRC
    static const uint8_t CHCFG0R1_CKOUTDIV = 16;        // CKOUTDIV (8 bits)
    static const uint8_t CHCFG0R1_DATPACK = 14;         // DATPACK (2 bits)
    static const uint8_t CHCFG0R1_DATMPX = 12;          // DATMPX (2 bits)
    static const uint8_t CHCFG0R1_CHINSEL = 8;          // CHINSEL
    static const uint8_t CHCFG0R1_CHEN = 7;             // CHEN
    static const uint8_t CHCFG0R1_CKABEN = 6;           // CKABEN
    static const uint8_t CHCFG0R1_SCDEN = 5;            // SCDEN
    static const uint8_t CHCFG0R1_SPICKSEL = 2;         // SPICKSEL (2 bits)
    static const uint8_t CHCFG0R1_SITP = 0;             // SITP (2 bits)
    static const uint32_t CHCFG0R1_RESET_VALUE = 0x0;

    static const uint8_t CHCFG0R2_OFFSET = 8;           // OFFSET (24 bits)
    static const uint8_t CHCFG0R2_DTRBS = 3;            // DTRBS (5 bits)
    static const uint32_t CHCFG0R2_RESET_VALUE = 0x0;

    static const uint8_t AWSCD0R_AWFORD = 22;          // AWFORD (2 bits)
    static const uint8_t AWSCD0R_AWFOSR = 16;          // AWFOSR (5 bits)
    static const uint8_t AWSCD0R_BKSCD = 12;           // BKSCD (4 bits)
    static const uint8_t AWSCD0R_SCDT = 0;             // SCDT (8 bits)
    static const uint32_t AWSCD0R_RESET_VALUE = 0x0;

    static const uint8_t CHWDAT0R_WDATA = 0;            // WDATA (16 bits)
    static const uint32_t CHWDAT0R_RESET_VALUE = 0x0;

    static const uint8_t CHDATIN0R_INDAT1 = 16;          // INDAT1 (16 bits)
    static const uint8_t CHDATIN0R_INDAT0 = 0;           // INDAT0 (16 bits)
    static const uint32_t CHDATIN0R_RESET_VALUE = 0x0;

    static const uint8_t CHCFG1R1_DATPACK = 14;         // DATPACK (2 bits)
    static const uint8_t CHCFG1R1_DATMPX = 12;          // DATMPX (2 bits)
    static const uint8_t CHCFG1R1_CHINSEL = 8;          // CHINSEL
    static const uint8_t CHCFG1R1_CHEN = 7;             // CHEN
    static const uint8_t CHCFG1R1_CKABEN = 6;           // CKABEN
    static const uint8_t CHCFG1R1_SCDEN = 5;            // SCDEN
    static const uint8_t CHCFG1R1_SPICKSEL = 2;         // SPICKSEL (2 bits)
    static const uint8_t CHCFG1R1_SITP = 0;             // SITP (2 bits)
    static const uint32_t CHCFG1R1_RESET_VALUE = 0x0;

    static const uint8_t CHCFG1R2_OFFSET = 8;           // OFFSET (24 bits)
    static const uint8_t CHCFG1R2_DTRBS = 3;            // DTRBS (5 bits)
    static const uint32_t CHCFG1R2_RESET_VALUE = 0x0;

    static const uint8_t AWSCD1R_AWFORD = 22;          // AWFORD (2 bits)
    static const uint8_t AWSCD1R_AWFOSR = 16;          // AWFOSR (5 bits)
    static const uint8_t AWSCD1R_BKSCD = 12;           // BKSCD (4 bits)
    static const uint8_t AWSCD1R_SCDT = 0;             // SCDT (8 bits)
    static const uint32_t AWSCD1R_RESET_VALUE = 0x0;

    static const uint8_t CHWDAT1R_WDATA = 0;            // WDATA (16 bits)
    static const uint32_t CHWDAT1R_RESET_VALUE = 0x0;

    static const uint8_t CHDATIN1R_INDAT1 = 16;          // INDAT1 (16 bits)
    static const uint8_t CHDATIN1R_INDAT0 = 0;           // INDAT0 (16 bits)
    static const uint32_t CHDATIN1R_RESET_VALUE = 0x0;

    static const uint8_t CHCFG2R1_DATPACK = 14;         // DATPACK (2 bits)
    static const uint8_t CHCFG2R1_DATMPX = 12;          // DATMPX (2 bits)
    static const uint8_t CHCFG2R1_CHINSEL = 8;          // CHINSEL
    static const uint8_t CHCFG2R1_CHEN = 7;             // CHEN
    static const uint8_t CHCFG2R1_CKABEN = 6;           // CKABEN
    static const uint8_t CHCFG2R1_SCDEN = 5;            // SCDEN
    static const uint8_t CHCFG2R1_SPICKSEL = 2;         // SPICKSEL (2 bits)
    static const uint8_t CHCFG2R1_SITP = 0;             // SITP (2 bits)
    static const uint32_t CHCFG2R1_RESET_VALUE = 0x0;

    static const uint8_t CHCFG2R2_OFFSET = 8;           // OFFSET (24 bits)
    static const uint8_t CHCFG2R2_DTRBS = 3;            // DTRBS (5 bits)
    static const uint32_t CHCFG2R2_RESET_VALUE = 0x0;

    static const uint8_t AWSCD2R_AWFORD = 22;          // AWFORD (2 bits)
    static const uint8_t AWSCD2R_AWFOSR = 16;          // AWFOSR (5 bits)
    static const uint8_t AWSCD2R_BKSCD = 12;           // BKSCD (4 bits)
    static const uint8_t AWSCD2R_SCDT = 0;             // SCDT (8 bits)
    static const uint32_t AWSCD2R_RESET_VALUE = 0x0;

    static const uint8_t CHWDAT2R_WDATA = 0;            // WDATA (16 bits)
    static const uint32_t CHWDAT2R_RESET_VALUE = 0x0;

    static const uint8_t CHDATIN2R_INDAT1 = 16;          // INDAT1 (16 bits)
    static const uint8_t CHDATIN2R_INDAT0 = 0;           // INDAT0 (16 bits)
    static const uint32_t CHDATIN2R_RESET_VALUE = 0x0;

    static const uint8_t CHCFG3R1_DATPACK = 14;         // DATPACK (2 bits)
    static const uint8_t CHCFG3R1_DATMPX = 12;          // DATMPX (2 bits)
    static const uint8_t CHCFG3R1_CHINSEL = 8;          // CHINSEL
    static const uint8_t CHCFG3R1_CHEN = 7;             // CHEN
    static const uint8_t CHCFG3R1_CKABEN = 6;           // CKABEN
    static const uint8_t CHCFG3R1_SCDEN = 5;            // SCDEN
    static const uint8_t CHCFG3R1_SPICKSEL = 2;         // SPICKSEL (2 bits)
    static const uint8_t CHCFG3R1_SITP = 0;             // SITP (2 bits)
    static const uint32_t CHCFG3R1_RESET_VALUE = 0x0;

    static const uint8_t CHCFG3R2_OFFSET = 8;           // OFFSET (24 bits)
    static const uint8_t CHCFG3R2_DTRBS = 3;            // DTRBS (5 bits)
    static const uint32_t CHCFG3R2_RESET_VALUE = 0x0;

    static const uint8_t AWSCD3R_AWFORD = 22;          // AWFORD (2 bits)
    static const uint8_t AWSCD3R_AWFOSR = 16;          // AWFOSR (5 bits)
    static const uint8_t AWSCD3R_BKSCD = 12;           // BKSCD (4 bits)
    static const uint8_t AWSCD3R_SCDT = 0;             // SCDT (8 bits)
    static const uint32_t AWSCD3R_RESET_VALUE = 0x0;

    static const uint8_t CHWDAT3R_WDATA = 0;            // WDATA (16 bits)
    static const uint32_t CHWDAT3R_RESET_VALUE = 0x0;

    static const uint8_t CHDATIN3R_INDAT1 = 16;          // INDAT1 (16 bits)
    static const uint8_t CHDATIN3R_INDAT0 = 0;           // INDAT0 (16 bits)
    static const uint32_t CHDATIN3R_RESET_VALUE = 0x0;

    static const uint8_t CHCFG4R1_DATPACK = 14;         // DATPACK (2 bits)
    static const uint8_t CHCFG4R1_DATMPX = 12;          // DATMPX (2 bits)
    static const uint8_t CHCFG4R1_CHINSEL = 8;          // CHINSEL
    static const uint8_t CHCFG4R1_CHEN = 7;             // CHEN
    static const uint8_t CHCFG4R1_CKABEN = 6;           // CKABEN
    static const uint8_t CHCFG4R1_SCDEN = 5;            // SCDEN
    static const uint8_t CHCFG4R1_SPICKSEL = 2;         // SPICKSEL (2 bits)
    static const uint8_t CHCFG4R1_SITP = 0;             // SITP (2 bits)
    static const uint32_t CHCFG4R1_RESET_VALUE = 0x0;

    static const uint8_t CHCFG4R2_OFFSET = 8;           // OFFSET (24 bits)
    static const uint8_t CHCFG4R2_DTRBS = 3;            // DTRBS (5 bits)
    static const uint32_t CHCFG4R2_RESET_VALUE = 0x0;

    static const uint8_t AWSCD4R_AWFORD = 22;          // AWFORD (2 bits)
    static const uint8_t AWSCD4R_AWFOSR = 16;          // AWFOSR (5 bits)
    static const uint8_t AWSCD4R_BKSCD = 12;           // BKSCD (4 bits)
    static const uint8_t AWSCD4R_SCDT = 0;             // SCDT (8 bits)
    static const uint32_t AWSCD4R_RESET_VALUE = 0x0;

    static const uint8_t CHWDAT4R_WDATA = 0;            // WDATA (16 bits)
    static const uint32_t CHWDAT4R_RESET_VALUE = 0x0;

    static const uint8_t CHDATIN4R_INDAT1 = 16;          // INDAT1 (16 bits)
    static const uint8_t CHDATIN4R_INDAT0 = 0;           // INDAT0 (16 bits)
    static const uint32_t CHDATIN4R_RESET_VALUE = 0x0;

    static const uint8_t CHCFG5R1_DATPACK = 14;         // DATPACK (2 bits)
    static const uint8_t CHCFG5R1_DATMPX = 12;          // DATMPX (2 bits)
    static const uint8_t CHCFG5R1_CHINSEL = 8;          // CHINSEL
    static const uint8_t CHCFG5R1_CHEN = 7;             // CHEN
    static const uint8_t CHCFG5R1_CKABEN = 6;           // CKABEN
    static const uint8_t CHCFG5R1_SCDEN = 5;            // SCDEN
    static const uint8_t CHCFG5R1_SPICKSEL = 2;         // SPICKSEL (2 bits)
    static const uint8_t CHCFG5R1_SITP = 0;             // SITP (2 bits)
    static const uint32_t CHCFG5R1_RESET_VALUE = 0x0;

    static const uint8_t CHCFG5R2_OFFSET = 8;           // OFFSET (24 bits)
    static const uint8_t CHCFG5R2_DTRBS = 3;            // DTRBS (5 bits)
    static const uint32_t CHCFG5R2_RESET_VALUE = 0x0;

    static const uint8_t AWSCD5R_AWFORD = 22;          // AWFORD (2 bits)
    static const uint8_t AWSCD5R_AWFOSR = 16;          // AWFOSR (5 bits)
    static const uint8_t AWSCD5R_BKSCD = 12;           // BKSCD (4 bits)
    static const uint8_t AWSCD5R_SCDT = 0;             // SCDT (8 bits)
    static const uint32_t AWSCD5R_RESET_VALUE = 0x0;

    static const uint8_t CHWDAT5R_WDATA = 0;            // WDATA (16 bits)
    static const uint32_t CHWDAT5R_RESET_VALUE = 0x0;

    static const uint8_t CHDATIN5R_INDAT1 = 16;          // INDAT1 (16 bits)
    static const uint8_t CHDATIN5R_INDAT0 = 0;           // INDAT0 (16 bits)
    static const uint32_t CHDATIN5R_RESET_VALUE = 0x0;

    static const uint8_t CHCFG6R1_DATPACK = 14;         // DATPACK (2 bits)
    static const uint8_t CHCFG6R1_DATMPX = 12;          // DATMPX (2 bits)
    static const uint8_t CHCFG6R1_CHINSEL = 8;          // CHINSEL
    static const uint8_t CHCFG6R1_CHEN = 7;             // CHEN
    static const uint8_t CHCFG6R1_CKABEN = 6;           // CKABEN
    static const uint8_t CHCFG6R1_SCDEN = 5;            // SCDEN
    static const uint8_t CHCFG6R1_SPICKSEL = 2;         // SPICKSEL (2 bits)
    static const uint8_t CHCFG6R1_SITP = 0;             // SITP (2 bits)
    static const uint32_t CHCFG6R1_RESET_VALUE = 0x0;

    static const uint8_t CHCFG6R2_OFFSET = 8;           // OFFSET (24 bits)
    static const uint8_t CHCFG6R2_DTRBS = 3;            // DTRBS (5 bits)
    static const uint32_t CHCFG6R2_RESET_VALUE = 0x0;

    static const uint8_t AWSCD6R_AWFORD = 22;          // AWFORD (2 bits)
    static const uint8_t AWSCD6R_AWFOSR = 16;          // AWFOSR (5 bits)
    static const uint8_t AWSCD6R_BKSCD = 12;           // BKSCD (4 bits)
    static const uint8_t AWSCD6R_SCDT = 0;             // SCDT (8 bits)
    static const uint32_t AWSCD6R_RESET_VALUE = 0x0;

    static const uint8_t CHWDAT6R_WDATA = 0;            // WDATA (16 bits)
    static const uint32_t CHWDAT6R_RESET_VALUE = 0x0;

    static const uint8_t CHDATIN6R_INDAT1 = 16;          // INDAT1 (16 bits)
    static const uint8_t CHDATIN6R_INDAT0 = 0;           // INDAT0 (16 bits)
    static const uint32_t CHDATIN6R_RESET_VALUE = 0x0;

    static const uint8_t CHCFG7R1_DATPACK = 14;         // DATPACK (2 bits)
    static const uint8_t CHCFG7R1_DATMPX = 12;          // DATMPX (2 bits)
    static const uint8_t CHCFG7R1_CHINSEL = 8;          // CHINSEL
    static const uint8_t CHCFG7R1_CHEN = 7;             // CHEN
    static const uint8_t CHCFG7R1_CKABEN = 6;           // CKABEN
    static const uint8_t CHCFG7R1_SCDEN = 5;            // SCDEN
    static const uint8_t CHCFG7R1_SPICKSEL = 2;         // SPICKSEL (2 bits)
    static const uint8_t CHCFG7R1_SITP = 0;             // SITP (2 bits)
    static const uint32_t CHCFG7R1_RESET_VALUE = 0x0;

    static const uint8_t CHCFG7R2_OFFSET = 8;           // OFFSET (24 bits)
    static const uint8_t CHCFG7R2_DTRBS = 3;            // DTRBS (5 bits)
    static const uint32_t CHCFG7R2_RESET_VALUE = 0x0;

    static const uint8_t AWSCD7R_AWFORD = 22;          // AWFORD (2 bits)
    static const uint8_t AWSCD7R_AWFOSR = 16;          // AWFOSR (5 bits)
    static const uint8_t AWSCD7R_BKSCD = 12;           // BKSCD (4 bits)
    static const uint8_t AWSCD7R_SCDT = 0;             // SCDT (8 bits)
    static const uint32_t AWSCD7R_RESET_VALUE = 0x0;

    static const uint8_t CHWDAT7R_WDATA = 0;            // WDATA (16 bits)
    static const uint32_t CHWDAT7R_RESET_VALUE = 0x0;

    static const uint8_t CHDATIN7R_INDAT1 = 16;          // INDAT1 (16 bits)
    static const uint8_t CHDATIN7R_INDAT0 = 0;           // INDAT0 (16 bits)
    static const uint32_t CHDATIN7R_RESET_VALUE = 0x0;

    static const uint8_t DFSDM0_CR1_AWFSEL = 30;          // Analog watchdog fast mode select
    static const uint8_t DFSDM0_CR1_FAST = 29;            // Fast conversion mode selection for regular conversions
    static const uint8_t DFSDM0_CR1_RCH = 24;             // Regular channel selection (3 bits)
    static const uint8_t DFSDM0_CR1_RDMAEN = 21;          // DMA channel enabled to read data for the regular conversion
    static const uint8_t DFSDM0_CR1_RSYNC = 19;           // Launch regular conversion synchronously with DFSDM0
    static const uint8_t DFSDM0_CR1_RCONT = 18;           // Continuous mode selection for regular conversions
    static const uint8_t DFSDM0_CR1_RSWSTART = 17;        // Software start of a conversion on the regular channel
    static const uint8_t DFSDM0_CR1_JEXTEN = 13;          // Trigger enable and trigger edge selection for injected conversions (2 bits)
    static const uint8_t DFSDM0_CR1_JEXTSEL = 8;          // Trigger signal selection for launching injected conversions (3 bits)
    static const uint8_t DFSDM0_CR1_JDMAEN = 5;           // DMA channel enabled to read data for the injected channel group
    static const uint8_t DFSDM0_CR1_JSCAN = 4;            // Scanning conversion mode for injected conversions
    static const uint8_t DFSDM0_CR1_JSYNC = 3;            // Launch an injected conversion synchronously with the DFSDM0 JSWSTART trigger
    static const uint8_t DFSDM0_CR1_JSWSTART = 1;         // Start a conversion of the injected group of channels
    static const uint8_t DFSDM0_CR1_DFEN = 0;             // DFSDM enable
    static const uint32_t DFSDM0_CR1_RESET_VALUE = 0x0;

    static const uint8_t DFSDM0_CR2_AWDCH = 16;           // Analog watchdog channel selection (8 bits)
    static const uint8_t DFSDM0_CR2_EXCH = 8;             // Extremes detector channel selection (8 bits)
    static const uint8_t DFSDM0_CR2_CKABIE = 6;           // Clock absence interrupt enable
    static const uint8_t DFSDM0_CR2_SCDIE = 5;            // Short-circuit detector interrupt enable
    static const uint8_t DFSDM0_CR2_AWDIE = 4;            // Analog watchdog interrupt enable
    static const uint8_t DFSDM0_CR2_ROVRIE = 3;           // Regular data overrun interrupt enable
    static const uint8_t DFSDM0_CR2_JOVRIE = 2;           // Injected data overrun interrupt enable
    static const uint8_t DFSDM0_CR2_REOCIE = 1;           // Regular end of conversion interrupt enable
    static const uint8_t DFSDM0_CR2_JEOCIE = 0;           // Injected end of conversion interrupt enable
    static const uint32_t DFSDM0_CR2_RESET_VALUE = 0x0;

    static const uint8_t DFSDM0_ISR_SCDF = 24;            // short-circuit detector flag (8 bits)
    static const uint8_t DFSDM0_ISR_CKABF = 16;           // Clock absence flag (8 bits)
    static const uint8_t DFSDM0_ISR_RCIP = 14;            // Regular conversion in progress status
    static const uint8_t DFSDM0_ISR_JCIP = 13;            // Injected conversion in progress status
    static const uint8_t DFSDM0_ISR_AWDF = 4;             // Analog watchdog
    static const uint8_t DFSDM0_ISR_ROVRF = 3;            // Regular conversion overrun flag
    static const uint8_t DFSDM0_ISR_JOVRF = 2;            // Injected conversion overrun flag
    static const uint8_t DFSDM0_ISR_REOCF = 1;            // End of regular conversion flag
    static const uint8_t DFSDM0_ISR_JEOCF = 0;            // End of injected conversion flag
    static const uint32_t DFSDM0_ISR_RESET_VALUE = 0xff0000;

    static const uint8_t DFSDM0_ICR_CLRSCDF = 24;         // Clear the short-circuit detector flag (8 bits)
    static const uint8_t DFSDM0_ICR_CLRCKABF = 16;        // Clear the clock absence flag (8 bits)
    static const uint8_t DFSDM0_ICR_CLRROVRF = 3;         // Clear the regular conversion overrun flag
    static const uint8_t DFSDM0_ICR_CLRJOVRF = 2;         // Clear the injected conversion overrun flag
    static const uint32_t DFSDM0_ICR_RESET_VALUE = 0x0;

    static const uint8_t DFSDM0_JCHGR_JCHG = 0;             // Injected channel group selection (8 bits)
    static const uint32_t DFSDM0_JCHGR_RESET_VALUE = 0x1;

    static const uint8_t DFSDM0_FCR_FORD = 29;            // Sinc filter order (3 bits)
    static const uint8_t DFSDM0_FCR_FOSR = 16;            // Sinc filter oversampling ratio (decimation rate) (10 bits)
    static const uint8_t DFSDM0_FCR_IOSR = 0;             // Integrator oversampling ratio (averaging length) (8 bits)
    static const uint32_t DFSDM0_FCR_RESET_VALUE = 0x0;

    static const uint8_t DFSDM0_JDATAR_JDATA = 8;            // Injected group conversion data (24 bits)
    static const uint8_t DFSDM0_JDATAR_JDATACH = 0;          // Injected channel most recently converted (3 bits)
    static const uint32_t DFSDM0_JDATAR_RESET_VALUE = 0x0;

    static const uint8_t DFSDM0_RDATAR_RDATA = 8;            // Regular channel conversion data (24 bits)
    static const uint8_t DFSDM0_RDATAR_RPEND = 4;            // Regular channel pending data
    static const uint8_t DFSDM0_RDATAR_RDATACH = 0;          // Regular channel most recently converted (3 bits)
    static const uint32_t DFSDM0_RDATAR_RESET_VALUE = 0x0;

    static const uint8_t DFSDM0_AWHTR_AWHT = 8;             // Analog watchdog high threshold (24 bits)
    static const uint8_t DFSDM0_AWHTR_BKAWH = 0;            // Break signal assignment to analog watchdog high threshold event (4 bits)
    static const uint32_t DFSDM0_AWHTR_RESET_VALUE = 0x0;

    static const uint8_t DFSDM0_AWLTR_AWLT = 8;             // Analog watchdog low threshold (24 bits)
    static const uint8_t DFSDM0_AWLTR_BKAWL = 0;            // Break signal assignment to analog watchdog low threshold event (4 bits)
    static const uint32_t DFSDM0_AWLTR_RESET_VALUE = 0x0;

    static const uint8_t DFSDM0_AWSR_AWHTF = 8;            // Analog watchdog high threshold flag (8 bits)
    static const uint8_t DFSDM0_AWSR_AWLTF = 0;            // Analog watchdog low threshold flag (8 bits)
    static const uint32_t DFSDM0_AWSR_RESET_VALUE = 0x0;

    static const uint8_t DFSDM0_AWCFR_CLRAWHTF = 8;         // Clear the analog watchdog high threshold flag (8 bits)
    static const uint8_t DFSDM0_AWCFR_CLRAWLTF = 0;         // Clear the analog watchdog low threshold flag (8 bits)
    static const uint32_t DFSDM0_AWCFR_RESET_VALUE = 0x0;

    static const uint8_t DFSDM0_EXMAX_EXMAX = 8;            // Extremes detector maximum value (24 bits)
    static const uint8_t DFSDM0_EXMAX_EXMAXCH = 0;          // Extremes detector maximum data channel (3 bits)
    static const uint32_t DFSDM0_EXMAX_RESET_VALUE = 0x80000000;

    static const uint8_t DFSDM0_EXMIN_EXMIN = 8;            // EXMIN (24 bits)
    static const uint8_t DFSDM0_EXMIN_EXMINCH = 0;          // Extremes detector minimum data channel (3 bits)
    static const uint32_t DFSDM0_EXMIN_RESET_VALUE = 0x7fffff00;

    static const uint8_t DFSDM0_CNVTIMR_CNVCNT = 4;           // 28-bit timer counting conversion time t = CNVCNT[27:0] / fDFSDM_CKIN (28 bits)
    static const uint32_t DFSDM0_CNVTIMR_RESET_VALUE = 0x0;

    static const uint8_t DFSDM1_CR1_AWFSEL = 30;          // Analog watchdog fast mode select
    static const uint8_t DFSDM1_CR1_FAST = 29;            // Fast conversion mode selection for regular conversions
    static const uint8_t DFSDM1_CR1_RCH = 24;             // Regular channel selection (3 bits)
    static const uint8_t DFSDM1_CR1_RDMAEN = 21;          // DMA channel enabled to read data for the regular conversion
    static const uint8_t DFSDM1_CR1_RSYNC = 19;           // Launch regular conversion synchronously with DFSDM0
    static const uint8_t DFSDM1_CR1_RCONT = 18;           // Continuous mode selection for regular conversions
    static const uint8_t DFSDM1_CR1_RSWSTART = 17;        // Software start of a conversion on the regular channel
    static const uint8_t DFSDM1_CR1_JEXTEN = 13;          // Trigger enable and trigger edge selection for injected conversions (2 bits)
    static const uint8_t DFSDM1_CR1_JEXTSEL = 8;          // Trigger signal selection for launching injected conversions (3 bits)
    static const uint8_t DFSDM1_CR1_JDMAEN = 5;           // DMA channel enabled to read data for the injected channel group
    static const uint8_t DFSDM1_CR1_JSCAN = 4;            // Scanning conversion mode for injected conversions
    static const uint8_t DFSDM1_CR1_JSYNC = 3;            // Launch an injected conversion synchronously with the DFSDM0 JSWSTART trigger
    static const uint8_t DFSDM1_CR1_JSWSTART = 1;         // Start a conversion of the injected group of channels
    static const uint8_t DFSDM1_CR1_DFEN = 0;             // DFSDM enable
    static const uint32_t DFSDM1_CR1_RESET_VALUE = 0x0;

    static const uint8_t DFSDM1_CR2_AWDCH = 16;           // Analog watchdog channel selection (8 bits)
    static const uint8_t DFSDM1_CR2_EXCH = 8;             // Extremes detector channel selection (8 bits)
    static const uint8_t DFSDM1_CR2_CKABIE = 6;           // Clock absence interrupt enable
    static const uint8_t DFSDM1_CR2_SCDIE = 5;            // Short-circuit detector interrupt enable
    static const uint8_t DFSDM1_CR2_AWDIE = 4;            // Analog watchdog interrupt enable
    static const uint8_t DFSDM1_CR2_ROVRIE = 3;           // Regular data overrun interrupt enable
    static const uint8_t DFSDM1_CR2_JOVRIE = 2;           // Injected data overrun interrupt enable
    static const uint8_t DFSDM1_CR2_REOCIE = 1;           // Regular end of conversion interrupt enable
    static const uint8_t DFSDM1_CR2_JEOCIE = 0;           // Injected end of conversion interrupt enable
    static const uint32_t DFSDM1_CR2_RESET_VALUE = 0x0;

    static const uint8_t DFSDM1_ISR_SCDF = 24;            // short-circuit detector flag (8 bits)
    static const uint8_t DFSDM1_ISR_CKABF = 16;           // Clock absence flag (8 bits)
    static const uint8_t DFSDM1_ISR_RCIP = 14;            // Regular conversion in progress status
    static const uint8_t DFSDM1_ISR_JCIP = 13;            // Injected conversion in progress status
    static const uint8_t DFSDM1_ISR_AWDF = 4;             // Analog watchdog
    static const uint8_t DFSDM1_ISR_ROVRF = 3;            // Regular conversion overrun flag
    static const uint8_t DFSDM1_ISR_JOVRF = 2;            // Injected conversion overrun flag
    static const uint8_t DFSDM1_ISR_REOCF = 1;            // End of regular conversion flag
    static const uint8_t DFSDM1_ISR_JEOCF = 0;            // End of injected conversion flag
    static const uint32_t DFSDM1_ISR_RESET_VALUE = 0xff0000;

    static const uint8_t DFSDM1_ICR_CLRSCDF = 24;         // Clear the short-circuit detector flag (8 bits)
    static const uint8_t DFSDM1_ICR_CLRCKABF = 16;        // Clear the clock absence flag (8 bits)
    static const uint8_t DFSDM1_ICR_CLRROVRF = 3;         // Clear the regular conversion overrun flag
    static const uint8_t DFSDM1_ICR_CLRJOVRF = 2;         // Clear the injected conversion overrun flag
    static const uint32_t DFSDM1_ICR_RESET_VALUE = 0x0;

    static const uint8_t DFSDM1_JCHGR_JCHG = 0;             // Injected channel group selection (8 bits)
    static const uint32_t DFSDM1_JCHGR_RESET_VALUE = 0x1;

    static const uint8_t DFSDM1_FCR_FORD = 29;            // Sinc filter order (3 bits)
    static const uint8_t DFSDM1_FCR_FOSR = 16;            // Sinc filter oversampling ratio (decimation rate) (10 bits)
    static const uint8_t DFSDM1_FCR_IOSR = 0;             // Integrator oversampling ratio (averaging length) (8 bits)
    static const uint32_t DFSDM1_FCR_RESET_VALUE = 0x0;

    static const uint8_t DFSDM1_JDATAR_JDATA = 8;            // Injected group conversion data (24 bits)
    static const uint8_t DFSDM1_JDATAR_JDATACH = 0;          // Injected channel most recently converted (3 bits)
    static const uint32_t DFSDM1_JDATAR_RESET_VALUE = 0x0;

    static const uint8_t DFSDM1_RDATAR_RDATA = 8;            // Regular channel conversion data (24 bits)
    static const uint8_t DFSDM1_RDATAR_RPEND = 4;            // Regular channel pending data
    static const uint8_t DFSDM1_RDATAR_RDATACH = 0;          // Regular channel most recently converted (3 bits)
    static const uint32_t DFSDM1_RDATAR_RESET_VALUE = 0x0;

    static const uint8_t DFSDM1_AWHTR_AWHT = 8;             // Analog watchdog high threshold (24 bits)
    static const uint8_t DFSDM1_AWHTR_BKAWH = 0;            // Break signal assignment to analog watchdog high threshold event (4 bits)
    static const uint32_t DFSDM1_AWHTR_RESET_VALUE = 0x0;

    static const uint8_t DFSDM1_AWLTR_AWLT = 8;             // Analog watchdog low threshold (24 bits)
    static const uint8_t DFSDM1_AWLTR_BKAWL = 0;            // Break signal assignment to analog watchdog low threshold event (4 bits)
    static const uint32_t DFSDM1_AWLTR_RESET_VALUE = 0x0;

    static const uint8_t DFSDM1_AWSR_AWHTF = 8;            // Analog watchdog high threshold flag (8 bits)
    static const uint8_t DFSDM1_AWSR_AWLTF = 0;            // Analog watchdog low threshold flag (8 bits)
    static const uint32_t DFSDM1_AWSR_RESET_VALUE = 0x0;

    static const uint8_t DFSDM1_AWCFR_CLRAWHTF = 8;         // Clear the analog watchdog high threshold flag (8 bits)
    static const uint8_t DFSDM1_AWCFR_CLRAWLTF = 0;         // Clear the analog watchdog low threshold flag (8 bits)
    static const uint32_t DFSDM1_AWCFR_RESET_VALUE = 0x0;

    static const uint8_t DFSDM1_EXMAX_EXMAX = 8;            // Extremes detector maximum value (24 bits)
    static const uint8_t DFSDM1_EXMAX_EXMAXCH = 0;          // Extremes detector maximum data channel (3 bits)
    static const uint32_t DFSDM1_EXMAX_RESET_VALUE = 0x80000000;

    static const uint8_t DFSDM1_EXMIN_EXMIN = 8;            // EXMIN (24 bits)
    static const uint8_t DFSDM1_EXMIN_EXMINCH = 0;          // Extremes detector minimum data channel (3 bits)
    static const uint32_t DFSDM1_EXMIN_RESET_VALUE = 0x7fffff00;

    static const uint8_t DFSDM1_CNVTIMR_CNVCNT = 4;           // 28-bit timer counting conversion time t = CNVCNT[27:0] / fDFSDM_CKIN (28 bits)
    static const uint32_t DFSDM1_CNVTIMR_RESET_VALUE = 0x0;

    static const uint8_t DFSDM2_CR1_AWFSEL = 30;          // Analog watchdog fast mode select
    static const uint8_t DFSDM2_CR1_FAST = 29;            // Fast conversion mode selection for regular conversions
    static const uint8_t DFSDM2_CR1_RCH = 24;             // Regular channel selection (3 bits)
    static const uint8_t DFSDM2_CR1_RDMAEN = 21;          // DMA channel enabled to read data for the regular conversion
    static const uint8_t DFSDM2_CR1_RSYNC = 19;           // Launch regular conversion synchronously with DFSDM0
    static const uint8_t DFSDM2_CR1_RCONT = 18;           // Continuous mode selection for regular conversions
    static const uint8_t DFSDM2_CR1_RSWSTART = 17;        // Software start of a conversion on the regular channel
    static const uint8_t DFSDM2_CR1_JEXTEN = 13;          // Trigger enable and trigger edge selection for injected conversions (2 bits)
    static const uint8_t DFSDM2_CR1_JEXTSEL = 8;          // Trigger signal selection for launching injected conversions (3 bits)
    static const uint8_t DFSDM2_CR1_JDMAEN = 5;           // DMA channel enabled to read data for the injected channel group
    static const uint8_t DFSDM2_CR1_JSCAN = 4;            // Scanning conversion mode for injected conversions
    static const uint8_t DFSDM2_CR1_JSYNC = 3;            // Launch an injected conversion synchronously with the DFSDM0 JSWSTART trigger
    static const uint8_t DFSDM2_CR1_JSWSTART = 1;         // Start a conversion of the injected group of channels
    static const uint8_t DFSDM2_CR1_DFEN = 0;             // DFSDM enable
    static const uint32_t DFSDM2_CR1_RESET_VALUE = 0x0;

    static const uint8_t DFSDM2_CR2_AWDCH = 16;           // Analog watchdog channel selection (8 bits)
    static const uint8_t DFSDM2_CR2_EXCH = 8;             // Extremes detector channel selection (8 bits)
    static const uint8_t DFSDM2_CR2_CKABIE = 6;           // Clock absence interrupt enable
    static const uint8_t DFSDM2_CR2_SCDIE = 5;            // Short-circuit detector interrupt enable
    static const uint8_t DFSDM2_CR2_AWDIE = 4;            // Analog watchdog interrupt enable
    static const uint8_t DFSDM2_CR2_ROVRIE = 3;           // Regular data overrun interrupt enable
    static const uint8_t DFSDM2_CR2_JOVRIE = 2;           // Injected data overrun interrupt enable
    static const uint8_t DFSDM2_CR2_REOCIE = 1;           // Regular end of conversion interrupt enable
    static const uint8_t DFSDM2_CR2_JEOCIE = 0;           // Injected end of conversion interrupt enable
    static const uint32_t DFSDM2_CR2_RESET_VALUE = 0x0;

    static const uint8_t DFSDM2_ISR_SCDF = 24;            // short-circuit detector flag (8 bits)
    static const uint8_t DFSDM2_ISR_CKABF = 16;           // Clock absence flag (8 bits)
    static const uint8_t DFSDM2_ISR_RCIP = 14;            // Regular conversion in progress status
    static const uint8_t DFSDM2_ISR_JCIP = 13;            // Injected conversion in progress status
    static const uint8_t DFSDM2_ISR_AWDF = 4;             // Analog watchdog
    static const uint8_t DFSDM2_ISR_ROVRF = 3;            // Regular conversion overrun flag
    static const uint8_t DFSDM2_ISR_JOVRF = 2;            // Injected conversion overrun flag
    static const uint8_t DFSDM2_ISR_REOCF = 1;            // End of regular conversion flag
    static const uint8_t DFSDM2_ISR_JEOCF = 0;            // End of injected conversion flag
    static const uint32_t DFSDM2_ISR_RESET_VALUE = 0xff0000;

    static const uint8_t DFSDM2_ICR_CLRSCDF = 24;         // Clear the short-circuit detector flag (8 bits)
    static const uint8_t DFSDM2_ICR_CLRCKABF = 16;        // Clear the clock absence flag (8 bits)
    static const uint8_t DFSDM2_ICR_CLRROVRF = 3;         // Clear the regular conversion overrun flag
    static const uint8_t DFSDM2_ICR_CLRJOVRF = 2;         // Clear the injected conversion overrun flag
    static const uint32_t DFSDM2_ICR_RESET_VALUE = 0x0;

    static const uint8_t DFSDM2_JCHGR_JCHG = 0;             // Injected channel group selection (8 bits)
    static const uint32_t DFSDM2_JCHGR_RESET_VALUE = 0x1;

    static const uint8_t DFSDM2_FCR_FORD = 29;            // Sinc filter order (3 bits)
    static const uint8_t DFSDM2_FCR_FOSR = 16;            // Sinc filter oversampling ratio (decimation rate) (10 bits)
    static const uint8_t DFSDM2_FCR_IOSR = 0;             // Integrator oversampling ratio (averaging length) (8 bits)
    static const uint32_t DFSDM2_FCR_RESET_VALUE = 0x0;

    static const uint8_t DFSDM2_JDATAR_JDATA = 8;            // Injected group conversion data (24 bits)
    static const uint8_t DFSDM2_JDATAR_JDATACH = 0;          // Injected channel most recently converted (3 bits)
    static const uint32_t DFSDM2_JDATAR_RESET_VALUE = 0x0;

    static const uint8_t DFSDM2_RDATAR_RDATA = 8;            // Regular channel conversion data (24 bits)
    static const uint8_t DFSDM2_RDATAR_RPEND = 4;            // Regular channel pending data
    static const uint8_t DFSDM2_RDATAR_RDATACH = 0;          // Regular channel most recently converted (3 bits)
    static const uint32_t DFSDM2_RDATAR_RESET_VALUE = 0x0;

    static const uint8_t DFSDM2_AWHTR_AWHT = 8;             // Analog watchdog high threshold (24 bits)
    static const uint8_t DFSDM2_AWHTR_BKAWH = 0;            // Break signal assignment to analog watchdog high threshold event (4 bits)
    static const uint32_t DFSDM2_AWHTR_RESET_VALUE = 0x0;

    static const uint8_t DFSDM2_AWLTR_AWLT = 8;             // Analog watchdog low threshold (24 bits)
    static const uint8_t DFSDM2_AWLTR_BKAWL = 0;            // Break signal assignment to analog watchdog low threshold event (4 bits)
    static const uint32_t DFSDM2_AWLTR_RESET_VALUE = 0x0;

    static const uint8_t DFSDM2_AWSR_AWHTF = 8;            // Analog watchdog high threshold flag (8 bits)
    static const uint8_t DFSDM2_AWSR_AWLTF = 0;            // Analog watchdog low threshold flag (8 bits)
    static const uint32_t DFSDM2_AWSR_RESET_VALUE = 0x0;

    static const uint8_t DFSDM2_AWCFR_CLRAWHTF = 8;         // Clear the analog watchdog high threshold flag (8 bits)
    static const uint8_t DFSDM2_AWCFR_CLRAWLTF = 0;         // Clear the analog watchdog low threshold flag (8 bits)
    static const uint32_t DFSDM2_AWCFR_RESET_VALUE = 0x0;

    static const uint8_t DFSDM2_EXMAX_EXMAX = 8;            // Extremes detector maximum value (24 bits)
    static const uint8_t DFSDM2_EXMAX_EXMAXCH = 0;          // Extremes detector maximum data channel (3 bits)
    static const uint32_t DFSDM2_EXMAX_RESET_VALUE = 0x80000000;

    static const uint8_t DFSDM2_EXMIN_EXMIN = 8;            // EXMIN (24 bits)
    static const uint8_t DFSDM2_EXMIN_EXMINCH = 0;          // Extremes detector minimum data channel (3 bits)
    static const uint32_t DFSDM2_EXMIN_RESET_VALUE = 0x7fffff00;

    static const uint8_t DFSDM2_CNVTIMR_CNVCNT = 4;           // 28-bit timer counting conversion time t = CNVCNT[27:0] / fDFSDM_CKIN (28 bits)
    static const uint32_t DFSDM2_CNVTIMR_RESET_VALUE = 0x0;

    static const uint8_t DFSDM3_CR1_AWFSEL = 30;          // Analog watchdog fast mode select
    static const uint8_t DFSDM3_CR1_FAST = 29;            // Fast conversion mode selection for regular conversions
    static const uint8_t DFSDM3_CR1_RCH = 24;             // Regular channel selection (3 bits)
    static const uint8_t DFSDM3_CR1_RDMAEN = 21;          // DMA channel enabled to read data for the regular conversion
    static const uint8_t DFSDM3_CR1_RSYNC = 19;           // Launch regular conversion synchronously with DFSDM0
    static const uint8_t DFSDM3_CR1_RCONT = 18;           // Continuous mode selection for regular conversions
    static const uint8_t DFSDM3_CR1_RSWSTART = 17;        // Software start of a conversion on the regular channel
    static const uint8_t DFSDM3_CR1_JEXTEN = 13;          // Trigger enable and trigger edge selection for injected conversions (2 bits)
    static const uint8_t DFSDM3_CR1_JEXTSEL = 8;          // Trigger signal selection for launching injected conversions (3 bits)
    static const uint8_t DFSDM3_CR1_JDMAEN = 5;           // DMA channel enabled to read data for the injected channel group
    static const uint8_t DFSDM3_CR1_JSCAN = 4;            // Scanning conversion mode for injected conversions
    static const uint8_t DFSDM3_CR1_JSYNC = 3;            // Launch an injected conversion synchronously with the DFSDM0 JSWSTART trigger
    static const uint8_t DFSDM3_CR1_JSWSTART = 1;         // Start a conversion of the injected group of channels
    static const uint8_t DFSDM3_CR1_DFEN = 0;             // DFSDM enable
    static const uint32_t DFSDM3_CR1_RESET_VALUE = 0x0;

    static const uint8_t DFSDM3_CR2_AWDCH = 16;           // Analog watchdog channel selection (8 bits)
    static const uint8_t DFSDM3_CR2_EXCH = 8;             // Extremes detector channel selection (8 bits)
    static const uint8_t DFSDM3_CR2_CKABIE = 6;           // Clock absence interrupt enable
    static const uint8_t DFSDM3_CR2_SCDIE = 5;            // Short-circuit detector interrupt enable
    static const uint8_t DFSDM3_CR2_AWDIE = 4;            // Analog watchdog interrupt enable
    static const uint8_t DFSDM3_CR2_ROVRIE = 3;           // Regular data overrun interrupt enable
    static const uint8_t DFSDM3_CR2_JOVRIE = 2;           // Injected data overrun interrupt enable
    static const uint8_t DFSDM3_CR2_REOCIE = 1;           // Regular end of conversion interrupt enable
    static const uint8_t DFSDM3_CR2_JEOCIE = 0;           // Injected end of conversion interrupt enable
    static const uint32_t DFSDM3_CR2_RESET_VALUE = 0x0;

    static const uint8_t DFSDM3_ISR_SCDF = 24;            // short-circuit detector flag (8 bits)
    static const uint8_t DFSDM3_ISR_CKABF = 16;           // Clock absence flag (8 bits)
    static const uint8_t DFSDM3_ISR_RCIP = 14;            // Regular conversion in progress status
    static const uint8_t DFSDM3_ISR_JCIP = 13;            // Injected conversion in progress status
    static const uint8_t DFSDM3_ISR_AWDF = 4;             // Analog watchdog
    static const uint8_t DFSDM3_ISR_ROVRF = 3;            // Regular conversion overrun flag
    static const uint8_t DFSDM3_ISR_JOVRF = 2;            // Injected conversion overrun flag
    static const uint8_t DFSDM3_ISR_REOCF = 1;            // End of regular conversion flag
    static const uint8_t DFSDM3_ISR_JEOCF = 0;            // End of injected conversion flag
    static const uint32_t DFSDM3_ISR_RESET_VALUE = 0xff0000;

    static const uint8_t DFSDM3_ICR_CLRSCDF = 24;         // Clear the short-circuit detector flag (8 bits)
    static const uint8_t DFSDM3_ICR_CLRCKABF = 16;        // Clear the clock absence flag (8 bits)
    static const uint8_t DFSDM3_ICR_CLRROVRF = 3;         // Clear the regular conversion overrun flag
    static const uint8_t DFSDM3_ICR_CLRJOVRF = 2;         // Clear the injected conversion overrun flag
    static const uint32_t DFSDM3_ICR_RESET_VALUE = 0x0;

    static const uint8_t DFSDM3_JCHGR_JCHG = 0;             // Injected channel group selection (8 bits)
    static const uint32_t DFSDM3_JCHGR_RESET_VALUE = 0x1;

    static const uint8_t DFSDM3_FCR_FORD = 29;            // Sinc filter order (3 bits)
    static const uint8_t DFSDM3_FCR_FOSR = 16;            // Sinc filter oversampling ratio (decimation rate) (10 bits)
    static const uint8_t DFSDM3_FCR_IOSR = 0;             // Integrator oversampling ratio (averaging length) (8 bits)
    static const uint32_t DFSDM3_FCR_RESET_VALUE = 0x0;

    static const uint8_t DFSDM3_JDATAR_JDATA = 8;            // Injected group conversion data (24 bits)
    static const uint8_t DFSDM3_JDATAR_JDATACH = 0;          // Injected channel most recently converted (3 bits)
    static const uint32_t DFSDM3_JDATAR_RESET_VALUE = 0x0;

    static const uint8_t DFSDM3_RDATAR_RDATA = 8;            // Regular channel conversion data (24 bits)
    static const uint8_t DFSDM3_RDATAR_RPEND = 4;            // Regular channel pending data
    static const uint8_t DFSDM3_RDATAR_RDATACH = 0;          // Regular channel most recently converted (3 bits)
    static const uint32_t DFSDM3_RDATAR_RESET_VALUE = 0x0;

    static const uint8_t DFSDM3_AWHTR_AWHT = 8;             // Analog watchdog high threshold (24 bits)
    static const uint8_t DFSDM3_AWHTR_BKAWH = 0;            // Break signal assignment to analog watchdog high threshold event (4 bits)
    static const uint32_t DFSDM3_AWHTR_RESET_VALUE = 0x0;

    static const uint8_t DFSDM3_AWLTR_AWLT = 8;             // Analog watchdog low threshold (24 bits)
    static const uint8_t DFSDM3_AWLTR_BKAWL = 0;            // Break signal assignment to analog watchdog low threshold event (4 bits)
    static const uint32_t DFSDM3_AWLTR_RESET_VALUE = 0x0;

    static const uint8_t DFSDM3_AWSR_AWHTF = 8;            // Analog watchdog high threshold flag (8 bits)
    static const uint8_t DFSDM3_AWSR_AWLTF = 0;            // Analog watchdog low threshold flag (8 bits)
    static const uint32_t DFSDM3_AWSR_RESET_VALUE = 0x0;

    static const uint8_t DFSDM3_AWCFR_CLRAWHTF = 8;         // Clear the analog watchdog high threshold flag (8 bits)
    static const uint8_t DFSDM3_AWCFR_CLRAWLTF = 0;         // Clear the analog watchdog low threshold flag (8 bits)
    static const uint32_t DFSDM3_AWCFR_RESET_VALUE = 0x0;

    static const uint8_t DFSDM3_EXMAX_EXMAX = 8;            // Extremes detector maximum value (24 bits)
    static const uint8_t DFSDM3_EXMAX_EXMAXCH = 0;          // Extremes detector maximum data channel (3 bits)
    static const uint32_t DFSDM3_EXMAX_RESET_VALUE = 0x80000000;

    static const uint8_t DFSDM3_EXMIN_EXMIN = 8;            // EXMIN (24 bits)
    static const uint8_t DFSDM3_EXMIN_EXMINCH = 0;          // Extremes detector minimum data channel (3 bits)
    static const uint32_t DFSDM3_EXMIN_RESET_VALUE = 0x7fffff00;

    static const uint8_t DFSDM3_CNVTIMR_CNVCNT = 4;           // 28-bit timer counting conversion time t = CNVCNT[27:0] / fDFSDM_CKIN (28 bits)
    static const uint32_t DFSDM3_CNVTIMR_RESET_VALUE = 0x0;
};

static dfsdm_t& DFSDM = *reinterpret_cast<dfsdm_t*>(0x40016000);


////
//
//    Basic timers
//
////

struct tim6_t
{
    volatile uint32_t    CR1;                  // [Read-write] control register 1
    volatile uint32_t    CR2;                  // [Read-write] control register 2
    reserved_t<1>        _0;
    volatile uint32_t    DIER;                 // [Read-write] DMA/Interrupt enable register
    volatile uint32_t    SR;                   // [Read-write] status register
    volatile uint32_t    EGR;                  // [Write-only] event generation register
    reserved_t<3>        _1;
    volatile uint32_t    CNT;                  // counter
    volatile uint32_t    PSC;                  // [Read-write] prescaler
    volatile uint32_t    ARR;                  // [Read-write] auto-reload register

    static const uint8_t CR1_CEN = 0;              // Counter enable
    static const uint8_t CR1_UDIS = 1;             // Update disable
    static const uint8_t CR1_URS = 2;              // Update request source
    static const uint8_t CR1_OPM = 3;              // One-pulse mode
    static const uint8_t CR1_ARPE = 7;             // Auto-reload preload enable
    static const uint8_t CR1_UIFREMAP = 11;        // UIF status bit remapping
    static const uint32_t CR1_RESET_VALUE = 0x0;

    static const uint8_t CR2_MMS = 4;              // Master mode selection (3 bits)
    static const uint32_t CR2_RESET_VALUE = 0x0;

    static const uint8_t DIER_UDE = 8;              // Update DMA request enable
    static const uint8_t DIER_UIE = 0;              // Update interrupt enable
    static const uint32_t DIER_RESET_VALUE = 0x0;

    static const uint8_t SR_UIF = 0;              // Update interrupt flag
    static const uint32_t SR_RESET_VALUE = 0x0;

    static const uint8_t EGR_UG = 0;               // Update generation
    static const uint32_t EGR_RESET_VALUE = 0x0;

    static const uint8_t CNT_CNT = 0;              // Low counter value (16 bits), Read-write
    static const uint8_t CNT_UIFCPY = 31;          // UIF Copy, Read-only
    static const uint32_t CNT_RESET_VALUE = 0x0;

    static const uint8_t PSC_PSC = 0;              // Prescaler value (16 bits)
    static const uint32_t PSC_RESET_VALUE = 0x0;

    static const uint8_t ARR_ARR = 0;              // Low Auto-reload value (16 bits)
    static const uint32_t ARR_RESET_VALUE = 0x0;
};

static tim6_t& TIM6 = *reinterpret_cast<tim6_t*>(0x40001000);


////
//
//    Basic timers
//
////

struct tim7_t
{
    volatile uint32_t    CR1;                  // [Read-write] control register 1
    volatile uint32_t    CR2;                  // [Read-write] control register 2
    reserved_t<1>        _0;
    volatile uint32_t    DIER;                 // [Read-write] DMA/Interrupt enable register
    volatile uint32_t    SR;                   // [Read-write] status register
    volatile uint32_t    EGR;                  // [Write-only] event generation register
    reserved_t<3>        _1;
    volatile uint32_t    CNT;                  // counter
    volatile uint32_t    PSC;                  // [Read-write] prescaler
    volatile uint32_t    ARR;                  // [Read-write] auto-reload register

    static const uint8_t CR1_CEN = 0;              // Counter enable
    static const uint8_t CR1_UDIS = 1;             // Update disable
    static const uint8_t CR1_URS = 2;              // Update request source
    static const uint8_t CR1_OPM = 3;              // One-pulse mode
    static const uint8_t CR1_ARPE = 7;             // Auto-reload preload enable
    static const uint8_t CR1_UIFREMAP = 11;        // UIF status bit remapping
    static const uint32_t CR1_RESET_VALUE = 0x0;

    static const uint8_t CR2_MMS = 4;              // Master mode selection (3 bits)
    static const uint32_t CR2_RESET_VALUE = 0x0;

    static const uint8_t DIER_UDE = 8;              // Update DMA request enable
    static const uint8_t DIER_UIE = 0;              // Update interrupt enable
    static const uint32_t DIER_RESET_VALUE = 0x0;

    static const uint8_t SR_UIF = 0;              // Update interrupt flag
    static const uint32_t SR_RESET_VALUE = 0x0;

    static const uint8_t EGR_UG = 0;               // Update generation
    static const uint32_t EGR_RESET_VALUE = 0x0;

    static const uint8_t CNT_CNT = 0;              // Low counter value (16 bits), Read-write
    static const uint8_t CNT_UIFCPY = 31;          // UIF Copy, Read-only
    static const uint32_t CNT_RESET_VALUE = 0x0;

    static const uint8_t PSC_PSC = 0;              // Prescaler value (16 bits)
    static const uint32_t PSC_RESET_VALUE = 0x0;

    static const uint8_t ARR_ARR = 0;              // Low Auto-reload value (16 bits)
    static const uint32_t ARR_RESET_VALUE = 0x0;
};

static tim7_t& TIM7 = *reinterpret_cast<tim7_t*>(0x40001400);


////
//
//    General purpose timers
//
////

struct tim12_t
{
    volatile uint32_t    CR1;                  // [Read-write] control register 1
    reserved_t<1>        _0;
    volatile uint32_t    SMCR;                 // [Read-write] slave mode control register
    volatile uint32_t    DIER;                 // [Read-write] DMA/Interrupt enable register
    volatile uint32_t    SR;                   // [Read-write] status register
    volatile uint32_t    EGR;                  // [Write-only] event generation register
    volatile uint32_t    CCMR1;                // [Read-write] capture/compare mode register (output mode)
    reserved_t<1>        _1;
    volatile uint32_t    CCER;                 // [Read-write] capture/compare enable register
    volatile uint32_t    CNT;                  // [Read-write] counter
    volatile uint32_t    PSC;                  // [Read-write] prescaler
    volatile uint32_t    ARR;                  // [Read-write] auto-reload register
    reserved_t<1>        _2;
    volatile uint32_t    CCR1;                 // [Read-write] capture/compare register 1
    volatile uint32_t    CCR2;                 // [Read-write] capture/compare register 2

    static const uint8_t CR1_CKD = 8;              // Clock division (2 bits)
    static const uint8_t CR1_ARPE = 7;             // Auto-reload preload enable
    static const uint8_t CR1_OPM = 3;              // One-pulse mode
    static const uint8_t CR1_URS = 2;              // Update request source
    static const uint8_t CR1_UDIS = 1;             // Update disable
    static const uint8_t CR1_CEN = 0;              // Counter enable
    static const uint32_t CR1_RESET_VALUE = 0x0;

    static const uint8_t SMCR_MSM = 7;              // Master/Slave mode
    static const uint8_t SMCR_TS = 4;               // Trigger selection (3 bits)
    static const uint8_t SMCR_SMS = 0;              // Slave mode selection (3 bits)
    static const uint32_t SMCR_RESET_VALUE = 0x0;

    static const uint8_t DIER_TIE = 6;              // Trigger interrupt enable
    static const uint8_t DIER_CC2IE = 2;            // Capture/Compare 2 interrupt enable
    static const uint8_t DIER_CC1IE = 1;            // Capture/Compare 1 interrupt enable
    static const uint8_t DIER_UIE = 0;              // Update interrupt enable
    static const uint32_t DIER_RESET_VALUE = 0x0;

    static const uint8_t SR_CC2OF = 10;           // Capture/compare 2 overcapture flag
    static const uint8_t SR_CC1OF = 9;            // Capture/Compare 1 overcapture flag
    static const uint8_t SR_TIF = 6;              // Trigger interrupt flag
    static const uint8_t SR_CC2IF = 2;            // Capture/Compare 2 interrupt flag
    static const uint8_t SR_CC1IF = 1;            // Capture/compare 1 interrupt flag
    static const uint8_t SR_UIF = 0;              // Update interrupt flag
    static const uint32_t SR_RESET_VALUE = 0x0;

    static const uint8_t EGR_TG = 6;               // Trigger generation
    static const uint8_t EGR_CC2G = 2;             // Capture/compare 2 generation
    static const uint8_t EGR_CC1G = 1;             // Capture/compare 1 generation
    static const uint8_t EGR_UG = 0;               // Update generation
    static const uint32_t EGR_RESET_VALUE = 0x0;

    static const uint8_t CCMR1_CC1S = 0;             // Capture/Compare 1 selection (2 bits)
    static const uint8_t CCMR1_CC2S = 8;             // Capture/Compare 2 selection (2 bits)
    static const uint8_t CCMR1_IC1F = 4;             // Input capture 1 filter (3 bits)
    static const uint8_t CCMR1_IC1PSC = 2;           // Input capture 1 prescaler (2 bits)
    static const uint8_t CCMR1_IC2F = 12;            // Input capture 2 filter (4 bits)
    static const uint8_t CCMR1_IC2PSC = 10;          // Input capture 2 prescaler (2 bits)
    static const uint8_t CCMR1_OC1FE = 2;            // Output Compare 1 fast enable
    static const uint8_t CCMR1_OC1M = 4;             // Output Compare 1 mode (3 bits)
    static const uint8_t CCMR1_OC1PE = 3;            // Output Compare 1 preload enable
    static const uint8_t CCMR1_OC2FE = 10;           // Output Compare 2 fast enable
    static const uint8_t CCMR1_OC2M = 12;            // Output Compare 2 mode (3 bits)
    static const uint8_t CCMR1_OC2PE = 11;           // Output Compare 2 preload enable
    static const uint32_t CCMR1_RESET_VALUE = 0x0;

    static const uint8_t CCER_CC2NP = 7;            // Capture/Compare 2 output Polarity
    static const uint8_t CCER_CC2P = 5;             // Capture/Compare 2 output Polarity
    static const uint8_t CCER_CC2E = 4;             // Capture/Compare 2 output enable
    static const uint8_t CCER_CC1NP = 3;            // Capture/Compare 1 output Polarity
    static const uint8_t CCER_CC1P = 1;             // Capture/Compare 1 output Polarity
    static const uint8_t CCER_CC1E = 0;             // Capture/Compare 1 output enable
    static const uint32_t CCER_RESET_VALUE = 0x0;

    static const uint8_t CNT_CNT = 0;              // counter value (16 bits)
    static const uint32_t CNT_RESET_VALUE = 0x0;

    static const uint8_t PSC_PSC = 0;              // Prescaler value (16 bits)
    static const uint32_t PSC_RESET_VALUE = 0x0;

    static const uint8_t ARR_ARR = 0;              // Auto-reload value (16 bits)
    static const uint32_t ARR_RESET_VALUE = 0x0;

    static const uint8_t CCR1_CCR1 = 0;             // Capture/Compare 1 value (16 bits)
    static const uint32_t CCR1_RESET_VALUE = 0x0;

    static const uint8_t CCR2_CCR2 = 0;             // Capture/Compare 2 value (16 bits)
    static const uint32_t CCR2_RESET_VALUE = 0x0;
};

static tim12_t& TIM12 = *reinterpret_cast<tim12_t*>(0x40001800);


////
//
//    General purpose timers
//
////

struct tim13_t
{
    volatile uint32_t    CR1;                  // [Read-write] control register 1
    reserved_t<2>        _0;
    volatile uint32_t    DIER;                 // [Read-write] DMA/Interrupt enable register
    volatile uint32_t    SR;                   // [Read-write] status register
    volatile uint32_t    EGR;                  // [Write-only] event generation register
    volatile uint32_t    CCMR1;                // [Read-write] capture/compare mode register (output mode)
    reserved_t<1>        _1;
    volatile uint32_t    CCER;                 // [Read-write] capture/compare enable register
    volatile uint32_t    CNT;                  // [Read-write] counter
    volatile uint32_t    PSC;                  // [Read-write] prescaler
    volatile uint32_t    ARR;                  // [Read-write] auto-reload register
    reserved_t<1>        _2;
    volatile uint32_t    CCR1;                 // [Read-write] capture/compare register 1

    static const uint8_t CR1_CKD = 8;              // Clock division (2 bits)
    static const uint8_t CR1_ARPE = 7;             // Auto-reload preload enable
    static const uint8_t CR1_URS = 2;              // Update request source
    static const uint8_t CR1_UDIS = 1;             // Update disable
    static const uint8_t CR1_CEN = 0;              // Counter enable
    static const uint32_t CR1_RESET_VALUE = 0x0;

    static const uint8_t DIER_CC1IE = 1;            // Capture/Compare 1 interrupt enable
    static const uint8_t DIER_UIE = 0;              // Update interrupt enable
    static const uint32_t DIER_RESET_VALUE = 0x0;

    static const uint8_t SR_CC1OF = 9;            // Capture/Compare 1 overcapture flag
    static const uint8_t SR_CC1IF = 1;            // Capture/compare 1 interrupt flag
    static const uint8_t SR_UIF = 0;              // Update interrupt flag
    static const uint32_t SR_RESET_VALUE = 0x0;

    static const uint8_t EGR_CC1G = 1;             // Capture/compare 1 generation
    static const uint8_t EGR_UG = 0;               // Update generation
    static const uint32_t EGR_RESET_VALUE = 0x0;

    static const uint8_t CCMR1_CC1S = 0;             // Capture/Compare 1 selection (2 bits)
    static const uint8_t CCMR1_IC1F = 4;             // Input capture 1 filter (4 bits)
    static const uint8_t CCMR1_IC1PSC = 2;           // Input capture 1 prescaler (2 bits)
    static const uint8_t CCMR1_OC1FE = 2;            // Output compare 1 fast enable
    static const uint8_t CCMR1_OC1M = 4;             // Output Compare 1 mode (3 bits)
    static const uint8_t CCMR1_OC1PE = 3;            // Output Compare 1 preload enable
    static const uint32_t CCMR1_RESET_VALUE = 0x0;

    static const uint8_t CCER_CC1NP = 3;            // Capture/Compare 1 output Polarity
    static const uint8_t CCER_CC1P = 1;             // Capture/Compare 1 output Polarity
    static const uint8_t CCER_CC1E = 0;             // Capture/Compare 1 output enable
    static const uint32_t CCER_RESET_VALUE = 0x0;

    static const uint8_t CNT_CNT = 0;              // counter value (16 bits)
    static const uint32_t CNT_RESET_VALUE = 0x0;

    static const uint8_t PSC_PSC = 0;              // Prescaler value (16 bits)
    static const uint32_t PSC_RESET_VALUE = 0x0;

    static const uint8_t ARR_ARR = 0;              // Auto-reload value (16 bits)
    static const uint32_t ARR_RESET_VALUE = 0x0;

    static const uint8_t CCR1_CCR1 = 0;             // Capture/Compare 1 value (16 bits)
    static const uint32_t CCR1_RESET_VALUE = 0x0;
};

static tim13_t& TIM13 = *reinterpret_cast<tim13_t*>(0x40001c00);


////
//
//    General purpose timers
//
////

struct tim14_t
{
    volatile uint32_t    CR1;                  // [Read-write] control register 1
    reserved_t<2>        _0;
    volatile uint32_t    DIER;                 // [Read-write] DMA/Interrupt enable register
    volatile uint32_t    SR;                   // [Read-write] status register
    volatile uint32_t    EGR;                  // [Write-only] event generation register
    volatile uint32_t    CCMR1;                // [Read-write] capture/compare mode register (output mode)
    reserved_t<1>        _1;
    volatile uint32_t    CCER;                 // [Read-write] capture/compare enable register
    volatile uint32_t    CNT;                  // [Read-write] counter
    volatile uint32_t    PSC;                  // [Read-write] prescaler
    volatile uint32_t    ARR;                  // [Read-write] auto-reload register
    reserved_t<1>        _2;
    volatile uint32_t    CCR1;                 // [Read-write] capture/compare register 1

    static const uint8_t CR1_CKD = 8;              // Clock division (2 bits)
    static const uint8_t CR1_ARPE = 7;             // Auto-reload preload enable
    static const uint8_t CR1_URS = 2;              // Update request source
    static const uint8_t CR1_UDIS = 1;             // Update disable
    static const uint8_t CR1_CEN = 0;              // Counter enable
    static const uint32_t CR1_RESET_VALUE = 0x0;

    static const uint8_t DIER_CC1IE = 1;            // Capture/Compare 1 interrupt enable
    static const uint8_t DIER_UIE = 0;              // Update interrupt enable
    static const uint32_t DIER_RESET_VALUE = 0x0;

    static const uint8_t SR_CC1OF = 9;            // Capture/Compare 1 overcapture flag
    static const uint8_t SR_CC1IF = 1;            // Capture/compare 1 interrupt flag
    static const uint8_t SR_UIF = 0;              // Update interrupt flag
    static const uint32_t SR_RESET_VALUE = 0x0;

    static const uint8_t EGR_CC1G = 1;             // Capture/compare 1 generation
    static const uint8_t EGR_UG = 0;               // Update generation
    static const uint32_t EGR_RESET_VALUE = 0x0;

    static const uint8_t CCMR1_CC1S = 0;             // Capture/Compare 1 selection (2 bits)
    static const uint8_t CCMR1_IC1F = 4;             // Input capture 1 filter (4 bits)
    static const uint8_t CCMR1_IC1PSC = 2;           // Input capture 1 prescaler (2 bits)
    static const uint8_t CCMR1_OC1FE = 2;            // Output compare 1 fast enable
    static const uint8_t CCMR1_OC1M = 4;             // Output Compare 1 mode (3 bits)
    static const uint8_t CCMR1_OC1PE = 3;            // Output Compare 1 preload enable
    static const uint32_t CCMR1_RESET_VALUE = 0x0;

    static const uint8_t CCER_CC1NP = 3;            // Capture/Compare 1 output Polarity
    static const uint8_t CCER_CC1P = 1;             // Capture/Compare 1 output Polarity
    static const uint8_t CCER_CC1E = 0;             // Capture/Compare 1 output enable
    static const uint32_t CCER_RESET_VALUE = 0x0;

    static const uint8_t CNT_CNT = 0;              // counter value (16 bits)
    static const uint32_t CNT_RESET_VALUE = 0x0;

    static const uint8_t PSC_PSC = 0;              // Prescaler value (16 bits)
    static const uint32_t PSC_RESET_VALUE = 0x0;

    static const uint8_t ARR_ARR = 0;              // Auto-reload value (16 bits)
    static const uint32_t ARR_RESET_VALUE = 0x0;

    static const uint8_t CCR1_CCR1 = 0;             // Capture/Compare 1 value (16 bits)
    static const uint32_t CCR1_RESET_VALUE = 0x0;
};

static tim14_t& TIM14 = *reinterpret_cast<tim14_t*>(0x40002000);


////
//
//    Random number generator
//
////

struct rng_t
{
    volatile uint32_t    CR;                   // [Read-write] control register
    volatile uint32_t    SR;                   // status register
    volatile uint32_t    DR;                   // [Read-only] data register

    static const uint8_t CR_IE = 3;               // Interrupt enable
    static const uint8_t CR_RNGEN = 2;            // Random number generator enable
    static const uint32_t CR_RESET_VALUE = 0x0;

    static const uint8_t SR_SEIS = 6;             // Seed error interrupt status, Read-write
    static const uint8_t SR_CEIS = 5;             // Clock error interrupt status, Read-write
    static const uint8_t SR_SECS = 2;             // Seed error current status, Read-only
    static const uint8_t SR_CECS = 1;             // Clock error current status, Read-only
    static const uint8_t SR_DRDY = 0;             // Data ready, Read-only
    static const uint32_t SR_RESET_VALUE = 0x0;

    static const uint8_t DR_RNDATA = 0;           // Random data (32 bits)
    static const uint32_t DR_RESET_VALUE = 0x0;
};

static rng_t& RNG = *reinterpret_cast<rng_t*>(0x50060800);


////
//
//    Controller area network
//
////

struct can1_t
{
    volatile uint32_t    MCR;                  // [Read-write] master control register
    volatile uint32_t    MSR;                  // master status register
    volatile uint32_t    TSR;                  // transmit status register
    volatile uint32_t    RF0R;                 // receive FIFO 0 register
    volatile uint32_t    RF1R;                 // receive FIFO 1 register
    volatile uint32_t    IER;                  // [Read-write] interrupt enable register
    volatile uint32_t    ESR;                  // interrupt enable register
    volatile uint32_t    BTR;                  // [Read-write] bit timing register
    reserved_t<88>       _0;
    volatile uint32_t    TI0R;                 // [Read-write] TX mailbox identifier register
    volatile uint32_t    TDT0R;                // [Read-write] mailbox data length control and time stamp register
    volatile uint32_t    TDL0R;                // [Read-write] mailbox data low register
    volatile uint32_t    TDH0R;                // [Read-write] mailbox data high register
    volatile uint32_t    TI1R;                 // [Read-write] mailbox identifier register
    volatile uint32_t    TDT1R;                // [Read-write] mailbox data length control and time stamp register
    volatile uint32_t    TDL1R;                // [Read-write] mailbox data low register
    volatile uint32_t    TDH1R;                // [Read-write] mailbox data high register
    volatile uint32_t    TI2R;                 // [Read-write] mailbox identifier register
    volatile uint32_t    TDT2R;                // [Read-write] mailbox data length control and time stamp register
    volatile uint32_t    TDL2R;                // [Read-write] mailbox data low register
    volatile uint32_t    TDH2R;                // [Read-write] mailbox data high register
    volatile uint32_t    RI0R;                 // [Read-only] receive FIFO mailbox identifier register
    volatile uint32_t    RDT0R;                // [Read-only] mailbox data high register
    volatile uint32_t    RDL0R;                // [Read-only] mailbox data high register
    volatile uint32_t    RDH0R;                // [Read-only] receive FIFO mailbox data high register
    volatile uint32_t    RI1R;                 // [Read-only] mailbox data high register
    volatile uint32_t    RDT1R;                // [Read-only] mailbox data high register
    volatile uint32_t    RDL1R;                // [Read-only] mailbox data high register
    volatile uint32_t    RDH1R;                // [Read-only] mailbox data high register
    reserved_t<12>       _1;
    volatile uint32_t    FMR;                  // [Read-write] filter master register
    volatile uint32_t    FM1R;                 // [Read-write] filter mode register
    reserved_t<1>        _2;
    volatile uint32_t    FS1R;                 // [Read-write] filter scale register
    reserved_t<1>        _3;
    volatile uint32_t    FFA1R;                // [Read-write] filter FIFO assignment register
    reserved_t<1>        _4;
    volatile uint32_t    FA1R;                 // [Read-write] filter activation register
    reserved_t<8>        _5;
    volatile uint32_t    F0R1;                 // [Read-write] Filter bank 0 register 1
    volatile uint32_t    F0R2;                 // [Read-write] Filter bank 0 register 2
    volatile uint32_t    F1R1;                 // [Read-write] Filter bank 1 register 1
    volatile uint32_t    F1R2;                 // [Read-write] Filter bank 1 register 2
    volatile uint32_t    F2R1;                 // [Read-write] Filter bank 2 register 1
    volatile uint32_t    F2R2;                 // [Read-write] Filter bank 2 register 2
    volatile uint32_t    F3R1;                 // [Read-write] Filter bank 3 register 1
    volatile uint32_t    F3R2;                 // [Read-write] Filter bank 3 register 2
    volatile uint32_t    F4R1;                 // [Read-write] Filter bank 4 register 1
    volatile uint32_t    F4R2;                 // [Read-write] Filter bank 4 register 2
    volatile uint32_t    F5R1;                 // [Read-write] Filter bank 5 register 1
    volatile uint32_t    F5R2;                 // [Read-write] Filter bank 5 register 2
    volatile uint32_t    F6R1;                 // [Read-write] Filter bank 6 register 1
    volatile uint32_t    F6R2;                 // [Read-write] Filter bank 6 register 2
    volatile uint32_t    F7R1;                 // [Read-write] Filter bank 7 register 1
    volatile uint32_t    F7R2;                 // [Read-write] Filter bank 7 register 2
    volatile uint32_t    F8R1;                 // [Read-write] Filter bank 8 register 1
    volatile uint32_t    F8R2;                 // [Read-write] Filter bank 8 register 2
    volatile uint32_t    F9R1;                 // [Read-write] Filter bank 9 register 1
    volatile uint32_t    F9R2;                 // [Read-write] Filter bank 9 register 2
    volatile uint32_t    F10R1;                // [Read-write] Filter bank 10 register 1
    volatile uint32_t    F10R2;                // [Read-write] Filter bank 10 register 2
    volatile uint32_t    F11R1;                // [Read-write] Filter bank 11 register 1
    volatile uint32_t    F11R2;                // [Read-write] Filter bank 11 register 2
    volatile uint32_t    F12R1;                // [Read-write] Filter bank 4 register 1
    volatile uint32_t    F12R2;                // [Read-write] Filter bank 12 register 2
    volatile uint32_t    F13R1;                // [Read-write] Filter bank 13 register 1
    volatile uint32_t    F13R2;                // [Read-write] Filter bank 13 register 2
    volatile uint32_t    F14R1;                // [Read-write] Filter bank 14 register 1
    volatile uint32_t    F14R2;                // [Read-write] Filter bank 14 register 2
    volatile uint32_t    F15R1;                // [Read-write] Filter bank 15 register 1
    volatile uint32_t    F15R2;                // [Read-write] Filter bank 15 register 2
    volatile uint32_t    F16R1;                // [Read-write] Filter bank 16 register 1
    volatile uint32_t    F16R2;                // [Read-write] Filter bank 16 register 2
    volatile uint32_t    F17R1;                // [Read-write] Filter bank 17 register 1
    volatile uint32_t    F17R2;                // [Read-write] Filter bank 17 register 2
    volatile uint32_t    F18R1;                // [Read-write] Filter bank 18 register 1
    volatile uint32_t    F18R2;                // [Read-write] Filter bank 18 register 2
    volatile uint32_t    F19R1;                // [Read-write] Filter bank 19 register 1
    volatile uint32_t    F19R2;                // [Read-write] Filter bank 19 register 2
    volatile uint32_t    F20R1;                // [Read-write] Filter bank 20 register 1
    volatile uint32_t    F20R2;                // [Read-write] Filter bank 20 register 2
    volatile uint32_t    F21R1;                // [Read-write] Filter bank 21 register 1
    volatile uint32_t    F21R2;                // [Read-write] Filter bank 21 register 2
    volatile uint32_t    F22R1;                // [Read-write] Filter bank 22 register 1
    volatile uint32_t    F22R2;                // [Read-write] Filter bank 22 register 2
    volatile uint32_t    F23R1;                // [Read-write] Filter bank 23 register 1
    volatile uint32_t    F23R2;                // [Read-write] Filter bank 23 register 2
    volatile uint32_t    F24R1;                // [Read-write] Filter bank 24 register 1
    volatile uint32_t    F24R2;                // [Read-write] Filter bank 24 register 2
    volatile uint32_t    F25R1;                // [Read-write] Filter bank 25 register 1
    volatile uint32_t    F25R2;                // [Read-write] Filter bank 25 register 2
    volatile uint32_t    F26R1;                // [Read-write] Filter bank 26 register 1
    volatile uint32_t    F26R2;                // [Read-write] Filter bank 26 register 2
    volatile uint32_t    F27R1;                // [Read-write] Filter bank 27 register 1
    volatile uint32_t    F27R2;                // [Read-write] Filter bank 27 register 2

    static const uint8_t MCR_DBF = 16;             // DBF
    static const uint8_t MCR_RESET = 15;           // RESET
    static const uint8_t MCR_TTCM = 7;             // TTCM
    static const uint8_t MCR_ABOM = 6;             // ABOM
    static const uint8_t MCR_AWUM = 5;             // AWUM
    static const uint8_t MCR_NART = 4;             // NART
    static const uint8_t MCR_RFLM = 3;             // RFLM
    static const uint8_t MCR_TXFP = 2;             // TXFP
    static const uint8_t MCR_SLEEP = 1;            // SLEEP
    static const uint8_t MCR_INRQ = 0;             // INRQ
    static const uint32_t MCR_RESET_VALUE = 0x10002;

    static const uint8_t MSR_RX = 11;              // RX, Read-only
    static const uint8_t MSR_SAMP = 10;            // SAMP, Read-only
    static const uint8_t MSR_RXM = 9;              // RXM, Read-only
    static const uint8_t MSR_TXM = 8;              // TXM, Read-only
    static const uint8_t MSR_SLAKI = 4;            // SLAKI, Read-write
    static const uint8_t MSR_WKUI = 3;             // WKUI, Read-write
    static const uint8_t MSR_ERRI = 2;             // ERRI, Read-write
    static const uint8_t MSR_SLAK = 1;             // SLAK, Read-only
    static const uint8_t MSR_INAK = 0;             // INAK, Read-only
    static const uint32_t MSR_RESET_VALUE = 0xc02;

    static const uint8_t TSR_LOW2 = 31;            // Lowest priority flag for mailbox 2, Read-only
    static const uint8_t TSR_LOW1 = 30;            // Lowest priority flag for mailbox 1, Read-only
    static const uint8_t TSR_LOW0 = 29;            // Lowest priority flag for mailbox 0, Read-only
    static const uint8_t TSR_TME2 = 28;            // Lowest priority flag for mailbox 2, Read-only
    static const uint8_t TSR_TME1 = 27;            // Lowest priority flag for mailbox 1, Read-only
    static const uint8_t TSR_TME0 = 26;            // Lowest priority flag for mailbox 0, Read-only
    static const uint8_t TSR_CODE = 24;            // CODE (2 bits), Read-only
    static const uint8_t TSR_ABRQ2 = 23;           // ABRQ2, Read-write
    static const uint8_t TSR_TERR2 = 19;           // TERR2, Read-write
    static const uint8_t TSR_ALST2 = 18;           // ALST2, Read-write
    static const uint8_t TSR_TXOK2 = 17;           // TXOK2, Read-write
    static const uint8_t TSR_RQCP2 = 16;           // RQCP2, Read-write
    static const uint8_t TSR_ABRQ1 = 15;           // ABRQ1, Read-write
    static const uint8_t TSR_TERR1 = 11;           // TERR1, Read-write
    static const uint8_t TSR_ALST1 = 10;           // ALST1, Read-write
    static const uint8_t TSR_TXOK1 = 9;            // TXOK1, Read-write
    static const uint8_t TSR_RQCP1 = 8;            // RQCP1, Read-write
    static const uint8_t TSR_ABRQ0 = 7;            // ABRQ0, Read-write
    static const uint8_t TSR_TERR0 = 3;            // TERR0, Read-write
    static const uint8_t TSR_ALST0 = 2;            // ALST0, Read-write
    static const uint8_t TSR_TXOK0 = 1;            // TXOK0, Read-write
    static const uint8_t TSR_RQCP0 = 0;            // RQCP0, Read-write
    static const uint32_t TSR_RESET_VALUE = 0x1c000000;

    static const uint8_t RF0R_RFOM0 = 5;            // RFOM0, Read-write
    static const uint8_t RF0R_FOVR0 = 4;            // FOVR0, Read-write
    static const uint8_t RF0R_FULL0 = 3;            // FULL0, Read-write
    static const uint8_t RF0R_FMP0 = 0;             // FMP0 (2 bits), Read-only
    static const uint32_t RF0R_RESET_VALUE = 0x0;

    static const uint8_t RF1R_RFOM1 = 5;            // RFOM1, Read-write
    static const uint8_t RF1R_FOVR1 = 4;            // FOVR1, Read-write
    static const uint8_t RF1R_FULL1 = 3;            // FULL1, Read-write
    static const uint8_t RF1R_FMP1 = 0;             // FMP1 (2 bits), Read-only
    static const uint32_t RF1R_RESET_VALUE = 0x0;

    static const uint8_t IER_SLKIE = 17;           // SLKIE
    static const uint8_t IER_WKUIE = 16;           // WKUIE
    static const uint8_t IER_ERRIE = 15;           // ERRIE
    static const uint8_t IER_LECIE = 11;           // LECIE
    static const uint8_t IER_BOFIE = 10;           // BOFIE
    static const uint8_t IER_EPVIE = 9;            // EPVIE
    static const uint8_t IER_EWGIE = 8;            // EWGIE
    static const uint8_t IER_FOVIE1 = 6;           // FOVIE1
    static const uint8_t IER_FFIE1 = 5;            // FFIE1
    static const uint8_t IER_FMPIE1 = 4;           // FMPIE1
    static const uint8_t IER_FOVIE0 = 3;           // FOVIE0
    static const uint8_t IER_FFIE0 = 2;            // FFIE0
    static const uint8_t IER_FMPIE0 = 1;           // FMPIE0
    static const uint8_t IER_TMEIE = 0;            // TMEIE
    static const uint32_t IER_RESET_VALUE = 0x0;

    static const uint8_t ESR_REC = 24;             // REC (8 bits), Read-only
    static const uint8_t ESR_TEC = 16;             // TEC (8 bits), Read-only
    static const uint8_t ESR_LEC = 4;              // LEC (3 bits), Read-write
    static const uint8_t ESR_BOFF = 2;             // BOFF, Read-only
    static const uint8_t ESR_EPVF = 1;             // EPVF, Read-only
    static const uint8_t ESR_EWGF = 0;             // EWGF, Read-only
    static const uint32_t ESR_RESET_VALUE = 0x0;

    static const uint8_t BTR_SILM = 31;            // SILM
    static const uint8_t BTR_LBKM = 30;            // LBKM
    static const uint8_t BTR_SJW = 24;             // SJW (2 bits)
    static const uint8_t BTR_TS2 = 20;             // TS2 (3 bits)
    static const uint8_t BTR_TS1 = 16;             // TS1 (4 bits)
    static const uint8_t BTR_BRP = 0;              // BRP (10 bits)
    static const uint32_t BTR_RESET_VALUE = 0x0;

    static const uint8_t TI0R_STID = 21;            // STID (11 bits)
    static const uint8_t TI0R_EXID = 3;             // EXID (18 bits)
    static const uint8_t TI0R_IDE = 2;              // IDE
    static const uint8_t TI0R_RTR = 1;              // RTR
    static const uint8_t TI0R_TXRQ = 0;             // TXRQ
    static const uint32_t TI0R_RESET_VALUE = 0x0;

    static const uint8_t TDT0R_TIME = 16;            // TIME (16 bits)
    static const uint8_t TDT0R_TGT = 8;              // TGT
    static const uint8_t TDT0R_DLC = 0;              // DLC (4 bits)
    static const uint32_t TDT0R_RESET_VALUE = 0x0;

    static const uint8_t TDL0R_DATA3 = 24;           // DATA3 (8 bits)
    static const uint8_t TDL0R_DATA2 = 16;           // DATA2 (8 bits)
    static const uint8_t TDL0R_DATA1 = 8;            // DATA1 (8 bits)
    static const uint8_t TDL0R_DATA0 = 0;            // DATA0 (8 bits)
    static const uint32_t TDL0R_RESET_VALUE = 0x0;

    static const uint8_t TDH0R_DATA7 = 24;           // DATA7 (8 bits)
    static const uint8_t TDH0R_DATA6 = 16;           // DATA6 (8 bits)
    static const uint8_t TDH0R_DATA5 = 8;            // DATA5 (8 bits)
    static const uint8_t TDH0R_DATA4 = 0;            // DATA4 (8 bits)
    static const uint32_t TDH0R_RESET_VALUE = 0x0;

    static const uint8_t TI1R_STID = 21;            // STID (11 bits)
    static const uint8_t TI1R_EXID = 3;             // EXID (18 bits)
    static const uint8_t TI1R_IDE = 2;              // IDE
    static const uint8_t TI1R_RTR = 1;              // RTR
    static const uint8_t TI1R_TXRQ = 0;             // TXRQ
    static const uint32_t TI1R_RESET_VALUE = 0x0;

    static const uint8_t TDT1R_TIME = 16;            // TIME (16 bits)
    static const uint8_t TDT1R_TGT = 8;              // TGT
    static const uint8_t TDT1R_DLC = 0;              // DLC (4 bits)
    static const uint32_t TDT1R_RESET_VALUE = 0x0;

    static const uint8_t TDL1R_DATA3 = 24;           // DATA3 (8 bits)
    static const uint8_t TDL1R_DATA2 = 16;           // DATA2 (8 bits)
    static const uint8_t TDL1R_DATA1 = 8;            // DATA1 (8 bits)
    static const uint8_t TDL1R_DATA0 = 0;            // DATA0 (8 bits)
    static const uint32_t TDL1R_RESET_VALUE = 0x0;

    static const uint8_t TDH1R_DATA7 = 24;           // DATA7 (8 bits)
    static const uint8_t TDH1R_DATA6 = 16;           // DATA6 (8 bits)
    static const uint8_t TDH1R_DATA5 = 8;            // DATA5 (8 bits)
    static const uint8_t TDH1R_DATA4 = 0;            // DATA4 (8 bits)
    static const uint32_t TDH1R_RESET_VALUE = 0x0;

    static const uint8_t TI2R_STID = 21;            // STID (11 bits)
    static const uint8_t TI2R_EXID = 3;             // EXID (18 bits)
    static const uint8_t TI2R_IDE = 2;              // IDE
    static const uint8_t TI2R_RTR = 1;              // RTR
    static const uint8_t TI2R_TXRQ = 0;             // TXRQ
    static const uint32_t TI2R_RESET_VALUE = 0x0;

    static const uint8_t TDT2R_TIME = 16;            // TIME (16 bits)
    static const uint8_t TDT2R_TGT = 8;              // TGT
    static const uint8_t TDT2R_DLC = 0;              // DLC (4 bits)
    static const uint32_t TDT2R_RESET_VALUE = 0x0;

    static const uint8_t TDL2R_DATA3 = 24;           // DATA3 (8 bits)
    static const uint8_t TDL2R_DATA2 = 16;           // DATA2 (8 bits)
    static const uint8_t TDL2R_DATA1 = 8;            // DATA1 (8 bits)
    static const uint8_t TDL2R_DATA0 = 0;            // DATA0 (8 bits)
    static const uint32_t TDL2R_RESET_VALUE = 0x0;

    static const uint8_t TDH2R_DATA7 = 24;           // DATA7 (8 bits)
    static const uint8_t TDH2R_DATA6 = 16;           // DATA6 (8 bits)
    static const uint8_t TDH2R_DATA5 = 8;            // DATA5 (8 bits)
    static const uint8_t TDH2R_DATA4 = 0;            // DATA4 (8 bits)
    static const uint32_t TDH2R_RESET_VALUE = 0x0;

    static const uint8_t RI0R_STID = 21;            // STID (11 bits)
    static const uint8_t RI0R_EXID = 3;             // EXID (18 bits)
    static const uint8_t RI0R_IDE = 2;              // IDE
    static const uint8_t RI0R_RTR = 1;              // RTR
    static const uint32_t RI0R_RESET_VALUE = 0x0;

    static const uint8_t RDT0R_TIME = 16;            // TIME (16 bits)
    static const uint8_t RDT0R_FMI = 8;              // FMI (8 bits)
    static const uint8_t RDT0R_DLC = 0;              // DLC (4 bits)
    static const uint32_t RDT0R_RESET_VALUE = 0x0;

    static const uint8_t RDL0R_DATA3 = 24;           // DATA3 (8 bits)
    static const uint8_t RDL0R_DATA2 = 16;           // DATA2 (8 bits)
    static const uint8_t RDL0R_DATA1 = 8;            // DATA1 (8 bits)
    static const uint8_t RDL0R_DATA0 = 0;            // DATA0 (8 bits)
    static const uint32_t RDL0R_RESET_VALUE = 0x0;

    static const uint8_t RDH0R_DATA7 = 24;           // DATA7 (8 bits)
    static const uint8_t RDH0R_DATA6 = 16;           // DATA6 (8 bits)
    static const uint8_t RDH0R_DATA5 = 8;            // DATA5 (8 bits)
    static const uint8_t RDH0R_DATA4 = 0;            // DATA4 (8 bits)
    static const uint32_t RDH0R_RESET_VALUE = 0x0;

    static const uint8_t RI1R_STID = 21;            // STID (11 bits)
    static const uint8_t RI1R_EXID = 3;             // EXID (18 bits)
    static const uint8_t RI1R_IDE = 2;              // IDE
    static const uint8_t RI1R_RTR = 1;              // RTR
    static const uint32_t RI1R_RESET_VALUE = 0x0;

    static const uint8_t RDT1R_TIME = 16;            // TIME (16 bits)
    static const uint8_t RDT1R_FMI = 8;              // FMI (8 bits)
    static const uint8_t RDT1R_DLC = 0;              // DLC (4 bits)
    static const uint32_t RDT1R_RESET_VALUE = 0x0;

    static const uint8_t RDL1R_DATA3 = 24;           // DATA3 (8 bits)
    static const uint8_t RDL1R_DATA2 = 16;           // DATA2 (8 bits)
    static const uint8_t RDL1R_DATA1 = 8;            // DATA1 (8 bits)
    static const uint8_t RDL1R_DATA0 = 0;            // DATA0 (8 bits)
    static const uint32_t RDL1R_RESET_VALUE = 0x0;

    static const uint8_t RDH1R_DATA7 = 24;           // DATA7 (8 bits)
    static const uint8_t RDH1R_DATA6 = 16;           // DATA6 (8 bits)
    static const uint8_t RDH1R_DATA5 = 8;            // DATA5 (8 bits)
    static const uint8_t RDH1R_DATA4 = 0;            // DATA4 (8 bits)
    static const uint32_t RDH1R_RESET_VALUE = 0x0;

    static const uint8_t FMR_CAN2SB = 8;           // CAN2SB (6 bits)
    static const uint8_t FMR_FINIT = 0;            // FINIT
    static const uint32_t FMR_RESET_VALUE = 0x2a1c0e01;

    static const uint8_t FM1R_FBM0 = 0;             // Filter mode
    static const uint8_t FM1R_FBM1 = 1;             // Filter mode
    static const uint8_t FM1R_FBM2 = 2;             // Filter mode
    static const uint8_t FM1R_FBM3 = 3;             // Filter mode
    static const uint8_t FM1R_FBM4 = 4;             // Filter mode
    static const uint8_t FM1R_FBM5 = 5;             // Filter mode
    static const uint8_t FM1R_FBM6 = 6;             // Filter mode
    static const uint8_t FM1R_FBM7 = 7;             // Filter mode
    static const uint8_t FM1R_FBM8 = 8;             // Filter mode
    static const uint8_t FM1R_FBM9 = 9;             // Filter mode
    static const uint8_t FM1R_FBM10 = 10;           // Filter mode
    static const uint8_t FM1R_FBM11 = 11;           // Filter mode
    static const uint8_t FM1R_FBM12 = 12;           // Filter mode
    static const uint8_t FM1R_FBM13 = 13;           // Filter mode
    static const uint8_t FM1R_FBM14 = 14;           // Filter mode
    static const uint8_t FM1R_FBM15 = 15;           // Filter mode
    static const uint8_t FM1R_FBM16 = 16;           // Filter mode
    static const uint8_t FM1R_FBM17 = 17;           // Filter mode
    static const uint8_t FM1R_FBM18 = 18;           // Filter mode
    static const uint8_t FM1R_FBM19 = 19;           // Filter mode
    static const uint8_t FM1R_FBM20 = 20;           // Filter mode
    static const uint8_t FM1R_FBM21 = 21;           // Filter mode
    static const uint8_t FM1R_FBM22 = 22;           // Filter mode
    static const uint8_t FM1R_FBM23 = 23;           // Filter mode
    static const uint8_t FM1R_FBM24 = 24;           // Filter mode
    static const uint8_t FM1R_FBM25 = 25;           // Filter mode
    static const uint8_t FM1R_FBM26 = 26;           // Filter mode
    static const uint8_t FM1R_FBM27 = 27;           // Filter mode
    static const uint32_t FM1R_RESET_VALUE = 0x0;

    static const uint8_t FS1R_FSC0 = 0;             // Filter scale configuration
    static const uint8_t FS1R_FSC1 = 1;             // Filter scale configuration
    static const uint8_t FS1R_FSC2 = 2;             // Filter scale configuration
    static const uint8_t FS1R_FSC3 = 3;             // Filter scale configuration
    static const uint8_t FS1R_FSC4 = 4;             // Filter scale configuration
    static const uint8_t FS1R_FSC5 = 5;             // Filter scale configuration
    static const uint8_t FS1R_FSC6 = 6;             // Filter scale configuration
    static const uint8_t FS1R_FSC7 = 7;             // Filter scale configuration
    static const uint8_t FS1R_FSC8 = 8;             // Filter scale configuration
    static const uint8_t FS1R_FSC9 = 9;             // Filter scale configuration
    static const uint8_t FS1R_FSC10 = 10;           // Filter scale configuration
    static const uint8_t FS1R_FSC11 = 11;           // Filter scale configuration
    static const uint8_t FS1R_FSC12 = 12;           // Filter scale configuration
    static const uint8_t FS1R_FSC13 = 13;           // Filter scale configuration
    static const uint8_t FS1R_FSC14 = 14;           // Filter scale configuration
    static const uint8_t FS1R_FSC15 = 15;           // Filter scale configuration
    static const uint8_t FS1R_FSC16 = 16;           // Filter scale configuration
    static const uint8_t FS1R_FSC17 = 17;           // Filter scale configuration
    static const uint8_t FS1R_FSC18 = 18;           // Filter scale configuration
    static const uint8_t FS1R_FSC19 = 19;           // Filter scale configuration
    static const uint8_t FS1R_FSC20 = 20;           // Filter scale configuration
    static const uint8_t FS1R_FSC21 = 21;           // Filter scale configuration
    static const uint8_t FS1R_FSC22 = 22;           // Filter scale configuration
    static const uint8_t FS1R_FSC23 = 23;           // Filter scale configuration
    static const uint8_t FS1R_FSC24 = 24;           // Filter scale configuration
    static const uint8_t FS1R_FSC25 = 25;           // Filter scale configuration
    static const uint8_t FS1R_FSC26 = 26;           // Filter scale configuration
    static const uint8_t FS1R_FSC27 = 27;           // Filter scale configuration
    static const uint32_t FS1R_RESET_VALUE = 0x0;

    static const uint8_t FFA1R_FFA0 = 0;             // Filter FIFO assignment for filter 0
    static const uint8_t FFA1R_FFA1 = 1;             // Filter FIFO assignment for filter 1
    static const uint8_t FFA1R_FFA2 = 2;             // Filter FIFO assignment for filter 2
    static const uint8_t FFA1R_FFA3 = 3;             // Filter FIFO assignment for filter 3
    static const uint8_t FFA1R_FFA4 = 4;             // Filter FIFO assignment for filter 4
    static const uint8_t FFA1R_FFA5 = 5;             // Filter FIFO assignment for filter 5
    static const uint8_t FFA1R_FFA6 = 6;             // Filter FIFO assignment for filter 6
    static const uint8_t FFA1R_FFA7 = 7;             // Filter FIFO assignment for filter 7
    static const uint8_t FFA1R_FFA8 = 8;             // Filter FIFO assignment for filter 8
    static const uint8_t FFA1R_FFA9 = 9;             // Filter FIFO assignment for filter 9
    static const uint8_t FFA1R_FFA10 = 10;           // Filter FIFO assignment for filter 10
    static const uint8_t FFA1R_FFA11 = 11;           // Filter FIFO assignment for filter 11
    static const uint8_t FFA1R_FFA12 = 12;           // Filter FIFO assignment for filter 12
    static const uint8_t FFA1R_FFA13 = 13;           // Filter FIFO assignment for filter 13
    static const uint8_t FFA1R_FFA14 = 14;           // Filter FIFO assignment for filter 14
    static const uint8_t FFA1R_FFA15 = 15;           // Filter FIFO assignment for filter 15
    static const uint8_t FFA1R_FFA16 = 16;           // Filter FIFO assignment for filter 16
    static const uint8_t FFA1R_FFA17 = 17;           // Filter FIFO assignment for filter 17
    static const uint8_t FFA1R_FFA18 = 18;           // Filter FIFO assignment for filter 18
    static const uint8_t FFA1R_FFA19 = 19;           // Filter FIFO assignment for filter 19
    static const uint8_t FFA1R_FFA20 = 20;           // Filter FIFO assignment for filter 20
    static const uint8_t FFA1R_FFA21 = 21;           // Filter FIFO assignment for filter 21
    static const uint8_t FFA1R_FFA22 = 22;           // Filter FIFO assignment for filter 22
    static const uint8_t FFA1R_FFA23 = 23;           // Filter FIFO assignment for filter 23
    static const uint8_t FFA1R_FFA24 = 24;           // Filter FIFO assignment for filter 24
    static const uint8_t FFA1R_FFA25 = 25;           // Filter FIFO assignment for filter 25
    static const uint8_t FFA1R_FFA26 = 26;           // Filter FIFO assignment for filter 26
    static const uint8_t FFA1R_FFA27 = 27;           // Filter FIFO assignment for filter 27
    static const uint32_t FFA1R_RESET_VALUE = 0x0;

    static const uint8_t FA1R_FACT0 = 0;            // Filter active
    static const uint8_t FA1R_FACT1 = 1;            // Filter active
    static const uint8_t FA1R_FACT2 = 2;            // Filter active
    static const uint8_t FA1R_FACT3 = 3;            // Filter active
    static const uint8_t FA1R_FACT4 = 4;            // Filter active
    static const uint8_t FA1R_FACT5 = 5;            // Filter active
    static const uint8_t FA1R_FACT6 = 6;            // Filter active
    static const uint8_t FA1R_FACT7 = 7;            // Filter active
    static const uint8_t FA1R_FACT8 = 8;            // Filter active
    static const uint8_t FA1R_FACT9 = 9;            // Filter active
    static const uint8_t FA1R_FACT10 = 10;          // Filter active
    static const uint8_t FA1R_FACT11 = 11;          // Filter active
    static const uint8_t FA1R_FACT12 = 12;          // Filter active
    static const uint8_t FA1R_FACT13 = 13;          // Filter active
    static const uint8_t FA1R_FACT14 = 14;          // Filter active
    static const uint8_t FA1R_FACT15 = 15;          // Filter active
    static const uint8_t FA1R_FACT16 = 16;          // Filter active
    static const uint8_t FA1R_FACT17 = 17;          // Filter active
    static const uint8_t FA1R_FACT18 = 18;          // Filter active
    static const uint8_t FA1R_FACT19 = 19;          // Filter active
    static const uint8_t FA1R_FACT20 = 20;          // Filter active
    static const uint8_t FA1R_FACT21 = 21;          // Filter active
    static const uint8_t FA1R_FACT22 = 22;          // Filter active
    static const uint8_t FA1R_FACT23 = 23;          // Filter active
    static const uint8_t FA1R_FACT24 = 24;          // Filter active
    static const uint8_t FA1R_FACT25 = 25;          // Filter active
    static const uint8_t FA1R_FACT26 = 26;          // Filter active
    static const uint8_t FA1R_FACT27 = 27;          // Filter active
    static const uint32_t FA1R_RESET_VALUE = 0x0;

    static const uint8_t F0R1_FB0 = 0;              // Filter bits
    static const uint8_t F0R1_FB1 = 1;              // Filter bits
    static const uint8_t F0R1_FB2 = 2;              // Filter bits
    static const uint8_t F0R1_FB3 = 3;              // Filter bits
    static const uint8_t F0R1_FB4 = 4;              // Filter bits
    static const uint8_t F0R1_FB5 = 5;              // Filter bits
    static const uint8_t F0R1_FB6 = 6;              // Filter bits
    static const uint8_t F0R1_FB7 = 7;              // Filter bits
    static const uint8_t F0R1_FB8 = 8;              // Filter bits
    static const uint8_t F0R1_FB9 = 9;              // Filter bits
    static const uint8_t F0R1_FB10 = 10;            // Filter bits
    static const uint8_t F0R1_FB11 = 11;            // Filter bits
    static const uint8_t F0R1_FB12 = 12;            // Filter bits
    static const uint8_t F0R1_FB13 = 13;            // Filter bits
    static const uint8_t F0R1_FB14 = 14;            // Filter bits
    static const uint8_t F0R1_FB15 = 15;            // Filter bits
    static const uint8_t F0R1_FB16 = 16;            // Filter bits
    static const uint8_t F0R1_FB17 = 17;            // Filter bits
    static const uint8_t F0R1_FB18 = 18;            // Filter bits
    static const uint8_t F0R1_FB19 = 19;            // Filter bits
    static const uint8_t F0R1_FB20 = 20;            // Filter bits
    static const uint8_t F0R1_FB21 = 21;            // Filter bits
    static const uint8_t F0R1_FB22 = 22;            // Filter bits
    static const uint8_t F0R1_FB23 = 23;            // Filter bits
    static const uint8_t F0R1_FB24 = 24;            // Filter bits
    static const uint8_t F0R1_FB25 = 25;            // Filter bits
    static const uint8_t F0R1_FB26 = 26;            // Filter bits
    static const uint8_t F0R1_FB27 = 27;            // Filter bits
    static const uint8_t F0R1_FB28 = 28;            // Filter bits
    static const uint8_t F0R1_FB29 = 29;            // Filter bits
    static const uint8_t F0R1_FB30 = 30;            // Filter bits
    static const uint8_t F0R1_FB31 = 31;            // Filter bits
    static const uint32_t F0R1_RESET_VALUE = 0x0;

    static const uint8_t F0R2_FB0 = 0;              // Filter bits
    static const uint8_t F0R2_FB1 = 1;              // Filter bits
    static const uint8_t F0R2_FB2 = 2;              // Filter bits
    static const uint8_t F0R2_FB3 = 3;              // Filter bits
    static const uint8_t F0R2_FB4 = 4;              // Filter bits
    static const uint8_t F0R2_FB5 = 5;              // Filter bits
    static const uint8_t F0R2_FB6 = 6;              // Filter bits
    static const uint8_t F0R2_FB7 = 7;              // Filter bits
    static const uint8_t F0R2_FB8 = 8;              // Filter bits
    static const uint8_t F0R2_FB9 = 9;              // Filter bits
    static const uint8_t F0R2_FB10 = 10;            // Filter bits
    static const uint8_t F0R2_FB11 = 11;            // Filter bits
    static const uint8_t F0R2_FB12 = 12;            // Filter bits
    static const uint8_t F0R2_FB13 = 13;            // Filter bits
    static const uint8_t F0R2_FB14 = 14;            // Filter bits
    static const uint8_t F0R2_FB15 = 15;            // Filter bits
    static const uint8_t F0R2_FB16 = 16;            // Filter bits
    static const uint8_t F0R2_FB17 = 17;            // Filter bits
    static const uint8_t F0R2_FB18 = 18;            // Filter bits
    static const uint8_t F0R2_FB19 = 19;            // Filter bits
    static const uint8_t F0R2_FB20 = 20;            // Filter bits
    static const uint8_t F0R2_FB21 = 21;            // Filter bits
    static const uint8_t F0R2_FB22 = 22;            // Filter bits
    static const uint8_t F0R2_FB23 = 23;            // Filter bits
    static const uint8_t F0R2_FB24 = 24;            // Filter bits
    static const uint8_t F0R2_FB25 = 25;            // Filter bits
    static const uint8_t F0R2_FB26 = 26;            // Filter bits
    static const uint8_t F0R2_FB27 = 27;            // Filter bits
    static const uint8_t F0R2_FB28 = 28;            // Filter bits
    static const uint8_t F0R2_FB29 = 29;            // Filter bits
    static const uint8_t F0R2_FB30 = 30;            // Filter bits
    static const uint8_t F0R2_FB31 = 31;            // Filter bits
    static const uint32_t F0R2_RESET_VALUE = 0x0;

    static const uint8_t F1R1_FB0 = 0;              // Filter bits
    static const uint8_t F1R1_FB1 = 1;              // Filter bits
    static const uint8_t F1R1_FB2 = 2;              // Filter bits
    static const uint8_t F1R1_FB3 = 3;              // Filter bits
    static const uint8_t F1R1_FB4 = 4;              // Filter bits
    static const uint8_t F1R1_FB5 = 5;              // Filter bits
    static const uint8_t F1R1_FB6 = 6;              // Filter bits
    static const uint8_t F1R1_FB7 = 7;              // Filter bits
    static const uint8_t F1R1_FB8 = 8;              // Filter bits
    static const uint8_t F1R1_FB9 = 9;              // Filter bits
    static const uint8_t F1R1_FB10 = 10;            // Filter bits
    static const uint8_t F1R1_FB11 = 11;            // Filter bits
    static const uint8_t F1R1_FB12 = 12;            // Filter bits
    static const uint8_t F1R1_FB13 = 13;            // Filter bits
    static const uint8_t F1R1_FB14 = 14;            // Filter bits
    static const uint8_t F1R1_FB15 = 15;            // Filter bits
    static const uint8_t F1R1_FB16 = 16;            // Filter bits
    static const uint8_t F1R1_FB17 = 17;            // Filter bits
    static const uint8_t F1R1_FB18 = 18;            // Filter bits
    static const uint8_t F1R1_FB19 = 19;            // Filter bits
    static const uint8_t F1R1_FB20 = 20;            // Filter bits
    static const uint8_t F1R1_FB21 = 21;            // Filter bits
    static const uint8_t F1R1_FB22 = 22;            // Filter bits
    static const uint8_t F1R1_FB23 = 23;            // Filter bits
    static const uint8_t F1R1_FB24 = 24;            // Filter bits
    static const uint8_t F1R1_FB25 = 25;            // Filter bits
    static const uint8_t F1R1_FB26 = 26;            // Filter bits
    static const uint8_t F1R1_FB27 = 27;            // Filter bits
    static const uint8_t F1R1_FB28 = 28;            // Filter bits
    static const uint8_t F1R1_FB29 = 29;            // Filter bits
    static const uint8_t F1R1_FB30 = 30;            // Filter bits
    static const uint8_t F1R1_FB31 = 31;            // Filter bits
    static const uint32_t F1R1_RESET_VALUE = 0x0;

    static const uint8_t F1R2_FB0 = 0;              // Filter bits
    static const uint8_t F1R2_FB1 = 1;              // Filter bits
    static const uint8_t F1R2_FB2 = 2;              // Filter bits
    static const uint8_t F1R2_FB3 = 3;              // Filter bits
    static const uint8_t F1R2_FB4 = 4;              // Filter bits
    static const uint8_t F1R2_FB5 = 5;              // Filter bits
    static const uint8_t F1R2_FB6 = 6;              // Filter bits
    static const uint8_t F1R2_FB7 = 7;              // Filter bits
    static const uint8_t F1R2_FB8 = 8;              // Filter bits
    static const uint8_t F1R2_FB9 = 9;              // Filter bits
    static const uint8_t F1R2_FB10 = 10;            // Filter bits
    static const uint8_t F1R2_FB11 = 11;            // Filter bits
    static const uint8_t F1R2_FB12 = 12;            // Filter bits
    static const uint8_t F1R2_FB13 = 13;            // Filter bits
    static const uint8_t F1R2_FB14 = 14;            // Filter bits
    static const uint8_t F1R2_FB15 = 15;            // Filter bits
    static const uint8_t F1R2_FB16 = 16;            // Filter bits
    static const uint8_t F1R2_FB17 = 17;            // Filter bits
    static const uint8_t F1R2_FB18 = 18;            // Filter bits
    static const uint8_t F1R2_FB19 = 19;            // Filter bits
    static const uint8_t F1R2_FB20 = 20;            // Filter bits
    static const uint8_t F1R2_FB21 = 21;            // Filter bits
    static const uint8_t F1R2_FB22 = 22;            // Filter bits
    static const uint8_t F1R2_FB23 = 23;            // Filter bits
    static const uint8_t F1R2_FB24 = 24;            // Filter bits
    static const uint8_t F1R2_FB25 = 25;            // Filter bits
    static const uint8_t F1R2_FB26 = 26;            // Filter bits
    static const uint8_t F1R2_FB27 = 27;            // Filter bits
    static const uint8_t F1R2_FB28 = 28;            // Filter bits
    static const uint8_t F1R2_FB29 = 29;            // Filter bits
    static const uint8_t F1R2_FB30 = 30;            // Filter bits
    static const uint8_t F1R2_FB31 = 31;            // Filter bits
    static const uint32_t F1R2_RESET_VALUE = 0x0;

    static const uint8_t F2R1_FB0 = 0;              // Filter bits
    static const uint8_t F2R1_FB1 = 1;              // Filter bits
    static const uint8_t F2R1_FB2 = 2;              // Filter bits
    static const uint8_t F2R1_FB3 = 3;              // Filter bits
    static const uint8_t F2R1_FB4 = 4;              // Filter bits
    static const uint8_t F2R1_FB5 = 5;              // Filter bits
    static const uint8_t F2R1_FB6 = 6;              // Filter bits
    static const uint8_t F2R1_FB7 = 7;              // Filter bits
    static const uint8_t F2R1_FB8 = 8;              // Filter bits
    static const uint8_t F2R1_FB9 = 9;              // Filter bits
    static const uint8_t F2R1_FB10 = 10;            // Filter bits
    static const uint8_t F2R1_FB11 = 11;            // Filter bits
    static const uint8_t F2R1_FB12 = 12;            // Filter bits
    static const uint8_t F2R1_FB13 = 13;            // Filter bits
    static const uint8_t F2R1_FB14 = 14;            // Filter bits
    static const uint8_t F2R1_FB15 = 15;            // Filter bits
    static const uint8_t F2R1_FB16 = 16;            // Filter bits
    static const uint8_t F2R1_FB17 = 17;            // Filter bits
    static const uint8_t F2R1_FB18 = 18;            // Filter bits
    static const uint8_t F2R1_FB19 = 19;            // Filter bits
    static const uint8_t F2R1_FB20 = 20;            // Filter bits
    static const uint8_t F2R1_FB21 = 21;            // Filter bits
    static const uint8_t F2R1_FB22 = 22;            // Filter bits
    static const uint8_t F2R1_FB23 = 23;            // Filter bits
    static const uint8_t F2R1_FB24 = 24;            // Filter bits
    static const uint8_t F2R1_FB25 = 25;            // Filter bits
    static const uint8_t F2R1_FB26 = 26;            // Filter bits
    static const uint8_t F2R1_FB27 = 27;            // Filter bits
    static const uint8_t F2R1_FB28 = 28;            // Filter bits
    static const uint8_t F2R1_FB29 = 29;            // Filter bits
    static const uint8_t F2R1_FB30 = 30;            // Filter bits
    static const uint8_t F2R1_FB31 = 31;            // Filter bits
    static const uint32_t F2R1_RESET_VALUE = 0x0;

    static const uint8_t F2R2_FB0 = 0;              // Filter bits
    static const uint8_t F2R2_FB1 = 1;              // Filter bits
    static const uint8_t F2R2_FB2 = 2;              // Filter bits
    static const uint8_t F2R2_FB3 = 3;              // Filter bits
    static const uint8_t F2R2_FB4 = 4;              // Filter bits
    static const uint8_t F2R2_FB5 = 5;              // Filter bits
    static const uint8_t F2R2_FB6 = 6;              // Filter bits
    static const uint8_t F2R2_FB7 = 7;              // Filter bits
    static const uint8_t F2R2_FB8 = 8;              // Filter bits
    static const uint8_t F2R2_FB9 = 9;              // Filter bits
    static const uint8_t F2R2_FB10 = 10;            // Filter bits
    static const uint8_t F2R2_FB11 = 11;            // Filter bits
    static const uint8_t F2R2_FB12 = 12;            // Filter bits
    static const uint8_t F2R2_FB13 = 13;            // Filter bits
    static const uint8_t F2R2_FB14 = 14;            // Filter bits
    static const uint8_t F2R2_FB15 = 15;            // Filter bits
    static const uint8_t F2R2_FB16 = 16;            // Filter bits
    static const uint8_t F2R2_FB17 = 17;            // Filter bits
    static const uint8_t F2R2_FB18 = 18;            // Filter bits
    static const uint8_t F2R2_FB19 = 19;            // Filter bits
    static const uint8_t F2R2_FB20 = 20;            // Filter bits
    static const uint8_t F2R2_FB21 = 21;            // Filter bits
    static const uint8_t F2R2_FB22 = 22;            // Filter bits
    static const uint8_t F2R2_FB23 = 23;            // Filter bits
    static const uint8_t F2R2_FB24 = 24;            // Filter bits
    static const uint8_t F2R2_FB25 = 25;            // Filter bits
    static const uint8_t F2R2_FB26 = 26;            // Filter bits
    static const uint8_t F2R2_FB27 = 27;            // Filter bits
    static const uint8_t F2R2_FB28 = 28;            // Filter bits
    static const uint8_t F2R2_FB29 = 29;            // Filter bits
    static const uint8_t F2R2_FB30 = 30;            // Filter bits
    static const uint8_t F2R2_FB31 = 31;            // Filter bits
    static const uint32_t F2R2_RESET_VALUE = 0x0;

    static const uint8_t F3R1_FB0 = 0;              // Filter bits
    static const uint8_t F3R1_FB1 = 1;              // Filter bits
    static const uint8_t F3R1_FB2 = 2;              // Filter bits
    static const uint8_t F3R1_FB3 = 3;              // Filter bits
    static const uint8_t F3R1_FB4 = 4;              // Filter bits
    static const uint8_t F3R1_FB5 = 5;              // Filter bits
    static const uint8_t F3R1_FB6 = 6;              // Filter bits
    static const uint8_t F3R1_FB7 = 7;              // Filter bits
    static const uint8_t F3R1_FB8 = 8;              // Filter bits
    static const uint8_t F3R1_FB9 = 9;              // Filter bits
    static const uint8_t F3R1_FB10 = 10;            // Filter bits
    static const uint8_t F3R1_FB11 = 11;            // Filter bits
    static const uint8_t F3R1_FB12 = 12;            // Filter bits
    static const uint8_t F3R1_FB13 = 13;            // Filter bits
    static const uint8_t F3R1_FB14 = 14;            // Filter bits
    static const uint8_t F3R1_FB15 = 15;            // Filter bits
    static const uint8_t F3R1_FB16 = 16;            // Filter bits
    static const uint8_t F3R1_FB17 = 17;            // Filter bits
    static const uint8_t F3R1_FB18 = 18;            // Filter bits
    static const uint8_t F3R1_FB19 = 19;            // Filter bits
    static const uint8_t F3R1_FB20 = 20;            // Filter bits
    static const uint8_t F3R1_FB21 = 21;            // Filter bits
    static const uint8_t F3R1_FB22 = 22;            // Filter bits
    static const uint8_t F3R1_FB23 = 23;            // Filter bits
    static const uint8_t F3R1_FB24 = 24;            // Filter bits
    static const uint8_t F3R1_FB25 = 25;            // Filter bits
    static const uint8_t F3R1_FB26 = 26;            // Filter bits
    static const uint8_t F3R1_FB27 = 27;            // Filter bits
    static const uint8_t F3R1_FB28 = 28;            // Filter bits
    static const uint8_t F3R1_FB29 = 29;            // Filter bits
    static const uint8_t F3R1_FB30 = 30;            // Filter bits
    static const uint8_t F3R1_FB31 = 31;            // Filter bits
    static const uint32_t F3R1_RESET_VALUE = 0x0;

    static const uint8_t F3R2_FB0 = 0;              // Filter bits
    static const uint8_t F3R2_FB1 = 1;              // Filter bits
    static const uint8_t F3R2_FB2 = 2;              // Filter bits
    static const uint8_t F3R2_FB3 = 3;              // Filter bits
    static const uint8_t F3R2_FB4 = 4;              // Filter bits
    static const uint8_t F3R2_FB5 = 5;              // Filter bits
    static const uint8_t F3R2_FB6 = 6;              // Filter bits
    static const uint8_t F3R2_FB7 = 7;              // Filter bits
    static const uint8_t F3R2_FB8 = 8;              // Filter bits
    static const uint8_t F3R2_FB9 = 9;              // Filter bits
    static const uint8_t F3R2_FB10 = 10;            // Filter bits
    static const uint8_t F3R2_FB11 = 11;            // Filter bits
    static const uint8_t F3R2_FB12 = 12;            // Filter bits
    static const uint8_t F3R2_FB13 = 13;            // Filter bits
    static const uint8_t F3R2_FB14 = 14;            // Filter bits
    static const uint8_t F3R2_FB15 = 15;            // Filter bits
    static const uint8_t F3R2_FB16 = 16;            // Filter bits
    static const uint8_t F3R2_FB17 = 17;            // Filter bits
    static const uint8_t F3R2_FB18 = 18;            // Filter bits
    static const uint8_t F3R2_FB19 = 19;            // Filter bits
    static const uint8_t F3R2_FB20 = 20;            // Filter bits
    static const uint8_t F3R2_FB21 = 21;            // Filter bits
    static const uint8_t F3R2_FB22 = 22;            // Filter bits
    static const uint8_t F3R2_FB23 = 23;            // Filter bits
    static const uint8_t F3R2_FB24 = 24;            // Filter bits
    static const uint8_t F3R2_FB25 = 25;            // Filter bits
    static const uint8_t F3R2_FB26 = 26;            // Filter bits
    static const uint8_t F3R2_FB27 = 27;            // Filter bits
    static const uint8_t F3R2_FB28 = 28;            // Filter bits
    static const uint8_t F3R2_FB29 = 29;            // Filter bits
    static const uint8_t F3R2_FB30 = 30;            // Filter bits
    static const uint8_t F3R2_FB31 = 31;            // Filter bits
    static const uint32_t F3R2_RESET_VALUE = 0x0;

    static const uint8_t F4R1_FB0 = 0;              // Filter bits
    static const uint8_t F4R1_FB1 = 1;              // Filter bits
    static const uint8_t F4R1_FB2 = 2;              // Filter bits
    static const uint8_t F4R1_FB3 = 3;              // Filter bits
    static const uint8_t F4R1_FB4 = 4;              // Filter bits
    static const uint8_t F4R1_FB5 = 5;              // Filter bits
    static const uint8_t F4R1_FB6 = 6;              // Filter bits
    static const uint8_t F4R1_FB7 = 7;              // Filter bits
    static const uint8_t F4R1_FB8 = 8;              // Filter bits
    static const uint8_t F4R1_FB9 = 9;              // Filter bits
    static const uint8_t F4R1_FB10 = 10;            // Filter bits
    static const uint8_t F4R1_FB11 = 11;            // Filter bits
    static const uint8_t F4R1_FB12 = 12;            // Filter bits
    static const uint8_t F4R1_FB13 = 13;            // Filter bits
    static const uint8_t F4R1_FB14 = 14;            // Filter bits
    static const uint8_t F4R1_FB15 = 15;            // Filter bits
    static const uint8_t F4R1_FB16 = 16;            // Filter bits
    static const uint8_t F4R1_FB17 = 17;            // Filter bits
    static const uint8_t F4R1_FB18 = 18;            // Filter bits
    static const uint8_t F4R1_FB19 = 19;            // Filter bits
    static const uint8_t F4R1_FB20 = 20;            // Filter bits
    static const uint8_t F4R1_FB21 = 21;            // Filter bits
    static const uint8_t F4R1_FB22 = 22;            // Filter bits
    static const uint8_t F4R1_FB23 = 23;            // Filter bits
    static const uint8_t F4R1_FB24 = 24;            // Filter bits
    static const uint8_t F4R1_FB25 = 25;            // Filter bits
    static const uint8_t F4R1_FB26 = 26;            // Filter bits
    static const uint8_t F4R1_FB27 = 27;            // Filter bits
    static const uint8_t F4R1_FB28 = 28;            // Filter bits
    static const uint8_t F4R1_FB29 = 29;            // Filter bits
    static const uint8_t F4R1_FB30 = 30;            // Filter bits
    static const uint8_t F4R1_FB31 = 31;            // Filter bits
    static const uint32_t F4R1_RESET_VALUE = 0x0;

    static const uint8_t F4R2_FB0 = 0;              // Filter bits
    static const uint8_t F4R2_FB1 = 1;              // Filter bits
    static const uint8_t F4R2_FB2 = 2;              // Filter bits
    static const uint8_t F4R2_FB3 = 3;              // Filter bits
    static const uint8_t F4R2_FB4 = 4;              // Filter bits
    static const uint8_t F4R2_FB5 = 5;              // Filter bits
    static const uint8_t F4R2_FB6 = 6;              // Filter bits
    static const uint8_t F4R2_FB7 = 7;              // Filter bits
    static const uint8_t F4R2_FB8 = 8;              // Filter bits
    static const uint8_t F4R2_FB9 = 9;              // Filter bits
    static const uint8_t F4R2_FB10 = 10;            // Filter bits
    static const uint8_t F4R2_FB11 = 11;            // Filter bits
    static const uint8_t F4R2_FB12 = 12;            // Filter bits
    static const uint8_t F4R2_FB13 = 13;            // Filter bits
    static const uint8_t F4R2_FB14 = 14;            // Filter bits
    static const uint8_t F4R2_FB15 = 15;            // Filter bits
    static const uint8_t F4R2_FB16 = 16;            // Filter bits
    static const uint8_t F4R2_FB17 = 17;            // Filter bits
    static const uint8_t F4R2_FB18 = 18;            // Filter bits
    static const uint8_t F4R2_FB19 = 19;            // Filter bits
    static const uint8_t F4R2_FB20 = 20;            // Filter bits
    static const uint8_t F4R2_FB21 = 21;            // Filter bits
    static const uint8_t F4R2_FB22 = 22;            // Filter bits
    static const uint8_t F4R2_FB23 = 23;            // Filter bits
    static const uint8_t F4R2_FB24 = 24;            // Filter bits
    static const uint8_t F4R2_FB25 = 25;            // Filter bits
    static const uint8_t F4R2_FB26 = 26;            // Filter bits
    static const uint8_t F4R2_FB27 = 27;            // Filter bits
    static const uint8_t F4R2_FB28 = 28;            // Filter bits
    static const uint8_t F4R2_FB29 = 29;            // Filter bits
    static const uint8_t F4R2_FB30 = 30;            // Filter bits
    static const uint8_t F4R2_FB31 = 31;            // Filter bits
    static const uint32_t F4R2_RESET_VALUE = 0x0;

    static const uint8_t F5R1_FB0 = 0;              // Filter bits
    static const uint8_t F5R1_FB1 = 1;              // Filter bits
    static const uint8_t F5R1_FB2 = 2;              // Filter bits
    static const uint8_t F5R1_FB3 = 3;              // Filter bits
    static const uint8_t F5R1_FB4 = 4;              // Filter bits
    static const uint8_t F5R1_FB5 = 5;              // Filter bits
    static const uint8_t F5R1_FB6 = 6;              // Filter bits
    static const uint8_t F5R1_FB7 = 7;              // Filter bits
    static const uint8_t F5R1_FB8 = 8;              // Filter bits
    static const uint8_t F5R1_FB9 = 9;              // Filter bits
    static const uint8_t F5R1_FB10 = 10;            // Filter bits
    static const uint8_t F5R1_FB11 = 11;            // Filter bits
    static const uint8_t F5R1_FB12 = 12;            // Filter bits
    static const uint8_t F5R1_FB13 = 13;            // Filter bits
    static const uint8_t F5R1_FB14 = 14;            // Filter bits
    static const uint8_t F5R1_FB15 = 15;            // Filter bits
    static const uint8_t F5R1_FB16 = 16;            // Filter bits
    static const uint8_t F5R1_FB17 = 17;            // Filter bits
    static const uint8_t F5R1_FB18 = 18;            // Filter bits
    static const uint8_t F5R1_FB19 = 19;            // Filter bits
    static const uint8_t F5R1_FB20 = 20;            // Filter bits
    static const uint8_t F5R1_FB21 = 21;            // Filter bits
    static const uint8_t F5R1_FB22 = 22;            // Filter bits
    static const uint8_t F5R1_FB23 = 23;            // Filter bits
    static const uint8_t F5R1_FB24 = 24;            // Filter bits
    static const uint8_t F5R1_FB25 = 25;            // Filter bits
    static const uint8_t F5R1_FB26 = 26;            // Filter bits
    static const uint8_t F5R1_FB27 = 27;            // Filter bits
    static const uint8_t F5R1_FB28 = 28;            // Filter bits
    static const uint8_t F5R1_FB29 = 29;            // Filter bits
    static const uint8_t F5R1_FB30 = 30;            // Filter bits
    static const uint8_t F5R1_FB31 = 31;            // Filter bits
    static const uint32_t F5R1_RESET_VALUE = 0x0;

    static const uint8_t F5R2_FB0 = 0;              // Filter bits
    static const uint8_t F5R2_FB1 = 1;              // Filter bits
    static const uint8_t F5R2_FB2 = 2;              // Filter bits
    static const uint8_t F5R2_FB3 = 3;              // Filter bits
    static const uint8_t F5R2_FB4 = 4;              // Filter bits
    static const uint8_t F5R2_FB5 = 5;              // Filter bits
    static const uint8_t F5R2_FB6 = 6;              // Filter bits
    static const uint8_t F5R2_FB7 = 7;              // Filter bits
    static const uint8_t F5R2_FB8 = 8;              // Filter bits
    static const uint8_t F5R2_FB9 = 9;              // Filter bits
    static const uint8_t F5R2_FB10 = 10;            // Filter bits
    static const uint8_t F5R2_FB11 = 11;            // Filter bits
    static const uint8_t F5R2_FB12 = 12;            // Filter bits
    static const uint8_t F5R2_FB13 = 13;            // Filter bits
    static const uint8_t F5R2_FB14 = 14;            // Filter bits
    static const uint8_t F5R2_FB15 = 15;            // Filter bits
    static const uint8_t F5R2_FB16 = 16;            // Filter bits
    static const uint8_t F5R2_FB17 = 17;            // Filter bits
    static const uint8_t F5R2_FB18 = 18;            // Filter bits
    static const uint8_t F5R2_FB19 = 19;            // Filter bits
    static const uint8_t F5R2_FB20 = 20;            // Filter bits
    static const uint8_t F5R2_FB21 = 21;            // Filter bits
    static const uint8_t F5R2_FB22 = 22;            // Filter bits
    static const uint8_t F5R2_FB23 = 23;            // Filter bits
    static const uint8_t F5R2_FB24 = 24;            // Filter bits
    static const uint8_t F5R2_FB25 = 25;            // Filter bits
    static const uint8_t F5R2_FB26 = 26;            // Filter bits
    static const uint8_t F5R2_FB27 = 27;            // Filter bits
    static const uint8_t F5R2_FB28 = 28;            // Filter bits
    static const uint8_t F5R2_FB29 = 29;            // Filter bits
    static const uint8_t F5R2_FB30 = 30;            // Filter bits
    static const uint8_t F5R2_FB31 = 31;            // Filter bits
    static const uint32_t F5R2_RESET_VALUE = 0x0;

    static const uint8_t F6R1_FB0 = 0;              // Filter bits
    static const uint8_t F6R1_FB1 = 1;              // Filter bits
    static const uint8_t F6R1_FB2 = 2;              // Filter bits
    static const uint8_t F6R1_FB3 = 3;              // Filter bits
    static const uint8_t F6R1_FB4 = 4;              // Filter bits
    static const uint8_t F6R1_FB5 = 5;              // Filter bits
    static const uint8_t F6R1_FB6 = 6;              // Filter bits
    static const uint8_t F6R1_FB7 = 7;              // Filter bits
    static const uint8_t F6R1_FB8 = 8;              // Filter bits
    static const uint8_t F6R1_FB9 = 9;              // Filter bits
    static const uint8_t F6R1_FB10 = 10;            // Filter bits
    static const uint8_t F6R1_FB11 = 11;            // Filter bits
    static const uint8_t F6R1_FB12 = 12;            // Filter bits
    static const uint8_t F6R1_FB13 = 13;            // Filter bits
    static const uint8_t F6R1_FB14 = 14;            // Filter bits
    static const uint8_t F6R1_FB15 = 15;            // Filter bits
    static const uint8_t F6R1_FB16 = 16;            // Filter bits
    static const uint8_t F6R1_FB17 = 17;            // Filter bits
    static const uint8_t F6R1_FB18 = 18;            // Filter bits
    static const uint8_t F6R1_FB19 = 19;            // Filter bits
    static const uint8_t F6R1_FB20 = 20;            // Filter bits
    static const uint8_t F6R1_FB21 = 21;            // Filter bits
    static const uint8_t F6R1_FB22 = 22;            // Filter bits
    static const uint8_t F6R1_FB23 = 23;            // Filter bits
    static const uint8_t F6R1_FB24 = 24;            // Filter bits
    static const uint8_t F6R1_FB25 = 25;            // Filter bits
    static const uint8_t F6R1_FB26 = 26;            // Filter bits
    static const uint8_t F6R1_FB27 = 27;            // Filter bits
    static const uint8_t F6R1_FB28 = 28;            // Filter bits
    static const uint8_t F6R1_FB29 = 29;            // Filter bits
    static const uint8_t F6R1_FB30 = 30;            // Filter bits
    static const uint8_t F6R1_FB31 = 31;            // Filter bits
    static const uint32_t F6R1_RESET_VALUE = 0x0;

    static const uint8_t F6R2_FB0 = 0;              // Filter bits
    static const uint8_t F6R2_FB1 = 1;              // Filter bits
    static const uint8_t F6R2_FB2 = 2;              // Filter bits
    static const uint8_t F6R2_FB3 = 3;              // Filter bits
    static const uint8_t F6R2_FB4 = 4;              // Filter bits
    static const uint8_t F6R2_FB5 = 5;              // Filter bits
    static const uint8_t F6R2_FB6 = 6;              // Filter bits
    static const uint8_t F6R2_FB7 = 7;              // Filter bits
    static const uint8_t F6R2_FB8 = 8;              // Filter bits
    static const uint8_t F6R2_FB9 = 9;              // Filter bits
    static const uint8_t F6R2_FB10 = 10;            // Filter bits
    static const uint8_t F6R2_FB11 = 11;            // Filter bits
    static const uint8_t F6R2_FB12 = 12;            // Filter bits
    static const uint8_t F6R2_FB13 = 13;            // Filter bits
    static const uint8_t F6R2_FB14 = 14;            // Filter bits
    static const uint8_t F6R2_FB15 = 15;            // Filter bits
    static const uint8_t F6R2_FB16 = 16;            // Filter bits
    static const uint8_t F6R2_FB17 = 17;            // Filter bits
    static const uint8_t F6R2_FB18 = 18;            // Filter bits
    static const uint8_t F6R2_FB19 = 19;            // Filter bits
    static const uint8_t F6R2_FB20 = 20;            // Filter bits
    static const uint8_t F6R2_FB21 = 21;            // Filter bits
    static const uint8_t F6R2_FB22 = 22;            // Filter bits
    static const uint8_t F6R2_FB23 = 23;            // Filter bits
    static const uint8_t F6R2_FB24 = 24;            // Filter bits
    static const uint8_t F6R2_FB25 = 25;            // Filter bits
    static const uint8_t F6R2_FB26 = 26;            // Filter bits
    static const uint8_t F6R2_FB27 = 27;            // Filter bits
    static const uint8_t F6R2_FB28 = 28;            // Filter bits
    static const uint8_t F6R2_FB29 = 29;            // Filter bits
    static const uint8_t F6R2_FB30 = 30;            // Filter bits
    static const uint8_t F6R2_FB31 = 31;            // Filter bits
    static const uint32_t F6R2_RESET_VALUE = 0x0;

    static const uint8_t F7R1_FB0 = 0;              // Filter bits
    static const uint8_t F7R1_FB1 = 1;              // Filter bits
    static const uint8_t F7R1_FB2 = 2;              // Filter bits
    static const uint8_t F7R1_FB3 = 3;              // Filter bits
    static const uint8_t F7R1_FB4 = 4;              // Filter bits
    static const uint8_t F7R1_FB5 = 5;              // Filter bits
    static const uint8_t F7R1_FB6 = 6;              // Filter bits
    static const uint8_t F7R1_FB7 = 7;              // Filter bits
    static const uint8_t F7R1_FB8 = 8;              // Filter bits
    static const uint8_t F7R1_FB9 = 9;              // Filter bits
    static const uint8_t F7R1_FB10 = 10;            // Filter bits
    static const uint8_t F7R1_FB11 = 11;            // Filter bits
    static const uint8_t F7R1_FB12 = 12;            // Filter bits
    static const uint8_t F7R1_FB13 = 13;            // Filter bits
    static const uint8_t F7R1_FB14 = 14;            // Filter bits
    static const uint8_t F7R1_FB15 = 15;            // Filter bits
    static const uint8_t F7R1_FB16 = 16;            // Filter bits
    static const uint8_t F7R1_FB17 = 17;            // Filter bits
    static const uint8_t F7R1_FB18 = 18;            // Filter bits
    static const uint8_t F7R1_FB19 = 19;            // Filter bits
    static const uint8_t F7R1_FB20 = 20;            // Filter bits
    static const uint8_t F7R1_FB21 = 21;            // Filter bits
    static const uint8_t F7R1_FB22 = 22;            // Filter bits
    static const uint8_t F7R1_FB23 = 23;            // Filter bits
    static const uint8_t F7R1_FB24 = 24;            // Filter bits
    static const uint8_t F7R1_FB25 = 25;            // Filter bits
    static const uint8_t F7R1_FB26 = 26;            // Filter bits
    static const uint8_t F7R1_FB27 = 27;            // Filter bits
    static const uint8_t F7R1_FB28 = 28;            // Filter bits
    static const uint8_t F7R1_FB29 = 29;            // Filter bits
    static const uint8_t F7R1_FB30 = 30;            // Filter bits
    static const uint8_t F7R1_FB31 = 31;            // Filter bits
    static const uint32_t F7R1_RESET_VALUE = 0x0;

    static const uint8_t F7R2_FB0 = 0;              // Filter bits
    static const uint8_t F7R2_FB1 = 1;              // Filter bits
    static const uint8_t F7R2_FB2 = 2;              // Filter bits
    static const uint8_t F7R2_FB3 = 3;              // Filter bits
    static const uint8_t F7R2_FB4 = 4;              // Filter bits
    static const uint8_t F7R2_FB5 = 5;              // Filter bits
    static const uint8_t F7R2_FB6 = 6;              // Filter bits
    static const uint8_t F7R2_FB7 = 7;              // Filter bits
    static const uint8_t F7R2_FB8 = 8;              // Filter bits
    static const uint8_t F7R2_FB9 = 9;              // Filter bits
    static const uint8_t F7R2_FB10 = 10;            // Filter bits
    static const uint8_t F7R2_FB11 = 11;            // Filter bits
    static const uint8_t F7R2_FB12 = 12;            // Filter bits
    static const uint8_t F7R2_FB13 = 13;            // Filter bits
    static const uint8_t F7R2_FB14 = 14;            // Filter bits
    static const uint8_t F7R2_FB15 = 15;            // Filter bits
    static const uint8_t F7R2_FB16 = 16;            // Filter bits
    static const uint8_t F7R2_FB17 = 17;            // Filter bits
    static const uint8_t F7R2_FB18 = 18;            // Filter bits
    static const uint8_t F7R2_FB19 = 19;            // Filter bits
    static const uint8_t F7R2_FB20 = 20;            // Filter bits
    static const uint8_t F7R2_FB21 = 21;            // Filter bits
    static const uint8_t F7R2_FB22 = 22;            // Filter bits
    static const uint8_t F7R2_FB23 = 23;            // Filter bits
    static const uint8_t F7R2_FB24 = 24;            // Filter bits
    static const uint8_t F7R2_FB25 = 25;            // Filter bits
    static const uint8_t F7R2_FB26 = 26;            // Filter bits
    static const uint8_t F7R2_FB27 = 27;            // Filter bits
    static const uint8_t F7R2_FB28 = 28;            // Filter bits
    static const uint8_t F7R2_FB29 = 29;            // Filter bits
    static const uint8_t F7R2_FB30 = 30;            // Filter bits
    static const uint8_t F7R2_FB31 = 31;            // Filter bits
    static const uint32_t F7R2_RESET_VALUE = 0x0;

    static const uint8_t F8R1_FB0 = 0;              // Filter bits
    static const uint8_t F8R1_FB1 = 1;              // Filter bits
    static const uint8_t F8R1_FB2 = 2;              // Filter bits
    static const uint8_t F8R1_FB3 = 3;              // Filter bits
    static const uint8_t F8R1_FB4 = 4;              // Filter bits
    static const uint8_t F8R1_FB5 = 5;              // Filter bits
    static const uint8_t F8R1_FB6 = 6;              // Filter bits
    static const uint8_t F8R1_FB7 = 7;              // Filter bits
    static const uint8_t F8R1_FB8 = 8;              // Filter bits
    static const uint8_t F8R1_FB9 = 9;              // Filter bits
    static const uint8_t F8R1_FB10 = 10;            // Filter bits
    static const uint8_t F8R1_FB11 = 11;            // Filter bits
    static const uint8_t F8R1_FB12 = 12;            // Filter bits
    static const uint8_t F8R1_FB13 = 13;            // Filter bits
    static const uint8_t F8R1_FB14 = 14;            // Filter bits
    static const uint8_t F8R1_FB15 = 15;            // Filter bits
    static const uint8_t F8R1_FB16 = 16;            // Filter bits
    static const uint8_t F8R1_FB17 = 17;            // Filter bits
    static const uint8_t F8R1_FB18 = 18;            // Filter bits
    static const uint8_t F8R1_FB19 = 19;            // Filter bits
    static const uint8_t F8R1_FB20 = 20;            // Filter bits
    static const uint8_t F8R1_FB21 = 21;            // Filter bits
    static const uint8_t F8R1_FB22 = 22;            // Filter bits
    static const uint8_t F8R1_FB23 = 23;            // Filter bits
    static const uint8_t F8R1_FB24 = 24;            // Filter bits
    static const uint8_t F8R1_FB25 = 25;            // Filter bits
    static const uint8_t F8R1_FB26 = 26;            // Filter bits
    static const uint8_t F8R1_FB27 = 27;            // Filter bits
    static const uint8_t F8R1_FB28 = 28;            // Filter bits
    static const uint8_t F8R1_FB29 = 29;            // Filter bits
    static const uint8_t F8R1_FB30 = 30;            // Filter bits
    static const uint8_t F8R1_FB31 = 31;            // Filter bits
    static const uint32_t F8R1_RESET_VALUE = 0x0;

    static const uint8_t F8R2_FB0 = 0;              // Filter bits
    static const uint8_t F8R2_FB1 = 1;              // Filter bits
    static const uint8_t F8R2_FB2 = 2;              // Filter bits
    static const uint8_t F8R2_FB3 = 3;              // Filter bits
    static const uint8_t F8R2_FB4 = 4;              // Filter bits
    static const uint8_t F8R2_FB5 = 5;              // Filter bits
    static const uint8_t F8R2_FB6 = 6;              // Filter bits
    static const uint8_t F8R2_FB7 = 7;              // Filter bits
    static const uint8_t F8R2_FB8 = 8;              // Filter bits
    static const uint8_t F8R2_FB9 = 9;              // Filter bits
    static const uint8_t F8R2_FB10 = 10;            // Filter bits
    static const uint8_t F8R2_FB11 = 11;            // Filter bits
    static const uint8_t F8R2_FB12 = 12;            // Filter bits
    static const uint8_t F8R2_FB13 = 13;            // Filter bits
    static const uint8_t F8R2_FB14 = 14;            // Filter bits
    static const uint8_t F8R2_FB15 = 15;            // Filter bits
    static const uint8_t F8R2_FB16 = 16;            // Filter bits
    static const uint8_t F8R2_FB17 = 17;            // Filter bits
    static const uint8_t F8R2_FB18 = 18;            // Filter bits
    static const uint8_t F8R2_FB19 = 19;            // Filter bits
    static const uint8_t F8R2_FB20 = 20;            // Filter bits
    static const uint8_t F8R2_FB21 = 21;            // Filter bits
    static const uint8_t F8R2_FB22 = 22;            // Filter bits
    static const uint8_t F8R2_FB23 = 23;            // Filter bits
    static const uint8_t F8R2_FB24 = 24;            // Filter bits
    static const uint8_t F8R2_FB25 = 25;            // Filter bits
    static const uint8_t F8R2_FB26 = 26;            // Filter bits
    static const uint8_t F8R2_FB27 = 27;            // Filter bits
    static const uint8_t F8R2_FB28 = 28;            // Filter bits
    static const uint8_t F8R2_FB29 = 29;            // Filter bits
    static const uint8_t F8R2_FB30 = 30;            // Filter bits
    static const uint8_t F8R2_FB31 = 31;            // Filter bits
    static const uint32_t F8R2_RESET_VALUE = 0x0;

    static const uint8_t F9R1_FB0 = 0;              // Filter bits
    static const uint8_t F9R1_FB1 = 1;              // Filter bits
    static const uint8_t F9R1_FB2 = 2;              // Filter bits
    static const uint8_t F9R1_FB3 = 3;              // Filter bits
    static const uint8_t F9R1_FB4 = 4;              // Filter bits
    static const uint8_t F9R1_FB5 = 5;              // Filter bits
    static const uint8_t F9R1_FB6 = 6;              // Filter bits
    static const uint8_t F9R1_FB7 = 7;              // Filter bits
    static const uint8_t F9R1_FB8 = 8;              // Filter bits
    static const uint8_t F9R1_FB9 = 9;              // Filter bits
    static const uint8_t F9R1_FB10 = 10;            // Filter bits
    static const uint8_t F9R1_FB11 = 11;            // Filter bits
    static const uint8_t F9R1_FB12 = 12;            // Filter bits
    static const uint8_t F9R1_FB13 = 13;            // Filter bits
    static const uint8_t F9R1_FB14 = 14;            // Filter bits
    static const uint8_t F9R1_FB15 = 15;            // Filter bits
    static const uint8_t F9R1_FB16 = 16;            // Filter bits
    static const uint8_t F9R1_FB17 = 17;            // Filter bits
    static const uint8_t F9R1_FB18 = 18;            // Filter bits
    static const uint8_t F9R1_FB19 = 19;            // Filter bits
    static const uint8_t F9R1_FB20 = 20;            // Filter bits
    static const uint8_t F9R1_FB21 = 21;            // Filter bits
    static const uint8_t F9R1_FB22 = 22;            // Filter bits
    static const uint8_t F9R1_FB23 = 23;            // Filter bits
    static const uint8_t F9R1_FB24 = 24;            // Filter bits
    static const uint8_t F9R1_FB25 = 25;            // Filter bits
    static const uint8_t F9R1_FB26 = 26;            // Filter bits
    static const uint8_t F9R1_FB27 = 27;            // Filter bits
    static const uint8_t F9R1_FB28 = 28;            // Filter bits
    static const uint8_t F9R1_FB29 = 29;            // Filter bits
    static const uint8_t F9R1_FB30 = 30;            // Filter bits
    static const uint8_t F9R1_FB31 = 31;            // Filter bits
    static const uint32_t F9R1_RESET_VALUE = 0x0;

    static const uint8_t F9R2_FB0 = 0;              // Filter bits
    static const uint8_t F9R2_FB1 = 1;              // Filter bits
    static const uint8_t F9R2_FB2 = 2;              // Filter bits
    static const uint8_t F9R2_FB3 = 3;              // Filter bits
    static const uint8_t F9R2_FB4 = 4;              // Filter bits
    static const uint8_t F9R2_FB5 = 5;              // Filter bits
    static const uint8_t F9R2_FB6 = 6;              // Filter bits
    static const uint8_t F9R2_FB7 = 7;              // Filter bits
    static const uint8_t F9R2_FB8 = 8;              // Filter bits
    static const uint8_t F9R2_FB9 = 9;              // Filter bits
    static const uint8_t F9R2_FB10 = 10;            // Filter bits
    static const uint8_t F9R2_FB11 = 11;            // Filter bits
    static const uint8_t F9R2_FB12 = 12;            // Filter bits
    static const uint8_t F9R2_FB13 = 13;            // Filter bits
    static const uint8_t F9R2_FB14 = 14;            // Filter bits
    static const uint8_t F9R2_FB15 = 15;            // Filter bits
    static const uint8_t F9R2_FB16 = 16;            // Filter bits
    static const uint8_t F9R2_FB17 = 17;            // Filter bits
    static const uint8_t F9R2_FB18 = 18;            // Filter bits
    static const uint8_t F9R2_FB19 = 19;            // Filter bits
    static const uint8_t F9R2_FB20 = 20;            // Filter bits
    static const uint8_t F9R2_FB21 = 21;            // Filter bits
    static const uint8_t F9R2_FB22 = 22;            // Filter bits
    static const uint8_t F9R2_FB23 = 23;            // Filter bits
    static const uint8_t F9R2_FB24 = 24;            // Filter bits
    static const uint8_t F9R2_FB25 = 25;            // Filter bits
    static const uint8_t F9R2_FB26 = 26;            // Filter bits
    static const uint8_t F9R2_FB27 = 27;            // Filter bits
    static const uint8_t F9R2_FB28 = 28;            // Filter bits
    static const uint8_t F9R2_FB29 = 29;            // Filter bits
    static const uint8_t F9R2_FB30 = 30;            // Filter bits
    static const uint8_t F9R2_FB31 = 31;            // Filter bits
    static const uint32_t F9R2_RESET_VALUE = 0x0;

    static const uint8_t F10R1_FB0 = 0;              // Filter bits
    static const uint8_t F10R1_FB1 = 1;              // Filter bits
    static const uint8_t F10R1_FB2 = 2;              // Filter bits
    static const uint8_t F10R1_FB3 = 3;              // Filter bits
    static const uint8_t F10R1_FB4 = 4;              // Filter bits
    static const uint8_t F10R1_FB5 = 5;              // Filter bits
    static const uint8_t F10R1_FB6 = 6;              // Filter bits
    static const uint8_t F10R1_FB7 = 7;              // Filter bits
    static const uint8_t F10R1_FB8 = 8;              // Filter bits
    static const uint8_t F10R1_FB9 = 9;              // Filter bits
    static const uint8_t F10R1_FB10 = 10;            // Filter bits
    static const uint8_t F10R1_FB11 = 11;            // Filter bits
    static const uint8_t F10R1_FB12 = 12;            // Filter bits
    static const uint8_t F10R1_FB13 = 13;            // Filter bits
    static const uint8_t F10R1_FB14 = 14;            // Filter bits
    static const uint8_t F10R1_FB15 = 15;            // Filter bits
    static const uint8_t F10R1_FB16 = 16;            // Filter bits
    static const uint8_t F10R1_FB17 = 17;            // Filter bits
    static const uint8_t F10R1_FB18 = 18;            // Filter bits
    static const uint8_t F10R1_FB19 = 19;            // Filter bits
    static const uint8_t F10R1_FB20 = 20;            // Filter bits
    static const uint8_t F10R1_FB21 = 21;            // Filter bits
    static const uint8_t F10R1_FB22 = 22;            // Filter bits
    static const uint8_t F10R1_FB23 = 23;            // Filter bits
    static const uint8_t F10R1_FB24 = 24;            // Filter bits
    static const uint8_t F10R1_FB25 = 25;            // Filter bits
    static const uint8_t F10R1_FB26 = 26;            // Filter bits
    static const uint8_t F10R1_FB27 = 27;            // Filter bits
    static const uint8_t F10R1_FB28 = 28;            // Filter bits
    static const uint8_t F10R1_FB29 = 29;            // Filter bits
    static const uint8_t F10R1_FB30 = 30;            // Filter bits
    static const uint8_t F10R1_FB31 = 31;            // Filter bits
    static const uint32_t F10R1_RESET_VALUE = 0x0;

    static const uint8_t F10R2_FB0 = 0;              // Filter bits
    static const uint8_t F10R2_FB1 = 1;              // Filter bits
    static const uint8_t F10R2_FB2 = 2;              // Filter bits
    static const uint8_t F10R2_FB3 = 3;              // Filter bits
    static const uint8_t F10R2_FB4 = 4;              // Filter bits
    static const uint8_t F10R2_FB5 = 5;              // Filter bits
    static const uint8_t F10R2_FB6 = 6;              // Filter bits
    static const uint8_t F10R2_FB7 = 7;              // Filter bits
    static const uint8_t F10R2_FB8 = 8;              // Filter bits
    static const uint8_t F10R2_FB9 = 9;              // Filter bits
    static const uint8_t F10R2_FB10 = 10;            // Filter bits
    static const uint8_t F10R2_FB11 = 11;            // Filter bits
    static const uint8_t F10R2_FB12 = 12;            // Filter bits
    static const uint8_t F10R2_FB13 = 13;            // Filter bits
    static const uint8_t F10R2_FB14 = 14;            // Filter bits
    static const uint8_t F10R2_FB15 = 15;            // Filter bits
    static const uint8_t F10R2_FB16 = 16;            // Filter bits
    static const uint8_t F10R2_FB17 = 17;            // Filter bits
    static const uint8_t F10R2_FB18 = 18;            // Filter bits
    static const uint8_t F10R2_FB19 = 19;            // Filter bits
    static const uint8_t F10R2_FB20 = 20;            // Filter bits
    static const uint8_t F10R2_FB21 = 21;            // Filter bits
    static const uint8_t F10R2_FB22 = 22;            // Filter bits
    static const uint8_t F10R2_FB23 = 23;            // Filter bits
    static const uint8_t F10R2_FB24 = 24;            // Filter bits
    static const uint8_t F10R2_FB25 = 25;            // Filter bits
    static const uint8_t F10R2_FB26 = 26;            // Filter bits
    static const uint8_t F10R2_FB27 = 27;            // Filter bits
    static const uint8_t F10R2_FB28 = 28;            // Filter bits
    static const uint8_t F10R2_FB29 = 29;            // Filter bits
    static const uint8_t F10R2_FB30 = 30;            // Filter bits
    static const uint8_t F10R2_FB31 = 31;            // Filter bits
    static const uint32_t F10R2_RESET_VALUE = 0x0;

    static const uint8_t F11R1_FB0 = 0;              // Filter bits
    static const uint8_t F11R1_FB1 = 1;              // Filter bits
    static const uint8_t F11R1_FB2 = 2;              // Filter bits
    static const uint8_t F11R1_FB3 = 3;              // Filter bits
    static const uint8_t F11R1_FB4 = 4;              // Filter bits
    static const uint8_t F11R1_FB5 = 5;              // Filter bits
    static const uint8_t F11R1_FB6 = 6;              // Filter bits
    static const uint8_t F11R1_FB7 = 7;              // Filter bits
    static const uint8_t F11R1_FB8 = 8;              // Filter bits
    static const uint8_t F11R1_FB9 = 9;              // Filter bits
    static const uint8_t F11R1_FB10 = 10;            // Filter bits
    static const uint8_t F11R1_FB11 = 11;            // Filter bits
    static const uint8_t F11R1_FB12 = 12;            // Filter bits
    static const uint8_t F11R1_FB13 = 13;            // Filter bits
    static const uint8_t F11R1_FB14 = 14;            // Filter bits
    static const uint8_t F11R1_FB15 = 15;            // Filter bits
    static const uint8_t F11R1_FB16 = 16;            // Filter bits
    static const uint8_t F11R1_FB17 = 17;            // Filter bits
    static const uint8_t F11R1_FB18 = 18;            // Filter bits
    static const uint8_t F11R1_FB19 = 19;            // Filter bits
    static const uint8_t F11R1_FB20 = 20;            // Filter bits
    static const uint8_t F11R1_FB21 = 21;            // Filter bits
    static const uint8_t F11R1_FB22 = 22;            // Filter bits
    static const uint8_t F11R1_FB23 = 23;            // Filter bits
    static const uint8_t F11R1_FB24 = 24;            // Filter bits
    static const uint8_t F11R1_FB25 = 25;            // Filter bits
    static const uint8_t F11R1_FB26 = 26;            // Filter bits
    static const uint8_t F11R1_FB27 = 27;            // Filter bits
    static const uint8_t F11R1_FB28 = 28;            // Filter bits
    static const uint8_t F11R1_FB29 = 29;            // Filter bits
    static const uint8_t F11R1_FB30 = 30;            // Filter bits
    static const uint8_t F11R1_FB31 = 31;            // Filter bits
    static const uint32_t F11R1_RESET_VALUE = 0x0;

    static const uint8_t F11R2_FB0 = 0;              // Filter bits
    static const uint8_t F11R2_FB1 = 1;              // Filter bits
    static const uint8_t F11R2_FB2 = 2;              // Filter bits
    static const uint8_t F11R2_FB3 = 3;              // Filter bits
    static const uint8_t F11R2_FB4 = 4;              // Filter bits
    static const uint8_t F11R2_FB5 = 5;              // Filter bits
    static const uint8_t F11R2_FB6 = 6;              // Filter bits
    static const uint8_t F11R2_FB7 = 7;              // Filter bits
    static const uint8_t F11R2_FB8 = 8;              // Filter bits
    static const uint8_t F11R2_FB9 = 9;              // Filter bits
    static const uint8_t F11R2_FB10 = 10;            // Filter bits
    static const uint8_t F11R2_FB11 = 11;            // Filter bits
    static const uint8_t F11R2_FB12 = 12;            // Filter bits
    static const uint8_t F11R2_FB13 = 13;            // Filter bits
    static const uint8_t F11R2_FB14 = 14;            // Filter bits
    static const uint8_t F11R2_FB15 = 15;            // Filter bits
    static const uint8_t F11R2_FB16 = 16;            // Filter bits
    static const uint8_t F11R2_FB17 = 17;            // Filter bits
    static const uint8_t F11R2_FB18 = 18;            // Filter bits
    static const uint8_t F11R2_FB19 = 19;            // Filter bits
    static const uint8_t F11R2_FB20 = 20;            // Filter bits
    static const uint8_t F11R2_FB21 = 21;            // Filter bits
    static const uint8_t F11R2_FB22 = 22;            // Filter bits
    static const uint8_t F11R2_FB23 = 23;            // Filter bits
    static const uint8_t F11R2_FB24 = 24;            // Filter bits
    static const uint8_t F11R2_FB25 = 25;            // Filter bits
    static const uint8_t F11R2_FB26 = 26;            // Filter bits
    static const uint8_t F11R2_FB27 = 27;            // Filter bits
    static const uint8_t F11R2_FB28 = 28;            // Filter bits
    static const uint8_t F11R2_FB29 = 29;            // Filter bits
    static const uint8_t F11R2_FB30 = 30;            // Filter bits
    static const uint8_t F11R2_FB31 = 31;            // Filter bits
    static const uint32_t F11R2_RESET_VALUE = 0x0;

    static const uint8_t F12R1_FB0 = 0;              // Filter bits
    static const uint8_t F12R1_FB1 = 1;              // Filter bits
    static const uint8_t F12R1_FB2 = 2;              // Filter bits
    static const uint8_t F12R1_FB3 = 3;              // Filter bits
    static const uint8_t F12R1_FB4 = 4;              // Filter bits
    static const uint8_t F12R1_FB5 = 5;              // Filter bits
    static const uint8_t F12R1_FB6 = 6;              // Filter bits
    static const uint8_t F12R1_FB7 = 7;              // Filter bits
    static const uint8_t F12R1_FB8 = 8;              // Filter bits
    static const uint8_t F12R1_FB9 = 9;              // Filter bits
    static const uint8_t F12R1_FB10 = 10;            // Filter bits
    static const uint8_t F12R1_FB11 = 11;            // Filter bits
    static const uint8_t F12R1_FB12 = 12;            // Filter bits
    static const uint8_t F12R1_FB13 = 13;            // Filter bits
    static const uint8_t F12R1_FB14 = 14;            // Filter bits
    static const uint8_t F12R1_FB15 = 15;            // Filter bits
    static const uint8_t F12R1_FB16 = 16;            // Filter bits
    static const uint8_t F12R1_FB17 = 17;            // Filter bits
    static const uint8_t F12R1_FB18 = 18;            // Filter bits
    static const uint8_t F12R1_FB19 = 19;            // Filter bits
    static const uint8_t F12R1_FB20 = 20;            // Filter bits
    static const uint8_t F12R1_FB21 = 21;            // Filter bits
    static const uint8_t F12R1_FB22 = 22;            // Filter bits
    static const uint8_t F12R1_FB23 = 23;            // Filter bits
    static const uint8_t F12R1_FB24 = 24;            // Filter bits
    static const uint8_t F12R1_FB25 = 25;            // Filter bits
    static const uint8_t F12R1_FB26 = 26;            // Filter bits
    static const uint8_t F12R1_FB27 = 27;            // Filter bits
    static const uint8_t F12R1_FB28 = 28;            // Filter bits
    static const uint8_t F12R1_FB29 = 29;            // Filter bits
    static const uint8_t F12R1_FB30 = 30;            // Filter bits
    static const uint8_t F12R1_FB31 = 31;            // Filter bits
    static const uint32_t F12R1_RESET_VALUE = 0x0;

    static const uint8_t F12R2_FB0 = 0;              // Filter bits
    static const uint8_t F12R2_FB1 = 1;              // Filter bits
    static const uint8_t F12R2_FB2 = 2;              // Filter bits
    static const uint8_t F12R2_FB3 = 3;              // Filter bits
    static const uint8_t F12R2_FB4 = 4;              // Filter bits
    static const uint8_t F12R2_FB5 = 5;              // Filter bits
    static const uint8_t F12R2_FB6 = 6;              // Filter bits
    static const uint8_t F12R2_FB7 = 7;              // Filter bits
    static const uint8_t F12R2_FB8 = 8;              // Filter bits
    static const uint8_t F12R2_FB9 = 9;              // Filter bits
    static const uint8_t F12R2_FB10 = 10;            // Filter bits
    static const uint8_t F12R2_FB11 = 11;            // Filter bits
    static const uint8_t F12R2_FB12 = 12;            // Filter bits
    static const uint8_t F12R2_FB13 = 13;            // Filter bits
    static const uint8_t F12R2_FB14 = 14;            // Filter bits
    static const uint8_t F12R2_FB15 = 15;            // Filter bits
    static const uint8_t F12R2_FB16 = 16;            // Filter bits
    static const uint8_t F12R2_FB17 = 17;            // Filter bits
    static const uint8_t F12R2_FB18 = 18;            // Filter bits
    static const uint8_t F12R2_FB19 = 19;            // Filter bits
    static const uint8_t F12R2_FB20 = 20;            // Filter bits
    static const uint8_t F12R2_FB21 = 21;            // Filter bits
    static const uint8_t F12R2_FB22 = 22;            // Filter bits
    static const uint8_t F12R2_FB23 = 23;            // Filter bits
    static const uint8_t F12R2_FB24 = 24;            // Filter bits
    static const uint8_t F12R2_FB25 = 25;            // Filter bits
    static const uint8_t F12R2_FB26 = 26;            // Filter bits
    static const uint8_t F12R2_FB27 = 27;            // Filter bits
    static const uint8_t F12R2_FB28 = 28;            // Filter bits
    static const uint8_t F12R2_FB29 = 29;            // Filter bits
    static const uint8_t F12R2_FB30 = 30;            // Filter bits
    static const uint8_t F12R2_FB31 = 31;            // Filter bits
    static const uint32_t F12R2_RESET_VALUE = 0x0;

    static const uint8_t F13R1_FB0 = 0;              // Filter bits
    static const uint8_t F13R1_FB1 = 1;              // Filter bits
    static const uint8_t F13R1_FB2 = 2;              // Filter bits
    static const uint8_t F13R1_FB3 = 3;              // Filter bits
    static const uint8_t F13R1_FB4 = 4;              // Filter bits
    static const uint8_t F13R1_FB5 = 5;              // Filter bits
    static const uint8_t F13R1_FB6 = 6;              // Filter bits
    static const uint8_t F13R1_FB7 = 7;              // Filter bits
    static const uint8_t F13R1_FB8 = 8;              // Filter bits
    static const uint8_t F13R1_FB9 = 9;              // Filter bits
    static const uint8_t F13R1_FB10 = 10;            // Filter bits
    static const uint8_t F13R1_FB11 = 11;            // Filter bits
    static const uint8_t F13R1_FB12 = 12;            // Filter bits
    static const uint8_t F13R1_FB13 = 13;            // Filter bits
    static const uint8_t F13R1_FB14 = 14;            // Filter bits
    static const uint8_t F13R1_FB15 = 15;            // Filter bits
    static const uint8_t F13R1_FB16 = 16;            // Filter bits
    static const uint8_t F13R1_FB17 = 17;            // Filter bits
    static const uint8_t F13R1_FB18 = 18;            // Filter bits
    static const uint8_t F13R1_FB19 = 19;            // Filter bits
    static const uint8_t F13R1_FB20 = 20;            // Filter bits
    static const uint8_t F13R1_FB21 = 21;            // Filter bits
    static const uint8_t F13R1_FB22 = 22;            // Filter bits
    static const uint8_t F13R1_FB23 = 23;            // Filter bits
    static const uint8_t F13R1_FB24 = 24;            // Filter bits
    static const uint8_t F13R1_FB25 = 25;            // Filter bits
    static const uint8_t F13R1_FB26 = 26;            // Filter bits
    static const uint8_t F13R1_FB27 = 27;            // Filter bits
    static const uint8_t F13R1_FB28 = 28;            // Filter bits
    static const uint8_t F13R1_FB29 = 29;            // Filter bits
    static const uint8_t F13R1_FB30 = 30;            // Filter bits
    static const uint8_t F13R1_FB31 = 31;            // Filter bits
    static const uint32_t F13R1_RESET_VALUE = 0x0;

    static const uint8_t F13R2_FB0 = 0;              // Filter bits
    static const uint8_t F13R2_FB1 = 1;              // Filter bits
    static const uint8_t F13R2_FB2 = 2;              // Filter bits
    static const uint8_t F13R2_FB3 = 3;              // Filter bits
    static const uint8_t F13R2_FB4 = 4;              // Filter bits
    static const uint8_t F13R2_FB5 = 5;              // Filter bits
    static const uint8_t F13R2_FB6 = 6;              // Filter bits
    static const uint8_t F13R2_FB7 = 7;              // Filter bits
    static const uint8_t F13R2_FB8 = 8;              // Filter bits
    static const uint8_t F13R2_FB9 = 9;              // Filter bits
    static const uint8_t F13R2_FB10 = 10;            // Filter bits
    static const uint8_t F13R2_FB11 = 11;            // Filter bits
    static const uint8_t F13R2_FB12 = 12;            // Filter bits
    static const uint8_t F13R2_FB13 = 13;            // Filter bits
    static const uint8_t F13R2_FB14 = 14;            // Filter bits
    static const uint8_t F13R2_FB15 = 15;            // Filter bits
    static const uint8_t F13R2_FB16 = 16;            // Filter bits
    static const uint8_t F13R2_FB17 = 17;            // Filter bits
    static const uint8_t F13R2_FB18 = 18;            // Filter bits
    static const uint8_t F13R2_FB19 = 19;            // Filter bits
    static const uint8_t F13R2_FB20 = 20;            // Filter bits
    static const uint8_t F13R2_FB21 = 21;            // Filter bits
    static const uint8_t F13R2_FB22 = 22;            // Filter bits
    static const uint8_t F13R2_FB23 = 23;            // Filter bits
    static const uint8_t F13R2_FB24 = 24;            // Filter bits
    static const uint8_t F13R2_FB25 = 25;            // Filter bits
    static const uint8_t F13R2_FB26 = 26;            // Filter bits
    static const uint8_t F13R2_FB27 = 27;            // Filter bits
    static const uint8_t F13R2_FB28 = 28;            // Filter bits
    static const uint8_t F13R2_FB29 = 29;            // Filter bits
    static const uint8_t F13R2_FB30 = 30;            // Filter bits
    static const uint8_t F13R2_FB31 = 31;            // Filter bits
    static const uint32_t F13R2_RESET_VALUE = 0x0;

    static const uint8_t F14R1_FB0 = 0;              // Filter bits
    static const uint8_t F14R1_FB1 = 1;              // Filter bits
    static const uint8_t F14R1_FB2 = 2;              // Filter bits
    static const uint8_t F14R1_FB3 = 3;              // Filter bits
    static const uint8_t F14R1_FB4 = 4;              // Filter bits
    static const uint8_t F14R1_FB5 = 5;              // Filter bits
    static const uint8_t F14R1_FB6 = 6;              // Filter bits
    static const uint8_t F14R1_FB7 = 7;              // Filter bits
    static const uint8_t F14R1_FB8 = 8;              // Filter bits
    static const uint8_t F14R1_FB9 = 9;              // Filter bits
    static const uint8_t F14R1_FB10 = 10;            // Filter bits
    static const uint8_t F14R1_FB11 = 11;            // Filter bits
    static const uint8_t F14R1_FB12 = 12;            // Filter bits
    static const uint8_t F14R1_FB13 = 13;            // Filter bits
    static const uint8_t F14R1_FB14 = 14;            // Filter bits
    static const uint8_t F14R1_FB15 = 15;            // Filter bits
    static const uint8_t F14R1_FB16 = 16;            // Filter bits
    static const uint8_t F14R1_FB17 = 17;            // Filter bits
    static const uint8_t F14R1_FB18 = 18;            // Filter bits
    static const uint8_t F14R1_FB19 = 19;            // Filter bits
    static const uint8_t F14R1_FB20 = 20;            // Filter bits
    static const uint8_t F14R1_FB21 = 21;            // Filter bits
    static const uint8_t F14R1_FB22 = 22;            // Filter bits
    static const uint8_t F14R1_FB23 = 23;            // Filter bits
    static const uint8_t F14R1_FB24 = 24;            // Filter bits
    static const uint8_t F14R1_FB25 = 25;            // Filter bits
    static const uint8_t F14R1_FB26 = 26;            // Filter bits
    static const uint8_t F14R1_FB27 = 27;            // Filter bits
    static const uint8_t F14R1_FB28 = 28;            // Filter bits
    static const uint8_t F14R1_FB29 = 29;            // Filter bits
    static const uint8_t F14R1_FB30 = 30;            // Filter bits
    static const uint8_t F14R1_FB31 = 31;            // Filter bits
    static const uint32_t F14R1_RESET_VALUE = 0x0;

    static const uint8_t F14R2_FB0 = 0;              // Filter bits
    static const uint8_t F14R2_FB1 = 1;              // Filter bits
    static const uint8_t F14R2_FB2 = 2;              // Filter bits
    static const uint8_t F14R2_FB3 = 3;              // Filter bits
    static const uint8_t F14R2_FB4 = 4;              // Filter bits
    static const uint8_t F14R2_FB5 = 5;              // Filter bits
    static const uint8_t F14R2_FB6 = 6;              // Filter bits
    static const uint8_t F14R2_FB7 = 7;              // Filter bits
    static const uint8_t F14R2_FB8 = 8;              // Filter bits
    static const uint8_t F14R2_FB9 = 9;              // Filter bits
    static const uint8_t F14R2_FB10 = 10;            // Filter bits
    static const uint8_t F14R2_FB11 = 11;            // Filter bits
    static const uint8_t F14R2_FB12 = 12;            // Filter bits
    static const uint8_t F14R2_FB13 = 13;            // Filter bits
    static const uint8_t F14R2_FB14 = 14;            // Filter bits
    static const uint8_t F14R2_FB15 = 15;            // Filter bits
    static const uint8_t F14R2_FB16 = 16;            // Filter bits
    static const uint8_t F14R2_FB17 = 17;            // Filter bits
    static const uint8_t F14R2_FB18 = 18;            // Filter bits
    static const uint8_t F14R2_FB19 = 19;            // Filter bits
    static const uint8_t F14R2_FB20 = 20;            // Filter bits
    static const uint8_t F14R2_FB21 = 21;            // Filter bits
    static const uint8_t F14R2_FB22 = 22;            // Filter bits
    static const uint8_t F14R2_FB23 = 23;            // Filter bits
    static const uint8_t F14R2_FB24 = 24;            // Filter bits
    static const uint8_t F14R2_FB25 = 25;            // Filter bits
    static const uint8_t F14R2_FB26 = 26;            // Filter bits
    static const uint8_t F14R2_FB27 = 27;            // Filter bits
    static const uint8_t F14R2_FB28 = 28;            // Filter bits
    static const uint8_t F14R2_FB29 = 29;            // Filter bits
    static const uint8_t F14R2_FB30 = 30;            // Filter bits
    static const uint8_t F14R2_FB31 = 31;            // Filter bits
    static const uint32_t F14R2_RESET_VALUE = 0x0;

    static const uint8_t F15R1_FB0 = 0;              // Filter bits
    static const uint8_t F15R1_FB1 = 1;              // Filter bits
    static const uint8_t F15R1_FB2 = 2;              // Filter bits
    static const uint8_t F15R1_FB3 = 3;              // Filter bits
    static const uint8_t F15R1_FB4 = 4;              // Filter bits
    static const uint8_t F15R1_FB5 = 5;              // Filter bits
    static const uint8_t F15R1_FB6 = 6;              // Filter bits
    static const uint8_t F15R1_FB7 = 7;              // Filter bits
    static const uint8_t F15R1_FB8 = 8;              // Filter bits
    static const uint8_t F15R1_FB9 = 9;              // Filter bits
    static const uint8_t F15R1_FB10 = 10;            // Filter bits
    static const uint8_t F15R1_FB11 = 11;            // Filter bits
    static const uint8_t F15R1_FB12 = 12;            // Filter bits
    static const uint8_t F15R1_FB13 = 13;            // Filter bits
    static const uint8_t F15R1_FB14 = 14;            // Filter bits
    static const uint8_t F15R1_FB15 = 15;            // Filter bits
    static const uint8_t F15R1_FB16 = 16;            // Filter bits
    static const uint8_t F15R1_FB17 = 17;            // Filter bits
    static const uint8_t F15R1_FB18 = 18;            // Filter bits
    static const uint8_t F15R1_FB19 = 19;            // Filter bits
    static const uint8_t F15R1_FB20 = 20;            // Filter bits
    static const uint8_t F15R1_FB21 = 21;            // Filter bits
    static const uint8_t F15R1_FB22 = 22;            // Filter bits
    static const uint8_t F15R1_FB23 = 23;            // Filter bits
    static const uint8_t F15R1_FB24 = 24;            // Filter bits
    static const uint8_t F15R1_FB25 = 25;            // Filter bits
    static const uint8_t F15R1_FB26 = 26;            // Filter bits
    static const uint8_t F15R1_FB27 = 27;            // Filter bits
    static const uint8_t F15R1_FB28 = 28;            // Filter bits
    static const uint8_t F15R1_FB29 = 29;            // Filter bits
    static const uint8_t F15R1_FB30 = 30;            // Filter bits
    static const uint8_t F15R1_FB31 = 31;            // Filter bits
    static const uint32_t F15R1_RESET_VALUE = 0x0;

    static const uint8_t F15R2_FB0 = 0;              // Filter bits
    static const uint8_t F15R2_FB1 = 1;              // Filter bits
    static const uint8_t F15R2_FB2 = 2;              // Filter bits
    static const uint8_t F15R2_FB3 = 3;              // Filter bits
    static const uint8_t F15R2_FB4 = 4;              // Filter bits
    static const uint8_t F15R2_FB5 = 5;              // Filter bits
    static const uint8_t F15R2_FB6 = 6;              // Filter bits
    static const uint8_t F15R2_FB7 = 7;              // Filter bits
    static const uint8_t F15R2_FB8 = 8;              // Filter bits
    static const uint8_t F15R2_FB9 = 9;              // Filter bits
    static const uint8_t F15R2_FB10 = 10;            // Filter bits
    static const uint8_t F15R2_FB11 = 11;            // Filter bits
    static const uint8_t F15R2_FB12 = 12;            // Filter bits
    static const uint8_t F15R2_FB13 = 13;            // Filter bits
    static const uint8_t F15R2_FB14 = 14;            // Filter bits
    static const uint8_t F15R2_FB15 = 15;            // Filter bits
    static const uint8_t F15R2_FB16 = 16;            // Filter bits
    static const uint8_t F15R2_FB17 = 17;            // Filter bits
    static const uint8_t F15R2_FB18 = 18;            // Filter bits
    static const uint8_t F15R2_FB19 = 19;            // Filter bits
    static const uint8_t F15R2_FB20 = 20;            // Filter bits
    static const uint8_t F15R2_FB21 = 21;            // Filter bits
    static const uint8_t F15R2_FB22 = 22;            // Filter bits
    static const uint8_t F15R2_FB23 = 23;            // Filter bits
    static const uint8_t F15R2_FB24 = 24;            // Filter bits
    static const uint8_t F15R2_FB25 = 25;            // Filter bits
    static const uint8_t F15R2_FB26 = 26;            // Filter bits
    static const uint8_t F15R2_FB27 = 27;            // Filter bits
    static const uint8_t F15R2_FB28 = 28;            // Filter bits
    static const uint8_t F15R2_FB29 = 29;            // Filter bits
    static const uint8_t F15R2_FB30 = 30;            // Filter bits
    static const uint8_t F15R2_FB31 = 31;            // Filter bits
    static const uint32_t F15R2_RESET_VALUE = 0x0;

    static const uint8_t F16R1_FB0 = 0;              // Filter bits
    static const uint8_t F16R1_FB1 = 1;              // Filter bits
    static const uint8_t F16R1_FB2 = 2;              // Filter bits
    static const uint8_t F16R1_FB3 = 3;              // Filter bits
    static const uint8_t F16R1_FB4 = 4;              // Filter bits
    static const uint8_t F16R1_FB5 = 5;              // Filter bits
    static const uint8_t F16R1_FB6 = 6;              // Filter bits
    static const uint8_t F16R1_FB7 = 7;              // Filter bits
    static const uint8_t F16R1_FB8 = 8;              // Filter bits
    static const uint8_t F16R1_FB9 = 9;              // Filter bits
    static const uint8_t F16R1_FB10 = 10;            // Filter bits
    static const uint8_t F16R1_FB11 = 11;            // Filter bits
    static const uint8_t F16R1_FB12 = 12;            // Filter bits
    static const uint8_t F16R1_FB13 = 13;            // Filter bits
    static const uint8_t F16R1_FB14 = 14;            // Filter bits
    static const uint8_t F16R1_FB15 = 15;            // Filter bits
    static const uint8_t F16R1_FB16 = 16;            // Filter bits
    static const uint8_t F16R1_FB17 = 17;            // Filter bits
    static const uint8_t F16R1_FB18 = 18;            // Filter bits
    static const uint8_t F16R1_FB19 = 19;            // Filter bits
    static const uint8_t F16R1_FB20 = 20;            // Filter bits
    static const uint8_t F16R1_FB21 = 21;            // Filter bits
    static const uint8_t F16R1_FB22 = 22;            // Filter bits
    static const uint8_t F16R1_FB23 = 23;            // Filter bits
    static const uint8_t F16R1_FB24 = 24;            // Filter bits
    static const uint8_t F16R1_FB25 = 25;            // Filter bits
    static const uint8_t F16R1_FB26 = 26;            // Filter bits
    static const uint8_t F16R1_FB27 = 27;            // Filter bits
    static const uint8_t F16R1_FB28 = 28;            // Filter bits
    static const uint8_t F16R1_FB29 = 29;            // Filter bits
    static const uint8_t F16R1_FB30 = 30;            // Filter bits
    static const uint8_t F16R1_FB31 = 31;            // Filter bits
    static const uint32_t F16R1_RESET_VALUE = 0x0;

    static const uint8_t F16R2_FB0 = 0;              // Filter bits
    static const uint8_t F16R2_FB1 = 1;              // Filter bits
    static const uint8_t F16R2_FB2 = 2;              // Filter bits
    static const uint8_t F16R2_FB3 = 3;              // Filter bits
    static const uint8_t F16R2_FB4 = 4;              // Filter bits
    static const uint8_t F16R2_FB5 = 5;              // Filter bits
    static const uint8_t F16R2_FB6 = 6;              // Filter bits
    static const uint8_t F16R2_FB7 = 7;              // Filter bits
    static const uint8_t F16R2_FB8 = 8;              // Filter bits
    static const uint8_t F16R2_FB9 = 9;              // Filter bits
    static const uint8_t F16R2_FB10 = 10;            // Filter bits
    static const uint8_t F16R2_FB11 = 11;            // Filter bits
    static const uint8_t F16R2_FB12 = 12;            // Filter bits
    static const uint8_t F16R2_FB13 = 13;            // Filter bits
    static const uint8_t F16R2_FB14 = 14;            // Filter bits
    static const uint8_t F16R2_FB15 = 15;            // Filter bits
    static const uint8_t F16R2_FB16 = 16;            // Filter bits
    static const uint8_t F16R2_FB17 = 17;            // Filter bits
    static const uint8_t F16R2_FB18 = 18;            // Filter bits
    static const uint8_t F16R2_FB19 = 19;            // Filter bits
    static const uint8_t F16R2_FB20 = 20;            // Filter bits
    static const uint8_t F16R2_FB21 = 21;            // Filter bits
    static const uint8_t F16R2_FB22 = 22;            // Filter bits
    static const uint8_t F16R2_FB23 = 23;            // Filter bits
    static const uint8_t F16R2_FB24 = 24;            // Filter bits
    static const uint8_t F16R2_FB25 = 25;            // Filter bits
    static const uint8_t F16R2_FB26 = 26;            // Filter bits
    static const uint8_t F16R2_FB27 = 27;            // Filter bits
    static const uint8_t F16R2_FB28 = 28;            // Filter bits
    static const uint8_t F16R2_FB29 = 29;            // Filter bits
    static const uint8_t F16R2_FB30 = 30;            // Filter bits
    static const uint8_t F16R2_FB31 = 31;            // Filter bits
    static const uint32_t F16R2_RESET_VALUE = 0x0;

    static const uint8_t F17R1_FB0 = 0;              // Filter bits
    static const uint8_t F17R1_FB1 = 1;              // Filter bits
    static const uint8_t F17R1_FB2 = 2;              // Filter bits
    static const uint8_t F17R1_FB3 = 3;              // Filter bits
    static const uint8_t F17R1_FB4 = 4;              // Filter bits
    static const uint8_t F17R1_FB5 = 5;              // Filter bits
    static const uint8_t F17R1_FB6 = 6;              // Filter bits
    static const uint8_t F17R1_FB7 = 7;              // Filter bits
    static const uint8_t F17R1_FB8 = 8;              // Filter bits
    static const uint8_t F17R1_FB9 = 9;              // Filter bits
    static const uint8_t F17R1_FB10 = 10;            // Filter bits
    static const uint8_t F17R1_FB11 = 11;            // Filter bits
    static const uint8_t F17R1_FB12 = 12;            // Filter bits
    static const uint8_t F17R1_FB13 = 13;            // Filter bits
    static const uint8_t F17R1_FB14 = 14;            // Filter bits
    static const uint8_t F17R1_FB15 = 15;            // Filter bits
    static const uint8_t F17R1_FB16 = 16;            // Filter bits
    static const uint8_t F17R1_FB17 = 17;            // Filter bits
    static const uint8_t F17R1_FB18 = 18;            // Filter bits
    static const uint8_t F17R1_FB19 = 19;            // Filter bits
    static const uint8_t F17R1_FB20 = 20;            // Filter bits
    static const uint8_t F17R1_FB21 = 21;            // Filter bits
    static const uint8_t F17R1_FB22 = 22;            // Filter bits
    static const uint8_t F17R1_FB23 = 23;            // Filter bits
    static const uint8_t F17R1_FB24 = 24;            // Filter bits
    static const uint8_t F17R1_FB25 = 25;            // Filter bits
    static const uint8_t F17R1_FB26 = 26;            // Filter bits
    static const uint8_t F17R1_FB27 = 27;            // Filter bits
    static const uint8_t F17R1_FB28 = 28;            // Filter bits
    static const uint8_t F17R1_FB29 = 29;            // Filter bits
    static const uint8_t F17R1_FB30 = 30;            // Filter bits
    static const uint8_t F17R1_FB31 = 31;            // Filter bits
    static const uint32_t F17R1_RESET_VALUE = 0x0;

    static const uint8_t F17R2_FB0 = 0;              // Filter bits
    static const uint8_t F17R2_FB1 = 1;              // Filter bits
    static const uint8_t F17R2_FB2 = 2;              // Filter bits
    static const uint8_t F17R2_FB3 = 3;              // Filter bits
    static const uint8_t F17R2_FB4 = 4;              // Filter bits
    static const uint8_t F17R2_FB5 = 5;              // Filter bits
    static const uint8_t F17R2_FB6 = 6;              // Filter bits
    static const uint8_t F17R2_FB7 = 7;              // Filter bits
    static const uint8_t F17R2_FB8 = 8;              // Filter bits
    static const uint8_t F17R2_FB9 = 9;              // Filter bits
    static const uint8_t F17R2_FB10 = 10;            // Filter bits
    static const uint8_t F17R2_FB11 = 11;            // Filter bits
    static const uint8_t F17R2_FB12 = 12;            // Filter bits
    static const uint8_t F17R2_FB13 = 13;            // Filter bits
    static const uint8_t F17R2_FB14 = 14;            // Filter bits
    static const uint8_t F17R2_FB15 = 15;            // Filter bits
    static const uint8_t F17R2_FB16 = 16;            // Filter bits
    static const uint8_t F17R2_FB17 = 17;            // Filter bits
    static const uint8_t F17R2_FB18 = 18;            // Filter bits
    static const uint8_t F17R2_FB19 = 19;            // Filter bits
    static const uint8_t F17R2_FB20 = 20;            // Filter bits
    static const uint8_t F17R2_FB21 = 21;            // Filter bits
    static const uint8_t F17R2_FB22 = 22;            // Filter bits
    static const uint8_t F17R2_FB23 = 23;            // Filter bits
    static const uint8_t F17R2_FB24 = 24;            // Filter bits
    static const uint8_t F17R2_FB25 = 25;            // Filter bits
    static const uint8_t F17R2_FB26 = 26;            // Filter bits
    static const uint8_t F17R2_FB27 = 27;            // Filter bits
    static const uint8_t F17R2_FB28 = 28;            // Filter bits
    static const uint8_t F17R2_FB29 = 29;            // Filter bits
    static const uint8_t F17R2_FB30 = 30;            // Filter bits
    static const uint8_t F17R2_FB31 = 31;            // Filter bits
    static const uint32_t F17R2_RESET_VALUE = 0x0;

    static const uint8_t F18R1_FB0 = 0;              // Filter bits
    static const uint8_t F18R1_FB1 = 1;              // Filter bits
    static const uint8_t F18R1_FB2 = 2;              // Filter bits
    static const uint8_t F18R1_FB3 = 3;              // Filter bits
    static const uint8_t F18R1_FB4 = 4;              // Filter bits
    static const uint8_t F18R1_FB5 = 5;              // Filter bits
    static const uint8_t F18R1_FB6 = 6;              // Filter bits
    static const uint8_t F18R1_FB7 = 7;              // Filter bits
    static const uint8_t F18R1_FB8 = 8;              // Filter bits
    static const uint8_t F18R1_FB9 = 9;              // Filter bits
    static const uint8_t F18R1_FB10 = 10;            // Filter bits
    static const uint8_t F18R1_FB11 = 11;            // Filter bits
    static const uint8_t F18R1_FB12 = 12;            // Filter bits
    static const uint8_t F18R1_FB13 = 13;            // Filter bits
    static const uint8_t F18R1_FB14 = 14;            // Filter bits
    static const uint8_t F18R1_FB15 = 15;            // Filter bits
    static const uint8_t F18R1_FB16 = 16;            // Filter bits
    static const uint8_t F18R1_FB17 = 17;            // Filter bits
    static const uint8_t F18R1_FB18 = 18;            // Filter bits
    static const uint8_t F18R1_FB19 = 19;            // Filter bits
    static const uint8_t F18R1_FB20 = 20;            // Filter bits
    static const uint8_t F18R1_FB21 = 21;            // Filter bits
    static const uint8_t F18R1_FB22 = 22;            // Filter bits
    static const uint8_t F18R1_FB23 = 23;            // Filter bits
    static const uint8_t F18R1_FB24 = 24;            // Filter bits
    static const uint8_t F18R1_FB25 = 25;            // Filter bits
    static const uint8_t F18R1_FB26 = 26;            // Filter bits
    static const uint8_t F18R1_FB27 = 27;            // Filter bits
    static const uint8_t F18R1_FB28 = 28;            // Filter bits
    static const uint8_t F18R1_FB29 = 29;            // Filter bits
    static const uint8_t F18R1_FB30 = 30;            // Filter bits
    static const uint8_t F18R1_FB31 = 31;            // Filter bits
    static const uint32_t F18R1_RESET_VALUE = 0x0;

    static const uint8_t F18R2_FB0 = 0;              // Filter bits
    static const uint8_t F18R2_FB1 = 1;              // Filter bits
    static const uint8_t F18R2_FB2 = 2;              // Filter bits
    static const uint8_t F18R2_FB3 = 3;              // Filter bits
    static const uint8_t F18R2_FB4 = 4;              // Filter bits
    static const uint8_t F18R2_FB5 = 5;              // Filter bits
    static const uint8_t F18R2_FB6 = 6;              // Filter bits
    static const uint8_t F18R2_FB7 = 7;              // Filter bits
    static const uint8_t F18R2_FB8 = 8;              // Filter bits
    static const uint8_t F18R2_FB9 = 9;              // Filter bits
    static const uint8_t F18R2_FB10 = 10;            // Filter bits
    static const uint8_t F18R2_FB11 = 11;            // Filter bits
    static const uint8_t F18R2_FB12 = 12;            // Filter bits
    static const uint8_t F18R2_FB13 = 13;            // Filter bits
    static const uint8_t F18R2_FB14 = 14;            // Filter bits
    static const uint8_t F18R2_FB15 = 15;            // Filter bits
    static const uint8_t F18R2_FB16 = 16;            // Filter bits
    static const uint8_t F18R2_FB17 = 17;            // Filter bits
    static const uint8_t F18R2_FB18 = 18;            // Filter bits
    static const uint8_t F18R2_FB19 = 19;            // Filter bits
    static const uint8_t F18R2_FB20 = 20;            // Filter bits
    static const uint8_t F18R2_FB21 = 21;            // Filter bits
    static const uint8_t F18R2_FB22 = 22;            // Filter bits
    static const uint8_t F18R2_FB23 = 23;            // Filter bits
    static const uint8_t F18R2_FB24 = 24;            // Filter bits
    static const uint8_t F18R2_FB25 = 25;            // Filter bits
    static const uint8_t F18R2_FB26 = 26;            // Filter bits
    static const uint8_t F18R2_FB27 = 27;            // Filter bits
    static const uint8_t F18R2_FB28 = 28;            // Filter bits
    static const uint8_t F18R2_FB29 = 29;            // Filter bits
    static const uint8_t F18R2_FB30 = 30;            // Filter bits
    static const uint8_t F18R2_FB31 = 31;            // Filter bits
    static const uint32_t F18R2_RESET_VALUE = 0x0;

    static const uint8_t F19R1_FB0 = 0;              // Filter bits
    static const uint8_t F19R1_FB1 = 1;              // Filter bits
    static const uint8_t F19R1_FB2 = 2;              // Filter bits
    static const uint8_t F19R1_FB3 = 3;              // Filter bits
    static const uint8_t F19R1_FB4 = 4;              // Filter bits
    static const uint8_t F19R1_FB5 = 5;              // Filter bits
    static const uint8_t F19R1_FB6 = 6;              // Filter bits
    static const uint8_t F19R1_FB7 = 7;              // Filter bits
    static const uint8_t F19R1_FB8 = 8;              // Filter bits
    static const uint8_t F19R1_FB9 = 9;              // Filter bits
    static const uint8_t F19R1_FB10 = 10;            // Filter bits
    static const uint8_t F19R1_FB11 = 11;            // Filter bits
    static const uint8_t F19R1_FB12 = 12;            // Filter bits
    static const uint8_t F19R1_FB13 = 13;            // Filter bits
    static const uint8_t F19R1_FB14 = 14;            // Filter bits
    static const uint8_t F19R1_FB15 = 15;            // Filter bits
    static const uint8_t F19R1_FB16 = 16;            // Filter bits
    static const uint8_t F19R1_FB17 = 17;            // Filter bits
    static const uint8_t F19R1_FB18 = 18;            // Filter bits
    static const uint8_t F19R1_FB19 = 19;            // Filter bits
    static const uint8_t F19R1_FB20 = 20;            // Filter bits
    static const uint8_t F19R1_FB21 = 21;            // Filter bits
    static const uint8_t F19R1_FB22 = 22;            // Filter bits
    static const uint8_t F19R1_FB23 = 23;            // Filter bits
    static const uint8_t F19R1_FB24 = 24;            // Filter bits
    static const uint8_t F19R1_FB25 = 25;            // Filter bits
    static const uint8_t F19R1_FB26 = 26;            // Filter bits
    static const uint8_t F19R1_FB27 = 27;            // Filter bits
    static const uint8_t F19R1_FB28 = 28;            // Filter bits
    static const uint8_t F19R1_FB29 = 29;            // Filter bits
    static const uint8_t F19R1_FB30 = 30;            // Filter bits
    static const uint8_t F19R1_FB31 = 31;            // Filter bits
    static const uint32_t F19R1_RESET_VALUE = 0x0;

    static const uint8_t F19R2_FB0 = 0;              // Filter bits
    static const uint8_t F19R2_FB1 = 1;              // Filter bits
    static const uint8_t F19R2_FB2 = 2;              // Filter bits
    static const uint8_t F19R2_FB3 = 3;              // Filter bits
    static const uint8_t F19R2_FB4 = 4;              // Filter bits
    static const uint8_t F19R2_FB5 = 5;              // Filter bits
    static const uint8_t F19R2_FB6 = 6;              // Filter bits
    static const uint8_t F19R2_FB7 = 7;              // Filter bits
    static const uint8_t F19R2_FB8 = 8;              // Filter bits
    static const uint8_t F19R2_FB9 = 9;              // Filter bits
    static const uint8_t F19R2_FB10 = 10;            // Filter bits
    static const uint8_t F19R2_FB11 = 11;            // Filter bits
    static const uint8_t F19R2_FB12 = 12;            // Filter bits
    static const uint8_t F19R2_FB13 = 13;            // Filter bits
    static const uint8_t F19R2_FB14 = 14;            // Filter bits
    static const uint8_t F19R2_FB15 = 15;            // Filter bits
    static const uint8_t F19R2_FB16 = 16;            // Filter bits
    static const uint8_t F19R2_FB17 = 17;            // Filter bits
    static const uint8_t F19R2_FB18 = 18;            // Filter bits
    static const uint8_t F19R2_FB19 = 19;            // Filter bits
    static const uint8_t F19R2_FB20 = 20;            // Filter bits
    static const uint8_t F19R2_FB21 = 21;            // Filter bits
    static const uint8_t F19R2_FB22 = 22;            // Filter bits
    static const uint8_t F19R2_FB23 = 23;            // Filter bits
    static const uint8_t F19R2_FB24 = 24;            // Filter bits
    static const uint8_t F19R2_FB25 = 25;            // Filter bits
    static const uint8_t F19R2_FB26 = 26;            // Filter bits
    static const uint8_t F19R2_FB27 = 27;            // Filter bits
    static const uint8_t F19R2_FB28 = 28;            // Filter bits
    static const uint8_t F19R2_FB29 = 29;            // Filter bits
    static const uint8_t F19R2_FB30 = 30;            // Filter bits
    static const uint8_t F19R2_FB31 = 31;            // Filter bits
    static const uint32_t F19R2_RESET_VALUE = 0x0;

    static const uint8_t F20R1_FB0 = 0;              // Filter bits
    static const uint8_t F20R1_FB1 = 1;              // Filter bits
    static const uint8_t F20R1_FB2 = 2;              // Filter bits
    static const uint8_t F20R1_FB3 = 3;              // Filter bits
    static const uint8_t F20R1_FB4 = 4;              // Filter bits
    static const uint8_t F20R1_FB5 = 5;              // Filter bits
    static const uint8_t F20R1_FB6 = 6;              // Filter bits
    static const uint8_t F20R1_FB7 = 7;              // Filter bits
    static const uint8_t F20R1_FB8 = 8;              // Filter bits
    static const uint8_t F20R1_FB9 = 9;              // Filter bits
    static const uint8_t F20R1_FB10 = 10;            // Filter bits
    static const uint8_t F20R1_FB11 = 11;            // Filter bits
    static const uint8_t F20R1_FB12 = 12;            // Filter bits
    static const uint8_t F20R1_FB13 = 13;            // Filter bits
    static const uint8_t F20R1_FB14 = 14;            // Filter bits
    static const uint8_t F20R1_FB15 = 15;            // Filter bits
    static const uint8_t F20R1_FB16 = 16;            // Filter bits
    static const uint8_t F20R1_FB17 = 17;            // Filter bits
    static const uint8_t F20R1_FB18 = 18;            // Filter bits
    static const uint8_t F20R1_FB19 = 19;            // Filter bits
    static const uint8_t F20R1_FB20 = 20;            // Filter bits
    static const uint8_t F20R1_FB21 = 21;            // Filter bits
    static const uint8_t F20R1_FB22 = 22;            // Filter bits
    static const uint8_t F20R1_FB23 = 23;            // Filter bits
    static const uint8_t F20R1_FB24 = 24;            // Filter bits
    static const uint8_t F20R1_FB25 = 25;            // Filter bits
    static const uint8_t F20R1_FB26 = 26;            // Filter bits
    static const uint8_t F20R1_FB27 = 27;            // Filter bits
    static const uint8_t F20R1_FB28 = 28;            // Filter bits
    static const uint8_t F20R1_FB29 = 29;            // Filter bits
    static const uint8_t F20R1_FB30 = 30;            // Filter bits
    static const uint8_t F20R1_FB31 = 31;            // Filter bits
    static const uint32_t F20R1_RESET_VALUE = 0x0;

    static const uint8_t F20R2_FB0 = 0;              // Filter bits
    static const uint8_t F20R2_FB1 = 1;              // Filter bits
    static const uint8_t F20R2_FB2 = 2;              // Filter bits
    static const uint8_t F20R2_FB3 = 3;              // Filter bits
    static const uint8_t F20R2_FB4 = 4;              // Filter bits
    static const uint8_t F20R2_FB5 = 5;              // Filter bits
    static const uint8_t F20R2_FB6 = 6;              // Filter bits
    static const uint8_t F20R2_FB7 = 7;              // Filter bits
    static const uint8_t F20R2_FB8 = 8;              // Filter bits
    static const uint8_t F20R2_FB9 = 9;              // Filter bits
    static const uint8_t F20R2_FB10 = 10;            // Filter bits
    static const uint8_t F20R2_FB11 = 11;            // Filter bits
    static const uint8_t F20R2_FB12 = 12;            // Filter bits
    static const uint8_t F20R2_FB13 = 13;            // Filter bits
    static const uint8_t F20R2_FB14 = 14;            // Filter bits
    static const uint8_t F20R2_FB15 = 15;            // Filter bits
    static const uint8_t F20R2_FB16 = 16;            // Filter bits
    static const uint8_t F20R2_FB17 = 17;            // Filter bits
    static const uint8_t F20R2_FB18 = 18;            // Filter bits
    static const uint8_t F20R2_FB19 = 19;            // Filter bits
    static const uint8_t F20R2_FB20 = 20;            // Filter bits
    static const uint8_t F20R2_FB21 = 21;            // Filter bits
    static const uint8_t F20R2_FB22 = 22;            // Filter bits
    static const uint8_t F20R2_FB23 = 23;            // Filter bits
    static const uint8_t F20R2_FB24 = 24;            // Filter bits
    static const uint8_t F20R2_FB25 = 25;            // Filter bits
    static const uint8_t F20R2_FB26 = 26;            // Filter bits
    static const uint8_t F20R2_FB27 = 27;            // Filter bits
    static const uint8_t F20R2_FB28 = 28;            // Filter bits
    static const uint8_t F20R2_FB29 = 29;            // Filter bits
    static const uint8_t F20R2_FB30 = 30;            // Filter bits
    static const uint8_t F20R2_FB31 = 31;            // Filter bits
    static const uint32_t F20R2_RESET_VALUE = 0x0;

    static const uint8_t F21R1_FB0 = 0;              // Filter bits
    static const uint8_t F21R1_FB1 = 1;              // Filter bits
    static const uint8_t F21R1_FB2 = 2;              // Filter bits
    static const uint8_t F21R1_FB3 = 3;              // Filter bits
    static const uint8_t F21R1_FB4 = 4;              // Filter bits
    static const uint8_t F21R1_FB5 = 5;              // Filter bits
    static const uint8_t F21R1_FB6 = 6;              // Filter bits
    static const uint8_t F21R1_FB7 = 7;              // Filter bits
    static const uint8_t F21R1_FB8 = 8;              // Filter bits
    static const uint8_t F21R1_FB9 = 9;              // Filter bits
    static const uint8_t F21R1_FB10 = 10;            // Filter bits
    static const uint8_t F21R1_FB11 = 11;            // Filter bits
    static const uint8_t F21R1_FB12 = 12;            // Filter bits
    static const uint8_t F21R1_FB13 = 13;            // Filter bits
    static const uint8_t F21R1_FB14 = 14;            // Filter bits
    static const uint8_t F21R1_FB15 = 15;            // Filter bits
    static const uint8_t F21R1_FB16 = 16;            // Filter bits
    static const uint8_t F21R1_FB17 = 17;            // Filter bits
    static const uint8_t F21R1_FB18 = 18;            // Filter bits
    static const uint8_t F21R1_FB19 = 19;            // Filter bits
    static const uint8_t F21R1_FB20 = 20;            // Filter bits
    static const uint8_t F21R1_FB21 = 21;            // Filter bits
    static const uint8_t F21R1_FB22 = 22;            // Filter bits
    static const uint8_t F21R1_FB23 = 23;            // Filter bits
    static const uint8_t F21R1_FB24 = 24;            // Filter bits
    static const uint8_t F21R1_FB25 = 25;            // Filter bits
    static const uint8_t F21R1_FB26 = 26;            // Filter bits
    static const uint8_t F21R1_FB27 = 27;            // Filter bits
    static const uint8_t F21R1_FB28 = 28;            // Filter bits
    static const uint8_t F21R1_FB29 = 29;            // Filter bits
    static const uint8_t F21R1_FB30 = 30;            // Filter bits
    static const uint8_t F21R1_FB31 = 31;            // Filter bits
    static const uint32_t F21R1_RESET_VALUE = 0x0;

    static const uint8_t F21R2_FB0 = 0;              // Filter bits
    static const uint8_t F21R2_FB1 = 1;              // Filter bits
    static const uint8_t F21R2_FB2 = 2;              // Filter bits
    static const uint8_t F21R2_FB3 = 3;              // Filter bits
    static const uint8_t F21R2_FB4 = 4;              // Filter bits
    static const uint8_t F21R2_FB5 = 5;              // Filter bits
    static const uint8_t F21R2_FB6 = 6;              // Filter bits
    static const uint8_t F21R2_FB7 = 7;              // Filter bits
    static const uint8_t F21R2_FB8 = 8;              // Filter bits
    static const uint8_t F21R2_FB9 = 9;              // Filter bits
    static const uint8_t F21R2_FB10 = 10;            // Filter bits
    static const uint8_t F21R2_FB11 = 11;            // Filter bits
    static const uint8_t F21R2_FB12 = 12;            // Filter bits
    static const uint8_t F21R2_FB13 = 13;            // Filter bits
    static const uint8_t F21R2_FB14 = 14;            // Filter bits
    static const uint8_t F21R2_FB15 = 15;            // Filter bits
    static const uint8_t F21R2_FB16 = 16;            // Filter bits
    static const uint8_t F21R2_FB17 = 17;            // Filter bits
    static const uint8_t F21R2_FB18 = 18;            // Filter bits
    static const uint8_t F21R2_FB19 = 19;            // Filter bits
    static const uint8_t F21R2_FB20 = 20;            // Filter bits
    static const uint8_t F21R2_FB21 = 21;            // Filter bits
    static const uint8_t F21R2_FB22 = 22;            // Filter bits
    static const uint8_t F21R2_FB23 = 23;            // Filter bits
    static const uint8_t F21R2_FB24 = 24;            // Filter bits
    static const uint8_t F21R2_FB25 = 25;            // Filter bits
    static const uint8_t F21R2_FB26 = 26;            // Filter bits
    static const uint8_t F21R2_FB27 = 27;            // Filter bits
    static const uint8_t F21R2_FB28 = 28;            // Filter bits
    static const uint8_t F21R2_FB29 = 29;            // Filter bits
    static const uint8_t F21R2_FB30 = 30;            // Filter bits
    static const uint8_t F21R2_FB31 = 31;            // Filter bits
    static const uint32_t F21R2_RESET_VALUE = 0x0;

    static const uint8_t F22R1_FB0 = 0;              // Filter bits
    static const uint8_t F22R1_FB1 = 1;              // Filter bits
    static const uint8_t F22R1_FB2 = 2;              // Filter bits
    static const uint8_t F22R1_FB3 = 3;              // Filter bits
    static const uint8_t F22R1_FB4 = 4;              // Filter bits
    static const uint8_t F22R1_FB5 = 5;              // Filter bits
    static const uint8_t F22R1_FB6 = 6;              // Filter bits
    static const uint8_t F22R1_FB7 = 7;              // Filter bits
    static const uint8_t F22R1_FB8 = 8;              // Filter bits
    static const uint8_t F22R1_FB9 = 9;              // Filter bits
    static const uint8_t F22R1_FB10 = 10;            // Filter bits
    static const uint8_t F22R1_FB11 = 11;            // Filter bits
    static const uint8_t F22R1_FB12 = 12;            // Filter bits
    static const uint8_t F22R1_FB13 = 13;            // Filter bits
    static const uint8_t F22R1_FB14 = 14;            // Filter bits
    static const uint8_t F22R1_FB15 = 15;            // Filter bits
    static const uint8_t F22R1_FB16 = 16;            // Filter bits
    static const uint8_t F22R1_FB17 = 17;            // Filter bits
    static const uint8_t F22R1_FB18 = 18;            // Filter bits
    static const uint8_t F22R1_FB19 = 19;            // Filter bits
    static const uint8_t F22R1_FB20 = 20;            // Filter bits
    static const uint8_t F22R1_FB21 = 21;            // Filter bits
    static const uint8_t F22R1_FB22 = 22;            // Filter bits
    static const uint8_t F22R1_FB23 = 23;            // Filter bits
    static const uint8_t F22R1_FB24 = 24;            // Filter bits
    static const uint8_t F22R1_FB25 = 25;            // Filter bits
    static const uint8_t F22R1_FB26 = 26;            // Filter bits
    static const uint8_t F22R1_FB27 = 27;            // Filter bits
    static const uint8_t F22R1_FB28 = 28;            // Filter bits
    static const uint8_t F22R1_FB29 = 29;            // Filter bits
    static const uint8_t F22R1_FB30 = 30;            // Filter bits
    static const uint8_t F22R1_FB31 = 31;            // Filter bits
    static const uint32_t F22R1_RESET_VALUE = 0x0;

    static const uint8_t F22R2_FB0 = 0;              // Filter bits
    static const uint8_t F22R2_FB1 = 1;              // Filter bits
    static const uint8_t F22R2_FB2 = 2;              // Filter bits
    static const uint8_t F22R2_FB3 = 3;              // Filter bits
    static const uint8_t F22R2_FB4 = 4;              // Filter bits
    static const uint8_t F22R2_FB5 = 5;              // Filter bits
    static const uint8_t F22R2_FB6 = 6;              // Filter bits
    static const uint8_t F22R2_FB7 = 7;              // Filter bits
    static const uint8_t F22R2_FB8 = 8;              // Filter bits
    static const uint8_t F22R2_FB9 = 9;              // Filter bits
    static const uint8_t F22R2_FB10 = 10;            // Filter bits
    static const uint8_t F22R2_FB11 = 11;            // Filter bits
    static const uint8_t F22R2_FB12 = 12;            // Filter bits
    static const uint8_t F22R2_FB13 = 13;            // Filter bits
    static const uint8_t F22R2_FB14 = 14;            // Filter bits
    static const uint8_t F22R2_FB15 = 15;            // Filter bits
    static const uint8_t F22R2_FB16 = 16;            // Filter bits
    static const uint8_t F22R2_FB17 = 17;            // Filter bits
    static const uint8_t F22R2_FB18 = 18;            // Filter bits
    static const uint8_t F22R2_FB19 = 19;            // Filter bits
    static const uint8_t F22R2_FB20 = 20;            // Filter bits
    static const uint8_t F22R2_FB21 = 21;            // Filter bits
    static const uint8_t F22R2_FB22 = 22;            // Filter bits
    static const uint8_t F22R2_FB23 = 23;            // Filter bits
    static const uint8_t F22R2_FB24 = 24;            // Filter bits
    static const uint8_t F22R2_FB25 = 25;            // Filter bits
    static const uint8_t F22R2_FB26 = 26;            // Filter bits
    static const uint8_t F22R2_FB27 = 27;            // Filter bits
    static const uint8_t F22R2_FB28 = 28;            // Filter bits
    static const uint8_t F22R2_FB29 = 29;            // Filter bits
    static const uint8_t F22R2_FB30 = 30;            // Filter bits
    static const uint8_t F22R2_FB31 = 31;            // Filter bits
    static const uint32_t F22R2_RESET_VALUE = 0x0;

    static const uint8_t F23R1_FB0 = 0;              // Filter bits
    static const uint8_t F23R1_FB1 = 1;              // Filter bits
    static const uint8_t F23R1_FB2 = 2;              // Filter bits
    static const uint8_t F23R1_FB3 = 3;              // Filter bits
    static const uint8_t F23R1_FB4 = 4;              // Filter bits
    static const uint8_t F23R1_FB5 = 5;              // Filter bits
    static const uint8_t F23R1_FB6 = 6;              // Filter bits
    static const uint8_t F23R1_FB7 = 7;              // Filter bits
    static const uint8_t F23R1_FB8 = 8;              // Filter bits
    static const uint8_t F23R1_FB9 = 9;              // Filter bits
    static const uint8_t F23R1_FB10 = 10;            // Filter bits
    static const uint8_t F23R1_FB11 = 11;            // Filter bits
    static const uint8_t F23R1_FB12 = 12;            // Filter bits
    static const uint8_t F23R1_FB13 = 13;            // Filter bits
    static const uint8_t F23R1_FB14 = 14;            // Filter bits
    static const uint8_t F23R1_FB15 = 15;            // Filter bits
    static const uint8_t F23R1_FB16 = 16;            // Filter bits
    static const uint8_t F23R1_FB17 = 17;            // Filter bits
    static const uint8_t F23R1_FB18 = 18;            // Filter bits
    static const uint8_t F23R1_FB19 = 19;            // Filter bits
    static const uint8_t F23R1_FB20 = 20;            // Filter bits
    static const uint8_t F23R1_FB21 = 21;            // Filter bits
    static const uint8_t F23R1_FB22 = 22;            // Filter bits
    static const uint8_t F23R1_FB23 = 23;            // Filter bits
    static const uint8_t F23R1_FB24 = 24;            // Filter bits
    static const uint8_t F23R1_FB25 = 25;            // Filter bits
    static const uint8_t F23R1_FB26 = 26;            // Filter bits
    static const uint8_t F23R1_FB27 = 27;            // Filter bits
    static const uint8_t F23R1_FB28 = 28;            // Filter bits
    static const uint8_t F23R1_FB29 = 29;            // Filter bits
    static const uint8_t F23R1_FB30 = 30;            // Filter bits
    static const uint8_t F23R1_FB31 = 31;            // Filter bits
    static const uint32_t F23R1_RESET_VALUE = 0x0;

    static const uint8_t F23R2_FB0 = 0;              // Filter bits
    static const uint8_t F23R2_FB1 = 1;              // Filter bits
    static const uint8_t F23R2_FB2 = 2;              // Filter bits
    static const uint8_t F23R2_FB3 = 3;              // Filter bits
    static const uint8_t F23R2_FB4 = 4;              // Filter bits
    static const uint8_t F23R2_FB5 = 5;              // Filter bits
    static const uint8_t F23R2_FB6 = 6;              // Filter bits
    static const uint8_t F23R2_FB7 = 7;              // Filter bits
    static const uint8_t F23R2_FB8 = 8;              // Filter bits
    static const uint8_t F23R2_FB9 = 9;              // Filter bits
    static const uint8_t F23R2_FB10 = 10;            // Filter bits
    static const uint8_t F23R2_FB11 = 11;            // Filter bits
    static const uint8_t F23R2_FB12 = 12;            // Filter bits
    static const uint8_t F23R2_FB13 = 13;            // Filter bits
    static const uint8_t F23R2_FB14 = 14;            // Filter bits
    static const uint8_t F23R2_FB15 = 15;            // Filter bits
    static const uint8_t F23R2_FB16 = 16;            // Filter bits
    static const uint8_t F23R2_FB17 = 17;            // Filter bits
    static const uint8_t F23R2_FB18 = 18;            // Filter bits
    static const uint8_t F23R2_FB19 = 19;            // Filter bits
    static const uint8_t F23R2_FB20 = 20;            // Filter bits
    static const uint8_t F23R2_FB21 = 21;            // Filter bits
    static const uint8_t F23R2_FB22 = 22;            // Filter bits
    static const uint8_t F23R2_FB23 = 23;            // Filter bits
    static const uint8_t F23R2_FB24 = 24;            // Filter bits
    static const uint8_t F23R2_FB25 = 25;            // Filter bits
    static const uint8_t F23R2_FB26 = 26;            // Filter bits
    static const uint8_t F23R2_FB27 = 27;            // Filter bits
    static const uint8_t F23R2_FB28 = 28;            // Filter bits
    static const uint8_t F23R2_FB29 = 29;            // Filter bits
    static const uint8_t F23R2_FB30 = 30;            // Filter bits
    static const uint8_t F23R2_FB31 = 31;            // Filter bits
    static const uint32_t F23R2_RESET_VALUE = 0x0;

    static const uint8_t F24R1_FB0 = 0;              // Filter bits
    static const uint8_t F24R1_FB1 = 1;              // Filter bits
    static const uint8_t F24R1_FB2 = 2;              // Filter bits
    static const uint8_t F24R1_FB3 = 3;              // Filter bits
    static const uint8_t F24R1_FB4 = 4;              // Filter bits
    static const uint8_t F24R1_FB5 = 5;              // Filter bits
    static const uint8_t F24R1_FB6 = 6;              // Filter bits
    static const uint8_t F24R1_FB7 = 7;              // Filter bits
    static const uint8_t F24R1_FB8 = 8;              // Filter bits
    static const uint8_t F24R1_FB9 = 9;              // Filter bits
    static const uint8_t F24R1_FB10 = 10;            // Filter bits
    static const uint8_t F24R1_FB11 = 11;            // Filter bits
    static const uint8_t F24R1_FB12 = 12;            // Filter bits
    static const uint8_t F24R1_FB13 = 13;            // Filter bits
    static const uint8_t F24R1_FB14 = 14;            // Filter bits
    static const uint8_t F24R1_FB15 = 15;            // Filter bits
    static const uint8_t F24R1_FB16 = 16;            // Filter bits
    static const uint8_t F24R1_FB17 = 17;            // Filter bits
    static const uint8_t F24R1_FB18 = 18;            // Filter bits
    static const uint8_t F24R1_FB19 = 19;            // Filter bits
    static const uint8_t F24R1_FB20 = 20;            // Filter bits
    static const uint8_t F24R1_FB21 = 21;            // Filter bits
    static const uint8_t F24R1_FB22 = 22;            // Filter bits
    static const uint8_t F24R1_FB23 = 23;            // Filter bits
    static const uint8_t F24R1_FB24 = 24;            // Filter bits
    static const uint8_t F24R1_FB25 = 25;            // Filter bits
    static const uint8_t F24R1_FB26 = 26;            // Filter bits
    static const uint8_t F24R1_FB27 = 27;            // Filter bits
    static const uint8_t F24R1_FB28 = 28;            // Filter bits
    static const uint8_t F24R1_FB29 = 29;            // Filter bits
    static const uint8_t F24R1_FB30 = 30;            // Filter bits
    static const uint8_t F24R1_FB31 = 31;            // Filter bits
    static const uint32_t F24R1_RESET_VALUE = 0x0;

    static const uint8_t F24R2_FB0 = 0;              // Filter bits
    static const uint8_t F24R2_FB1 = 1;              // Filter bits
    static const uint8_t F24R2_FB2 = 2;              // Filter bits
    static const uint8_t F24R2_FB3 = 3;              // Filter bits
    static const uint8_t F24R2_FB4 = 4;              // Filter bits
    static const uint8_t F24R2_FB5 = 5;              // Filter bits
    static const uint8_t F24R2_FB6 = 6;              // Filter bits
    static const uint8_t F24R2_FB7 = 7;              // Filter bits
    static const uint8_t F24R2_FB8 = 8;              // Filter bits
    static const uint8_t F24R2_FB9 = 9;              // Filter bits
    static const uint8_t F24R2_FB10 = 10;            // Filter bits
    static const uint8_t F24R2_FB11 = 11;            // Filter bits
    static const uint8_t F24R2_FB12 = 12;            // Filter bits
    static const uint8_t F24R2_FB13 = 13;            // Filter bits
    static const uint8_t F24R2_FB14 = 14;            // Filter bits
    static const uint8_t F24R2_FB15 = 15;            // Filter bits
    static const uint8_t F24R2_FB16 = 16;            // Filter bits
    static const uint8_t F24R2_FB17 = 17;            // Filter bits
    static const uint8_t F24R2_FB18 = 18;            // Filter bits
    static const uint8_t F24R2_FB19 = 19;            // Filter bits
    static const uint8_t F24R2_FB20 = 20;            // Filter bits
    static const uint8_t F24R2_FB21 = 21;            // Filter bits
    static const uint8_t F24R2_FB22 = 22;            // Filter bits
    static const uint8_t F24R2_FB23 = 23;            // Filter bits
    static const uint8_t F24R2_FB24 = 24;            // Filter bits
    static const uint8_t F24R2_FB25 = 25;            // Filter bits
    static const uint8_t F24R2_FB26 = 26;            // Filter bits
    static const uint8_t F24R2_FB27 = 27;            // Filter bits
    static const uint8_t F24R2_FB28 = 28;            // Filter bits
    static const uint8_t F24R2_FB29 = 29;            // Filter bits
    static const uint8_t F24R2_FB30 = 30;            // Filter bits
    static const uint8_t F24R2_FB31 = 31;            // Filter bits
    static const uint32_t F24R2_RESET_VALUE = 0x0;

    static const uint8_t F25R1_FB0 = 0;              // Filter bits
    static const uint8_t F25R1_FB1 = 1;              // Filter bits
    static const uint8_t F25R1_FB2 = 2;              // Filter bits
    static const uint8_t F25R1_FB3 = 3;              // Filter bits
    static const uint8_t F25R1_FB4 = 4;              // Filter bits
    static const uint8_t F25R1_FB5 = 5;              // Filter bits
    static const uint8_t F25R1_FB6 = 6;              // Filter bits
    static const uint8_t F25R1_FB7 = 7;              // Filter bits
    static const uint8_t F25R1_FB8 = 8;              // Filter bits
    static const uint8_t F25R1_FB9 = 9;              // Filter bits
    static const uint8_t F25R1_FB10 = 10;            // Filter bits
    static const uint8_t F25R1_FB11 = 11;            // Filter bits
    static const uint8_t F25R1_FB12 = 12;            // Filter bits
    static const uint8_t F25R1_FB13 = 13;            // Filter bits
    static const uint8_t F25R1_FB14 = 14;            // Filter bits
    static const uint8_t F25R1_FB15 = 15;            // Filter bits
    static const uint8_t F25R1_FB16 = 16;            // Filter bits
    static const uint8_t F25R1_FB17 = 17;            // Filter bits
    static const uint8_t F25R1_FB18 = 18;            // Filter bits
    static const uint8_t F25R1_FB19 = 19;            // Filter bits
    static const uint8_t F25R1_FB20 = 20;            // Filter bits
    static const uint8_t F25R1_FB21 = 21;            // Filter bits
    static const uint8_t F25R1_FB22 = 22;            // Filter bits
    static const uint8_t F25R1_FB23 = 23;            // Filter bits
    static const uint8_t F25R1_FB24 = 24;            // Filter bits
    static const uint8_t F25R1_FB25 = 25;            // Filter bits
    static const uint8_t F25R1_FB26 = 26;            // Filter bits
    static const uint8_t F25R1_FB27 = 27;            // Filter bits
    static const uint8_t F25R1_FB28 = 28;            // Filter bits
    static const uint8_t F25R1_FB29 = 29;            // Filter bits
    static const uint8_t F25R1_FB30 = 30;            // Filter bits
    static const uint8_t F25R1_FB31 = 31;            // Filter bits
    static const uint32_t F25R1_RESET_VALUE = 0x0;

    static const uint8_t F25R2_FB0 = 0;              // Filter bits
    static const uint8_t F25R2_FB1 = 1;              // Filter bits
    static const uint8_t F25R2_FB2 = 2;              // Filter bits
    static const uint8_t F25R2_FB3 = 3;              // Filter bits
    static const uint8_t F25R2_FB4 = 4;              // Filter bits
    static const uint8_t F25R2_FB5 = 5;              // Filter bits
    static const uint8_t F25R2_FB6 = 6;              // Filter bits
    static const uint8_t F25R2_FB7 = 7;              // Filter bits
    static const uint8_t F25R2_FB8 = 8;              // Filter bits
    static const uint8_t F25R2_FB9 = 9;              // Filter bits
    static const uint8_t F25R2_FB10 = 10;            // Filter bits
    static const uint8_t F25R2_FB11 = 11;            // Filter bits
    static const uint8_t F25R2_FB12 = 12;            // Filter bits
    static const uint8_t F25R2_FB13 = 13;            // Filter bits
    static const uint8_t F25R2_FB14 = 14;            // Filter bits
    static const uint8_t F25R2_FB15 = 15;            // Filter bits
    static const uint8_t F25R2_FB16 = 16;            // Filter bits
    static const uint8_t F25R2_FB17 = 17;            // Filter bits
    static const uint8_t F25R2_FB18 = 18;            // Filter bits
    static const uint8_t F25R2_FB19 = 19;            // Filter bits
    static const uint8_t F25R2_FB20 = 20;            // Filter bits
    static const uint8_t F25R2_FB21 = 21;            // Filter bits
    static const uint8_t F25R2_FB22 = 22;            // Filter bits
    static const uint8_t F25R2_FB23 = 23;            // Filter bits
    static const uint8_t F25R2_FB24 = 24;            // Filter bits
    static const uint8_t F25R2_FB25 = 25;            // Filter bits
    static const uint8_t F25R2_FB26 = 26;            // Filter bits
    static const uint8_t F25R2_FB27 = 27;            // Filter bits
    static const uint8_t F25R2_FB28 = 28;            // Filter bits
    static const uint8_t F25R2_FB29 = 29;            // Filter bits
    static const uint8_t F25R2_FB30 = 30;            // Filter bits
    static const uint8_t F25R2_FB31 = 31;            // Filter bits
    static const uint32_t F25R2_RESET_VALUE = 0x0;

    static const uint8_t F26R1_FB0 = 0;              // Filter bits
    static const uint8_t F26R1_FB1 = 1;              // Filter bits
    static const uint8_t F26R1_FB2 = 2;              // Filter bits
    static const uint8_t F26R1_FB3 = 3;              // Filter bits
    static const uint8_t F26R1_FB4 = 4;              // Filter bits
    static const uint8_t F26R1_FB5 = 5;              // Filter bits
    static const uint8_t F26R1_FB6 = 6;              // Filter bits
    static const uint8_t F26R1_FB7 = 7;              // Filter bits
    static const uint8_t F26R1_FB8 = 8;              // Filter bits
    static const uint8_t F26R1_FB9 = 9;              // Filter bits
    static const uint8_t F26R1_FB10 = 10;            // Filter bits
    static const uint8_t F26R1_FB11 = 11;            // Filter bits
    static const uint8_t F26R1_FB12 = 12;            // Filter bits
    static const uint8_t F26R1_FB13 = 13;            // Filter bits
    static const uint8_t F26R1_FB14 = 14;            // Filter bits
    static const uint8_t F26R1_FB15 = 15;            // Filter bits
    static const uint8_t F26R1_FB16 = 16;            // Filter bits
    static const uint8_t F26R1_FB17 = 17;            // Filter bits
    static const uint8_t F26R1_FB18 = 18;            // Filter bits
    static const uint8_t F26R1_FB19 = 19;            // Filter bits
    static const uint8_t F26R1_FB20 = 20;            // Filter bits
    static const uint8_t F26R1_FB21 = 21;            // Filter bits
    static const uint8_t F26R1_FB22 = 22;            // Filter bits
    static const uint8_t F26R1_FB23 = 23;            // Filter bits
    static const uint8_t F26R1_FB24 = 24;            // Filter bits
    static const uint8_t F26R1_FB25 = 25;            // Filter bits
    static const uint8_t F26R1_FB26 = 26;            // Filter bits
    static const uint8_t F26R1_FB27 = 27;            // Filter bits
    static const uint8_t F26R1_FB28 = 28;            // Filter bits
    static const uint8_t F26R1_FB29 = 29;            // Filter bits
    static const uint8_t F26R1_FB30 = 30;            // Filter bits
    static const uint8_t F26R1_FB31 = 31;            // Filter bits
    static const uint32_t F26R1_RESET_VALUE = 0x0;

    static const uint8_t F26R2_FB0 = 0;              // Filter bits
    static const uint8_t F26R2_FB1 = 1;              // Filter bits
    static const uint8_t F26R2_FB2 = 2;              // Filter bits
    static const uint8_t F26R2_FB3 = 3;              // Filter bits
    static const uint8_t F26R2_FB4 = 4;              // Filter bits
    static const uint8_t F26R2_FB5 = 5;              // Filter bits
    static const uint8_t F26R2_FB6 = 6;              // Filter bits
    static const uint8_t F26R2_FB7 = 7;              // Filter bits
    static const uint8_t F26R2_FB8 = 8;              // Filter bits
    static const uint8_t F26R2_FB9 = 9;              // Filter bits
    static const uint8_t F26R2_FB10 = 10;            // Filter bits
    static const uint8_t F26R2_FB11 = 11;            // Filter bits
    static const uint8_t F26R2_FB12 = 12;            // Filter bits
    static const uint8_t F26R2_FB13 = 13;            // Filter bits
    static const uint8_t F26R2_FB14 = 14;            // Filter bits
    static const uint8_t F26R2_FB15 = 15;            // Filter bits
    static const uint8_t F26R2_FB16 = 16;            // Filter bits
    static const uint8_t F26R2_FB17 = 17;            // Filter bits
    static const uint8_t F26R2_FB18 = 18;            // Filter bits
    static const uint8_t F26R2_FB19 = 19;            // Filter bits
    static const uint8_t F26R2_FB20 = 20;            // Filter bits
    static const uint8_t F26R2_FB21 = 21;            // Filter bits
    static const uint8_t F26R2_FB22 = 22;            // Filter bits
    static const uint8_t F26R2_FB23 = 23;            // Filter bits
    static const uint8_t F26R2_FB24 = 24;            // Filter bits
    static const uint8_t F26R2_FB25 = 25;            // Filter bits
    static const uint8_t F26R2_FB26 = 26;            // Filter bits
    static const uint8_t F26R2_FB27 = 27;            // Filter bits
    static const uint8_t F26R2_FB28 = 28;            // Filter bits
    static const uint8_t F26R2_FB29 = 29;            // Filter bits
    static const uint8_t F26R2_FB30 = 30;            // Filter bits
    static const uint8_t F26R2_FB31 = 31;            // Filter bits
    static const uint32_t F26R2_RESET_VALUE = 0x0;

    static const uint8_t F27R1_FB0 = 0;              // Filter bits
    static const uint8_t F27R1_FB1 = 1;              // Filter bits
    static const uint8_t F27R1_FB2 = 2;              // Filter bits
    static const uint8_t F27R1_FB3 = 3;              // Filter bits
    static const uint8_t F27R1_FB4 = 4;              // Filter bits
    static const uint8_t F27R1_FB5 = 5;              // Filter bits
    static const uint8_t F27R1_FB6 = 6;              // Filter bits
    static const uint8_t F27R1_FB7 = 7;              // Filter bits
    static const uint8_t F27R1_FB8 = 8;              // Filter bits
    static const uint8_t F27R1_FB9 = 9;              // Filter bits
    static const uint8_t F27R1_FB10 = 10;            // Filter bits
    static const uint8_t F27R1_FB11 = 11;            // Filter bits
    static const uint8_t F27R1_FB12 = 12;            // Filter bits
    static const uint8_t F27R1_FB13 = 13;            // Filter bits
    static const uint8_t F27R1_FB14 = 14;            // Filter bits
    static const uint8_t F27R1_FB15 = 15;            // Filter bits
    static const uint8_t F27R1_FB16 = 16;            // Filter bits
    static const uint8_t F27R1_FB17 = 17;            // Filter bits
    static const uint8_t F27R1_FB18 = 18;            // Filter bits
    static const uint8_t F27R1_FB19 = 19;            // Filter bits
    static const uint8_t F27R1_FB20 = 20;            // Filter bits
    static const uint8_t F27R1_FB21 = 21;            // Filter bits
    static const uint8_t F27R1_FB22 = 22;            // Filter bits
    static const uint8_t F27R1_FB23 = 23;            // Filter bits
    static const uint8_t F27R1_FB24 = 24;            // Filter bits
    static const uint8_t F27R1_FB25 = 25;            // Filter bits
    static const uint8_t F27R1_FB26 = 26;            // Filter bits
    static const uint8_t F27R1_FB27 = 27;            // Filter bits
    static const uint8_t F27R1_FB28 = 28;            // Filter bits
    static const uint8_t F27R1_FB29 = 29;            // Filter bits
    static const uint8_t F27R1_FB30 = 30;            // Filter bits
    static const uint8_t F27R1_FB31 = 31;            // Filter bits
    static const uint32_t F27R1_RESET_VALUE = 0x0;

    static const uint8_t F27R2_FB0 = 0;              // Filter bits
    static const uint8_t F27R2_FB1 = 1;              // Filter bits
    static const uint8_t F27R2_FB2 = 2;              // Filter bits
    static const uint8_t F27R2_FB3 = 3;              // Filter bits
    static const uint8_t F27R2_FB4 = 4;              // Filter bits
    static const uint8_t F27R2_FB5 = 5;              // Filter bits
    static const uint8_t F27R2_FB6 = 6;              // Filter bits
    static const uint8_t F27R2_FB7 = 7;              // Filter bits
    static const uint8_t F27R2_FB8 = 8;              // Filter bits
    static const uint8_t F27R2_FB9 = 9;              // Filter bits
    static const uint8_t F27R2_FB10 = 10;            // Filter bits
    static const uint8_t F27R2_FB11 = 11;            // Filter bits
    static const uint8_t F27R2_FB12 = 12;            // Filter bits
    static const uint8_t F27R2_FB13 = 13;            // Filter bits
    static const uint8_t F27R2_FB14 = 14;            // Filter bits
    static const uint8_t F27R2_FB15 = 15;            // Filter bits
    static const uint8_t F27R2_FB16 = 16;            // Filter bits
    static const uint8_t F27R2_FB17 = 17;            // Filter bits
    static const uint8_t F27R2_FB18 = 18;            // Filter bits
    static const uint8_t F27R2_FB19 = 19;            // Filter bits
    static const uint8_t F27R2_FB20 = 20;            // Filter bits
    static const uint8_t F27R2_FB21 = 21;            // Filter bits
    static const uint8_t F27R2_FB22 = 22;            // Filter bits
    static const uint8_t F27R2_FB23 = 23;            // Filter bits
    static const uint8_t F27R2_FB24 = 24;            // Filter bits
    static const uint8_t F27R2_FB25 = 25;            // Filter bits
    static const uint8_t F27R2_FB26 = 26;            // Filter bits
    static const uint8_t F27R2_FB27 = 27;            // Filter bits
    static const uint8_t F27R2_FB28 = 28;            // Filter bits
    static const uint8_t F27R2_FB29 = 29;            // Filter bits
    static const uint8_t F27R2_FB30 = 30;            // Filter bits
    static const uint8_t F27R2_FB31 = 31;            // Filter bits
    static const uint32_t F27R2_RESET_VALUE = 0x0;
};

static can1_t& CAN1 = *reinterpret_cast<can1_t*>(0x40006400);


////
//
//    Controller area network
//
////

struct can2_t
{
    volatile uint32_t    MCR;                  // [Read-write] master control register
    volatile uint32_t    MSR;                  // master status register
    volatile uint32_t    TSR;                  // transmit status register
    volatile uint32_t    RF0R;                 // receive FIFO 0 register
    volatile uint32_t    RF1R;                 // receive FIFO 1 register
    volatile uint32_t    IER;                  // [Read-write] interrupt enable register
    volatile uint32_t    ESR;                  // interrupt enable register
    volatile uint32_t    BTR;                  // [Read-write] bit timing register
    reserved_t<88>       _0;
    volatile uint32_t    TI0R;                 // [Read-write] TX mailbox identifier register
    volatile uint32_t    TDT0R;                // [Read-write] mailbox data length control and time stamp register
    volatile uint32_t    TDL0R;                // [Read-write] mailbox data low register
    volatile uint32_t    TDH0R;                // [Read-write] mailbox data high register
    volatile uint32_t    TI1R;                 // [Read-write] mailbox identifier register
    volatile uint32_t    TDT1R;                // [Read-write] mailbox data length control and time stamp register
    volatile uint32_t    TDL1R;                // [Read-write] mailbox data low register
    volatile uint32_t    TDH1R;                // [Read-write] mailbox data high register
    volatile uint32_t    TI2R;                 // [Read-write] mailbox identifier register
    volatile uint32_t    TDT2R;                // [Read-write] mailbox data length control and time stamp register
    volatile uint32_t    TDL2R;                // [Read-write] mailbox data low register
    volatile uint32_t    TDH2R;                // [Read-write] mailbox data high register
    volatile uint32_t    RI0R;                 // [Read-only] receive FIFO mailbox identifier register
    volatile uint32_t    RDT0R;                // [Read-only] mailbox data high register
    volatile uint32_t    RDL0R;                // [Read-only] mailbox data high register
    volatile uint32_t    RDH0R;                // [Read-only] receive FIFO mailbox data high register
    volatile uint32_t    RI1R;                 // [Read-only] mailbox data high register
    volatile uint32_t    RDT1R;                // [Read-only] mailbox data high register
    volatile uint32_t    RDL1R;                // [Read-only] mailbox data high register
    volatile uint32_t    RDH1R;                // [Read-only] mailbox data high register
    reserved_t<12>       _1;
    volatile uint32_t    FMR;                  // [Read-write] filter master register
    volatile uint32_t    FM1R;                 // [Read-write] filter mode register
    reserved_t<1>        _2;
    volatile uint32_t    FS1R;                 // [Read-write] filter scale register
    reserved_t<1>        _3;
    volatile uint32_t    FFA1R;                // [Read-write] filter FIFO assignment register
    reserved_t<1>        _4;
    volatile uint32_t    FA1R;                 // [Read-write] filter activation register
    reserved_t<8>        _5;
    volatile uint32_t    F0R1;                 // [Read-write] Filter bank 0 register 1
    volatile uint32_t    F0R2;                 // [Read-write] Filter bank 0 register 2
    volatile uint32_t    F1R1;                 // [Read-write] Filter bank 1 register 1
    volatile uint32_t    F1R2;                 // [Read-write] Filter bank 1 register 2
    volatile uint32_t    F2R1;                 // [Read-write] Filter bank 2 register 1
    volatile uint32_t    F2R2;                 // [Read-write] Filter bank 2 register 2
    volatile uint32_t    F3R1;                 // [Read-write] Filter bank 3 register 1
    volatile uint32_t    F3R2;                 // [Read-write] Filter bank 3 register 2
    volatile uint32_t    F4R1;                 // [Read-write] Filter bank 4 register 1
    volatile uint32_t    F4R2;                 // [Read-write] Filter bank 4 register 2
    volatile uint32_t    F5R1;                 // [Read-write] Filter bank 5 register 1
    volatile uint32_t    F5R2;                 // [Read-write] Filter bank 5 register 2
    volatile uint32_t    F6R1;                 // [Read-write] Filter bank 6 register 1
    volatile uint32_t    F6R2;                 // [Read-write] Filter bank 6 register 2
    volatile uint32_t    F7R1;                 // [Read-write] Filter bank 7 register 1
    volatile uint32_t    F7R2;                 // [Read-write] Filter bank 7 register 2
    volatile uint32_t    F8R1;                 // [Read-write] Filter bank 8 register 1
    volatile uint32_t    F8R2;                 // [Read-write] Filter bank 8 register 2
    volatile uint32_t    F9R1;                 // [Read-write] Filter bank 9 register 1
    volatile uint32_t    F9R2;                 // [Read-write] Filter bank 9 register 2
    volatile uint32_t    F10R1;                // [Read-write] Filter bank 10 register 1
    volatile uint32_t    F10R2;                // [Read-write] Filter bank 10 register 2
    volatile uint32_t    F11R1;                // [Read-write] Filter bank 11 register 1
    volatile uint32_t    F11R2;                // [Read-write] Filter bank 11 register 2
    volatile uint32_t    F12R1;                // [Read-write] Filter bank 4 register 1
    volatile uint32_t    F12R2;                // [Read-write] Filter bank 12 register 2
    volatile uint32_t    F13R1;                // [Read-write] Filter bank 13 register 1
    volatile uint32_t    F13R2;                // [Read-write] Filter bank 13 register 2
    volatile uint32_t    F14R1;                // [Read-write] Filter bank 14 register 1
    volatile uint32_t    F14R2;                // [Read-write] Filter bank 14 register 2
    volatile uint32_t    F15R1;                // [Read-write] Filter bank 15 register 1
    volatile uint32_t    F15R2;                // [Read-write] Filter bank 15 register 2
    volatile uint32_t    F16R1;                // [Read-write] Filter bank 16 register 1
    volatile uint32_t    F16R2;                // [Read-write] Filter bank 16 register 2
    volatile uint32_t    F17R1;                // [Read-write] Filter bank 17 register 1
    volatile uint32_t    F17R2;                // [Read-write] Filter bank 17 register 2
    volatile uint32_t    F18R1;                // [Read-write] Filter bank 18 register 1
    volatile uint32_t    F18R2;                // [Read-write] Filter bank 18 register 2
    volatile uint32_t    F19R1;                // [Read-write] Filter bank 19 register 1
    volatile uint32_t    F19R2;                // [Read-write] Filter bank 19 register 2
    volatile uint32_t    F20R1;                // [Read-write] Filter bank 20 register 1
    volatile uint32_t    F20R2;                // [Read-write] Filter bank 20 register 2
    volatile uint32_t    F21R1;                // [Read-write] Filter bank 21 register 1
    volatile uint32_t    F21R2;                // [Read-write] Filter bank 21 register 2
    volatile uint32_t    F22R1;                // [Read-write] Filter bank 22 register 1
    volatile uint32_t    F22R2;                // [Read-write] Filter bank 22 register 2
    volatile uint32_t    F23R1;                // [Read-write] Filter bank 23 register 1
    volatile uint32_t    F23R2;                // [Read-write] Filter bank 23 register 2
    volatile uint32_t    F24R1;                // [Read-write] Filter bank 24 register 1
    volatile uint32_t    F24R2;                // [Read-write] Filter bank 24 register 2
    volatile uint32_t    F25R1;                // [Read-write] Filter bank 25 register 1
    volatile uint32_t    F25R2;                // [Read-write] Filter bank 25 register 2
    volatile uint32_t    F26R1;                // [Read-write] Filter bank 26 register 1
    volatile uint32_t    F26R2;                // [Read-write] Filter bank 26 register 2
    volatile uint32_t    F27R1;                // [Read-write] Filter bank 27 register 1
    volatile uint32_t    F27R2;                // [Read-write] Filter bank 27 register 2

    static const uint8_t MCR_DBF = 16;             // DBF
    static const uint8_t MCR_RESET = 15;           // RESET
    static const uint8_t MCR_TTCM = 7;             // TTCM
    static const uint8_t MCR_ABOM = 6;             // ABOM
    static const uint8_t MCR_AWUM = 5;             // AWUM
    static const uint8_t MCR_NART = 4;             // NART
    static const uint8_t MCR_RFLM = 3;             // RFLM
    static const uint8_t MCR_TXFP = 2;             // TXFP
    static const uint8_t MCR_SLEEP = 1;            // SLEEP
    static const uint8_t MCR_INRQ = 0;             // INRQ
    static const uint32_t MCR_RESET_VALUE = 0x10002;

    static const uint8_t MSR_RX = 11;              // RX, Read-only
    static const uint8_t MSR_SAMP = 10;            // SAMP, Read-only
    static const uint8_t MSR_RXM = 9;              // RXM, Read-only
    static const uint8_t MSR_TXM = 8;              // TXM, Read-only
    static const uint8_t MSR_SLAKI = 4;            // SLAKI, Read-write
    static const uint8_t MSR_WKUI = 3;             // WKUI, Read-write
    static const uint8_t MSR_ERRI = 2;             // ERRI, Read-write
    static const uint8_t MSR_SLAK = 1;             // SLAK, Read-only
    static const uint8_t MSR_INAK = 0;             // INAK, Read-only
    static const uint32_t MSR_RESET_VALUE = 0xc02;

    static const uint8_t TSR_LOW2 = 31;            // Lowest priority flag for mailbox 2, Read-only
    static const uint8_t TSR_LOW1 = 30;            // Lowest priority flag for mailbox 1, Read-only
    static const uint8_t TSR_LOW0 = 29;            // Lowest priority flag for mailbox 0, Read-only
    static const uint8_t TSR_TME2 = 28;            // Lowest priority flag for mailbox 2, Read-only
    static const uint8_t TSR_TME1 = 27;            // Lowest priority flag for mailbox 1, Read-only
    static const uint8_t TSR_TME0 = 26;            // Lowest priority flag for mailbox 0, Read-only
    static const uint8_t TSR_CODE = 24;            // CODE (2 bits), Read-only
    static const uint8_t TSR_ABRQ2 = 23;           // ABRQ2, Read-write
    static const uint8_t TSR_TERR2 = 19;           // TERR2, Read-write
    static const uint8_t TSR_ALST2 = 18;           // ALST2, Read-write
    static const uint8_t TSR_TXOK2 = 17;           // TXOK2, Read-write
    static const uint8_t TSR_RQCP2 = 16;           // RQCP2, Read-write
    static const uint8_t TSR_ABRQ1 = 15;           // ABRQ1, Read-write
    static const uint8_t TSR_TERR1 = 11;           // TERR1, Read-write
    static const uint8_t TSR_ALST1 = 10;           // ALST1, Read-write
    static const uint8_t TSR_TXOK1 = 9;            // TXOK1, Read-write
    static const uint8_t TSR_RQCP1 = 8;            // RQCP1, Read-write
    static const uint8_t TSR_ABRQ0 = 7;            // ABRQ0, Read-write
    static const uint8_t TSR_TERR0 = 3;            // TERR0, Read-write
    static const uint8_t TSR_ALST0 = 2;            // ALST0, Read-write
    static const uint8_t TSR_TXOK0 = 1;            // TXOK0, Read-write
    static const uint8_t TSR_RQCP0 = 0;            // RQCP0, Read-write
    static const uint32_t TSR_RESET_VALUE = 0x1c000000;

    static const uint8_t RF0R_RFOM0 = 5;            // RFOM0, Read-write
    static const uint8_t RF0R_FOVR0 = 4;            // FOVR0, Read-write
    static const uint8_t RF0R_FULL0 = 3;            // FULL0, Read-write
    static const uint8_t RF0R_FMP0 = 0;             // FMP0 (2 bits), Read-only
    static const uint32_t RF0R_RESET_VALUE = 0x0;

    static const uint8_t RF1R_RFOM1 = 5;            // RFOM1, Read-write
    static const uint8_t RF1R_FOVR1 = 4;            // FOVR1, Read-write
    static const uint8_t RF1R_FULL1 = 3;            // FULL1, Read-write
    static const uint8_t RF1R_FMP1 = 0;             // FMP1 (2 bits), Read-only
    static const uint32_t RF1R_RESET_VALUE = 0x0;

    static const uint8_t IER_SLKIE = 17;           // SLKIE
    static const uint8_t IER_WKUIE = 16;           // WKUIE
    static const uint8_t IER_ERRIE = 15;           // ERRIE
    static const uint8_t IER_LECIE = 11;           // LECIE
    static const uint8_t IER_BOFIE = 10;           // BOFIE
    static const uint8_t IER_EPVIE = 9;            // EPVIE
    static const uint8_t IER_EWGIE = 8;            // EWGIE
    static const uint8_t IER_FOVIE1 = 6;           // FOVIE1
    static const uint8_t IER_FFIE1 = 5;            // FFIE1
    static const uint8_t IER_FMPIE1 = 4;           // FMPIE1
    static const uint8_t IER_FOVIE0 = 3;           // FOVIE0
    static const uint8_t IER_FFIE0 = 2;            // FFIE0
    static const uint8_t IER_FMPIE0 = 1;           // FMPIE0
    static const uint8_t IER_TMEIE = 0;            // TMEIE
    static const uint32_t IER_RESET_VALUE = 0x0;

    static const uint8_t ESR_REC = 24;             // REC (8 bits), Read-only
    static const uint8_t ESR_TEC = 16;             // TEC (8 bits), Read-only
    static const uint8_t ESR_LEC = 4;              // LEC (3 bits), Read-write
    static const uint8_t ESR_BOFF = 2;             // BOFF, Read-only
    static const uint8_t ESR_EPVF = 1;             // EPVF, Read-only
    static const uint8_t ESR_EWGF = 0;             // EWGF, Read-only
    static const uint32_t ESR_RESET_VALUE = 0x0;

    static const uint8_t BTR_SILM = 31;            // SILM
    static const uint8_t BTR_LBKM = 30;            // LBKM
    static const uint8_t BTR_SJW = 24;             // SJW (2 bits)
    static const uint8_t BTR_TS2 = 20;             // TS2 (3 bits)
    static const uint8_t BTR_TS1 = 16;             // TS1 (4 bits)
    static const uint8_t BTR_BRP = 0;              // BRP (10 bits)
    static const uint32_t BTR_RESET_VALUE = 0x0;

    static const uint8_t TI0R_STID = 21;            // STID (11 bits)
    static const uint8_t TI0R_EXID = 3;             // EXID (18 bits)
    static const uint8_t TI0R_IDE = 2;              // IDE
    static const uint8_t TI0R_RTR = 1;              // RTR
    static const uint8_t TI0R_TXRQ = 0;             // TXRQ
    static const uint32_t TI0R_RESET_VALUE = 0x0;

    static const uint8_t TDT0R_TIME = 16;            // TIME (16 bits)
    static const uint8_t TDT0R_TGT = 8;              // TGT
    static const uint8_t TDT0R_DLC = 0;              // DLC (4 bits)
    static const uint32_t TDT0R_RESET_VALUE = 0x0;

    static const uint8_t TDL0R_DATA3 = 24;           // DATA3 (8 bits)
    static const uint8_t TDL0R_DATA2 = 16;           // DATA2 (8 bits)
    static const uint8_t TDL0R_DATA1 = 8;            // DATA1 (8 bits)
    static const uint8_t TDL0R_DATA0 = 0;            // DATA0 (8 bits)
    static const uint32_t TDL0R_RESET_VALUE = 0x0;

    static const uint8_t TDH0R_DATA7 = 24;           // DATA7 (8 bits)
    static const uint8_t TDH0R_DATA6 = 16;           // DATA6 (8 bits)
    static const uint8_t TDH0R_DATA5 = 8;            // DATA5 (8 bits)
    static const uint8_t TDH0R_DATA4 = 0;            // DATA4 (8 bits)
    static const uint32_t TDH0R_RESET_VALUE = 0x0;

    static const uint8_t TI1R_STID = 21;            // STID (11 bits)
    static const uint8_t TI1R_EXID = 3;             // EXID (18 bits)
    static const uint8_t TI1R_IDE = 2;              // IDE
    static const uint8_t TI1R_RTR = 1;              // RTR
    static const uint8_t TI1R_TXRQ = 0;             // TXRQ
    static const uint32_t TI1R_RESET_VALUE = 0x0;

    static const uint8_t TDT1R_TIME = 16;            // TIME (16 bits)
    static const uint8_t TDT1R_TGT = 8;              // TGT
    static const uint8_t TDT1R_DLC = 0;              // DLC (4 bits)
    static const uint32_t TDT1R_RESET_VALUE = 0x0;

    static const uint8_t TDL1R_DATA3 = 24;           // DATA3 (8 bits)
    static const uint8_t TDL1R_DATA2 = 16;           // DATA2 (8 bits)
    static const uint8_t TDL1R_DATA1 = 8;            // DATA1 (8 bits)
    static const uint8_t TDL1R_DATA0 = 0;            // DATA0 (8 bits)
    static const uint32_t TDL1R_RESET_VALUE = 0x0;

    static const uint8_t TDH1R_DATA7 = 24;           // DATA7 (8 bits)
    static const uint8_t TDH1R_DATA6 = 16;           // DATA6 (8 bits)
    static const uint8_t TDH1R_DATA5 = 8;            // DATA5 (8 bits)
    static const uint8_t TDH1R_DATA4 = 0;            // DATA4 (8 bits)
    static const uint32_t TDH1R_RESET_VALUE = 0x0;

    static const uint8_t TI2R_STID = 21;            // STID (11 bits)
    static const uint8_t TI2R_EXID = 3;             // EXID (18 bits)
    static const uint8_t TI2R_IDE = 2;              // IDE
    static const uint8_t TI2R_RTR = 1;              // RTR
    static const uint8_t TI2R_TXRQ = 0;             // TXRQ
    static const uint32_t TI2R_RESET_VALUE = 0x0;

    static const uint8_t TDT2R_TIME = 16;            // TIME (16 bits)
    static const uint8_t TDT2R_TGT = 8;              // TGT
    static const uint8_t TDT2R_DLC = 0;              // DLC (4 bits)
    static const uint32_t TDT2R_RESET_VALUE = 0x0;

    static const uint8_t TDL2R_DATA3 = 24;           // DATA3 (8 bits)
    static const uint8_t TDL2R_DATA2 = 16;           // DATA2 (8 bits)
    static const uint8_t TDL2R_DATA1 = 8;            // DATA1 (8 bits)
    static const uint8_t TDL2R_DATA0 = 0;            // DATA0 (8 bits)
    static const uint32_t TDL2R_RESET_VALUE = 0x0;

    static const uint8_t TDH2R_DATA7 = 24;           // DATA7 (8 bits)
    static const uint8_t TDH2R_DATA6 = 16;           // DATA6 (8 bits)
    static const uint8_t TDH2R_DATA5 = 8;            // DATA5 (8 bits)
    static const uint8_t TDH2R_DATA4 = 0;            // DATA4 (8 bits)
    static const uint32_t TDH2R_RESET_VALUE = 0x0;

    static const uint8_t RI0R_STID = 21;            // STID (11 bits)
    static const uint8_t RI0R_EXID = 3;             // EXID (18 bits)
    static const uint8_t RI0R_IDE = 2;              // IDE
    static const uint8_t RI0R_RTR = 1;              // RTR
    static const uint32_t RI0R_RESET_VALUE = 0x0;

    static const uint8_t RDT0R_TIME = 16;            // TIME (16 bits)
    static const uint8_t RDT0R_FMI = 8;              // FMI (8 bits)
    static const uint8_t RDT0R_DLC = 0;              // DLC (4 bits)
    static const uint32_t RDT0R_RESET_VALUE = 0x0;

    static const uint8_t RDL0R_DATA3 = 24;           // DATA3 (8 bits)
    static const uint8_t RDL0R_DATA2 = 16;           // DATA2 (8 bits)
    static const uint8_t RDL0R_DATA1 = 8;            // DATA1 (8 bits)
    static const uint8_t RDL0R_DATA0 = 0;            // DATA0 (8 bits)
    static const uint32_t RDL0R_RESET_VALUE = 0x0;

    static const uint8_t RDH0R_DATA7 = 24;           // DATA7 (8 bits)
    static const uint8_t RDH0R_DATA6 = 16;           // DATA6 (8 bits)
    static const uint8_t RDH0R_DATA5 = 8;            // DATA5 (8 bits)
    static const uint8_t RDH0R_DATA4 = 0;            // DATA4 (8 bits)
    static const uint32_t RDH0R_RESET_VALUE = 0x0;

    static const uint8_t RI1R_STID = 21;            // STID (11 bits)
    static const uint8_t RI1R_EXID = 3;             // EXID (18 bits)
    static const uint8_t RI1R_IDE = 2;              // IDE
    static const uint8_t RI1R_RTR = 1;              // RTR
    static const uint32_t RI1R_RESET_VALUE = 0x0;

    static const uint8_t RDT1R_TIME = 16;            // TIME (16 bits)
    static const uint8_t RDT1R_FMI = 8;              // FMI (8 bits)
    static const uint8_t RDT1R_DLC = 0;              // DLC (4 bits)
    static const uint32_t RDT1R_RESET_VALUE = 0x0;

    static const uint8_t RDL1R_DATA3 = 24;           // DATA3 (8 bits)
    static const uint8_t RDL1R_DATA2 = 16;           // DATA2 (8 bits)
    static const uint8_t RDL1R_DATA1 = 8;            // DATA1 (8 bits)
    static const uint8_t RDL1R_DATA0 = 0;            // DATA0 (8 bits)
    static const uint32_t RDL1R_RESET_VALUE = 0x0;

    static const uint8_t RDH1R_DATA7 = 24;           // DATA7 (8 bits)
    static const uint8_t RDH1R_DATA6 = 16;           // DATA6 (8 bits)
    static const uint8_t RDH1R_DATA5 = 8;            // DATA5 (8 bits)
    static const uint8_t RDH1R_DATA4 = 0;            // DATA4 (8 bits)
    static const uint32_t RDH1R_RESET_VALUE = 0x0;

    static const uint8_t FMR_CAN2SB = 8;           // CAN2SB (6 bits)
    static const uint8_t FMR_FINIT = 0;            // FINIT
    static const uint32_t FMR_RESET_VALUE = 0x2a1c0e01;

    static const uint8_t FM1R_FBM0 = 0;             // Filter mode
    static const uint8_t FM1R_FBM1 = 1;             // Filter mode
    static const uint8_t FM1R_FBM2 = 2;             // Filter mode
    static const uint8_t FM1R_FBM3 = 3;             // Filter mode
    static const uint8_t FM1R_FBM4 = 4;             // Filter mode
    static const uint8_t FM1R_FBM5 = 5;             // Filter mode
    static const uint8_t FM1R_FBM6 = 6;             // Filter mode
    static const uint8_t FM1R_FBM7 = 7;             // Filter mode
    static const uint8_t FM1R_FBM8 = 8;             // Filter mode
    static const uint8_t FM1R_FBM9 = 9;             // Filter mode
    static const uint8_t FM1R_FBM10 = 10;           // Filter mode
    static const uint8_t FM1R_FBM11 = 11;           // Filter mode
    static const uint8_t FM1R_FBM12 = 12;           // Filter mode
    static const uint8_t FM1R_FBM13 = 13;           // Filter mode
    static const uint8_t FM1R_FBM14 = 14;           // Filter mode
    static const uint8_t FM1R_FBM15 = 15;           // Filter mode
    static const uint8_t FM1R_FBM16 = 16;           // Filter mode
    static const uint8_t FM1R_FBM17 = 17;           // Filter mode
    static const uint8_t FM1R_FBM18 = 18;           // Filter mode
    static const uint8_t FM1R_FBM19 = 19;           // Filter mode
    static const uint8_t FM1R_FBM20 = 20;           // Filter mode
    static const uint8_t FM1R_FBM21 = 21;           // Filter mode
    static const uint8_t FM1R_FBM22 = 22;           // Filter mode
    static const uint8_t FM1R_FBM23 = 23;           // Filter mode
    static const uint8_t FM1R_FBM24 = 24;           // Filter mode
    static const uint8_t FM1R_FBM25 = 25;           // Filter mode
    static const uint8_t FM1R_FBM26 = 26;           // Filter mode
    static const uint8_t FM1R_FBM27 = 27;           // Filter mode
    static const uint32_t FM1R_RESET_VALUE = 0x0;

    static const uint8_t FS1R_FSC0 = 0;             // Filter scale configuration
    static const uint8_t FS1R_FSC1 = 1;             // Filter scale configuration
    static const uint8_t FS1R_FSC2 = 2;             // Filter scale configuration
    static const uint8_t FS1R_FSC3 = 3;             // Filter scale configuration
    static const uint8_t FS1R_FSC4 = 4;             // Filter scale configuration
    static const uint8_t FS1R_FSC5 = 5;             // Filter scale configuration
    static const uint8_t FS1R_FSC6 = 6;             // Filter scale configuration
    static const uint8_t FS1R_FSC7 = 7;             // Filter scale configuration
    static const uint8_t FS1R_FSC8 = 8;             // Filter scale configuration
    static const uint8_t FS1R_FSC9 = 9;             // Filter scale configuration
    static const uint8_t FS1R_FSC10 = 10;           // Filter scale configuration
    static const uint8_t FS1R_FSC11 = 11;           // Filter scale configuration
    static const uint8_t FS1R_FSC12 = 12;           // Filter scale configuration
    static const uint8_t FS1R_FSC13 = 13;           // Filter scale configuration
    static const uint8_t FS1R_FSC14 = 14;           // Filter scale configuration
    static const uint8_t FS1R_FSC15 = 15;           // Filter scale configuration
    static const uint8_t FS1R_FSC16 = 16;           // Filter scale configuration
    static const uint8_t FS1R_FSC17 = 17;           // Filter scale configuration
    static const uint8_t FS1R_FSC18 = 18;           // Filter scale configuration
    static const uint8_t FS1R_FSC19 = 19;           // Filter scale configuration
    static const uint8_t FS1R_FSC20 = 20;           // Filter scale configuration
    static const uint8_t FS1R_FSC21 = 21;           // Filter scale configuration
    static const uint8_t FS1R_FSC22 = 22;           // Filter scale configuration
    static const uint8_t FS1R_FSC23 = 23;           // Filter scale configuration
    static const uint8_t FS1R_FSC24 = 24;           // Filter scale configuration
    static const uint8_t FS1R_FSC25 = 25;           // Filter scale configuration
    static const uint8_t FS1R_FSC26 = 26;           // Filter scale configuration
    static const uint8_t FS1R_FSC27 = 27;           // Filter scale configuration
    static const uint32_t FS1R_RESET_VALUE = 0x0;

    static const uint8_t FFA1R_FFA0 = 0;             // Filter FIFO assignment for filter 0
    static const uint8_t FFA1R_FFA1 = 1;             // Filter FIFO assignment for filter 1
    static const uint8_t FFA1R_FFA2 = 2;             // Filter FIFO assignment for filter 2
    static const uint8_t FFA1R_FFA3 = 3;             // Filter FIFO assignment for filter 3
    static const uint8_t FFA1R_FFA4 = 4;             // Filter FIFO assignment for filter 4
    static const uint8_t FFA1R_FFA5 = 5;             // Filter FIFO assignment for filter 5
    static const uint8_t FFA1R_FFA6 = 6;             // Filter FIFO assignment for filter 6
    static const uint8_t FFA1R_FFA7 = 7;             // Filter FIFO assignment for filter 7
    static const uint8_t FFA1R_FFA8 = 8;             // Filter FIFO assignment for filter 8
    static const uint8_t FFA1R_FFA9 = 9;             // Filter FIFO assignment for filter 9
    static const uint8_t FFA1R_FFA10 = 10;           // Filter FIFO assignment for filter 10
    static const uint8_t FFA1R_FFA11 = 11;           // Filter FIFO assignment for filter 11
    static const uint8_t FFA1R_FFA12 = 12;           // Filter FIFO assignment for filter 12
    static const uint8_t FFA1R_FFA13 = 13;           // Filter FIFO assignment for filter 13
    static const uint8_t FFA1R_FFA14 = 14;           // Filter FIFO assignment for filter 14
    static const uint8_t FFA1R_FFA15 = 15;           // Filter FIFO assignment for filter 15
    static const uint8_t FFA1R_FFA16 = 16;           // Filter FIFO assignment for filter 16
    static const uint8_t FFA1R_FFA17 = 17;           // Filter FIFO assignment for filter 17
    static const uint8_t FFA1R_FFA18 = 18;           // Filter FIFO assignment for filter 18
    static const uint8_t FFA1R_FFA19 = 19;           // Filter FIFO assignment for filter 19
    static const uint8_t FFA1R_FFA20 = 20;           // Filter FIFO assignment for filter 20
    static const uint8_t FFA1R_FFA21 = 21;           // Filter FIFO assignment for filter 21
    static const uint8_t FFA1R_FFA22 = 22;           // Filter FIFO assignment for filter 22
    static const uint8_t FFA1R_FFA23 = 23;           // Filter FIFO assignment for filter 23
    static const uint8_t FFA1R_FFA24 = 24;           // Filter FIFO assignment for filter 24
    static const uint8_t FFA1R_FFA25 = 25;           // Filter FIFO assignment for filter 25
    static const uint8_t FFA1R_FFA26 = 26;           // Filter FIFO assignment for filter 26
    static const uint8_t FFA1R_FFA27 = 27;           // Filter FIFO assignment for filter 27
    static const uint32_t FFA1R_RESET_VALUE = 0x0;

    static const uint8_t FA1R_FACT0 = 0;            // Filter active
    static const uint8_t FA1R_FACT1 = 1;            // Filter active
    static const uint8_t FA1R_FACT2 = 2;            // Filter active
    static const uint8_t FA1R_FACT3 = 3;            // Filter active
    static const uint8_t FA1R_FACT4 = 4;            // Filter active
    static const uint8_t FA1R_FACT5 = 5;            // Filter active
    static const uint8_t FA1R_FACT6 = 6;            // Filter active
    static const uint8_t FA1R_FACT7 = 7;            // Filter active
    static const uint8_t FA1R_FACT8 = 8;            // Filter active
    static const uint8_t FA1R_FACT9 = 9;            // Filter active
    static const uint8_t FA1R_FACT10 = 10;          // Filter active
    static const uint8_t FA1R_FACT11 = 11;          // Filter active
    static const uint8_t FA1R_FACT12 = 12;          // Filter active
    static const uint8_t FA1R_FACT13 = 13;          // Filter active
    static const uint8_t FA1R_FACT14 = 14;          // Filter active
    static const uint8_t FA1R_FACT15 = 15;          // Filter active
    static const uint8_t FA1R_FACT16 = 16;          // Filter active
    static const uint8_t FA1R_FACT17 = 17;          // Filter active
    static const uint8_t FA1R_FACT18 = 18;          // Filter active
    static const uint8_t FA1R_FACT19 = 19;          // Filter active
    static const uint8_t FA1R_FACT20 = 20;          // Filter active
    static const uint8_t FA1R_FACT21 = 21;          // Filter active
    static const uint8_t FA1R_FACT22 = 22;          // Filter active
    static const uint8_t FA1R_FACT23 = 23;          // Filter active
    static const uint8_t FA1R_FACT24 = 24;          // Filter active
    static const uint8_t FA1R_FACT25 = 25;          // Filter active
    static const uint8_t FA1R_FACT26 = 26;          // Filter active
    static const uint8_t FA1R_FACT27 = 27;          // Filter active
    static const uint32_t FA1R_RESET_VALUE = 0x0;

    static const uint8_t F0R1_FB0 = 0;              // Filter bits
    static const uint8_t F0R1_FB1 = 1;              // Filter bits
    static const uint8_t F0R1_FB2 = 2;              // Filter bits
    static const uint8_t F0R1_FB3 = 3;              // Filter bits
    static const uint8_t F0R1_FB4 = 4;              // Filter bits
    static const uint8_t F0R1_FB5 = 5;              // Filter bits
    static const uint8_t F0R1_FB6 = 6;              // Filter bits
    static const uint8_t F0R1_FB7 = 7;              // Filter bits
    static const uint8_t F0R1_FB8 = 8;              // Filter bits
    static const uint8_t F0R1_FB9 = 9;              // Filter bits
    static const uint8_t F0R1_FB10 = 10;            // Filter bits
    static const uint8_t F0R1_FB11 = 11;            // Filter bits
    static const uint8_t F0R1_FB12 = 12;            // Filter bits
    static const uint8_t F0R1_FB13 = 13;            // Filter bits
    static const uint8_t F0R1_FB14 = 14;            // Filter bits
    static const uint8_t F0R1_FB15 = 15;            // Filter bits
    static const uint8_t F0R1_FB16 = 16;            // Filter bits
    static const uint8_t F0R1_FB17 = 17;            // Filter bits
    static const uint8_t F0R1_FB18 = 18;            // Filter bits
    static const uint8_t F0R1_FB19 = 19;            // Filter bits
    static const uint8_t F0R1_FB20 = 20;            // Filter bits
    static const uint8_t F0R1_FB21 = 21;            // Filter bits
    static const uint8_t F0R1_FB22 = 22;            // Filter bits
    static const uint8_t F0R1_FB23 = 23;            // Filter bits
    static const uint8_t F0R1_FB24 = 24;            // Filter bits
    static const uint8_t F0R1_FB25 = 25;            // Filter bits
    static const uint8_t F0R1_FB26 = 26;            // Filter bits
    static const uint8_t F0R1_FB27 = 27;            // Filter bits
    static const uint8_t F0R1_FB28 = 28;            // Filter bits
    static const uint8_t F0R1_FB29 = 29;            // Filter bits
    static const uint8_t F0R1_FB30 = 30;            // Filter bits
    static const uint8_t F0R1_FB31 = 31;            // Filter bits
    static const uint32_t F0R1_RESET_VALUE = 0x0;

    static const uint8_t F0R2_FB0 = 0;              // Filter bits
    static const uint8_t F0R2_FB1 = 1;              // Filter bits
    static const uint8_t F0R2_FB2 = 2;              // Filter bits
    static const uint8_t F0R2_FB3 = 3;              // Filter bits
    static const uint8_t F0R2_FB4 = 4;              // Filter bits
    static const uint8_t F0R2_FB5 = 5;              // Filter bits
    static const uint8_t F0R2_FB6 = 6;              // Filter bits
    static const uint8_t F0R2_FB7 = 7;              // Filter bits
    static const uint8_t F0R2_FB8 = 8;              // Filter bits
    static const uint8_t F0R2_FB9 = 9;              // Filter bits
    static const uint8_t F0R2_FB10 = 10;            // Filter bits
    static const uint8_t F0R2_FB11 = 11;            // Filter bits
    static const uint8_t F0R2_FB12 = 12;            // Filter bits
    static const uint8_t F0R2_FB13 = 13;            // Filter bits
    static const uint8_t F0R2_FB14 = 14;            // Filter bits
    static const uint8_t F0R2_FB15 = 15;            // Filter bits
    static const uint8_t F0R2_FB16 = 16;            // Filter bits
    static const uint8_t F0R2_FB17 = 17;            // Filter bits
    static const uint8_t F0R2_FB18 = 18;            // Filter bits
    static const uint8_t F0R2_FB19 = 19;            // Filter bits
    static const uint8_t F0R2_FB20 = 20;            // Filter bits
    static const uint8_t F0R2_FB21 = 21;            // Filter bits
    static const uint8_t F0R2_FB22 = 22;            // Filter bits
    static const uint8_t F0R2_FB23 = 23;            // Filter bits
    static const uint8_t F0R2_FB24 = 24;            // Filter bits
    static const uint8_t F0R2_FB25 = 25;            // Filter bits
    static const uint8_t F0R2_FB26 = 26;            // Filter bits
    static const uint8_t F0R2_FB27 = 27;            // Filter bits
    static const uint8_t F0R2_FB28 = 28;            // Filter bits
    static const uint8_t F0R2_FB29 = 29;            // Filter bits
    static const uint8_t F0R2_FB30 = 30;            // Filter bits
    static const uint8_t F0R2_FB31 = 31;            // Filter bits
    static const uint32_t F0R2_RESET_VALUE = 0x0;

    static const uint8_t F1R1_FB0 = 0;              // Filter bits
    static const uint8_t F1R1_FB1 = 1;              // Filter bits
    static const uint8_t F1R1_FB2 = 2;              // Filter bits
    static const uint8_t F1R1_FB3 = 3;              // Filter bits
    static const uint8_t F1R1_FB4 = 4;              // Filter bits
    static const uint8_t F1R1_FB5 = 5;              // Filter bits
    static const uint8_t F1R1_FB6 = 6;              // Filter bits
    static const uint8_t F1R1_FB7 = 7;              // Filter bits
    static const uint8_t F1R1_FB8 = 8;              // Filter bits
    static const uint8_t F1R1_FB9 = 9;              // Filter bits
    static const uint8_t F1R1_FB10 = 10;            // Filter bits
    static const uint8_t F1R1_FB11 = 11;            // Filter bits
    static const uint8_t F1R1_FB12 = 12;            // Filter bits
    static const uint8_t F1R1_FB13 = 13;            // Filter bits
    static const uint8_t F1R1_FB14 = 14;            // Filter bits
    static const uint8_t F1R1_FB15 = 15;            // Filter bits
    static const uint8_t F1R1_FB16 = 16;            // Filter bits
    static const uint8_t F1R1_FB17 = 17;            // Filter bits
    static const uint8_t F1R1_FB18 = 18;            // Filter bits
    static const uint8_t F1R1_FB19 = 19;            // Filter bits
    static const uint8_t F1R1_FB20 = 20;            // Filter bits
    static const uint8_t F1R1_FB21 = 21;            // Filter bits
    static const uint8_t F1R1_FB22 = 22;            // Filter bits
    static const uint8_t F1R1_FB23 = 23;            // Filter bits
    static const uint8_t F1R1_FB24 = 24;            // Filter bits
    static const uint8_t F1R1_FB25 = 25;            // Filter bits
    static const uint8_t F1R1_FB26 = 26;            // Filter bits
    static const uint8_t F1R1_FB27 = 27;            // Filter bits
    static const uint8_t F1R1_FB28 = 28;            // Filter bits
    static const uint8_t F1R1_FB29 = 29;            // Filter bits
    static const uint8_t F1R1_FB30 = 30;            // Filter bits
    static const uint8_t F1R1_FB31 = 31;            // Filter bits
    static const uint32_t F1R1_RESET_VALUE = 0x0;

    static const uint8_t F1R2_FB0 = 0;              // Filter bits
    static const uint8_t F1R2_FB1 = 1;              // Filter bits
    static const uint8_t F1R2_FB2 = 2;              // Filter bits
    static const uint8_t F1R2_FB3 = 3;              // Filter bits
    static const uint8_t F1R2_FB4 = 4;              // Filter bits
    static const uint8_t F1R2_FB5 = 5;              // Filter bits
    static const uint8_t F1R2_FB6 = 6;              // Filter bits
    static const uint8_t F1R2_FB7 = 7;              // Filter bits
    static const uint8_t F1R2_FB8 = 8;              // Filter bits
    static const uint8_t F1R2_FB9 = 9;              // Filter bits
    static const uint8_t F1R2_FB10 = 10;            // Filter bits
    static const uint8_t F1R2_FB11 = 11;            // Filter bits
    static const uint8_t F1R2_FB12 = 12;            // Filter bits
    static const uint8_t F1R2_FB13 = 13;            // Filter bits
    static const uint8_t F1R2_FB14 = 14;            // Filter bits
    static const uint8_t F1R2_FB15 = 15;            // Filter bits
    static const uint8_t F1R2_FB16 = 16;            // Filter bits
    static const uint8_t F1R2_FB17 = 17;            // Filter bits
    static const uint8_t F1R2_FB18 = 18;            // Filter bits
    static const uint8_t F1R2_FB19 = 19;            // Filter bits
    static const uint8_t F1R2_FB20 = 20;            // Filter bits
    static const uint8_t F1R2_FB21 = 21;            // Filter bits
    static const uint8_t F1R2_FB22 = 22;            // Filter bits
    static const uint8_t F1R2_FB23 = 23;            // Filter bits
    static const uint8_t F1R2_FB24 = 24;            // Filter bits
    static const uint8_t F1R2_FB25 = 25;            // Filter bits
    static const uint8_t F1R2_FB26 = 26;            // Filter bits
    static const uint8_t F1R2_FB27 = 27;            // Filter bits
    static const uint8_t F1R2_FB28 = 28;            // Filter bits
    static const uint8_t F1R2_FB29 = 29;            // Filter bits
    static const uint8_t F1R2_FB30 = 30;            // Filter bits
    static const uint8_t F1R2_FB31 = 31;            // Filter bits
    static const uint32_t F1R2_RESET_VALUE = 0x0;

    static const uint8_t F2R1_FB0 = 0;              // Filter bits
    static const uint8_t F2R1_FB1 = 1;              // Filter bits
    static const uint8_t F2R1_FB2 = 2;              // Filter bits
    static const uint8_t F2R1_FB3 = 3;              // Filter bits
    static const uint8_t F2R1_FB4 = 4;              // Filter bits
    static const uint8_t F2R1_FB5 = 5;              // Filter bits
    static const uint8_t F2R1_FB6 = 6;              // Filter bits
    static const uint8_t F2R1_FB7 = 7;              // Filter bits
    static const uint8_t F2R1_FB8 = 8;              // Filter bits
    static const uint8_t F2R1_FB9 = 9;              // Filter bits
    static const uint8_t F2R1_FB10 = 10;            // Filter bits
    static const uint8_t F2R1_FB11 = 11;            // Filter bits
    static const uint8_t F2R1_FB12 = 12;            // Filter bits
    static const uint8_t F2R1_FB13 = 13;            // Filter bits
    static const uint8_t F2R1_FB14 = 14;            // Filter bits
    static const uint8_t F2R1_FB15 = 15;            // Filter bits
    static const uint8_t F2R1_FB16 = 16;            // Filter bits
    static const uint8_t F2R1_FB17 = 17;            // Filter bits
    static const uint8_t F2R1_FB18 = 18;            // Filter bits
    static const uint8_t F2R1_FB19 = 19;            // Filter bits
    static const uint8_t F2R1_FB20 = 20;            // Filter bits
    static const uint8_t F2R1_FB21 = 21;            // Filter bits
    static const uint8_t F2R1_FB22 = 22;            // Filter bits
    static const uint8_t F2R1_FB23 = 23;            // Filter bits
    static const uint8_t F2R1_FB24 = 24;            // Filter bits
    static const uint8_t F2R1_FB25 = 25;            // Filter bits
    static const uint8_t F2R1_FB26 = 26;            // Filter bits
    static const uint8_t F2R1_FB27 = 27;            // Filter bits
    static const uint8_t F2R1_FB28 = 28;            // Filter bits
    static const uint8_t F2R1_FB29 = 29;            // Filter bits
    static const uint8_t F2R1_FB30 = 30;            // Filter bits
    static const uint8_t F2R1_FB31 = 31;            // Filter bits
    static const uint32_t F2R1_RESET_VALUE = 0x0;

    static const uint8_t F2R2_FB0 = 0;              // Filter bits
    static const uint8_t F2R2_FB1 = 1;              // Filter bits
    static const uint8_t F2R2_FB2 = 2;              // Filter bits
    static const uint8_t F2R2_FB3 = 3;              // Filter bits
    static const uint8_t F2R2_FB4 = 4;              // Filter bits
    static const uint8_t F2R2_FB5 = 5;              // Filter bits
    static const uint8_t F2R2_FB6 = 6;              // Filter bits
    static const uint8_t F2R2_FB7 = 7;              // Filter bits
    static const uint8_t F2R2_FB8 = 8;              // Filter bits
    static const uint8_t F2R2_FB9 = 9;              // Filter bits
    static const uint8_t F2R2_FB10 = 10;            // Filter bits
    static const uint8_t F2R2_FB11 = 11;            // Filter bits
    static const uint8_t F2R2_FB12 = 12;            // Filter bits
    static const uint8_t F2R2_FB13 = 13;            // Filter bits
    static const uint8_t F2R2_FB14 = 14;            // Filter bits
    static const uint8_t F2R2_FB15 = 15;            // Filter bits
    static const uint8_t F2R2_FB16 = 16;            // Filter bits
    static const uint8_t F2R2_FB17 = 17;            // Filter bits
    static const uint8_t F2R2_FB18 = 18;            // Filter bits
    static const uint8_t F2R2_FB19 = 19;            // Filter bits
    static const uint8_t F2R2_FB20 = 20;            // Filter bits
    static const uint8_t F2R2_FB21 = 21;            // Filter bits
    static const uint8_t F2R2_FB22 = 22;            // Filter bits
    static const uint8_t F2R2_FB23 = 23;            // Filter bits
    static const uint8_t F2R2_FB24 = 24;            // Filter bits
    static const uint8_t F2R2_FB25 = 25;            // Filter bits
    static const uint8_t F2R2_FB26 = 26;            // Filter bits
    static const uint8_t F2R2_FB27 = 27;            // Filter bits
    static const uint8_t F2R2_FB28 = 28;            // Filter bits
    static const uint8_t F2R2_FB29 = 29;            // Filter bits
    static const uint8_t F2R2_FB30 = 30;            // Filter bits
    static const uint8_t F2R2_FB31 = 31;            // Filter bits
    static const uint32_t F2R2_RESET_VALUE = 0x0;

    static const uint8_t F3R1_FB0 = 0;              // Filter bits
    static const uint8_t F3R1_FB1 = 1;              // Filter bits
    static const uint8_t F3R1_FB2 = 2;              // Filter bits
    static const uint8_t F3R1_FB3 = 3;              // Filter bits
    static const uint8_t F3R1_FB4 = 4;              // Filter bits
    static const uint8_t F3R1_FB5 = 5;              // Filter bits
    static const uint8_t F3R1_FB6 = 6;              // Filter bits
    static const uint8_t F3R1_FB7 = 7;              // Filter bits
    static const uint8_t F3R1_FB8 = 8;              // Filter bits
    static const uint8_t F3R1_FB9 = 9;              // Filter bits
    static const uint8_t F3R1_FB10 = 10;            // Filter bits
    static const uint8_t F3R1_FB11 = 11;            // Filter bits
    static const uint8_t F3R1_FB12 = 12;            // Filter bits
    static const uint8_t F3R1_FB13 = 13;            // Filter bits
    static const uint8_t F3R1_FB14 = 14;            // Filter bits
    static const uint8_t F3R1_FB15 = 15;            // Filter bits
    static const uint8_t F3R1_FB16 = 16;            // Filter bits
    static const uint8_t F3R1_FB17 = 17;            // Filter bits
    static const uint8_t F3R1_FB18 = 18;            // Filter bits
    static const uint8_t F3R1_FB19 = 19;            // Filter bits
    static const uint8_t F3R1_FB20 = 20;            // Filter bits
    static const uint8_t F3R1_FB21 = 21;            // Filter bits
    static const uint8_t F3R1_FB22 = 22;            // Filter bits
    static const uint8_t F3R1_FB23 = 23;            // Filter bits
    static const uint8_t F3R1_FB24 = 24;            // Filter bits
    static const uint8_t F3R1_FB25 = 25;            // Filter bits
    static const uint8_t F3R1_FB26 = 26;            // Filter bits
    static const uint8_t F3R1_FB27 = 27;            // Filter bits
    static const uint8_t F3R1_FB28 = 28;            // Filter bits
    static const uint8_t F3R1_FB29 = 29;            // Filter bits
    static const uint8_t F3R1_FB30 = 30;            // Filter bits
    static const uint8_t F3R1_FB31 = 31;            // Filter bits
    static const uint32_t F3R1_RESET_VALUE = 0x0;

    static const uint8_t F3R2_FB0 = 0;              // Filter bits
    static const uint8_t F3R2_FB1 = 1;              // Filter bits
    static const uint8_t F3R2_FB2 = 2;              // Filter bits
    static const uint8_t F3R2_FB3 = 3;              // Filter bits
    static const uint8_t F3R2_FB4 = 4;              // Filter bits
    static const uint8_t F3R2_FB5 = 5;              // Filter bits
    static const uint8_t F3R2_FB6 = 6;              // Filter bits
    static const uint8_t F3R2_FB7 = 7;              // Filter bits
    static const uint8_t F3R2_FB8 = 8;              // Filter bits
    static const uint8_t F3R2_FB9 = 9;              // Filter bits
    static const uint8_t F3R2_FB10 = 10;            // Filter bits
    static const uint8_t F3R2_FB11 = 11;            // Filter bits
    static const uint8_t F3R2_FB12 = 12;            // Filter bits
    static const uint8_t F3R2_FB13 = 13;            // Filter bits
    static const uint8_t F3R2_FB14 = 14;            // Filter bits
    static const uint8_t F3R2_FB15 = 15;            // Filter bits
    static const uint8_t F3R2_FB16 = 16;            // Filter bits
    static const uint8_t F3R2_FB17 = 17;            // Filter bits
    static const uint8_t F3R2_FB18 = 18;            // Filter bits
    static const uint8_t F3R2_FB19 = 19;            // Filter bits
    static const uint8_t F3R2_FB20 = 20;            // Filter bits
    static const uint8_t F3R2_FB21 = 21;            // Filter bits
    static const uint8_t F3R2_FB22 = 22;            // Filter bits
    static const uint8_t F3R2_FB23 = 23;            // Filter bits
    static const uint8_t F3R2_FB24 = 24;            // Filter bits
    static const uint8_t F3R2_FB25 = 25;            // Filter bits
    static const uint8_t F3R2_FB26 = 26;            // Filter bits
    static const uint8_t F3R2_FB27 = 27;            // Filter bits
    static const uint8_t F3R2_FB28 = 28;            // Filter bits
    static const uint8_t F3R2_FB29 = 29;            // Filter bits
    static const uint8_t F3R2_FB30 = 30;            // Filter bits
    static const uint8_t F3R2_FB31 = 31;            // Filter bits
    static const uint32_t F3R2_RESET_VALUE = 0x0;

    static const uint8_t F4R1_FB0 = 0;              // Filter bits
    static const uint8_t F4R1_FB1 = 1;              // Filter bits
    static const uint8_t F4R1_FB2 = 2;              // Filter bits
    static const uint8_t F4R1_FB3 = 3;              // Filter bits
    static const uint8_t F4R1_FB4 = 4;              // Filter bits
    static const uint8_t F4R1_FB5 = 5;              // Filter bits
    static const uint8_t F4R1_FB6 = 6;              // Filter bits
    static const uint8_t F4R1_FB7 = 7;              // Filter bits
    static const uint8_t F4R1_FB8 = 8;              // Filter bits
    static const uint8_t F4R1_FB9 = 9;              // Filter bits
    static const uint8_t F4R1_FB10 = 10;            // Filter bits
    static const uint8_t F4R1_FB11 = 11;            // Filter bits
    static const uint8_t F4R1_FB12 = 12;            // Filter bits
    static const uint8_t F4R1_FB13 = 13;            // Filter bits
    static const uint8_t F4R1_FB14 = 14;            // Filter bits
    static const uint8_t F4R1_FB15 = 15;            // Filter bits
    static const uint8_t F4R1_FB16 = 16;            // Filter bits
    static const uint8_t F4R1_FB17 = 17;            // Filter bits
    static const uint8_t F4R1_FB18 = 18;            // Filter bits
    static const uint8_t F4R1_FB19 = 19;            // Filter bits
    static const uint8_t F4R1_FB20 = 20;            // Filter bits
    static const uint8_t F4R1_FB21 = 21;            // Filter bits
    static const uint8_t F4R1_FB22 = 22;            // Filter bits
    static const uint8_t F4R1_FB23 = 23;            // Filter bits
    static const uint8_t F4R1_FB24 = 24;            // Filter bits
    static const uint8_t F4R1_FB25 = 25;            // Filter bits
    static const uint8_t F4R1_FB26 = 26;            // Filter bits
    static const uint8_t F4R1_FB27 = 27;            // Filter bits
    static const uint8_t F4R1_FB28 = 28;            // Filter bits
    static const uint8_t F4R1_FB29 = 29;            // Filter bits
    static const uint8_t F4R1_FB30 = 30;            // Filter bits
    static const uint8_t F4R1_FB31 = 31;            // Filter bits
    static const uint32_t F4R1_RESET_VALUE = 0x0;

    static const uint8_t F4R2_FB0 = 0;              // Filter bits
    static const uint8_t F4R2_FB1 = 1;              // Filter bits
    static const uint8_t F4R2_FB2 = 2;              // Filter bits
    static const uint8_t F4R2_FB3 = 3;              // Filter bits
    static const uint8_t F4R2_FB4 = 4;              // Filter bits
    static const uint8_t F4R2_FB5 = 5;              // Filter bits
    static const uint8_t F4R2_FB6 = 6;              // Filter bits
    static const uint8_t F4R2_FB7 = 7;              // Filter bits
    static const uint8_t F4R2_FB8 = 8;              // Filter bits
    static const uint8_t F4R2_FB9 = 9;              // Filter bits
    static const uint8_t F4R2_FB10 = 10;            // Filter bits
    static const uint8_t F4R2_FB11 = 11;            // Filter bits
    static const uint8_t F4R2_FB12 = 12;            // Filter bits
    static const uint8_t F4R2_FB13 = 13;            // Filter bits
    static const uint8_t F4R2_FB14 = 14;            // Filter bits
    static const uint8_t F4R2_FB15 = 15;            // Filter bits
    static const uint8_t F4R2_FB16 = 16;            // Filter bits
    static const uint8_t F4R2_FB17 = 17;            // Filter bits
    static const uint8_t F4R2_FB18 = 18;            // Filter bits
    static const uint8_t F4R2_FB19 = 19;            // Filter bits
    static const uint8_t F4R2_FB20 = 20;            // Filter bits
    static const uint8_t F4R2_FB21 = 21;            // Filter bits
    static const uint8_t F4R2_FB22 = 22;            // Filter bits
    static const uint8_t F4R2_FB23 = 23;            // Filter bits
    static const uint8_t F4R2_FB24 = 24;            // Filter bits
    static const uint8_t F4R2_FB25 = 25;            // Filter bits
    static const uint8_t F4R2_FB26 = 26;            // Filter bits
    static const uint8_t F4R2_FB27 = 27;            // Filter bits
    static const uint8_t F4R2_FB28 = 28;            // Filter bits
    static const uint8_t F4R2_FB29 = 29;            // Filter bits
    static const uint8_t F4R2_FB30 = 30;            // Filter bits
    static const uint8_t F4R2_FB31 = 31;            // Filter bits
    static const uint32_t F4R2_RESET_VALUE = 0x0;

    static const uint8_t F5R1_FB0 = 0;              // Filter bits
    static const uint8_t F5R1_FB1 = 1;              // Filter bits
    static const uint8_t F5R1_FB2 = 2;              // Filter bits
    static const uint8_t F5R1_FB3 = 3;              // Filter bits
    static const uint8_t F5R1_FB4 = 4;              // Filter bits
    static const uint8_t F5R1_FB5 = 5;              // Filter bits
    static const uint8_t F5R1_FB6 = 6;              // Filter bits
    static const uint8_t F5R1_FB7 = 7;              // Filter bits
    static const uint8_t F5R1_FB8 = 8;              // Filter bits
    static const uint8_t F5R1_FB9 = 9;              // Filter bits
    static const uint8_t F5R1_FB10 = 10;            // Filter bits
    static const uint8_t F5R1_FB11 = 11;            // Filter bits
    static const uint8_t F5R1_FB12 = 12;            // Filter bits
    static const uint8_t F5R1_FB13 = 13;            // Filter bits
    static const uint8_t F5R1_FB14 = 14;            // Filter bits
    static const uint8_t F5R1_FB15 = 15;            // Filter bits
    static const uint8_t F5R1_FB16 = 16;            // Filter bits
    static const uint8_t F5R1_FB17 = 17;            // Filter bits
    static const uint8_t F5R1_FB18 = 18;            // Filter bits
    static const uint8_t F5R1_FB19 = 19;            // Filter bits
    static const uint8_t F5R1_FB20 = 20;            // Filter bits
    static const uint8_t F5R1_FB21 = 21;            // Filter bits
    static const uint8_t F5R1_FB22 = 22;            // Filter bits
    static const uint8_t F5R1_FB23 = 23;            // Filter bits
    static const uint8_t F5R1_FB24 = 24;            // Filter bits
    static const uint8_t F5R1_FB25 = 25;            // Filter bits
    static const uint8_t F5R1_FB26 = 26;            // Filter bits
    static const uint8_t F5R1_FB27 = 27;            // Filter bits
    static const uint8_t F5R1_FB28 = 28;            // Filter bits
    static const uint8_t F5R1_FB29 = 29;            // Filter bits
    static const uint8_t F5R1_FB30 = 30;            // Filter bits
    static const uint8_t F5R1_FB31 = 31;            // Filter bits
    static const uint32_t F5R1_RESET_VALUE = 0x0;

    static const uint8_t F5R2_FB0 = 0;              // Filter bits
    static const uint8_t F5R2_FB1 = 1;              // Filter bits
    static const uint8_t F5R2_FB2 = 2;              // Filter bits
    static const uint8_t F5R2_FB3 = 3;              // Filter bits
    static const uint8_t F5R2_FB4 = 4;              // Filter bits
    static const uint8_t F5R2_FB5 = 5;              // Filter bits
    static const uint8_t F5R2_FB6 = 6;              // Filter bits
    static const uint8_t F5R2_FB7 = 7;              // Filter bits
    static const uint8_t F5R2_FB8 = 8;              // Filter bits
    static const uint8_t F5R2_FB9 = 9;              // Filter bits
    static const uint8_t F5R2_FB10 = 10;            // Filter bits
    static const uint8_t F5R2_FB11 = 11;            // Filter bits
    static const uint8_t F5R2_FB12 = 12;            // Filter bits
    static const uint8_t F5R2_FB13 = 13;            // Filter bits
    static const uint8_t F5R2_FB14 = 14;            // Filter bits
    static const uint8_t F5R2_FB15 = 15;            // Filter bits
    static const uint8_t F5R2_FB16 = 16;            // Filter bits
    static const uint8_t F5R2_FB17 = 17;            // Filter bits
    static const uint8_t F5R2_FB18 = 18;            // Filter bits
    static const uint8_t F5R2_FB19 = 19;            // Filter bits
    static const uint8_t F5R2_FB20 = 20;            // Filter bits
    static const uint8_t F5R2_FB21 = 21;            // Filter bits
    static const uint8_t F5R2_FB22 = 22;            // Filter bits
    static const uint8_t F5R2_FB23 = 23;            // Filter bits
    static const uint8_t F5R2_FB24 = 24;            // Filter bits
    static const uint8_t F5R2_FB25 = 25;            // Filter bits
    static const uint8_t F5R2_FB26 = 26;            // Filter bits
    static const uint8_t F5R2_FB27 = 27;            // Filter bits
    static const uint8_t F5R2_FB28 = 28;            // Filter bits
    static const uint8_t F5R2_FB29 = 29;            // Filter bits
    static const uint8_t F5R2_FB30 = 30;            // Filter bits
    static const uint8_t F5R2_FB31 = 31;            // Filter bits
    static const uint32_t F5R2_RESET_VALUE = 0x0;

    static const uint8_t F6R1_FB0 = 0;              // Filter bits
    static const uint8_t F6R1_FB1 = 1;              // Filter bits
    static const uint8_t F6R1_FB2 = 2;              // Filter bits
    static const uint8_t F6R1_FB3 = 3;              // Filter bits
    static const uint8_t F6R1_FB4 = 4;              // Filter bits
    static const uint8_t F6R1_FB5 = 5;              // Filter bits
    static const uint8_t F6R1_FB6 = 6;              // Filter bits
    static const uint8_t F6R1_FB7 = 7;              // Filter bits
    static const uint8_t F6R1_FB8 = 8;              // Filter bits
    static const uint8_t F6R1_FB9 = 9;              // Filter bits
    static const uint8_t F6R1_FB10 = 10;            // Filter bits
    static const uint8_t F6R1_FB11 = 11;            // Filter bits
    static const uint8_t F6R1_FB12 = 12;            // Filter bits
    static const uint8_t F6R1_FB13 = 13;            // Filter bits
    static const uint8_t F6R1_FB14 = 14;            // Filter bits
    static const uint8_t F6R1_FB15 = 15;            // Filter bits
    static const uint8_t F6R1_FB16 = 16;            // Filter bits
    static const uint8_t F6R1_FB17 = 17;            // Filter bits
    static const uint8_t F6R1_FB18 = 18;            // Filter bits
    static const uint8_t F6R1_FB19 = 19;            // Filter bits
    static const uint8_t F6R1_FB20 = 20;            // Filter bits
    static const uint8_t F6R1_FB21 = 21;            // Filter bits
    static const uint8_t F6R1_FB22 = 22;            // Filter bits
    static const uint8_t F6R1_FB23 = 23;            // Filter bits
    static const uint8_t F6R1_FB24 = 24;            // Filter bits
    static const uint8_t F6R1_FB25 = 25;            // Filter bits
    static const uint8_t F6R1_FB26 = 26;            // Filter bits
    static const uint8_t F6R1_FB27 = 27;            // Filter bits
    static const uint8_t F6R1_FB28 = 28;            // Filter bits
    static const uint8_t F6R1_FB29 = 29;            // Filter bits
    static const uint8_t F6R1_FB30 = 30;            // Filter bits
    static const uint8_t F6R1_FB31 = 31;            // Filter bits
    static const uint32_t F6R1_RESET_VALUE = 0x0;

    static const uint8_t F6R2_FB0 = 0;              // Filter bits
    static const uint8_t F6R2_FB1 = 1;              // Filter bits
    static const uint8_t F6R2_FB2 = 2;              // Filter bits
    static const uint8_t F6R2_FB3 = 3;              // Filter bits
    static const uint8_t F6R2_FB4 = 4;              // Filter bits
    static const uint8_t F6R2_FB5 = 5;              // Filter bits
    static const uint8_t F6R2_FB6 = 6;              // Filter bits
    static const uint8_t F6R2_FB7 = 7;              // Filter bits
    static const uint8_t F6R2_FB8 = 8;              // Filter bits
    static const uint8_t F6R2_FB9 = 9;              // Filter bits
    static const uint8_t F6R2_FB10 = 10;            // Filter bits
    static const uint8_t F6R2_FB11 = 11;            // Filter bits
    static const uint8_t F6R2_FB12 = 12;            // Filter bits
    static const uint8_t F6R2_FB13 = 13;            // Filter bits
    static const uint8_t F6R2_FB14 = 14;            // Filter bits
    static const uint8_t F6R2_FB15 = 15;            // Filter bits
    static const uint8_t F6R2_FB16 = 16;            // Filter bits
    static const uint8_t F6R2_FB17 = 17;            // Filter bits
    static const uint8_t F6R2_FB18 = 18;            // Filter bits
    static const uint8_t F6R2_FB19 = 19;            // Filter bits
    static const uint8_t F6R2_FB20 = 20;            // Filter bits
    static const uint8_t F6R2_FB21 = 21;            // Filter bits
    static const uint8_t F6R2_FB22 = 22;            // Filter bits
    static const uint8_t F6R2_FB23 = 23;            // Filter bits
    static const uint8_t F6R2_FB24 = 24;            // Filter bits
    static const uint8_t F6R2_FB25 = 25;            // Filter bits
    static const uint8_t F6R2_FB26 = 26;            // Filter bits
    static const uint8_t F6R2_FB27 = 27;            // Filter bits
    static const uint8_t F6R2_FB28 = 28;            // Filter bits
    static const uint8_t F6R2_FB29 = 29;            // Filter bits
    static const uint8_t F6R2_FB30 = 30;            // Filter bits
    static const uint8_t F6R2_FB31 = 31;            // Filter bits
    static const uint32_t F6R2_RESET_VALUE = 0x0;

    static const uint8_t F7R1_FB0 = 0;              // Filter bits
    static const uint8_t F7R1_FB1 = 1;              // Filter bits
    static const uint8_t F7R1_FB2 = 2;              // Filter bits
    static const uint8_t F7R1_FB3 = 3;              // Filter bits
    static const uint8_t F7R1_FB4 = 4;              // Filter bits
    static const uint8_t F7R1_FB5 = 5;              // Filter bits
    static const uint8_t F7R1_FB6 = 6;              // Filter bits
    static const uint8_t F7R1_FB7 = 7;              // Filter bits
    static const uint8_t F7R1_FB8 = 8;              // Filter bits
    static const uint8_t F7R1_FB9 = 9;              // Filter bits
    static const uint8_t F7R1_FB10 = 10;            // Filter bits
    static const uint8_t F7R1_FB11 = 11;            // Filter bits
    static const uint8_t F7R1_FB12 = 12;            // Filter bits
    static const uint8_t F7R1_FB13 = 13;            // Filter bits
    static const uint8_t F7R1_FB14 = 14;            // Filter bits
    static const uint8_t F7R1_FB15 = 15;            // Filter bits
    static const uint8_t F7R1_FB16 = 16;            // Filter bits
    static const uint8_t F7R1_FB17 = 17;            // Filter bits
    static const uint8_t F7R1_FB18 = 18;            // Filter bits
    static const uint8_t F7R1_FB19 = 19;            // Filter bits
    static const uint8_t F7R1_FB20 = 20;            // Filter bits
    static const uint8_t F7R1_FB21 = 21;            // Filter bits
    static const uint8_t F7R1_FB22 = 22;            // Filter bits
    static const uint8_t F7R1_FB23 = 23;            // Filter bits
    static const uint8_t F7R1_FB24 = 24;            // Filter bits
    static const uint8_t F7R1_FB25 = 25;            // Filter bits
    static const uint8_t F7R1_FB26 = 26;            // Filter bits
    static const uint8_t F7R1_FB27 = 27;            // Filter bits
    static const uint8_t F7R1_FB28 = 28;            // Filter bits
    static const uint8_t F7R1_FB29 = 29;            // Filter bits
    static const uint8_t F7R1_FB30 = 30;            // Filter bits
    static const uint8_t F7R1_FB31 = 31;            // Filter bits
    static const uint32_t F7R1_RESET_VALUE = 0x0;

    static const uint8_t F7R2_FB0 = 0;              // Filter bits
    static const uint8_t F7R2_FB1 = 1;              // Filter bits
    static const uint8_t F7R2_FB2 = 2;              // Filter bits
    static const uint8_t F7R2_FB3 = 3;              // Filter bits
    static const uint8_t F7R2_FB4 = 4;              // Filter bits
    static const uint8_t F7R2_FB5 = 5;              // Filter bits
    static const uint8_t F7R2_FB6 = 6;              // Filter bits
    static const uint8_t F7R2_FB7 = 7;              // Filter bits
    static const uint8_t F7R2_FB8 = 8;              // Filter bits
    static const uint8_t F7R2_FB9 = 9;              // Filter bits
    static const uint8_t F7R2_FB10 = 10;            // Filter bits
    static const uint8_t F7R2_FB11 = 11;            // Filter bits
    static const uint8_t F7R2_FB12 = 12;            // Filter bits
    static const uint8_t F7R2_FB13 = 13;            // Filter bits
    static const uint8_t F7R2_FB14 = 14;            // Filter bits
    static const uint8_t F7R2_FB15 = 15;            // Filter bits
    static const uint8_t F7R2_FB16 = 16;            // Filter bits
    static const uint8_t F7R2_FB17 = 17;            // Filter bits
    static const uint8_t F7R2_FB18 = 18;            // Filter bits
    static const uint8_t F7R2_FB19 = 19;            // Filter bits
    static const uint8_t F7R2_FB20 = 20;            // Filter bits
    static const uint8_t F7R2_FB21 = 21;            // Filter bits
    static const uint8_t F7R2_FB22 = 22;            // Filter bits
    static const uint8_t F7R2_FB23 = 23;            // Filter bits
    static const uint8_t F7R2_FB24 = 24;            // Filter bits
    static const uint8_t F7R2_FB25 = 25;            // Filter bits
    static const uint8_t F7R2_FB26 = 26;            // Filter bits
    static const uint8_t F7R2_FB27 = 27;            // Filter bits
    static const uint8_t F7R2_FB28 = 28;            // Filter bits
    static const uint8_t F7R2_FB29 = 29;            // Filter bits
    static const uint8_t F7R2_FB30 = 30;            // Filter bits
    static const uint8_t F7R2_FB31 = 31;            // Filter bits
    static const uint32_t F7R2_RESET_VALUE = 0x0;

    static const uint8_t F8R1_FB0 = 0;              // Filter bits
    static const uint8_t F8R1_FB1 = 1;              // Filter bits
    static const uint8_t F8R1_FB2 = 2;              // Filter bits
    static const uint8_t F8R1_FB3 = 3;              // Filter bits
    static const uint8_t F8R1_FB4 = 4;              // Filter bits
    static const uint8_t F8R1_FB5 = 5;              // Filter bits
    static const uint8_t F8R1_FB6 = 6;              // Filter bits
    static const uint8_t F8R1_FB7 = 7;              // Filter bits
    static const uint8_t F8R1_FB8 = 8;              // Filter bits
    static const uint8_t F8R1_FB9 = 9;              // Filter bits
    static const uint8_t F8R1_FB10 = 10;            // Filter bits
    static const uint8_t F8R1_FB11 = 11;            // Filter bits
    static const uint8_t F8R1_FB12 = 12;            // Filter bits
    static const uint8_t F8R1_FB13 = 13;            // Filter bits
    static const uint8_t F8R1_FB14 = 14;            // Filter bits
    static const uint8_t F8R1_FB15 = 15;            // Filter bits
    static const uint8_t F8R1_FB16 = 16;            // Filter bits
    static const uint8_t F8R1_FB17 = 17;            // Filter bits
    static const uint8_t F8R1_FB18 = 18;            // Filter bits
    static const uint8_t F8R1_FB19 = 19;            // Filter bits
    static const uint8_t F8R1_FB20 = 20;            // Filter bits
    static const uint8_t F8R1_FB21 = 21;            // Filter bits
    static const uint8_t F8R1_FB22 = 22;            // Filter bits
    static const uint8_t F8R1_FB23 = 23;            // Filter bits
    static const uint8_t F8R1_FB24 = 24;            // Filter bits
    static const uint8_t F8R1_FB25 = 25;            // Filter bits
    static const uint8_t F8R1_FB26 = 26;            // Filter bits
    static const uint8_t F8R1_FB27 = 27;            // Filter bits
    static const uint8_t F8R1_FB28 = 28;            // Filter bits
    static const uint8_t F8R1_FB29 = 29;            // Filter bits
    static const uint8_t F8R1_FB30 = 30;            // Filter bits
    static const uint8_t F8R1_FB31 = 31;            // Filter bits
    static const uint32_t F8R1_RESET_VALUE = 0x0;

    static const uint8_t F8R2_FB0 = 0;              // Filter bits
    static const uint8_t F8R2_FB1 = 1;              // Filter bits
    static const uint8_t F8R2_FB2 = 2;              // Filter bits
    static const uint8_t F8R2_FB3 = 3;              // Filter bits
    static const uint8_t F8R2_FB4 = 4;              // Filter bits
    static const uint8_t F8R2_FB5 = 5;              // Filter bits
    static const uint8_t F8R2_FB6 = 6;              // Filter bits
    static const uint8_t F8R2_FB7 = 7;              // Filter bits
    static const uint8_t F8R2_FB8 = 8;              // Filter bits
    static const uint8_t F8R2_FB9 = 9;              // Filter bits
    static const uint8_t F8R2_FB10 = 10;            // Filter bits
    static const uint8_t F8R2_FB11 = 11;            // Filter bits
    static const uint8_t F8R2_FB12 = 12;            // Filter bits
    static const uint8_t F8R2_FB13 = 13;            // Filter bits
    static const uint8_t F8R2_FB14 = 14;            // Filter bits
    static const uint8_t F8R2_FB15 = 15;            // Filter bits
    static const uint8_t F8R2_FB16 = 16;            // Filter bits
    static const uint8_t F8R2_FB17 = 17;            // Filter bits
    static const uint8_t F8R2_FB18 = 18;            // Filter bits
    static const uint8_t F8R2_FB19 = 19;            // Filter bits
    static const uint8_t F8R2_FB20 = 20;            // Filter bits
    static const uint8_t F8R2_FB21 = 21;            // Filter bits
    static const uint8_t F8R2_FB22 = 22;            // Filter bits
    static const uint8_t F8R2_FB23 = 23;            // Filter bits
    static const uint8_t F8R2_FB24 = 24;            // Filter bits
    static const uint8_t F8R2_FB25 = 25;            // Filter bits
    static const uint8_t F8R2_FB26 = 26;            // Filter bits
    static const uint8_t F8R2_FB27 = 27;            // Filter bits
    static const uint8_t F8R2_FB28 = 28;            // Filter bits
    static const uint8_t F8R2_FB29 = 29;            // Filter bits
    static const uint8_t F8R2_FB30 = 30;            // Filter bits
    static const uint8_t F8R2_FB31 = 31;            // Filter bits
    static const uint32_t F8R2_RESET_VALUE = 0x0;

    static const uint8_t F9R1_FB0 = 0;              // Filter bits
    static const uint8_t F9R1_FB1 = 1;              // Filter bits
    static const uint8_t F9R1_FB2 = 2;              // Filter bits
    static const uint8_t F9R1_FB3 = 3;              // Filter bits
    static const uint8_t F9R1_FB4 = 4;              // Filter bits
    static const uint8_t F9R1_FB5 = 5;              // Filter bits
    static const uint8_t F9R1_FB6 = 6;              // Filter bits
    static const uint8_t F9R1_FB7 = 7;              // Filter bits
    static const uint8_t F9R1_FB8 = 8;              // Filter bits
    static const uint8_t F9R1_FB9 = 9;              // Filter bits
    static const uint8_t F9R1_FB10 = 10;            // Filter bits
    static const uint8_t F9R1_FB11 = 11;            // Filter bits
    static const uint8_t F9R1_FB12 = 12;            // Filter bits
    static const uint8_t F9R1_FB13 = 13;            // Filter bits
    static const uint8_t F9R1_FB14 = 14;            // Filter bits
    static const uint8_t F9R1_FB15 = 15;            // Filter bits
    static const uint8_t F9R1_FB16 = 16;            // Filter bits
    static const uint8_t F9R1_FB17 = 17;            // Filter bits
    static const uint8_t F9R1_FB18 = 18;            // Filter bits
    static const uint8_t F9R1_FB19 = 19;            // Filter bits
    static const uint8_t F9R1_FB20 = 20;            // Filter bits
    static const uint8_t F9R1_FB21 = 21;            // Filter bits
    static const uint8_t F9R1_FB22 = 22;            // Filter bits
    static const uint8_t F9R1_FB23 = 23;            // Filter bits
    static const uint8_t F9R1_FB24 = 24;            // Filter bits
    static const uint8_t F9R1_FB25 = 25;            // Filter bits
    static const uint8_t F9R1_FB26 = 26;            // Filter bits
    static const uint8_t F9R1_FB27 = 27;            // Filter bits
    static const uint8_t F9R1_FB28 = 28;            // Filter bits
    static const uint8_t F9R1_FB29 = 29;            // Filter bits
    static const uint8_t F9R1_FB30 = 30;            // Filter bits
    static const uint8_t F9R1_FB31 = 31;            // Filter bits
    static const uint32_t F9R1_RESET_VALUE = 0x0;

    static const uint8_t F9R2_FB0 = 0;              // Filter bits
    static const uint8_t F9R2_FB1 = 1;              // Filter bits
    static const uint8_t F9R2_FB2 = 2;              // Filter bits
    static const uint8_t F9R2_FB3 = 3;              // Filter bits
    static const uint8_t F9R2_FB4 = 4;              // Filter bits
    static const uint8_t F9R2_FB5 = 5;              // Filter bits
    static const uint8_t F9R2_FB6 = 6;              // Filter bits
    static const uint8_t F9R2_FB7 = 7;              // Filter bits
    static const uint8_t F9R2_FB8 = 8;              // Filter bits
    static const uint8_t F9R2_FB9 = 9;              // Filter bits
    static const uint8_t F9R2_FB10 = 10;            // Filter bits
    static const uint8_t F9R2_FB11 = 11;            // Filter bits
    static const uint8_t F9R2_FB12 = 12;            // Filter bits
    static const uint8_t F9R2_FB13 = 13;            // Filter bits
    static const uint8_t F9R2_FB14 = 14;            // Filter bits
    static const uint8_t F9R2_FB15 = 15;            // Filter bits
    static const uint8_t F9R2_FB16 = 16;            // Filter bits
    static const uint8_t F9R2_FB17 = 17;            // Filter bits
    static const uint8_t F9R2_FB18 = 18;            // Filter bits
    static const uint8_t F9R2_FB19 = 19;            // Filter bits
    static const uint8_t F9R2_FB20 = 20;            // Filter bits
    static const uint8_t F9R2_FB21 = 21;            // Filter bits
    static const uint8_t F9R2_FB22 = 22;            // Filter bits
    static const uint8_t F9R2_FB23 = 23;            // Filter bits
    static const uint8_t F9R2_FB24 = 24;            // Filter bits
    static const uint8_t F9R2_FB25 = 25;            // Filter bits
    static const uint8_t F9R2_FB26 = 26;            // Filter bits
    static const uint8_t F9R2_FB27 = 27;            // Filter bits
    static const uint8_t F9R2_FB28 = 28;            // Filter bits
    static const uint8_t F9R2_FB29 = 29;            // Filter bits
    static const uint8_t F9R2_FB30 = 30;            // Filter bits
    static const uint8_t F9R2_FB31 = 31;            // Filter bits
    static const uint32_t F9R2_RESET_VALUE = 0x0;

    static const uint8_t F10R1_FB0 = 0;              // Filter bits
    static const uint8_t F10R1_FB1 = 1;              // Filter bits
    static const uint8_t F10R1_FB2 = 2;              // Filter bits
    static const uint8_t F10R1_FB3 = 3;              // Filter bits
    static const uint8_t F10R1_FB4 = 4;              // Filter bits
    static const uint8_t F10R1_FB5 = 5;              // Filter bits
    static const uint8_t F10R1_FB6 = 6;              // Filter bits
    static const uint8_t F10R1_FB7 = 7;              // Filter bits
    static const uint8_t F10R1_FB8 = 8;              // Filter bits
    static const uint8_t F10R1_FB9 = 9;              // Filter bits
    static const uint8_t F10R1_FB10 = 10;            // Filter bits
    static const uint8_t F10R1_FB11 = 11;            // Filter bits
    static const uint8_t F10R1_FB12 = 12;            // Filter bits
    static const uint8_t F10R1_FB13 = 13;            // Filter bits
    static const uint8_t F10R1_FB14 = 14;            // Filter bits
    static const uint8_t F10R1_FB15 = 15;            // Filter bits
    static const uint8_t F10R1_FB16 = 16;            // Filter bits
    static const uint8_t F10R1_FB17 = 17;            // Filter bits
    static const uint8_t F10R1_FB18 = 18;            // Filter bits
    static const uint8_t F10R1_FB19 = 19;            // Filter bits
    static const uint8_t F10R1_FB20 = 20;            // Filter bits
    static const uint8_t F10R1_FB21 = 21;            // Filter bits
    static const uint8_t F10R1_FB22 = 22;            // Filter bits
    static const uint8_t F10R1_FB23 = 23;            // Filter bits
    static const uint8_t F10R1_FB24 = 24;            // Filter bits
    static const uint8_t F10R1_FB25 = 25;            // Filter bits
    static const uint8_t F10R1_FB26 = 26;            // Filter bits
    static const uint8_t F10R1_FB27 = 27;            // Filter bits
    static const uint8_t F10R1_FB28 = 28;            // Filter bits
    static const uint8_t F10R1_FB29 = 29;            // Filter bits
    static const uint8_t F10R1_FB30 = 30;            // Filter bits
    static const uint8_t F10R1_FB31 = 31;            // Filter bits
    static const uint32_t F10R1_RESET_VALUE = 0x0;

    static const uint8_t F10R2_FB0 = 0;              // Filter bits
    static const uint8_t F10R2_FB1 = 1;              // Filter bits
    static const uint8_t F10R2_FB2 = 2;              // Filter bits
    static const uint8_t F10R2_FB3 = 3;              // Filter bits
    static const uint8_t F10R2_FB4 = 4;              // Filter bits
    static const uint8_t F10R2_FB5 = 5;              // Filter bits
    static const uint8_t F10R2_FB6 = 6;              // Filter bits
    static const uint8_t F10R2_FB7 = 7;              // Filter bits
    static const uint8_t F10R2_FB8 = 8;              // Filter bits
    static const uint8_t F10R2_FB9 = 9;              // Filter bits
    static const uint8_t F10R2_FB10 = 10;            // Filter bits
    static const uint8_t F10R2_FB11 = 11;            // Filter bits
    static const uint8_t F10R2_FB12 = 12;            // Filter bits
    static const uint8_t F10R2_FB13 = 13;            // Filter bits
    static const uint8_t F10R2_FB14 = 14;            // Filter bits
    static const uint8_t F10R2_FB15 = 15;            // Filter bits
    static const uint8_t F10R2_FB16 = 16;            // Filter bits
    static const uint8_t F10R2_FB17 = 17;            // Filter bits
    static const uint8_t F10R2_FB18 = 18;            // Filter bits
    static const uint8_t F10R2_FB19 = 19;            // Filter bits
    static const uint8_t F10R2_FB20 = 20;            // Filter bits
    static const uint8_t F10R2_FB21 = 21;            // Filter bits
    static const uint8_t F10R2_FB22 = 22;            // Filter bits
    static const uint8_t F10R2_FB23 = 23;            // Filter bits
    static const uint8_t F10R2_FB24 = 24;            // Filter bits
    static const uint8_t F10R2_FB25 = 25;            // Filter bits
    static const uint8_t F10R2_FB26 = 26;            // Filter bits
    static const uint8_t F10R2_FB27 = 27;            // Filter bits
    static const uint8_t F10R2_FB28 = 28;            // Filter bits
    static const uint8_t F10R2_FB29 = 29;            // Filter bits
    static const uint8_t F10R2_FB30 = 30;            // Filter bits
    static const uint8_t F10R2_FB31 = 31;            // Filter bits
    static const uint32_t F10R2_RESET_VALUE = 0x0;

    static const uint8_t F11R1_FB0 = 0;              // Filter bits
    static const uint8_t F11R1_FB1 = 1;              // Filter bits
    static const uint8_t F11R1_FB2 = 2;              // Filter bits
    static const uint8_t F11R1_FB3 = 3;              // Filter bits
    static const uint8_t F11R1_FB4 = 4;              // Filter bits
    static const uint8_t F11R1_FB5 = 5;              // Filter bits
    static const uint8_t F11R1_FB6 = 6;              // Filter bits
    static const uint8_t F11R1_FB7 = 7;              // Filter bits
    static const uint8_t F11R1_FB8 = 8;              // Filter bits
    static const uint8_t F11R1_FB9 = 9;              // Filter bits
    static const uint8_t F11R1_FB10 = 10;            // Filter bits
    static const uint8_t F11R1_FB11 = 11;            // Filter bits
    static const uint8_t F11R1_FB12 = 12;            // Filter bits
    static const uint8_t F11R1_FB13 = 13;            // Filter bits
    static const uint8_t F11R1_FB14 = 14;            // Filter bits
    static const uint8_t F11R1_FB15 = 15;            // Filter bits
    static const uint8_t F11R1_FB16 = 16;            // Filter bits
    static const uint8_t F11R1_FB17 = 17;            // Filter bits
    static const uint8_t F11R1_FB18 = 18;            // Filter bits
    static const uint8_t F11R1_FB19 = 19;            // Filter bits
    static const uint8_t F11R1_FB20 = 20;            // Filter bits
    static const uint8_t F11R1_FB21 = 21;            // Filter bits
    static const uint8_t F11R1_FB22 = 22;            // Filter bits
    static const uint8_t F11R1_FB23 = 23;            // Filter bits
    static const uint8_t F11R1_FB24 = 24;            // Filter bits
    static const uint8_t F11R1_FB25 = 25;            // Filter bits
    static const uint8_t F11R1_FB26 = 26;            // Filter bits
    static const uint8_t F11R1_FB27 = 27;            // Filter bits
    static const uint8_t F11R1_FB28 = 28;            // Filter bits
    static const uint8_t F11R1_FB29 = 29;            // Filter bits
    static const uint8_t F11R1_FB30 = 30;            // Filter bits
    static const uint8_t F11R1_FB31 = 31;            // Filter bits
    static const uint32_t F11R1_RESET_VALUE = 0x0;

    static const uint8_t F11R2_FB0 = 0;              // Filter bits
    static const uint8_t F11R2_FB1 = 1;              // Filter bits
    static const uint8_t F11R2_FB2 = 2;              // Filter bits
    static const uint8_t F11R2_FB3 = 3;              // Filter bits
    static const uint8_t F11R2_FB4 = 4;              // Filter bits
    static const uint8_t F11R2_FB5 = 5;              // Filter bits
    static const uint8_t F11R2_FB6 = 6;              // Filter bits
    static const uint8_t F11R2_FB7 = 7;              // Filter bits
    static const uint8_t F11R2_FB8 = 8;              // Filter bits
    static const uint8_t F11R2_FB9 = 9;              // Filter bits
    static const uint8_t F11R2_FB10 = 10;            // Filter bits
    static const uint8_t F11R2_FB11 = 11;            // Filter bits
    static const uint8_t F11R2_FB12 = 12;            // Filter bits
    static const uint8_t F11R2_FB13 = 13;            // Filter bits
    static const uint8_t F11R2_FB14 = 14;            // Filter bits
    static const uint8_t F11R2_FB15 = 15;            // Filter bits
    static const uint8_t F11R2_FB16 = 16;            // Filter bits
    static const uint8_t F11R2_FB17 = 17;            // Filter bits
    static const uint8_t F11R2_FB18 = 18;            // Filter bits
    static const uint8_t F11R2_FB19 = 19;            // Filter bits
    static const uint8_t F11R2_FB20 = 20;            // Filter bits
    static const uint8_t F11R2_FB21 = 21;            // Filter bits
    static const uint8_t F11R2_FB22 = 22;            // Filter bits
    static const uint8_t F11R2_FB23 = 23;            // Filter bits
    static const uint8_t F11R2_FB24 = 24;            // Filter bits
    static const uint8_t F11R2_FB25 = 25;            // Filter bits
    static const uint8_t F11R2_FB26 = 26;            // Filter bits
    static const uint8_t F11R2_FB27 = 27;            // Filter bits
    static const uint8_t F11R2_FB28 = 28;            // Filter bits
    static const uint8_t F11R2_FB29 = 29;            // Filter bits
    static const uint8_t F11R2_FB30 = 30;            // Filter bits
    static const uint8_t F11R2_FB31 = 31;            // Filter bits
    static const uint32_t F11R2_RESET_VALUE = 0x0;

    static const uint8_t F12R1_FB0 = 0;              // Filter bits
    static const uint8_t F12R1_FB1 = 1;              // Filter bits
    static const uint8_t F12R1_FB2 = 2;              // Filter bits
    static const uint8_t F12R1_FB3 = 3;              // Filter bits
    static const uint8_t F12R1_FB4 = 4;              // Filter bits
    static const uint8_t F12R1_FB5 = 5;              // Filter bits
    static const uint8_t F12R1_FB6 = 6;              // Filter bits
    static const uint8_t F12R1_FB7 = 7;              // Filter bits
    static const uint8_t F12R1_FB8 = 8;              // Filter bits
    static const uint8_t F12R1_FB9 = 9;              // Filter bits
    static const uint8_t F12R1_FB10 = 10;            // Filter bits
    static const uint8_t F12R1_FB11 = 11;            // Filter bits
    static const uint8_t F12R1_FB12 = 12;            // Filter bits
    static const uint8_t F12R1_FB13 = 13;            // Filter bits
    static const uint8_t F12R1_FB14 = 14;            // Filter bits
    static const uint8_t F12R1_FB15 = 15;            // Filter bits
    static const uint8_t F12R1_FB16 = 16;            // Filter bits
    static const uint8_t F12R1_FB17 = 17;            // Filter bits
    static const uint8_t F12R1_FB18 = 18;            // Filter bits
    static const uint8_t F12R1_FB19 = 19;            // Filter bits
    static const uint8_t F12R1_FB20 = 20;            // Filter bits
    static const uint8_t F12R1_FB21 = 21;            // Filter bits
    static const uint8_t F12R1_FB22 = 22;            // Filter bits
    static const uint8_t F12R1_FB23 = 23;            // Filter bits
    static const uint8_t F12R1_FB24 = 24;            // Filter bits
    static const uint8_t F12R1_FB25 = 25;            // Filter bits
    static const uint8_t F12R1_FB26 = 26;            // Filter bits
    static const uint8_t F12R1_FB27 = 27;            // Filter bits
    static const uint8_t F12R1_FB28 = 28;            // Filter bits
    static const uint8_t F12R1_FB29 = 29;            // Filter bits
    static const uint8_t F12R1_FB30 = 30;            // Filter bits
    static const uint8_t F12R1_FB31 = 31;            // Filter bits
    static const uint32_t F12R1_RESET_VALUE = 0x0;

    static const uint8_t F12R2_FB0 = 0;              // Filter bits
    static const uint8_t F12R2_FB1 = 1;              // Filter bits
    static const uint8_t F12R2_FB2 = 2;              // Filter bits
    static const uint8_t F12R2_FB3 = 3;              // Filter bits
    static const uint8_t F12R2_FB4 = 4;              // Filter bits
    static const uint8_t F12R2_FB5 = 5;              // Filter bits
    static const uint8_t F12R2_FB6 = 6;              // Filter bits
    static const uint8_t F12R2_FB7 = 7;              // Filter bits
    static const uint8_t F12R2_FB8 = 8;              // Filter bits
    static const uint8_t F12R2_FB9 = 9;              // Filter bits
    static const uint8_t F12R2_FB10 = 10;            // Filter bits
    static const uint8_t F12R2_FB11 = 11;            // Filter bits
    static const uint8_t F12R2_FB12 = 12;            // Filter bits
    static const uint8_t F12R2_FB13 = 13;            // Filter bits
    static const uint8_t F12R2_FB14 = 14;            // Filter bits
    static const uint8_t F12R2_FB15 = 15;            // Filter bits
    static const uint8_t F12R2_FB16 = 16;            // Filter bits
    static const uint8_t F12R2_FB17 = 17;            // Filter bits
    static const uint8_t F12R2_FB18 = 18;            // Filter bits
    static const uint8_t F12R2_FB19 = 19;            // Filter bits
    static const uint8_t F12R2_FB20 = 20;            // Filter bits
    static const uint8_t F12R2_FB21 = 21;            // Filter bits
    static const uint8_t F12R2_FB22 = 22;            // Filter bits
    static const uint8_t F12R2_FB23 = 23;            // Filter bits
    static const uint8_t F12R2_FB24 = 24;            // Filter bits
    static const uint8_t F12R2_FB25 = 25;            // Filter bits
    static const uint8_t F12R2_FB26 = 26;            // Filter bits
    static const uint8_t F12R2_FB27 = 27;            // Filter bits
    static const uint8_t F12R2_FB28 = 28;            // Filter bits
    static const uint8_t F12R2_FB29 = 29;            // Filter bits
    static const uint8_t F12R2_FB30 = 30;            // Filter bits
    static const uint8_t F12R2_FB31 = 31;            // Filter bits
    static const uint32_t F12R2_RESET_VALUE = 0x0;

    static const uint8_t F13R1_FB0 = 0;              // Filter bits
    static const uint8_t F13R1_FB1 = 1;              // Filter bits
    static const uint8_t F13R1_FB2 = 2;              // Filter bits
    static const uint8_t F13R1_FB3 = 3;              // Filter bits
    static const uint8_t F13R1_FB4 = 4;              // Filter bits
    static const uint8_t F13R1_FB5 = 5;              // Filter bits
    static const uint8_t F13R1_FB6 = 6;              // Filter bits
    static const uint8_t F13R1_FB7 = 7;              // Filter bits
    static const uint8_t F13R1_FB8 = 8;              // Filter bits
    static const uint8_t F13R1_FB9 = 9;              // Filter bits
    static const uint8_t F13R1_FB10 = 10;            // Filter bits
    static const uint8_t F13R1_FB11 = 11;            // Filter bits
    static const uint8_t F13R1_FB12 = 12;            // Filter bits
    static const uint8_t F13R1_FB13 = 13;            // Filter bits
    static const uint8_t F13R1_FB14 = 14;            // Filter bits
    static const uint8_t F13R1_FB15 = 15;            // Filter bits
    static const uint8_t F13R1_FB16 = 16;            // Filter bits
    static const uint8_t F13R1_FB17 = 17;            // Filter bits
    static const uint8_t F13R1_FB18 = 18;            // Filter bits
    static const uint8_t F13R1_FB19 = 19;            // Filter bits
    static const uint8_t F13R1_FB20 = 20;            // Filter bits
    static const uint8_t F13R1_FB21 = 21;            // Filter bits
    static const uint8_t F13R1_FB22 = 22;            // Filter bits
    static const uint8_t F13R1_FB23 = 23;            // Filter bits
    static const uint8_t F13R1_FB24 = 24;            // Filter bits
    static const uint8_t F13R1_FB25 = 25;            // Filter bits
    static const uint8_t F13R1_FB26 = 26;            // Filter bits
    static const uint8_t F13R1_FB27 = 27;            // Filter bits
    static const uint8_t F13R1_FB28 = 28;            // Filter bits
    static const uint8_t F13R1_FB29 = 29;            // Filter bits
    static const uint8_t F13R1_FB30 = 30;            // Filter bits
    static const uint8_t F13R1_FB31 = 31;            // Filter bits
    static const uint32_t F13R1_RESET_VALUE = 0x0;

    static const uint8_t F13R2_FB0 = 0;              // Filter bits
    static const uint8_t F13R2_FB1 = 1;              // Filter bits
    static const uint8_t F13R2_FB2 = 2;              // Filter bits
    static const uint8_t F13R2_FB3 = 3;              // Filter bits
    static const uint8_t F13R2_FB4 = 4;              // Filter bits
    static const uint8_t F13R2_FB5 = 5;              // Filter bits
    static const uint8_t F13R2_FB6 = 6;              // Filter bits
    static const uint8_t F13R2_FB7 = 7;              // Filter bits
    static const uint8_t F13R2_FB8 = 8;              // Filter bits
    static const uint8_t F13R2_FB9 = 9;              // Filter bits
    static const uint8_t F13R2_FB10 = 10;            // Filter bits
    static const uint8_t F13R2_FB11 = 11;            // Filter bits
    static const uint8_t F13R2_FB12 = 12;            // Filter bits
    static const uint8_t F13R2_FB13 = 13;            // Filter bits
    static const uint8_t F13R2_FB14 = 14;            // Filter bits
    static const uint8_t F13R2_FB15 = 15;            // Filter bits
    static const uint8_t F13R2_FB16 = 16;            // Filter bits
    static const uint8_t F13R2_FB17 = 17;            // Filter bits
    static const uint8_t F13R2_FB18 = 18;            // Filter bits
    static const uint8_t F13R2_FB19 = 19;            // Filter bits
    static const uint8_t F13R2_FB20 = 20;            // Filter bits
    static const uint8_t F13R2_FB21 = 21;            // Filter bits
    static const uint8_t F13R2_FB22 = 22;            // Filter bits
    static const uint8_t F13R2_FB23 = 23;            // Filter bits
    static const uint8_t F13R2_FB24 = 24;            // Filter bits
    static const uint8_t F13R2_FB25 = 25;            // Filter bits
    static const uint8_t F13R2_FB26 = 26;            // Filter bits
    static const uint8_t F13R2_FB27 = 27;            // Filter bits
    static const uint8_t F13R2_FB28 = 28;            // Filter bits
    static const uint8_t F13R2_FB29 = 29;            // Filter bits
    static const uint8_t F13R2_FB30 = 30;            // Filter bits
    static const uint8_t F13R2_FB31 = 31;            // Filter bits
    static const uint32_t F13R2_RESET_VALUE = 0x0;

    static const uint8_t F14R1_FB0 = 0;              // Filter bits
    static const uint8_t F14R1_FB1 = 1;              // Filter bits
    static const uint8_t F14R1_FB2 = 2;              // Filter bits
    static const uint8_t F14R1_FB3 = 3;              // Filter bits
    static const uint8_t F14R1_FB4 = 4;              // Filter bits
    static const uint8_t F14R1_FB5 = 5;              // Filter bits
    static const uint8_t F14R1_FB6 = 6;              // Filter bits
    static const uint8_t F14R1_FB7 = 7;              // Filter bits
    static const uint8_t F14R1_FB8 = 8;              // Filter bits
    static const uint8_t F14R1_FB9 = 9;              // Filter bits
    static const uint8_t F14R1_FB10 = 10;            // Filter bits
    static const uint8_t F14R1_FB11 = 11;            // Filter bits
    static const uint8_t F14R1_FB12 = 12;            // Filter bits
    static const uint8_t F14R1_FB13 = 13;            // Filter bits
    static const uint8_t F14R1_FB14 = 14;            // Filter bits
    static const uint8_t F14R1_FB15 = 15;            // Filter bits
    static const uint8_t F14R1_FB16 = 16;            // Filter bits
    static const uint8_t F14R1_FB17 = 17;            // Filter bits
    static const uint8_t F14R1_FB18 = 18;            // Filter bits
    static const uint8_t F14R1_FB19 = 19;            // Filter bits
    static const uint8_t F14R1_FB20 = 20;            // Filter bits
    static const uint8_t F14R1_FB21 = 21;            // Filter bits
    static const uint8_t F14R1_FB22 = 22;            // Filter bits
    static const uint8_t F14R1_FB23 = 23;            // Filter bits
    static const uint8_t F14R1_FB24 = 24;            // Filter bits
    static const uint8_t F14R1_FB25 = 25;            // Filter bits
    static const uint8_t F14R1_FB26 = 26;            // Filter bits
    static const uint8_t F14R1_FB27 = 27;            // Filter bits
    static const uint8_t F14R1_FB28 = 28;            // Filter bits
    static const uint8_t F14R1_FB29 = 29;            // Filter bits
    static const uint8_t F14R1_FB30 = 30;            // Filter bits
    static const uint8_t F14R1_FB31 = 31;            // Filter bits
    static const uint32_t F14R1_RESET_VALUE = 0x0;

    static const uint8_t F14R2_FB0 = 0;              // Filter bits
    static const uint8_t F14R2_FB1 = 1;              // Filter bits
    static const uint8_t F14R2_FB2 = 2;              // Filter bits
    static const uint8_t F14R2_FB3 = 3;              // Filter bits
    static const uint8_t F14R2_FB4 = 4;              // Filter bits
    static const uint8_t F14R2_FB5 = 5;              // Filter bits
    static const uint8_t F14R2_FB6 = 6;              // Filter bits
    static const uint8_t F14R2_FB7 = 7;              // Filter bits
    static const uint8_t F14R2_FB8 = 8;              // Filter bits
    static const uint8_t F14R2_FB9 = 9;              // Filter bits
    static const uint8_t F14R2_FB10 = 10;            // Filter bits
    static const uint8_t F14R2_FB11 = 11;            // Filter bits
    static const uint8_t F14R2_FB12 = 12;            // Filter bits
    static const uint8_t F14R2_FB13 = 13;            // Filter bits
    static const uint8_t F14R2_FB14 = 14;            // Filter bits
    static const uint8_t F14R2_FB15 = 15;            // Filter bits
    static const uint8_t F14R2_FB16 = 16;            // Filter bits
    static const uint8_t F14R2_FB17 = 17;            // Filter bits
    static const uint8_t F14R2_FB18 = 18;            // Filter bits
    static const uint8_t F14R2_FB19 = 19;            // Filter bits
    static const uint8_t F14R2_FB20 = 20;            // Filter bits
    static const uint8_t F14R2_FB21 = 21;            // Filter bits
    static const uint8_t F14R2_FB22 = 22;            // Filter bits
    static const uint8_t F14R2_FB23 = 23;            // Filter bits
    static const uint8_t F14R2_FB24 = 24;            // Filter bits
    static const uint8_t F14R2_FB25 = 25;            // Filter bits
    static const uint8_t F14R2_FB26 = 26;            // Filter bits
    static const uint8_t F14R2_FB27 = 27;            // Filter bits
    static const uint8_t F14R2_FB28 = 28;            // Filter bits
    static const uint8_t F14R2_FB29 = 29;            // Filter bits
    static const uint8_t F14R2_FB30 = 30;            // Filter bits
    static const uint8_t F14R2_FB31 = 31;            // Filter bits
    static const uint32_t F14R2_RESET_VALUE = 0x0;

    static const uint8_t F15R1_FB0 = 0;              // Filter bits
    static const uint8_t F15R1_FB1 = 1;              // Filter bits
    static const uint8_t F15R1_FB2 = 2;              // Filter bits
    static const uint8_t F15R1_FB3 = 3;              // Filter bits
    static const uint8_t F15R1_FB4 = 4;              // Filter bits
    static const uint8_t F15R1_FB5 = 5;              // Filter bits
    static const uint8_t F15R1_FB6 = 6;              // Filter bits
    static const uint8_t F15R1_FB7 = 7;              // Filter bits
    static const uint8_t F15R1_FB8 = 8;              // Filter bits
    static const uint8_t F15R1_FB9 = 9;              // Filter bits
    static const uint8_t F15R1_FB10 = 10;            // Filter bits
    static const uint8_t F15R1_FB11 = 11;            // Filter bits
    static const uint8_t F15R1_FB12 = 12;            // Filter bits
    static const uint8_t F15R1_FB13 = 13;            // Filter bits
    static const uint8_t F15R1_FB14 = 14;            // Filter bits
    static const uint8_t F15R1_FB15 = 15;            // Filter bits
    static const uint8_t F15R1_FB16 = 16;            // Filter bits
    static const uint8_t F15R1_FB17 = 17;            // Filter bits
    static const uint8_t F15R1_FB18 = 18;            // Filter bits
    static const uint8_t F15R1_FB19 = 19;            // Filter bits
    static const uint8_t F15R1_FB20 = 20;            // Filter bits
    static const uint8_t F15R1_FB21 = 21;            // Filter bits
    static const uint8_t F15R1_FB22 = 22;            // Filter bits
    static const uint8_t F15R1_FB23 = 23;            // Filter bits
    static const uint8_t F15R1_FB24 = 24;            // Filter bits
    static const uint8_t F15R1_FB25 = 25;            // Filter bits
    static const uint8_t F15R1_FB26 = 26;            // Filter bits
    static const uint8_t F15R1_FB27 = 27;            // Filter bits
    static const uint8_t F15R1_FB28 = 28;            // Filter bits
    static const uint8_t F15R1_FB29 = 29;            // Filter bits
    static const uint8_t F15R1_FB30 = 30;            // Filter bits
    static const uint8_t F15R1_FB31 = 31;            // Filter bits
    static const uint32_t F15R1_RESET_VALUE = 0x0;

    static const uint8_t F15R2_FB0 = 0;              // Filter bits
    static const uint8_t F15R2_FB1 = 1;              // Filter bits
    static const uint8_t F15R2_FB2 = 2;              // Filter bits
    static const uint8_t F15R2_FB3 = 3;              // Filter bits
    static const uint8_t F15R2_FB4 = 4;              // Filter bits
    static const uint8_t F15R2_FB5 = 5;              // Filter bits
    static const uint8_t F15R2_FB6 = 6;              // Filter bits
    static const uint8_t F15R2_FB7 = 7;              // Filter bits
    static const uint8_t F15R2_FB8 = 8;              // Filter bits
    static const uint8_t F15R2_FB9 = 9;              // Filter bits
    static const uint8_t F15R2_FB10 = 10;            // Filter bits
    static const uint8_t F15R2_FB11 = 11;            // Filter bits
    static const uint8_t F15R2_FB12 = 12;            // Filter bits
    static const uint8_t F15R2_FB13 = 13;            // Filter bits
    static const uint8_t F15R2_FB14 = 14;            // Filter bits
    static const uint8_t F15R2_FB15 = 15;            // Filter bits
    static const uint8_t F15R2_FB16 = 16;            // Filter bits
    static const uint8_t F15R2_FB17 = 17;            // Filter bits
    static const uint8_t F15R2_FB18 = 18;            // Filter bits
    static const uint8_t F15R2_FB19 = 19;            // Filter bits
    static const uint8_t F15R2_FB20 = 20;            // Filter bits
    static const uint8_t F15R2_FB21 = 21;            // Filter bits
    static const uint8_t F15R2_FB22 = 22;            // Filter bits
    static const uint8_t F15R2_FB23 = 23;            // Filter bits
    static const uint8_t F15R2_FB24 = 24;            // Filter bits
    static const uint8_t F15R2_FB25 = 25;            // Filter bits
    static const uint8_t F15R2_FB26 = 26;            // Filter bits
    static const uint8_t F15R2_FB27 = 27;            // Filter bits
    static const uint8_t F15R2_FB28 = 28;            // Filter bits
    static const uint8_t F15R2_FB29 = 29;            // Filter bits
    static const uint8_t F15R2_FB30 = 30;            // Filter bits
    static const uint8_t F15R2_FB31 = 31;            // Filter bits
    static const uint32_t F15R2_RESET_VALUE = 0x0;

    static const uint8_t F16R1_FB0 = 0;              // Filter bits
    static const uint8_t F16R1_FB1 = 1;              // Filter bits
    static const uint8_t F16R1_FB2 = 2;              // Filter bits
    static const uint8_t F16R1_FB3 = 3;              // Filter bits
    static const uint8_t F16R1_FB4 = 4;              // Filter bits
    static const uint8_t F16R1_FB5 = 5;              // Filter bits
    static const uint8_t F16R1_FB6 = 6;              // Filter bits
    static const uint8_t F16R1_FB7 = 7;              // Filter bits
    static const uint8_t F16R1_FB8 = 8;              // Filter bits
    static const uint8_t F16R1_FB9 = 9;              // Filter bits
    static const uint8_t F16R1_FB10 = 10;            // Filter bits
    static const uint8_t F16R1_FB11 = 11;            // Filter bits
    static const uint8_t F16R1_FB12 = 12;            // Filter bits
    static const uint8_t F16R1_FB13 = 13;            // Filter bits
    static const uint8_t F16R1_FB14 = 14;            // Filter bits
    static const uint8_t F16R1_FB15 = 15;            // Filter bits
    static const uint8_t F16R1_FB16 = 16;            // Filter bits
    static const uint8_t F16R1_FB17 = 17;            // Filter bits
    static const uint8_t F16R1_FB18 = 18;            // Filter bits
    static const uint8_t F16R1_FB19 = 19;            // Filter bits
    static const uint8_t F16R1_FB20 = 20;            // Filter bits
    static const uint8_t F16R1_FB21 = 21;            // Filter bits
    static const uint8_t F16R1_FB22 = 22;            // Filter bits
    static const uint8_t F16R1_FB23 = 23;            // Filter bits
    static const uint8_t F16R1_FB24 = 24;            // Filter bits
    static const uint8_t F16R1_FB25 = 25;            // Filter bits
    static const uint8_t F16R1_FB26 = 26;            // Filter bits
    static const uint8_t F16R1_FB27 = 27;            // Filter bits
    static const uint8_t F16R1_FB28 = 28;            // Filter bits
    static const uint8_t F16R1_FB29 = 29;            // Filter bits
    static const uint8_t F16R1_FB30 = 30;            // Filter bits
    static const uint8_t F16R1_FB31 = 31;            // Filter bits
    static const uint32_t F16R1_RESET_VALUE = 0x0;

    static const uint8_t F16R2_FB0 = 0;              // Filter bits
    static const uint8_t F16R2_FB1 = 1;              // Filter bits
    static const uint8_t F16R2_FB2 = 2;              // Filter bits
    static const uint8_t F16R2_FB3 = 3;              // Filter bits
    static const uint8_t F16R2_FB4 = 4;              // Filter bits
    static const uint8_t F16R2_FB5 = 5;              // Filter bits
    static const uint8_t F16R2_FB6 = 6;              // Filter bits
    static const uint8_t F16R2_FB7 = 7;              // Filter bits
    static const uint8_t F16R2_FB8 = 8;              // Filter bits
    static const uint8_t F16R2_FB9 = 9;              // Filter bits
    static const uint8_t F16R2_FB10 = 10;            // Filter bits
    static const uint8_t F16R2_FB11 = 11;            // Filter bits
    static const uint8_t F16R2_FB12 = 12;            // Filter bits
    static const uint8_t F16R2_FB13 = 13;            // Filter bits
    static const uint8_t F16R2_FB14 = 14;            // Filter bits
    static const uint8_t F16R2_FB15 = 15;            // Filter bits
    static const uint8_t F16R2_FB16 = 16;            // Filter bits
    static const uint8_t F16R2_FB17 = 17;            // Filter bits
    static const uint8_t F16R2_FB18 = 18;            // Filter bits
    static const uint8_t F16R2_FB19 = 19;            // Filter bits
    static const uint8_t F16R2_FB20 = 20;            // Filter bits
    static const uint8_t F16R2_FB21 = 21;            // Filter bits
    static const uint8_t F16R2_FB22 = 22;            // Filter bits
    static const uint8_t F16R2_FB23 = 23;            // Filter bits
    static const uint8_t F16R2_FB24 = 24;            // Filter bits
    static const uint8_t F16R2_FB25 = 25;            // Filter bits
    static const uint8_t F16R2_FB26 = 26;            // Filter bits
    static const uint8_t F16R2_FB27 = 27;            // Filter bits
    static const uint8_t F16R2_FB28 = 28;            // Filter bits
    static const uint8_t F16R2_FB29 = 29;            // Filter bits
    static const uint8_t F16R2_FB30 = 30;            // Filter bits
    static const uint8_t F16R2_FB31 = 31;            // Filter bits
    static const uint32_t F16R2_RESET_VALUE = 0x0;

    static const uint8_t F17R1_FB0 = 0;              // Filter bits
    static const uint8_t F17R1_FB1 = 1;              // Filter bits
    static const uint8_t F17R1_FB2 = 2;              // Filter bits
    static const uint8_t F17R1_FB3 = 3;              // Filter bits
    static const uint8_t F17R1_FB4 = 4;              // Filter bits
    static const uint8_t F17R1_FB5 = 5;              // Filter bits
    static const uint8_t F17R1_FB6 = 6;              // Filter bits
    static const uint8_t F17R1_FB7 = 7;              // Filter bits
    static const uint8_t F17R1_FB8 = 8;              // Filter bits
    static const uint8_t F17R1_FB9 = 9;              // Filter bits
    static const uint8_t F17R1_FB10 = 10;            // Filter bits
    static const uint8_t F17R1_FB11 = 11;            // Filter bits
    static const uint8_t F17R1_FB12 = 12;            // Filter bits
    static const uint8_t F17R1_FB13 = 13;            // Filter bits
    static const uint8_t F17R1_FB14 = 14;            // Filter bits
    static const uint8_t F17R1_FB15 = 15;            // Filter bits
    static const uint8_t F17R1_FB16 = 16;            // Filter bits
    static const uint8_t F17R1_FB17 = 17;            // Filter bits
    static const uint8_t F17R1_FB18 = 18;            // Filter bits
    static const uint8_t F17R1_FB19 = 19;            // Filter bits
    static const uint8_t F17R1_FB20 = 20;            // Filter bits
    static const uint8_t F17R1_FB21 = 21;            // Filter bits
    static const uint8_t F17R1_FB22 = 22;            // Filter bits
    static const uint8_t F17R1_FB23 = 23;            // Filter bits
    static const uint8_t F17R1_FB24 = 24;            // Filter bits
    static const uint8_t F17R1_FB25 = 25;            // Filter bits
    static const uint8_t F17R1_FB26 = 26;            // Filter bits
    static const uint8_t F17R1_FB27 = 27;            // Filter bits
    static const uint8_t F17R1_FB28 = 28;            // Filter bits
    static const uint8_t F17R1_FB29 = 29;            // Filter bits
    static const uint8_t F17R1_FB30 = 30;            // Filter bits
    static const uint8_t F17R1_FB31 = 31;            // Filter bits
    static const uint32_t F17R1_RESET_VALUE = 0x0;

    static const uint8_t F17R2_FB0 = 0;              // Filter bits
    static const uint8_t F17R2_FB1 = 1;              // Filter bits
    static const uint8_t F17R2_FB2 = 2;              // Filter bits
    static const uint8_t F17R2_FB3 = 3;              // Filter bits
    static const uint8_t F17R2_FB4 = 4;              // Filter bits
    static const uint8_t F17R2_FB5 = 5;              // Filter bits
    static const uint8_t F17R2_FB6 = 6;              // Filter bits
    static const uint8_t F17R2_FB7 = 7;              // Filter bits
    static const uint8_t F17R2_FB8 = 8;              // Filter bits
    static const uint8_t F17R2_FB9 = 9;              // Filter bits
    static const uint8_t F17R2_FB10 = 10;            // Filter bits
    static const uint8_t F17R2_FB11 = 11;            // Filter bits
    static const uint8_t F17R2_FB12 = 12;            // Filter bits
    static const uint8_t F17R2_FB13 = 13;            // Filter bits
    static const uint8_t F17R2_FB14 = 14;            // Filter bits
    static const uint8_t F17R2_FB15 = 15;            // Filter bits
    static const uint8_t F17R2_FB16 = 16;            // Filter bits
    static const uint8_t F17R2_FB17 = 17;            // Filter bits
    static const uint8_t F17R2_FB18 = 18;            // Filter bits
    static const uint8_t F17R2_FB19 = 19;            // Filter bits
    static const uint8_t F17R2_FB20 = 20;            // Filter bits
    static const uint8_t F17R2_FB21 = 21;            // Filter bits
    static const uint8_t F17R2_FB22 = 22;            // Filter bits
    static const uint8_t F17R2_FB23 = 23;            // Filter bits
    static const uint8_t F17R2_FB24 = 24;            // Filter bits
    static const uint8_t F17R2_FB25 = 25;            // Filter bits
    static const uint8_t F17R2_FB26 = 26;            // Filter bits
    static const uint8_t F17R2_FB27 = 27;            // Filter bits
    static const uint8_t F17R2_FB28 = 28;            // Filter bits
    static const uint8_t F17R2_FB29 = 29;            // Filter bits
    static const uint8_t F17R2_FB30 = 30;            // Filter bits
    static const uint8_t F17R2_FB31 = 31;            // Filter bits
    static const uint32_t F17R2_RESET_VALUE = 0x0;

    static const uint8_t F18R1_FB0 = 0;              // Filter bits
    static const uint8_t F18R1_FB1 = 1;              // Filter bits
    static const uint8_t F18R1_FB2 = 2;              // Filter bits
    static const uint8_t F18R1_FB3 = 3;              // Filter bits
    static const uint8_t F18R1_FB4 = 4;              // Filter bits
    static const uint8_t F18R1_FB5 = 5;              // Filter bits
    static const uint8_t F18R1_FB6 = 6;              // Filter bits
    static const uint8_t F18R1_FB7 = 7;              // Filter bits
    static const uint8_t F18R1_FB8 = 8;              // Filter bits
    static const uint8_t F18R1_FB9 = 9;              // Filter bits
    static const uint8_t F18R1_FB10 = 10;            // Filter bits
    static const uint8_t F18R1_FB11 = 11;            // Filter bits
    static const uint8_t F18R1_FB12 = 12;            // Filter bits
    static const uint8_t F18R1_FB13 = 13;            // Filter bits
    static const uint8_t F18R1_FB14 = 14;            // Filter bits
    static const uint8_t F18R1_FB15 = 15;            // Filter bits
    static const uint8_t F18R1_FB16 = 16;            // Filter bits
    static const uint8_t F18R1_FB17 = 17;            // Filter bits
    static const uint8_t F18R1_FB18 = 18;            // Filter bits
    static const uint8_t F18R1_FB19 = 19;            // Filter bits
    static const uint8_t F18R1_FB20 = 20;            // Filter bits
    static const uint8_t F18R1_FB21 = 21;            // Filter bits
    static const uint8_t F18R1_FB22 = 22;            // Filter bits
    static const uint8_t F18R1_FB23 = 23;            // Filter bits
    static const uint8_t F18R1_FB24 = 24;            // Filter bits
    static const uint8_t F18R1_FB25 = 25;            // Filter bits
    static const uint8_t F18R1_FB26 = 26;            // Filter bits
    static const uint8_t F18R1_FB27 = 27;            // Filter bits
    static const uint8_t F18R1_FB28 = 28;            // Filter bits
    static const uint8_t F18R1_FB29 = 29;            // Filter bits
    static const uint8_t F18R1_FB30 = 30;            // Filter bits
    static const uint8_t F18R1_FB31 = 31;            // Filter bits
    static const uint32_t F18R1_RESET_VALUE = 0x0;

    static const uint8_t F18R2_FB0 = 0;              // Filter bits
    static const uint8_t F18R2_FB1 = 1;              // Filter bits
    static const uint8_t F18R2_FB2 = 2;              // Filter bits
    static const uint8_t F18R2_FB3 = 3;              // Filter bits
    static const uint8_t F18R2_FB4 = 4;              // Filter bits
    static const uint8_t F18R2_FB5 = 5;              // Filter bits
    static const uint8_t F18R2_FB6 = 6;              // Filter bits
    static const uint8_t F18R2_FB7 = 7;              // Filter bits
    static const uint8_t F18R2_FB8 = 8;              // Filter bits
    static const uint8_t F18R2_FB9 = 9;              // Filter bits
    static const uint8_t F18R2_FB10 = 10;            // Filter bits
    static const uint8_t F18R2_FB11 = 11;            // Filter bits
    static const uint8_t F18R2_FB12 = 12;            // Filter bits
    static const uint8_t F18R2_FB13 = 13;            // Filter bits
    static const uint8_t F18R2_FB14 = 14;            // Filter bits
    static const uint8_t F18R2_FB15 = 15;            // Filter bits
    static const uint8_t F18R2_FB16 = 16;            // Filter bits
    static const uint8_t F18R2_FB17 = 17;            // Filter bits
    static const uint8_t F18R2_FB18 = 18;            // Filter bits
    static const uint8_t F18R2_FB19 = 19;            // Filter bits
    static const uint8_t F18R2_FB20 = 20;            // Filter bits
    static const uint8_t F18R2_FB21 = 21;            // Filter bits
    static const uint8_t F18R2_FB22 = 22;            // Filter bits
    static const uint8_t F18R2_FB23 = 23;            // Filter bits
    static const uint8_t F18R2_FB24 = 24;            // Filter bits
    static const uint8_t F18R2_FB25 = 25;            // Filter bits
    static const uint8_t F18R2_FB26 = 26;            // Filter bits
    static const uint8_t F18R2_FB27 = 27;            // Filter bits
    static const uint8_t F18R2_FB28 = 28;            // Filter bits
    static const uint8_t F18R2_FB29 = 29;            // Filter bits
    static const uint8_t F18R2_FB30 = 30;            // Filter bits
    static const uint8_t F18R2_FB31 = 31;            // Filter bits
    static const uint32_t F18R2_RESET_VALUE = 0x0;

    static const uint8_t F19R1_FB0 = 0;              // Filter bits
    static const uint8_t F19R1_FB1 = 1;              // Filter bits
    static const uint8_t F19R1_FB2 = 2;              // Filter bits
    static const uint8_t F19R1_FB3 = 3;              // Filter bits
    static const uint8_t F19R1_FB4 = 4;              // Filter bits
    static const uint8_t F19R1_FB5 = 5;              // Filter bits
    static const uint8_t F19R1_FB6 = 6;              // Filter bits
    static const uint8_t F19R1_FB7 = 7;              // Filter bits
    static const uint8_t F19R1_FB8 = 8;              // Filter bits
    static const uint8_t F19R1_FB9 = 9;              // Filter bits
    static const uint8_t F19R1_FB10 = 10;            // Filter bits
    static const uint8_t F19R1_FB11 = 11;            // Filter bits
    static const uint8_t F19R1_FB12 = 12;            // Filter bits
    static const uint8_t F19R1_FB13 = 13;            // Filter bits
    static const uint8_t F19R1_FB14 = 14;            // Filter bits
    static const uint8_t F19R1_FB15 = 15;            // Filter bits
    static const uint8_t F19R1_FB16 = 16;            // Filter bits
    static const uint8_t F19R1_FB17 = 17;            // Filter bits
    static const uint8_t F19R1_FB18 = 18;            // Filter bits
    static const uint8_t F19R1_FB19 = 19;            // Filter bits
    static const uint8_t F19R1_FB20 = 20;            // Filter bits
    static const uint8_t F19R1_FB21 = 21;            // Filter bits
    static const uint8_t F19R1_FB22 = 22;            // Filter bits
    static const uint8_t F19R1_FB23 = 23;            // Filter bits
    static const uint8_t F19R1_FB24 = 24;            // Filter bits
    static const uint8_t F19R1_FB25 = 25;            // Filter bits
    static const uint8_t F19R1_FB26 = 26;            // Filter bits
    static const uint8_t F19R1_FB27 = 27;            // Filter bits
    static const uint8_t F19R1_FB28 = 28;            // Filter bits
    static const uint8_t F19R1_FB29 = 29;            // Filter bits
    static const uint8_t F19R1_FB30 = 30;            // Filter bits
    static const uint8_t F19R1_FB31 = 31;            // Filter bits
    static const uint32_t F19R1_RESET_VALUE = 0x0;

    static const uint8_t F19R2_FB0 = 0;              // Filter bits
    static const uint8_t F19R2_FB1 = 1;              // Filter bits
    static const uint8_t F19R2_FB2 = 2;              // Filter bits
    static const uint8_t F19R2_FB3 = 3;              // Filter bits
    static const uint8_t F19R2_FB4 = 4;              // Filter bits
    static const uint8_t F19R2_FB5 = 5;              // Filter bits
    static const uint8_t F19R2_FB6 = 6;              // Filter bits
    static const uint8_t F19R2_FB7 = 7;              // Filter bits
    static const uint8_t F19R2_FB8 = 8;              // Filter bits
    static const uint8_t F19R2_FB9 = 9;              // Filter bits
    static const uint8_t F19R2_FB10 = 10;            // Filter bits
    static const uint8_t F19R2_FB11 = 11;            // Filter bits
    static const uint8_t F19R2_FB12 = 12;            // Filter bits
    static const uint8_t F19R2_FB13 = 13;            // Filter bits
    static const uint8_t F19R2_FB14 = 14;            // Filter bits
    static const uint8_t F19R2_FB15 = 15;            // Filter bits
    static const uint8_t F19R2_FB16 = 16;            // Filter bits
    static const uint8_t F19R2_FB17 = 17;            // Filter bits
    static const uint8_t F19R2_FB18 = 18;            // Filter bits
    static const uint8_t F19R2_FB19 = 19;            // Filter bits
    static const uint8_t F19R2_FB20 = 20;            // Filter bits
    static const uint8_t F19R2_FB21 = 21;            // Filter bits
    static const uint8_t F19R2_FB22 = 22;            // Filter bits
    static const uint8_t F19R2_FB23 = 23;            // Filter bits
    static const uint8_t F19R2_FB24 = 24;            // Filter bits
    static const uint8_t F19R2_FB25 = 25;            // Filter bits
    static const uint8_t F19R2_FB26 = 26;            // Filter bits
    static const uint8_t F19R2_FB27 = 27;            // Filter bits
    static const uint8_t F19R2_FB28 = 28;            // Filter bits
    static const uint8_t F19R2_FB29 = 29;            // Filter bits
    static const uint8_t F19R2_FB30 = 30;            // Filter bits
    static const uint8_t F19R2_FB31 = 31;            // Filter bits
    static const uint32_t F19R2_RESET_VALUE = 0x0;

    static const uint8_t F20R1_FB0 = 0;              // Filter bits
    static const uint8_t F20R1_FB1 = 1;              // Filter bits
    static const uint8_t F20R1_FB2 = 2;              // Filter bits
    static const uint8_t F20R1_FB3 = 3;              // Filter bits
    static const uint8_t F20R1_FB4 = 4;              // Filter bits
    static const uint8_t F20R1_FB5 = 5;              // Filter bits
    static const uint8_t F20R1_FB6 = 6;              // Filter bits
    static const uint8_t F20R1_FB7 = 7;              // Filter bits
    static const uint8_t F20R1_FB8 = 8;              // Filter bits
    static const uint8_t F20R1_FB9 = 9;              // Filter bits
    static const uint8_t F20R1_FB10 = 10;            // Filter bits
    static const uint8_t F20R1_FB11 = 11;            // Filter bits
    static const uint8_t F20R1_FB12 = 12;            // Filter bits
    static const uint8_t F20R1_FB13 = 13;            // Filter bits
    static const uint8_t F20R1_FB14 = 14;            // Filter bits
    static const uint8_t F20R1_FB15 = 15;            // Filter bits
    static const uint8_t F20R1_FB16 = 16;            // Filter bits
    static const uint8_t F20R1_FB17 = 17;            // Filter bits
    static const uint8_t F20R1_FB18 = 18;            // Filter bits
    static const uint8_t F20R1_FB19 = 19;            // Filter bits
    static const uint8_t F20R1_FB20 = 20;            // Filter bits
    static const uint8_t F20R1_FB21 = 21;            // Filter bits
    static const uint8_t F20R1_FB22 = 22;            // Filter bits
    static const uint8_t F20R1_FB23 = 23;            // Filter bits
    static const uint8_t F20R1_FB24 = 24;            // Filter bits
    static const uint8_t F20R1_FB25 = 25;            // Filter bits
    static const uint8_t F20R1_FB26 = 26;            // Filter bits
    static const uint8_t F20R1_FB27 = 27;            // Filter bits
    static const uint8_t F20R1_FB28 = 28;            // Filter bits
    static const uint8_t F20R1_FB29 = 29;            // Filter bits
    static const uint8_t F20R1_FB30 = 30;            // Filter bits
    static const uint8_t F20R1_FB31 = 31;            // Filter bits
    static const uint32_t F20R1_RESET_VALUE = 0x0;

    static const uint8_t F20R2_FB0 = 0;              // Filter bits
    static const uint8_t F20R2_FB1 = 1;              // Filter bits
    static const uint8_t F20R2_FB2 = 2;              // Filter bits
    static const uint8_t F20R2_FB3 = 3;              // Filter bits
    static const uint8_t F20R2_FB4 = 4;              // Filter bits
    static const uint8_t F20R2_FB5 = 5;              // Filter bits
    static const uint8_t F20R2_FB6 = 6;              // Filter bits
    static const uint8_t F20R2_FB7 = 7;              // Filter bits
    static const uint8_t F20R2_FB8 = 8;              // Filter bits
    static const uint8_t F20R2_FB9 = 9;              // Filter bits
    static const uint8_t F20R2_FB10 = 10;            // Filter bits
    static const uint8_t F20R2_FB11 = 11;            // Filter bits
    static const uint8_t F20R2_FB12 = 12;            // Filter bits
    static const uint8_t F20R2_FB13 = 13;            // Filter bits
    static const uint8_t F20R2_FB14 = 14;            // Filter bits
    static const uint8_t F20R2_FB15 = 15;            // Filter bits
    static const uint8_t F20R2_FB16 = 16;            // Filter bits
    static const uint8_t F20R2_FB17 = 17;            // Filter bits
    static const uint8_t F20R2_FB18 = 18;            // Filter bits
    static const uint8_t F20R2_FB19 = 19;            // Filter bits
    static const uint8_t F20R2_FB20 = 20;            // Filter bits
    static const uint8_t F20R2_FB21 = 21;            // Filter bits
    static const uint8_t F20R2_FB22 = 22;            // Filter bits
    static const uint8_t F20R2_FB23 = 23;            // Filter bits
    static const uint8_t F20R2_FB24 = 24;            // Filter bits
    static const uint8_t F20R2_FB25 = 25;            // Filter bits
    static const uint8_t F20R2_FB26 = 26;            // Filter bits
    static const uint8_t F20R2_FB27 = 27;            // Filter bits
    static const uint8_t F20R2_FB28 = 28;            // Filter bits
    static const uint8_t F20R2_FB29 = 29;            // Filter bits
    static const uint8_t F20R2_FB30 = 30;            // Filter bits
    static const uint8_t F20R2_FB31 = 31;            // Filter bits
    static const uint32_t F20R2_RESET_VALUE = 0x0;

    static const uint8_t F21R1_FB0 = 0;              // Filter bits
    static const uint8_t F21R1_FB1 = 1;              // Filter bits
    static const uint8_t F21R1_FB2 = 2;              // Filter bits
    static const uint8_t F21R1_FB3 = 3;              // Filter bits
    static const uint8_t F21R1_FB4 = 4;              // Filter bits
    static const uint8_t F21R1_FB5 = 5;              // Filter bits
    static const uint8_t F21R1_FB6 = 6;              // Filter bits
    static const uint8_t F21R1_FB7 = 7;              // Filter bits
    static const uint8_t F21R1_FB8 = 8;              // Filter bits
    static const uint8_t F21R1_FB9 = 9;              // Filter bits
    static const uint8_t F21R1_FB10 = 10;            // Filter bits
    static const uint8_t F21R1_FB11 = 11;            // Filter bits
    static const uint8_t F21R1_FB12 = 12;            // Filter bits
    static const uint8_t F21R1_FB13 = 13;            // Filter bits
    static const uint8_t F21R1_FB14 = 14;            // Filter bits
    static const uint8_t F21R1_FB15 = 15;            // Filter bits
    static const uint8_t F21R1_FB16 = 16;            // Filter bits
    static const uint8_t F21R1_FB17 = 17;            // Filter bits
    static const uint8_t F21R1_FB18 = 18;            // Filter bits
    static const uint8_t F21R1_FB19 = 19;            // Filter bits
    static const uint8_t F21R1_FB20 = 20;            // Filter bits
    static const uint8_t F21R1_FB21 = 21;            // Filter bits
    static const uint8_t F21R1_FB22 = 22;            // Filter bits
    static const uint8_t F21R1_FB23 = 23;            // Filter bits
    static const uint8_t F21R1_FB24 = 24;            // Filter bits
    static const uint8_t F21R1_FB25 = 25;            // Filter bits
    static const uint8_t F21R1_FB26 = 26;            // Filter bits
    static const uint8_t F21R1_FB27 = 27;            // Filter bits
    static const uint8_t F21R1_FB28 = 28;            // Filter bits
    static const uint8_t F21R1_FB29 = 29;            // Filter bits
    static const uint8_t F21R1_FB30 = 30;            // Filter bits
    static const uint8_t F21R1_FB31 = 31;            // Filter bits
    static const uint32_t F21R1_RESET_VALUE = 0x0;

    static const uint8_t F21R2_FB0 = 0;              // Filter bits
    static const uint8_t F21R2_FB1 = 1;              // Filter bits
    static const uint8_t F21R2_FB2 = 2;              // Filter bits
    static const uint8_t F21R2_FB3 = 3;              // Filter bits
    static const uint8_t F21R2_FB4 = 4;              // Filter bits
    static const uint8_t F21R2_FB5 = 5;              // Filter bits
    static const uint8_t F21R2_FB6 = 6;              // Filter bits
    static const uint8_t F21R2_FB7 = 7;              // Filter bits
    static const uint8_t F21R2_FB8 = 8;              // Filter bits
    static const uint8_t F21R2_FB9 = 9;              // Filter bits
    static const uint8_t F21R2_FB10 = 10;            // Filter bits
    static const uint8_t F21R2_FB11 = 11;            // Filter bits
    static const uint8_t F21R2_FB12 = 12;            // Filter bits
    static const uint8_t F21R2_FB13 = 13;            // Filter bits
    static const uint8_t F21R2_FB14 = 14;            // Filter bits
    static const uint8_t F21R2_FB15 = 15;            // Filter bits
    static const uint8_t F21R2_FB16 = 16;            // Filter bits
    static const uint8_t F21R2_FB17 = 17;            // Filter bits
    static const uint8_t F21R2_FB18 = 18;            // Filter bits
    static const uint8_t F21R2_FB19 = 19;            // Filter bits
    static const uint8_t F21R2_FB20 = 20;            // Filter bits
    static const uint8_t F21R2_FB21 = 21;            // Filter bits
    static const uint8_t F21R2_FB22 = 22;            // Filter bits
    static const uint8_t F21R2_FB23 = 23;            // Filter bits
    static const uint8_t F21R2_FB24 = 24;            // Filter bits
    static const uint8_t F21R2_FB25 = 25;            // Filter bits
    static const uint8_t F21R2_FB26 = 26;            // Filter bits
    static const uint8_t F21R2_FB27 = 27;            // Filter bits
    static const uint8_t F21R2_FB28 = 28;            // Filter bits
    static const uint8_t F21R2_FB29 = 29;            // Filter bits
    static const uint8_t F21R2_FB30 = 30;            // Filter bits
    static const uint8_t F21R2_FB31 = 31;            // Filter bits
    static const uint32_t F21R2_RESET_VALUE = 0x0;

    static const uint8_t F22R1_FB0 = 0;              // Filter bits
    static const uint8_t F22R1_FB1 = 1;              // Filter bits
    static const uint8_t F22R1_FB2 = 2;              // Filter bits
    static const uint8_t F22R1_FB3 = 3;              // Filter bits
    static const uint8_t F22R1_FB4 = 4;              // Filter bits
    static const uint8_t F22R1_FB5 = 5;              // Filter bits
    static const uint8_t F22R1_FB6 = 6;              // Filter bits
    static const uint8_t F22R1_FB7 = 7;              // Filter bits
    static const uint8_t F22R1_FB8 = 8;              // Filter bits
    static const uint8_t F22R1_FB9 = 9;              // Filter bits
    static const uint8_t F22R1_FB10 = 10;            // Filter bits
    static const uint8_t F22R1_FB11 = 11;            // Filter bits
    static const uint8_t F22R1_FB12 = 12;            // Filter bits
    static const uint8_t F22R1_FB13 = 13;            // Filter bits
    static const uint8_t F22R1_FB14 = 14;            // Filter bits
    static const uint8_t F22R1_FB15 = 15;            // Filter bits
    static const uint8_t F22R1_FB16 = 16;            // Filter bits
    static const uint8_t F22R1_FB17 = 17;            // Filter bits
    static const uint8_t F22R1_FB18 = 18;            // Filter bits
    static const uint8_t F22R1_FB19 = 19;            // Filter bits
    static const uint8_t F22R1_FB20 = 20;            // Filter bits
    static const uint8_t F22R1_FB21 = 21;            // Filter bits
    static const uint8_t F22R1_FB22 = 22;            // Filter bits
    static const uint8_t F22R1_FB23 = 23;            // Filter bits
    static const uint8_t F22R1_FB24 = 24;            // Filter bits
    static const uint8_t F22R1_FB25 = 25;            // Filter bits
    static const uint8_t F22R1_FB26 = 26;            // Filter bits
    static const uint8_t F22R1_FB27 = 27;            // Filter bits
    static const uint8_t F22R1_FB28 = 28;            // Filter bits
    static const uint8_t F22R1_FB29 = 29;            // Filter bits
    static const uint8_t F22R1_FB30 = 30;            // Filter bits
    static const uint8_t F22R1_FB31 = 31;            // Filter bits
    static const uint32_t F22R1_RESET_VALUE = 0x0;

    static const uint8_t F22R2_FB0 = 0;              // Filter bits
    static const uint8_t F22R2_FB1 = 1;              // Filter bits
    static const uint8_t F22R2_FB2 = 2;              // Filter bits
    static const uint8_t F22R2_FB3 = 3;              // Filter bits
    static const uint8_t F22R2_FB4 = 4;              // Filter bits
    static const uint8_t F22R2_FB5 = 5;              // Filter bits
    static const uint8_t F22R2_FB6 = 6;              // Filter bits
    static const uint8_t F22R2_FB7 = 7;              // Filter bits
    static const uint8_t F22R2_FB8 = 8;              // Filter bits
    static const uint8_t F22R2_FB9 = 9;              // Filter bits
    static const uint8_t F22R2_FB10 = 10;            // Filter bits
    static const uint8_t F22R2_FB11 = 11;            // Filter bits
    static const uint8_t F22R2_FB12 = 12;            // Filter bits
    static const uint8_t F22R2_FB13 = 13;            // Filter bits
    static const uint8_t F22R2_FB14 = 14;            // Filter bits
    static const uint8_t F22R2_FB15 = 15;            // Filter bits
    static const uint8_t F22R2_FB16 = 16;            // Filter bits
    static const uint8_t F22R2_FB17 = 17;            // Filter bits
    static const uint8_t F22R2_FB18 = 18;            // Filter bits
    static const uint8_t F22R2_FB19 = 19;            // Filter bits
    static const uint8_t F22R2_FB20 = 20;            // Filter bits
    static const uint8_t F22R2_FB21 = 21;            // Filter bits
    static const uint8_t F22R2_FB22 = 22;            // Filter bits
    static const uint8_t F22R2_FB23 = 23;            // Filter bits
    static const uint8_t F22R2_FB24 = 24;            // Filter bits
    static const uint8_t F22R2_FB25 = 25;            // Filter bits
    static const uint8_t F22R2_FB26 = 26;            // Filter bits
    static const uint8_t F22R2_FB27 = 27;            // Filter bits
    static const uint8_t F22R2_FB28 = 28;            // Filter bits
    static const uint8_t F22R2_FB29 = 29;            // Filter bits
    static const uint8_t F22R2_FB30 = 30;            // Filter bits
    static const uint8_t F22R2_FB31 = 31;            // Filter bits
    static const uint32_t F22R2_RESET_VALUE = 0x0;

    static const uint8_t F23R1_FB0 = 0;              // Filter bits
    static const uint8_t F23R1_FB1 = 1;              // Filter bits
    static const uint8_t F23R1_FB2 = 2;              // Filter bits
    static const uint8_t F23R1_FB3 = 3;              // Filter bits
    static const uint8_t F23R1_FB4 = 4;              // Filter bits
    static const uint8_t F23R1_FB5 = 5;              // Filter bits
    static const uint8_t F23R1_FB6 = 6;              // Filter bits
    static const uint8_t F23R1_FB7 = 7;              // Filter bits
    static const uint8_t F23R1_FB8 = 8;              // Filter bits
    static const uint8_t F23R1_FB9 = 9;              // Filter bits
    static const uint8_t F23R1_FB10 = 10;            // Filter bits
    static const uint8_t F23R1_FB11 = 11;            // Filter bits
    static const uint8_t F23R1_FB12 = 12;            // Filter bits
    static const uint8_t F23R1_FB13 = 13;            // Filter bits
    static const uint8_t F23R1_FB14 = 14;            // Filter bits
    static const uint8_t F23R1_FB15 = 15;            // Filter bits
    static const uint8_t F23R1_FB16 = 16;            // Filter bits
    static const uint8_t F23R1_FB17 = 17;            // Filter bits
    static const uint8_t F23R1_FB18 = 18;            // Filter bits
    static const uint8_t F23R1_FB19 = 19;            // Filter bits
    static const uint8_t F23R1_FB20 = 20;            // Filter bits
    static const uint8_t F23R1_FB21 = 21;            // Filter bits
    static const uint8_t F23R1_FB22 = 22;            // Filter bits
    static const uint8_t F23R1_FB23 = 23;            // Filter bits
    static const uint8_t F23R1_FB24 = 24;            // Filter bits
    static const uint8_t F23R1_FB25 = 25;            // Filter bits
    static const uint8_t F23R1_FB26 = 26;            // Filter bits
    static const uint8_t F23R1_FB27 = 27;            // Filter bits
    static const uint8_t F23R1_FB28 = 28;            // Filter bits
    static const uint8_t F23R1_FB29 = 29;            // Filter bits
    static const uint8_t F23R1_FB30 = 30;            // Filter bits
    static const uint8_t F23R1_FB31 = 31;            // Filter bits
    static const uint32_t F23R1_RESET_VALUE = 0x0;

    static const uint8_t F23R2_FB0 = 0;              // Filter bits
    static const uint8_t F23R2_FB1 = 1;              // Filter bits
    static const uint8_t F23R2_FB2 = 2;              // Filter bits
    static const uint8_t F23R2_FB3 = 3;              // Filter bits
    static const uint8_t F23R2_FB4 = 4;              // Filter bits
    static const uint8_t F23R2_FB5 = 5;              // Filter bits
    static const uint8_t F23R2_FB6 = 6;              // Filter bits
    static const uint8_t F23R2_FB7 = 7;              // Filter bits
    static const uint8_t F23R2_FB8 = 8;              // Filter bits
    static const uint8_t F23R2_FB9 = 9;              // Filter bits
    static const uint8_t F23R2_FB10 = 10;            // Filter bits
    static const uint8_t F23R2_FB11 = 11;            // Filter bits
    static const uint8_t F23R2_FB12 = 12;            // Filter bits
    static const uint8_t F23R2_FB13 = 13;            // Filter bits
    static const uint8_t F23R2_FB14 = 14;            // Filter bits
    static const uint8_t F23R2_FB15 = 15;            // Filter bits
    static const uint8_t F23R2_FB16 = 16;            // Filter bits
    static const uint8_t F23R2_FB17 = 17;            // Filter bits
    static const uint8_t F23R2_FB18 = 18;            // Filter bits
    static const uint8_t F23R2_FB19 = 19;            // Filter bits
    static const uint8_t F23R2_FB20 = 20;            // Filter bits
    static const uint8_t F23R2_FB21 = 21;            // Filter bits
    static const uint8_t F23R2_FB22 = 22;            // Filter bits
    static const uint8_t F23R2_FB23 = 23;            // Filter bits
    static const uint8_t F23R2_FB24 = 24;            // Filter bits
    static const uint8_t F23R2_FB25 = 25;            // Filter bits
    static const uint8_t F23R2_FB26 = 26;            // Filter bits
    static const uint8_t F23R2_FB27 = 27;            // Filter bits
    static const uint8_t F23R2_FB28 = 28;            // Filter bits
    static const uint8_t F23R2_FB29 = 29;            // Filter bits
    static const uint8_t F23R2_FB30 = 30;            // Filter bits
    static const uint8_t F23R2_FB31 = 31;            // Filter bits
    static const uint32_t F23R2_RESET_VALUE = 0x0;

    static const uint8_t F24R1_FB0 = 0;              // Filter bits
    static const uint8_t F24R1_FB1 = 1;              // Filter bits
    static const uint8_t F24R1_FB2 = 2;              // Filter bits
    static const uint8_t F24R1_FB3 = 3;              // Filter bits
    static const uint8_t F24R1_FB4 = 4;              // Filter bits
    static const uint8_t F24R1_FB5 = 5;              // Filter bits
    static const uint8_t F24R1_FB6 = 6;              // Filter bits
    static const uint8_t F24R1_FB7 = 7;              // Filter bits
    static const uint8_t F24R1_FB8 = 8;              // Filter bits
    static const uint8_t F24R1_FB9 = 9;              // Filter bits
    static const uint8_t F24R1_FB10 = 10;            // Filter bits
    static const uint8_t F24R1_FB11 = 11;            // Filter bits
    static const uint8_t F24R1_FB12 = 12;            // Filter bits
    static const uint8_t F24R1_FB13 = 13;            // Filter bits
    static const uint8_t F24R1_FB14 = 14;            // Filter bits
    static const uint8_t F24R1_FB15 = 15;            // Filter bits
    static const uint8_t F24R1_FB16 = 16;            // Filter bits
    static const uint8_t F24R1_FB17 = 17;            // Filter bits
    static const uint8_t F24R1_FB18 = 18;            // Filter bits
    static const uint8_t F24R1_FB19 = 19;            // Filter bits
    static const uint8_t F24R1_FB20 = 20;            // Filter bits
    static const uint8_t F24R1_FB21 = 21;            // Filter bits
    static const uint8_t F24R1_FB22 = 22;            // Filter bits
    static const uint8_t F24R1_FB23 = 23;            // Filter bits
    static const uint8_t F24R1_FB24 = 24;            // Filter bits
    static const uint8_t F24R1_FB25 = 25;            // Filter bits
    static const uint8_t F24R1_FB26 = 26;            // Filter bits
    static const uint8_t F24R1_FB27 = 27;            // Filter bits
    static const uint8_t F24R1_FB28 = 28;            // Filter bits
    static const uint8_t F24R1_FB29 = 29;            // Filter bits
    static const uint8_t F24R1_FB30 = 30;            // Filter bits
    static const uint8_t F24R1_FB31 = 31;            // Filter bits
    static const uint32_t F24R1_RESET_VALUE = 0x0;

    static const uint8_t F24R2_FB0 = 0;              // Filter bits
    static const uint8_t F24R2_FB1 = 1;              // Filter bits
    static const uint8_t F24R2_FB2 = 2;              // Filter bits
    static const uint8_t F24R2_FB3 = 3;              // Filter bits
    static const uint8_t F24R2_FB4 = 4;              // Filter bits
    static const uint8_t F24R2_FB5 = 5;              // Filter bits
    static const uint8_t F24R2_FB6 = 6;              // Filter bits
    static const uint8_t F24R2_FB7 = 7;              // Filter bits
    static const uint8_t F24R2_FB8 = 8;              // Filter bits
    static const uint8_t F24R2_FB9 = 9;              // Filter bits
    static const uint8_t F24R2_FB10 = 10;            // Filter bits
    static const uint8_t F24R2_FB11 = 11;            // Filter bits
    static const uint8_t F24R2_FB12 = 12;            // Filter bits
    static const uint8_t F24R2_FB13 = 13;            // Filter bits
    static const uint8_t F24R2_FB14 = 14;            // Filter bits
    static const uint8_t F24R2_FB15 = 15;            // Filter bits
    static const uint8_t F24R2_FB16 = 16;            // Filter bits
    static const uint8_t F24R2_FB17 = 17;            // Filter bits
    static const uint8_t F24R2_FB18 = 18;            // Filter bits
    static const uint8_t F24R2_FB19 = 19;            // Filter bits
    static const uint8_t F24R2_FB20 = 20;            // Filter bits
    static const uint8_t F24R2_FB21 = 21;            // Filter bits
    static const uint8_t F24R2_FB22 = 22;            // Filter bits
    static const uint8_t F24R2_FB23 = 23;            // Filter bits
    static const uint8_t F24R2_FB24 = 24;            // Filter bits
    static const uint8_t F24R2_FB25 = 25;            // Filter bits
    static const uint8_t F24R2_FB26 = 26;            // Filter bits
    static const uint8_t F24R2_FB27 = 27;            // Filter bits
    static const uint8_t F24R2_FB28 = 28;            // Filter bits
    static const uint8_t F24R2_FB29 = 29;            // Filter bits
    static const uint8_t F24R2_FB30 = 30;            // Filter bits
    static const uint8_t F24R2_FB31 = 31;            // Filter bits
    static const uint32_t F24R2_RESET_VALUE = 0x0;

    static const uint8_t F25R1_FB0 = 0;              // Filter bits
    static const uint8_t F25R1_FB1 = 1;              // Filter bits
    static const uint8_t F25R1_FB2 = 2;              // Filter bits
    static const uint8_t F25R1_FB3 = 3;              // Filter bits
    static const uint8_t F25R1_FB4 = 4;              // Filter bits
    static const uint8_t F25R1_FB5 = 5;              // Filter bits
    static const uint8_t F25R1_FB6 = 6;              // Filter bits
    static const uint8_t F25R1_FB7 = 7;              // Filter bits
    static const uint8_t F25R1_FB8 = 8;              // Filter bits
    static const uint8_t F25R1_FB9 = 9;              // Filter bits
    static const uint8_t F25R1_FB10 = 10;            // Filter bits
    static const uint8_t F25R1_FB11 = 11;            // Filter bits
    static const uint8_t F25R1_FB12 = 12;            // Filter bits
    static const uint8_t F25R1_FB13 = 13;            // Filter bits
    static const uint8_t F25R1_FB14 = 14;            // Filter bits
    static const uint8_t F25R1_FB15 = 15;            // Filter bits
    static const uint8_t F25R1_FB16 = 16;            // Filter bits
    static const uint8_t F25R1_FB17 = 17;            // Filter bits
    static const uint8_t F25R1_FB18 = 18;            // Filter bits
    static const uint8_t F25R1_FB19 = 19;            // Filter bits
    static const uint8_t F25R1_FB20 = 20;            // Filter bits
    static const uint8_t F25R1_FB21 = 21;            // Filter bits
    static const uint8_t F25R1_FB22 = 22;            // Filter bits
    static const uint8_t F25R1_FB23 = 23;            // Filter bits
    static const uint8_t F25R1_FB24 = 24;            // Filter bits
    static const uint8_t F25R1_FB25 = 25;            // Filter bits
    static const uint8_t F25R1_FB26 = 26;            // Filter bits
    static const uint8_t F25R1_FB27 = 27;            // Filter bits
    static const uint8_t F25R1_FB28 = 28;            // Filter bits
    static const uint8_t F25R1_FB29 = 29;            // Filter bits
    static const uint8_t F25R1_FB30 = 30;            // Filter bits
    static const uint8_t F25R1_FB31 = 31;            // Filter bits
    static const uint32_t F25R1_RESET_VALUE = 0x0;

    static const uint8_t F25R2_FB0 = 0;              // Filter bits
    static const uint8_t F25R2_FB1 = 1;              // Filter bits
    static const uint8_t F25R2_FB2 = 2;              // Filter bits
    static const uint8_t F25R2_FB3 = 3;              // Filter bits
    static const uint8_t F25R2_FB4 = 4;              // Filter bits
    static const uint8_t F25R2_FB5 = 5;              // Filter bits
    static const uint8_t F25R2_FB6 = 6;              // Filter bits
    static const uint8_t F25R2_FB7 = 7;              // Filter bits
    static const uint8_t F25R2_FB8 = 8;              // Filter bits
    static const uint8_t F25R2_FB9 = 9;              // Filter bits
    static const uint8_t F25R2_FB10 = 10;            // Filter bits
    static const uint8_t F25R2_FB11 = 11;            // Filter bits
    static const uint8_t F25R2_FB12 = 12;            // Filter bits
    static const uint8_t F25R2_FB13 = 13;            // Filter bits
    static const uint8_t F25R2_FB14 = 14;            // Filter bits
    static const uint8_t F25R2_FB15 = 15;            // Filter bits
    static const uint8_t F25R2_FB16 = 16;            // Filter bits
    static const uint8_t F25R2_FB17 = 17;            // Filter bits
    static const uint8_t F25R2_FB18 = 18;            // Filter bits
    static const uint8_t F25R2_FB19 = 19;            // Filter bits
    static const uint8_t F25R2_FB20 = 20;            // Filter bits
    static const uint8_t F25R2_FB21 = 21;            // Filter bits
    static const uint8_t F25R2_FB22 = 22;            // Filter bits
    static const uint8_t F25R2_FB23 = 23;            // Filter bits
    static const uint8_t F25R2_FB24 = 24;            // Filter bits
    static const uint8_t F25R2_FB25 = 25;            // Filter bits
    static const uint8_t F25R2_FB26 = 26;            // Filter bits
    static const uint8_t F25R2_FB27 = 27;            // Filter bits
    static const uint8_t F25R2_FB28 = 28;            // Filter bits
    static const uint8_t F25R2_FB29 = 29;            // Filter bits
    static const uint8_t F25R2_FB30 = 30;            // Filter bits
    static const uint8_t F25R2_FB31 = 31;            // Filter bits
    static const uint32_t F25R2_RESET_VALUE = 0x0;

    static const uint8_t F26R1_FB0 = 0;              // Filter bits
    static const uint8_t F26R1_FB1 = 1;              // Filter bits
    static const uint8_t F26R1_FB2 = 2;              // Filter bits
    static const uint8_t F26R1_FB3 = 3;              // Filter bits
    static const uint8_t F26R1_FB4 = 4;              // Filter bits
    static const uint8_t F26R1_FB5 = 5;              // Filter bits
    static const uint8_t F26R1_FB6 = 6;              // Filter bits
    static const uint8_t F26R1_FB7 = 7;              // Filter bits
    static const uint8_t F26R1_FB8 = 8;              // Filter bits
    static const uint8_t F26R1_FB9 = 9;              // Filter bits
    static const uint8_t F26R1_FB10 = 10;            // Filter bits
    static const uint8_t F26R1_FB11 = 11;            // Filter bits
    static const uint8_t F26R1_FB12 = 12;            // Filter bits
    static const uint8_t F26R1_FB13 = 13;            // Filter bits
    static const uint8_t F26R1_FB14 = 14;            // Filter bits
    static const uint8_t F26R1_FB15 = 15;            // Filter bits
    static const uint8_t F26R1_FB16 = 16;            // Filter bits
    static const uint8_t F26R1_FB17 = 17;            // Filter bits
    static const uint8_t F26R1_FB18 = 18;            // Filter bits
    static const uint8_t F26R1_FB19 = 19;            // Filter bits
    static const uint8_t F26R1_FB20 = 20;            // Filter bits
    static const uint8_t F26R1_FB21 = 21;            // Filter bits
    static const uint8_t F26R1_FB22 = 22;            // Filter bits
    static const uint8_t F26R1_FB23 = 23;            // Filter bits
    static const uint8_t F26R1_FB24 = 24;            // Filter bits
    static const uint8_t F26R1_FB25 = 25;            // Filter bits
    static const uint8_t F26R1_FB26 = 26;            // Filter bits
    static const uint8_t F26R1_FB27 = 27;            // Filter bits
    static const uint8_t F26R1_FB28 = 28;            // Filter bits
    static const uint8_t F26R1_FB29 = 29;            // Filter bits
    static const uint8_t F26R1_FB30 = 30;            // Filter bits
    static const uint8_t F26R1_FB31 = 31;            // Filter bits
    static const uint32_t F26R1_RESET_VALUE = 0x0;

    static const uint8_t F26R2_FB0 = 0;              // Filter bits
    static const uint8_t F26R2_FB1 = 1;              // Filter bits
    static const uint8_t F26R2_FB2 = 2;              // Filter bits
    static const uint8_t F26R2_FB3 = 3;              // Filter bits
    static const uint8_t F26R2_FB4 = 4;              // Filter bits
    static const uint8_t F26R2_FB5 = 5;              // Filter bits
    static const uint8_t F26R2_FB6 = 6;              // Filter bits
    static const uint8_t F26R2_FB7 = 7;              // Filter bits
    static const uint8_t F26R2_FB8 = 8;              // Filter bits
    static const uint8_t F26R2_FB9 = 9;              // Filter bits
    static const uint8_t F26R2_FB10 = 10;            // Filter bits
    static const uint8_t F26R2_FB11 = 11;            // Filter bits
    static const uint8_t F26R2_FB12 = 12;            // Filter bits
    static const uint8_t F26R2_FB13 = 13;            // Filter bits
    static const uint8_t F26R2_FB14 = 14;            // Filter bits
    static const uint8_t F26R2_FB15 = 15;            // Filter bits
    static const uint8_t F26R2_FB16 = 16;            // Filter bits
    static const uint8_t F26R2_FB17 = 17;            // Filter bits
    static const uint8_t F26R2_FB18 = 18;            // Filter bits
    static const uint8_t F26R2_FB19 = 19;            // Filter bits
    static const uint8_t F26R2_FB20 = 20;            // Filter bits
    static const uint8_t F26R2_FB21 = 21;            // Filter bits
    static const uint8_t F26R2_FB22 = 22;            // Filter bits
    static const uint8_t F26R2_FB23 = 23;            // Filter bits
    static const uint8_t F26R2_FB24 = 24;            // Filter bits
    static const uint8_t F26R2_FB25 = 25;            // Filter bits
    static const uint8_t F26R2_FB26 = 26;            // Filter bits
    static const uint8_t F26R2_FB27 = 27;            // Filter bits
    static const uint8_t F26R2_FB28 = 28;            // Filter bits
    static const uint8_t F26R2_FB29 = 29;            // Filter bits
    static const uint8_t F26R2_FB30 = 30;            // Filter bits
    static const uint8_t F26R2_FB31 = 31;            // Filter bits
    static const uint32_t F26R2_RESET_VALUE = 0x0;

    static const uint8_t F27R1_FB0 = 0;              // Filter bits
    static const uint8_t F27R1_FB1 = 1;              // Filter bits
    static const uint8_t F27R1_FB2 = 2;              // Filter bits
    static const uint8_t F27R1_FB3 = 3;              // Filter bits
    static const uint8_t F27R1_FB4 = 4;              // Filter bits
    static const uint8_t F27R1_FB5 = 5;              // Filter bits
    static const uint8_t F27R1_FB6 = 6;              // Filter bits
    static const uint8_t F27R1_FB7 = 7;              // Filter bits
    static const uint8_t F27R1_FB8 = 8;              // Filter bits
    static const uint8_t F27R1_FB9 = 9;              // Filter bits
    static const uint8_t F27R1_FB10 = 10;            // Filter bits
    static const uint8_t F27R1_FB11 = 11;            // Filter bits
    static const uint8_t F27R1_FB12 = 12;            // Filter bits
    static const uint8_t F27R1_FB13 = 13;            // Filter bits
    static const uint8_t F27R1_FB14 = 14;            // Filter bits
    static const uint8_t F27R1_FB15 = 15;            // Filter bits
    static const uint8_t F27R1_FB16 = 16;            // Filter bits
    static const uint8_t F27R1_FB17 = 17;            // Filter bits
    static const uint8_t F27R1_FB18 = 18;            // Filter bits
    static const uint8_t F27R1_FB19 = 19;            // Filter bits
    static const uint8_t F27R1_FB20 = 20;            // Filter bits
    static const uint8_t F27R1_FB21 = 21;            // Filter bits
    static const uint8_t F27R1_FB22 = 22;            // Filter bits
    static const uint8_t F27R1_FB23 = 23;            // Filter bits
    static const uint8_t F27R1_FB24 = 24;            // Filter bits
    static const uint8_t F27R1_FB25 = 25;            // Filter bits
    static const uint8_t F27R1_FB26 = 26;            // Filter bits
    static const uint8_t F27R1_FB27 = 27;            // Filter bits
    static const uint8_t F27R1_FB28 = 28;            // Filter bits
    static const uint8_t F27R1_FB29 = 29;            // Filter bits
    static const uint8_t F27R1_FB30 = 30;            // Filter bits
    static const uint8_t F27R1_FB31 = 31;            // Filter bits
    static const uint32_t F27R1_RESET_VALUE = 0x0;

    static const uint8_t F27R2_FB0 = 0;              // Filter bits
    static const uint8_t F27R2_FB1 = 1;              // Filter bits
    static const uint8_t F27R2_FB2 = 2;              // Filter bits
    static const uint8_t F27R2_FB3 = 3;              // Filter bits
    static const uint8_t F27R2_FB4 = 4;              // Filter bits
    static const uint8_t F27R2_FB5 = 5;              // Filter bits
    static const uint8_t F27R2_FB6 = 6;              // Filter bits
    static const uint8_t F27R2_FB7 = 7;              // Filter bits
    static const uint8_t F27R2_FB8 = 8;              // Filter bits
    static const uint8_t F27R2_FB9 = 9;              // Filter bits
    static const uint8_t F27R2_FB10 = 10;            // Filter bits
    static const uint8_t F27R2_FB11 = 11;            // Filter bits
    static const uint8_t F27R2_FB12 = 12;            // Filter bits
    static const uint8_t F27R2_FB13 = 13;            // Filter bits
    static const uint8_t F27R2_FB14 = 14;            // Filter bits
    static const uint8_t F27R2_FB15 = 15;            // Filter bits
    static const uint8_t F27R2_FB16 = 16;            // Filter bits
    static const uint8_t F27R2_FB17 = 17;            // Filter bits
    static const uint8_t F27R2_FB18 = 18;            // Filter bits
    static const uint8_t F27R2_FB19 = 19;            // Filter bits
    static const uint8_t F27R2_FB20 = 20;            // Filter bits
    static const uint8_t F27R2_FB21 = 21;            // Filter bits
    static const uint8_t F27R2_FB22 = 22;            // Filter bits
    static const uint8_t F27R2_FB23 = 23;            // Filter bits
    static const uint8_t F27R2_FB24 = 24;            // Filter bits
    static const uint8_t F27R2_FB25 = 25;            // Filter bits
    static const uint8_t F27R2_FB26 = 26;            // Filter bits
    static const uint8_t F27R2_FB27 = 27;            // Filter bits
    static const uint8_t F27R2_FB28 = 28;            // Filter bits
    static const uint8_t F27R2_FB29 = 29;            // Filter bits
    static const uint8_t F27R2_FB30 = 30;            // Filter bits
    static const uint8_t F27R2_FB31 = 31;            // Filter bits
    static const uint32_t F27R2_RESET_VALUE = 0x0;
};

static can2_t& CAN2 = *reinterpret_cast<can2_t*>(0x40006800);


////
//
//    Inter-integrated circuit
//
////

struct i2c4_t
{
    volatile uint32_t    CR1;                  // [Read-write] Control register 1
    volatile uint32_t    CR2;                  // [Read-write] Control register 2
    volatile uint32_t    OAR1;                 // [Read-write] Own address register 1
    volatile uint32_t    OAR2;                 // [Read-write] Own address register 2
    volatile uint32_t    TIMINGR;              // [Read-write] Timing register
    volatile uint32_t    TIMEOUTR;             // [Read-write] Timeout register
    volatile uint32_t    ISR;                  // Interrupt and Status register
    volatile uint32_t    ICR;                  // [Write-only] Interrupt clear register
    volatile uint32_t    PECR;                 // [Read-only] PEC register
    volatile uint32_t    RXDR;                 // [Read-only] Receive data register
    volatile uint32_t    TXDR;                 // [Read-write] Transmit data register

    static const uint8_t CR1_PE = 0;               // Peripheral enable
    static const uint8_t CR1_TXIE = 1;             // TXIE
    static const uint8_t CR1_RXIE = 2;             // RXIE
    static const uint8_t CR1_ADDRE = 3;            // ADDRE
    static const uint8_t CR1_NACKIE = 4;           // NACKIE
    static const uint8_t CR1_STOPIE = 5;           // STOPIE
    static const uint8_t CR1_TCIE = 6;             // TCIE
    static const uint8_t CR1_ERRIE = 7;            // ERRIE
    static const uint8_t CR1_DNF = 8;              // DNF (4 bits)
    static const uint8_t CR1_ANFOFF = 12;          // ANFOFF
    static const uint8_t CR1_TCDMAEN = 14;         // TCDMAEN
    static const uint8_t CR1_RXDMAEN = 15;         // RXDMAEN
    static const uint8_t CR1_SBC = 16;             // SBC
    static const uint8_t CR1_NOSTRETCH = 17;       // NOSTRETCH
    static const uint8_t CR1_WUPEN = 18;           // WUPEN
    static const uint8_t CR1_GCEN = 19;            // GCEN
    static const uint8_t CR1_SMBHEN = 20;          // SMBHEN
    static const uint8_t CR1_SMBDEN = 21;          // SMBDEN
    static const uint8_t CR1_ALERTEN = 22;         // ALERTEN
    static const uint8_t CR1_PECEN = 23;           // PECEN
    static const uint32_t CR1_RESET_VALUE = 0x0;

    static const uint8_t CR2_SADD0 = 0;            // Slave address bit 0
    static const uint8_t CR2_SADD1_7 = 1;          // Slave address bit 7_1 (7 bits)
    static const uint8_t CR2_SADD8_9 = 8;          // Slave address bit 8_9 (2 bits)
    static const uint8_t CR2_RD_WRN = 10;          // Transfer direction
    static const uint8_t CR2_ADD10 = 11;           // 10-bit addressing mode
    static const uint8_t CR2_HEAD10R = 12;         // 10-bit address header only read direction
    static const uint8_t CR2_START = 13;           // Start generation
    static const uint8_t CR2_STOP = 14;            // Stop generation
    static const uint8_t CR2_NACK = 15;            // NACK generation
    static const uint8_t CR2_NBYTES = 16;          // Number of bytes (8 bits)
    static const uint8_t CR2_RELOAD = 24;          // NBYTES reload mode
    static const uint8_t CR2_AUTOEND = 25;         // Automatic end mode
    static const uint8_t CR2_PECBYTE = 26;         // Packet error checking byte
    static const uint32_t CR2_RESET_VALUE = 0x0;

    static const uint8_t OAR1_OA1 = 0;              // OA1
    static const uint8_t OAR1_OA11_7 = 1;           // OA11_7 (7 bits)
    static const uint8_t OAR1_OA18_9 = 8;           // OA18_9 (2 bits)
    static const uint8_t OAR1_OA1MODE = 10;         // OA1MODE
    static const uint8_t OAR1_OA1EN = 15;           // OA1EN
    static const uint32_t OAR1_RESET_VALUE = 0x0;

    static const uint8_t OAR2_OA21_7 = 1;           // OA21_7 (7 bits)
    static const uint8_t OAR2_OA2MSK = 8;           // OA2MSK (3 bits)
    static const uint8_t OAR2_OA2EN = 15;           // OA2EN
    static const uint32_t OAR2_RESET_VALUE = 0x0;

    static const uint8_t TIMINGR_SCLL = 0;             // SCLL (8 bits)
    static const uint8_t TIMINGR_SCLH = 8;             // SCLH (8 bits)
    static const uint8_t TIMINGR_SDADEL = 16;          // SDADEL (4 bits)
    static const uint8_t TIMINGR_SCLDEL = 20;          // SCLDEL (4 bits)
    static const uint8_t TIMINGR_PRESC = 28;           // PRESC (4 bits)
    static const uint32_t TIMINGR_RESET_VALUE = 0x0;

    static const uint8_t TIMEOUTR_TIMEOUTA = 0;         // TIMEOUTA (12 bits)
    static const uint8_t TIMEOUTR_TIDLE = 12;           // TIDLE
    static const uint8_t TIMEOUTR_TIMOUTEN = 15;        // TIMOUTEN
    static const uint8_t TIMEOUTR_TIMEOUTB = 16;        // TIMEOUTB (12 bits)
    static const uint8_t TIMEOUTR_TEXTEN = 31;          // TEXTEN
    static const uint32_t TIMEOUTR_RESET_VALUE = 0x0;

    static const uint8_t ISR_TXE = 0;              // TXE, Read-write
    static const uint8_t ISR_TXIS = 1;             // TXIS, Read-write
    static const uint8_t ISR_RXNE = 2;             // RXNE, Read-only
    static const uint8_t ISR_ADDR = 3;             // ADDR, Read-only
    static const uint8_t ISR_NACKF = 4;            // NACKF, Read-only
    static const uint8_t ISR_STOPF = 5;            // STOPF, Read-only
    static const uint8_t ISR_TC = 6;               // TC, Read-only
    static const uint8_t ISR_TCR = 7;              // TCR, Read-only
    static const uint8_t ISR_BERR = 8;             // BERR, Read-only
    static const uint8_t ISR_ARLO = 9;             // ARLO, Read-only
    static const uint8_t ISR_OVR = 10;             // OVR, Read-only
    static const uint8_t ISR_PECERR = 11;          // PECERR, Read-only
    static const uint8_t ISR_TIMEOUT = 12;         // TIMEOUT, Read-only
    static const uint8_t ISR_ALERT = 13;           // ALERT, Read-only
    static const uint8_t ISR_BUSY = 15;            // BUSY, Read-only
    static const uint8_t ISR_DIR = 16;             // DIR, Read-only
    static const uint8_t ISR_ADDCODE = 17;         // ADDCODE (7 bits), Read-only
    static const uint32_t ISR_RESET_VALUE = 0x1;

    static const uint8_t ICR_ADDRCF = 3;           // ADDRCF
    static const uint8_t ICR_NACKCF = 4;           // NACKCF
    static const uint8_t ICR_STOPCF = 5;           // STOPCF
    static const uint8_t ICR_BERRCF = 8;           // BERRCF
    static const uint8_t ICR_ARLOCF = 9;           // ARLOCF
    static const uint8_t ICR_OVRCF = 10;           // OVRCF
    static const uint8_t ICR_PECCF = 11;           // PECCF
    static const uint8_t ICR_TIMOUTCF = 12;        // TIMOUTCF
    static const uint8_t ICR_ALERTC = 13;          // ALERTC
    static const uint32_t ICR_RESET_VALUE = 0x0;

    static const uint8_t PECR_PEC = 0;              // PEC (8 bits)
    static const uint32_t PECR_RESET_VALUE = 0x0;

    static const uint8_t RXDR_RXDATA = 0;           // RXDATA (8 bits)
    static const uint32_t RXDR_RESET_VALUE = 0x0;

    static const uint8_t TXDR_TXDATA = 0;           // TXDATA (8 bits)
    static const uint32_t TXDR_RESET_VALUE = 0x0;
};

static i2c4_t& I2C4 = *reinterpret_cast<i2c4_t*>(0x40006000);


////
//
//    Flexible static memory controller
//
////

struct fsmc_t
{
    volatile uint32_t    BCR1;                 // [Read-write] SRAM/NOR-Flash chip-select control register 1
    volatile uint32_t    BTR1;                 // [Read-write] SRAM/NOR-Flash chip-select timing register 1
    volatile uint32_t    BCR2;                 // [Read-write] SRAM/NOR-Flash chip-select control register 2
    volatile uint32_t    BTR2;                 // [Read-write] SRAM/NOR-Flash chip-select timing register 2
    volatile uint32_t    BCR3;                 // [Read-write] SRAM/NOR-Flash chip-select control register 3
    volatile uint32_t    BTR3;                 // [Read-write] SRAM/NOR-Flash chip-select timing register 3
    volatile uint32_t    BCR4;                 // [Read-write] SRAM/NOR-Flash chip-select control register 4
    volatile uint32_t    BTR4;                 // [Read-write] SRAM/NOR-Flash chip-select timing register 4
    reserved_t<16>       _0;
    volatile uint32_t    PCR2;                 // [Read-write] PC Card/NAND Flash control register 2
    volatile uint32_t    SR2;                  // FIFO status and interrupt register 2
    volatile uint32_t    PMEM2;                // [Read-write] Common memory space timing register 2
    volatile uint32_t    PATT2;                // [Read-write] Attribute memory space timing register 2
    reserved_t<1>        _1;
    volatile uint32_t    ECCR2;                // [Read-only] ECC result register 2
    reserved_t<2>        _2;
    volatile uint32_t    PCR3;                 // [Read-write] PC Card/NAND Flash control register 3
    volatile uint32_t    SR3;                  // FIFO status and interrupt register 3
    volatile uint32_t    PMEM3;                // [Read-write] Common memory space timing register 3
    volatile uint32_t    PATT3;                // [Read-write] Attribute memory space timing register 3
    reserved_t<1>        _3;
    volatile uint32_t    ECCR3;                // [Read-only] ECC result register 3
    reserved_t<2>        _4;
    volatile uint32_t    PCR4;                 // [Read-write] PC Card/NAND Flash control register 4
    volatile uint32_t    SR4;                  // FIFO status and interrupt register 4
    volatile uint32_t    PMEM4;                // [Read-write] Common memory space timing register 4
    volatile uint32_t    PATT4;                // [Read-write] Attribute memory space timing register 4
    volatile uint32_t    PIO4;                 // [Read-write] I/O space timing register 4
    reserved_t<20>       _5;
    volatile uint32_t    BWTR1;                // [Read-write] SRAM/NOR-Flash write timing registers 1
    reserved_t<1>        _6;
    volatile uint32_t    BWTR2;                // [Read-write] SRAM/NOR-Flash write timing registers 2
    reserved_t<1>        _7;
    volatile uint32_t    BWTR3;                // [Read-write] SRAM/NOR-Flash write timing registers 3
    reserved_t<1>        _8;
    volatile uint32_t    BWTR4;                // [Read-write] SRAM/NOR-Flash write timing registers 4

    static const uint8_t BCR1_CBURSTRW = 19;        // CBURSTRW
    static const uint8_t BCR1_ASYNCWAIT = 15;       // ASYNCWAIT
    static const uint8_t BCR1_EXTMOD = 14;          // EXTMOD
    static const uint8_t BCR1_WAITEN = 13;          // WAITEN
    static const uint8_t BCR1_WREN = 12;            // WREN
    static const uint8_t BCR1_WAITCFG = 11;         // WAITCFG
    static const uint8_t BCR1_WAITPOL = 9;          // WAITPOL
    static const uint8_t BCR1_BURSTEN = 8;          // BURSTEN
    static const uint8_t BCR1_FACCEN = 6;           // FACCEN
    static const uint8_t BCR1_MWID = 4;             // MWID (2 bits)
    static const uint8_t BCR1_MTYP = 2;             // MTYP (2 bits)
    static const uint8_t BCR1_MUXEN = 1;            // MUXEN
    static const uint8_t BCR1_MBKEN = 0;            // MBKEN
    static const uint32_t BCR1_RESET_VALUE = 0x30d0;

    static const uint8_t BTR1_ACCMOD = 28;          // ACCMOD (2 bits)
    static const uint8_t BTR1_DATLAT = 24;          // DATLAT (4 bits)
    static const uint8_t BTR1_CLKDIV = 20;          // CLKDIV (4 bits)
    static const uint8_t BTR1_BUSTURN = 16;         // BUSTURN (4 bits)
    static const uint8_t BTR1_DATAST = 8;           // DATAST (8 bits)
    static const uint8_t BTR1_ADDHLD = 4;           // ADDHLD (4 bits)
    static const uint8_t BTR1_ADDSET = 0;           // ADDSET (4 bits)
    static const uint32_t BTR1_RESET_VALUE = 0xffffffff;

    static const uint8_t BCR2_CBURSTRW = 19;        // CBURSTRW
    static const uint8_t BCR2_ASYNCWAIT = 15;       // ASYNCWAIT
    static const uint8_t BCR2_EXTMOD = 14;          // EXTMOD
    static const uint8_t BCR2_WAITEN = 13;          // WAITEN
    static const uint8_t BCR2_WREN = 12;            // WREN
    static const uint8_t BCR2_WAITCFG = 11;         // WAITCFG
    static const uint8_t BCR2_WRAPMOD = 10;         // WRAPMOD
    static const uint8_t BCR2_WAITPOL = 9;          // WAITPOL
    static const uint8_t BCR2_BURSTEN = 8;          // BURSTEN
    static const uint8_t BCR2_FACCEN = 6;           // FACCEN
    static const uint8_t BCR2_MWID = 4;             // MWID (2 bits)
    static const uint8_t BCR2_MTYP = 2;             // MTYP (2 bits)
    static const uint8_t BCR2_MUXEN = 1;            // MUXEN
    static const uint8_t BCR2_MBKEN = 0;            // MBKEN
    static const uint32_t BCR2_RESET_VALUE = 0x30d0;

    static const uint8_t BTR2_ACCMOD = 28;          // ACCMOD (2 bits)
    static const uint8_t BTR2_DATLAT = 24;          // DATLAT (4 bits)
    static const uint8_t BTR2_CLKDIV = 20;          // CLKDIV (4 bits)
    static const uint8_t BTR2_BUSTURN = 16;         // BUSTURN (4 bits)
    static const uint8_t BTR2_DATAST = 8;           // DATAST (8 bits)
    static const uint8_t BTR2_ADDHLD = 4;           // ADDHLD (4 bits)
    static const uint8_t BTR2_ADDSET = 0;           // ADDSET (4 bits)
    static const uint32_t BTR2_RESET_VALUE = 0xffffffff;

    static const uint8_t BCR3_CBURSTRW = 19;        // CBURSTRW
    static const uint8_t BCR3_ASYNCWAIT = 15;       // ASYNCWAIT
    static const uint8_t BCR3_EXTMOD = 14;          // EXTMOD
    static const uint8_t BCR3_WAITEN = 13;          // WAITEN
    static const uint8_t BCR3_WREN = 12;            // WREN
    static const uint8_t BCR3_WAITCFG = 11;         // WAITCFG
    static const uint8_t BCR3_WRAPMOD = 10;         // WRAPMOD
    static const uint8_t BCR3_WAITPOL = 9;          // WAITPOL
    static const uint8_t BCR3_BURSTEN = 8;          // BURSTEN
    static const uint8_t BCR3_FACCEN = 6;           // FACCEN
    static const uint8_t BCR3_MWID = 4;             // MWID (2 bits)
    static const uint8_t BCR3_MTYP = 2;             // MTYP (2 bits)
    static const uint8_t BCR3_MUXEN = 1;            // MUXEN
    static const uint8_t BCR3_MBKEN = 0;            // MBKEN
    static const uint32_t BCR3_RESET_VALUE = 0x30d0;

    static const uint8_t BTR3_ACCMOD = 28;          // ACCMOD (2 bits)
    static const uint8_t BTR3_DATLAT = 24;          // DATLAT (4 bits)
    static const uint8_t BTR3_CLKDIV = 20;          // CLKDIV (4 bits)
    static const uint8_t BTR3_BUSTURN = 16;         // BUSTURN (4 bits)
    static const uint8_t BTR3_DATAST = 8;           // DATAST (8 bits)
    static const uint8_t BTR3_ADDHLD = 4;           // ADDHLD (4 bits)
    static const uint8_t BTR3_ADDSET = 0;           // ADDSET (4 bits)
    static const uint32_t BTR3_RESET_VALUE = 0xffffffff;

    static const uint8_t BCR4_CBURSTRW = 19;        // CBURSTRW
    static const uint8_t BCR4_ASYNCWAIT = 15;       // ASYNCWAIT
    static const uint8_t BCR4_EXTMOD = 14;          // EXTMOD
    static const uint8_t BCR4_WAITEN = 13;          // WAITEN
    static const uint8_t BCR4_WREN = 12;            // WREN
    static const uint8_t BCR4_WAITCFG = 11;         // WAITCFG
    static const uint8_t BCR4_WRAPMOD = 10;         // WRAPMOD
    static const uint8_t BCR4_WAITPOL = 9;          // WAITPOL
    static const uint8_t BCR4_BURSTEN = 8;          // BURSTEN
    static const uint8_t BCR4_FACCEN = 6;           // FACCEN
    static const uint8_t BCR4_MWID = 4;             // MWID (2 bits)
    static const uint8_t BCR4_MTYP = 2;             // MTYP (2 bits)
    static const uint8_t BCR4_MUXEN = 1;            // MUXEN
    static const uint8_t BCR4_MBKEN = 0;            // MBKEN
    static const uint32_t BCR4_RESET_VALUE = 0x30d0;

    static const uint8_t BTR4_ACCMOD = 28;          // ACCMOD (2 bits)
    static const uint8_t BTR4_DATLAT = 24;          // DATLAT (4 bits)
    static const uint8_t BTR4_CLKDIV = 20;          // CLKDIV (4 bits)
    static const uint8_t BTR4_BUSTURN = 16;         // BUSTURN (4 bits)
    static const uint8_t BTR4_DATAST = 8;           // DATAST (8 bits)
    static const uint8_t BTR4_ADDHLD = 4;           // ADDHLD (4 bits)
    static const uint8_t BTR4_ADDSET = 0;           // ADDSET (4 bits)
    static const uint32_t BTR4_RESET_VALUE = 0xffffffff;

    static const uint8_t PCR2_ECCPS = 17;           // ECCPS (3 bits)
    static const uint8_t PCR2_TAR = 13;             // TAR (4 bits)
    static const uint8_t PCR2_TCLR = 9;             // TCLR (4 bits)
    static const uint8_t PCR2_ECCEN = 6;            // ECCEN
    static const uint8_t PCR2_PWID = 4;             // PWID (2 bits)
    static const uint8_t PCR2_PTYP = 3;             // PTYP
    static const uint8_t PCR2_PBKEN = 2;            // PBKEN
    static const uint8_t PCR2_PWAITEN = 1;          // PWAITEN
    static const uint32_t PCR2_RESET_VALUE = 0x18;

    static const uint8_t SR2_FEMPT = 6;            // FEMPT, Read-only
    static const uint8_t SR2_IFEN = 5;             // IFEN, Read-write
    static const uint8_t SR2_ILEN = 4;             // ILEN, Read-write
    static const uint8_t SR2_IREN = 3;             // IREN, Read-write
    static const uint8_t SR2_IFS = 2;              // IFS, Read-write
    static const uint8_t SR2_ILS = 1;              // ILS, Read-write
    static const uint8_t SR2_IRS = 0;              // IRS, Read-write
    static const uint32_t SR2_RESET_VALUE = 0x40;

    static const uint8_t PMEM2_MEMHIZx = 24;         // MEMHIZx (8 bits)
    static const uint8_t PMEM2_MEMHOLDx = 16;        // MEMHOLDx (8 bits)
    static const uint8_t PMEM2_MEMWAITx = 8;         // MEMWAITx (8 bits)
    static const uint8_t PMEM2_MEMSETx = 0;          // MEMSETx (8 bits)
    static const uint32_t PMEM2_RESET_VALUE = 0xfcfcfcfc;

    static const uint8_t PATT2_ATTHIZx = 24;         // ATTHIZx (8 bits)
    static const uint8_t PATT2_ATTHOLDx = 16;        // ATTHOLDx (8 bits)
    static const uint8_t PATT2_ATTWAITx = 8;         // ATTWAITx (8 bits)
    static const uint8_t PATT2_ATTSETx = 0;          // ATTSETx (8 bits)
    static const uint32_t PATT2_RESET_VALUE = 0xfcfcfcfc;

    static const uint8_t ECCR2_ECCx = 0;             // ECCx (32 bits)
    static const uint32_t ECCR2_RESET_VALUE = 0x0;

    static const uint8_t PCR3_ECCPS = 17;           // ECCPS (3 bits)
    static const uint8_t PCR3_TAR = 13;             // TAR (4 bits)
    static const uint8_t PCR3_TCLR = 9;             // TCLR (4 bits)
    static const uint8_t PCR3_ECCEN = 6;            // ECCEN
    static const uint8_t PCR3_PWID = 4;             // PWID (2 bits)
    static const uint8_t PCR3_PTYP = 3;             // PTYP
    static const uint8_t PCR3_PBKEN = 2;            // PBKEN
    static const uint8_t PCR3_PWAITEN = 1;          // PWAITEN
    static const uint32_t PCR3_RESET_VALUE = 0x18;

    static const uint8_t SR3_FEMPT = 6;            // FEMPT, Read-only
    static const uint8_t SR3_IFEN = 5;             // IFEN, Read-write
    static const uint8_t SR3_ILEN = 4;             // ILEN, Read-write
    static const uint8_t SR3_IREN = 3;             // IREN, Read-write
    static const uint8_t SR3_IFS = 2;              // IFS, Read-write
    static const uint8_t SR3_ILS = 1;              // ILS, Read-write
    static const uint8_t SR3_IRS = 0;              // IRS, Read-write
    static const uint32_t SR3_RESET_VALUE = 0x40;

    static const uint8_t PMEM3_MEMHIZx = 24;         // MEMHIZx (8 bits)
    static const uint8_t PMEM3_MEMHOLDx = 16;        // MEMHOLDx (8 bits)
    static const uint8_t PMEM3_MEMWAITx = 8;         // MEMWAITx (8 bits)
    static const uint8_t PMEM3_MEMSETx = 0;          // MEMSETx (8 bits)
    static const uint32_t PMEM3_RESET_VALUE = 0xfcfcfcfc;

    static const uint8_t PATT3_ATTHIZx = 24;         // ATTHIZx (8 bits)
    static const uint8_t PATT3_ATTHOLDx = 16;        // ATTHOLDx (8 bits)
    static const uint8_t PATT3_ATTWAITx = 8;         // ATTWAITx (8 bits)
    static const uint8_t PATT3_ATTSETx = 0;          // ATTSETx (8 bits)
    static const uint32_t PATT3_RESET_VALUE = 0xfcfcfcfc;

    static const uint8_t ECCR3_ECCx = 0;             // ECCx (32 bits)
    static const uint32_t ECCR3_RESET_VALUE = 0x0;

    static const uint8_t PCR4_ECCPS = 17;           // ECCPS (3 bits)
    static const uint8_t PCR4_TAR = 13;             // TAR (4 bits)
    static const uint8_t PCR4_TCLR = 9;             // TCLR (4 bits)
    static const uint8_t PCR4_ECCEN = 6;            // ECCEN
    static const uint8_t PCR4_PWID = 4;             // PWID (2 bits)
    static const uint8_t PCR4_PTYP = 3;             // PTYP
    static const uint8_t PCR4_PBKEN = 2;            // PBKEN
    static const uint8_t PCR4_PWAITEN = 1;          // PWAITEN
    static const uint32_t PCR4_RESET_VALUE = 0x18;

    static const uint8_t SR4_FEMPT = 6;            // FEMPT, Read-only
    static const uint8_t SR4_IFEN = 5;             // IFEN, Read-write
    static const uint8_t SR4_ILEN = 4;             // ILEN, Read-write
    static const uint8_t SR4_IREN = 3;             // IREN, Read-write
    static const uint8_t SR4_IFS = 2;              // IFS, Read-write
    static const uint8_t SR4_ILS = 1;              // ILS, Read-write
    static const uint8_t SR4_IRS = 0;              // IRS, Read-write
    static const uint32_t SR4_RESET_VALUE = 0x40;

    static const uint8_t PMEM4_MEMHIZx = 24;         // MEMHIZx (8 bits)
    static const uint8_t PMEM4_MEMHOLDx = 16;        // MEMHOLDx (8 bits)
    static const uint8_t PMEM4_MEMWAITx = 8;         // MEMWAITx (8 bits)
    static const uint8_t PMEM4_MEMSETx = 0;          // MEMSETx (8 bits)
    static const uint32_t PMEM4_RESET_VALUE = 0xfcfcfcfc;

    static const uint8_t PATT4_ATTHIZx = 24;         // ATTHIZx (8 bits)
    static const uint8_t PATT4_ATTHOLDx = 16;        // ATTHOLDx (8 bits)
    static const uint8_t PATT4_ATTWAITx = 8;         // ATTWAITx (8 bits)
    static const uint8_t PATT4_ATTSETx = 0;          // ATTSETx (8 bits)
    static const uint32_t PATT4_RESET_VALUE = 0xfcfcfcfc;

    static const uint8_t PIO4_IOHIZx = 24;          // IOHIZx (8 bits)
    static const uint8_t PIO4_IOHOLDx = 16;         // IOHOLDx (8 bits)
    static const uint8_t PIO4_IOWAITx = 8;          // IOWAITx (8 bits)
    static const uint8_t PIO4_IOSETx = 0;           // IOSETx (8 bits)
    static const uint32_t PIO4_RESET_VALUE = 0xfcfcfcfc;

    static const uint8_t BWTR1_ACCMOD = 28;          // ACCMOD (2 bits)
    static const uint8_t BWTR1_DATLAT = 24;          // DATLAT (4 bits)
    static const uint8_t BWTR1_CLKDIV = 20;          // CLKDIV (4 bits)
    static const uint8_t BWTR1_DATAST = 8;           // DATAST (8 bits)
    static const uint8_t BWTR1_ADDHLD = 4;           // ADDHLD (4 bits)
    static const uint8_t BWTR1_ADDSET = 0;           // ADDSET (4 bits)
    static const uint32_t BWTR1_RESET_VALUE = 0xfffffff;

    static const uint8_t BWTR2_ACCMOD = 28;          // ACCMOD (2 bits)
    static const uint8_t BWTR2_DATLAT = 24;          // DATLAT (4 bits)
    static const uint8_t BWTR2_CLKDIV = 20;          // CLKDIV (4 bits)
    static const uint8_t BWTR2_DATAST = 8;           // DATAST (8 bits)
    static const uint8_t BWTR2_ADDHLD = 4;           // ADDHLD (4 bits)
    static const uint8_t BWTR2_ADDSET = 0;           // ADDSET (4 bits)
    static const uint32_t BWTR2_RESET_VALUE = 0xfffffff;

    static const uint8_t BWTR3_ACCMOD = 28;          // ACCMOD (2 bits)
    static const uint8_t BWTR3_DATLAT = 24;          // DATLAT (4 bits)
    static const uint8_t BWTR3_CLKDIV = 20;          // CLKDIV (4 bits)
    static const uint8_t BWTR3_DATAST = 8;           // DATAST (8 bits)
    static const uint8_t BWTR3_ADDHLD = 4;           // ADDHLD (4 bits)
    static const uint8_t BWTR3_ADDSET = 0;           // ADDSET (4 bits)
    static const uint32_t BWTR3_RESET_VALUE = 0xfffffff;

    static const uint8_t BWTR4_ACCMOD = 28;          // ACCMOD (2 bits)
    static const uint8_t BWTR4_DATLAT = 24;          // DATLAT (4 bits)
    static const uint8_t BWTR4_CLKDIV = 20;          // CLKDIV (4 bits)
    static const uint8_t BWTR4_DATAST = 8;           // DATAST (8 bits)
    static const uint8_t BWTR4_ADDHLD = 4;           // ADDHLD (4 bits)
    static const uint8_t BWTR4_ADDSET = 0;           // ADDSET (4 bits)
    static const uint32_t BWTR4_RESET_VALUE = 0xfffffff;
};

static fsmc_t& FSMC = *reinterpret_cast<fsmc_t*>(0x60000000);


////
//
//    USB on the go full speed
//
////

struct otg_fs_global_t
{
    volatile uint32_t    FS_GOTGCTL;           // OTG_FS control and status register (OTG_FS_GOTGCTL)
    volatile uint32_t    FS_GOTGINT;           // [Read-write] OTG_FS interrupt register (OTG_FS_GOTGINT)
    volatile uint32_t    FS_GAHBCFG;           // [Read-write] OTG_FS AHB configuration register (OTG_FS_GAHBCFG)
    volatile uint32_t    FS_GUSBCFG;           // OTG_FS USB configuration register (OTG_FS_GUSBCFG)
    volatile uint32_t    FS_GRSTCTL;           // OTG_FS reset register (OTG_FS_GRSTCTL)
    volatile uint32_t    FS_GINTSTS;           // OTG_FS core interrupt register (OTG_FS_GINTSTS)
    volatile uint32_t    FS_GINTMSK;           // OTG_FS interrupt mask register (OTG_FS_GINTMSK)
    volatile uint32_t    FS_GRXSTSR_Device;    // [Read-only] OTG_FS Receive status debug read(Device mode)
    reserved_t<1>        _0;
    volatile uint32_t    FS_GRXFSIZ;           // [Read-write] OTG_FS Receive FIFO size register (OTG_FS_GRXFSIZ)
    volatile uint32_t    FS_GNPTXFSIZ_Device;  // [Read-write] OTG_FS non-periodic transmit FIFO size register (Device mode)
    volatile uint32_t    FS_GNPTXSTS;          // [Read-only] OTG_FS non-periodic transmit FIFO/queue status register (OTG_FS_GNPTXSTS)
    reserved_t<2>        _1;
    volatile uint32_t    FS_GCCFG;             // [Read-write] OTG_FS general core configuration register (OTG_FS_GCCFG)
    volatile uint32_t    FS_CID;               // [Read-write] core ID register
    reserved_t<48>       _2;
    volatile uint32_t    FS_HPTXFSIZ;          // [Read-write] OTG_FS Host periodic transmit FIFO size register (OTG_FS_HPTXFSIZ)
    volatile uint32_t    FS_DIEPTXF1;          // [Read-write] OTG_FS device IN endpoint transmit FIFO size register (OTG_FS_DIEPTXF2)
    volatile uint32_t    FS_DIEPTXF2;          // [Read-write] OTG_FS device IN endpoint transmit FIFO size register (OTG_FS_DIEPTXF3)
    volatile uint32_t    FS_DIEPTXF3;          // [Read-write] OTG_FS device IN endpoint transmit FIFO size register (OTG_FS_DIEPTXF4)

    static const uint8_t FS_GOTGCTL_SRQSCS = 0;           // Session request success, Read-only
    static const uint8_t FS_GOTGCTL_SRQ = 1;              // Session request, Read-write
    static const uint8_t FS_GOTGCTL_HNGSCS = 8;           // Host negotiation success, Read-only
    static const uint8_t FS_GOTGCTL_HNPRQ = 9;            // HNP request, Read-write
    static const uint8_t FS_GOTGCTL_HSHNPEN = 10;         // Host set HNP enable, Read-write
    static const uint8_t FS_GOTGCTL_DHNPEN = 11;          // Device HNP enabled, Read-write
    static const uint8_t FS_GOTGCTL_CIDSTS = 16;          // Connector ID status, Read-only
    static const uint8_t FS_GOTGCTL_DBCT = 17;            // Long/short debounce time, Read-only
    static const uint8_t FS_GOTGCTL_ASVLD = 18;           // A-session valid, Read-only
    static const uint8_t FS_GOTGCTL_BSVLD = 19;           // B-session valid, Read-only
    static const uint32_t FS_GOTGCTL_RESET_VALUE = 0x800;

    static const uint8_t FS_GOTGINT_SEDET = 2;            // Session end detected
    static const uint8_t FS_GOTGINT_SRSSCHG = 8;          // Session request success status change
    static const uint8_t FS_GOTGINT_HNSSCHG = 9;          // Host negotiation success status change
    static const uint8_t FS_GOTGINT_HNGDET = 17;          // Host negotiation detected
    static const uint8_t FS_GOTGINT_ADTOCHG = 18;         // A-device timeout change
    static const uint8_t FS_GOTGINT_DBCDNE = 19;          // Debounce done
    static const uint32_t FS_GOTGINT_RESET_VALUE = 0x0;

    static const uint8_t FS_GAHBCFG_GINT = 0;             // Global interrupt mask
    static const uint8_t FS_GAHBCFG_TXFELVL = 7;          // TxFIFO empty level
    static const uint8_t FS_GAHBCFG_PTXFELVL = 8;         // Periodic TxFIFO empty level
    static const uint32_t FS_GAHBCFG_RESET_VALUE = 0x0;

    static const uint8_t FS_GUSBCFG_TOCAL = 0;            // FS timeout calibration (3 bits), Read-write
    static const uint8_t FS_GUSBCFG_PHYSEL = 6;           // Full Speed serial transceiver select, Write-only
    static const uint8_t FS_GUSBCFG_SRPCAP = 8;           // SRP-capable, Read-write
    static const uint8_t FS_GUSBCFG_HNPCAP = 9;           // HNP-capable, Read-write
    static const uint8_t FS_GUSBCFG_TRDT = 10;            // USB turnaround time (4 bits), Read-write
    static const uint8_t FS_GUSBCFG_FHMOD = 29;           // Force host mode, Read-write
    static const uint8_t FS_GUSBCFG_FDMOD = 30;           // Force device mode, Read-write
    static const uint8_t FS_GUSBCFG_CTXPKT = 31;          // Corrupt Tx packet, Read-write
    static const uint32_t FS_GUSBCFG_RESET_VALUE = 0xa00;

    static const uint8_t FS_GRSTCTL_CSRST = 0;            // Core soft reset, Read-write
    static const uint8_t FS_GRSTCTL_HSRST = 1;            // HCLK soft reset, Read-write
    static const uint8_t FS_GRSTCTL_FCRST = 2;            // Host frame counter reset, Read-write
    static const uint8_t FS_GRSTCTL_RXFFLSH = 4;          // RxFIFO flush, Read-write
    static const uint8_t FS_GRSTCTL_TXFFLSH = 5;          // TxFIFO flush, Read-write
    static const uint8_t FS_GRSTCTL_TXFNUM = 6;           // TxFIFO number (5 bits), Read-write
    static const uint8_t FS_GRSTCTL_AHBIDL = 31;          // AHB master idle, Read-only
    static const uint32_t FS_GRSTCTL_RESET_VALUE = 0x20000000;

    static const uint8_t FS_GINTSTS_CMOD = 0;             // Current mode of operation, Read-only
    static const uint8_t FS_GINTSTS_MMIS = 1;             // Mode mismatch interrupt, Read-write
    static const uint8_t FS_GINTSTS_OTGINT = 2;           // OTG interrupt, Read-only
    static const uint8_t FS_GINTSTS_SOF = 3;              // Start of frame, Read-write
    static const uint8_t FS_GINTSTS_RXFLVL = 4;           // RxFIFO non-empty, Read-only
    static const uint8_t FS_GINTSTS_NPTXFE = 5;           // Non-periodic TxFIFO empty, Read-only
    static const uint8_t FS_GINTSTS_GINAKEFF = 6;         // Global IN non-periodic NAK effective, Read-only
    static const uint8_t FS_GINTSTS_GOUTNAKEFF = 7;       // Global OUT NAK effective, Read-only
    static const uint8_t FS_GINTSTS_ESUSP = 10;           // Early suspend, Read-write
    static const uint8_t FS_GINTSTS_USBSUSP = 11;         // USB suspend, Read-write
    static const uint8_t FS_GINTSTS_USBRST = 12;          // USB reset, Read-write
    static const uint8_t FS_GINTSTS_ENUMDNE = 13;         // Enumeration done, Read-write
    static const uint8_t FS_GINTSTS_ISOODRP = 14;         // Isochronous OUT packet dropped interrupt, Read-write
    static const uint8_t FS_GINTSTS_EOPF = 15;            // End of periodic frame interrupt, Read-write
    static const uint8_t FS_GINTSTS_IEPINT = 18;          // IN endpoint interrupt, Read-only
    static const uint8_t FS_GINTSTS_OEPINT = 19;          // OUT endpoint interrupt, Read-only
    static const uint8_t FS_GINTSTS_IISOIXFR = 20;        // Incomplete isochronous IN transfer, Read-write
    static const uint8_t FS_GINTSTS_IPXFR_INCOMPISOOUT = 21;// Incomplete periodic transfer(Host mode)/Incomplete isochronous OUT transfer(Device mode), Read-write
    static const uint8_t FS_GINTSTS_HPRTINT = 24;         // Host port interrupt, Read-only
    static const uint8_t FS_GINTSTS_HCINT = 25;           // Host channels interrupt, Read-only
    static const uint8_t FS_GINTSTS_PTXFE = 26;           // Periodic TxFIFO empty, Read-only
    static const uint8_t FS_GINTSTS_CIDSCHG = 28;         // Connector ID status change, Read-write
    static const uint8_t FS_GINTSTS_DISCINT = 29;         // Disconnect detected interrupt, Read-write
    static const uint8_t FS_GINTSTS_SRQINT = 30;          // Session request/new session detected interrupt, Read-write
    static const uint8_t FS_GINTSTS_WKUPINT = 31;         // Resume/remote wakeup detected interrupt, Read-write
    static const uint32_t FS_GINTSTS_RESET_VALUE = 0x4000020;

    static const uint8_t FS_GINTMSK_MMISM = 1;            // Mode mismatch interrupt mask, Read-write
    static const uint8_t FS_GINTMSK_OTGINT = 2;           // OTG interrupt mask, Read-write
    static const uint8_t FS_GINTMSK_SOFM = 3;             // Start of frame mask, Read-write
    static const uint8_t FS_GINTMSK_RXFLVLM = 4;          // Receive FIFO non-empty mask, Read-write
    static const uint8_t FS_GINTMSK_NPTXFEM = 5;          // Non-periodic TxFIFO empty mask, Read-write
    static const uint8_t FS_GINTMSK_GINAKEFFM = 6;        // Global non-periodic IN NAK effective mask, Read-write
    static const uint8_t FS_GINTMSK_GONAKEFFM = 7;        // Global OUT NAK effective mask, Read-write
    static const uint8_t FS_GINTMSK_ESUSPM = 10;          // Early suspend mask, Read-write
    static const uint8_t FS_GINTMSK_USBSUSPM = 11;        // USB suspend mask, Read-write
    static const uint8_t FS_GINTMSK_USBRST = 12;          // USB reset mask, Read-write
    static const uint8_t FS_GINTMSK_ENUMDNEM = 13;        // Enumeration done mask, Read-write
    static const uint8_t FS_GINTMSK_ISOODRPM = 14;        // Isochronous OUT packet dropped interrupt mask, Read-write
    static const uint8_t FS_GINTMSK_EOPFM = 15;           // End of periodic frame interrupt mask, Read-write
    static const uint8_t FS_GINTMSK_EPMISM = 17;          // Endpoint mismatch interrupt mask, Read-write
    static const uint8_t FS_GINTMSK_IEPINT = 18;          // IN endpoints interrupt mask, Read-write
    static const uint8_t FS_GINTMSK_OEPINT = 19;          // OUT endpoints interrupt mask, Read-write
    static const uint8_t FS_GINTMSK_IISOIXFRM = 20;       // Incomplete isochronous IN transfer mask, Read-write
    static const uint8_t FS_GINTMSK_IPXFRM_IISOOXFRM = 21;// Incomplete periodic transfer mask(Host mode)/Incomplete isochronous OUT transfer mask(Device mode), Read-write
    static const uint8_t FS_GINTMSK_PRTIM = 24;           // Host port interrupt mask, Read-only
    static const uint8_t FS_GINTMSK_HCIM = 25;            // Host channels interrupt mask, Read-write
    static const uint8_t FS_GINTMSK_PTXFEM = 26;          // Periodic TxFIFO empty mask, Read-write
    static const uint8_t FS_GINTMSK_CIDSCHGM = 28;        // Connector ID status change mask, Read-write
    static const uint8_t FS_GINTMSK_DISCINT = 29;         // Disconnect detected interrupt mask, Read-write
    static const uint8_t FS_GINTMSK_SRQIM = 30;           // Session request/new session detected interrupt mask, Read-write
    static const uint8_t FS_GINTMSK_WUIM = 31;            // Resume/remote wakeup detected interrupt mask, Read-write
    static const uint32_t FS_GINTMSK_RESET_VALUE = 0x0;

    static const uint8_t FS_GRXSTSR_Device_BCNT = 4;             // Byte count (11 bits)
    static const uint8_t FS_GRXSTSR_Device_DPID = 15;            // Data PID (2 bits)
    static const uint8_t FS_GRXSTSR_Device_EPNUM = 0;            // Endpoint number (4 bits)
    static const uint8_t FS_GRXSTSR_Device_FRMNUM = 21;          // Frame number (4 bits)
    static const uint8_t FS_GRXSTSR_Device_PKTSTS = 17;          // Packet status (4 bits)
    static const uint32_t FS_GRXSTSR_Device_RESET_VALUE = 0x0;

    static const uint8_t FS_GRXFSIZ_RXFD = 0;             // RxFIFO depth (16 bits)
    static const uint32_t FS_GRXFSIZ_RESET_VALUE = 0x200;

    static const uint8_t FS_GNPTXFSIZ_Device_NPTXFD = 16;          // Non-periodic TxFIFO depth (16 bits)
    static const uint8_t FS_GNPTXFSIZ_Device_NPTXFSA = 0;          // Non-periodic transmit RAM start address (16 bits)
    static const uint8_t FS_GNPTXFSIZ_Device_TX0FD = 16;           // Endpoint 0 TxFIFO depth (16 bits)
    static const uint8_t FS_GNPTXFSIZ_Device_TX0FSA = 0;           // Endpoint 0 transmit RAM start address (16 bits)
    static const uint32_t FS_GNPTXFSIZ_Device_RESET_VALUE = 0x200;

    static const uint8_t FS_GNPTXSTS_NPTXFSAV = 0;         // Non-periodic TxFIFO space available (16 bits)
    static const uint8_t FS_GNPTXSTS_NPTQXSAV = 16;        // Non-periodic transmit request queue space available (8 bits)
    static const uint8_t FS_GNPTXSTS_NPTXQTOP = 24;        // Top of the non-periodic transmit request queue (7 bits)
    static const uint32_t FS_GNPTXSTS_RESET_VALUE = 0x80200;

    static const uint8_t FS_GCCFG_DCDET = 0;            // DCDET
    static const uint8_t FS_GCCFG_PDET = 1;             // PDET
    static const uint8_t FS_GCCFG_SDET = 2;             // SDET
    static const uint8_t FS_GCCFG_PS2DET = 3;           // PS2DET
    static const uint8_t FS_GCCFG_PWRDWN = 16;          // PWRDWN
    static const uint8_t FS_GCCFG_BCDEN = 17;           // BCDEN
    static const uint8_t FS_GCCFG_DCDEN = 18;           // DCDEN
    static const uint8_t FS_GCCFG_PDEN = 19;            // PDEN
    static const uint8_t FS_GCCFG_SDEN = 20;            // SDEN
    static const uint8_t FS_GCCFG_VBDEN = 21;           // VBDEN
    static const uint32_t FS_GCCFG_RESET_VALUE = 0x0;

    static const uint8_t FS_CID_PRODUCT_ID = 0;       // Product ID field (32 bits)
    static const uint32_t FS_CID_RESET_VALUE = 0x1000;

    static const uint8_t FS_HPTXFSIZ_PTXSA = 0;            // Host periodic TxFIFO start address (16 bits)
    static const uint8_t FS_HPTXFSIZ_PTXFSIZ = 16;         // Host periodic TxFIFO depth (16 bits)
    static const uint32_t FS_HPTXFSIZ_RESET_VALUE = 0x2000600;

    static const uint8_t FS_DIEPTXF1_INEPTXSA = 0;         // IN endpoint FIFO2 transmit RAM start address (16 bits)
    static const uint8_t FS_DIEPTXF1_INEPTXFD = 16;        // IN endpoint TxFIFO depth (16 bits)
    static const uint32_t FS_DIEPTXF1_RESET_VALUE = 0x2000400;

    static const uint8_t FS_DIEPTXF2_INEPTXSA = 0;         // IN endpoint FIFO3 transmit RAM start address (16 bits)
    static const uint8_t FS_DIEPTXF2_INEPTXFD = 16;        // IN endpoint TxFIFO depth (16 bits)
    static const uint32_t FS_DIEPTXF2_RESET_VALUE = 0x2000400;

    static const uint8_t FS_DIEPTXF3_INEPTXSA = 0;         // IN endpoint FIFO4 transmit RAM start address (16 bits)
    static const uint8_t FS_DIEPTXF3_INEPTXFD = 16;        // IN endpoint TxFIFO depth (16 bits)
    static const uint32_t FS_DIEPTXF3_RESET_VALUE = 0x2000400;
};

static otg_fs_global_t& OTG_FS_GLOBAL = *reinterpret_cast<otg_fs_global_t*>(0x50000000);


////
//
//    USB on the go full speed
//
////

struct otg_fs_host_t
{
    volatile uint32_t    FS_HCFG;              // OTG_FS host configuration register (OTG_FS_HCFG)
    volatile uint32_t    HFIR;                 // [Read-write] OTG_FS Host frame interval register
    volatile uint32_t    FS_HFNUM;             // [Read-only] OTG_FS host frame number/frame time remaining register (OTG_FS_HFNUM)
    reserved_t<1>        _0;
    volatile uint32_t    FS_HPTXSTS;           // OTG_FS_Host periodic transmit FIFO/queue status register (OTG_FS_HPTXSTS)
    volatile uint32_t    HAINT;                // [Read-only] OTG_FS Host all channels interrupt register
    volatile uint32_t    HAINTMSK;             // [Read-write] OTG_FS host all channels interrupt mask register
    reserved_t<9>        _1;
    volatile uint32_t    FS_HPRT;              // OTG_FS host port control and status register (OTG_FS_HPRT)
    reserved_t<47>       _2;
    volatile uint32_t    FS_HCCHAR0;           // [Read-write] OTG_FS host channel-0 characteristics register (OTG_FS_HCCHAR0)
    reserved_t<1>        _3;
    volatile uint32_t    FS_HCINT0;            // [Read-write] OTG_FS host channel-0 interrupt register (OTG_FS_HCINT0)
    volatile uint32_t    FS_HCINTMSK0;         // [Read-write] OTG_FS host channel-0 mask register (OTG_FS_HCINTMSK0)
    volatile uint32_t    FS_HCTSIZ0;           // [Read-write] OTG_FS host channel-0 transfer size register
    reserved_t<3>        _4;
    volatile uint32_t    FS_HCCHAR1;           // [Read-write] OTG_FS host channel-1 characteristics register (OTG_FS_HCCHAR1)
    reserved_t<1>        _5;
    volatile uint32_t    FS_HCINT1;            // [Read-write] OTG_FS host channel-1 interrupt register (OTG_FS_HCINT1)
    volatile uint32_t    FS_HCINTMSK1;         // [Read-write] OTG_FS host channel-1 mask register (OTG_FS_HCINTMSK1)
    volatile uint32_t    FS_HCTSIZ1;           // [Read-write] OTG_FS host channel-1 transfer size register
    reserved_t<3>        _6;
    volatile uint32_t    FS_HCCHAR2;           // [Read-write] OTG_FS host channel-2 characteristics register (OTG_FS_HCCHAR2)
    reserved_t<1>        _7;
    volatile uint32_t    FS_HCINT2;            // [Read-write] OTG_FS host channel-2 interrupt register (OTG_FS_HCINT2)
    volatile uint32_t    FS_HCINTMSK2;         // [Read-write] OTG_FS host channel-2 mask register (OTG_FS_HCINTMSK2)
    volatile uint32_t    FS_HCTSIZ2;           // [Read-write] OTG_FS host channel-2 transfer size register
    reserved_t<3>        _8;
    volatile uint32_t    FS_HCCHAR3;           // [Read-write] OTG_FS host channel-3 characteristics register (OTG_FS_HCCHAR3)
    reserved_t<1>        _9;
    volatile uint32_t    FS_HCINT3;            // [Read-write] OTG_FS host channel-3 interrupt register (OTG_FS_HCINT3)
    volatile uint32_t    FS_HCINTMSK3;         // [Read-write] OTG_FS host channel-3 mask register (OTG_FS_HCINTMSK3)
    volatile uint32_t    FS_HCTSIZ3;           // [Read-write] OTG_FS host channel-3 transfer size register
    reserved_t<3>        _10;
    volatile uint32_t    FS_HCCHAR4;           // [Read-write] OTG_FS host channel-4 characteristics register (OTG_FS_HCCHAR4)
    reserved_t<1>        _11;
    volatile uint32_t    FS_HCINT4;            // [Read-write] OTG_FS host channel-4 interrupt register (OTG_FS_HCINT4)
    volatile uint32_t    FS_HCINTMSK4;         // [Read-write] OTG_FS host channel-4 mask register (OTG_FS_HCINTMSK4)
    volatile uint32_t    FS_HCTSIZ4;           // [Read-write] OTG_FS host channel-x transfer size register
    reserved_t<3>        _12;
    volatile uint32_t    FS_HCCHAR5;           // [Read-write] OTG_FS host channel-5 characteristics register (OTG_FS_HCCHAR5)
    reserved_t<1>        _13;
    volatile uint32_t    FS_HCINT5;            // [Read-write] OTG_FS host channel-5 interrupt register (OTG_FS_HCINT5)
    volatile uint32_t    FS_HCINTMSK5;         // [Read-write] OTG_FS host channel-5 mask register (OTG_FS_HCINTMSK5)
    volatile uint32_t    FS_HCTSIZ5;           // [Read-write] OTG_FS host channel-5 transfer size register
    reserved_t<3>        _14;
    volatile uint32_t    FS_HCCHAR6;           // [Read-write] OTG_FS host channel-6 characteristics register (OTG_FS_HCCHAR6)
    reserved_t<1>        _15;
    volatile uint32_t    FS_HCINT6;            // [Read-write] OTG_FS host channel-6 interrupt register (OTG_FS_HCINT6)
    volatile uint32_t    FS_HCINTMSK6;         // [Read-write] OTG_FS host channel-6 mask register (OTG_FS_HCINTMSK6)
    volatile uint32_t    FS_HCTSIZ6;           // [Read-write] OTG_FS host channel-6 transfer size register
    reserved_t<3>        _16;
    volatile uint32_t    FS_HCCHAR7;           // [Read-write] OTG_FS host channel-7 characteristics register (OTG_FS_HCCHAR7)
    reserved_t<1>        _17;
    volatile uint32_t    FS_HCINT7;            // [Read-write] OTG_FS host channel-7 interrupt register (OTG_FS_HCINT7)
    volatile uint32_t    FS_HCINTMSK7;         // [Read-write] OTG_FS host channel-7 mask register (OTG_FS_HCINTMSK7)
    volatile uint32_t    FS_HCTSIZ7;           // [Read-write] OTG_FS host channel-7 transfer size register

    static const uint8_t FS_HCFG_FSLSPCS = 0;          // FS/LS PHY clock select (2 bits), Read-write
    static const uint8_t FS_HCFG_FSLSS = 2;            // FS- and LS-only support, Read-only
    static const uint32_t FS_HCFG_RESET_VALUE = 0x0;

    static const uint8_t HFIR_FRIVL = 0;            // Frame interval (16 bits)
    static const uint32_t HFIR_RESET_VALUE = 0xea60;

    static const uint8_t FS_HFNUM_FRNUM = 0;            // Frame number (16 bits)
    static const uint8_t FS_HFNUM_FTREM = 16;           // Frame time remaining (16 bits)
    static const uint32_t FS_HFNUM_RESET_VALUE = 0x3fff;

    static const uint8_t FS_HPTXSTS_PTXFSAVL = 0;         // Periodic transmit data FIFO space available (16 bits), Read-write
    static const uint8_t FS_HPTXSTS_PTXQSAV = 16;         // Periodic transmit request queue space available (8 bits), Read-only
    static const uint8_t FS_HPTXSTS_PTXQTOP = 24;         // Top of the periodic transmit request queue (8 bits), Read-only
    static const uint32_t FS_HPTXSTS_RESET_VALUE = 0x80100;

    static const uint8_t HAINT_HAINT = 0;            // Channel interrupts (16 bits)
    static const uint32_t HAINT_RESET_VALUE = 0x0;

    static const uint8_t HAINTMSK_HAINTM = 0;           // Channel interrupt mask (16 bits)
    static const uint32_t HAINTMSK_RESET_VALUE = 0x0;

    static const uint8_t FS_HPRT_PCSTS = 0;            // Port connect status, Read-only
    static const uint8_t FS_HPRT_PCDET = 1;            // Port connect detected, Read-write
    static const uint8_t FS_HPRT_PENA = 2;             // Port enable, Read-write
    static const uint8_t FS_HPRT_PENCHNG = 3;          // Port enable/disable change, Read-write
    static const uint8_t FS_HPRT_POCA = 4;             // Port overcurrent active, Read-only
    static const uint8_t FS_HPRT_POCCHNG = 5;          // Port overcurrent change, Read-write
    static const uint8_t FS_HPRT_PRES = 6;             // Port resume, Read-write
    static const uint8_t FS_HPRT_PSUSP = 7;            // Port suspend, Read-write
    static const uint8_t FS_HPRT_PRST = 8;             // Port reset, Read-write
    static const uint8_t FS_HPRT_PLSTS = 10;           // Port line status (2 bits), Read-only
    static const uint8_t FS_HPRT_PPWR = 12;            // Port power, Read-write
    static const uint8_t FS_HPRT_PTCTL = 13;           // Port test control (4 bits), Read-write
    static const uint8_t FS_HPRT_PSPD = 17;            // Port speed (2 bits), Read-only
    static const uint32_t FS_HPRT_RESET_VALUE = 0x0;

    static const uint8_t FS_HCCHAR0_MPSIZ = 0;            // Maximum packet size (11 bits)
    static const uint8_t FS_HCCHAR0_EPNUM = 11;           // Endpoint number (4 bits)
    static const uint8_t FS_HCCHAR0_EPDIR = 15;           // Endpoint direction
    static const uint8_t FS_HCCHAR0_LSDEV = 17;           // Low-speed device
    static const uint8_t FS_HCCHAR0_EPTYP = 18;           // Endpoint type (2 bits)
    static const uint8_t FS_HCCHAR0_MCNT = 20;            // Multicount (2 bits)
    static const uint8_t FS_HCCHAR0_DAD = 22;             // Device address (7 bits)
    static const uint8_t FS_HCCHAR0_ODDFRM = 29;          // Odd frame
    static const uint8_t FS_HCCHAR0_CHDIS = 30;           // Channel disable
    static const uint8_t FS_HCCHAR0_CHENA = 31;           // Channel enable
    static const uint32_t FS_HCCHAR0_RESET_VALUE = 0x0;

    static const uint8_t FS_HCINT0_XFRC = 0;             // Transfer completed
    static const uint8_t FS_HCINT0_CHH = 1;              // Channel halted
    static const uint8_t FS_HCINT0_STALL = 3;            // STALL response received interrupt
    static const uint8_t FS_HCINT0_NAK = 4;              // NAK response received interrupt
    static const uint8_t FS_HCINT0_ACK = 5;              // ACK response received/transmitted interrupt
    static const uint8_t FS_HCINT0_TXERR = 7;            // Transaction error
    static const uint8_t FS_HCINT0_BBERR = 8;            // Babble error
    static const uint8_t FS_HCINT0_FRMOR = 9;            // Frame overrun
    static const uint8_t FS_HCINT0_DTERR = 10;           // Data toggle error
    static const uint32_t FS_HCINT0_RESET_VALUE = 0x0;

    static const uint8_t FS_HCINTMSK0_XFRCM = 0;            // Transfer completed mask
    static const uint8_t FS_HCINTMSK0_CHHM = 1;             // Channel halted mask
    static const uint8_t FS_HCINTMSK0_STALLM = 3;           // STALL response received interrupt mask
    static const uint8_t FS_HCINTMSK0_NAKM = 4;             // NAK response received interrupt mask
    static const uint8_t FS_HCINTMSK0_ACKM = 5;             // ACK response received/transmitted interrupt mask
    static const uint8_t FS_HCINTMSK0_NYET = 6;             // response received interrupt mask
    static const uint8_t FS_HCINTMSK0_TXERRM = 7;           // Transaction error mask
    static const uint8_t FS_HCINTMSK0_BBERRM = 8;           // Babble error mask
    static const uint8_t FS_HCINTMSK0_FRMORM = 9;           // Frame overrun mask
    static const uint8_t FS_HCINTMSK0_DTERRM = 10;          // Data toggle error mask
    static const uint32_t FS_HCINTMSK0_RESET_VALUE = 0x0;

    static const uint8_t FS_HCTSIZ0_XFRSIZ = 0;           // Transfer size (19 bits)
    static const uint8_t FS_HCTSIZ0_PKTCNT = 19;          // Packet count (10 bits)
    static const uint8_t FS_HCTSIZ0_DPID = 29;            // Data PID (2 bits)
    static const uint32_t FS_HCTSIZ0_RESET_VALUE = 0x0;

    static const uint8_t FS_HCCHAR1_MPSIZ = 0;            // Maximum packet size (11 bits)
    static const uint8_t FS_HCCHAR1_EPNUM = 11;           // Endpoint number (4 bits)
    static const uint8_t FS_HCCHAR1_EPDIR = 15;           // Endpoint direction
    static const uint8_t FS_HCCHAR1_LSDEV = 17;           // Low-speed device
    static const uint8_t FS_HCCHAR1_EPTYP = 18;           // Endpoint type (2 bits)
    static const uint8_t FS_HCCHAR1_MCNT = 20;            // Multicount (2 bits)
    static const uint8_t FS_HCCHAR1_DAD = 22;             // Device address (7 bits)
    static const uint8_t FS_HCCHAR1_ODDFRM = 29;          // Odd frame
    static const uint8_t FS_HCCHAR1_CHDIS = 30;           // Channel disable
    static const uint8_t FS_HCCHAR1_CHENA = 31;           // Channel enable
    static const uint32_t FS_HCCHAR1_RESET_VALUE = 0x0;

    static const uint8_t FS_HCINT1_XFRC = 0;             // Transfer completed
    static const uint8_t FS_HCINT1_CHH = 1;              // Channel halted
    static const uint8_t FS_HCINT1_STALL = 3;            // STALL response received interrupt
    static const uint8_t FS_HCINT1_NAK = 4;              // NAK response received interrupt
    static const uint8_t FS_HCINT1_ACK = 5;              // ACK response received/transmitted interrupt
    static const uint8_t FS_HCINT1_TXERR = 7;            // Transaction error
    static const uint8_t FS_HCINT1_BBERR = 8;            // Babble error
    static const uint8_t FS_HCINT1_FRMOR = 9;            // Frame overrun
    static const uint8_t FS_HCINT1_DTERR = 10;           // Data toggle error
    static const uint32_t FS_HCINT1_RESET_VALUE = 0x0;

    static const uint8_t FS_HCINTMSK1_XFRCM = 0;            // Transfer completed mask
    static const uint8_t FS_HCINTMSK1_CHHM = 1;             // Channel halted mask
    static const uint8_t FS_HCINTMSK1_STALLM = 3;           // STALL response received interrupt mask
    static const uint8_t FS_HCINTMSK1_NAKM = 4;             // NAK response received interrupt mask
    static const uint8_t FS_HCINTMSK1_ACKM = 5;             // ACK response received/transmitted interrupt mask
    static const uint8_t FS_HCINTMSK1_NYET = 6;             // response received interrupt mask
    static const uint8_t FS_HCINTMSK1_TXERRM = 7;           // Transaction error mask
    static const uint8_t FS_HCINTMSK1_BBERRM = 8;           // Babble error mask
    static const uint8_t FS_HCINTMSK1_FRMORM = 9;           // Frame overrun mask
    static const uint8_t FS_HCINTMSK1_DTERRM = 10;          // Data toggle error mask
    static const uint32_t FS_HCINTMSK1_RESET_VALUE = 0x0;

    static const uint8_t FS_HCTSIZ1_XFRSIZ = 0;           // Transfer size (19 bits)
    static const uint8_t FS_HCTSIZ1_PKTCNT = 19;          // Packet count (10 bits)
    static const uint8_t FS_HCTSIZ1_DPID = 29;            // Data PID (2 bits)
    static const uint32_t FS_HCTSIZ1_RESET_VALUE = 0x0;

    static const uint8_t FS_HCCHAR2_MPSIZ = 0;            // Maximum packet size (11 bits)
    static const uint8_t FS_HCCHAR2_EPNUM = 11;           // Endpoint number (4 bits)
    static const uint8_t FS_HCCHAR2_EPDIR = 15;           // Endpoint direction
    static const uint8_t FS_HCCHAR2_LSDEV = 17;           // Low-speed device
    static const uint8_t FS_HCCHAR2_EPTYP = 18;           // Endpoint type (2 bits)
    static const uint8_t FS_HCCHAR2_MCNT = 20;            // Multicount (2 bits)
    static const uint8_t FS_HCCHAR2_DAD = 22;             // Device address (7 bits)
    static const uint8_t FS_HCCHAR2_ODDFRM = 29;          // Odd frame
    static const uint8_t FS_HCCHAR2_CHDIS = 30;           // Channel disable
    static const uint8_t FS_HCCHAR2_CHENA = 31;           // Channel enable
    static const uint32_t FS_HCCHAR2_RESET_VALUE = 0x0;

    static const uint8_t FS_HCINT2_XFRC = 0;             // Transfer completed
    static const uint8_t FS_HCINT2_CHH = 1;              // Channel halted
    static const uint8_t FS_HCINT2_STALL = 3;            // STALL response received interrupt
    static const uint8_t FS_HCINT2_NAK = 4;              // NAK response received interrupt
    static const uint8_t FS_HCINT2_ACK = 5;              // ACK response received/transmitted interrupt
    static const uint8_t FS_HCINT2_TXERR = 7;            // Transaction error
    static const uint8_t FS_HCINT2_BBERR = 8;            // Babble error
    static const uint8_t FS_HCINT2_FRMOR = 9;            // Frame overrun
    static const uint8_t FS_HCINT2_DTERR = 10;           // Data toggle error
    static const uint32_t FS_HCINT2_RESET_VALUE = 0x0;

    static const uint8_t FS_HCINTMSK2_XFRCM = 0;            // Transfer completed mask
    static const uint8_t FS_HCINTMSK2_CHHM = 1;             // Channel halted mask
    static const uint8_t FS_HCINTMSK2_STALLM = 3;           // STALL response received interrupt mask
    static const uint8_t FS_HCINTMSK2_NAKM = 4;             // NAK response received interrupt mask
    static const uint8_t FS_HCINTMSK2_ACKM = 5;             // ACK response received/transmitted interrupt mask
    static const uint8_t FS_HCINTMSK2_NYET = 6;             // response received interrupt mask
    static const uint8_t FS_HCINTMSK2_TXERRM = 7;           // Transaction error mask
    static const uint8_t FS_HCINTMSK2_BBERRM = 8;           // Babble error mask
    static const uint8_t FS_HCINTMSK2_FRMORM = 9;           // Frame overrun mask
    static const uint8_t FS_HCINTMSK2_DTERRM = 10;          // Data toggle error mask
    static const uint32_t FS_HCINTMSK2_RESET_VALUE = 0x0;

    static const uint8_t FS_HCTSIZ2_XFRSIZ = 0;           // Transfer size (19 bits)
    static const uint8_t FS_HCTSIZ2_PKTCNT = 19;          // Packet count (10 bits)
    static const uint8_t FS_HCTSIZ2_DPID = 29;            // Data PID (2 bits)
    static const uint32_t FS_HCTSIZ2_RESET_VALUE = 0x0;

    static const uint8_t FS_HCCHAR3_MPSIZ = 0;            // Maximum packet size (11 bits)
    static const uint8_t FS_HCCHAR3_EPNUM = 11;           // Endpoint number (4 bits)
    static const uint8_t FS_HCCHAR3_EPDIR = 15;           // Endpoint direction
    static const uint8_t FS_HCCHAR3_LSDEV = 17;           // Low-speed device
    static const uint8_t FS_HCCHAR3_EPTYP = 18;           // Endpoint type (2 bits)
    static const uint8_t FS_HCCHAR3_MCNT = 20;            // Multicount (2 bits)
    static const uint8_t FS_HCCHAR3_DAD = 22;             // Device address (7 bits)
    static const uint8_t FS_HCCHAR3_ODDFRM = 29;          // Odd frame
    static const uint8_t FS_HCCHAR3_CHDIS = 30;           // Channel disable
    static const uint8_t FS_HCCHAR3_CHENA = 31;           // Channel enable
    static const uint32_t FS_HCCHAR3_RESET_VALUE = 0x0;

    static const uint8_t FS_HCINT3_XFRC = 0;             // Transfer completed
    static const uint8_t FS_HCINT3_CHH = 1;              // Channel halted
    static const uint8_t FS_HCINT3_STALL = 3;            // STALL response received interrupt
    static const uint8_t FS_HCINT3_NAK = 4;              // NAK response received interrupt
    static const uint8_t FS_HCINT3_ACK = 5;              // ACK response received/transmitted interrupt
    static const uint8_t FS_HCINT3_TXERR = 7;            // Transaction error
    static const uint8_t FS_HCINT3_BBERR = 8;            // Babble error
    static const uint8_t FS_HCINT3_FRMOR = 9;            // Frame overrun
    static const uint8_t FS_HCINT3_DTERR = 10;           // Data toggle error
    static const uint32_t FS_HCINT3_RESET_VALUE = 0x0;

    static const uint8_t FS_HCINTMSK3_XFRCM = 0;            // Transfer completed mask
    static const uint8_t FS_HCINTMSK3_CHHM = 1;             // Channel halted mask
    static const uint8_t FS_HCINTMSK3_STALLM = 3;           // STALL response received interrupt mask
    static const uint8_t FS_HCINTMSK3_NAKM = 4;             // NAK response received interrupt mask
    static const uint8_t FS_HCINTMSK3_ACKM = 5;             // ACK response received/transmitted interrupt mask
    static const uint8_t FS_HCINTMSK3_NYET = 6;             // response received interrupt mask
    static const uint8_t FS_HCINTMSK3_TXERRM = 7;           // Transaction error mask
    static const uint8_t FS_HCINTMSK3_BBERRM = 8;           // Babble error mask
    static const uint8_t FS_HCINTMSK3_FRMORM = 9;           // Frame overrun mask
    static const uint8_t FS_HCINTMSK3_DTERRM = 10;          // Data toggle error mask
    static const uint32_t FS_HCINTMSK3_RESET_VALUE = 0x0;

    static const uint8_t FS_HCTSIZ3_XFRSIZ = 0;           // Transfer size (19 bits)
    static const uint8_t FS_HCTSIZ3_PKTCNT = 19;          // Packet count (10 bits)
    static const uint8_t FS_HCTSIZ3_DPID = 29;            // Data PID (2 bits)
    static const uint32_t FS_HCTSIZ3_RESET_VALUE = 0x0;

    static const uint8_t FS_HCCHAR4_MPSIZ = 0;            // Maximum packet size (11 bits)
    static const uint8_t FS_HCCHAR4_EPNUM = 11;           // Endpoint number (4 bits)
    static const uint8_t FS_HCCHAR4_EPDIR = 15;           // Endpoint direction
    static const uint8_t FS_HCCHAR4_LSDEV = 17;           // Low-speed device
    static const uint8_t FS_HCCHAR4_EPTYP = 18;           // Endpoint type (2 bits)
    static const uint8_t FS_HCCHAR4_MCNT = 20;            // Multicount (2 bits)
    static const uint8_t FS_HCCHAR4_DAD = 22;             // Device address (7 bits)
    static const uint8_t FS_HCCHAR4_ODDFRM = 29;          // Odd frame
    static const uint8_t FS_HCCHAR4_CHDIS = 30;           // Channel disable
    static const uint8_t FS_HCCHAR4_CHENA = 31;           // Channel enable
    static const uint32_t FS_HCCHAR4_RESET_VALUE = 0x0;

    static const uint8_t FS_HCINT4_XFRC = 0;             // Transfer completed
    static const uint8_t FS_HCINT4_CHH = 1;              // Channel halted
    static const uint8_t FS_HCINT4_STALL = 3;            // STALL response received interrupt
    static const uint8_t FS_HCINT4_NAK = 4;              // NAK response received interrupt
    static const uint8_t FS_HCINT4_ACK = 5;              // ACK response received/transmitted interrupt
    static const uint8_t FS_HCINT4_TXERR = 7;            // Transaction error
    static const uint8_t FS_HCINT4_BBERR = 8;            // Babble error
    static const uint8_t FS_HCINT4_FRMOR = 9;            // Frame overrun
    static const uint8_t FS_HCINT4_DTERR = 10;           // Data toggle error
    static const uint32_t FS_HCINT4_RESET_VALUE = 0x0;

    static const uint8_t FS_HCINTMSK4_XFRCM = 0;            // Transfer completed mask
    static const uint8_t FS_HCINTMSK4_CHHM = 1;             // Channel halted mask
    static const uint8_t FS_HCINTMSK4_STALLM = 3;           // STALL response received interrupt mask
    static const uint8_t FS_HCINTMSK4_NAKM = 4;             // NAK response received interrupt mask
    static const uint8_t FS_HCINTMSK4_ACKM = 5;             // ACK response received/transmitted interrupt mask
    static const uint8_t FS_HCINTMSK4_NYET = 6;             // response received interrupt mask
    static const uint8_t FS_HCINTMSK4_TXERRM = 7;           // Transaction error mask
    static const uint8_t FS_HCINTMSK4_BBERRM = 8;           // Babble error mask
    static const uint8_t FS_HCINTMSK4_FRMORM = 9;           // Frame overrun mask
    static const uint8_t FS_HCINTMSK4_DTERRM = 10;          // Data toggle error mask
    static const uint32_t FS_HCINTMSK4_RESET_VALUE = 0x0;

    static const uint8_t FS_HCTSIZ4_XFRSIZ = 0;           // Transfer size (19 bits)
    static const uint8_t FS_HCTSIZ4_PKTCNT = 19;          // Packet count (10 bits)
    static const uint8_t FS_HCTSIZ4_DPID = 29;            // Data PID (2 bits)
    static const uint32_t FS_HCTSIZ4_RESET_VALUE = 0x0;

    static const uint8_t FS_HCCHAR5_MPSIZ = 0;            // Maximum packet size (11 bits)
    static const uint8_t FS_HCCHAR5_EPNUM = 11;           // Endpoint number (4 bits)
    static const uint8_t FS_HCCHAR5_EPDIR = 15;           // Endpoint direction
    static const uint8_t FS_HCCHAR5_LSDEV = 17;           // Low-speed device
    static const uint8_t FS_HCCHAR5_EPTYP = 18;           // Endpoint type (2 bits)
    static const uint8_t FS_HCCHAR5_MCNT = 20;            // Multicount (2 bits)
    static const uint8_t FS_HCCHAR5_DAD = 22;             // Device address (7 bits)
    static const uint8_t FS_HCCHAR5_ODDFRM = 29;          // Odd frame
    static const uint8_t FS_HCCHAR5_CHDIS = 30;           // Channel disable
    static const uint8_t FS_HCCHAR5_CHENA = 31;           // Channel enable
    static const uint32_t FS_HCCHAR5_RESET_VALUE = 0x0;

    static const uint8_t FS_HCINT5_XFRC = 0;             // Transfer completed
    static const uint8_t FS_HCINT5_CHH = 1;              // Channel halted
    static const uint8_t FS_HCINT5_STALL = 3;            // STALL response received interrupt
    static const uint8_t FS_HCINT5_NAK = 4;              // NAK response received interrupt
    static const uint8_t FS_HCINT5_ACK = 5;              // ACK response received/transmitted interrupt
    static const uint8_t FS_HCINT5_TXERR = 7;            // Transaction error
    static const uint8_t FS_HCINT5_BBERR = 8;            // Babble error
    static const uint8_t FS_HCINT5_FRMOR = 9;            // Frame overrun
    static const uint8_t FS_HCINT5_DTERR = 10;           // Data toggle error
    static const uint32_t FS_HCINT5_RESET_VALUE = 0x0;

    static const uint8_t FS_HCINTMSK5_XFRCM = 0;            // Transfer completed mask
    static const uint8_t FS_HCINTMSK5_CHHM = 1;             // Channel halted mask
    static const uint8_t FS_HCINTMSK5_STALLM = 3;           // STALL response received interrupt mask
    static const uint8_t FS_HCINTMSK5_NAKM = 4;             // NAK response received interrupt mask
    static const uint8_t FS_HCINTMSK5_ACKM = 5;             // ACK response received/transmitted interrupt mask
    static const uint8_t FS_HCINTMSK5_NYET = 6;             // response received interrupt mask
    static const uint8_t FS_HCINTMSK5_TXERRM = 7;           // Transaction error mask
    static const uint8_t FS_HCINTMSK5_BBERRM = 8;           // Babble error mask
    static const uint8_t FS_HCINTMSK5_FRMORM = 9;           // Frame overrun mask
    static const uint8_t FS_HCINTMSK5_DTERRM = 10;          // Data toggle error mask
    static const uint32_t FS_HCINTMSK5_RESET_VALUE = 0x0;

    static const uint8_t FS_HCTSIZ5_XFRSIZ = 0;           // Transfer size (19 bits)
    static const uint8_t FS_HCTSIZ5_PKTCNT = 19;          // Packet count (10 bits)
    static const uint8_t FS_HCTSIZ5_DPID = 29;            // Data PID (2 bits)
    static const uint32_t FS_HCTSIZ5_RESET_VALUE = 0x0;

    static const uint8_t FS_HCCHAR6_MPSIZ = 0;            // Maximum packet size (11 bits)
    static const uint8_t FS_HCCHAR6_EPNUM = 11;           // Endpoint number (4 bits)
    static const uint8_t FS_HCCHAR6_EPDIR = 15;           // Endpoint direction
    static const uint8_t FS_HCCHAR6_LSDEV = 17;           // Low-speed device
    static const uint8_t FS_HCCHAR6_EPTYP = 18;           // Endpoint type (2 bits)
    static const uint8_t FS_HCCHAR6_MCNT = 20;            // Multicount (2 bits)
    static const uint8_t FS_HCCHAR6_DAD = 22;             // Device address (7 bits)
    static const uint8_t FS_HCCHAR6_ODDFRM = 29;          // Odd frame
    static const uint8_t FS_HCCHAR6_CHDIS = 30;           // Channel disable
    static const uint8_t FS_HCCHAR6_CHENA = 31;           // Channel enable
    static const uint32_t FS_HCCHAR6_RESET_VALUE = 0x0;

    static const uint8_t FS_HCINT6_XFRC = 0;             // Transfer completed
    static const uint8_t FS_HCINT6_CHH = 1;              // Channel halted
    static const uint8_t FS_HCINT6_STALL = 3;            // STALL response received interrupt
    static const uint8_t FS_HCINT6_NAK = 4;              // NAK response received interrupt
    static const uint8_t FS_HCINT6_ACK = 5;              // ACK response received/transmitted interrupt
    static const uint8_t FS_HCINT6_TXERR = 7;            // Transaction error
    static const uint8_t FS_HCINT6_BBERR = 8;            // Babble error
    static const uint8_t FS_HCINT6_FRMOR = 9;            // Frame overrun
    static const uint8_t FS_HCINT6_DTERR = 10;           // Data toggle error
    static const uint32_t FS_HCINT6_RESET_VALUE = 0x0;

    static const uint8_t FS_HCINTMSK6_XFRCM = 0;            // Transfer completed mask
    static const uint8_t FS_HCINTMSK6_CHHM = 1;             // Channel halted mask
    static const uint8_t FS_HCINTMSK6_STALLM = 3;           // STALL response received interrupt mask
    static const uint8_t FS_HCINTMSK6_NAKM = 4;             // NAK response received interrupt mask
    static const uint8_t FS_HCINTMSK6_ACKM = 5;             // ACK response received/transmitted interrupt mask
    static const uint8_t FS_HCINTMSK6_NYET = 6;             // response received interrupt mask
    static const uint8_t FS_HCINTMSK6_TXERRM = 7;           // Transaction error mask
    static const uint8_t FS_HCINTMSK6_BBERRM = 8;           // Babble error mask
    static const uint8_t FS_HCINTMSK6_FRMORM = 9;           // Frame overrun mask
    static const uint8_t FS_HCINTMSK6_DTERRM = 10;          // Data toggle error mask
    static const uint32_t FS_HCINTMSK6_RESET_VALUE = 0x0;

    static const uint8_t FS_HCTSIZ6_XFRSIZ = 0;           // Transfer size (19 bits)
    static const uint8_t FS_HCTSIZ6_PKTCNT = 19;          // Packet count (10 bits)
    static const uint8_t FS_HCTSIZ6_DPID = 29;            // Data PID (2 bits)
    static const uint32_t FS_HCTSIZ6_RESET_VALUE = 0x0;

    static const uint8_t FS_HCCHAR7_MPSIZ = 0;            // Maximum packet size (11 bits)
    static const uint8_t FS_HCCHAR7_EPNUM = 11;           // Endpoint number (4 bits)
    static const uint8_t FS_HCCHAR7_EPDIR = 15;           // Endpoint direction
    static const uint8_t FS_HCCHAR7_LSDEV = 17;           // Low-speed device
    static const uint8_t FS_HCCHAR7_EPTYP = 18;           // Endpoint type (2 bits)
    static const uint8_t FS_HCCHAR7_MCNT = 20;            // Multicount (2 bits)
    static const uint8_t FS_HCCHAR7_DAD = 22;             // Device address (7 bits)
    static const uint8_t FS_HCCHAR7_ODDFRM = 29;          // Odd frame
    static const uint8_t FS_HCCHAR7_CHDIS = 30;           // Channel disable
    static const uint8_t FS_HCCHAR7_CHENA = 31;           // Channel enable
    static const uint32_t FS_HCCHAR7_RESET_VALUE = 0x0;

    static const uint8_t FS_HCINT7_XFRC = 0;             // Transfer completed
    static const uint8_t FS_HCINT7_CHH = 1;              // Channel halted
    static const uint8_t FS_HCINT7_STALL = 3;            // STALL response received interrupt
    static const uint8_t FS_HCINT7_NAK = 4;              // NAK response received interrupt
    static const uint8_t FS_HCINT7_ACK = 5;              // ACK response received/transmitted interrupt
    static const uint8_t FS_HCINT7_TXERR = 7;            // Transaction error
    static const uint8_t FS_HCINT7_BBERR = 8;            // Babble error
    static const uint8_t FS_HCINT7_FRMOR = 9;            // Frame overrun
    static const uint8_t FS_HCINT7_DTERR = 10;           // Data toggle error
    static const uint32_t FS_HCINT7_RESET_VALUE = 0x0;

    static const uint8_t FS_HCINTMSK7_XFRCM = 0;            // Transfer completed mask
    static const uint8_t FS_HCINTMSK7_CHHM = 1;             // Channel halted mask
    static const uint8_t FS_HCINTMSK7_STALLM = 3;           // STALL response received interrupt mask
    static const uint8_t FS_HCINTMSK7_NAKM = 4;             // NAK response received interrupt mask
    static const uint8_t FS_HCINTMSK7_ACKM = 5;             // ACK response received/transmitted interrupt mask
    static const uint8_t FS_HCINTMSK7_NYET = 6;             // response received interrupt mask
    static const uint8_t FS_HCINTMSK7_TXERRM = 7;           // Transaction error mask
    static const uint8_t FS_HCINTMSK7_BBERRM = 8;           // Babble error mask
    static const uint8_t FS_HCINTMSK7_FRMORM = 9;           // Frame overrun mask
    static const uint8_t FS_HCINTMSK7_DTERRM = 10;          // Data toggle error mask
    static const uint32_t FS_HCINTMSK7_RESET_VALUE = 0x0;

    static const uint8_t FS_HCTSIZ7_XFRSIZ = 0;           // Transfer size (19 bits)
    static const uint8_t FS_HCTSIZ7_PKTCNT = 19;          // Packet count (10 bits)
    static const uint8_t FS_HCTSIZ7_DPID = 29;            // Data PID (2 bits)
    static const uint32_t FS_HCTSIZ7_RESET_VALUE = 0x0;
};

static otg_fs_host_t& OTG_FS_HOST = *reinterpret_cast<otg_fs_host_t*>(0x50000400);


////
//
//    USB on the go full speed
//
////

struct otg_fs_device_t
{
    volatile uint32_t    FS_DCFG;              // [Read-write] OTG_FS device configuration register (OTG_FS_DCFG)
    volatile uint32_t    FS_DCTL;              // OTG_FS device control register (OTG_FS_DCTL)
    volatile uint32_t    FS_DSTS;              // [Read-only] OTG_FS device status register (OTG_FS_DSTS)
    reserved_t<1>        _0;
    volatile uint32_t    FS_DIEPMSK;           // [Read-write] OTG_FS device IN endpoint common interrupt mask register (OTG_FS_DIEPMSK)
    volatile uint32_t    FS_DOEPMSK;           // [Read-write] OTG_FS device OUT endpoint common interrupt mask register (OTG_FS_DOEPMSK)
    volatile uint32_t    FS_DAINT;             // [Read-only] OTG_FS device all endpoints interrupt register (OTG_FS_DAINT)
    volatile uint32_t    FS_DAINTMSK;          // [Read-write] OTG_FS all endpoints interrupt mask register (OTG_FS_DAINTMSK)
    reserved_t<2>        _1;
    volatile uint32_t    DVBUSDIS;             // [Read-write] OTG_FS device VBUS discharge time register
    volatile uint32_t    DVBUSPULSE;           // [Read-write] OTG_FS device VBUS pulsing time register
    reserved_t<1>        _2;
    volatile uint32_t    DIEPEMPMSK;           // [Read-write] OTG_FS device IN endpoint FIFO empty interrupt mask register
    reserved_t<50>       _3;
    volatile uint32_t    FS_DIEPCTL0;          // OTG_FS device control IN endpoint 0 control register (OTG_FS_DIEPCTL0)
    reserved_t<1>        _4;
    volatile uint32_t    DIEPINT0;             // device endpoint-x interrupt register
    reserved_t<1>        _5;
    volatile uint32_t    DIEPTSIZ0;            // [Read-write] device endpoint-0 transfer size register
    reserved_t<1>        _6;
    volatile uint32_t    DTXFSTS0;             // [Read-only] OTG_FS device IN endpoint transmit FIFO status register
    reserved_t<1>        _7;
    volatile uint32_t    DIEPCTL1;             // OTG device endpoint-1 control register
    reserved_t<1>        _8;
    volatile uint32_t    DIEPINT1;             // device endpoint-1 interrupt register
    reserved_t<1>        _9;
    volatile uint32_t    DIEPTSIZ1;            // [Read-write] device endpoint-1 transfer size register
    reserved_t<1>        _10;
    volatile uint32_t    DTXFSTS1;             // [Read-only] OTG_FS device IN endpoint transmit FIFO status register
    reserved_t<1>        _11;
    volatile uint32_t    DIEPCTL2;             // OTG device endpoint-2 control register
    reserved_t<1>        _12;
    volatile uint32_t    DIEPINT2;             // device endpoint-2 interrupt register
    reserved_t<1>        _13;
    volatile uint32_t    DIEPTSIZ2;            // [Read-write] device endpoint-2 transfer size register
    reserved_t<1>        _14;
    volatile uint32_t    DTXFSTS2;             // [Read-only] OTG_FS device IN endpoint transmit FIFO status register
    reserved_t<1>        _15;
    volatile uint32_t    DIEPCTL3;             // OTG device endpoint-3 control register
    reserved_t<1>        _16;
    volatile uint32_t    DIEPINT3;             // device endpoint-3 interrupt register
    reserved_t<1>        _17;
    volatile uint32_t    DIEPTSIZ3;            // [Read-write] device endpoint-3 transfer size register
    reserved_t<1>        _18;
    volatile uint32_t    DTXFSTS3;             // [Read-only] OTG_FS device IN endpoint transmit FIFO status register
    reserved_t<97>       _19;
    volatile uint32_t    DOEPCTL0;             // device endpoint-0 control register
    reserved_t<1>        _20;
    volatile uint32_t    DOEPINT0;             // [Read-write] device endpoint-0 interrupt register
    reserved_t<1>        _21;
    volatile uint32_t    DOEPTSIZ0;            // [Read-write] device OUT endpoint-0 transfer size register
    reserved_t<3>        _22;
    volatile uint32_t    DOEPCTL1;             // device endpoint-1 control register
    reserved_t<1>        _23;
    volatile uint32_t    DOEPINT1;             // [Read-write] device endpoint-1 interrupt register
    reserved_t<1>        _24;
    volatile uint32_t    DOEPTSIZ1;            // [Read-write] device OUT endpoint-1 transfer size register
    reserved_t<3>        _25;
    volatile uint32_t    DOEPCTL2;             // device endpoint-2 control register
    reserved_t<1>        _26;
    volatile uint32_t    DOEPINT2;             // [Read-write] device endpoint-2 interrupt register
    reserved_t<1>        _27;
    volatile uint32_t    DOEPTSIZ2;            // [Read-write] device OUT endpoint-2 transfer size register
    reserved_t<3>        _28;
    volatile uint32_t    DOEPCTL3;             // device endpoint-3 control register
    reserved_t<1>        _29;
    volatile uint32_t    DOEPINT3;             // [Read-write] device endpoint-3 interrupt register
    reserved_t<1>        _30;
    volatile uint32_t    DOEPTSIZ3;            // [Read-write] device OUT endpoint-3 transfer size register

    static const uint8_t FS_DCFG_DSPD = 0;             // Device speed (2 bits)
    static const uint8_t FS_DCFG_NZLSOHSK = 2;         // Non-zero-length status OUT handshake
    static const uint8_t FS_DCFG_DAD = 4;              // Device address (7 bits)
    static const uint8_t FS_DCFG_PFIVL = 11;           // Periodic frame interval (2 bits)
    static const uint32_t FS_DCFG_RESET_VALUE = 0x2200000;

    static const uint8_t FS_DCTL_RWUSIG = 0;           // Remote wakeup signaling, Read-write
    static const uint8_t FS_DCTL_SDIS = 1;             // Soft disconnect, Read-write
    static const uint8_t FS_DCTL_GINSTS = 2;           // Global IN NAK status, Read-only
    static const uint8_t FS_DCTL_GONSTS = 3;           // Global OUT NAK status, Read-only
    static const uint8_t FS_DCTL_TCTL = 4;             // Test control (3 bits), Read-write
    static const uint8_t FS_DCTL_SGINAK = 7;           // Set global IN NAK, Read-write
    static const uint8_t FS_DCTL_CGINAK = 8;           // Clear global IN NAK, Read-write
    static const uint8_t FS_DCTL_SGONAK = 9;           // Set global OUT NAK, Read-write
    static const uint8_t FS_DCTL_CGONAK = 10;          // Clear global OUT NAK, Read-write
    static const uint8_t FS_DCTL_POPRGDNE = 11;        // Power-on programming done, Read-write
    static const uint32_t FS_DCTL_RESET_VALUE = 0x0;

    static const uint8_t FS_DSTS_SUSPSTS = 0;          // Suspend status
    static const uint8_t FS_DSTS_ENUMSPD = 1;          // Enumerated speed (2 bits)
    static const uint8_t FS_DSTS_EERR = 3;             // Erratic error
    static const uint8_t FS_DSTS_FNSOF = 8;            // Frame number of the received SOF (14 bits)
    static const uint32_t FS_DSTS_RESET_VALUE = 0x10;

    static const uint8_t FS_DIEPMSK_XFRCM = 0;            // Transfer completed interrupt mask
    static const uint8_t FS_DIEPMSK_EPDM = 1;             // Endpoint disabled interrupt mask
    static const uint8_t FS_DIEPMSK_TOM = 3;              // Timeout condition mask (Non-isochronous endpoints)
    static const uint8_t FS_DIEPMSK_ITTXFEMSK = 4;        // IN token received when TxFIFO empty mask
    static const uint8_t FS_DIEPMSK_INEPNMM = 5;          // IN token received with EP mismatch mask
    static const uint8_t FS_DIEPMSK_INEPNEM = 6;          // IN endpoint NAK effective mask
    static const uint32_t FS_DIEPMSK_RESET_VALUE = 0x0;

    static const uint8_t FS_DOEPMSK_XFRCM = 0;            // Transfer completed interrupt mask
    static const uint8_t FS_DOEPMSK_EPDM = 1;             // Endpoint disabled interrupt mask
    static const uint8_t FS_DOEPMSK_STUPM = 3;            // SETUP phase done mask
    static const uint8_t FS_DOEPMSK_OTEPDM = 4;           // OUT token received when endpoint disabled mask
    static const uint32_t FS_DOEPMSK_RESET_VALUE = 0x0;

    static const uint8_t FS_DAINT_IEPINT = 0;           // IN endpoint interrupt bits (16 bits)
    static const uint8_t FS_DAINT_OEPINT = 16;          // OUT endpoint interrupt bits (16 bits)
    static const uint32_t FS_DAINT_RESET_VALUE = 0x0;

    static const uint8_t FS_DAINTMSK_IEPM = 0;             // IN EP interrupt mask bits (16 bits)
    static const uint8_t FS_DAINTMSK_OEPINT = 16;          // OUT endpoint interrupt bits (16 bits)
    static const uint32_t FS_DAINTMSK_RESET_VALUE = 0x0;

    static const uint8_t DVBUSDIS_VBUSDT = 0;           // Device VBUS discharge time (16 bits)
    static const uint32_t DVBUSDIS_RESET_VALUE = 0x17d7;

    static const uint8_t DVBUSPULSE_DVBUSP = 0;           // Device VBUS pulsing time (12 bits)
    static const uint32_t DVBUSPULSE_RESET_VALUE = 0x5b8;

    static const uint8_t DIEPEMPMSK_INEPTXFEM = 0;        // IN EP Tx FIFO empty interrupt mask bits (16 bits)
    static const uint32_t DIEPEMPMSK_RESET_VALUE = 0x0;

    static const uint8_t FS_DIEPCTL0_MPSIZ = 0;            // Maximum packet size (2 bits), Read-write
    static const uint8_t FS_DIEPCTL0_USBAEP = 15;          // USB active endpoint, Read-only
    static const uint8_t FS_DIEPCTL0_NAKSTS = 17;          // NAK status, Read-only
    static const uint8_t FS_DIEPCTL0_EPTYP = 18;           // Endpoint type (2 bits), Read-only
    static const uint8_t FS_DIEPCTL0_STALL = 21;           // STALL handshake, Read-write
    static const uint8_t FS_DIEPCTL0_TXFNUM = 22;          // TxFIFO number (4 bits), Read-write
    static const uint8_t FS_DIEPCTL0_CNAK = 26;            // Clear NAK, Write-only
    static const uint8_t FS_DIEPCTL0_SNAK = 27;            // Set NAK, Write-only
    static const uint8_t FS_DIEPCTL0_EPDIS = 30;           // Endpoint disable, Read-only
    static const uint8_t FS_DIEPCTL0_EPENA = 31;           // Endpoint enable, Read-only
    static const uint32_t FS_DIEPCTL0_RESET_VALUE = 0x0;

    static const uint8_t DIEPINT0_TXFE = 7;             // TXFE, Read-only
    static const uint8_t DIEPINT0_INEPNE = 6;           // INEPNE, Read-write
    static const uint8_t DIEPINT0_ITTXFE = 4;           // ITTXFE, Read-write
    static const uint8_t DIEPINT0_TOC = 3;              // TOC, Read-write
    static const uint8_t DIEPINT0_EPDISD = 1;           // EPDISD, Read-write
    static const uint8_t DIEPINT0_XFRC = 0;             // XFRC, Read-write
    static const uint32_t DIEPINT0_RESET_VALUE = 0x80;

    static const uint8_t DIEPTSIZ0_PKTCNT = 19;          // Packet count (2 bits)
    static const uint8_t DIEPTSIZ0_XFRSIZ = 0;           // Transfer size (7 bits)
    static const uint32_t DIEPTSIZ0_RESET_VALUE = 0x0;

    static const uint8_t DTXFSTS0_INEPTFSAV = 0;        // IN endpoint TxFIFO space available (16 bits)
    static const uint32_t DTXFSTS0_RESET_VALUE = 0x0;

    static const uint8_t DIEPCTL1_EPENA = 31;           // EPENA, Read-write
    static const uint8_t DIEPCTL1_EPDIS = 30;           // EPDIS, Read-write
    static const uint8_t DIEPCTL1_SODDFRM_SD1PID = 29;  // SODDFRM/SD1PID, Write-only
    static const uint8_t DIEPCTL1_SD0PID_SEVNFRM = 28;  // SD0PID/SEVNFRM, Write-only
    static const uint8_t DIEPCTL1_SNAK = 27;            // SNAK, Write-only
    static const uint8_t DIEPCTL1_CNAK = 26;            // CNAK, Write-only
    static const uint8_t DIEPCTL1_TXFNUM = 22;          // TXFNUM (4 bits), Read-write
    static const uint8_t DIEPCTL1_Stall = 21;           // Stall, Read-write
    static const uint8_t DIEPCTL1_EPTYP = 18;           // EPTYP (2 bits), Read-write
    static const uint8_t DIEPCTL1_NAKSTS = 17;          // NAKSTS, Read-only
    static const uint8_t DIEPCTL1_EONUM_DPID = 16;      // EONUM/DPID, Read-only
    static const uint8_t DIEPCTL1_USBAEP = 15;          // USBAEP, Read-write
    static const uint8_t DIEPCTL1_MPSIZ = 0;            // MPSIZ (11 bits), Read-write
    static const uint32_t DIEPCTL1_RESET_VALUE = 0x0;

    static const uint8_t DIEPINT1_TXFE = 7;             // TXFE, Read-only
    static const uint8_t DIEPINT1_INEPNE = 6;           // INEPNE, Read-write
    static const uint8_t DIEPINT1_ITTXFE = 4;           // ITTXFE, Read-write
    static const uint8_t DIEPINT1_TOC = 3;              // TOC, Read-write
    static const uint8_t DIEPINT1_EPDISD = 1;           // EPDISD, Read-write
    static const uint8_t DIEPINT1_XFRC = 0;             // XFRC, Read-write
    static const uint32_t DIEPINT1_RESET_VALUE = 0x80;

    static const uint8_t DIEPTSIZ1_MCNT = 29;            // Multi count (2 bits)
    static const uint8_t DIEPTSIZ1_PKTCNT = 19;          // Packet count (10 bits)
    static const uint8_t DIEPTSIZ1_XFRSIZ = 0;           // Transfer size (19 bits)
    static const uint32_t DIEPTSIZ1_RESET_VALUE = 0x0;

    static const uint8_t DTXFSTS1_INEPTFSAV = 0;        // IN endpoint TxFIFO space available (16 bits)
    static const uint32_t DTXFSTS1_RESET_VALUE = 0x0;

    static const uint8_t DIEPCTL2_EPENA = 31;           // EPENA, Read-write
    static const uint8_t DIEPCTL2_EPDIS = 30;           // EPDIS, Read-write
    static const uint8_t DIEPCTL2_SODDFRM = 29;         // SODDFRM, Write-only
    static const uint8_t DIEPCTL2_SD0PID_SEVNFRM = 28;  // SD0PID/SEVNFRM, Write-only
    static const uint8_t DIEPCTL2_SNAK = 27;            // SNAK, Write-only
    static const uint8_t DIEPCTL2_CNAK = 26;            // CNAK, Write-only
    static const uint8_t DIEPCTL2_TXFNUM = 22;          // TXFNUM (4 bits), Read-write
    static const uint8_t DIEPCTL2_Stall = 21;           // Stall, Read-write
    static const uint8_t DIEPCTL2_EPTYP = 18;           // EPTYP (2 bits), Read-write
    static const uint8_t DIEPCTL2_NAKSTS = 17;          // NAKSTS, Read-only
    static const uint8_t DIEPCTL2_EONUM_DPID = 16;      // EONUM/DPID, Read-only
    static const uint8_t DIEPCTL2_USBAEP = 15;          // USBAEP, Read-write
    static const uint8_t DIEPCTL2_MPSIZ = 0;            // MPSIZ (11 bits), Read-write
    static const uint32_t DIEPCTL2_RESET_VALUE = 0x0;

    static const uint8_t DIEPINT2_TXFE = 7;             // TXFE, Read-only
    static const uint8_t DIEPINT2_INEPNE = 6;           // INEPNE, Read-write
    static const uint8_t DIEPINT2_ITTXFE = 4;           // ITTXFE, Read-write
    static const uint8_t DIEPINT2_TOC = 3;              // TOC, Read-write
    static const uint8_t DIEPINT2_EPDISD = 1;           // EPDISD, Read-write
    static const uint8_t DIEPINT2_XFRC = 0;             // XFRC, Read-write
    static const uint32_t DIEPINT2_RESET_VALUE = 0x80;

    static const uint8_t DIEPTSIZ2_MCNT = 29;            // Multi count (2 bits)
    static const uint8_t DIEPTSIZ2_PKTCNT = 19;          // Packet count (10 bits)
    static const uint8_t DIEPTSIZ2_XFRSIZ = 0;           // Transfer size (19 bits)
    static const uint32_t DIEPTSIZ2_RESET_VALUE = 0x0;

    static const uint8_t DTXFSTS2_INEPTFSAV = 0;        // IN endpoint TxFIFO space available (16 bits)
    static const uint32_t DTXFSTS2_RESET_VALUE = 0x0;

    static const uint8_t DIEPCTL3_EPENA = 31;           // EPENA, Read-write
    static const uint8_t DIEPCTL3_EPDIS = 30;           // EPDIS, Read-write
    static const uint8_t DIEPCTL3_SODDFRM = 29;         // SODDFRM, Write-only
    static const uint8_t DIEPCTL3_SD0PID_SEVNFRM = 28;  // SD0PID/SEVNFRM, Write-only
    static const uint8_t DIEPCTL3_SNAK = 27;            // SNAK, Write-only
    static const uint8_t DIEPCTL3_CNAK = 26;            // CNAK, Write-only
    static const uint8_t DIEPCTL3_TXFNUM = 22;          // TXFNUM (4 bits), Read-write
    static const uint8_t DIEPCTL3_Stall = 21;           // Stall, Read-write
    static const uint8_t DIEPCTL3_EPTYP = 18;           // EPTYP (2 bits), Read-write
    static const uint8_t DIEPCTL3_NAKSTS = 17;          // NAKSTS, Read-only
    static const uint8_t DIEPCTL3_EONUM_DPID = 16;      // EONUM/DPID, Read-only
    static const uint8_t DIEPCTL3_USBAEP = 15;          // USBAEP, Read-write
    static const uint8_t DIEPCTL3_MPSIZ = 0;            // MPSIZ (11 bits), Read-write
    static const uint32_t DIEPCTL3_RESET_VALUE = 0x0;

    static const uint8_t DIEPINT3_TXFE = 7;             // TXFE, Read-only
    static const uint8_t DIEPINT3_INEPNE = 6;           // INEPNE, Read-write
    static const uint8_t DIEPINT3_ITTXFE = 4;           // ITTXFE, Read-write
    static const uint8_t DIEPINT3_TOC = 3;              // TOC, Read-write
    static const uint8_t DIEPINT3_EPDISD = 1;           // EPDISD, Read-write
    static const uint8_t DIEPINT3_XFRC = 0;             // XFRC, Read-write
    static const uint32_t DIEPINT3_RESET_VALUE = 0x80;

    static const uint8_t DIEPTSIZ3_MCNT = 29;            // Multi count (2 bits)
    static const uint8_t DIEPTSIZ3_PKTCNT = 19;          // Packet count (10 bits)
    static const uint8_t DIEPTSIZ3_XFRSIZ = 0;           // Transfer size (19 bits)
    static const uint32_t DIEPTSIZ3_RESET_VALUE = 0x0;

    static const uint8_t DTXFSTS3_INEPTFSAV = 0;        // IN endpoint TxFIFO space available (16 bits)
    static const uint32_t DTXFSTS3_RESET_VALUE = 0x0;

    static const uint8_t DOEPCTL0_EPENA = 31;           // EPENA, Write-only
    static const uint8_t DOEPCTL0_EPDIS = 30;           // EPDIS, Read-only
    static const uint8_t DOEPCTL0_SNAK = 27;            // SNAK, Write-only
    static const uint8_t DOEPCTL0_CNAK = 26;            // CNAK, Write-only
    static const uint8_t DOEPCTL0_Stall = 21;           // Stall, Read-write
    static const uint8_t DOEPCTL0_SNPM = 20;            // SNPM, Read-write
    static const uint8_t DOEPCTL0_EPTYP = 18;           // EPTYP (2 bits), Read-only
    static const uint8_t DOEPCTL0_NAKSTS = 17;          // NAKSTS, Read-only
    static const uint8_t DOEPCTL0_USBAEP = 15;          // USBAEP, Read-only
    static const uint8_t DOEPCTL0_MPSIZ = 0;            // MPSIZ (2 bits), Read-only
    static const uint32_t DOEPCTL0_RESET_VALUE = 0x8000;

    static const uint8_t DOEPINT0_B2BSTUP = 6;          // B2BSTUP
    static const uint8_t DOEPINT0_OTEPDIS = 4;          // OTEPDIS
    static const uint8_t DOEPINT0_STUP = 3;             // STUP
    static const uint8_t DOEPINT0_EPDISD = 1;           // EPDISD
    static const uint8_t DOEPINT0_XFRC = 0;             // XFRC
    static const uint32_t DOEPINT0_RESET_VALUE = 0x80;

    static const uint8_t DOEPTSIZ0_STUPCNT = 29;         // SETUP packet count (2 bits)
    static const uint8_t DOEPTSIZ0_PKTCNT = 19;          // Packet count
    static const uint8_t DOEPTSIZ0_XFRSIZ = 0;           // Transfer size (7 bits)
    static const uint32_t DOEPTSIZ0_RESET_VALUE = 0x0;

    static const uint8_t DOEPCTL1_EPENA = 31;           // EPENA, Read-write
    static const uint8_t DOEPCTL1_EPDIS = 30;           // EPDIS, Read-write
    static const uint8_t DOEPCTL1_SODDFRM = 29;         // SODDFRM, Write-only
    static const uint8_t DOEPCTL1_SD0PID_SEVNFRM = 28;  // SD0PID/SEVNFRM, Write-only
    static const uint8_t DOEPCTL1_SNAK = 27;            // SNAK, Write-only
    static const uint8_t DOEPCTL1_CNAK = 26;            // CNAK, Write-only
    static const uint8_t DOEPCTL1_Stall = 21;           // Stall, Read-write
    static const uint8_t DOEPCTL1_SNPM = 20;            // SNPM, Read-write
    static const uint8_t DOEPCTL1_EPTYP = 18;           // EPTYP (2 bits), Read-write
    static const uint8_t DOEPCTL1_NAKSTS = 17;          // NAKSTS, Read-only
    static const uint8_t DOEPCTL1_EONUM_DPID = 16;      // EONUM/DPID, Read-only
    static const uint8_t DOEPCTL1_USBAEP = 15;          // USBAEP, Read-write
    static const uint8_t DOEPCTL1_MPSIZ = 0;            // MPSIZ (11 bits), Read-write
    static const uint32_t DOEPCTL1_RESET_VALUE = 0x0;

    static const uint8_t DOEPINT1_B2BSTUP = 6;          // B2BSTUP
    static const uint8_t DOEPINT1_OTEPDIS = 4;          // OTEPDIS
    static const uint8_t DOEPINT1_STUP = 3;             // STUP
    static const uint8_t DOEPINT1_EPDISD = 1;           // EPDISD
    static const uint8_t DOEPINT1_XFRC = 0;             // XFRC
    static const uint32_t DOEPINT1_RESET_VALUE = 0x80;

    static const uint8_t DOEPTSIZ1_RXDPID_STUPCNT = 29;  // Received data PID/SETUP packet count (2 bits)
    static const uint8_t DOEPTSIZ1_PKTCNT = 19;          // Packet count (10 bits)
    static const uint8_t DOEPTSIZ1_XFRSIZ = 0;           // Transfer size (19 bits)
    static const uint32_t DOEPTSIZ1_RESET_VALUE = 0x0;

    static const uint8_t DOEPCTL2_EPENA = 31;           // EPENA, Read-write
    static const uint8_t DOEPCTL2_EPDIS = 30;           // EPDIS, Read-write
    static const uint8_t DOEPCTL2_SODDFRM = 29;         // SODDFRM, Write-only
    static const uint8_t DOEPCTL2_SD0PID_SEVNFRM = 28;  // SD0PID/SEVNFRM, Write-only
    static const uint8_t DOEPCTL2_SNAK = 27;            // SNAK, Write-only
    static const uint8_t DOEPCTL2_CNAK = 26;            // CNAK, Write-only
    static const uint8_t DOEPCTL2_Stall = 21;           // Stall, Read-write
    static const uint8_t DOEPCTL2_SNPM = 20;            // SNPM, Read-write
    static const uint8_t DOEPCTL2_EPTYP = 18;           // EPTYP (2 bits), Read-write
    static const uint8_t DOEPCTL2_NAKSTS = 17;          // NAKSTS, Read-only
    static const uint8_t DOEPCTL2_EONUM_DPID = 16;      // EONUM/DPID, Read-only
    static const uint8_t DOEPCTL2_USBAEP = 15;          // USBAEP, Read-write
    static const uint8_t DOEPCTL2_MPSIZ = 0;            // MPSIZ (11 bits), Read-write
    static const uint32_t DOEPCTL2_RESET_VALUE = 0x0;

    static const uint8_t DOEPINT2_B2BSTUP = 6;          // B2BSTUP
    static const uint8_t DOEPINT2_OTEPDIS = 4;          // OTEPDIS
    static const uint8_t DOEPINT2_STUP = 3;             // STUP
    static const uint8_t DOEPINT2_EPDISD = 1;           // EPDISD
    static const uint8_t DOEPINT2_XFRC = 0;             // XFRC
    static const uint32_t DOEPINT2_RESET_VALUE = 0x80;

    static const uint8_t DOEPTSIZ2_RXDPID_STUPCNT = 29;  // Received data PID/SETUP packet count (2 bits)
    static const uint8_t DOEPTSIZ2_PKTCNT = 19;          // Packet count (10 bits)
    static const uint8_t DOEPTSIZ2_XFRSIZ = 0;           // Transfer size (19 bits)
    static const uint32_t DOEPTSIZ2_RESET_VALUE = 0x0;

    static const uint8_t DOEPCTL3_EPENA = 31;           // EPENA, Read-write
    static const uint8_t DOEPCTL3_EPDIS = 30;           // EPDIS, Read-write
    static const uint8_t DOEPCTL3_SODDFRM = 29;         // SODDFRM, Write-only
    static const uint8_t DOEPCTL3_SD0PID_SEVNFRM = 28;  // SD0PID/SEVNFRM, Write-only
    static const uint8_t DOEPCTL3_SNAK = 27;            // SNAK, Write-only
    static const uint8_t DOEPCTL3_CNAK = 26;            // CNAK, Write-only
    static const uint8_t DOEPCTL3_Stall = 21;           // Stall, Read-write
    static const uint8_t DOEPCTL3_SNPM = 20;            // SNPM, Read-write
    static const uint8_t DOEPCTL3_EPTYP = 18;           // EPTYP (2 bits), Read-write
    static const uint8_t DOEPCTL3_NAKSTS = 17;          // NAKSTS, Read-only
    static const uint8_t DOEPCTL3_EONUM_DPID = 16;      // EONUM/DPID, Read-only
    static const uint8_t DOEPCTL3_USBAEP = 15;          // USBAEP, Read-write
    static const uint8_t DOEPCTL3_MPSIZ = 0;            // MPSIZ (11 bits), Read-write
    static const uint32_t DOEPCTL3_RESET_VALUE = 0x0;

    static const uint8_t DOEPINT3_B2BSTUP = 6;          // B2BSTUP
    static const uint8_t DOEPINT3_OTEPDIS = 4;          // OTEPDIS
    static const uint8_t DOEPINT3_STUP = 3;             // STUP
    static const uint8_t DOEPINT3_EPDISD = 1;           // EPDISD
    static const uint8_t DOEPINT3_XFRC = 0;             // XFRC
    static const uint32_t DOEPINT3_RESET_VALUE = 0x80;

    static const uint8_t DOEPTSIZ3_RXDPID_STUPCNT = 29;  // Received data PID/SETUP packet count (2 bits)
    static const uint8_t DOEPTSIZ3_PKTCNT = 19;          // Packet count (10 bits)
    static const uint8_t DOEPTSIZ3_XFRSIZ = 0;           // Transfer size (19 bits)
    static const uint32_t DOEPTSIZ3_RESET_VALUE = 0x0;
};

static otg_fs_device_t& OTG_FS_DEVICE = *reinterpret_cast<otg_fs_device_t*>(0x50000800);


////
//
//    USB on the go full speed
//
////

struct otg_fs_pwrclk_t
{
    volatile uint32_t    FS_PCGCCTL;           // [Read-write] OTG_FS power and clock gating control register (OTG_FS_PCGCCTL)

    static const uint8_t FS_PCGCCTL_STPPCLK = 0;          // Stop PHY clock
    static const uint8_t FS_PCGCCTL_GATEHCLK = 1;         // Gate HCLK
    static const uint8_t FS_PCGCCTL_PHYSUSP = 4;          // PHY Suspended
    static const uint32_t FS_PCGCCTL_RESET_VALUE = 0x0;
};

static otg_fs_pwrclk_t& OTG_FS_PWRCLK = *reinterpret_cast<otg_fs_pwrclk_t*>(0x50000e00);


////
//
//    QuadSPI interface
//
////

struct quadspi_t
{
    volatile uint32_t    CR;                   // [Read-write] control register
    volatile uint32_t    DCR;                  // [Read-write] device configuration register
    volatile uint32_t    SR;                   // [Read-only] status register
    volatile uint32_t    FCR;                  // [Read-write] flag clear register
    volatile uint32_t    DLR;                  // [Read-write] data length register
    volatile uint32_t    CCR;                  // [Read-write] communication configuration register
    volatile uint32_t    AR;                   // [Read-write] address register
    volatile uint32_t    ABR;                  // [Read-write] ABR
    volatile uint32_t    DR;                   // [Read-write] data register
    volatile uint32_t    PSMKR;                // [Read-write] polling status mask register
    volatile uint32_t    PSMAR;                // [Read-write] polling status match register
    volatile uint32_t    PIR;                  // [Read-write] polling interval register
    volatile uint32_t    LPTR;                 // [Read-write] low-power timeout register

    static const uint8_t CR_PRESCALER = 24;       // Clock prescaler (8 bits)
    static const uint8_t CR_PMM = 23;             // Polling match mode
    static const uint8_t CR_APMS = 22;            // Automatic poll mode stop
    static const uint8_t CR_TOIE = 20;            // TimeOut interrupt enable
    static const uint8_t CR_SMIE = 19;            // Status match interrupt enable
    static const uint8_t CR_FTIE = 18;            // FIFO threshold interrupt enable
    static const uint8_t CR_TCIE = 17;            // Transfer complete interrupt enable
    static const uint8_t CR_TEIE = 16;            // Transfer error interrupt enable
    static const uint8_t CR_FTHRES = 8;           // IFO threshold level (5 bits)
    static const uint8_t CR_FSEL = 7;             // FLASH memory selection
    static const uint8_t CR_DFM = 6;              // Dual-flash mode
    static const uint8_t CR_SSHIFT = 4;           // Sample shift
    static const uint8_t CR_TCEN = 3;             // Timeout counter enable
    static const uint8_t CR_DMAEN = 2;            // DMA enable
    static const uint8_t CR_ABORT = 1;            // Abort request
    static const uint8_t CR_EN = 0;               // Enable
    static const uint32_t CR_RESET_VALUE = 0x0;

    static const uint8_t DCR_FSIZE = 16;           // FLASH memory size (5 bits)
    static const uint8_t DCR_CSHT = 8;             // Chip select high time (3 bits)
    static const uint8_t DCR_CKMODE = 0;           // Mode 0 / mode 3
    static const uint32_t DCR_RESET_VALUE = 0x0;

    static const uint8_t SR_FLEVEL = 8;           // FIFO level (7 bits)
    static const uint8_t SR_BUSY = 5;             // Busy
    static const uint8_t SR_TOF = 4;              // Timeout flag
    static const uint8_t SR_SMF = 3;              // Status match flag
    static const uint8_t SR_FTF = 2;              // FIFO threshold flag
    static const uint8_t SR_TCF = 1;              // Transfer complete flag
    static const uint8_t SR_TEF = 0;              // Transfer error flag
    static const uint32_t SR_RESET_VALUE = 0x0;

    static const uint8_t FCR_CTOF = 4;             // Clear timeout flag
    static const uint8_t FCR_CSMF = 3;             // Clear status match flag
    static const uint8_t FCR_CTCF = 1;             // Clear transfer complete flag
    static const uint8_t FCR_CTEF = 0;             // Clear transfer error flag
    static const uint32_t FCR_RESET_VALUE = 0x0;

    static const uint8_t DLR_DL = 0;               // Data length (32 bits)
    static const uint32_t DLR_RESET_VALUE = 0x0;

    static const uint8_t CCR_DDRM = 31;            // Double data rate mode
    static const uint8_t CCR_DHHC = 30;            // DDR hold half cycle
    static const uint8_t CCR_SIOO = 28;            // Send instruction only once mode
    static const uint8_t CCR_FMODE = 26;           // Functional mode (2 bits)
    static const uint8_t CCR_DMODE = 24;           // Data mode (2 bits)
    static const uint8_t CCR_DCYC = 18;            // Number of dummy cycles (5 bits)
    static const uint8_t CCR_ABSIZE = 16;          // Alternate bytes size (2 bits)
    static const uint8_t CCR_ABMODE = 14;          // Alternate bytes mode (2 bits)
    static const uint8_t CCR_ADSIZE = 12;          // Address size (2 bits)
    static const uint8_t CCR_ADMODE = 10;          // Address mode (2 bits)
    static const uint8_t CCR_IMODE = 8;            // Instruction mode (2 bits)
    static const uint8_t CCR_INSTRUCTION = 0;      // Instruction (8 bits)
    static const uint32_t CCR_RESET_VALUE = 0x0;

    static const uint8_t AR_ADDRESS = 0;          // Address (32 bits)
    static const uint32_t AR_RESET_VALUE = 0x0;

    static const uint8_t ABR_ALTERNATE = 0;        // ALTERNATE (32 bits)
    static const uint32_t ABR_RESET_VALUE = 0x0;

    static const uint8_t DR_DATA = 0;             // Data (32 bits)
    static const uint32_t DR_RESET_VALUE = 0x0;

    static const uint8_t PSMKR_MASK = 0;             // Status mask (32 bits)
    static const uint32_t PSMKR_RESET_VALUE = 0x0;

    static const uint8_t PSMAR_MATCH = 0;            // Status match (32 bits)
    static const uint32_t PSMAR_RESET_VALUE = 0x0;

    static const uint8_t PIR_INTERVAL = 0;         // Polling interval (16 bits)
    static const uint32_t PIR_RESET_VALUE = 0x0;

    static const uint8_t LPTR_TIMEOUT = 0;          // Timeout period (16 bits)
    static const uint32_t LPTR_RESET_VALUE = 0x0;
};

static quadspi_t& QUADSPI = *reinterpret_cast<quadspi_t*>(0xa0001000);


////
//
//    Floting point unit
//
////

struct fpu_t
{
    volatile uint32_t    FPCCR;                // [Read-write] Floating-point context control register
    volatile uint32_t    FPCAR;                // [Read-write] Floating-point context address register
    volatile uint32_t    FPSCR;                // [Read-write] Floating-point status control register

    static const uint8_t FPCCR_LSPACT = 0;           // LSPACT
    static const uint8_t FPCCR_USER = 1;             // USER
    static const uint8_t FPCCR_THREAD = 3;           // THREAD
    static const uint8_t FPCCR_HFRDY = 4;            // HFRDY
    static const uint8_t FPCCR_MMRDY = 5;            // MMRDY
    static const uint8_t FPCCR_BFRDY = 6;            // BFRDY
    static const uint8_t FPCCR_MONRDY = 8;           // MONRDY
    static const uint8_t FPCCR_LSPEN = 30;           // LSPEN
    static const uint8_t FPCCR_ASPEN = 31;           // ASPEN
    static const uint32_t FPCCR_RESET_VALUE = 0x0;

    static const uint8_t FPCAR_ADDRESS = 3;          // Location of unpopulated floating-point (29 bits)
    static const uint32_t FPCAR_RESET_VALUE = 0x0;

    static const uint8_t FPSCR_IOC = 0;              // Invalid operation cumulative exception bit
    static const uint8_t FPSCR_DZC = 1;              // Division by zero cumulative exception bit.
    static const uint8_t FPSCR_OFC = 2;              // Overflow cumulative exception bit
    static const uint8_t FPSCR_UFC = 3;              // Underflow cumulative exception bit
    static const uint8_t FPSCR_IXC = 4;              // Inexact cumulative exception bit
    static const uint8_t FPSCR_IDC = 7;              // Input denormal cumulative exception bit.
    static const uint8_t FPSCR_RMode = 22;           // Rounding Mode control field (2 bits)
    static const uint8_t FPSCR_FZ = 24;              // Flush-to-zero mode control bit:
    static const uint8_t FPSCR_DN = 25;              // Default NaN mode control bit
    static const uint8_t FPSCR_AHP = 26;             // Alternative half-precision control bit
    static const uint8_t FPSCR_V = 28;               // Overflow condition code flag
    static const uint8_t FPSCR_C = 29;               // Carry condition code flag
    static const uint8_t FPSCR_Z = 30;               // Zero condition code flag
    static const uint8_t FPSCR_N = 31;               // Negative condition code flag
    static const uint32_t FPSCR_RESET_VALUE = 0x0;
};

static fpu_t& FPU = *reinterpret_cast<fpu_t*>(0xe000ef34);


////
//
//    Memory protection unit
//
////

struct mpu_t
{
    volatile uint32_t    MPU_TYPER;            // [Read-only] MPU type register
    volatile uint32_t    MPU_CTRL;             // [Read-only] MPU control register
    volatile uint32_t    MPU_RNR;              // [Read-write] MPU region number register
    volatile uint32_t    MPU_RBAR;             // [Read-write] MPU region base address register
    volatile uint32_t    MPU_RASR;             // [Read-write] MPU region attribute and size register

    static const uint8_t MPU_TYPER_SEPARATE = 0;         // Separate flag
    static const uint8_t MPU_TYPER_DREGION = 8;          // Number of MPU data regions (8 bits)
    static const uint8_t MPU_TYPER_IREGION = 16;         // Number of MPU instruction regions (8 bits)
    static const uint32_t MPU_TYPER_RESET_VALUE = 0x800;

    static const uint8_t MPU_CTRL_ENABLE = 0;           // Enables the MPU
    static const uint8_t MPU_CTRL_HFNMIENA = 1;         // Enables the operation of MPU during hard fault
    static const uint8_t MPU_CTRL_PRIVDEFENA = 2;       // Enable priviliged software access to default memory map
    static const uint32_t MPU_CTRL_RESET_VALUE = 0x0;

    static const uint8_t MPU_RNR_REGION = 0;           // MPU region (8 bits)
    static const uint32_t MPU_RNR_RESET_VALUE = 0x0;

    static const uint8_t MPU_RBAR_REGION = 0;           // MPU region field (4 bits)
    static const uint8_t MPU_RBAR_VALID = 4;            // MPU region number valid
    static const uint8_t MPU_RBAR_ADDR = 5;             // Region base address field (27 bits)
    static const uint32_t MPU_RBAR_RESET_VALUE = 0x0;

    static const uint8_t MPU_RASR_ENABLE = 0;           // Region enable bit.
    static const uint8_t MPU_RASR_SIZE = 1;             // Size of the MPU protection region (5 bits)
    static const uint8_t MPU_RASR_SRD = 8;              // Subregion disable bits (8 bits)
    static const uint8_t MPU_RASR_B = 16;               // memory attribute
    static const uint8_t MPU_RASR_C = 17;               // memory attribute
    static const uint8_t MPU_RASR_S = 18;               // Shareable memory attribute
    static const uint8_t MPU_RASR_TEX = 19;             // memory attribute (3 bits)
    static const uint8_t MPU_RASR_AP = 24;              // Access permission (3 bits)
    static const uint8_t MPU_RASR_XN = 28;              // Instruction access disable bit
    static const uint32_t MPU_RASR_RESET_VALUE = 0x0;
};

static mpu_t& MPU = *reinterpret_cast<mpu_t*>(0xe000ed90);


////
//
//    SysTick timer
//
////

struct stk_t
{
    volatile uint32_t    CTRL;                 // [Read-write] SysTick control and status register
    volatile uint32_t    LOAD;                 // [Read-write] SysTick reload value register
    volatile uint32_t    VAL;                  // [Read-write] SysTick current value register
    volatile uint32_t    CALIB;                // [Read-write] SysTick calibration value register

    static const uint8_t CTRL_ENABLE = 0;           // Counter enable
    static const uint8_t CTRL_TICKINT = 1;          // SysTick exception request enable
    static const uint8_t CTRL_CLKSOURCE = 2;        // Clock source selection
    static const uint8_t CTRL_COUNTFLAG = 16;       // COUNTFLAG
    static const uint32_t CTRL_RESET_VALUE = 0x0;

    static const uint8_t LOAD_RELOAD = 0;           // RELOAD value (24 bits)
    static const uint32_t LOAD_RESET_VALUE = 0x0;

    static const uint8_t VAL_CURRENT = 0;          // Current counter value (24 bits)
    static const uint32_t VAL_RESET_VALUE = 0x0;

    static const uint8_t CALIB_TENMS = 0;            // Calibration value (24 bits)
    static const uint8_t CALIB_SKEW = 30;            // SKEW flag: Indicates whether the TENMS value is exact
    static const uint8_t CALIB_NOREF = 31;           // NOREF flag. Reads as zero
    static const uint32_t CALIB_RESET_VALUE = 0x0;
};

static stk_t& STK = *reinterpret_cast<stk_t*>(0xe000e010);


////
//
//    System control block
//
////

struct scb_t
{
    volatile uint32_t    CPUID;                // [Read-only] CPUID base register
    volatile uint32_t    ICSR;                 // [Read-write] Interrupt control and state register
    volatile uint32_t    VTOR;                 // [Read-write] Vector table offset register
    volatile uint32_t    AIRCR;                // [Read-write] Application interrupt and reset control register
    volatile uint32_t    SCR;                  // [Read-write] System control register
    volatile uint32_t    CCR;                  // [Read-write] Configuration and control register
    volatile uint32_t    SHPR1;                // [Read-write] System handler priority registers
    volatile uint32_t    SHPR2;                // [Read-write] System handler priority registers
    volatile uint32_t    SHPR3;                // [Read-write] System handler priority registers
    volatile uint32_t    SHCRS;                // [Read-write] System handler control and state register
    volatile uint32_t    CFSR_UFSR_BFSR_MMFSR; // [Read-write] Configurable fault status register
    volatile uint32_t    HFSR;                 // [Read-write] Hard fault status register
    reserved_t<1>        _0;
    volatile uint32_t    MMFAR;                // [Read-write] Memory management fault address register
    volatile uint32_t    BFAR;                 // [Read-write] Bus fault address register
    volatile uint32_t    AFSR;                 // [Read-write] Auxiliary fault status register

    static const uint8_t CPUID_Revision = 0;         // Revision number (4 bits)
    static const uint8_t CPUID_PartNo = 4;           // Part number of the processor (12 bits)
    static const uint8_t CPUID_Constant = 16;        // Reads as 0xF (4 bits)
    static const uint8_t CPUID_Variant = 20;         // Variant number (4 bits)
    static const uint8_t CPUID_Implementer = 24;     // Implementer code (8 bits)
    static const uint32_t CPUID_RESET_VALUE = 0x410fc241;

    static const uint8_t ICSR_VECTACTIVE = 0;       // Active vector (9 bits)
    static const uint8_t ICSR_RETTOBASE = 11;       // Return to base level
    static const uint8_t ICSR_VECTPENDING = 12;     // Pending vector (7 bits)
    static const uint8_t ICSR_ISRPENDING = 22;      // Interrupt pending flag
    static const uint8_t ICSR_PENDSTCLR = 25;       // SysTick exception clear-pending bit
    static const uint8_t ICSR_PENDSTSET = 26;       // SysTick exception set-pending bit
    static const uint8_t ICSR_PENDSVCLR = 27;       // PendSV clear-pending bit
    static const uint8_t ICSR_PENDSVSET = 28;       // PendSV set-pending bit
    static const uint8_t ICSR_NMIPENDSET = 31;      // NMI set-pending bit.
    static const uint32_t ICSR_RESET_VALUE = 0x0;

    static const uint8_t VTOR_TBLOFF = 9;           // Vector table base offset field (21 bits)
    static const uint32_t VTOR_RESET_VALUE = 0x0;

    static const uint8_t AIRCR_VECTRESET = 0;        // VECTRESET
    static const uint8_t AIRCR_VECTCLRACTIVE = 1;    // VECTCLRACTIVE
    static const uint8_t AIRCR_SYSRESETREQ = 2;      // SYSRESETREQ
    static const uint8_t AIRCR_PRIGROUP = 8;         // PRIGROUP (3 bits)
    static const uint8_t AIRCR_ENDIANESS = 15;       // ENDIANESS
    static const uint8_t AIRCR_VECTKEYSTAT = 16;     // Register key (16 bits)
    static const uint32_t AIRCR_RESET_VALUE = 0x0;

    static const uint8_t SCR_SLEEPONEXIT = 1;      // SLEEPONEXIT
    static const uint8_t SCR_SLEEPDEEP = 2;        // SLEEPDEEP
    static const uint8_t SCR_SEVEONPEND = 4;       // Send Event on Pending bit
    static const uint32_t SCR_RESET_VALUE = 0x0;

    static const uint8_t CCR_NONBASETHRDENA = 0;   // Configures how the processor enters Thread mode
    static const uint8_t CCR_USERSETMPEND = 1;     // USERSETMPEND
    static const uint8_t CCR_UNALIGN__TRP = 3;     // UNALIGN_ TRP
    static const uint8_t CCR_DIV_0_TRP = 4;        // DIV_0_TRP
    static const uint8_t CCR_BFHFNMIGN = 8;        // BFHFNMIGN
    static const uint8_t CCR_STKALIGN = 9;         // STKALIGN
    static const uint32_t CCR_RESET_VALUE = 0x0;

    static const uint8_t SHPR1_PRI_4 = 0;            // Priority of system handler 4 (8 bits)
    static const uint8_t SHPR1_PRI_5 = 8;            // Priority of system handler 5 (8 bits)
    static const uint8_t SHPR1_PRI_6 = 16;           // Priority of system handler 6 (8 bits)
    static const uint32_t SHPR1_RESET_VALUE = 0x0;

    static const uint8_t SHPR2_PRI_11 = 24;          // Priority of system handler 11 (8 bits)
    static const uint32_t SHPR2_RESET_VALUE = 0x0;

    static const uint8_t SHPR3_PRI_14 = 16;          // Priority of system handler 14 (8 bits)
    static const uint8_t SHPR3_PRI_15 = 24;          // Priority of system handler 15 (8 bits)
    static const uint32_t SHPR3_RESET_VALUE = 0x0;

    static const uint8_t SHCRS_MEMFAULTACT = 0;      // Memory management fault exception active bit
    static const uint8_t SHCRS_BUSFAULTACT = 1;      // Bus fault exception active bit
    static const uint8_t SHCRS_USGFAULTACT = 3;      // Usage fault exception active bit
    static const uint8_t SHCRS_SVCALLACT = 7;        // SVC call active bit
    static const uint8_t SHCRS_MONITORACT = 8;       // Debug monitor active bit
    static const uint8_t SHCRS_PENDSVACT = 10;       // PendSV exception active bit
    static const uint8_t SHCRS_SYSTICKACT = 11;      // SysTick exception active bit
    static const uint8_t SHCRS_USGFAULTPENDED = 12;  // Usage fault exception pending bit
    static const uint8_t SHCRS_MEMFAULTPENDED = 13;  // Memory management fault exception pending bit
    static const uint8_t SHCRS_BUSFAULTPENDED = 14;  // Bus fault exception pending bit
    static const uint8_t SHCRS_SVCALLPENDED = 15;    // SVC call pending bit
    static const uint8_t SHCRS_MEMFAULTENA = 16;     // Memory management fault enable bit
    static const uint8_t SHCRS_BUSFAULTENA = 17;     // Bus fault enable bit
    static const uint8_t SHCRS_USGFAULTENA = 18;     // Usage fault enable bit
    static const uint32_t SHCRS_RESET_VALUE = 0x0;

    static const uint8_t CFSR_UFSR_BFSR_MMFSR_IACCVIOL = 1;         // Instruction access violation flag
    static const uint8_t CFSR_UFSR_BFSR_MMFSR_MUNSTKERR = 3;        // Memory manager fault on unstacking for a return from exception
    static const uint8_t CFSR_UFSR_BFSR_MMFSR_MSTKERR = 4;          // Memory manager fault on stacking for exception entry.
    static const uint8_t CFSR_UFSR_BFSR_MMFSR_MLSPERR = 5;          // MLSPERR
    static const uint8_t CFSR_UFSR_BFSR_MMFSR_MMARVALID = 7;        // Memory Management Fault Address Register (MMAR) valid flag
    static const uint8_t CFSR_UFSR_BFSR_MMFSR_IBUSERR = 8;          // Instruction bus error
    static const uint8_t CFSR_UFSR_BFSR_MMFSR_PRECISERR = 9;        // Precise data bus error
    static const uint8_t CFSR_UFSR_BFSR_MMFSR_IMPRECISERR = 10;     // Imprecise data bus error
    static const uint8_t CFSR_UFSR_BFSR_MMFSR_UNSTKERR = 11;        // Bus fault on unstacking for a return from exception
    static const uint8_t CFSR_UFSR_BFSR_MMFSR_STKERR = 12;          // Bus fault on stacking for exception entry
    static const uint8_t CFSR_UFSR_BFSR_MMFSR_LSPERR = 13;          // Bus fault on floating-point lazy state preservation
    static const uint8_t CFSR_UFSR_BFSR_MMFSR_BFARVALID = 15;       // Bus Fault Address Register (BFAR) valid flag
    static const uint8_t CFSR_UFSR_BFSR_MMFSR_UNDEFINSTR = 16;      // Undefined instruction usage fault
    static const uint8_t CFSR_UFSR_BFSR_MMFSR_INVSTATE = 17;        // Invalid state usage fault
    static const uint8_t CFSR_UFSR_BFSR_MMFSR_INVPC = 18;           // Invalid PC load usage fault
    static const uint8_t CFSR_UFSR_BFSR_MMFSR_NOCP = 19;            // No coprocessor usage fault.
    static const uint8_t CFSR_UFSR_BFSR_MMFSR_UNALIGNED = 24;       // Unaligned access usage fault
    static const uint8_t CFSR_UFSR_BFSR_MMFSR_DIVBYZERO = 25;       // Divide by zero usage fault
    static const uint32_t CFSR_UFSR_BFSR_MMFSR_RESET_VALUE = 0x0;

    static const uint8_t HFSR_VECTTBL = 1;          // Vector table hard fault
    static const uint8_t HFSR_FORCED = 30;          // Forced hard fault
    static const uint8_t HFSR_DEBUG_VT = 31;        // Reserved for Debug use
    static const uint32_t HFSR_RESET_VALUE = 0x0;

    static const uint8_t MMFAR_MMFAR = 0;            // Memory management fault address (32 bits)
    static const uint32_t MMFAR_RESET_VALUE = 0x0;

    static const uint8_t BFAR_BFAR = 0;             // Bus fault address (32 bits)
    static const uint32_t BFAR_RESET_VALUE = 0x0;

    static const uint8_t AFSR_IMPDEF = 0;           // Implementation defined (32 bits)
    static const uint32_t AFSR_RESET_VALUE = 0x0;
};

static scb_t& SCB = *reinterpret_cast<scb_t*>(0xe000ed00);


////
//
//    Nested vectored interrupt controller
//
////

struct nvic_stir_t
{
    volatile uint32_t    STIR;                 // [Read-write] Software trigger interrupt register

    static const uint8_t STIR_INTID = 0;            // Software generated interrupt ID (9 bits)
    static const uint32_t STIR_RESET_VALUE = 0x0;
};

static nvic_stir_t& NVIC_STIR = *reinterpret_cast<nvic_stir_t*>(0xe000ef00);


////
//
//    Floating point unit CPACR
//
////

struct fpu_cpacr_t
{
    volatile uint32_t    CPACR;                // [Read-write] Coprocessor access control register

    static const uint8_t CPACR_CP = 20;              // CP (4 bits)
    static const uint32_t CPACR_RESET_VALUE = 0x0;
};

static fpu_cpacr_t& FPU_CPACR = *reinterpret_cast<fpu_cpacr_t*>(0xe000ed88);


////
//
//    System control block ACTLR
//
////

struct scb_actrl_t
{
    volatile uint32_t    ACTRL;                // [Read-write] Auxiliary control register

    static const uint8_t ACTRL_DISMCYCINT = 0;       // DISMCYCINT
    static const uint8_t ACTRL_DISDEFWBUF = 1;       // DISDEFWBUF
    static const uint8_t ACTRL_DISFOLD = 2;          // DISFOLD
    static const uint8_t ACTRL_DISFPCA = 8;          // DISFPCA
    static const uint8_t ACTRL_DISOOFP = 9;          // DISOOFP
    static const uint32_t ACTRL_RESET_VALUE = 0x0;
};

static scb_actrl_t& SCB_ACTRL = *reinterpret_cast<scb_actrl_t*>(0xe000e008);


}


