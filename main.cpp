#include "main.h"
#include "SubSystemHeaders/globals.hpp"
#include "SubSystemHeaders/shoot.hpp"
#include "SubSystemHeaders/drive.hpp"
#include "SubSystemHeaders/intake.hpp"
#include "subSystemHeaders/autons.hpp"
#include "okapi/api/util/mathUtil.hpp"
#include "pros/adi.hpp"
#include "pros/imu.hpp"
#include "pros/llemu.hpp"
#include "pros/motors.h"
#include "pros/motors.hpp"
#include "pros/rotation.hpp"
#include <atomic>
#include <string>
#include <cmath>
#include <memory>

std::shared_ptr <ChassisController> chassis = ChassisControllerBuilder()
	.withMotors({18,20},{17,19})
// Green gearset, external ratio of (36.0 / 60.0), 4 inch wheel diameter, 11.5 inch wheel track
	.withDimensions({AbstractMotor::gearset::green, (36.0 / 60.0)}, {{3.25_in, 10.5_in}, imev5GreenTPR})
	.build();

void initialize() {
	pros::lcd::initialize();
}

void disabled() {}

void intakeAut(int power, int deg);


//this would be where auton selector would be
void competition_initialize() {}

//autonomous period
void autonomous() {
	aut1();
}

//driver control period
void opcontrol() {

	while (true) {
		//drive function
		setDriveMotors();

		//catapult function
		setCataMotors();

		if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)){
			arm.set_value(true);
		}
		else if (controller.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)){
			arm.set_value(false);
		}

		pros::delay(20);
	}
}
