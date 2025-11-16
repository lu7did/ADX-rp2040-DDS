/**
 * USB Audio Device implementation
 * 
 * Provides digital sound card functionality via USB
 * Uses TinyUSB for USB audio device class implementation
 */

#include "usb_audio.h"
#include "pico/stdlib.h"
#include "tusb.h"
#include <string.h>

// Audio buffers
static int16_t audio_input_buffer[AUDIO_BUFFER_SIZE * AUDIO_CHANNELS];
static int16_t audio_output_buffer[AUDIO_BUFFER_SIZE * AUDIO_CHANNELS];

// USB audio state
static struct {
    bool initialized;
    bool ready;
} usb_audio_state = {0};

bool usb_audio_init(void) {
    // Initialize TinyUSB
    tusb_init();
    
    // Clear audio buffers
    memset(audio_input_buffer, 0, sizeof(audio_input_buffer));
    memset(audio_output_buffer, 0, sizeof(audio_output_buffer));
    
    usb_audio_state.initialized = true;
    usb_audio_state.ready = false;
    
    return true;
}

void usb_audio_task(void) {
    if (!usb_audio_state.initialized) {
        return;
    }
    
    // Process TinyUSB tasks
    tud_task();
    
    // Check if device is mounted
    usb_audio_state.ready = tud_mounted();
}

int16_t* usb_audio_get_input_buffer(void) {
    return audio_input_buffer;
}

int16_t* usb_audio_get_output_buffer(void) {
    return audio_output_buffer;
}

bool usb_audio_is_ready(void) {
    return usb_audio_state.ready;
}
