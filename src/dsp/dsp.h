#ifndef DSP_H
#define DSP_H

#include "config.h"

#if DSP_ENABLE_HARDWARE_CORDIC
#include "hardware/cordic.h"
#endif

#include "trig/simple.h"
#include "trig/recursive.h"
#include "trig/cordic.h"

#include "filter/iir.h"

#endif