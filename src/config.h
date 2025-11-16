/**
 * ADX-rp2040-DDS Configuration
 * 
 * Hardware and software configuration parameters
 */

#ifndef CONFIG_H
#define CONFIG_H

// Hardware version
#define HW_VERSION_MAJOR 1
#define HW_VERSION_MINOR 0

// Software version
#define SW_VERSION_MAJOR 0
#define SW_VERSION_MINOR 1
#define SW_VERSION_PATCH 0

// GPIO Pin assignments
#define PIN_DDS_OUTPUT      0
#define PIN_TX_CONTROL      16
#define PIN_RX_CONTROL      17
#define PIN_STATUS_LED      25

// DDS Configuration
#define DDS_CLOCK_FREQ      125000000   // 125 MHz system clock
#define DDS_MIN_FREQ        1000000     // 1 MHz
#define DDS_MAX_FREQ        30000000    // 30 MHz
#define DDS_DEFAULT_FREQ    7074000     // 7.074 MHz (40m FT8)

// Audio Configuration
#define AUDIO_SAMPLE_RATE   48000       // 48 kHz
#define AUDIO_BIT_DEPTH     16          // 16-bit
#define AUDIO_CHANNELS      2           // Stereo

// Transceiver Configuration
#define TX_POWER_MIN        0
#define TX_POWER_MAX        100
#define TX_POWER_DEFAULT    50

// FT8 Configuration
#define FT8_SLOT_DURATION   15000       // 15 seconds per slot
#define FT8_TX_DURATION     12800       // 12.8 seconds transmission
#define FT8_DEFAULT_BAND    ADX_BAND_40M

// Debug Configuration
#define DEBUG_ENABLE        1
#define DEBUG_USB_CDC       1

#endif // CONFIG_H
