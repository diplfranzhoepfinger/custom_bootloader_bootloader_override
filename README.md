


```
Bootloader binary size 0x89e0 bytes. 0x620 bytes (4%) free.
```





https://github.com/espressif/esp-idf/issues/13727

```
franz@franz-Ubuntu:~/git/franz/custom_bootloader_bootloader_override/bootloader_override$ idf_size.py ./build/bootloader/bootloader.map 
Total sizes:
Used stat D/IRAM:   35386 bytes (  -4666 remain, 115.2% used) Overflow detected! You can run idf.py size-files for more information.
      .data size:   13332 bytes
      .bss  size:     272 bytes
      .text size:   15450 bytes
    .rodata size:    6332 bytes
Total image size:   35114 bytes (.bin may be padded larger)
franz@franz-Ubuntu:~/git/franz/custom_bootloader_bootloader_override/bootloader_override$ 




```
