# Building ADX-rp2040-DDS

## Prerequisites

1. **Raspberry Pi Pico SDK**
   - Download and install the [Pico SDK](https://github.com/raspberrypi/pico-sdk)
   - Set the `PICO_SDK_PATH` environment variable

2. **Build Tools**
   - CMake (version 3.13 or higher)
   - ARM GCC toolchain (arm-none-eabi-gcc)
   - Make or Ninja

## Quick Start

### Linux/macOS

```bash
# Set Pico SDK path
export PICO_SDK_PATH=/path/to/pico-sdk

# Create build directory
mkdir build
cd build

# Configure
cmake ..

# Build
make -j4
```

### Windows

```powershell
# Set Pico SDK path
set PICO_SDK_PATH=C:\path\to\pico-sdk

# Create build directory
mkdir build
cd build

# Configure
cmake -G "NMake Makefiles" ..

# Build
nmake
```

## Output Files

After successful build, you'll find:

- `adx_rp2040_dds.uf2` - Firmware file for uploading to RP2040
- `adx_rp2040_dds.elf` - ELF binary for debugging
- `adx_rp2040_dds.bin` - Raw binary file

## Flashing

1. Hold the BOOTSEL button while connecting the Pico to USB
2. The Pico will appear as a USB mass storage device
3. Copy `adx_rp2040_dds.uf2` to the device
4. The Pico will automatically reboot and run the firmware

## Debugging

Connect a serial terminal (115200 baud) to the USB CDC port for debug output.

## Configuration

Edit the following files to customize:
- `src/adx_transceiver.c` - Transceiver settings
- `src/dds.c` - DDS configuration
- `CMakeLists.txt` - Build configuration
