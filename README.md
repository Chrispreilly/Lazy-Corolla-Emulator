# Lazy-Corolla-Emulator
Fingerprint as a corolla in openpilot with 1 CAN ID

Setup:

Arduino UNO
MCP2515 CAN Board with 16mhz oscillator
White Panda
OnePlus3


Loops sending CAN ID 0x7e1 which is unique to a corolla LE, allowing OP to instantly fingerprint.

Also sends a vehicle speed so you know when it's successfull.
