/***********************************************************************************************************************
 * This file was generated by the MCUXpresso Config Tools. Any manual edits made to this file
 * will be overwritten if the respective MCUXpresso Config Tools is used to update this file.
 **********************************************************************************************************************/

/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
!!GlobalInfo
product: Peripherals v13.0
processor: LPC804
package_id: LPC804M101JDH24
mcu_data: ksdk2_0
processor_version: 14.0.0
board: LPCXpresso804
functionalGroups:
- name: BOARD_InitPeripherals
  UUID: 4d2f4a99-7981-4376-859d-05028596f45c
  called_from_default_init: true
  selectedCore: core0
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/

/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
component:
- type: 'system'
- type_id: 'system'
- global_system_definitions:
  - user_definitions: ''
  - user_includes: ''
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/

/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
component:
- type: 'uart_cmsis_common'
- type_id: 'uart_cmsis_common_9cb8e302497aa696fdbb5a4fd622c2a8'
- global_USART_CMSIS_common:
  - quick_selection: 'default'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/

/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
component:
- type: 'gpio_adapter_common'
- type_id: 'gpio_adapter_common_57579b9ac814fe26bf95df0a384c36b6'
- global_gpio_adapter_common:
  - quick_selection: 'default'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */

/***********************************************************************************************************************
 * Included files
 **********************************************************************************************************************/
#include "peripherals.h"

/***********************************************************************************************************************
 * BOARD_InitPeripherals functional group
 **********************************************************************************************************************/
/***********************************************************************************************************************
 * SPI0 initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'SPI0'
- type: 'lpc_minispi'
- mode: 'transfer'
- custom_name_enabled: 'false'
- type_id: 'lpc_minispi_f45b6e04ed20bff9f52c4f4d863b265d'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'SPI0'
- config_sets:
  - fsl_spi:
    - spiConfig:
      - spi_mode: 'kSPI_Master'
      - clockSource: 'FunctionClock'
      - clockSourceFreq: 'BOARD_BootClockFRO18M'
      - spi_master_config:
        - baudRate_Bps: '250000'
        - clockPolarity: 'kSPI_ClockPolarityActiveLow'
        - clockPhase: 'kSPI_ClockPhaseSecondEdge'
        - direction: 'kSPI_LsbFirst'
        - dataWidth_enum: 'kSPI_Data8Bits'
        - sselNumber: 'kSPI_Ssel0Assert'
        - sselPol: 'false'
        - enableLoopback: 'false'
        - enableMaster: 'true'
        - delayConfig:
          - preDelay: '5'
          - postDelay: '5'
          - frameDelay: '0'
          - transferDelay: '0'
  - Transfer_cfg:
    - transfer:
      - init_transfer: 'true'
      - transfer_config:
        - txDataBufferEnable: 'true'
        - rxDataBufferEnable: 'true'
        - dataSize: '9'
        - configFlags: 'kSPI_EndOfTransfer'
    - init_callback: 'false'
    - callback_fcn: ''
    - user_data: ''
    - interrupt_priority:
      - IRQn: 'SPI0_IRQn'
      - enable_priority: 'false'
      - priority: '0'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */
const spi_master_config_t SPI0_config = {
  .baudRate_Bps = 250000UL,
  .clockPolarity = kSPI_ClockPolarityActiveLow,
  .clockPhase = kSPI_ClockPhaseSecondEdge,
  .direction = kSPI_LsbFirst,
  .dataWidth = 7,
  .sselNumber = kSPI_Ssel0Assert,
  .sselPolarity = kSPI_SpolActiveAllLow,
  .enableLoopback = false,
  .enableMaster = true,
  .delayConfig = {
    .preDelay = 5U,
    .postDelay = 5U,
    .frameDelay = 0U,
    .transferDelay = 0U
  }
};
uint8_t SPI0_txBuffer[SPI0_BUFFER_SIZE];
uint8_t SPI0_rxBuffer[SPI0_BUFFER_SIZE];
spi_transfer_t SPI0_transfer = {
  .txData = SPI0_txBuffer,
  .rxData = SPI0_rxBuffer,
  .dataSize = 9U,
  .configFlags = kSPI_EndOfTransfer
};
spi_master_handle_t SPI0_handle;

