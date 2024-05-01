idf_component_register(SRCS 
                             "bootloader_start.c"
                             "crc32.c" 
                    REQUIRES bootloader bootloader_support)

idf_build_get_property(target IDF_TARGET)
set(scripts "ld/bootloader.ld"
            "ld/bootloader.rom.ld")

target_linker_script(${COMPONENT_LIB} INTERFACE "${scripts}")
