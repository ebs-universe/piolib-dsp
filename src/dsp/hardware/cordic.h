
#ifndef DSP_HW_CORDIC_H
#define DSP_HW_CORDIC_H

#include "../config.h"

#if DSP_ENABLE_HARDWARE_CORDIC

#define OFS_CORDIC_CFGR     0x00
#define OFS_CORDIC_WDATA    0x04
#define OFS_CORDIC_RDATA    0x08

void cordic_init(void);
static inline void cordic_sincos(q31_t phase, q31_t m, q31_t * sin_res, q31_t * cos_res);

FASTEXEC
static inline void cordic_sincos(q31_t phase, q31_t m, q31_t * sin_res, q31_t * cos_res){
    HAL_SFR_t * csr = (HAL_SFR_t *)(CORDIC_BASE + OFS_CORDIC_CFGR);
    HAL_SFR_t * wdata = (HAL_SFR_t *)(CORDIC_BASE + OFS_CORDIC_WDATA);
    HAL_SFR_t * rdata = (HAL_SFR_t *)(CORDIC_BASE + OFS_CORDIC_RDATA);
    
    *wdata = phase;
    *wdata = m;

    while(!(*csr & CORDIC_CSR_RRDY)){
        ;
    }

    *sin_res = *rdata;
    *cos_res = *rdata;
}

#endif
#endif