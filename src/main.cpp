#include "main.h"

motion processMotion;
Queue motions;


void setup() {
    Serial.begin(115200);

    setup_communication();
    setup_movement();
}

void loop() {
    loop_movement();
}
