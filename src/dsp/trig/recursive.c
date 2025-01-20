

#include "recursive.h"

void recurs_sine_wave_f32_init(recurs_sine_wave_f32_t * wave, float freq, float initial_phase, float amplitude){
    wave->freq = freq;
    wave->initial_phase = initial_phase;
    wave->amplitude = amplitude;    
};

void recurs_sine_wave_f64_init(recurs_sine_wave_f64_t * wave, float freq, float initial_phase, float amplitude){
    wave->freq = freq;
    wave->initial_phase = initial_phase;
    wave->amplitude = amplitude;    
};

FASTEXEC
void recurs_sine_wave_f32_reset(recurs_sine_wave_f32_t * wave, float sample_freq){
    wave->sin = sinf(wave->initial_phase);
    wave->cos = cosf(wave->initial_phase);
    if (sample_freq){       
        wave->phase_step = 2 * M_PI * wave->freq / sample_freq;
        wave->sin_delta = sinf(wave->phase_step);
        wave->cos_delta = cosf(wave->phase_step);
    }
};

FASTEXEC
void recurs_sine_wave_f64_reset(recurs_sine_wave_f64_t * wave, float sample_freq){
    wave->sin = sin(wave->initial_phase);
    wave->cos = cos(wave->initial_phase);
    if (sample_freq){       
        wave->phase_step = 2 * M_PI_L * wave->freq / sample_freq;
        wave->sin_delta = sin(wave->phase_step);
        wave->cos_delta = cos(wave->phase_step);
    }
};

#pragma GCC push_options 
#pragma GCC optimize("O3")

FASTEXEC
void recurs_sine_wave_f32_propagate(recurs_sine_wave_f32_t * wave){
    f64_t new_sin, new_cos;
    new_sin = (wave->sin * wave->cos_delta) + (wave->cos * wave->sin_delta);
    new_cos = (wave->cos * wave->cos_delta) - (wave->sin * wave->sin_delta);
    wave->sin = new_sin;
    wave->cos = new_cos;
};

FASTEXEC
void recurs_sine_wave_f64_propagate(recurs_sine_wave_f64_t * wave){
    f64_t new_sin, new_cos;
    new_sin = (wave->sin * wave->cos_delta) + (wave->cos * wave->sin_delta);
    new_cos = (wave->cos * wave->cos_delta) - (wave->sin * wave->sin_delta);
    wave->sin = new_sin;
    wave->cos = new_cos;
};

#pragma GCC pop_options
