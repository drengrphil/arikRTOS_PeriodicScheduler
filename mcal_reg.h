#ifndef __MCAL_REG_H
#define __MCAL_REG_H

#include "reg_access.h"
// #include <cstdint>

using namespace std;

namespace mcal{
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
	}
}

// Typecast systick_base address
#define SysTick ((mcal::reg::SysTick_Type*) mcal::reg::systick_base)
// System Handler to set systick priority - using system handler priority register 3
#define SYSPRI3 (*reinterpret_cast<volatile uint32_t *>(0xE000ED20))
// Interrupt control and sate register (pg. 4-13 CortexM4)
#define INTCTRL (*reinterpret_cast<volatile uint32_t *>(0xE000ED04))



#endif
