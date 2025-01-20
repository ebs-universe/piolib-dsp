

#ifndef DSP_TRIG_CORDIC_H
#define DSP_TRIG_CORDIC_H

#include "../config.h"

typedef struct CORDIC_SINE_WAVE_F32_t{
    f32_t sin;
    f32_t cos;
    q31_t phase;
    q31_t phase_step;
    q31_t m;
    int32_t gain;
    f32_t freq;             
    f32_t initial_phase;
    f32_t amplitude;
} cordic_sine_wave_f32_t;

typedef struct CORDIC_SINE_WAVE_F64_t{
    f64_t sin;
    f64_t cos;
    q31_t phase;
    q31_t phase_step;
    q31_t m;
    int32_t gain;
    f32_t freq;             
    f32_t initial_phase;
    f32_t amplitude;
} cordic_sine_wave_f64_t;

void cordic_sine_wave_f32_init(cordic_sine_wave_f32_t * wave, float freq, float initial_phase, float amplitude);
void cordic_sine_wave_f32_reset(cordic_sine_wave_f32_t * wave, f32_t sample_freq);
void cordic_sine_wave_f32_propagate(cordic_sine_wave_f32_t * wave);

void cordic_sine_wave_f64_init(cordic_sine_wave_f64_t * wave, float freq, float initial_phase, float amplitude);
void cordic_sine_wave_f64_reset(cordic_sine_wave_f64_t * wave, f32_t sample_freq);
void cordic_sine_wave_f64_propagate(cordic_sine_wave_f64_t * wave);

#endif