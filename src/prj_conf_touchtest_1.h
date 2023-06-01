#ifndef _PRJ_CONF_TOUCHTEST_1_H_
  #define _PRJ_CONF_TOUCHTEST_1_H_

  #include <Arduino.h>
  #include <md_defines.h>
  #include <prj_touchtest_1.h>

  // ******************************************
    // --- test features --------------------------------
      #define TEST_SOCKET_SERVER    OFF
      #define TEST_RGBLED_PWM       OFF
      #define USE_WEBCTRL_RGB       OFF
      #define USE_WEBCTRL_FAN       OFF
      #define USE_POTICTRL_RGB      OFF
      #define USE_POTICTRL_FAN      OFF
      #define USE_SWCTRL_RGB        OFF
      #define USE_SWCTRL_FAN        OFF
      #define USE_SWCTRL_1812       OFF
  // ******************************************
  // ******************************************
  // --- specification first to define device config
    // --- system
      // --- error status bits
        #define ERRBIT_TOUCH      0x00000001     // touchscreen
        #define ERRBIT_SERVER     0x00000002     // webserver
        #define ERRBIT_WIFI       0x00000004     // WIFI connection
        #define ERRBIT_NTPTIME    0x00000008     // NTP timeserver connection
      // --- generic
        #define SCAN_I2C          ON // 128
        #define TEST_NUM_CONVERT  OFF
        #define CHECK_I2C_DEVICES
        //#define UTC_SEASONTIME UTC_WINTERTIME
        #define UTC_SEASONTIME UTC_SUMMERTIME
        #if (USE_TASKING > 0)
            #define USE_SONGTASK
            #define TASK_SLICE_T  5000ul   // task beat [us]
          #endif // USE_TASKING
        #if (USE_LED_BLINK_OUT > 0)
            #define BLINKTIME_MS  1200ul
            #define BLINKPWM_FREQ 400
            #define BLINKPWM_RES  8
          #endif

    // --- I2C interface
      // --- address configuration
        #if (USE_OLED_I2C > OFF)
            #define OLED1_I2C_ADDR  I2C_OLED_3C
            #define OLED1_I2C       I2C1
            #if (USE_OLED_I2C > 1)
                #define OLED2_I2C_ADDR  I2C_OLED_3C
                #define OLED2_I2C       I2C2
              #endif
          #endif
        #if (USE_FRAM_I2C > OFF)
            #define FRAM1_I2C_ADDR      I2C_FRAM_50
            #define FRAM1_SIZE          0x8000
            #define FRAM1_I2C           I2C1
            #if (USE_FRAM_I2C > 1 )
                #define FRAM2_I2C_ADDR  I2C_FRAM_50
                #define FRAM1_SIZE      0x8000
                #define FRAM2_I2C       I2C2
              #endif
          #endif
        #if (USE_CCS811_I2C > OFF )
            #define CCS811_I2C_ADDR     I2C_CSS811_
            #define CCS811_I2C          I2C1
          #endif
        #if (USE_BME280_I2C > OFF )
            #define BME280_I2C         I2C1
          #endif
        #if (USE_BME680_I2C > OFF )
            #define BME680_I2C         I2C1
          #endif
#ifdef UNUSED
          #if (USE_ADC1115_I2C > OFF)
              #ifndef USE_INPUT_CYCLE
                  #define USE_INPUT_CYCLE
                #endif
              #define ADC1115_I2C          I2C1
              #define ADC1115_1_ADDR       I2C_ADS1115_48
              #define ADC1115_1_CHIDXS      4
              #if (USE_ADC1115_I2C > 1)
                  #define ADC1115_2_ADDR   I2C_ADS1115_48 //I2C_ADS1115_49
                  #define ADC1115_2_CHIDXs  4
                  #if (USE_ADC1115_I2C > 2)
                      #define ADC1115_3_ADDR   I2C_ADS1115_48 //I2C_ADS1115_4A
                      #define ADC1115_3_CHIDXs  4
                      #if (USE_ADC1115_I2C > 3)
                          #define ADC1115_4_ADDR   I2C_ADS1115_48 //I2C_ADS1115_4B
                          #define ADC1115_4_CHIDXs  4
                        #endif
                    #endif
                #endif
            #endif
