


```
Bootloader binary size 0x7ca0 bytes. 0x360 bytes (3%) free.

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
