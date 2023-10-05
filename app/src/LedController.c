#include <stdlib.h>
#include <memory.h>

#include "../inc/LedController.h"

/**
 * @brief This array holds the initialized LED drivers
 */
static pLedDriver leddrivers[MAX_LEDS] = { NULL };

/**
 * @brief Initialize a pLedDriver array.
 */
void ledcontroller_create(void) {
    memset(leddrivers, 0, sizeof leddrivers);
}

/**
 * @brief Frees the allocated memory of the pLedDriver array.
 */
void ledcontroller_destroy(void) {
    int i;
    for (i = 0; i < MAX_LEDS; i++)
    {
        pLedDriver driver = leddrivers[i];
        leddriver_destroy(driver);
        leddrivers[i] = NULL;
    }
}

/**
 * @brief Checks if the passed id is in bounds
 *
 * @param[in] id Unique identifier for the pLedDriver.
 * @return Out of Bounds = 1 or not out of bounds = 0
 */
static BOOL isIdInBounds(int id) {
    return (BOOL)(id < 0 || id >= MAX_LEDS);
}

/**
 * @brief Adds a new LED driver to the pLedDriver array.
 *
 * @param[in] id Unique identifier for the pLedDriver.
 * @return Seccess = 1 or Failure = 0
 */
BOOL ledcontroller_add(int id, pLedDriver leddrv) {
    if (isIdInBounds(id))
        return FALSE;

    if (leddrv == NULL)
        return FALSE;

    leddriver_destroy(leddrivers[id]);

    leddrivers[id] = leddrv;
    return TRUE;
}

/**
 * @brief Removes LED driver from the pLedDriver array.
 *
 * @param[in] id Unique identifier for the pLedDriver.
 * @return Seccess = 1 or Failure = 0
 */
BOOL ledcontroller_remove(int id) {
    if (isIdInBounds(id))
        return FALSE;

    if (leddrivers[id] == NULL)
        return FALSE;

    leddriver_destroy(leddrivers[id]);

    leddrivers[id] = NULL;
    return TRUE;
}

/**
 * @brief Sets the pLedDriver state to ON.
 *
 * @param[in] id Unique identifier for the pLedDriver.
 */
void ledcontroller_turnon(int id) {
    leddriver_turnOn(leddrivers[id]);
}

/**
 * @brief Sets the pLedDriver state to OFF.
 *
 * @param[in] id Unique identifier for the pLedDriver.
 */
void ledcontroller_turnoff(int id) {
    leddriver_turnOff(leddrivers[id]);
}

/**
 * @brief Gets the pLedDriver state of either ON or OFF.
 *
 * @param[in] id Unique identifier for the pLedDriver.
 * @return The current state of the pLedDriver.
 */
int ledcontroller_getstatus(int id) {
    return leddriver_getstatus(leddrivers[id]);
}