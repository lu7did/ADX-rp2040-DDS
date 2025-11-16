# ADX-rp2040-DDS
ADX class FT8 transceiver with direct digital synthesis

## Overview

This is a derivative of the well-known ADX digital transceiver but based on the **RP2040 processor**. It features:

- ✨ **Direct Digital Synthesis** - Uses the RP2040 processor directly for signal generation (no Si5351 clock generator required)
- 🎵 **Digital USB Sound Card** - Implements a digital sound card through the USB interface (no analog audio involved)
- 📡 **FT8 Protocol Support** - Supports FT8 weak signal digital mode for amateur radio
- 🔧 **Highly Experimental** - This is an experimental implementation for development and testing

## Features

### Hardware
- Based on Raspberry Pi RP2040 microcontroller
- Direct digital synthesis using RP2040 PIO and PWM
- USB audio device interface
- Multi-band support (80m, 40m, 30m, 20m, 17m, 15m, 10m)

### Software
- FT8 protocol implementation
- ADX transceiver logic
- Digital signal processing
- USB CDC for debugging

## Architecture

```
┌─────────────────────────────────────────────┐
│           ADX-rp2040-DDS                    │
├─────────────────────────────────────────────┤
│  Main Controller                            │
│  ├── DDS (Direct Digital Synthesis)         │
│  │   └── RP2040 PIO/PWM Signal Generation   │
│  ├── USB Audio Device                       │
│  │   └── TinyUSB Digital Sound Card         │
│  ├── ADX Transceiver                        │
│  │   ├── TX/RX Switching                    │
│  │   └── Multi-band Support                 │
│  └── FT8 Protocol                           │
│      └── Digital Mode Processing            │
└─────────────────────────────────────────────┘
```

## Getting Started

### Prerequisites

- Raspberry Pi Pico SDK
- CMake 3.13 or higher
- ARM GCC toolchain
- Raspberry Pi Pico or compatible RP2040 board

### Building

See [BUILD.md](BUILD.md) for detailed build instructions.

Quick build:
```bash
export PICO_SDK_PATH=/path/to/pico-sdk
mkdir build && cd build
cmake ..
make -j4
```

### Flashing

1. Hold BOOTSEL button while connecting Pico to USB
2. Copy `adx_rp2040_dds.uf2` to the mounted drive
3. Pico will reboot automatically

## Hardware Connections

### GPIO Pin Assignments

| Pin | Function |
|-----|----------|
| GPIO 0 | DDS Output |
| GPIO 16 | TX Control |
| GPIO 17 | RX Control |
| GPIO 25 | Status LED |
| USB | Audio + Debug |

## Usage

1. Connect the RP2040 board to your computer via USB
2. The device will appear as a USB audio device
3. Use FT8 software (e.g., WSJT-X) with the USB audio device
4. Monitor debug output via USB serial (115200 baud)

## Project Status

⚠️ **EXPERIMENTAL** - This project is in early development stage and highly experimental. Features are being actively developed and tested.

### Implemented
- [x] Basic project structure
- [x] CMake build system
- [x] DDS signal generation framework
- [x] USB audio device framework
- [x] ADX transceiver structure
- [x] FT8 protocol skeleton

### In Progress
- [ ] Complete DDS implementation
- [ ] Full USB audio device
- [ ] FT8 encoding/decoding
- [ ] Hardware integration testing
- [ ] Performance optimization

## Contributing

This is an experimental project. Contributions, suggestions, and feedback are welcome!

## License

Copyright (c) 2025 Dr. Pedro E. Colla (LU7DZ)

Licensed under the MIT License. See [LICENSE](LICENSE) for details.

## Acknowledgments

- Based on the original ADX transceiver design
- Uses Raspberry Pi Pico SDK
- TinyUSB for USB device support
- FT8 protocol specifications

## Contact

- Author: Dr. Pedro E. Colla (LU7DID)
- Callsign: LU7DID

## Disclaimer

This is experimental amateur radio equipment. Use at your own risk. Ensure compliance with local amateur radio regulations.
