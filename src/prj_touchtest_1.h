#ifndef _PRJ_TOUCHTEST_1_H_
  #define _PRJ_TOUCHTEST_1_H_

  #include <Arduino.h>
  #include <md_defines.h>
  #include <project.h>

  // ******************************************
    // --- debugging
      #define DEBUG_MODE      CFG_DEBUG_STARTUP
        //#define DEBUG_MODE      CFG_DEBUG_NONE
        //#define DEBUG_MODE      CFG_DEBUG_ACTIONS
        //#define DEBUG_MODE      CFG_DEBUG_DETAILS

    // --- SW config
      #define USE_TASKING           ON
      #define USE_LED_BLINK_OUT     OFF
    // --- system components and devices
      #define DEV_I2C1              ON  // ON
      #define DEV_I2C2              OFF
      #define DEV_VSPI              ON
      #define DEV_HSPI              OFF
      #define DEV_PWM_OUTPUT        ON
      #define DEV_ADC_INT           1
        //#define DEV_ADC_ADS1115       OFF
        //#define DEV_ADC_ADS1115_1     OFF
        //#define DEV_ADC_ADS1115_2     OFF
        //#define DEV_ADC_ADS1115_3     OFF
        //#define DEV_ADC_ADS1115_4     OFF
    // --- user output components
      #define USE_WS2812_PWR_IN_SW  OFF                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                         // some time matrix and line not allowed
      // --- displays
        #define USE_DISP              1
          // OLEDs
            #define USE_OLED_I2C      OFF
          // TFTs
            #define USE_TFT           1
              // MC_UO_TFT1602_GPIO_RO, MC_UO_TOUCHXPT2046_AZ_UNO, MC_UO_TXPT2046_AZ_SPI
              // MC_UO_TFT1602_I2C_XA,  MC_UO_Keypad_ANA0_RO
      // buzzer
        #define USE_BUZZER_PWM        OFF
      // --- PWM output
        #define USE_FAN_PWM           OFF   // 2
        #define USE_OUT_FREQ_PWM      OFF // 1
      // --- LED output
        #define USE_TRAFFIC_LED_OUT   OFF
        #define USE_RGBLED_PWM        OFF
        #define USE_WS2812_MATRIX_OUT OFF // [0, 1..4]
        #define USE_WS2812_LINE_OUT   OFF // [0, 1..4]
      // --- digital output
        #define USE_GEN_DIG_OUT       OFF
    // --- user input components
      // --- touchscreen ---
        #define USE_TOUCHSCREEN     ON
        #define USE_MD_ATSMARTHOME  OFF // codesize to much
        // MC_UI_TXPT2046_AZ_SPI, MC_UI_TXPT2046_AZ_UNO
      // --- keypads ---
        #define USE_KEYPADSHIELD    OFF
        // MC_UI_Keypad_ANA0_RO
      #define USE_GEN_SW_INP        OFF // 1
      #define USE_GEN_CNT_INP       OFF // 1
      #define USE_GEN_PWM_INP       OFF // 2
    // --- sensors
      #define USE_ESPHALL           OFF
      #define USE_DS18B20_1W_IO     OFF // [0, 1, ....] limited by 1W connections
      #define USE_CCS811_I2C        OFF // [0, 1, ....] limited by I2C channels/addr
      #define USE_BME280_I2C        OFF // [0, 1, ....] limited by I2C channels/addr
      #define USE_BME680_I2C        1   // [0, 1, ....] limited by I2C channels/addr
      #define USE_TYPE_K_SPI        OFF // [0, 1, ....] limited by Pins
      #define USE_MQ135_GAS_ANA     OFF // [0, 1, ....] limited by analog inputs
      #define USE_MQ3_ALK_ANA       OFF // ADC or ADS1115
      #define USE_PHOTO_SENS_ANA    OFF // ADC or ADS1115
      #define USE_INA3221_I2C       OFF
      #define USE_ACS712_ANA        OFF // only ADS1115
      #define USE_POTI_ANA          OFF // ADC or ADS1115
      #define USE_VCC50_ANA         OFF // ADC or ADS1115
      #define USE_VCC33_ANA         OFF // ADC or ADS1115
      #define USE_ADC1115_I2C       OFF // ADC 4 channels 16Bit
    // --- network  components
      #define USE_WIFI              ON  // ON
      //#define USE_ATWIFI            OFF  // ON
      #define USE_NTP_SERVER        ON  // ON
      #define USE_BTOOTH            OFF
      #define USE_LOCAL_IP          ON  // ON
      #define USE_WEBSERVER         ON  // ON
      #define USE_MQTT              ON
    // --- memory components
      #define USE_FLASH_MEM         ON
      #define USE_FRAM_I2C          OFF   // 1   // [0, 1, ...] limited by I2C channel/addr
      #define USE_SD_SPI            ON
    // --- test components
      #define USE_CTRL_POTI         OFF   // [0, 1, ....] limited by analog inputs
      #define USE_CTRL_SW_INP       OFF // 1   // [0, 1, ....] limited by digital pins
    // --- devices
      #define USE_BLUETTI           OFF
    // usage of peripherals
      #define USE_PWM_OUT           3 * USE_RGBLED_PWM + USE_FAN_PWM + USE_OUT_FREQ_PWM + USE_BUZZER_PWM // max 16
      #define USE_CNT_INP           USE_GEN_CNT_INP     // max 2 * 8 independent
      #define USE_PWM_INP           USE_GEN_PWM_INP
      #define USE_VCC_ANA           USE_VCC50_ANA + USE_VCC33_ANA
      // #define USE_ADC1              USE_KEYPADSHIELD_ADC + USE_MQ135_GAS_ADC + USE_CTRL_POTI_ADC + USE_PHOTO_SENS
      // #define USE_ADC2              OFF // not to use
      #define USE_DIG_INP           USE_GEN_SW_INP + USE_CTRL_SW_INP + USE_WS2812_PWR_IN_SW    //
      #define USE_DIG_OUT           USE_WS2812_LINE_OUT + USE_LED_BLINK_OUT //
      #define USE_DIG_IO            USE_DS18B20_1W_IO     //
      #define USED_IOPINS           USE_DIG_INP + USE_DIG_OUT + USE_DIG_IO + (2 * USE_I2C) + USED_SPI_PINS + USE_PWM_OUT + USE_CNT_INP + USE_ADC1

    // to be reorganised
        #if (USE_KEYPADSHIELD > OFF)
            #define USE_TFT1602_GPIO_RO_V5  // used by KEYPADSHIELD
            #define KEYS_Keypad_ANA0_RO_V5        // used by KEYPADSHIELD
            #define KEYS            ?
          #endif // USE_KEYPADSHIELD

      //#define USE_TOUCHSCREEN     (3 * USE_TRAFFIC_LED_OUT) +USE_TOUCHSCREEN_SPI + USE_TOUCHSCREEN_OUT
        #if (USE_TOUCHSCREEN > OFF)
            #define TOUCHSCREEN1     TOUCHXPT2046_AZ_3V3
            //#define TOUCHKEYS1       KEYS_TOUCHXPT2046_AZ_3V3
          #endif // USE_TOUCHSCREEN

#endif // _PRJ_TOUCHTEST_1_H_