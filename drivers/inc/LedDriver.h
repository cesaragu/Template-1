#ifndef LEDDRIVER_H
#define LEDDRIVER_H
#ifdef __cplusplus
 extern "C" {
#endif

/**
 * @file LedDriver.h
 * @brief Header file for the LedDriver module.
 *
 * This header defines the interface for the generic LedDriver module,
 * which provides functions to create and interact with multiple types of LEDs.
 */

#include "../../interfaces/iLed.h"

/**
 * @brief Sets the pLedDriver state to ON.
 *
 * @param[in] self pLedDriver object
 */
void leddriver_turnOn(pLedDriver self);

/**
 * @brief Sets the pLedDriver state to OFF.
 *
 * @param[in] self pLedDriver object
 */
void leddriver_turnOff(pLedDriver self);

/**
 * @brief Frees allocated memory of the passed pLedDriver
 *
 * @param[in] self pLedDriver object
 */
void leddriver_destroy(pLedDriver self);

/**
 * @brief Gets the pLedDriver state of either ON or OFF.
 *
 * @param[in] self pLedDriver object
 * @return The current state of the pLedDriver.
 */
int leddriver_getstatus(pLedDriver self);

/**
 * @brief Gets the pLedDriver given id number
 *
 * @param[in] driver pLedDriver object
 * @return The given pLedDriver's id
 */
int leddriver_getid(pLedDriver driver);

#ifdef __cplusplus
 }
#endif
#endif /* LEDDRIVER_H */