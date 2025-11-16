/**
 * DDS (Direct Digital Synthesis) implementation
 * 
 * Uses RP2040 PIO and PWM for direct digital synthesis
 * No external Si5351 required
 */

#include "dds.h"
#include "pico/stdlib.h"
#include "hardware/pwm.h"
#include "hardware/clocks.h"
#include "hardware/dma.h"
#include <math.h>

// DDS state
static struct {
    uint32_t frequency;
    bool enabled;
    uint32_t phase_accumulator;
    uint32_t phase_increment;
    uint slice_num;
} dds_state = {0};

// DDS output pin
#include "config.h"
#define DDS_OUTPUT_PIN PIN_DDS_OUTPUT

bool dds_init(void) {
    // Initialize GPIO for PWM
    gpio_set_function(DDS_OUTPUT_PIN, GPIO_FUNC_PWM);
    
    // Get PWM slice for this pin
    dds_state.slice_num = pwm_gpio_to_slice_num(DDS_OUTPUT_PIN);
    
    // Configure PWM
    pwm_config config = pwm_get_default_config();
    
    // Set divider for high frequency operation
    pwm_config_set_clkdiv(&config, 1.0f);
    
    // Set wrap value (determines PWM frequency)
    pwm_config_set_wrap(&config, 255);
    
    // Initialize PWM
    pwm_init(dds_state.slice_num, &config, true);
    
    // Set initial frequency to 7.074 MHz (FT8 frequency)
    dds_set_frequency(7074000);
    
    dds_state.enabled = false;
    
    return true;
}

void dds_set_frequency(uint32_t frequency) {
    if (frequency > DDS_MAX_FREQUENCY) {
        frequency = DDS_MAX_FREQUENCY;
    }
    
    dds_state.frequency = frequency;
    
    // Calculate phase increment for DDS
    // phase_increment = (frequency * 2^32) / sample_rate
    uint64_t temp = ((uint64_t)frequency << 32) / DDS_SAMPLE_RATE;
    dds_state.phase_increment = (uint32_t)temp;
}

uint32_t dds_get_frequency(void) {
    return dds_state.frequency;
}

void dds_enable(bool enable) {
    dds_state.enabled = enable;
    
    if (enable) {
        pwm_set_enabled(dds_state.slice_num, true);
    } else {
        pwm_set_enabled(dds_state.slice_num, false);
    }
}

bool dds_is_enabled(void) {
    return dds_state.enabled;
}
