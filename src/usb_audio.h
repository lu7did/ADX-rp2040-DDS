/**
 * USB Audio Device module
 * 
 * Implements digital sound card functionality through USB interface
 * No analog audio involved - fully digital audio processing
 */

#ifndef USB_AUDIO_H
#define USB_AUDIO_H

#include <stdint.h>
#include <stdbool.h>

// Audio configuration
#define AUDIO_SAMPLE_RATE   48000
#define AUDIO_BUFFER_SIZE   512
#define AUDIO_CHANNELS      2

// Initialize USB audio device
bool usb_audio_init(void);

// Process audio tasks (must be called regularly)
void usb_audio_task(void);

// Get audio input buffer
int16_t* usb_audio_get_input_buffer(void);

// Get audio output buffer
int16_t* usb_audio_get_output_buffer(void);

// Check if audio device is ready
bool usb_audio_is_ready(void);

#endif // USB_AUDIO_H
