

#include "cordic.h"

#if DSP_ENABLE_HARDWARE_CORDIC

void cordic_init(void){
    __HAL_RCC_CORDIC_CLK_ENABLE();

    HAL_SFR_t * csr = (HAL_SFR_t *)(CORDIC_BASE + OFS_CORDIC_CFGR);
    volatile HAL_BASE_t csrval = 0;

    csrval |= CORDIC_CSR_NARGS; // We don't actually want this?
    csrval |= CORDIC_CSR_NRES;
    csrval |= (6 << CORDIC_CSR_PRECISION_Pos);
    csrval |= CORDIC_CSR_FUNC_0;    
    
    *csr = csrval;
}

#endif