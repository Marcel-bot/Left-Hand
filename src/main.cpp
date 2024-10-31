#include "main.h"

motion processMotion;
Queue motions;


void setup() {
    setup_communication();
    setup_movement();
}

void loop() {
    loop_movement();
}
