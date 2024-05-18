#ifndef BOARD_NHW003_H
#define BOARD_NHW003_H

#ifdef __cplusplus
extern "C" {
#endif

#include "nrf_gpio.h"

#define LED_ON      0
#define LED_OFF     1

// LEDs definitions
#define LED_ENABLE_PIN  27
#define LED_RED_PIN	    31
#define LED_GREEN_PIN   30
#define LED_BLUE_PIN    29

#define LEDS_NUMBER     3
#define LED_START      LED_RED_PIN
#define LED_1          LED_RED_PIN
#define LED_2          LED_GREEN_PIN
#define LED_3          LED_BLUE_PIN
//#define LED_4          20
#define LED_STOP       20

#define LEDS_ACTIVE_STATE 0

#define LEDS_INV_MASK  LEDS_MASK

#define LEDS_LIST { LED_1, LED_2, LED_3/*, LED_4*/}

#define BSP_LED_0      LED_1
#define BSP_LED_1      LED_2
#define BSP_LED_2      LED_3
#define BSP_LED_3      LED_4

#define BUTTONS_NUMBER 4

//#define BUTTON_START   13
#define BUTTON_1       28
//#define BUTTON_2       14
//#define BUTTON_3       15
//#define BUTTON_4       16
//#define BUTTON_STOP    16
#define BUTTON_PULL    NRF_GPIO_PIN_PULLUP

#define BUTTONS_ACTIVE_STATE 0

#define BUTTONS_LIST { BUTTON_1/*, BUTTON_2, BUTTON_3, BUTTON_4 */}

#define BSP_BUTTON_0   BUTTON_1
//#define BSP_BUTTON_1   BUTTON_2
//#define BSP_BUTTON_2   BUTTON_3
//#define BSP_BUTTON_3   BUTTON_4

#define RX_PIN_NUMBER  14
#define TX_PIN_NUMBER  18
#define CTS_PIN_NUMBER 11//7
#define RTS_PIN_NUMBER 15

#define HWFC           true

#define SPIS_MISO_PIN   28  // SPI MISO signal.
#define SPIS_CSN_PIN    12  // SPI CSN signal.
#define SPIS_MOSI_PIN   25  // SPI MOSI signal.
#define SPIS_SCK_PIN    29  // SPI SCK signal.

#define SPIM0_SCK_PIN   29  // SPI clock GPIO pin number.
#define SPIM0_MOSI_PIN  25  // SPI Master Out Slave In GPIO pin number.
#define SPIM0_MISO_PIN  28  // SPI Master In Slave Out GPIO pin number.
#define SPIM0_SS_PIN    12  // SPI Slave Select GPIO pin number.

#define SPIM1_SCK_PIN   2   // SPI clock GPIO pin number.
#define SPIM1_MOSI_PIN  3   // SPI Master Out Slave In GPIO pin number.
#define SPIM1_MISO_PIN  4   // SPI Master In Slave Out GPIO pin number.
#define SPIM1_SS_PIN    5   // SPI Slave Select GPIO pin number.

#define SPIM2_SCK_PIN   12  // SPI clock GPIO pin number.
#define SPIM2_MOSI_PIN  13  // SPI Master Out Slave In GPIO pin number.
#define SPIM2_MISO_PIN  14  // SPI Master In Slave Out GPIO pin number.
#define SPIM2_SS_PIN    15  // SPI Slave Select GPIO pin number.

//// serialization APPLICATION board - temp. setup for running serialized MEMU tests
//#define SER_APP_RX_PIN              23    // UART RX pin number.
//#define SER_APP_TX_PIN              24    // UART TX pin number.
//#define SER_APP_CTS_PIN             2     // UART Clear To Send pin number.
//#define SER_APP_RTS_PIN             25    // UART Request To Send pin number.

#define SER_APP_SPIM0_SCK_PIN       27     // SPI clock GPIO pin number.
#define SER_APP_SPIM0_MOSI_PIN      2      // SPI Master Out Slave In GPIO pin number
#define SER_APP_SPIM0_MISO_PIN      26     // SPI Master In Slave Out GPIO pin number
#define SER_APP_SPIM0_SS_PIN        23     // SPI Slave Select GPIO pin number
#define SER_APP_SPIM0_RDY_PIN       25     // SPI READY GPIO pin number
#define SER_APP_SPIM0_REQ_PIN       24     // SPI REQUEST GPIO pin number

//// serialization CONNECTIVITY board
//#define SER_CON_RX_PIN              24    // UART RX pin number.
//#define SER_CON_TX_PIN              23    // UART TX pin number.
//#define SER_CON_CTS_PIN             25    // UART Clear To Send pin number. Not used if HWFC is set to false.
//#define SER_CON_RTS_PIN             2     // UART Request To Send pin number. Not used if HWFC is set to false.


#define SER_CON_SPIS_SCK_PIN        27    // SPI SCK signal.
#define SER_CON_SPIS_MOSI_PIN       2     // SPI MOSI signal.
#define SER_CON_SPIS_MISO_PIN       26    // SPI MISO signal.
#define SER_CON_SPIS_CSN_PIN        23    // SPI CSN signal.
#define SER_CON_SPIS_RDY_PIN        25    // SPI READY GPIO pin number.
#define SER_CON_SPIS_REQ_PIN        24    // SPI REQUEST GPIO pin number.

#define SER_CONN_CHIP_RESET_PIN     11    // Pin used to reset connectivity chip



#ifdef __cplusplus
}
#endif

#endif // BOARD_NHW003_H
