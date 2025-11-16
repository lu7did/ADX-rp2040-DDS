/**
 * ADX-rp2040-DDS - ADX class FT8 transceiver with direct digital synthesis
 * 
 * Main application file
 * 
 * Copyright (c) 2025 Dr. Pedro E. Colla (LU7DZ)
 * Licensed under MIT License
 */

#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/clocks.h"
#include "config.h"
#include "dds.h"
#include "usb_audio.h"
#include "adx_transceiver.h"
#include "ft8_protocol.h"

// LED pin for status indication
#define LED_PIN PIN_STATUS_LED

int main() {
    // Initialize stdio for USB debugging
    stdio_init_all();
    
    // Initialize LED
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);
    
    printf("ADX-rp2040-DDS Digital Transceiver Starting...\n");
    printf("System Clock: %lu Hz\n", clock_get_hz(clk_sys));
    
    // Initialize DDS for direct digital synthesis
    if (!dds_init()) {
        printf("ERROR: DDS initialization failed\n");
        return -1;
    }
    printf("DDS initialized successfully\n");
    
    // Initialize USB audio device
    if (!usb_audio_init()) {
        printf("ERROR: USB audio initialization failed\n");
        return -1;
    }
    printf("USB audio initialized successfully\n");
    
    // Initialize ADX transceiver
    if (!adx_transceiver_init()) {
        printf("ERROR: ADX transceiver initialization failed\n");
        return -1;
    }
    printf("ADX transceiver initialized successfully\n");
    
    // Initialize FT8 protocol support
    if (!ft8_protocol_init()) {
        printf("ERROR: FT8 protocol initialization failed\n");
        return -1;
    }
    printf("FT8 protocol initialized successfully\n");
    
    printf("ADX-rp2040-DDS is now running (experimental)\n");
    
    // Main loop
    while (true) {
        // Blink LED to show we're alive
        gpio_put(LED_PIN, 1);
        sleep_ms(100);
        gpio_put(LED_PIN, 0);
        sleep_ms(900);
        
        // Process transceiver tasks
        adx_transceiver_task();
        
        // Process USB audio tasks
        usb_audio_task();
        
        // Process FT8 protocol tasks
        ft8_protocol_task();
    }
    
    return 0;
}
