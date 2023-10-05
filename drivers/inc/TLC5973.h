#ifndef TLC5973_H
#define TLC5973_H
#ifdef __cplusplus
 extern "C" {
#endif

/**
 * @file TLC5973.h
 * @brief Header file for the TLC5973 module.
 *
 * This header defines the interface for the TLC5973 module,
 * which provides a function to create a TLC5973 instance.
 */

#include "LedDriver.h"

/**
 * @brief Creates a TLC5973 object instance
 *
 * @param[in] id Unique identifier for the pLedDriver.
 * @return The TLC5973 driver instance
 */
pLedDriver tlc5973_create(int id);

#ifdef __cplusplus
 }
#endif
#endif /* TLC5973_H */