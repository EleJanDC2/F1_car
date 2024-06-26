/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

#ifndef _PERIPHERALS_H_
#define _PERIPHERALS_H_

/***********************************************************************************************************************
 * Included files
 **********************************************************************************************************************/
#include "fsl_common.h"
#include "fsl_spi.h"
#include "fsl_clock.h"
#include "fsl_ctimer.h"

#if defined(__cplusplus)
extern "C" {
#endif /* __cplusplus */

/***********************************************************************************************************************
 * Definitions
 **********************************************************************************************************************/
/* Definitions for BOARD_InitPeripherals functional group */
/* BOARD_InitPeripherals defines for SPI0 */
/* Definition of peripheral ID */
#define SPI0_PERIPHERAL ((SPI_Type *)SPI0)
/* Definition of the clock source frequency */
#define SPI0_CLOCK_SOURCE 15000000UL
/* Buffer size [Bytes]. */
#define SPI0_BUFFER_SIZE 9
/* SPI0 interrupt vector ID (number). */
#define SPI0_SPI_IRQN SPI0_IRQn
/* Definition of peripheral ID */
#define CTIMER0_PERIPHERAL CTIMER0
/* Timer tick frequency in Hz (input frequency of the timer) */
#define CTIMER0_TICK_FREQ 15000000UL
/* Timer tick period in ns (input period of the timer) */
#define CTIMER0_TICK_PERIOD 67UL
/* Definition of PWM period channel. */
#define CTIMER0_PWM_PERIOD_CH kCTIMER_Match_3
/* Definition of PWM period */
#define CTIMER0_PWM_PERIOD 9999
/* Definition of channel 0 ID */
#define CTIMER0_PWM_0_CHANNEL kCTIMER_Match_0
/* Definition of channel 0 duty */
#define CTIMER0_PWM_0_DUTY 1000
/* CTIMER0 interrupt vector ID (number). */
#define CTIMER0_TIMER_IRQN CTIMER0_IRQn

/***********************************************************************************************************************
 * Global variables
 **********************************************************************************************************************/
extern const spi_master_config_t SPI0_config;
extern uint8_t SPI0_txBuffer[SPI0_BUFFER_SIZE];
extern uint8_t SPI0_rxBuffer[SPI0_BUFFER_SIZE];
extern spi_transfer_t SPI0_transfer;
extern spi_master_handle_t SPI0_handle;
extern const ctimer_config_t CTIMER0_config;

/***********************************************************************************************************************
 * Callback functions
 **********************************************************************************************************************/
  /* Single callback function declaration */
extern void cbTimer(uint32_t flags);
extern ctimer_callback_t CTIMER0_callback[];

/***********************************************************************************************************************
 * Initialization functions
 **********************************************************************************************************************/

void BOARD_InitPeripherals(void);

/***********************************************************************************************************************
 * BOARD_InitBootPeripherals function
 **********************************************************************************************************************/
void BOARD_InitBootPeripherals(void);

#if defined(__cplusplus)
}
#endif

#endif /* _PERIPHERALS_H_ */
