/*
 * SPDX-FileCopyrightText: 2015-2021 Espressif Systems (Shanghai) CO LTD
 *
 * SPDX-License-Identifier: Apache-2.0
 */
#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include "sdkconfig.h"
#include "esp_log.h"
#include "bootloader_init.h"
#include "bootloader_utility.h"
#include "bootloader_common.h"

static const char* TAG = "boot";

static int select_partition_number(bootloader_state_t *bs);

extern
uint32_t
calculate_crc32c(uint32_t crc32c,
    const unsigned char *buffer,
    unsigned int length);


extern uint32_t crc32_tab[];
extern uint32_t crc32Table[256];
extern uint32_t sctp_crc_tableil8_o32[256];
extern uint32_t sctp_crc_tableil8_o40[256];
extern uint32_t sctp_crc_tableil8_o48[256];
extern uint32_t sctp_crc_tableil8_o56[256];
extern uint32_t sctp_crc_tableil8_o64[256];
extern uint32_t sctp_crc_tableil8_o72[256];
extern uint32_t sctp_crc_tableil8_o80[256];
extern uint32_t sctp_crc_tableil8_o88[256];

/*
 * We arrive here after the ROM bootloader finished loading this second stage bootloader from flash.
 * The hardware is mostly uninitialized, flash cache is down and the app CPU is in reset.
 * We do have a stack, so we can do the initialization in C.
 */
void __attribute__((noreturn)) call_start_cpu0(void)
{
    // 1. Hardware initialization
    if (bootloader_init() != ESP_OK) {
        bootloader_reset();
    }

#ifdef CONFIG_BOOTLOADER_SKIP_VALIDATE_IN_DEEP_SLEEP
    // If this boot is a wake up from the deep sleep then go to the short way,
    // try to load the application which worked before deep sleep.
    // It skips a lot of checks due to it was done before (while first boot).
    bootloader_utility_load_boot_image_from_deep_sleep();
    // If it is not successful try to load an application as usual.
#endif

    // 2. Select the number of boot partition
    bootloader_state_t bs = {0};
    int boot_index = select_partition_number(&bs);
    if (boot_index == INVALID_INDEX) {
        bootloader_reset();
    }

    // 2.1 Print a custom message!
    esp_rom_printf("[%s] %s\n", TAG, CONFIG_EXAMPLE_BOOTLOADER_WELCOME_MESSAGE);


    uint32_t crc = calculate_crc32c(0xffffffff, (const unsigned char *)CONFIG_EXAMPLE_BOOTLOADER_WELCOME_MESSAGE, strlen(CONFIG_EXAMPLE_BOOTLOADER_WELCOME_MESSAGE));

    esp_rom_printf("[%s] crc %d \n", TAG, crc);



    esp_rom_printf("[%s] crc32_tab[0] %d \n", TAG, crc32_tab[0]);
    esp_rom_printf("[%s] crc32Table[0] %d \n", TAG, crc32Table[0]);
    esp_rom_printf("[%s] sctp_crc_tableil8_o32[0] %d \n", TAG, sctp_crc_tableil8_o32[0]);
    esp_rom_printf("[%s] sctp_crc_tableil8_o40[0] %d \n", TAG, sctp_crc_tableil8_o40[0]);
    esp_rom_printf("[%s] sctp_crc_tableil8_o48[0] %d \n", TAG, sctp_crc_tableil8_o48[0]);
    esp_rom_printf("[%s] sctp_crc_tableil8_o56[0] %d \n", TAG, sctp_crc_tableil8_o56[0]);
    esp_rom_printf("[%s] sctp_crc_tableil8_o64[0] %d \n", TAG, sctp_crc_tableil8_o64[0]);
    esp_rom_printf("[%s] sctp_crc_tableil8_o72[0] %d \n", TAG, sctp_crc_tableil8_o72[0]);
    esp_rom_printf("[%s] sctp_crc_tableil8_o80[0] %d \n", TAG, sctp_crc_tableil8_o80[0]);
    esp_rom_printf("[%s] sctp_crc_tableil8_o88[0] %d \n", TAG, sctp_crc_tableil8_o88[0]);



    // 3. Load the app image for booting
    bootloader_utility_load_boot_image(&bs, boot_index);
}

// Select the number of boot partition
static int select_partition_number(bootloader_state_t *bs)
{
    // 1. Load partition table
    if (!bootloader_utility_load_partition_table(bs)) {
        ESP_LOGE(TAG, "load partition table error!");
        return INVALID_INDEX;
    }

    // 2. Select the number of boot partition
    return bootloader_utility_get_selected_boot_partition(bs);
}

// Return global reent struct if any newlib functions are linked to bootloader
struct _reent *__getreent(void)
{
    return _GLOBAL_REENT;
}