#endif
    // --- network
      // --- WIFI
        #if (USE_WIFI > OFF)
            #define WIFI_MAX_LEN    20
            #define WIFI_ANZ_LOGIN  8
            #define WIFI_IS_DUTY    ON
            #define WIFI_SSID0      "M&M_mobil"   // Bauwagen
            #define WIFI_SSID0_PW   "ElaNanniRalf3"
            #define WIFI_SSID1      "MAMD-HomeG"  // WLAN Moosgrabenstrasse 26
            #define WIFI_SSID1_PW   "ElaNanniRalf3"
            #define WIFI_SSID2      "HS-HomeG"    // WLAN Am Jungberg 9
            #define WIFI_SSID2_PW   "ElaNanniRalf3"
            #define WIFI_SSID3      "WL-Fairnetz" //Weltladen
            #define WIFI_SSID3_PW   "WL&Fair2Live#"
            #define WIFI_SSID4      "MachNet"     //machQuadrat
            #define WIFI_SSID4_PW   "!Machquadrat1"
            #define WIFI_SSID5      "MD_KingKong" //Hotspot Martin
            #define WIFI_SSID5_PW   "ElaNanniRalf3"
            #define WIFI_SSID6      "CDWiFi"      //OEBB Raijet
            #define WIFI_SSID6_PW   ""
            #define WIFI_SSID7      "xWIFI@DB"    //DB ICE
            #define WIFI_SSID7_PW   ""
            #define WIFI_SSID8      ""    // ?
            #define WIFI_SSID8_PW   ""
            #define WIFI_SSID9      ""    // ?
            #define WIFI_SSID9_PW   ""
            #define WIFI_CONN_DELAY 500000ul // Scan-Abstand [us]
            #define WIFI_CONN_REP   5        // Anzahle der Connect-Schleifen
            #define WIFI_CONN_CYCLE 4000ul   // Intervallzeit fuer Recoonect [us]
            #define NTPSERVER_CYCLE 1000ul   // Intervallzeit [us]

            #define WIFI_ANZ_LOCIP  WIFI_ANZ_LOGIN
            #if   !(BOARD ^ MC_ESP32_Node)
                  #define WIFI_FIXIP0     0x1800A8C0ul // 192.168.0.24   lowest first
                  #define WIFI_FIXIP1     0x1900000Aul // 10.0.0.25
            #elif !(BOARD ^ MC_ESP32_D1_MINI)
                   #define WIFI_FIXIP1    0x1A00000Aul // 10.0.0.26
            #elif !(BOARD ^ MC_ESP32_D1_R32)
                  #define WIFI_FIXIP1     0x1B00000Aul // 10.0.0.27   lowest first
            #elif !(BOARD ^ MC_ESP32_AZTOUCH)
                  #define WIFI_FIXIP0     0x1900A8C0ul // 192.168.0.25   lowest first
                  #define WIFI_FIXIP1     0x1900000Aul // 10.0.0.25
              #endif
            #ifdef USE_LOCAL_IP
                #define WIFI_GATEWAY0     0x0100A8C0ul // 192.168.0.1     // Bauwagen
                #define WIFI_GATEWAY1     0x8B00000Aul // 10.0.0.139      // Moosgraben
                #define WIFI_GATEWAY2     0x8B00000Aul // 10.0.0.139      // Jungberg
                #define WIFI_FIXIP2       0x1800000Aul // 10.0.0.24
                #define WIFI_GATEWAY3     0x8a00000Aul // 10.0.0.138      // Weltladen
                #define WIFI_FIXIP3       0x1600000Aul // 10.0.0.22
                #define WIFI_GATEWAY4     0x01250D0Aul // 10.0.0.1        // machquadrat
                #define WIFI_FIXIP4       0x6F250D0Aul // 10.0.0.22
                #define WIFI_GATEWAY5     0x012BA8C0ul // 192.168.43.154  // hotspot KingKong
                #define WIFI_FIXIP5       0x162BA8C0ul // 192.168.43.22
                #define WIFI_GATEWAY6     0x0926A8C0ul // 192.168.32.1    // OEBB Railjet
                #define WIFI_FIXIP6       0x1620A8C0ul // 192.168.32.22
                #define WIFI_GATEWAY7     0x01AE12ACul // 172.18.0.1      // DB ICE
                #define WIFI_FIXIP7       0x16AE12ACul // 172.18.174.22
                #define WIFI_GATEWAY8     0x0100000Aul // 10.0.0.10       // ?
                #define WIFI_FIXIP8       0x1600000Aul // 10.0.0.22       // ?
                #define WIFI_GATEWAY9     0x0100000Aul // 10.0.0.1        // ?
                #define WIFI_FIXIP9       0x1600000Aul // 10.0.0.22       // ?
                #define WIFI_SUBNET       0x00FFFFFFul // 255.255.255.0
              #endif
          #endif
      // --- webserver
        #if (USE_WEBSERVER > OFF)
            #define WEBSERVER_CYCLE       1000ul  // Intervallzeit [us]
          #endif
      // --- MQTT Mosquitto client
        #if (USE_MQTT > OFF)
            #define MQTT_HOST             "10.0.0.203"
            #define MQTT_PORT             1883
            #define MQTT_SECURE           OFF
            #define MQTT_DEVICE           "esp-24"
            #define MQTT_TOPDEV           "esp-24/"
            #define MQTT_TOPIC_MAXLEN     20
            #define MQTT_PAYLOAD_MAXLEN   20
            #define MQTT_MSG_MAXANZ       10
            typedef struct MQTT_MSG
              {
                char  topic[MQTT_TOPIC_MAXLEN];
                char  payload[MQTT_PAYLOAD_MAXLEN];
                void* pNext;
              } MQTTmsg_t;
            #if(MQTT_SECURE > OFF)
                #define MQTT_BROKER_USER  "<user>"
                #define MQTT_BROKER_PASS  "<pass>"
              #endif
          #endif
    // --- user output
      // --- display
        #if (USE_DISP > 0)
            #define USE_STATUS
            #if (USE_OLED_I2C > OFF)
                // select OLED - device & GEO   GEO_RAWMODE?
                          // MC_UO_OLED_066_AZ   GEO_64_48    OLED_DRV_1306
                          // MC_UO_OLED_091_AZ   GEO_128_32   OLED_DRV_1306
                          // MC_UO_OLED_096_AZ   GEO_128_64   OLED_DRV_1306
                          // MC_UO_OLED_130_AZ   GEO_128_64   OLED_DRV_1106
                #define OLED1_I2C_TYP MC_UO_OLED_130_AZ  // OLED1 on I2C1
                #define OLED1_STATUS     ON
                #define OLED1_I2C        I2C1
                #if !(OLED1_I2C_TYP ^ MC_UO_OLED_066_AZ)
                    #define OLED1_MAXCOLS  OLED_066_MAXCOLS
                    #define OLED1_MAXROWS  OLED_066_MAXROWS
                    #define OLED1_GEO      GEO_64_48
                    #define OLED1_DRV      OLED_DRV_1306
                  #endif
                #if !(OLED1_I2C_TYP ^ MC_UO_OLED_091_AZ)
                    #define OLED1_MAXCOLS  OLED_091_MAXCOLS
                    #define OLED1_MAXROWS  OLED_091_MAXROWS
                    #define OLED1_GEO      GEO_128_32
                    #define OLED1_DRV      OLED_DRV_1306
                  #endif
                #if !(OLED1_I2C_TYP ^ MC_UO_OLED_096_AZ)
                    #define OLED1_MAXCOLS  OLED_096_MAXCOLS
                    #define OLED1_MAXROWS  OLED_096_MAXROWS
                    #define OLED1_GEO      GEO_128_64
                    #define OLED1_DRV      OLED_DRV_1306
                  #endif
                #if !(OLED1_I2C_TYP ^ MC_UO_OLED_130_AZ)
                    #define OLED1_MAXCOLS         OLED_130_MAXCOLS
                    #define OLED1_MAXROWS         OLED_130_MAXROWS
                    #define OLED1_GEO             GEO_128_64
                    #define OLED1_DRV             OLED_DRV_1106
                  #endif

                #if ( USE_OLED_I2C > 1 )
                    #define OLED2_I2C_TYP         MC_UO_OLED_130_AZ  // OLED1 on I2C1
                    #define USE_STATUS2           ON
                    #define OLED2_I2C        I2C1
                    #if !(OLED2_I2C_TYP ^ MC_UO_OLED_066_AZ)
                        #define OLED2_MAXCOLS OLED_066_MAXCOLS
                        #define OLED2_MAXROWS OLED_066_MAXROWS
                        #define OLED2_GEO     GEO_64_48
                        #define OLED2_DRV     OLED_DRV_1306
                      #endif
                    #if !(OLED2_I2C_TYP ^ MC_UO_OLED_091_AZ)
                        #define OLED2_MAXCOLS OLED_091_MAXCOLS
                        #define OLED2_MAXROWS OLED_091_MAXROWS
                        #define OLED2_GEO     GEO_128_32
                        #define OLED2_DRV     OLED_DRV_1306
                      #endif
                    #if !(OLED2_I2C_TYP ^ MC_UO_OLED_096_AZ)
                        #define OLED2_MAXCOLS  OLED_096_MAXCOLS
                        #define OLED2_MAXROWS  OLED_096_MAXROWS
                        #define OLED2_GEO      GEO_128_64
                        #define OLED2_DRV      OLED_DRV_1306
                      #endif
                    #if !(OLED2_I2C_TYP ^ MC_UO_OLED_130_AZ)
                        #define OLED2_MAXCOLS  OLED_130_MAXCOLS
                        #define OLED2_MAXROWS  OLED_130_MAXROWS
                        #define OLED2_GEO      GEO_128_64
                        #define OLED2_DRV      OLED_DRV_1106
                      #endif
                  #else
                    #define OLED2_I2C       OFF  //
                  #endif

              #endif
            #if ( USE_TOUCHSCREEN > 0 )
                //
              #endif
            #if (USE_MD_ATSMARTHOME > OFF)
                //file names used with SPIFFS do not remove the starting slash!
                #define ATDEVICEFILE "/devices.txt"
                #define ATCONFIGFILE "/config.txt"
                #define RCPIN 16
                //Format flash file system if not already done

              #endif
            #if ( USE_TFT > 0 )
                #if !(DISP_TFT ^ MC_UO_TOUCHXPT2046_AZ)
                    // generell
                      #define USE_TOUCH_SPI  ON
                      #define TOUCHSIZE      24
                          // 0:USB oben, 1:USB links, 2:USB unten, 3:USB rechts
                        #if (TOUCHSIZE == 24)
                          #define TOUCH_ROTATION 2 //muss fuer 2.4 Zoll Display 1/2 und fuer 2.8 Zoll Display 3/0 sein
                        #else
                          #define TOUCH_ROTATION 3 //muss fuer 2.4 Zoll Display 1/2 und fuer 2.8 Zoll Display 3/0 sein
                        #endif
                      #define DATE_DISP_COL  0
                      #define DATE_DISP_LINE 9      // line on display for date / time
                    // text display area
                      #define DISP_X         0
                      #define DISP_Y         0
                      #if (TOUCH_ROTATION == 0 || TOUCH_ROTATION ==2)
                          #define DISP_W     240
                          #define DISP_H     320
                      #else
                          #define DISP_W     320
                          #define DISP_H     240
                        #endif
                      #define DISP_BCOL      0x000F // TFT_NAVY
                      #define DISP_ANZ_SP    20
                      #define DISP_ANZ_ZE    12
                      #define DISP_Hoe_ZE    25
                      #define DISP_TX_FCOL   0xB7E0 // TFT_GREENYELLOW
                      #define DISP_TX_BCOL   DISP_BCOL
                    // status line for messages
                      #define USE_STAT_TOUCH 1
                      #define STATUS_XCENT   DISP_H/2 // Centred on this
                      #define STATUS_YCENT   DISP_W - 5
                      #define STATUS_XLI     0
                      #define STATUS_XRE     DISP_W - 1
                      #define STATUS_YOB     DISP_H // 300
                      #define STATUS_YUN     Disp_H - 1
                      #define STATUS_FCOL    0xF81F // TFT_MAGENTA
                      #define STATUS_BCOL    0x0000 // TFT_BLACK
                    //layout
                      #define BACKGROUND ILI9341_GREENYELLOW //Farbe des Rahmens
                      #define TOPMARGIN 20                   //Rand oben
                      #define LEFTMARGIN 12                  //Rand links und rechts
                      #define COLUMNS 12                     //Anzahl der Spalten
                      #define ROWS 16                        //Anzahl der Zeilen
                      #define BLOCKSIZE 18                   //Groesse eines Blocks in Pixel
                      #define NOPIECE ILI9341_BLACK          //Farb fuer das leere Spielfeld
                      #define ALLON ILI9341_DARKGREY         //Farbe fuer alle Bloecke ein
                      #define BORDER ILI9341_WHITE           //Farbe fuer den Blockrand
                      /* Bitmuster fuer die Teile
                         0 = Block nicht gesetzt >0 Index der Farbe f�r den Block
                        */
                      const uint8_t piece[20][16] =
                        {
                          { 0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0 },
                          { 0, 0, 0, 0,  0, 0, 0, 0,  1, 1, 0, 0,  1, 1, 0, 0 },
                          { 0, 2, 0, 0,  0, 2, 0, 0,  0, 2, 0, 0,  0, 2, 0, 0 },
                          { 0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 0, 0,  2, 2, 2, 2 },
                          { 0, 0, 0, 0,  0, 0, 0, 0,  3, 3, 0, 0,  0, 3, 3, 0 },
                          { 0, 0, 0, 0,  0, 3, 0, 0,  3, 3, 0, 0,  3, 0, 0, 0 },
                          { 0, 0, 0, 0,  0, 0, 0, 0,  0, 4, 4, 0,  4, 4, 0, 0 },
                          { 0, 0, 0, 0,  4, 0, 0, 0,  4, 4, 0, 0,  0, 4, 0, 0 },
                          { 0, 0, 0, 0,  5, 0, 0, 0,  5, 0, 0, 0,  5, 5, 0, 0 },
                          { 0, 0, 0, 0,  0, 0, 0, 0,  0, 0, 5, 0,  5, 5, 5, 0 },
                          { 0, 0, 0, 0,  5, 5, 0, 0,  0, 5, 0, 0,  0, 5, 0, 0 },
                          { 0, 0, 0, 0,  0, 0, 0, 0,  5, 5, 5, 0,  5, 0, 0, 0 },
                          { 0, 0, 0, 0,  0, 6, 0, 0,  0, 6, 0, 0,  6, 6, 0, 0 },
                          { 0, 0, 0, 0,  0, 0, 0, 0,  6, 6, 6, 0,  0, 0, 6, 0 },
                          { 0, 0, 0, 0,  6, 6, 0, 0,  6, 0, 0, 0,  6, 0, 0, 0 },
                          { 0, 0, 0, 0,  0, 0, 0, 0,  6, 0, 0, 0,  6, 6, 6, 0 },
                          { 0, 0, 0, 0,  0, 0, 0, 0,  0, 7, 0, 0,  7, 7, 7, 0 },
                          { 0, 0, 0, 0,  0, 7, 0, 0,  7, 7, 0, 0,  0, 7, 0, 0 },
                          { 0, 0, 0, 0,  0, 0, 0, 0,  7, 7, 7, 0,  0, 7, 0, 0 },
                          { 0, 0, 0, 0,  0, 7, 0, 0,  0, 7, 7, 0,  0, 7, 0, 0 }
                        };
                  #endif
                //
                #if !(DISP_TFT ^ MC_UO_TFT1602_GPIO_RO)
                    #define DATE_DISP_COL   0
                    #define DATE_DISP_LINE  0    // line on display for date / time
                    #define LCD_ROWS        2
                    #define LCD_CULS        2
                  #endif
              #endif
          #endif // DISP
      // --- acoustic output
        #if (USE_BUZZER_PWM > OFF)
            #define PLAY_MUSIC
            #define MUSIC_BASE_OCTA 5        // base oktave for musik
            //#define PLAY_START_MUSIC
            #define PLAY_START_DINGDONG
          #endif // USE_BUZZER_PWM

      // WS2812 LEDs
        #if (USE_WS2812_MATRIX_OUT > OFF)
            #define COLCHAR_2812            6
            #define COLBMP_2812             8
            #define ROWBMP_2812             8
            #define UPD_2812_M1_MS          70
            //#define COL24_2812_M1           0xFF0000u   // 0xB924u   // color r-g-b (5-6-5)
            //#define COL24_2812_BM1          0x00FF00u   // color r-g-b (5-6-5)
            #define COL24_2812_M1           0xFF0080u   // color r-g-b (5-6-5) = 255,0,128
            #define COL24_2812_BM1          0xF0B63Cu   // color r-g-b (5-6-5) = 240, 182, 56
            #define BRI_2812_M1             255
            #define BRI_2812_BM1            255
            #define ROW1_2812_M1            NEO_MATRIX_TOP
            #define COL1_2812_M1            NEO_MATRIX_LEFT
            #define DIR_2812_M1             NEO_MATRIX_COLUMNS
            #define ORI_2812_M1             NEO_MATRIX_ZIGZAG
            #define TYPE_2812_M1            WS2812B
            #define COLORD_2812_M1          NEO_GRB
            #define ROWPIX_2812_M1          8
            #define LEDS_2812_M1            COLPIX_2812_M1 * ROWPIX_2812_M1
            #define ROW1_2812_T1            NEO_MATRIX_TOP
            #define COL1_2812_T1            NEO_MATRIX_LEFT
            #define DIR_2812_T1             NEO_MATRIX_COLUMNS
            #define ORI_2812_T1             NEO_MATRIX_ZIGZAG
            #define COLPIX_2812_T1          8
            #define ROWPIX_2812_T1          8
            #define COLTIL_2812_M1          16  // needs correct value
            #define ROWTIL_2812_M1          1   // 0 = OFF
            #define ANZ_TILES_M1            COLTIL_2812_M1 * ROWPIX_2812_T1
            #define COLPIX_2812_M1          COLTIL_2812_M1 * COLPIX_2812_T1
            #define OFFBEG_2812_M1          1 //+ COLPIX_2812_T1
            #define OFFEND_2812_M1          0 //+ COLPIX_2812_T1
            #if (USE_WS2812_MATRIX_OUT > 1)
                #define UPD_2812_M2_MS      8
                #define LEDS_2812_M2        512
                #define BRIGHT_2812_M2      5
                #define TYPE_2812_M2        WS2812B
                #define COLORD_2812_M2      NEO_GRB
                #define COLPIX_2812_M2      128
                #define ROWPIX_2812_M2      8
                #define COLPIX_2812_T2      8
                #define ROWPIX_2812_T2      8
                #define COLTIL_2812_M2      4
                #define ROWTIL_2812_M2      1
              #endif
            #if (USE_MQTT > OFF)
                #define MQTT_MAX_BRIGHT   "max-bright"
                #define MQTT_MAX_COLPICK  "max-colpick"
              #endif
            #ifndef USE_OUTPUT_CYCLE
                #define USE_OUTPUT_CYCLE
              #endif
            #define COLCHAR_2812   6
            #define COLBMP_2812    8
            #define ROWBMP_2812    8
            #define UPD_2812_M1_MS 70
            //#define COL24_2812_M1  0xFF0000u   // 0xB924u   // color r-g-b (5-6-5)
            //#define COL24_2812_BM1 0x00FF00u   // color r-g-b (5-6-5)
            #define COL24_2812_M1 0xFF0080u   // color r-g-b (5-6-5) = 255,0,128
            #define COL24_2812_BM1  0xF0B63Cu   // color r-g-b (5-6-5) = 240, 182, 56
            #define BRI_2812_M1    255
            #define BRI_2812_BM1   255

            #define ROW1_2812_M1   NEO_MATRIX_TOP
            #define COL1_2812_M1   NEO_MATRIX_LEFT
            #define DIR_2812_M1    NEO_MATRIX_COLUMNS
            #define ORI_2812_M1    NEO_MATRIX_ZIGZAG

            #define TYPE_2812_M1   WS2812B
            #define COLORD_2812_M1 NEO_GRB
            #define ROWPIX_2812_M1 8
            #define LEDS_2812_M1   COLPIX_2812_M1 * ROWPIX_2812_M1

            #define ROW1_2812_T1   NEO_MATRIX_TOP
            #define COL1_2812_T1   NEO_MATRIX_LEFT
            #define DIR_2812_T1    NEO_MATRIX_COLUMNS
            #define ORI_2812_T1    NEO_MATRIX_ZIGZAG

            #define COLPIX_2812_T1 8
            #define ROWPIX_2812_T1 8
            #define COLTIL_2812_M1 16  // needs correct value
            #define ROWTIL_2812_M1 1   // 0 = OFF
            #define ANZ_TILES_M1   COLTIL_2812_M1 * ROWPIX_2812_T1
            #define COLPIX_2812_M1 COLTIL_2812_M1 * COLPIX_2812_T1
            #define OFFBEG_2812_M1 1 //+ COLPIX_2812_T1
            #define OFFEND_2812_M1 0 //+ COLPIX_2812_T1
            #if (USE_WS2812_MATRIX_OUT > 1)
                #ifndef USE_OUTPUT_CYCLE
                    #define USE_OUTPUT_CYCLE
                  #endif
                #define UPD_2812_M2_MS 8
                #define LEDS_2812_M2   512
                #define BRIGHT_2812_M2 5
                #define TYPE_2812_M2   WS2812B
                #define COLORD_2812_M2 NEO_GRB
                #define COLPIX_2812_M2 128
                #define ROWPIX_2812_M2 8
                #define COLPIX_2812_T2 8
                #define ROWPIX_2812_T2 8
                #define COLTIL_2812_M2 4
                #define ROWTIL_2812_M2 1
              #endif
          #endif

        #if (USE_WS2812_LINE_OUT > OFF)
            #ifndef USE_OUTPUT_CYCLE
                #define USE_OUTPUT_CYCLE
              #endif
            #define UPD_2812_L1_MS          10
            #define COL24_2812_L1           0x6300F1u   // color r-g-b (5-6-5)
            #define BRI_2812_L1             5u
            #define TYPE_2812_L1            WS2812B
            #define COLORD_2812_L1          NEO_GRB
            #define COLPIX_2812_L1          30
            #define ROWPIX_2812_L1          1
            #define COLTIL_2812_L1          4
            #define ROWTIL_2812_L1          1
              //#define COLPIX_2812_T1 8
              //#define ROWPIX_2812_T1 8
                  //#define UPD_2812_L1_MS 1
                  //#define LEDS_2812_L1   300
                  //#define BRIGHT_2812_L1 5
                  //#define TYPE_2812_L1   WS2812B
                  //#define COLORD_2812_L1 NEO_GRB
            #if (USE_WS2812_LINE_OUT > 1)
                #define UPD_2812_L2_MS      10
                #define LEDS_2812_L2        30
                #define BRIGHT_2812_L2      12
                #define TYPE_2812_L2        WS2812B
                #define COLORD_2812_L2      GRB
                #if (USE_WS2812_LINE_OUT > 2)
                    #define LEDS_2812_L3    30
                    #define BRIGHT_2812_L3  12
                    #define TYPE_2812_L3    WS2812
                    #define COLORD_2812_L3  GRB
                    #if (USE_WS2812_LINE_OUT > 3)
                        #define LEDS_2812_L4   30
                        #define BRIGHT_2812_L4 12
                        #define TYPE_2812_L4   WS2812
                        #define COLORD_2812_L4 GRB
                      #endif
                  #endif
              #endif
            #if (USE_MQTT > OFF)
                #define MQTT_LIN_BRIGHT     "lin-bright"
                #define MQTT_LIN_COLPICK    "lin-colpick"
              #endif
          #endif
      // --- digital out
        #if (USE_GEN_DIG_OUT > OFF)
            #define DIG_OUT1_INV            ON   // Online controlled output
            #if (USE_MQTT > OFF)
                #define MQTT_TEST_LED       "test-led"
              #endif
          #endif
      // --- PWM
        #if (USE_RGBLED_PWM > OFF)
            #ifndef USE_OUTPUT_CYCLE
                #define USE_OUTPUT_CYCLE
              #endif
            #define PWM_LEDS_CYCLE_MS       600u
            #define PWM_LEDS_FREQ           4000u
            #define PWM_LEDS_RES            8
            #define BRI_RGBLED_1            15
            #define COL24_RGBLED_1          0xBE2727u   // bright 10 + red 10 + green 10 + blue 10
            #if (USE_MQTT > OFF)
                #define MQTT_RGB_BRIGHT     "rgb-bright"
                #define MQTT_RGB_COLPICK    "rgb-colpick"
              #endif
          #endif
        #if (USE_FAN_PWM > OFF)
            #ifndef USE_OUTPUT_CYCLE
                #define USE_OUTPUT_CYCLE
              #endif
            #define PWM_FAN_CYCLE_MS        390u
            #define PWM_FAN_FREQ            4500u
            #define PWM_FAN_RES             8
            #if (USE_MQTT > OFF)
                #define MQTT_FAN1           "fan1"
                #define MQTT_FAN2           "fan2"
              #endif
          #endif
    // --- user input
      // --- keypads
        #if defined(KEYS)
            #ifndef USE_INPUT_CYCLE
                #define USE_INPUT_CYCLE
              #endif
            #if !(KEYS ^ MC_UI_Keypad_ANA0_RO)
                #define USE_KEYPADSHIELD
                #define KEYS_ADC            34   // ADC Pin GPIO02
                #define ADC_STD_RES         12   // default resolution 12 Bit
                #define ADC_RES             12   // active resolution
                #define KP_NUM_KEYS         5
                #define KP_KEY_VAL_1        200  // max ADC value of button 0
                #define KP_KEY_VAL_2        750
                #define KP_KEY_VAL_3        1470
                #define KP_KEY_VAL_4        2330
                #define KP_KEY_VAL_5        3200
              #endif // keypad

            #if !(KEYS ^ MC_UI_TOUCHXPT2046_AZ)
                // Keypad start position, key sizes and spacing
                #define KEY_X               40 // Centre of key
                #define KEY_Y               287
                #define KEY_W               62 // Width and height
                #define KEY_H               26
                #define KEY_SPACING_X       18 // X and Y gap
                #define KEY_SPACING_Y       20
                #define KEY_TEXTSIZE        1   // Font size multiplier
                #define KEY_NUM_LEN         3 // Anzahl der Tasten
              #endif // touchpad

          #endif

      // --- counter
        #if (USE_CNT_INP > OFF)
            #define PCNT_H_LIM_VAL      0   // not used
            #define PCNT_L_LIM_VAL      0   // not used
            #define PNCT_AUTO_SWDN      5000000ul  // > 5 sec period
            #define PNCT_AUTO_SWUP      50000ul    // < 50 msec period
            // counter 1
            #define PCNT1_INP_FILT      10  // glitch filter (clock 80 MHz)
            #define PCNT1_UFLOW         3000000ul  // timedelay due to 0 Hz [us]
            #define PCNT1_INP_SIG_IO    PIN_CNT_FAN_1       // Pulse Input GPIO
            #define PCNT1_INP_CTRL_IO   PIN_CNT_FAN_1       // Control GPIO HIGH=count up, LOW=count down
            //#define PCNT1_THRESH1_VAL   5
            #define PCNT1_THRESH0_VAL   3
            #define PCNT1_EVT_0         PCNT_EVT_THRES_0
            //#define PCNT1_EVT_1         PCNT_EVT_THRES_1
            #define PCNT1_UNIDX          0
            #define PCNT1_CHIDX          0
            #define PCNT1_ID            0
            #if (USE_CNT_INP > 1)
                // counter 2
                #define PCNT2_INP_FILT      10  // glitch filter (clock 80 MHz)
                #define PCNT2_UFLOW         3000000ul  // timedelay due to 0 Hz [us]
                //#define PCNT2_INP_SIG_IO    PIN_CNT_FAN_2   // Pulse Input GPIO
                //#define PCNT2_INP_CTRL_IO   PIN_CNT_FAN_2       // Control GPIO HIGH=count up, LOW=count down
                //#define PCNT2_THRESH1_VAL   2
                #define PCNT2_THRESH0_VAL   400
                #define PCNT2_EVT_0         PCNT_EVT_THRES_0
                #define PCNT2_UNIDX          1
                #define PCNT2_CHIDX          0
                #define PCNT2_ID            1
              #endif
            #ifndef USE_INPUT_CYCLE
                #define USE_INPUT_CYCLE
              #endif
          #endif
      // --- dutycycle (pwm) input
        #if (USE_PWM_INP > OFF)
          #endif
      // --- internal adc input
        #if (USE_ADC1 > OFF)
            #ifndef USE_INPUT_CYCLE
                #define USE_INPUT_CYCLE
              #endif
          #endif
      // --- internal digital input
        #if (USE_DIG_INP > OFF)
            #ifndef USE_INPUT_CYCLE
                #define USE_INPUT_CYCLE
              #endif
            #if (USE_CTRL_SW_INP > OFF)
                #define INP_SW_CTRL         0
                #define POL_SW_CTRL         HIGH // LOW, HIGH
                #define MOD_SW_CTRL         INPUT_PULLUP // INPUT, INPUT_PULLDOWN
              #endif
            #if (USE_GEN_SW_INP > OFF)
                #define INP_REED_1          0
                #define POL_REED_1          LOW // LOW, HIGH
                #define MOD_REED_1          INPUT_PULLUP // INPUT, INPUT_PULLDOWN
              #endif
          #endif

    // --- memories
      // ---
        #define FORMAT_SPIFFS_IF_FAILED true
      // --- FRAM
        #if (USE_FRAM_I2C > OFF)
            #define SIZE_FRAM               0x8000
          #endif
    // --- sensors
      #if (USE_DS18B20_1W_IO > OFF)
          #define DS_T_PRECISION            9
          #define DS18B20_FILT              0
          #define DS18B20_Drop              0
          #if (USE_MQTT > OFF)
              #define MQTT_DS18B201         "ds18b201"
              #define MQTT_DS18B202         "ds18b202"
            #endif
          #ifndef USE_INPUT_CYCLE
              #define USE_INPUT_CYCLE
            #endif
        #endif
      #if (USE_CCS811_I2C > OFF)
          #define CCS811_I2C                I2C1
          #define CCS811C_FILT              0  // eCO2 value in air
          #define CCS811C_Drop              0  // [0 - 32768 ppm]
          #define CCS811T_FILT              0  // TVOC value carbon value in air
          #define CCS811T_Drop              0  // [400 - 29206 ppm]
          #if (USE_MQTT > OFF)
              #define MQTT_CCS811T         "ccs811t"
              #define MQTT_CCS811C         "ccs811c"
            #endif
          #ifndef USE_INPUT_CYCLE
              #define USE_INPUT_CYCLE
            #endif
        #endif
      #if (USE_INA3221_I2C > OFF)
          #define INA32211_I2C              I2C1
          #define INA32211_ADDR             I2C_INA3221_41

          #define INA3221U1_FILT            0  // voltage in1+
          #define INA3221U1_DROP            0  // [0 - 26000 mV]
          #define INA3221I1_FILT            0  // current in1
          #define INA3221I1_DROP            0  // [-5000 - +5000 mA]

          #define INA3221U2_FILT            0  // voltage in2+
          #define INA3221U2_DROP            0  // [0 - 26000 mV]
          #define INA3221I2_FILT            0  // current in2
          #define INA3221I2_DROP            0  // [-5000 - +5000 mA]

          #define INA3221I3_FILT            0  // current in3
          #define INA3221I3_DROP            0  // [-5000 - +5000 mA]
          #define INA3221U3_FILT            0  // voltage in3+
          #define INA3221U3_DROP            0  // [0 - 26000 mV]
          #if (USE_INA3221_I2C > OFF) // 1)
              #define INA32212_I2C              I2C1
              #define INA32212_ADDR             I2C_INA3221_42
            #endif
            #if (USE_INA3221_I2C > OFF) // 2)
                #define INA32213_I2C              I2C1
                #define INA32213_ADDR             I2C_INA3221_43
              #endif
          #if (USE_MQTT > OFF)
              #define MQTT_INA32211U1         "ina32211u1"
              #define MQTT_INA32211I1         "ina32211i1"
              #define MQTT_INA32211P1         "ina32211p1"

              #define MQTT_INA32211U2         "ina32211u2"
              #define MQTT_INA32211I2         "ina32211i2"
              #define MQTT_INA32211P2         "ina32211p2"

              #define MQTT_INA32211U3         "ina32211u3"
              #define MQTT_INA32211I3         "ina32211i3"
              #define MQTT_INA32211P3         "ina32211p3"
              #if (USE_MQTT > 1)
                  #define MQTT_INA32212U1         "ina32212u1"
                  #define MQTT_INA32212I1         "ina32212i1"
                  #define MQTT_INA32212P1         "ina32212p1"

                  #define MQTT_INA32212U2         "ina32212u2"
                  #define MQTT_INA32212I2         "ina32212i2"
                  #define MQTT_INA32212P2         "ina32212p2"

                  #define MQTT_INA32212U3         "ina32212u3"
                  #define MQTT_INA32212I3         "ina32212i3"
                  #define MQTT_INA32212P3         "ina32212p3"

                  #if (USE_MQTT > 1)
                      #define MQTT_INA32213U1         "ina32213u1"
                      #define MQTT_INA32213I1         "ina32213i1"
                      #define MQTT_INA32213P1         "ina32213p1"

                      #define MQTT_INA32213U2         "ina32213u2"
                      #define MQTT_INA32213I2         "ina32213i2"
                      #define MQTT_INA32213P2         "ina32213p2"

                      #define MQTT_INA32213U3         "ina32213u3"
                      #define MQTT_INA32213I3         "ina32213i3"
                      #define MQTT_INA32213P3         "ina32213p3"
                    #endif
                #endif
            #endif
        #endif
      #if (USE_BME280_I2C > OFF)
          #define BME280_I2C               I2C1
          #define BME280_ADDR              I2C_BME280_76
          #define BME280_RUNMODE           MD_NORM
          //#define BME280_RUNMODE           MD_SIM
          #define BME280T_FILT             0
          #define BME280T_Drop             0
          #define BME280P_FILT             0
          #define BME280P_Drop             0
          #define BME280H_FILT             0
          #define BME280H_Drop             0
          #if (USE_MQTT > OFF)
              #define MQTT_BME280T         "bme280t1"
              #define MQTT_BME280P         "bme280p1"
              #define MQTT_BME280H         "bme280h1"
            #endif
          #ifndef USE_INPUT_CYCLE
              #define USE_INPUT_CYCLE
            #endif
          #ifndef USE_OUTPUT_CYCLE
              #define USE_OUTPUT_CYCLE
            #endif
        #endif
      #if (USE_BME680_I2C > OFF)
          #define BME680_I2C               I2C1
          #define BME680_ADDR              I2C_BME680_77
          #define BME680_RUNMODE           MD_NORM
          //#define BME680_RUNMODE           MD_SIM
          #define BME680T_FILT             0
          #define BME680T_Drop             0
          #define BME680P_FILT             0
          #define BME680P_Drop             0
          #define BME680H_FILT             0
          #define BME680H_Drop             0
          #define BME680G_FILT             0
          #define BME680G_Drop             0
          #if (USE_MQTT > OFF)
              #define MQTT_BME680T         "bme680t1"
              #define MQTT_BME680P         "bme680p1"
              #define MQTT_BME680H         "bme680h1"
              #define MQTT_BME680G         "bme680g1"
            #endif
          #ifndef USE_INPUT_CYCLE
              #define USE_INPUT_CYCLE
            #endif
          #ifndef USE_OUTPUT_CYCLE
              #define USE_OUTPUT_CYCLE
            #endif
        #endif
    // analog channels
      /*  ADC channels
            ***_ADC_RES 12                    --> resolution 12 bit (def)
            ***_ADC_ATT  ADC_ATTEN_DB_0   -->  range 0 -  800 mV
            ***_ADC_ATT  ADC_ATTEN_DB_2_5 -->  range 0 - 1100 mV
            ***_ADC_ATT  ADC_ATTEN_DB_6   -->  range 0 - 1350 mV
            ***_ADC_ATT  ADC_ATTEN_DB_11  -->  range 0 - 2600 mV (def)

          ADS1115 channels
            ***_1115_ATT GAIN_TWOTHIRDS --> range +/-6144mV - 187.5    uV/bit
            ***_1115_ATT GAIN_ONE       --> range +/-4096mV - 125      uV/bit
            ***_1115_ATT GAIN_TWO (def) --> range +/-2048mV -  62.5    uV/bit
            ***_1115_ATT GAIN_FOUR      --> range +/-1024mV -  31.25   uV/bit
            ***_1115_ATT GAIN_EIGHT     --> range +/- 512mV -  15.625  uV/bit
            ***_1115_ATT GAIN_SIXTEEN   --> range +/- 256mV -   7.8125 uV/bit

          ADS1115 datarates
            RATE_ADS1115_8SPS         8 samples per second
            RATE_ADS1115_16SPS       16 samples per second
            RATE_ADS1115_32SPS       32 samples per second
            RATE_ADS1115_64SPS       64 samples per second
            RATE_ADS1115_128SPS      128 samples per second (default)
            RATE_ADS1115_250SPS      250 samples per second
            RATE_ADS1115_475SPS      475 samples per second
            RATE_ADS1115_860SPS      860 samples per second

          scaling parameters and calculation
          *pValue = (  (*pValue + (double) *_SCAL_OFFRAW)
                     * (double)*_SCAL_GAIN
                     + (double) *_SCAL_OFFRREAL
                    )
        */

      #if (USE_MQ135_GAS_ANA > OFF)
          #define MQ135_GAS_ADC             ON
          #define MQ135_GAS_1115            OFF
          #define MQ135_FILT                15       // floating  measure filtering
          #define MQ135_EM_WIN              100      // window for traffic light
          #define MQ135_SCAL_MIN            0
          #define MQ135_SCAL_MAX            100
            //#define MQ135_ThresFilt       25       // threshold measure filtering
            //#define MQ135_EM_MID          2350    // green < (MID-(WIN/2) < yellow < (MID+(WIN/2) < red
          #ifndef USE_INPUT_CYCLE
              #define USE_INPUT_CYCLE
            #endif
        #endif
      #if (USE_MQ3_ALK_ANA > OFF)
          #define MQ3_FILT                  5       // floating  measure filtering
          #define MQ3_DROP                  1
          #define MQ3_EM_WIN                100      // window for traffic light
          #define MQ3_SCAL                  OFF
          #define MQ3_ALK_ADC               OFF
          #define MQ3_ALK_1115              ON
          #if (MQ3_ALK_1115 > OFF)
              #define MQ3_1115_UNIDX          0
              #define MQ3_1115_CHIDX         3
              #define MQ3_1115_ATT          GAIN_TWOTHIRDS
              #define MQ3_OFFRAW            0
              #define MQ3_GAIN              0
              #define MQ3_OFFREAL           0
            #endif
          #if (USE_MQTT > OFF)
              #define MQTT_MQ3              "alc"
            #endif
          #ifndef USE_INPUT_CYCLE
              #define USE_INPUT_CYCLE
            #endif
        #endif
      #if (USE_TYPE_K_SPI > OFF)
          #define TYPEK_FILT      11        // floating  measure filtering
          #define TYPEK_DROP_PEEK 2         // drop biggest / lowest
          #define TYPEK1_OFFSET   0.        // offset unit °C
          #define TYPEK1_GAIN     1.        // result = (measure * gain) + offset
          #if (USE_TYPE_K_SPI > OFF)
              #define TYPEK2_OFFSET   0.        // offset unit °C
              #define TYPEK2_GAIN     1.        // result = (measure * gain) + offset
            #endif
          #if (USE_MQTT > OFF)
              #define TYPEK1_MQTT           "ttypek-1"
              #define TYPEK2_MQTT           "ttypek-2"
            #endif
          #ifndef USE_INPUT_CYCLE
              #define USE_INPUT_CYCLE
            #endif
        #endif
      #if (USE_PHOTO_SENS_ANA > OFF)
          #define PHOTO1_FILT               0
          #define PHOTO1_DROP               1
          #define PHOTO1_ADC                ON
          #if (PHOTO1_ADC > OFF)
              #define PHOTO1_ADC_ATT        ADC_ATTEN_DB_11
              #define PHOTO1_SCAL_OFFRAW    0
              #define PHOTO1_SCAL_GAIN      0.02442
              #define PHOTO1_SCAL_OFFREAL   0
            #endif
          #define PHOTO1_1115               OFF
          #if (PHOTO1_1115 > OFF)
              #define PHOTO1_1115_UNIDX     0
              #define PHOTO1_1115_CHIDX     0
              #define PHOTO1_1115_ATT       GAIN_ONE
              #define PHOTO1_SCAL_OFFRAW    0
              #define PHOTO1_SCAL_GAIN      1
              #define PHOTO1_SCAL_OFFREAL   0
            #endif
          #if (USE_MQTT > OFF)
              #define MQTT_PHOTO1           "photo1"
            #endif
          #if (USE_PHOTO_SENS_ANA > 1)
              #define PHOTO2_FILT           7
              #define PHOTO2_DROP           0
              #define PHOTO2_SCAL           OFF
              #define PHOTO2_SCAL_MIN       0
              #define PHOTO2_SCAL_MAX       100
              #define PHOTO2_ADC            ON
              #if (PHOTO2_ADC > OFF)
                  #define PHOTO2_ADC_ATT  ADC_ATTEN_DB_11
                #endif
              #define PHOTO2_1115           OFF
              #if (PHOTO2_1115 > OFF)
                  #define PHOTO2_1115_ATT  GAIN_ONE
                  #define PHOTO2_1115_UNIDX  0
                  #define PHOTO2_1115_CHIDX 0
                #endif
              #if (USE_MQTT > OFF)
                  #define MQTT_PHOTO2           "licht2"
                #endif
            #endif
          #ifndef USE_INPUT_CYCLE
              #define USE_INPUT_CYCLE
            #endif
        #endif
      #if (USE_VCC_ANA > OFF)
          #define VCC_FILT                0
          #define VCC_DROP                1
          #if (USE_VCC50_ANA > OFF)
              #define VCC50_ADC           OFF
              #define VCC50_1115          ON
              #if (VCC50_ADC > OFF)
                  #define VCC50_ADC_ATT       ADC_ATTEN_DB_11
                  #define VCC50_SCAL          OFF
                  #define VCC50_SCAL_OFFRAW   0
                  #define VCC50_SCAL_GAIN     1
                  #define VCC50_SCAL_OFFREAL  0
                #endif
              #if (VCC50_1115 > OFF)
                  #define VCC_1115_UNIDX     0
                  #define VCC50_1115_CHIDX   2    //
                  #define ADS13_GAIN        GAIN_TWOTHIRDS
                  #define ADS13_RATE        RATE_ADS1115_128SPS
                  #define ADS13_MUX         ADS1X15_MUX_SINGLE
                  #define VCC50_SCAL        ON
                  #define VCC50_OFFRAW      0
                  #define VCC50_GAIN        2
                  #define VCC50_OFFREAL     0
                #endif
              #if (USE_MQTT > OFF)
                  #define MQTT_VCC50        "vcc50"
                #endif
            #endif
          #if (USE_VCC33_ANA > OFF)
              #define VCC33_ADC         OFF
              #define VCC33_1115        ON
              #if (VCC33_1115 > OFF)
                  #define VCC33_1115_UNIDX   0
                  #define VCC33_1115_CHIDX   3    //
                  #define ADS11_GAIN        GAIN_TWOTHIRDS
                  #define ADS11_RATE        RATE_ADS1115_128SPS
                  #define ADS11_MUX         ADS1X15_MUX_SINGLE
                  #define VCC33_SCAL        OFF
                  #define VCC33_OFFRAW      0
                  #define VCC33_GAIN        1
                  #define VCC33_OFFREAL     0
                #endif
              #if (USE_MQTT > OFF)
                  #define MQTT_VCC33          "vcc33"
                #endif
            #endif
          #ifndef USE_INPUT_CYCLE
              #define USE_INPUT_CYCLE
            #endif
        #endif
      #if (USE_POTI_ANA > OFF)
          #define POTI1_FILT              9
          #define POTI1_DROP              1
          #define POTI1_ADC               OFF
          #if (POTI1_ADC > OFF)
              #define POTI1_ADC_ATT     ADC_ATTEN_DB_11
              #define VCC_SCAL_OFFRAW   0
              #define VCC_SCAL_GAIN     1
              #define VCC_SCAL_OFFREAL  0
            #endif
          #define POTI1_1115              ON
          #if (POTI1_1115 > OFF)
              #define POTI1_1115_UNIDX    0
              #define POTI1_1115_CHIDX    0
              #define ADS14_GAIN          GAIN_TWOTHIRDS
              #define ADS14_RATE          RATE_ADS1115_128SPS
              #define ADS14_MUX           ADS1X15_MUX_SINGLE
              #define POTI1_OFFRAW        0
              #define POTI1_GAIN          1
              #define POTI1_OFFREAL       0
            #endif
          #if (USE_MQTT > OFF)
              #define MQTT_POTI1          "poti1"
            #endif
          #if (USE_POTI_ANA > 1)
              #define POTI2_FILT          7
              #define POTI2_DROP          0
              #define POTI2_SCAL          OFF
              #define POTI2_SCAL_MIN      0
              #define POTI2_SCAL_MAX      100
              #define POTI2_ADC           ON
              #if (POTI2_ADC > OFF)
                  #define POTI2_ADC_ATT   ADC_ATTEN_DB_11
                #endif
              #define POTI2_1115            OFF
              #if (POTI2_1115 > OFF)
                  #define POTI2_1115_UNIDX  0
                  #define POTI2_1115_CHIDX 0
                  #define POTI2_1115_ATT  GAIN_TWOTHIRDS
                #endif
              #if (USE_MQTT > OFF)
                  #define MQTT_POTI2          "poti2"
                #endif
            #endif
          #ifndef USE_INPUT_CYCLE
              #define USE_INPUT_CYCLE
            #endif
        #endif
      #if (USE_ACS712_ANA > OFF)
          /*  ACS712 hall effect current sensor +/- 5A/20A/30 A
              output: VCC/2 (2,5V) + measured value
              sensitivity: type  5A -> 186mV/A ->  1570 - 3430 mV
              sensitivity: type 20A -> 100mV/A ->   500 - 4500 mV
              sensitivity: type 30A ->  66mV/A ->   520 - 4480 mV
            */
          #define I712_FILT               0
          #define I712_DROP               0
          #define I712_1_IMAX             5000 // mA
          #define I712_1_ADC              OFF // not recommended, low resolution
          #if (I712_1_ADC > OFF)
              #define I712_1_ADC_ATT   ADC_ATTEN_DB_11
            #endif
          #define I712_1_1115             ON
          #if (I712_1_1115 > OFF)
              #define I712_1_1115_UNIDX    0
              #define I712_1_1115_CHIDX    1
              #if   (I712_1_IMAX ==  5000)
                  #define ADS12_GAIN            GAIN_TWOTHIRDS
                  #define ADS12_RATE            RATE_ADS1115_128SPS
                  #define ADS12_MUX             ADS1X15_MUX_SINGLE
                  #define I712_1_SCAL_OFFRAW    0
                  #define I712_1_SCAL_GAIN      185
                  #define I712_1_SCAL_OFFREAL   0
                #endif
              #if (I712_1_IMAX == 20000)
                  #define ADS12_GAIN            GAIN_ONE
                  #define ADS12_RATE            RATE_ADS1115_128SPS
                  #define ADS12_MUX             ADS1X15_MUX_SINGLE
                  #define I712_1_SCAL_OFFRAW    0
                  #define I712_1_SCAL_GAIN      1
                  #define I712_1_SCAL_OFFRAW    0
                #endif
              #if (I712_1_IMAX == 30000)
                  #define ADS12_GAIN            GAIN_ONE
                  #define ADS12_RATE            RATE_ADS1115_128SPS
                  #define ADS12_MUX             ADS1X15_MUX_SINGLE
                  #define I712_1_SCAL_OFFRAW    0
                  #define I712_1_SCAL_GAIN      1
                  #define I712_1_SCAL_OFFRAW    0
                #endif
              #if (USE_MQTT > OFF)
                  #define MQTT_I712_1         "acs7121"
                #endif
            #endif
          #if (USE_ACS712_ANA > 1)
              #define I712_2_IMAX             5000 // mA
              #define I712_2_ADC              OFF // not recommended, low resolution
              #define I712_2_1115             ON
              #if (I712_2_ADC > OFF)
                  #define I712_2_ADC_ATT   ADC_ATTEN_DB_11
                #endif
              #if (I712_2_1115 > OFF)
                  #define I712_2_1115_UNIDX     0
                  #define I712_2_1115_CHIDX    2
                  #if  (I712_2_IMAX ==  5000)
                      #define I712_2_1115_ATT       GAIN_ONE
                      #define I712_2_SCAL_OFFRAW    0
                      #define I712_2_SCAL_GAIN      1
                      #define I712_2_SCAL_OFFREAL   0
                    #endif
                  #if (I712_2_IMAX == 20000)
                      #define I712_2_1115_ATT      GAIN_TWOTHIRDS
                      #define I712_2_SCAL_OFFRAW    0
                      #define I712_2_SCAL_GAIN      1
                      #define I712_2_SCAL_OFFRAW    0
                    #endif
                  #if (I712_2_IMAX == 30000)
                      #define I712_2_1115_ATT      GAIN_TWOTHIRDS
                      #define I712_2_SCAL_OFFRAW    0
                      #define I712_2_SCAL_GAIN      1
                      #define I712_2_SCAL_OFFRAW    0
                    #endif
                  #if (USE_MQTT > OFF)
                      #define MQTT_I712_1         "acs7121"
                      #define MQTT_I712_2         "acs7122"
                    #endif
                #endif

            #endif
        #endif

      #if (USE_ADC1115_I2C > OFF)
          #define ADS_I2C          I2C1
          #define ADS1_RUNMODE     MD_NORM
          //#define ADS1_RUNMODE     MD_SIM
          #define ADS1_ADDR        I2C_ADS1115_48
          #define ADS1_ANZ_CHANS   4
          #if (USE_ADC1115_I2C > 1)
              #define ADS2_ADDR        I2C_ADS1115_48 //I2C_ADS1115_49
              #define ADS2_ANZ_CHANS    4
              #if (USE_ADC1115_I2C > 2)
                  #define ADS3_ADDR        I2C_ADS1115_48 //I2C_ADS1115_4A
                  #define ADS3_ANZ_CHANS    4
                  #if (USE_ADC1115_I2C > 3)
                      #define ADS4_ADDR        I2C_ADS1115_48 //I2C_ADS1115_4B
                      #define ADS4_ANZ_CHANS    4
                    #endif
                #endif
            #endif
        #endif
      //#define ANZ_ANASENS  USE_DS18B20_1W_IO + USE_BME280_I2C * 3 + USE_MQ135_GAS_ADC + USE_TYPE_K_SPI
      // --- cycle timing
        #define DISP_CYCLE_MS       100ul   // Intervallzeit [us]
        // output status line
        #define STAT_DELTIME_MS     5000ul  // default time to clear status
        #define STAT_NEWTIME_MS     1000ul  // default time to clear status
        #ifdef USE_INPUT_CYCLE
            #define INPUT_CYCLE_MS  10u
          #endif
        #ifdef USE_OUTPUT_CYCLE
            #define OUTPUT_CYCLE_MS 20u
          #endif

  // ----------------------------------------------------------------
  // --- board management
  // ----------------------------------------------------------------
    #if !(BOARD ^ MC_ESP32_AZTOUCH)
      // --- system
        #define SER_BAUDRATE ESP_SER_BAUD
        // --- network
        // --- user output
          // --- LEDs
          // --- display
          // --- acustic output
        // --- user input
        // --- sensors
        // --- memories
      // --- pins, connections
        // --- system
          #if (USE_LED_BLINK_OUT > OFF)
              #define PIN_BOARD_LED       2 // NC
            #endif
          // --- I2C board connection
            #define PIN_I2C1_SDA          32  //21
            #define PIN_I2C1_SCL          26  //22
            #if ( USE_I2C > 1 )
                #define PIN_I2C2_SDA  25
                #define PIN_I2C2_SCL  26
              #endif
          // --- SPI board connection
            #define PIN_SPI_MOSI          23
            #define PIN_SPI_MISO          19
            #define PIN_SPI_SCL           18
        // --- display
          #if (USE_OLED_I2C > OFF)
              #define OLED1_I2C_SCL       PIN_I2C1_SCL
              #define OLED1_I2C_SDA       PIN_I2C1_SDA
              #if (USE_OLED_I2C > 1)
                  #define OLED2_I2C_SCL   PIN_I2C1_SCL
                  #define OLED2_I2C_SDA   PIN_I2C1_SDA
                #endif
            #endif
        // --- user input
          #if (USE_CTRL_POTI > OFF)
              #define PIN_INP_POTI_1      35   // ADC 1-5
              #define ADC_INP_POTI_1      NU   // ADC 1-5
            #endif
          #if (USE_CTRL_SW_INP > OFF)
              #define PIN_INP_SW_1        32   // INPUT_PULLUP
            #endif
          #if (USE_DIG_INP > OFF)
              #if (USE_GEN_SW_INP > OFF)
                  #define PIN_INP_REED_1  15
                #endif
            #endif
          #if (USE_GEN_CNT_INP > OFF)
              #define PIN_CNT_GEN_S0      4
              #define PIN_CNT_GEN_C0      PCNT_PIN_NOT_USED
              #define PIN_CNT_GEN_S1      17
              #define PIN_CNT_GEN_C1      PCNT_PIN_NOT_USED
            #endif
          #if (USE_PWM_INP > OFF)
                #define PIN_PWM_INP_1     PIN_CNT_GEN_2
            #endif
        // --- counter
          #if (USE_CNT_INP > OFF)
              #define PCNT1_INP_SIG_IO    PIN_CNT_FAN_1       // Pulse Input GPIO
              #define PCNT1_INP_CTRL_IO   PIN_CNT_FAN_1       // Control GPIO HIGH=count up, LOW=count down
              #if (USE_CNT_INP > 1)
                  // counter 2
                  #define PCNT2_INP_SIG_IO    PIN_CNT_FAN_2   // Pulse Input GPIO
                  #define PCNT2_INP_CTRL_IO   PIN_CNT_FAN_2       // Control GPIO HIGH=count up, LOW=count down
                #endif
              #ifndef USE_INPUT_CYCLE
                  #define USE_INPUT_CYCLE
                #endif
            #endif
        // --- user output
          #if (USE_GEN_DIG_OUT > OFF)
              #define PIN_GEN_DIG_OUT1     15   // Online controlled output
            #endif
          #if (USE_TRAFFIC_LED_OUT > OFF)
              #define PIN_TL_RED          26   // RGB red
              #define PIN_TL_YELLOW       25   // RGB green
              #define PIN_TL_GREEN        33   // RGB blue
            #endif
          #if (USE_RGBLED_PWM > OFF)
              #define PIN_RGB_RED         33 //26   // RGB red
              #define PIN_RGB_GREEN       26   // RGB blue
              #define PIN_RGB_BLUE        14 //33   // RGB blue
            #endif
          #if (USE_FAN_PWM > OFF)
              #define PIN_PWM_FAN_1       0
              #if (USE_FAN_PWM > 1)
                  #define PIN_PWM_FAN_2   4
                #endif
            #endif
          #if (USE_OUT_FREQ_PWM > OFF)
              #define PIN_FREQ_1          26
            #endif
          #if (USE_WS2812_MATRIX_OUT > OFF)
              #define PIN_WS2812_M1      16
              #if (USE_WS2812_PWR_IN_SW > OFF)
                  #define PIN_WS2812_PWR_IN_SW 36
                #endif
              #if (USE_WS2812_MATRIX_OUT > 1)
                  #define PIN_WS2812_M2   32
                #endif
                //#define PIN_WS2812_M3  x
                //#define PIN_WS2812_M4  x
            #endif
          #if (USE_WS2812_LINE_OUT > OFF)
              #if (USE_WS2812_PWR_IN_SW > OFF)
                  #define PIN_WS2812_PWR_IN_SW 36
                #endif
              #define PIN_WS2812_L1      12
                //#define PIN_WS2812_L2    17
                //#define PIN_WS2812_L3  x
                //#define PIN_WS2812_L4  x
            #endif

          #if (USE_TFT > OFF)
              #if !(DISP_TFT ^ MC_UO_TFT1602_GPIO_RO)
                  #define LCD_BL      5    // D10/SS  ARDUINO
                  #define LCD_EN      13   // D9
                  #define LCD_RS      12   // D8
                  #define LCD_D7      14   // D7
                  #define LCD_D6      27   // D6
                  #define LCD_D5      16   // D5
                  #define LCD_D4      17   // D4
                #endif
              #if !(DISP_TFT ^ MC_UO_TOUCHXPT2046_AZ)
                  #define TFT_CS      5
                  #define TFT_DC      4
                  #define TFT_RST     22
                  #define TFT_LED     15
                  #define TOUCH_CS    14
                  // v01.03.01
                  #define TOUCH_IRQ   27
                  #define LED_ON      0    // activ low
                #endif
              #if !(DISP_TFT ^ MC_UO_TFT1602_I2C_XA)
                  #define ME
                #endif
            #endif

          #if (USE_BUZZER_PWM > OFF)
              #define PIN_BUZZ        21
            #endif
        // --- sensors
          #if (USE_DS18B20_1W_IO > OFF)
              #define DS1_ONEWIRE_PIN     27
              #if (USE_DS18B20_1W_IO > 1)
                  #define DS2_ONEWIRE_PIN 32
                #endif
            #endif
          #if (USE_TYPE_K_SPI > OFF)
              #define TYPEK_DATA_PIN      PIN_SPI_MISO
              #define TYPEK_CLK_PIN       PIN_SPI_CLK
              #define TYPEK1_CS_PIN       16
              #define TYPEK2_CS_PIN       17
            #endif
          #if (USE_MQ135_GAS_ANA > OFF)
              #define PIN_MQ135           35
              #define ADC_MQ135           5   // ADC 1-3
            #endif
          #if (USE_MQ3_ALK_ANA > OFF)
              #if (MQ3_ALK_ADC > OFF)
                  #define PIN_MQ135           35
                  #define ADC_MQ135           5   // ADC 1-3
                #endif
            #endif
          #if (USE_PHOTO_SENS_ANA > OFF)
              #define PIN_PHOTO1_SENS     39
              #define ADC_PHOTO1_SENS     3
            #endif
        // --- memory
          #if (USE_FRAM_I2C > OFF)
              #define FRAM1_I2C_SCL       PIN_I2C1_SCL
              #define FRAM1_I2C_SDA       PIN_I2C1_SDA
              #if (USE_FRAM_I2C > 1 )
                  #define FRAM2_I2C_SCL   I2C1_SCL
                  #define FRAM2_I2C_SDA   I2C1_SDA
                #endif
            #endif

          #if (USE_SD_SPI > OFF)
              #define SD_SPI              VSPI
              #define SD_MISO             PIN_SPI_MISO
              #define SD_MOSI             PIN_SPI_MOSI
              #define SD_SCL              PIN_SPI_SCL
              #define SD_CS               17
            #endif
        // --- PWM channels   0..15
          #if (USE_PWM_OUT > OFF)
              #if (USE_BUZZER_PWM > OFF)
                  #define PWM_BUZZ  0
                #endif

              #if (USE_TRAFFIC_LED_OUT > OFF)
                  #define PWM_TL_GREEN  1
                  #define PWM_TL_YELLOW 2
                  #define PWM_TL_RED    3
                #endif

              #if (USE_RGBLED_PWM > OFF)
                  #define PWM_RGB_RED     1
                  #define PWM_RGB_GREEN   2
                  #define PWM_RGB_BLUE    3
                #endif
              #if (USE_FAN_PWM > OFF)
                  #define PWM_FAN_1       4
                  #if (USE_FAN_PWM > 1)
                      #define PWM_FAN_2   0
                    #endif
                #endif
              #if (USE_OUT_FREQ_PWM > OFF)
                  #define PWM_FREQ_1      6
                #endif
            #endif
        // --- counter channels  0..7
          #if (USE_CNT_INP > OFF)
              #define USE_CNT_UNIDX       PCNT_UNIDX_0
              #if (USE_GEN_CNT_INP > OFF)
                  #define CNT_UNIDX_GEN0  PCNT_UNIDX_0
                  #define CNT_CH_GEN0    (PCNT_CHANNEL_0)
                  #undef  USE_CNT_UNIDX
                  #define USE_CNT_UNIDX   (CNT_UNIDX_GEN0 + 1)
                #endif
              #if (USE_GEN_CNT_INP > 1)
                  #define CNT_UNIDX_GEN1  PCNT_UNIDX_1
                  #define CNT_CH_GEN1    (PCNT_CHANNEL_0)
                  #undef  USE_CNT_UNIDX
                  #define USE_CNT_UNIDX   (CNT_UNIDX_GEN1 + 1)
                #endif
              #if (USE_GEN_CNT_INP > 2)
                  #define CNT_UNIDX_GEN2  PCNT_UNIDX_2
                  #define CNT_CH_GEN2    (PCNT_CHANNEL_0)
                  #undef  USE_CNT_UNIDX
                  #define USE_CNT_UNIDX   (CNT_UNIDX_GEN2 + 1)
                #endif
              #if (USE_GEN_CNT_INP > 3)
                  #define CNT_UNIDX_GEN3  PCNT_UNIDX_3
                  #define CNT_CH_GEN3    (PCNT_CHANNEL_0)
                  #undef  USE_CNT_UNIDX
                  #define USE_CNT_UNIDX   (CNT_UNIDX_GEN3 + 1)
                #endif
            #endif
      #endif
    // ******************************************
#endif // _PRJ_CONF_TOUCHTEST_1_H_
