#include "main.h"

void onReceive(const int size) {
    switch (Wire.read()) {
        case MOTION_METADATA:
            float receivedFloats[5];

            for (int i = 0; i < 5; i++) {
                byte floatBytes[4];

                for (int b = 0; b < 4; b++) {
                    if (Wire.available()) {
                        floatBytes[b] = Wire.read();
                    }
                }

                receivedFloats[i] = *reinterpret_cast<float *>(floatBytes);
            }

            for (int i = 0; i < 5; i++) {
                processMotion.duration = receivedFloats[0];
                processMotion.x1 = receivedFloats[1];
                processMotion.y1 = receivedFloats[2];
                processMotion.x2 = receivedFloats[3];
                processMotion.y2 = receivedFloats[4];
            }

            break;

        case MOTION_DATA:
            for (int i = 0; i < size - 1; i += 2) {
                processMotion.motion_moves[processMotion.len].part = Wire.read();
                processMotion.motion_moves[processMotion.len++].degree = Wire.read();
            }

            motions.push(processMotion);

            processMotion.len = 0;

            break;

        case EMERGENCY_STOP: default:
            break;
    }
}

void setup_communication() {
    Wire.begin(I2C_ADDRESS);
    Wire.onReceive(onReceive);
}
