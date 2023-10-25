#include <stdio.h>

#include "../../drivers/inc/TLC5973.h"
#include "../inc/LedController.h"

int main(void) {

    // Feature added
	// Feature 2 addes
    ledcontroller_create();

    pLedDriver tlc = tlc5973_create(0);
    ledcontroller_add(0, tlc);

    ledcontroller_getstatus(0);
    ledcontroller_turnon(0);
    ledcontroller_getstatus(0);
    ledcontroller_turnoff(0);
    ledcontroller_getstatus(0);

    ledcontroller_destroy();

    return 0;
}