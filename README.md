# oled_ssd1306

这个驱动程序在STM32f103C8T6核心板完美运行。核心频率为72MHz。在使用驱动程序 时，必须保证在你的项目里使用STM32F1xx系列的HAL库。如需移植，只需修改底层文件关于SPI部分，在保证硬件SPI可用的情况下，实现两个底层函数即可。

1. void SPIWrite(uint8_t chr);

   发送一个字符。

2. void SPIWriteBuffer(uint8_t* buffer, uint16_t Size);

   发送可知长度的字符串。

如果硬件SPI不可用，请参考SPI时序，实现软件模拟SPI。



此版本驱动，移植了Adafruit_SSD1306库和Adafruit-GFX-Library。

[Adafruit_SSD1306](https://github.com/adafruit/Adafruit_SSD1306)

[Adafruit-GFX-Library](https://github.com/adafruit/Adafruit-GFX-Library)