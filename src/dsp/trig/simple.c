

#include "simple.h"

void simple_sine_wave_f32_init(simple_sine_wave_f32_t * wave, float freq, float initial_phase, float amplitude){
    wave->freq = freq;
    wave->initial_phase = initial_phase;
    wave->amplitude = amplitude;    
};

void simple_sine_wave_f64_init(simple_sine_wave_f64_t * wave, float freq, float initial_phase, float amplitude){
    wave->freq = freq;
    wave->initial_phase = initial_phase;
    wave->amplitude = amplitude;    
};

FASTEXEC
void simple_sine_wave_f32_reset(simple_sine_wave_f32_t * wave, float sample_freq){
    if (sample_freq){
        wave->phase_step = 2 * M_PI * wave->freq / sample_freq;
    }
    wave->phase = wave->initial_phase;
    wave->value = wave->amplitude * sinf(wave->initial_phase);
};

FASTEXEC
void simple_sine_wave_f64_reset(simple_sine_wave_f64_t * wave, float sample_freq){
    if (sample_freq){
        wave->phase_step = 2 * M_PI * wave->freq / sample_freq;
    }
    wave->phase = wave->initial_phase;
    wave->value = wave->amplitude * sin(wave->initial_phase);
};

#pragma GCC push_options 
#pragma GCC optimize("O3")

FASTEXEC
void simple_sine_wave_f32_propagate(simple_sine_wave_f32_t * wave){
    wave->phase += wave->phase_step;
    if (wave->phase > M_PI) {
        wave->phase -= 2 * M_PI;
    }
    wave->value = wave->amplitude * sinf(wave->phase);
};

FASTEXEC
void simple_sine_wave_f64_propagate(simple_sine_wave_f64_t * wave){
    wave->phase += wave->phase_step;
    if (wave->phase > M_PI) {
        wave->phase -= 2 * M_PI;
    }
    wave->value = wave->amplitude * sin(wave->phase);
};

#pragma GCC pop_options
