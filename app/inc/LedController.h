#ifndef LEDCONTROLLER_H
#define LEDCONTROLLER_H
#ifdef __cplusplus
 extern "C" {
#endif

/**
 * @file LedController.h
 * @brief Header file for the LedController module.
 *
 * This header defines the interface for the LedController module,
 * which provides functions to create and interact with multiple LEDs.
 */

#include "../../drivers/inc/LedDriver.h"
#include "../../util/common.h"

/**
 * @brief This enum holds the maximum number of LEDs.
 */
enum { MAX_LEDS = 32 };

/**
 * @brief Initialize a pLedDriver array.
 */
void ledcontroller_create(void);

/**
 * @brief Frees the allocated memory of the pLedDriver array.
 */
void ledcontroller_destroy(void);

/**
 * @brief Sets the pLedDriver state to ON.
 *
 * @param[in] id Unique identifier for the pLedDriver.
 */
void ledcontroller_turnon(int id);

/**
 * @brief Sets the pLedDriver state to OFF.
 *
 * @param[in] id Unique identifier for the pLedDriver.
 */
void ledcontroller_turnoff(int id);

/**
 * @brief Gets the pLedDriver state of either ON or OFF.
 *
 * @param[in] id Unique identifier for the pLedDriver.
 * @return The current state of the pLedDriver.
 */
int ledcontroller_getstatus(int id);

/**
 * @brief Adds a new LED driver to the pLedDriver array.
 *
 * @param[in] id Unique identifier for the pLedDriver.
 * @return Seccess = 1 or Failure = 0
 */
BOOL ledcontroller_add(int id, pLedDriver ledDriver);

/**
 * @brief Removes LED driver from the pLedDriver array.
 *
 * @param[in] id Unique identifier for the pLedDriver.
 * @return Seccess = 1 or Failure = 0
 */
BOOL ledcontroller_remove(int id);

#ifdef __cplusplus
 }
#endif
#endif /* LEDCONTROLLER_H */