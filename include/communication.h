#ifndef COMMUNICATION
#define COMMUNICATION

#define I2C_ADDRESS 0x09

#define MOTION_METADATA 1
#define MOTION_DATA 2
#define EMERGENCY_STOP 3

void setup_communication();

void onReceive(int size);

#endif
