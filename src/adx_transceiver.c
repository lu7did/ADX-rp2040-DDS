/**
 * ADX Transceiver implementation
 * 
 * Core ADX transceiver functionality for RP2040
 */

#include "adx_transceiver.h"
#include "dds.h"
#include "pico/stdlib.h"
#include <stdio.h>

// Band frequency table (in Hz)
static const uint32_t band_frequencies[ADX_BAND_COUNT] = {
    3573000,   // 80m
    7074000,   // 40m
    10136000,  // 30m
    14074000,  // 20m
    18100000,  // 17m
    21074000,  // 15m
    28074000   // 10m
};

// Transceiver state
static struct {
    adx_mode_t mode;
    adx_band_t band;
    uint8_t power;
    bool initialized;
} adx_state = {0};

// TX/RX control pins
#include "config.h"
#define TX_PIN PIN_TX_CONTROL
#define RX_PIN PIN_RX_CONTROL

bool adx_transceiver_init(void) {
    // Initialize TX/RX control pins
    gpio_init(TX_PIN);
    gpio_set_dir(TX_PIN, GPIO_OUT);
    gpio_put(TX_PIN, 0);
    
    gpio_init(RX_PIN);
    gpio_set_dir(RX_PIN, GPIO_OUT);
    gpio_put(RX_PIN, 1);  // Start in RX mode
    
    // Set initial state
    adx_state.mode = ADX_MODE_RX;
    adx_state.band = ADX_BAND_40M;  // Default to 40m (FT8)
    adx_state.power = 50;  // 50% power
    adx_state.initialized = true;
    
    // Set initial frequency
    dds_set_frequency(band_frequencies[adx_state.band]);
    
    printf("ADX Transceiver: Mode=%s, Band=%dm, Power=%d%%\n",
           adx_state.mode == ADX_MODE_RX ? "RX" : "TX",
           adx_state.band == ADX_BAND_40M ? 40 : 20,
           adx_state.power);
    
    return true;
}

void adx_transceiver_task(void) {
    if (!adx_state.initialized) {
        return;
    }
    
    // Process transceiver state machine
    // This is where we would handle PTT, AGC, etc.
}

void adx_set_mode(adx_mode_t mode) {
    adx_state.mode = mode;
    
    if (mode == ADX_MODE_TX) {
        gpio_put(TX_PIN, 1);
        gpio_put(RX_PIN, 0);
        dds_enable(true);
    } else {
        gpio_put(TX_PIN, 0);
        gpio_put(RX_PIN, 1);
        dds_enable(false);
    }
}

adx_mode_t adx_get_mode(void) {
    return adx_state.mode;
}

void adx_set_band(adx_band_t band) {
    if (band >= ADX_BAND_COUNT) {
        return;
    }
    
    adx_state.band = band;
    dds_set_frequency(band_frequencies[band]);
}

adx_band_t adx_get_band(void) {
    return adx_state.band;
}

void adx_set_power(uint8_t power) {
    if (power > 100) {
        power = 100;
    }
    adx_state.power = power;
}

uint8_t adx_get_power(void) {
    return adx_state.power;
}
