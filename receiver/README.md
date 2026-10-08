# Receiver

The receiver side receives AirMouse control data transmitted wirelessly from the Raspberry Pi Pico.

## Data Format

The transmitter sends:

mouseX,mouseY,leftClick,rightClick,scrollUp,scrollDown

Example:

5,-3,1,0,0,0

## Communication

- HC-05 Bluetooth
- ESP-01 Wi-Fi
- TCP communication on port 5000 for Wi-Fi mode

The receiver interprets the received values to control cursor movement, mouse clicks, and scrolling.
