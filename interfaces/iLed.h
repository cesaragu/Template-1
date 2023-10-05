#ifndef ILED_H
#define ILED_H
#ifdef __cplusplus
 extern "C" {
#endif

/**
 * @file iLed.h
 * @brief Header file for the iLed module.
 *
 * This header defines the interface for the generic iLed module,
 * which provides the interface that describes the pLedDriver object
 */

/**
 * @brief This enum holds the available LED states.
 */
typedef enum {
    OFF = 0,
    ON  = 1,
} LedStatus;

typedef struct iLed* piLed;
typedef struct LedDriverStruct* pLedDriver;

/**
 * @brief Structure representing a LedDriver instance.
 *
 * This structure holds the id and function pointers for the generic Led driver.
 */
typedef struct LedDriverStruct {
    piLed vtable;
    int id;
} LedDriverStruct;

/**
 * Create a typedef defining a simple function pointer
 * to be used for LED's
*/
typedef void (*iLedFunc)(pLedDriver);
typedef int (*iLedFuncStat)(pLedDriver);

/**
 * @brief Structure representing a iLed instance.
 *
 * This structure holds the function pointers for the generic Led driver.
 */
typedef struct iLed{
    /**
	 * On turns on the LED - regardless of the driver logic
	 */
    const iLedFunc turnon;
    /**
	 * Off turns off the LED - regardless of the driver logic
	 */
    const iLedFunc turnoff;
    /**
	 * Gets Led Status - regardless of the driver logic
	 */
    const iLedFuncStat getstatus;
    /**
	 * Frees the allocated memory - regardless of the driver logic
	 */
    const iLedFunc destroy;
} iLed;

#ifdef __cplusplus
 }
#endif
#endif /* ILED_H */