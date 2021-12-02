#pragma once

#include <stdint.h>
#include <LSM6.h>
#include <Balboa32U4.h>

const int16_t GEAR_RATIO = 75.81;
const int16_t MOTOR_SPEED_LIMIT = 300;
const int16_t ANGLE_RATE_RATIO = 140;
const int16_t ANGLE_RESPONSE = 11;
const int16_t DISTANCE_RESPONSE = 70;
const int16_t DISTANCE_DIFF_RESPONSE = -80;
const int16_t SPEED_RESPONSE = 2150;
const uint8_t UPDATE_TIME_MS = 10;
const uint8_t CALIBRATION_ITERATIONS = 100;
const int32_t START_BALANCING_ANGLE = 45000;
const int32_t STOP_BALANCING_ANGLE = 70000;
extern int32_t angle; // units: millidegrees
extern int32_t angleRate; // units: degrees/s (or millidegrees/ms)
extern int16_t motorSpeed; // current (average) motor speed setting
extern LSM6 imu;
extern Balboa32U4Motors motors;
extern Balboa32U4Encoders encoders;

void balanceSetup();

void balanceUpdate();

void balanceDrive(int16_t leftSpeed, int16_t rightSpeed);

bool isBalancing();

bool balanceUpdateDelayed();

void balanceUpdateSensors();

void balanceResetEncoders();
