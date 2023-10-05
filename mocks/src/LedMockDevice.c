#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#include "../inc/LedMockDevice.h"

/**
 * @brief Structure representing a Mock device instance.
 *
 * This structure holds the state and function pointers for the Mock device object.
 */
typedef struct LedMockDevStruct {
    LedDriverStruct base;
    LedStatus status;
} LedMockDevStruct;

typedef struct LedMockDevStruct* pLedMockDev;

/**
 * Private functions prototypes.
 */
static void turnon(pLedDriver super);
static void turnoff(pLedDriver super);
static int getstatus(pLedDriver super);
static void destroy(pLedDriver super);

/**
 * @brief Object holding the interface pointer function for the Mock device struct.
 *
 * This object holds all the neccessary pointer functions for the Mock device.
 */
static iLed interface = {
    turnon,
    turnoff,
    getstatus,
    destroy
};

/**
 * @brief Creates an Led mock object instance
 *
 * @param[in] id Unique identifier for the pLedDriver.
 * @return The mock device driver instance
 */
pLedDriver ledmockdevice_create(int id) {
    pLedMockDev self = (pLedMockDev)calloc(1, sizeof(pLedMockDev));
    self->base.vtable = &interface;
    self->base.id = id;
    self->status = OFF;
    return (pLedDriver)self;
}

/**
 * @brief Sets the pLedDriver state to ON.
 *
 * @param[in] super pLedDriver object
 */
static void turnon(pLedDriver super) {
    pLedMockDev self = (pLedMockDev)super;
    self->status = ON;
}

/**
 * @brief Sets the pLedDriver state to OFF.
 *
 * @param[in] super pLedDriver object
 */
static void turnoff(pLedDriver super) {
    pLedMockDev self = (pLedMockDev)super;
    self->status = OFF;
}

/**
 * @brief Gets the pLedDriver state of either ON or OFF.
 *
 * @param[in] super pLedDriver object
 * @return The current state of the pLedDriver.
 */
static int getstatus(pLedDriver super) {
    pLedMockDev self = (pLedMockDev)super;
    return self->status;
}

/**
 * @brief Frees allocated memory of the passed pLedDriver
 *
 * @param[in] super pLedDriver object
 */
static void destroy(pLedDriver super) {
    pLedMockDev self = (pLedMockDev)super;
    printf("Mock LED #%d destroyed \n", self->base.id);
    free(self);
}