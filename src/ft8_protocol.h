/**
 * FT8 Protocol module
 * 
 * Implements FT8 digital mode protocol support
 * FT8 is a weak signal digital mode for amateur radio
 */

#ifndef FT8_PROTOCOL_H
#define FT8_PROTOCOL_H

#include <stdint.h>
#include <stdbool.h>

// FT8 configuration
#define FT8_SYMBOL_RATE     6.25        // Symbols per second
#define FT8_TONE_SPACING    6.25        // Hz between tones
#define FT8_MESSAGE_LENGTH  79          // Symbols per message
#define FT8_TRANSMIT_TIME   12800       // ms (12.8 seconds)

// FT8 message structure
typedef struct {
    char callsign[13];
    char grid[7];
    int8_t snr;
    bool valid;
} ft8_message_t;

// Initialize FT8 protocol
bool ft8_protocol_init(void);

// Process FT8 tasks
void ft8_protocol_task(void);

// Decode FT8 message from audio buffer
bool ft8_decode(int16_t* audio_buffer, uint32_t length, ft8_message_t* message);

// Encode FT8 message to audio buffer
bool ft8_encode(const char* callsign, const char* grid, int8_t snr, int16_t* audio_buffer);

// Check if currently transmitting
bool ft8_is_transmitting(void);

// Start FT8 transmission
void ft8_start_transmission(const char* callsign, const char* grid, int8_t snr);

#endif // FT8_PROTOCOL_H
