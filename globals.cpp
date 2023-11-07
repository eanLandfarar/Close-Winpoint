#include "main.h"
#include "subSystemHeaders/globals.hpp"

//drive base motors
pros::Motor dlb(2, pros::E_MOTOR_GEARSET_36, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor dlf(1, pros::E_MOTOR_GEARSET_36, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor dl5(3, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor drb(4, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor drf(5, pros::E_MOTOR_GEARSET_36, false, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor dr5(6, pros::E_MOTOR_GEARSET_36, true, pros::E_MOTOR_ENCODER_COUNTS);

//cata motors
pros::Motor cata1(11, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_COUNTS);
pros::Motor cata2(12, pros::E_MOTOR_GEARSET_18, false, pros::E_MOTOR_ENCODER_COUNTS);

//intake motors
pros::Motor intake(13, pros::E_MOTOR_GEARSET_18, true, pros::E_MOTOR_ENCODER_COUNTS);

//pneumatics
pros::ADIDigitalOut left_wing('C');
pros::ADIDigitalOut right_wing('B');
pros::ADIDigitalOut arm('A');

//sensors
pros::IMU imu(20);

//controller
pros::Controller controller(pros::E_CONTROLLER_MASTER);