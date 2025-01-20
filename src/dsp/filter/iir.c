

#include "iir.h"

FASTEXEC
void lpf_iir_f32_init(lpf_iir_f32_t * lpf, float cutoff, float sample_freq){
    if (!sample_freq || !cutoff){
        die();
    }
    lpf->cutoff = cutoff;
    f32_t RC = 1.0f / (2 * M_PI * cutoff);
    f32_t period = 1 / sample_freq;
    lpf->alpha = period / (RC + period);
    lpf->value = 0;             
}

FASTEXEC
void lpf_iir_f64_init(lpf_iir_f64_t * lpf, float cutoff, float sample_freq){
    if (!sample_freq || !cutoff){
        die();
    }
    lpf->cutoff = cutoff;
    f64_t RC = 1.0 / (2 * M_PI * cutoff);
    f64_t period = 1 / sample_freq;
    lpf->alpha = period / (RC + period);
    lpf->value = 0;
}

void lpf_iir_f32_reset(lpf_iir_f32_t * lpf){
    lpf->value = 0;
}

void lpf_iir_f64_reset(lpf_iir_f64_t * lpf){
    lpf->value = 0;
}
