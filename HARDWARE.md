# Hardware Design

## Overview

The ADX-rp2040-DDS is designed around the Raspberry Pi RP2040 microcontroller, eliminating the need for external clock generators like the Si5351.

## Block Diagram

```
                 ┌──────────────────┐
                 │   RP2040 MCU     │
                 │                  │
  USB ◄──────────┤ USB              │
                 │                  │
                 │ PIO/PWM ─────────┼─────► DDS Output (GPIO 0)
                 │                  │
                 │ GPIO 16 ─────────┼─────► TX Control
                 │                  │
                 │ GPIO 17 ─────────┼─────► RX Control
                 │                  │
                 │ GPIO 25 ─────────┼─────► Status LED
                 │                  │
                 └──────────────────┘
```

## Components

### Microcontroller
- **RP2040** - Dual ARM Cortex-M0+ @ 125MHz
  - 264KB SRAM
  - 2MB Flash (via QSPI)
  - USB 1.1 Device/Host
  - 30 GPIO pins
  - 8 PIO state machines
  - 12-bit ADC

### Signal Generation
- **Direct Digital Synthesis**
  - Uses RP2040 PIO for precise timing
  - PWM for signal generation
  - No external clock generator needed

### Audio Interface
- **USB Audio Device**
  - Full-duplex digital audio
  - 48 kHz sample rate
  - 16-bit stereo
  - No analog audio components

## Pin Assignments

| GPIO | Direction | Function | Description |
|------|-----------|----------|-------------|
| 0 | Output | DDS_OUT | Direct digital synthesis output |
| 16 | Output | TX_CTL | Transmit control signal |
| 17 | Output | RX_CTL | Receive control signal |
| 25 | Output | LED | Status indicator LED |
| USB D+/D- | I/O | USB | USB audio + debug |

## Power Supply

- **USB Powered**: 5V via USB connector
- **Current Draw**: ~100mA typical
- **Voltage Regulation**: On-board 3.3V regulator

## RF Section (External)

The RP2040 generates baseband signals. External RF circuitry required:

1. **Low-pass Filter** - Filter DDS output
2. **RF Amplifier** - Amplify to desired power level
3. **Antenna Switch** - TX/RX switching
4. **Band Pass Filters** - Band selection

## PCB Design Considerations

### Layout Guidelines
- Keep DDS output traces short
- Ground plane under RF sections
- USB traces differential impedance matched
- Separate analog and digital grounds

### Component Placement
- RP2040 centrally located
- USB connector on edge
- RF output on opposite edge
- Decoupling caps near IC

## Future Enhancements

- On-board RF filters
- Integrated RF amplifier
- External antenna switch control
- Temperature-compensated oscillator
- Battery power option

## Schematic

*Note: Full schematic to be released in future revision*

## BOM (Minimal Configuration)

| Qty | Part | Description |
|-----|------|-------------|
| 1 | RP2040 | Microcontroller |
| 1 | W25Q16 | 2MB Flash memory |
| 1 | LDO 3.3V | Voltage regulator |
| 2 | 27Ω | USB resistors |
| 1 | USB Micro/Type-C | USB connector |
| 1 | LED | Status indicator |
| Various | Capacitors | Decoupling |

## Safety

⚠️ **Warning**: This device generates RF signals. Ensure:
- Proper RF shielding
- Appropriate filtering
- Antenna connection
- Compliance with local regulations
- Amateur radio license (where required)
