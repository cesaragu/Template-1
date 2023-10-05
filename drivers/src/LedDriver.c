#include "../inc/LedDriver.h"

/**
 * @brief Sets the pLedDriver state to ON.
 *
 * @param[in] self pLedDriver object
 */
void leddriver_turnOn(pLedDriver self) {
    if (self)
        self->vtable->turnon(self);
}

/**
 * @brief Sets the pLedDriver state to OFF.
 *
 * @param[in] self pLedDriver object
 */
void leddriver_turnOff(pLedDriver self) {
    if (self)
        self->vtable->turnoff(self);
}

/**
 * @brief Frees allocated memory of the passed pLedDriver
 *
 * @param[in] self pLedDriver object
 */
void leddriver_destroy(pLedDriver self) {
    if (self)
        self->vtable->destroy(self);
}

/**
 * @brief Gets the pLedDriver state of either ON or OFF.
 *
 * @param[in] self pLedDriver object
 */
int leddriver_getstatus(pLedDriver self) {
    if (self)
        return self->vtable->getstatus(self);
    return -1;
}

/**
 * @brief Gets the pLedDriver given id number
 *
 * @param[in] driver pLedDriver object
 * @return The given pLedDriver's id
 */
int leddriver_getid(pLedDriver driver) {
    return driver->id;
}