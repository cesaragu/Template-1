#ifndef LEDMOCKDEVICE_H
#define LEDMOCKDEVICE_H
#ifdef __cplusplus
 extern "C" {
#endif

/**
 * @file LedMockDevice.h
 * @brief Header file for the LedMockDevice module.
 *
 * This header defines the interface for the LedMockDevice module,
 * which provides a function to create a LedMockDevice instance.
 */

#include "../../drivers/inc/LedDriver.h"

/**
 * @brief Creates an Led mock object instance
 *
 * @param[in] id Unique identifier for the pLedDriver.
 * @return The mock device driver instance
 */
pLedDriver ledmockdevice_create(int id);

#ifdef __cplusplus
 }
#endif
#endif /* LEDMOCKDEVICE_H */