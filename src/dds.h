/**
 * DDS (Direct Digital Synthesis) module
 * 
 * Provides direct digital synthesis using RP2040 PIO for signal generation
 * Replaces traditional Si5351 clock generator
 */

#ifndef DDS_H
#define DDS_H

#include <stdint.h>
#include <stdbool.h>

// DDS configuration
#define DDS_SAMPLE_RATE     48000
#define DDS_BUFFER_SIZE     256
#define DDS_MAX_FREQUENCY   30000000  // 30 MHz

// Initialize DDS system
bool dds_init(void);

// Set output frequency in Hz
void dds_set_frequency(uint32_t frequency);

// Get current frequency
uint32_t dds_get_frequency(void);

// Enable/disable DDS output
void dds_enable(bool enable);

// Check if DDS is running
bool dds_is_enabled(void);

#endif // DDS_H
