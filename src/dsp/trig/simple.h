
#ifndef DSP_TRIG_SIMPLE_H
#define DSP_TRIG_SIMPLE_H

#include "../config.h"

typedef struct SIMPLE_SINE_WAVE_F32_t{
    f32_t value;
    f32_t phase;
    f32_t phase_step;
    f32_t amplitude;
    f32_t freq;
    f32_t initial_phase;
} simple_sine_wave_f32_t;    

typedef struct SIMPLE_SINE_WAVE_F64_t{
    f64_t value;
    f64_t phase;
    f64_t phase_step;
    f32_t amplitude;
    f32_t freq;
    f32_t initial_phase;
} simple_sine_wave_f64_t;    

void simple_sine_wave_f32_init(simple_sine_wave_f32_t * wave, float freq, float initial_phase, float amplitude);
void simple_sine_wave_f32_reset(simple_sine_wave_f32_t * wave, float sample_freq);
void simple_sine_wave_f32_propagate(simple_sine_wave_f32_t * wave);

void simple_sine_wave_f64_init(simple_sine_wave_f64_t * wave, float freq, float initial_phase, float amplitude);
void simple_sine_wave_f64_reset(simple_sine_wave_f64_t * wave, float sample_freq);
void simple_sine_wave_f64_propagate(simple_sine_wave_f64_t * wave);

#endif