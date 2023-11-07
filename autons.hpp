#include "main.h"
#include "globals.hpp"
#ifndef AUTONS_HPP
#define AUTONS_HPP

//autonomous catapult control
void cataAut(int power, int time);

//autonomous intake control
void intakeAut(int power, int time);

//turning pid
void turnPid(double deg);

//diff autons
void aut1();

#endif