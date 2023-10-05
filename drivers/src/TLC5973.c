#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#include "../inc/TLC5973.h"

/**
 * @brief Structure representing a TLC5973 instance.
 *
 * This structure holds the state and function pointers for the TLC5973 object.
 */
typedef struct TLC5973Struct {
    LedDriverStruct base;
    LedStatus status;
} TLC5973Struct;

typedef struct TLC5973Struct* pTLC5973;

/**
 * Private functions prototypes.
 */
static void turnon(pLedDriver super);
static void turnoff(pLedDriver super);
static int getstatus(pLedDriver super);
static void destroy(pLedDriver super);

/**
 * @brief Object holding the interface pointer function for the TLC5973 struct.
 *
 * This object holds all the neccessary pointer functions for the TLC5973.
 */
static iLed interface = {
    turnon,
    turnoff,
    getstatus,
    destroy
};

/**
 * @brief Creates a TLC5973 object instance
 *
 * @param[in] id Unique identifier for the pLedDriver.
 * @return The TLC5973 driver instance
 */
pLedDriver tlc5973_create(int id) {
    pTLC5973 self = (pTLC5973)calloc(1, sizeof(pTLC5973));
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
    pTLC5973 self = (pTLC5973)super;
    self->status = ON;
}

/**
 * @brief Sets the pLedDriver state to OFF.
 *
 * @param[in] super pLedDriver object
 */
static void turnoff(pLedDriver super) {
    pTLC5973 self = (pTLC5973)super;
    self->status = OFF;
}

/**
 * @brief Gets the pLedDriver state of either ON or OFF.
 *
 * @param[in] super pLedDriver object
 * @return The current state of the pLedDriver.
 */
static int getstatus(pLedDriver super) {
    pTLC5973 self = (pTLC5973)super;
    return self->status;
}

/**
 * @brief Frees allocated memory of the passed pLedDriver
 *
 * @param[in] super pLedDriver object
 */
static void destroy(pLedDriver super) {
    pTLC5973 self = (pTLC5973)super;
    printf("TLC5973 LED #%d destroyed \n", self->base.id);
    free(self);
}