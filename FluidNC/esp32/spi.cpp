// Copyright (c) 2022 Mitch Bradley
// Use of this source code is governed by a GPLv3 license that can be found in the LICENSE file.

#include "Driver/spi.h"

#include "driver/spi_common.h"
#include "src/Config.h"

#include <sdkconfig.h>

#ifdef CONFIG_IDF_TARGET_ESP32S3
#    define HSPI_HOST SPI2_HOST
#endif

bool spi_init_bus(pinnum_t sck_pin, pinnum_t miso_pin, pinnum_t mosi_pin, bool dma) {
    // Start the SPI bus with the pins defined here.  Once it has been started,
    // those pins "stick" and subsequent attempts to restart it with defaults
    // for the miso, mosi, and sck pins are ignored
    /*
    {
        gpio_config_t gp_cfg = { 0 };
        gp_cfg.mode          = GPIO_MODE_INPUT;
        gp_cfg.pull_up_en    = GPIO_PULLUP_ENABLE;
        gp_cfg.pin_bit_mask  = 1UL << miso_pin;
        gpio_config(&gp_cfg);
    }
    {
        gpio_config_t gp_cfg = { 0 };
        gp_cfg.mode          = GPIO_MODE_OUTPUT;
        gp_cfg.pull_up_en    = GPIO_PULLUP_ENABLE;
        gp_cfg.pin_bit_mask  = (1UL << mosi_pin) | (1UL << sck_pin);
        gpio_config(&gp_cfg);
    }*/

    // gpio_set_pull_mode(gpio_num_t(mosi_pin), GPIO_PULLUP_ONLY);
    // gpio_set_pull_mode(gpio_num_t(miso_pin), GPIO_PULLUP_ONLY);
    // gpio_set_pull_mode(gpio_num_t(sck_pin), GPIO_PULLUP_ONLY);

    spi_bus_config_t bus_cfg = {
        .mosi_io_num     = mosi_pin,
        .miso_io_num     = miso_pin,
        .sclk_io_num     = sck_pin,
        .quadwp_io_num   = -1,
        .quadhd_io_num   = -1,
        .max_transfer_sz = 4000,
    };

    // Depends on the chip variant
    return !spi_bus_initialize(HSPI_HOST, &bus_cfg, dma ? SPI_DMA_CH_AUTO : SPI_DMA_DISABLED);
}

void spi_deinit_bus() {
    esp_err_t err = spi_bus_free(HSPI_HOST);
    log_debug("deinit spi " << int(err));
}
