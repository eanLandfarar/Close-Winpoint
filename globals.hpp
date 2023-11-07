#include "main.h"
#include "pros/adi.hpp"
#ifndef GLOBALS_HPP
#define GLOBALS_HPP

//drive base motors
extern pros::Motor dlb;
extern pros::Motor dlf;
extern pros::Motor dl5;
extern pros::Motor drb;
extern pros::Motor drf;
extern pros::Motor dr5;

//cata motors
extern pros::Motor cata1;
extern pros::Motor cata2;

//intake motors
extern pros::Motor intake;

//pneumatics
extern pros::ADIDigitalOut left_wing;
extern pros::ADIDigitalOut right_wing;
extern pros::ADIDigitalOut arm;

//sensors
extern pros::IMU imu;

//controller
extern pros::Controller controller;

//miscellaneous
#endif