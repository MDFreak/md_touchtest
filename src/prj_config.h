#ifndef _PRJ_CONFIG_H_
  #define _PRJ_CONFIG_H_

  #include <Arduino.h>
  #include <md_defines.h>
  #include <project.h>

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

    #if (PROJECT == TOUCHTEST_1)
        #include <prj_conf_touchtest_1.h>
      #endif
    #if (PROJECT == MEASFREQ_1)
        #include <prj_conf_measfreq_1.h>
      #endif
    #if (PROJECT == LIGHTSHOW_1)
        #include <prj_conf_lightshow_1.h>
      #endif
    #if (PROJECT == GEN_ESP32_NODE)
        #include <prj_conf_gen_esp32_node.h>
      #endif
    #if (PROJECT == GEN_XIAO_ESP32C3)
        #include <prj_conf_gen_xiao_esp32c3.h>
      #endif
    #if (PROJECT == GEN_ESP32_D1_MINI)
        #include <prj_conf_gen_esp32_d1_mini.h>
      #endif

#endif // _PRJ_CONFIG_H_
