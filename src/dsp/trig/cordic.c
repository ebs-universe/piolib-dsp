

#include "cordic.h"

#if DSP_ENABLE_HARDWARE_CORDIC
    #include <dsp/hardware/cordic.h>
#else
    static inline void cordic_sincos(q31_t phase, q31_t m, q31_t * sin_res, q31_t * cos_res){
        die();
    }
#endif

void cordic_sine_wave_f32_init(cordic_sine_wave_f32_t * wave, float freq, float initial_phase, float amplitude){
    wave->freq = freq;
    wave->initial_phase = initial_phase;
    wave->amplitude = amplitude;    
}

void cordic_sine_wave_f64_init(cordic_sine_wave_f64_t * wave, float freq, float initial_phase, float amplitude){
    wave->freq = freq;
    wave->initial_phase = initial_phase;
    wave->amplitude = amplitude;    
}

FASTEXEC
void cordic_sine_wave_f32_reset(cordic_sine_wave_f32_t * wave, f32_t sample_freq){
    if (sample_freq) {
        wave->phase_step = f32_to_q31(2 * (wave->freq / sample_freq));
    }
    
    f32_t phase = (wave->initial_phase / M_PI);
    while (phase > 1) {
        phase -= 2;
    }
    while (phase < -1) {
        phase += 2;
    }

    wave->phase = f32_to_q31(phase);
      
    // Determine the gain and modulus (m)
    // Start with the smallest possible gain
    wave->gain = 1;
    f32_t m_float = wave->amplitude / wave->gain;

    // Increment gain until m_float is within the range [0, 0.5)
    while (m_float >= 0.5f) {
        wave->gain++;
        m_float = wave->amplitude / wave->gain;
    }

    wave->m = f32_to_q31(m_float);

    f32_t initial_phase_radians = q31_to_f32(wave->phase) * M_PI;
    wave->sin = wave->amplitude * sinf(initial_phase_radians);
    wave->cos = wave->amplitude * cosf(initial_phase_radians);
};

FASTEXEC
void cordic_sine_wave_f64_reset(cordic_sine_wave_f64_t * wave, f32_t sample_freq){
    if (sample_freq) {
        wave->phase_step = f32_to_q31(2 * (wave->freq / sample_freq));
    }
    
    f32_t phase = (wave->initial_phase / M_PI);
    while (phase > 1) {
        phase -= 2;
    }
    while (phase < -1) {
        phase += 2;
    }

    wave->phase = f32_to_q31(phase);
      
    // Determine the gain and modulus (m)
    // Start with the smallest possible gain
    wave->gain = 1;
    f32_t m_float = wave->amplitude / wave->gain;

    // Increment gain until m_float is within the range [0, 0.5)
    while (m_float >= 0.5f) {
        wave->gain++;
        m_float = wave->amplitude / wave->gain;
    }

    wave->m = f32_to_q31(m_float);

    f32_t initial_phase_radians = q31_to_f32(wave->phase) * M_PI;
    wave->sin = wave->amplitude * sin(initial_phase_radians);
    wave->cos = wave->amplitude * cos(initial_phase_radians);
};

#pragma GCC push_options 
#pragma GCC optimize("O3")

FASTEXEC
void cordic_sine_wave_f32_propagate(cordic_sine_wave_f32_t * wave){
    q31_t s, c;
    wave->phase += wave->phase_step;
    cordic_sincos(wave->phase, wave->m, &s, &c);
    wave->sin = q31_to_f32(s) * wave->gain;
    wave->cos = q31_to_f32(c) * wave->gain;
};  

FASTEXEC
void cordic_sine_wave_f64_propagate(cordic_sine_wave_f64_t * wave){
    q31_t s, c;
    wave->phase += wave->phase_step;
    cordic_sincos(wave->phase, wave->m, &s, &c);
    wave->sin = q31_to_f64(s) * wave->gain;
    wave->cos = q31_to_f64(c) * wave->gain;
};  

#pragma GCC pop_options

