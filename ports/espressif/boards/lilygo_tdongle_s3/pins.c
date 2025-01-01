// This file is part of the CircuitPython project: https://circuitpython.org
//
// SPDX-FileCopyrightText: Copyright (c) 2020 Scott Shawcroft for Adafruit Industries
//
// SPDX-License-Identifier: MIT

#include "shared-bindings/board/__init__.h"
#include "shared-module/displayio/__init__.h"

static const mp_rom_map_elem_t board_module_globals_table[] = {
    CIRCUITPYTHON_BOARD_DICT_STANDARD_ITEMS

    // Pin out from: https://cdn.shopifycdn.net/s/files/1/0617/7190/7253/files/T-Dongle-LILYGO_16_1024x1024.jpg

    // Available GPIO Pins
    { MP_ROM_QSTR(MP_QSTR_IO0), MP_ROM_PTR(&pin_GPIO0) },      // Boot Button

    { MP_ROM_QSTR(MP_QSTR_IO14), MP_ROM_PTR(&pin_GPIO14) },    // SDMMC_D0 pin_GPIO14
    { MP_ROM_QSTR(MP_QSTR_IO17), MP_ROM_PTR(&pin_GPIO17) },    // SDMMC_D0 pin_GPIO14
    { MP_ROM_QSTR(MP_QSTR_IO21), MP_ROM_PTR(&pin_GPIO21) },    // SDMMC_D2 pin_GPIO21
    { MP_ROM_QSTR(MP_QSTR_IO18), MP_ROM_PTR(&pin_GPIO18) },    // SDMMC_D3 pin_GPIO18
    { MP_ROM_QSTR(MP_QSTR_IO12), MP_ROM_PTR(&pin_GPIO12) },    // SDMMC_CLK pin_GPIO12
    { MP_ROM_QSTR(MP_QSTR_IO16), MP_ROM_PTR(&pin_GPIO16) },    // SDMMC_CMD pin_GPIO16

    { MP_ROM_QSTR(MP_QSTR_IO19), MP_ROM_PTR(&pin_GPIO19) },    // USB_DN pin_GPIO19
    { MP_ROM_QSTR(MP_QSTR_IO20), MP_ROM_PTR(&pin_GPIO20) },    // USB_DP pin_GPIO20

    { MP_ROM_QSTR(MP_QSTR_IO40), MP_ROM_PTR(&pin_GPIO40) },    // LED_DI_PIN pin_GPIO40
    { MP_ROM_QSTR(MP_QSTR_IO39), MP_ROM_PTR(&pin_GPIO39) },    // LED_CI_PIN pin_GPIO39

    { MP_ROM_QSTR(MP_QSTR_IO4), MP_ROM_PTR(&pin_GPIO4) },      // TFT_CS_PIN pin_GPIO4
    { MP_ROM_QSTR(MP_QSTR_IO3), MP_ROM_PTR(&pin_GPIO3) },      // TFT_SDA_PIN pin_GPIO3
    { MP_ROM_QSTR(MP_QSTR_IO5), MP_ROM_PTR(&pin_GPIO5) },      // TFT_SCL_PIN pin_GPIO5
    { MP_ROM_QSTR(MP_QSTR_IO2), MP_ROM_PTR(&pin_GPIO2) },      // TFT_DC_PIN pin_GPIO2
    { MP_ROM_QSTR(MP_QSTR_IO1), MP_ROM_PTR(&pin_GPIO1) },      // TFT_RES_PIN pin_GPIO1
    { MP_ROM_QSTR(MP_QSTR_IO38), MP_ROM_PTR(&pin_GPIO38) },    // TFT_LED_PIN pin_GPIO38

    { MP_ROM_QSTR(MP_QSTR_IO44), MP_ROM_PTR(&pin_GPIO44) },    // STEMMA_RX pin_GPIO44
    { MP_ROM_QSTR(MP_QSTR_IO43), MP_ROM_PTR(&pin_GPIO43) },    // STEMMA_TX pin_GPIO43


    // Special Function Pin Names
    { MP_ROM_QSTR(MP_QSTR_BUTTON_0), MP_ROM_PTR(&pin_GPIO0) },      // Boot Button pin_GPIO0

    { MP_ROM_QSTR(MP_QSTR_SDMMC_D0), MP_ROM_PTR(&pin_GPIO14) },     // SDMMC_D0 pin_GPIO14
    { MP_ROM_QSTR(MP_QSTR_SDMMC_D1), MP_ROM_PTR(&pin_GPIO17) },     // SDMMC_D1 pin_GPIO17
    { MP_ROM_QSTR(MP_QSTR_SDMMC_D2), MP_ROM_PTR(&pin_GPIO21) },     // SDMMC_D2 pin_GPIO21
    { MP_ROM_QSTR(MP_QSTR_SDMMC_D3), MP_ROM_PTR(&pin_GPIO18) },     // SDMMC_D3 pin_GPIO18
    { MP_ROM_QSTR(MP_QSTR_SDMMC_CLK), MP_ROM_PTR(&pin_GPIO12) },    // SDMMC_CLK pin_GPIO12
    { MP_ROM_QSTR(MP_QSTR_SDMMC_CMD), MP_ROM_PTR(&pin_GPIO16) },    // SDMMC_CMD pin_GPIO16

    { MP_ROM_QSTR(MP_QSTR_USB_DN), MP_ROM_PTR(&pin_GPIO19) },       // USB_DN pin_GPIO19
    { MP_ROM_QSTR(MP_QSTR_USB_DP), MP_ROM_PTR(&pin_GPIO20) },       // USB_DP pin_GPIO20

    { MP_ROM_QSTR(MP_QSTR_LED_DI_PIN), MP_ROM_PTR(&pin_GPIO40) },   // LED_DI_PIN pin_GPIO40 // APA102 LED
    { MP_ROM_QSTR(MP_QSTR_LED_CI_PIN), MP_ROM_PTR(&pin_GPIO39) },   // LED_CI_PIN pin_GPIO39 // APA102 LED

    { MP_ROM_QSTR(MP_QSTR_TFT_CS_PIN), MP_ROM_PTR(&pin_GPIO4) },    // TFT_CS_PIN pin_GPIO4
    { MP_ROM_QSTR(MP_QSTR_TFT_SDA_PIN), MP_ROM_PTR(&pin_GPIO3) },   // TFT_SDA_PIN pin_GPIO3
    { MP_ROM_QSTR(MP_QSTR_TFT_SCL_PIN), MP_ROM_PTR(&pin_GPIO5) },   // TFT_SCL_PIN pin_GPIO5
    { MP_ROM_QSTR(MP_QSTR_TFT_DC_PIN), MP_ROM_PTR(&pin_GPIO2) },    // TFT_DC_PIN pin_GPIO2
    { MP_ROM_QSTR(MP_QSTR_TFT_RES_PIN), MP_ROM_PTR(&pin_GPIO1) },   // TFT_RES_PIN pin_GPIO1
    { MP_ROM_QSTR(MP_QSTR_TFT_LED_PIN), MP_ROM_PTR(&pin_GPIO38) },  // TFT_LED_PIN pin_GPIO38

    { MP_ROM_QSTR(MP_QSTR_STEMMA_RX), MP_ROM_PTR(&pin_GPIO44) },    // STEMMA_RX pin_GPIO44
    { MP_ROM_QSTR(MP_QSTR_STEMMA_TX), MP_ROM_PTR(&pin_GPIO43) },    // STEMMA_TX pin_GPIO43
};
MP_DEFINE_CONST_DICT(board_module_globals, board_module_globals_table);
