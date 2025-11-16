# API Documentation

## DDS Module

### Functions

#### `bool dds_init(void)`
Initialize the Direct Digital Synthesis system.

**Returns:** `true` on success, `false` on failure

#### `void dds_set_frequency(uint32_t frequency)`
Set the DDS output frequency.

**Parameters:**
- `frequency`: Frequency in Hz (1 MHz to 30 MHz)

#### `uint32_t dds_get_frequency(void)`
Get the current DDS frequency.

**Returns:** Current frequency in Hz

#### `void dds_enable(bool enable)`
Enable or disable DDS output.

**Parameters:**
- `enable`: `true` to enable, `false` to disable

#### `bool dds_is_enabled(void)`
Check if DDS is currently enabled.

**Returns:** `true` if enabled, `false` otherwise

## USB Audio Module

### Functions

#### `bool usb_audio_init(void)`
Initialize the USB audio device.

**Returns:** `true` on success, `false` on failure

#### `void usb_audio_task(void)`
Process USB audio tasks. Must be called regularly in main loop.

#### `int16_t* usb_audio_get_input_buffer(void)`
Get pointer to audio input buffer.

**Returns:** Pointer to input buffer (512 samples × 2 channels)

#### `int16_t* usb_audio_get_output_buffer(void)`
Get pointer to audio output buffer.

**Returns:** Pointer to output buffer (512 samples × 2 channels)

#### `bool usb_audio_is_ready(void)`
Check if USB audio device is ready.

**Returns:** `true` if device is mounted and ready

## ADX Transceiver Module

### Types

#### `adx_mode_t`
Transceiver operating mode.
- `ADX_MODE_RX` - Receive mode
- `ADX_MODE_TX` - Transmit mode

#### `adx_band_t`
Amateur radio bands.
- `ADX_BAND_80M` - 80 meters
- `ADX_BAND_40M` - 40 meters
- `ADX_BAND_30M` - 30 meters
- `ADX_BAND_20M` - 20 meters
- `ADX_BAND_17M` - 17 meters
- `ADX_BAND_15M` - 15 meters
- `ADX_BAND_10M` - 10 meters

### Functions

#### `bool adx_transceiver_init(void)`
Initialize the ADX transceiver.

**Returns:** `true` on success, `false` on failure

#### `void adx_transceiver_task(void)`
Process transceiver tasks. Must be called regularly in main loop.

#### `void adx_set_mode(adx_mode_t mode)`
Set transceiver operating mode.

**Parameters:**
- `mode`: Operating mode (RX or TX)

#### `adx_mode_t adx_get_mode(void)`
Get current operating mode.

**Returns:** Current mode

#### `void adx_set_band(adx_band_t band)`
Set active amateur radio band.

**Parameters:**
- `band`: Band selection

#### `adx_band_t adx_get_band(void)`
Get current band.

**Returns:** Current band

#### `void adx_set_power(uint8_t power)`
Set transmit power level.

**Parameters:**
- `power`: Power level (0-100%)

#### `uint8_t adx_get_power(void)`
Get current power level.

**Returns:** Power level (0-100%)

## FT8 Protocol Module

### Types

#### `ft8_message_t`
FT8 message structure.

```c
typedef struct {
    char callsign[13];  // Station callsign
    char grid[7];       // Grid locator
    int8_t snr;         // Signal-to-noise ratio
    bool valid;         // Message validity flag
} ft8_message_t;
```

### Functions

#### `bool ft8_protocol_init(void)`
Initialize FT8 protocol support.

**Returns:** `true` on success, `false` on failure

#### `void ft8_protocol_task(void)`
Process FT8 protocol tasks. Must be called regularly in main loop.

#### `bool ft8_decode(int16_t* audio_buffer, uint32_t length, ft8_message_t* message)`
Decode FT8 message from audio buffer.

**Parameters:**
- `audio_buffer`: Input audio samples
- `length`: Buffer length
- `message`: Output message structure

**Returns:** `true` if message decoded successfully

#### `bool ft8_encode(const char* callsign, const char* grid, int8_t snr, int16_t* audio_buffer)`
Encode FT8 message to audio buffer.

**Parameters:**
- `callsign`: Station callsign
- `grid`: Grid locator
- `snr`: Signal-to-noise ratio
- `audio_buffer`: Output audio buffer

**Returns:** `true` on success

#### `bool ft8_is_transmitting(void)`
Check if currently transmitting FT8 message.

**Returns:** `true` if transmitting

#### `void ft8_start_transmission(const char* callsign, const char* grid, int8_t snr)`
Start FT8 transmission.

**Parameters:**
- `callsign`: Station callsign
- `grid`: Grid locator  
- `snr`: Signal-to-noise ratio

## Configuration

See `src/config.h` for hardware and software configuration parameters.

## Example Usage

```c
#include "dds.h"
#include "usb_audio.h"
#include "adx_transceiver.h"
#include "ft8_protocol.h"

int main() {
    // Initialize all systems
    dds_init();
    usb_audio_init();
    adx_transceiver_init();
    ft8_protocol_init();
    
    // Set frequency to 40m FT8
    adx_set_band(ADX_BAND_40M);
    
    // Main loop
    while (true) {
        adx_transceiver_task();
        usb_audio_task();
        ft8_protocol_task();
    }
}
```
