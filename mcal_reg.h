#ifndef __MCAL_REG_H
#define __MCAL_REG_H

#include "reg_access.h"
// #include <cstdint>

using namespace std;

namespace mcal{
    namespace params {
        // This means bit28 of iser0 must be set to 1
        const uint32_t tim2_rq_enable = 0x10000000;
    }
    
	namespace reg{
		const uint32_t scs_base       = 0xE000E000UL;   // System control space
		const uint32_t systick_offset = 0x0010UL;
		const uint32_t systick_base   = scs_base + systick_offset;
        
        const uint32_t periph_base = 0x40000000U;
        const uint32_t ahb1_periph_base = periph_base + 0x00020000U;
        const uint32_t rcc_base = ahb1_periph_base + 0x3800U;
        
        const uint32_t ahb1enr = rcc_base + 0x30;
        const uint32_t ahb2enr = rcc_base + 0x34;
        const uint32_t ahb3enr = rcc_base + 0x38;
        
        // APB1 Enable register needed to enable the timer.
        // Timer is connected to the APB1 BUS
        const uint32_t apb1enr = rcc_base + 0x40;
        
        // Timer 2 based address
        const uint32_t tim2_base_addr = periph_base;
        
        // Ref.: CortexM4 Generic user guide pg. 219
        /* iser0 enables interrupt for IRQ#0 - IRQ31 */
        const uint32_t iser0 = 0xE000E100UL;
        /* iser1 enables interrupt for IRQ#32 - IRQ#64 */
        const uint32_t iser1 = 0xE000E104UL;
        /* iser2 enables interrupt for IRQ#65 - IRQ#96 */
        const uint32_t iser2 = 0xE000E108UL;

		const uint32_t systick_ctrl_offset  = 0x000;  // SysTick Control and Status Register
		const uint32_t systick_load_offset  = 0x004;  // SysTick Reload Value Register
		const uint32_t systick_val_offset   = 0x008;   // SysTick Current Value Register
		const uint32_t systick_calib_offset = 0x00c; // SysTick Calibration Register

		// SysTick registers
		const uint32_t systick_ctrl  = systick_base  + systick_ctrl_offset;
		const uint32_t systick_load  = systick_base  + systick_load_offset;
		const uint32_t systick_val   = systick_base  + systick_val_offset;
		const uint32_t systick_calib = systick_base  + systick_calib_offset;

		typedef struct
		{
			volatile uint32_t CTRL;  // 0x000
			volatile uint32_t LOAD;  // 0x004
			volatile uint32_t VAL;   // 0x008
			volatile uint32_t CALIB; // 0x00c
		} SysTick_Type;
        
        // GPIO Registers
        const uint32_t gpioa = ahb1_periph_base + 0x0000U;
        const uint32_t gpiob = ahb1_periph_base + 0x0400U;
        const uint32_t gpioc = ahb1_periph_base + 0x0800U;
        const uint32_t gpiod = ahb1_periph_base + 0x0C00U;
        const uint32_t gpioe = ahb1_periph_base + 0x1000U;
        
        const uint32_t moder_offset = 0x00;
        const uint32_t idr_offset   = 0x10;
        const uint32_t odr_offset   = 0x14;
        const uint32_t bsrr_offset  = 0x18;
        
        // GPIOA
        const uint32_t gpioa_moder = gpioa + moder_offset;
        const uint32_t gpioa_idr = gpioa + idr_offset;
        const uint32_t gpioa_odr = gpioa + odr_offset;
        const uint32_t gpioa_bsrr = gpioa + bsrr_offset;
        
        // GPIOB
        const uint32_t gpiob_moder = gpiob + moder_offset;
        const uint32_t gpiob_idr = gpiob + idr_offset;
        const uint32_t gpiob_odr = gpiob + odr_offset;
        const uint32_t gpiob_bsrr = gpiob + bsrr_offset;
        
        // GPIOC
        const uint32_t gpioc_moder = gpioc + moder_offset;
        const uint32_t gpioc_idr = gpioc + idr_offset;
        const uint32_t gpioc_odr = gpioc + odr_offset;
        const uint32_t gpioc_bsrr = gpioc + bsrr_offset;
        
        // TIM Registers
        // Timer 2 has registers like other General Purpose timers.
        // Such as auto-reload, count, 4 control, and prescaler registers.
        const uint32_t tim_psc_offset = 0x28;
        const uint32_t tim_arr_offset = 0x2C;
        const uint32_t tim_cnt_offset = 0x24;
        
