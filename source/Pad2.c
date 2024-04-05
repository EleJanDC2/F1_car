#include <stdio.h>
#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "LPC804.h"
#include "fsl_debug_console.h"

uint8_t joysticAx = 0;

uint8_t motorApwm = 0;

uint8_t direction = 0;

void setSpeed(){
	int8_t mappedSpeed = mapSpeedValue(joysticAx);

	motorApwm = abs(mappedSpeed);

	if(mappedSpeed > 0){
		GPIO_PinWrite(MOTORA_ForwardA_GPIO,
				MOTORA_ForwardA_PORT,
				MOTORA_ForwardA_PIN,
				1);
		GPIO_PinWrite(MOTORA_BackwardA_GPIO,
				MOTORA_BackwardA_PORT,
				MOTORA_BackwardA_PIN,
				0);
	}else{
		GPIO_PinWrite(MOTORA_BackwardA_GPIO,
				MOTORA_BackwardA_PORT,
				MOTORA_BackwardA_PIN,
				1);
		GPIO_PinWrite(MOTORA_ForwardA_GPIO,
				MOTORA_ForwardA_PORT,
				MOTORA_ForwardA_PIN,
				0);
	}
}

void setDirection(){
	switch(direction){
	case 0:
		GPIO_PinWrite(SERVO_TurnRight_GPIO,
				SERVO_TurnRight_PORT,
				SERVO_TurnRight_PIN,
				0);
		GPIO_PinWrite(SERVO_TurnLeft_GPIO,
				SERVO_TurnLeft_PORT,
				SERVO_TurnLeft_PIN,
				0);
		break;
	case 1:
		GPIO_PinWrite(SERVO_TurnRight_GPIO,
				SERVO_TurnRight_PORT,
				SERVO_TurnRight_PIN,
				1);
		GPIO_PinWrite(SERVO_TurnLeft_GPIO,
				SERVO_TurnLeft_PORT,
				SERVO_TurnLeft_PIN,
				0);
		break;
	case 2:
		GPIO_PinWrite(SERVO_TurnRight_GPIO,
				SERVO_TurnRight_PORT,
				SERVO_TurnRight_PIN,
				0);
		GPIO_PinWrite(SERVO_TurnLeft_GPIO,
				SERVO_TurnLeft_PORT,
				SERVO_TurnLeft_PIN,
				1);
		break;
	default:
		GPIO_PinWrite(SERVO_TurnRight_GPIO,
				SERVO_TurnRight_PORT,
				SERVO_TurnRight_PIN,
				0);
		GPIO_PinWrite(SERVO_TurnLeft_GPIO,
				SERVO_TurnLeft_PORT,
				SERVO_TurnLeft_PIN,
				0);
		break;

	}
}

void cbTimer(uint32_t flags) {
	CTIMER_UpdatePwmDutycycle(CTIMER0_PERIPHERAL,
			CTIMER0_PWM_PERIOD_CH,
			CTIMER0_PWM_0_CHANNEL,
			motorApwm);

	PRINTF("HELLO TIMER \n\r");
}

static void MasterStartTransfer(void)
{

	/* Initialize txBuffer and rxBuffer. */
	for (int i = 0; i < SPI0_BUFFER_SIZE; i++)
	{
		SPI0_txBuffer[i] = 0U;
		SPI0_rxBuffer[i] = 0U;
	}
	SPI0_txBuffer[0] = 0x01;
	SPI0_txBuffer[1] = 0x42;

	/* Start transfer data. */
	SPI_MasterTransferNonBlocking(SPI0_PERIPHERAL, &SPI0_handle, &SPI0_transfer);
}

int mapSpeedValue(int inputValue) {

	if (inputValue < 0 || inputValue > 256) {
		return -1;
	}

	// Oblicz zmapowaną wartość w zakresie -100 do 100
	int minInput = 0;
	int maxInput = 256;
	int minOutput = -100;
	int maxOutput = 100;

	// Użyj reguły proporcji, aby obliczyć zmapowaną wartość
	int mappedValue = (inputValue - minInput) * (maxOutput - minOutput) / (maxInput - minInput) + minOutput;

	return mappedValue;
}

void readingController(){
	MasterStartTransfer();

	// Czytanie wartości z kontrolera.
	for (int i = 0; i < SPI0_BUFFER_SIZE; i++)
	{
		uint8_t read = SPI0_rxBuffer[i];

		PRINTF("%X ", read);

		switch(i){
		// Informację o krzyrzaku (prawo / lewo).
		case 3:
			switch(read){
			case 255 : direction = 0; break;
			case 127 : direction = 1; break;
			case 223 : direction = 2; break;
			default: direction = 0; break;
			}
			break;

		// Informację o prawym analogu.
		case 6:
			joysticAx = read;
			break;
		}

	}

	setSpeed();

	setDirection();
}

void SysTick_Handler(void) {
	readingController();
}


int main(void) {

	/* Init board hardware. */
	BOARD_InitBootPins();
	BOARD_InitBootClocks();
	BOARD_InitBootPeripherals();
#ifndef BOARD_INIT_DEBUG_CONSOLE_PERIPHERAL
	/* Init FSL debug console. */
	BOARD_InitDebugConsole();
#endif

	for(int i=0;i<10000000;i++);

	PRINTF("START\n\r");

	SysTick_Config(SystemCoreClock / 100U); // 100 Hz

	while(1) {}

	return 0 ;
}
