// Copyright 2015-2016 Espressif Systems (Shanghai) PTE LTD
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at

//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

/* C Includes */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//LV_COLOR_DEPTH

/* RTOS Includes */
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/event_groups.h"
#include "freertos/semphr.h"
#include "spi_master_lobo.h"


#ifdef CONFIG_LVGL_GUI_ENABLE

/* lvgl include */
#include "lvgl_disp_config.h"

/*Write the internal buffer (VDB) to the display. 'lv_flush_ready()' has to be called when finished*/
void ex_disp_flush(int32_t x1, int32_t y1, int32_t x2, int32_t y2, const lv_color_t *color_p)
{
    //lcd_obj->drawBitmap((int16_t)x1, (int16_t)y1, (const uint16_t *)color_p, (int16_t)(x2 - x1 + 1), (int16_t)(y2 - y1 + 1));

    lv_color32_t *32p=(lv_color_32_t*)color_p;
    colort_t *24p=(color_t*)color_t;
    int len=(x2-x1)*(y2-y1);
    int i=0;
    for(i=0;i<len;i++){
        24p[i].r=32p[i].red;
        24p[i].g=32p[i].green;
        24p[i].b=32p[i].blue;
    }
    
    send_data(x1, y1, x2, y2, len, color_t *buf)

    /* IMPORTANT!!!
     * Inform the graphics library that you are ready with the flushing*/
    lv_flush_ready();
}

/*Fill an area with a color on the display*/
void ex_disp_fill(int32_t x1, int32_t y1, int32_t x2, int32_t y2, lv_color_t color)
{
}

/*Write pixel map (e.g. image) to the display*/
void ex_disp_map(int32_t x1, int32_t y1, int32_t x2, int32_t y2, const lv_color_t *color_p)
{
}

lv_disp_drv_t lvgl_lcd_display_init()
{
     tft_disp_type = DEFAULT_DISP_TYPE;
     _width = DEFAULT_TFT_DISPLAY_WIDTH;  // smaller dimension
     _height = DEFAULT_TFT_DISPLAY_HEIGHT; // larger dimension
     TFT_PinsInit();

     spi_lobo_bus_config_t buscfg={
         .miso_io_num=CONFIG_LVGL_LCD_MISO_GPIO,              // set SPI MISO pin
         .mosi_io_num=CONFIG_LVGL_LCD_MOSI_GPIO,              // set SPI MOSI pin
         .sclk_io_num=CONFIG_LVGL_LCD_CLK_GPIO,               // set SPI CLK pin
         .quadwp_io_num=-1,
         .quadhd_io_num=-1,
         .max_transfer_sz = 6*1024,
     };
     spi_lobo_device_interface_config_t devcfg={
         .clock_speed_hz=8000000,                // Initial clock out at 8 MHz
         .mode=0,                                // SPI mode 0
         .spics_io_num=-1,                       // we will use external CS pin
         .spics_ext_io_num=CONFIG_LVGL_LCD_CS_GPIO,           // external CS pin
         .flags=LB_SPI_DEVICE_HALFDUPLEX,        // ALWAYS SET  to HALF DUPLEX MODE!! for display spi
     };

     vTaskDelay(500 / portTICK_RATE_MS);
     printf("\r\n==============================\r\n");
     printf("TFT display DEMO, LoBo 11/2017\r\n");
     printf("==============================\r\n");
     printf("Pins used: miso=%d, mosi=%d, sck=%d, cs=%d\r\n", PIN_NUM_MISO, PIN_NUM_MOSI, PIN_NUM_CLK, PIN_NUM_CS);
     ret=spi_lobo_bus_add_device(SPI_BUS, &buscfg, &devcfg, &spi);
     assert(ret==ESP_OK);
     printf("SPI: display device added to spi bus (%d)\r\n", SPI_BUS);
     disp_spi = spi;
          // ==== Test select/deselect ====
     ret = spi_lobo_device_select(spi, 1);
     assert(ret==ESP_OK);
     ret = spi_lobo_device_deselect(spi);
     assert(ret==ESP_OK);

     printf("SPI: attached display device, speed=%u\r\n", spi_lobo_get_speed(spi));
     printf("SPI: bus uses native pins: %s\r\n", spi_lobo_uses_native_pins(spi) ? "true" : "false");


     // ================================
     // ==== Initialize the Display ====

     printf("SPI: display init...\r\n");
     TFT_display_init();
     printf("OK\r\n");
          // ==== Set SPI clock used for display operations ====
     spi_lobo_set_speed(spi, 60000000);
     printf("SPI: Changed speed to %u\r\n", spi_lobo_get_speed(spi));
     TFT_setGammaCurve(DEFAULT_GAMMA_CURVE);
     TFT_setRotation(PORTRAIT);
     TFT_setFont(DEFAULT_FONT, NULL);
     TFT_resetclipwin();


    lv_disp_drv_t disp_drv;      /*Descriptor of a display driver*/
    lv_disp_drv_init(&disp_drv); /*Basic initialization*/

#ifdef CONFIG_LVGL_DISP_ROTATE_0
    TFT_setRotation(0);
    ESP_LOGI("lvgl_example", "CONFIG_LVGL_DISP_ROTATE_0");
#elif defined(CONFIG_LVGL_DISP_ROTATE_90)
    TFT_setRotation(1);
    ESP_LOGI("lvgl_example", "CONFIG_LVGL_DISP_ROTATE_90");
#elif defined(CONFIG_LVGL_DISP_ROTATE_180)
    TFT_setRotation(2);
    ESP_LOGI("lvgl_example", "CONFIG_LVGL_DISP_ROTATE_180");
#elif defined(CONFIG_LVGL_DISP_ROTATE_270)
    TFT_setRotation(3);
    ESP_LOGI("lvgl_example", "CONFIG_LVGL_DISP_ROTATE_270");
#endif

    /* Set up the functions to access to your display */
    if (LV_VDB_SIZE != 0) {
        disp_drv.disp_flush = ex_disp_flush; /*Used in buffered mode (LV_VDB_SIZE != 0  in lv_conf.h)*/
    } else if (LV_VDB_SIZE == 0) {
        disp_drv.disp_fill = ex_disp_fill; /*Used in unbuffered mode (LV_VDB_SIZE == 0  in lv_conf.h)*/
        disp_drv.disp_map = ex_disp_map;   /*Used in unbuffered mode (LV_VDB_SIZE == 0  in lv_conf.h)*/
    }

    /* Finally register the driver */
    lv_disp_drv_register(&disp_drv);
    return disp_drv;
}

#endif /* CONFIG_LVGL_GUI_ENABLE */
