#include "main.h"
#include "subSystemHeaders/autons.hpp"
#include "pros/motors.h"
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

//autonomous driving temporary (okapi)
std::shared_ptr<ChassisController> drive = ChassisControllerBuilder()
	.withMotors({2,1},{5, 4})
// Green gearset, external ratio of (36.0 / 60.0), 4 inch wheel diameter, 11.5 inch wheel track
	.withDimensions({AbstractMotor::gearset::blue, (36.0 / 60.0)}, {{3.25_in, 10.5_in}, imev5GreenTPR})
	.build();

//autonomous catapult control
void cataAut(int power, int time){
	cata1.move_velocity(power);
	cata2.move_velocity(power);
	pros::delay(time);
}

//autonomous intake control
void intakeAut(int power, int deg){
	intake.move_relative(deg, power);
}

//autonomous pneumatics control
void armA(int value){
	if (value == 1){
		arm.set_value(true);
	}
	else {
		arm.set_value(false);
	}
}

//turning pid
const double kpTurn = 0.5;
const double kiTurn = 0.0001;
const double kdTurn = 0.002;

void turnPid(double deg){
	imu.set_heading(0);
	dlb.set_brake_mode(pros::c::motor_get_brake_mode(MOTOR_BRAKE_HOLD));
	dlf.set_brake_mode(pros::c::motor_get_brake_mode(MOTOR_BRAKE_HOLD));
	dl5.set_brake_mode(pros::c::motor_get_brake_mode(MOTOR_BRAKE_HOLD));
	drb.set_brake_mode(pros::c::motor_get_brake_mode(MOTOR_BRAKE_HOLD));
    drf.set_brake_mode(pros::c::motor_get_brake_mode(MOTOR_BRAKE_HOLD));
    dr5.set_brake_mode(pros::c::motor_get_brake_mode(MOTOR_BRAKE_HOLD));

	double target = deg;
	double totalError = 0;
	double prevError = 0;
	while (1){
		double error = std::fmod(target - imu.get_heading() + 180, 360) - 180;
		if (error < -180){
			error += 360;
		}
		totalError += error;
		double derivative = error - prevError;
		double power = kpTurn * error + kiTurn * totalError + kdTurn * derivative;
		dlb.move_velocity(power);
		dlf.move_velocity(power);
		dl5.move_velocity(power);
		drb.move_velocity(-power);
        drf.move_velocity(-power);
        dr5.move_velocity(-power);

		if (std::abs(error) <= 2 && std::abs(derivative) <= 0.2){
			break;
		}
		prevError = error;
		pros::delay(5);
	}
	dlb.move_velocity(0);
	dlf.move_velocity(0);
	dl5.move_velocity(0);
	drb.move_velocity(0);
    drf.move_velocity(0);
    dr5.move_velocity(0);
}

//diff autons
void aut1(){
	drive->moveDistance(15_in);
	pros::delay(200);
	armA(1);
	drive->moveDistance(-15_in);
	turnPid(-50);
	pros::delay(200);
	armA(0);
	drive->setMaxVelocity(50);
	drive->moveDistance(-41_in);
}
