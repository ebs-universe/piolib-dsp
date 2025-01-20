
#ifndef DSP_FILTER_LPF_H
#define DPS_FILTER_LPF_H

#include "../config.h"

typedef struct LPF_IIR_F32_t{
    f32_t value;
    f32_t alpha;
    f32_t cutoff;
} lpf_iir_f32_t;

typedef struct LPF_IIR_F64_t{
    f64_t value;
    f64_t alpha;
    f32_t cutoff;
} lpf_iir_f64_t;

void lpf_iir_f32_init(lpf_iir_f32_t * lpf, f32_t cutoff, f32_t sample_freq);
void lpf_iir_f64_init(lpf_iir_f64_t * lpf, f32_t cutoff, f32_t sample_freq);
void lpf_iir_f32_reset(lpf_iir_f32_t * lpf);
void lpf_iir_f64_reset(lpf_iir_f64_t * lpf);
static inline void lpf_iir_f32_propagate(lpf_iir_f32_t * lpf, f32_t value);
static inline void lpf_iir_f64_propagate(lpf_iir_f64_t * lpf, f64_t value);

FASTEXEC                
static inline void lpf_iir_f32_propagate(lpf_iir_f32_t * lpf, f32_t value){
    lpf->value = lpf->value + lpf->alpha * (value - lpf->value);
};          

FASTEXEC                
static inline void lpf_iir_f64_propagate(lpf_iir_f64_t * lpf, f64_t value){
    lpf->value = lpf->value + lpf->alpha * (value - lpf->value);
};          

#endif
