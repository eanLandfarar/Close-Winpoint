#include "subSystemHeaders/shoot.hpp"

//helper functions
void setCata(int power){
    cata1 = power;
    cata2 = power;
}

//driver control functions
void setCataMotors(){
    int cataPower = 100 * (controller.get_digital(pros::E_CONTROLLER_DIGITAL_L1));
    setCata(cataPower);
}