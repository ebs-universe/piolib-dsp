

#ifndef DSP_TYPES_H
#define DSP_TYPES_H

#include <stdint.h>

// extracts from CMSIS DSP v1.10.0 arm_math.h 
// (gh latest)

typedef float f32_t;
typedef double f64_t;
typedef uint8_t q7_t;
typedef int16_t q15_t;
typedef int32_t q31_t;
typedef int64_t q63_t;

#define F64_MAX     ((f64_t)DBL_MAX)
#define F64_MIN     (-DBL_MAX)
#define F64_ABSMAX  ((f64_t)DBL_MAX)
#define F64_ABSMIN  ((f64_t)0.0)

#define F32_MAX     ((f32_t)FLT_MAX)
#define F32_MIN     (-FLT_MAX)
#define F32_ABSMAX  ((f32_t)FLT_MAX)
#define F32_ABSMIN  ((f32_t)0.0)

#define Q31_MAX     ((q31_t)(0x7FFFFFFFL))
#define Q31_MIN     ((q31_t)(0x80000000L))
#define Q31_ABSMAX  ((q31_t)(0x7FFFFFFFL))
#define Q31_ABSMIN  ((q31_t)0)

#define Q15_MAX     ((q15_t)(0x7FFF))
#define Q15_MIN     ((q15_t)(0x8000))
#define Q15_ABSMAX  ((q15_t)(0x7FFF))
#define Q15_ABSMIN  ((q15_t)0)

#define Q7_MAX      ((q7_t)(0x7F))
#define Q7_MIN      ((q7_t)(0x80))
#define Q7_ABSMAX   ((q7_t)(0x7F))
#define Q7_ABSMIN   ((q7_t)0)

static inline q31_t clip_q63_to_q31(q63_t x) {
    return ((q31_t) (x >> 32) != ((q31_t) x >> 31)) ?
      ((0x7FFFFFFF ^ ((q31_t) (x >> 63)))) : (q31_t) x;
}

static inline q15_t clip_q63_to_q15(q63_t x) {
    return ((q31_t) (x >> 32) != ((q31_t) x >> 31)) ?
      ((0x7FFF ^ ((q15_t) (x >> 63)))) : (q15_t) (x >> 15);
}

static inline q7_t clip_q31_to_q7(q31_t x) {
    return ((q31_t) (x >> 24) != ((q31_t) x >> 23)) ?
      ((0x7F ^ ((q7_t) (x >> 31)))) : (q7_t) x;
}

static inline q15_t clip_q31_to_q15(q31_t x) {
    return ((q31_t) (x >> 16) != ((q31_t) x >> 15)) ?
      ((0x7FFF ^ ((q15_t) (x >> 31)))) : (q15_t) x;
}

static inline q31_t f32_to_q31(f32_t x) {
    return clip_q63_to_q31((q63_t) (x * 2147483648.0f));
}

static inline f32_t q31_to_f32(q31_t x) {
    return (f32_t) x / 2147483648.0f;
}

static inline q31_t f64_to_q31(f64_t x) {
    return clip_q63_to_q31((q63_t) (x * 2147483648.0));
}

static inline f64_t q31_to_f64(q31_t x) {
    return (f64_t) x / 2147483648.0;
}

#endif