/**
@addtogroup SPIWrapper SPI Wrapper for Ruuvitag
@{
@file       spi.h

SPI Wrapper for Ruuvitag that provides a SPI Transfer function for the Sensors using the SPI bus.

Note: SPI and SPI0 have to be enabled in sdk_config.h in the project, to use this driver.

Vesa Koskinen
May 11, 2016

* @}
***************************************************************************************************/
#ifndef SPI_H
#define SPI_H


/* INCLUDES ***************************************************************************************/
#include <stdbool.h>
#include <stdint.h>
#include "app_error.h"

/* CONSTANTS **************************************************************************************/

/* MACROS *****************************************************************************************/

/* TYPES ******************************************************************************************/
/** States of the module */
typedef enum
{
    SPI_RET_OK = 0, /**< Ok */
    SPI_RET_BUSY = 1, /**< Other SPI transfer in progress */
    SPI_RET_ERROR = 2 /**< Not otherwise specified error */
} SPI_Ret;

/* PROTOTYPES *************************************************************************************/

/**
 * Initialize the SPI Wrapper
 */
extern void spi_init(void);

/**
 * Check if SPI Driver/Wrapper is initialized
 *
 * @return true Driver is initialized
 * @return false Driver is not yet initialized
 */
extern bool spi_isInitialized(void);

/**
 * Send and receive bytes for bme280 environmental sensor
 *
 * @param[in] p_toWrite Data to transfer
 * @param[out] p_toRead Receive buffer
 * @param[in] count Size of p_toRead and p_toWrite
 *
 * @return SPI_RET_OK SPI transfer was successful
 * @return SPI_RET_BUSY SPI is busy with other transfer, please try again
 */
extern SPI_Ret spi_transfer_bme280(
    uint8_t* const p_toWrite, uint8_t count, uint8_t* const p_toRead);

/**
 * Send and receive bytes for lis2dh12 Acceleration Sensor
 *
 * @param[in] p_toWrite Data to transfer
 * @param[out] p_toRead Receive buffer
 * @param[in] count Size of p_toRead and p_toWrite
 *
 * @return SPI_RET_OK SPI transfer was successful
 * @return SPI_RET_BUSY SPI is busy with other transfer, please try again
*/


#endif /* SPI_H */