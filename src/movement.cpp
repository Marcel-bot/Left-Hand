#include "main.h"

Servo parts[6];

int positions[6];

float cubic_bezier(const float p0, const float p1, const float p2, const float p3, const float t) {
    const float one_minus_t = 1 - t;
    return one_minus_t * one_minus_t * one_minus_t * p0 +
           3 * one_minus_t * one_minus_t * t * p1 +
           3 * one_minus_t * t * t * p2 +
           t * t * t * p3;
}

void setup_movement() {
    parts[0].attach(INNER_SHOULDER_PIN);
    parts[1].attach(OUTER_SHOULDER_PIN);
    parts[2].attach(UNDER_SHOULDER_PIN);
    parts[3].attach(ELBOW_PIN);
    parts[4].attach(WRIST_PIN);
    parts[5].attach(HAND_PIN);

    delay(100);

    parts[0].write(180);
    parts[1].write(180);
    parts[2].write(90);
    parts[3].write(90);

    positions[0] = 180;
    positions[1] = 180;
    positions[2] = 90;
    positions[3] = 90;
}

void loop_movement() {
    if (!motions.isEmpty()) {
        Serial.println("Processing command");
        const unsigned long start = millis();

        for (int i = 0; i < 6; i++) {
            Serial.print("Initial value for ");
            Serial.print(i);
            Serial.print(": ");
            Serial.println(positions[i]);
        }

        for (int i = 0; i < motions.first().len; i++) {
            Serial.print("Moving ");
            Serial.print(motions.first().motion_moves[i].part);
            Serial.print("to:");
            Serial.println(motions.first().motion_moves[i].degree);
        }

        for (unsigned long now = millis(); now < start + motions.first().duration * 1000; now = millis()) {
            const float t = static_cast<float>(now - start) / (motions.first().duration * 1000);

            for (int i = 0; i < motions.first().len; ++i) {
                const motionMove currentMotion = motions.first().motion_moves[i];

                const int pos = positions[currentMotion.part] + (
                                    currentMotion.degree - positions[currentMotion.part]) * t;

                Serial.print("Moving ");
                Serial.print(currentMotion.part);
                Serial.print(" to ");
                Serial.println(pos);

                parts[currentMotion.part].write(pos);
            }
        }

        for (int i = 0; i < motions.first().len; i++) {
            positions[motions.first().motion_moves[i].part] = motions.first().motion_moves[i].degree;
        }

        motions.pop();

        Serial.println("Command_processed");
    }
}
