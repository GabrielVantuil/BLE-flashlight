#include "handles.h"
#include "utils.h"

//APP_PWM_INSTANCE(PWM1,1);                   // Create the instance "PWM1" using TIMER1.

void timers_init(void){
    // Initialize timer module, making it use the scheduler
    APP_ERROR_CHECK(app_timer_init());
	APP_ERROR_CHECK(app_timer_create(&power_off_led_timer_id, APP_TIMER_MODE_SINGLE_SHOT, setLedOff));
}

void setLed(bool val){
	nrf_gpio_cfg_output(LED_CTRL_PIN);
    nrf_gpio_pin_write(LED_CTRL_PIN, val);
}

void setLedOff(void * p_context){
	setLed(LED_OFF);
}

void lock_handler           (uint16_t conn_handle, ble_torch_s_t * p_torch_s, uint8_t lock){
	
}

void led_power_handler      (uint16_t conn_handle, ble_torch_s_t * p_torch_s, const uint8_t *params){
	APP_ERROR_CHECK(app_timer_stop(power_off_led_timer_id));
    setLed(params[0]?LED_ON : LED_OFF);
	uint32_t timeout;
	ArrayToInt32(params, 1, timeout)
	if(timeout)	APP_ERROR_CHECK(app_timer_start(power_off_led_timer_id, APP_TIMER_TICKS(timeout), NULL));
}

void led_pwm_handler       	(uint16_t conn_handle, ble_torch_s_t * p_torch_s, const uint8_t *params){
//    app_pwm_config_t pwm1_cfg = APP_PWM_DEFAULT_CONFIG_1CH(10L, 12);
}


void connectionTimeout(void * p_context){
	sd_ble_gap_disconnect(m_conn_handle, BLE_HCI_CONN_INTERVAL_UNACCEPTABLE);
}

/**@brief Function for the LEDs initialization.
 *
 * @details Initializes all LEDs used by the application.
 */
void leds_init(void){
    setLed(LED_ON);
	nrf_delay_ms(100);
    setLed(LED_OFF);
	nrf_gpio_cfg_default(LED_CTRL_PIN);
}


/**@brief Function for handling the idle state (main loop).
 *
 * @details If there is no pending log operation, then sleep until next the next event occurs.
 */
void idle_state_handle(void){
    if (NRF_LOG_PROCESS() == false){
        nrf_pwr_mgmt_run();
    }
}

/**@brief Function for handling a Connection Parameters error.
 *
 * @param[in] nrf_error  Error code containing information about what went wrong.
 */
void conn_params_error_handler(uint32_t nrf_error){
    APP_ERROR_HANDLER(nrf_error);
}
/**@brief Function for assert macro callback.
 *
 * @details This function will be called in case of an assert in the SoftDevice.
 *
 * @warning This handler is an example only and does not fit a final product. You need to analyze
 *          how your product is supposed to react in case of Assert.
 * @warning On assert from the SoftDevice, the system can only recover on reset.
 *
 * @param[in] line_num    Line number of the failing ASSERT call.
 * @param[in] p_file_name File name of the failing ASSERT call.
 */
void assert_nrf_callback(uint16_t line_num, const uint8_t * p_file_name){
    app_error_handler(DEAD_BEEF, line_num, p_file_name);
}
