cmake_minimum_required(VERSION 3.13)

# Pull in Raspberry Pi Pico SDK (must be before project)
include(pico_sdk_import.cmake)

project(adx_rp2040_dds C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialize the SDK
pico_sdk_init()

add_executable(adx_rp2040_dds
    src/main.c
    src/dds.c
    src/usb_audio.c
    src/usb_descriptors.c
    src/adx_transceiver.c
    src/ft8_protocol.c
)

# Pull in common dependencies
target_link_libraries(adx_rp2040_dds
    pico_stdlib
    hardware_dma
    hardware_pio
    hardware_clocks
    hardware_pwm
    tinyusb_device
    tinyusb_board
)

# Enable USB output, disable UART output
pico_enable_stdio_usb(adx_rp2040_dds 1)
pico_enable_stdio_uart(adx_rp2040_dds 0)

# Create map/bin/hex/uf2 file etc.
pico_add_extra_outputs(adx_rp2040_dds)

# Add compile options
target_compile_options(adx_rp2040_dds PRIVATE
    -Wall
    -Wextra
    -Wno-unused-parameter
)
