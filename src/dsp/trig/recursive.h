
#ifndef DSP_TRIG_RECURSIVE_H
#define DSP_TRIG_RECURSIVE_H

#include "../config.h"

typedef struct RECURS_SINE_WAVE_F32_t{
    f32_t sin;
    f32_t cos;
    f32_t cos_delta;
    f32_t sin_delta;
    f32_t phase_step;
    f32_t freq;
    f32_t initial_phase;
    f32_t amplitude;
} recurs_sine_wave_f32_t;

typedef struct RECURS_SINE_WAVE_F64_t{
    f64_t sin;
    f64_t cos;
    f64_t cos_delta;
    f64_t sin_delta;
    f64_t phase_step;
    f32_t freq;
    f32_t initial_phase;
    f32_t amplitude;
} recurs_sine_wave_f64_t;

void recurs_sine_wave_f32_init(recurs_sine_wave_f32_t * wave, float freq, float initial_phase, float amplitude);
void recurs_sine_wave_f32_reset(recurs_sine_wave_f32_t * wave, float sample_freq);
void recurs_sine_wave_f32_propagate(recurs_sine_wave_f32_t * wave);

void recurs_sine_wave_f64_init(recurs_sine_wave_f64_t * wave, float freq, float initial_phase, float amplitude);
void recurs_sine_wave_f64_reset(recurs_sine_wave_f64_t * wave, float sample_freq);
void recurs_sine_wave_f64_propagate(recurs_sine_wave_f64_t * wave);

#endif