#ifndef MOVEMENT
#define MOVEMENT

#define INNER_SHOULDER_PIN 6
#define OUTER_SHOULDER_PIN 10
#define UNDER_SHOULDER_PIN 11
#define ELBOW_PIN 9
#define WRIST_PIN 5
#define HAND_PIN 3

float cubic_bezier(float p0, float p1, float p2, float p3, float t);

void setup_movement();

void loop_movement();

#endif
