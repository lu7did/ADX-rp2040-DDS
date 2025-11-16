/**
 * ADX Transceiver module
 * 
 * Implements ADX class transceiver functionality
 * Handles TX/RX switching and signal processing
 */

#ifndef ADX_TRANSCEIVER_H
#define ADX_TRANSCEIVER_H

#include <stdint.h>
#include <stdbool.h>

// Transceiver modes
typedef enum {
    ADX_MODE_RX,
    ADX_MODE_TX
} adx_mode_t;

// Transceiver bands (in meters)
typedef enum {
    ADX_BAND_80M = 0,
    ADX_BAND_40M,
    ADX_BAND_30M,
    ADX_BAND_20M,
    ADX_BAND_17M,
    ADX_BAND_15M,
    ADX_BAND_10M,
    ADX_BAND_COUNT
} adx_band_t;

// Initialize ADX transceiver
bool adx_transceiver_init(void);

// Process transceiver tasks
void adx_transceiver_task(void);

// Set transceiver mode
void adx_set_mode(adx_mode_t mode);

// Get current mode
adx_mode_t adx_get_mode(void);

// Set active band
void adx_set_band(adx_band_t band);

// Get current band
adx_band_t adx_get_band(void);

// Set transmit power (0-100%)
void adx_set_power(uint8_t power);

// Get current power level
uint8_t adx_get_power(void);

#endif // ADX_TRANSCEIVER_H
