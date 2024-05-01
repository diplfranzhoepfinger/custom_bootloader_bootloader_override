


```
FAILED: bootloader.elf 
/home/franz/.espressif/tools/xtensa-esp-elf/esp-13.2.0_20230928/xtensa-esp-elf/bin/../lib/gcc/xtensa-esp-elf/13.2.0/../../../../xtensa-esp-elf/bin/ld: bootloader.elf section `.dram0.rodata' will not fit in region `dram_seg'
/home/franz/.espressif/tools/xtensa-esp-elf/esp-13.2.0_20230928/xtensa-esp-elf/bin/../lib/gcc/xtensa-esp-elf/13.2.0/../../../../xtensa-esp-elf/bin/ld: region `dram_seg' overflowed by 280 bytes
collect2: error: ld returned 1 exit status
ninja: build stopped: subcommand failed.
[4/9] cd /home/franz/git/franz/custom_bootl

```





https://github.com/espressif/esp-idf/issues/13727

```
franz@franz-Ubuntu:~/git/franz/custom_bootloader_bootloader_override/bootloader_override$ idf_size.py ./build/bootloader/bootloader.map 
Total sizes:
Used stat D/IRAM:   29734 bytes (  -1062 remain, 103.7% used) Overflow detected! You can run idf.py size-files for more information.
      .data size:      20 bytes
      .bss  size:     272 bytes
      .text size:   15242 bytes
    .rodata size:   14200 bytes
Total image size:   29462 bytes (.bin may be padded larger)


```