static void SPI0_init(void) {
  /* Initialization function */
  SPI_MasterInit(SPI0_PERIPHERAL, &SPI0_config, SPI0_CLOCK_SOURCE);
  SPI_MasterTransferCreateHandle(SPI0_PERIPHERAL, &SPI0_handle, NULL, NULL);
}

/***********************************************************************************************************************
 * CTIMER0 initialization code
 **********************************************************************************************************************/
/* clang-format off */
/* TEXT BELOW IS USED AS SETTING FOR TOOLS *************************************
instance:
- name: 'CTIMER0'
- type: 'ctimer'
- mode: 'PWM'
- custom_name_enabled: 'false'
- type_id: 'ctimer_72ecb1f82fe6700da71dde4e8bc60e39'
- functional_group: 'BOARD_InitPeripherals'
- peripheral: 'CTIMER0'
- config_sets:
  - fsl_ctimer:
    - ctimerConfig:
      - mode: 'kCTIMER_TimerMode'
      - clockSource: 'FunctionClock'
      - clockSourceFreq: 'BOARD_BootClockFRO18M'
      - timerPrescaler: '1'
    - EnableTimerInInit: 'true'
    - pwmConfig:
      - pwmPeriodChannel: 'kCTIMER_Match_3'
      - pwmPeriodValueStr: '10000'
      - enableInterrupt: 'true'
      - pwmChannels:
        - 0:
          - pwmChannelPrefixId: 'PWM_0'
          - pwmChannel: 'kCTIMER_Match_0'
          - pwmDutyValueStr: '9000'
          - enableInterrupt: 'false'
    - interruptCallbackConfig:
      - interrupt:
        - IRQn: 'CTIMER0_IRQn'
        - enable_priority: 'false'
        - priority: '0'
      - callback: 'kCTIMER_SingleCallback'
      - singleCallback: 'cbTimer'
 * BE CAREFUL MODIFYING THIS COMMENT - IT IS YAML SETTINGS FOR TOOLS **********/
/* clang-format on */
const ctimer_config_t CTIMER0_config = {
  .mode = kCTIMER_TimerMode,
  .input = kCTIMER_Capture_0,
  .prescale = 0
};
/* Single callback functions definition */
ctimer_callback_t CTIMER0_callback[] = {cbTimer};

static void CTIMER0_init(void) {
  /* CTIMER0 peripheral initialization */
  CTIMER_Init(CTIMER0_PERIPHERAL, &CTIMER0_config);
  /* PWM channel 0 of CTIMER0 peripheral initialization */
  CTIMER_SetupPwmPeriod(CTIMER0_PERIPHERAL, CTIMER0_PWM_PERIOD_CH, CTIMER0_PWM_0_CHANNEL, CTIMER0_PWM_PERIOD, CTIMER0_PWM_0_DUTY, false);
  /* Enable interrupt of PWM channel 3 that determinates the PWM period */
  CTIMER_EnableInterrupts(CTIMER0_PERIPHERAL, kCTIMER_Match3InterruptEnable);
  CTIMER_RegisterCallBack(CTIMER0_PERIPHERAL, CTIMER0_callback, kCTIMER_SingleCallback);
  /* Enable interrupt CTIMER0_IRQn request in the NVIC. */
  EnableIRQ(CTIMER0_TIMER_IRQN);
  /* Start the timer */
  CTIMER_StartTimer(CTIMER0_PERIPHERAL);
}

/***********************************************************************************************************************
 * Initialization functions
 **********************************************************************************************************************/
void BOARD_InitPeripherals(void)
{
  /* Initialize components */
  SPI0_init();
  CTIMER0_init();
}

/***********************************************************************************************************************
 * BOARD_InitBootPeripherals function
 **********************************************************************************************************************/
void BOARD_InitBootPeripherals(void)
{
  BOARD_InitPeripherals();
}