        const uint32_t tim_cr1_offset = 0x00;
        const uint32_t tim_cr2_offset = 0x04;
        const uint32_t tim_cr3_offset = 0x3C;
        const uint32_t tim_cr4_offset = 0x40;
        
        const uint32_t tim_smcr_offset = 0x08;
        const uint32_t tim_dier_offset = 0x0C;
        
        const uint32_t tim_sr_offset = 0x10;
        const uint32_t tim_egr_offset = 0x14;
        
        const uint32_t tim_ccmr1_offset = 0x18;
        
        const uint32_t tim_ccmr2_offset = 0x1C;
        const uint32_t tim_ccer_offset = 0x20;
        
        // Timer 2 registers
        const uint32_t tim2_smcr = tim_smcr_offset + tim2_base_addr;
        const uint32_t tim2_dier = tim_dier_offset + tim2_base_addr;
        
        const uint32_t tim2_sr = tim_sr_offset + tim2_base_addr;
        const uint32_t tim2_egr = tim_egr_offset + tim2_base_addr;
        
        const uint32_t tim2_ccmr1 = tim_ccmr1_offset + tim2_base_addr;
        const uint32_t tim2_ccmr2 = tim_ccmr2_offset + tim2_base_addr;
        const uint32_t tim2_ccer = tim_ccer_offset + tim2_base_addr;
        
        const uint32_t tim2_psc = tim_psc_offset + tim2_base_addr;
        const uint32_t tim2_arr = tim_arr_offset + tim2_base_addr;
        const uint32_t tim2_cnt = tim_cnt_offset + tim2_base_addr;
        
        const uint32_t tim2_cr1 = tim_cr1_offset + tim2_base_addr;
        const uint32_t tim2_cr2 = tim_cr2_offset + tim2_base_addr;
        const uint32_t tim2_cr3 = tim_cr3_offset + tim2_base_addr;
        const uint32_t tim2_cr4 = tim_cr4_offset + tim2_base_addr;
        
        // Timer type registers
        typedef struct
        {
            volatile uint32_t CR1;              /*!< TIM control register 1,             Address: */
            volatile uint32_t CR2;              /*!< TIM control register 2,             Address: */
            volatile uint32_t SMCR;             /*!< TIM slave mode control register,    Address: */
            volatile uint32_t DIER;             /*!< TIM DMA/interrupt enable register,  Address: */
            volatile uint32_t SR;               /*!< TIM status register,                Address: */
            volatile uint32_t EGR;              /*!< TIM event generation register,      Address: */
            volatile uint32_t CCMR1;            /*!< TIM capture/compare mode register 1,    Address: */
            volatile uint32_t CCMR2;            /*!< TIM capture/compare mode register 2,    Address: */
            volatile uint32_t CCER;             /*!< TIM capture/compare enable register,    Address: */
            volatile uint32_t CNT;              /*!< TIM counter register,    Address: */
            volatile uint32_t PSC;              /*!< TIM prescaler,    Address: */
            volatile uint32_t ARR;              /*!< TIM autoreload register,    Address: */
            volatile uint32_t RCR;              /*!< TIM repitition counter register,    Address: */
            volatile uint32_t CCR1;             /*!< TIM capture/compare register 1,     Address: */
            volatile uint32_t CCR2;             /*!< TIM capture/compare register 2,     Address: */
            volatile uint32_t CCR3;             /*!< TIM capture/compare register 3,     Address: */
            volatile uint32_t CCR4;             /*!< TIM capture/compare register 4,     Address: */
            volatile uint32_t BDTR;             /*!< TIM break and dead-time register,   Address: */
            volatile uint32_t DCR;              /*!< TIM DMA control register,           Address: */
            volatile uint32_t DMAR;             /*!< TIM DMA address for full transfer,  Address: */
            volatile uint32_t OR;               /*!< TIM option register,                Address: */
        } TIM_TypeDef;
	}
}

// Typecast systick_base address
#define SysTick     ((mcal::reg::SysTick_Type*) mcal::reg::systick_base)
// System Handler to set systick priority - using system handler priority register 3
#define SYSPRI3     (*reinterpret_cast<volatile uint32_t *>(0xE000ED20))
// Interrupt control and sate register (pg. 4-13 CortexM4)
#define INTCTRL     (*reinterpret_cast<volatile uint32_t *>(0xE000ED04))
#define TIM2        ((mcal::reg::TIM_TypeDef*)mcal::reg::tim2_base_addr)



#endif
