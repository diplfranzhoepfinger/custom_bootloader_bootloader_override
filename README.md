


```
Error: Bootloader binary size 0x89e0 bytes is too large for partition table offset 0x8000. Bootloader binary can be maximum 0x8000 (32768) bytes unless the partition table offset is increased in the Partition Table section of the project configuration menu.

```





https://github.com/espressif/esp-idf/issues/13727

```
franz@franz-Ubuntu:~/git/franz/custom_bootloader_bootloader_override/bootloader_override$ idf_size.py ./build/bootloader/bootloader.map 
Total sizes:
Used stat D/IRAM:   31874 bytes (  -1154 remain, 103.8% used) Overflow detected! You can run idf.py size-files for more information.
      .data size:    2068 bytes
      .bss  size:     272 bytes
      .text size:   15290 bytes
    .rodata size:   14244 bytes
Total image size:   31602 bytes (.bin may be padded larger)



```
