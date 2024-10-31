#ifndef MAIN
#define MAIN

#include <Arduino.h>
#include <Wire.h>
#include <Servo.h>

#include "communication.h"
#include "movement.h"
#include "queue.h"

#define BAUDRATE 115200

#define STEP_SIZE 3
#define SMOOTHING_DELAY 12

extern motion processMotion;
extern Queue motions;

#endif
