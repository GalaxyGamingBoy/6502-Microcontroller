# Journal

| Session | Date                  | Hours Spent |
| ------- | --------------------- | ----------- |
| **1**   | May 18, 2025          | 3           |
|         | **Total Hours Spent** | **3**       |

## Session 1: May 18, 2025 - Beginning
**_Hours Spent: 3_**

Every project needs to start somewhere, I have been wanting to mess with the 6502 microcontroller for a while now, and I wanted to expand my hardware experience as well as improve my assembly skills since I started making games for the [GameBoy](https://github.com/GalaxyGamingBoy/gb-flappy).

The original project idea was spontaneous and originated as a challenge to use a limiting chip that powered hundred of well-known devices, the 6502, in the modern age where tiny and powerful chips like the RP2040 dominate. 

The current chips I definitely plan to have are:

|   Chip/Name    |                                 Description                                  | Quantity |
| :------------: | :--------------------------------------------------------------------------: | :------: |
| W65C02S6TPG-14 |          The actual W6502S chip, the brains of the microcontroller           |    1     |
| W65C22S6TPG-14 | The Versatile Interface Adapter of the W6502S, basically handles latched I/O |    2     |
| 256KiB EEPROM  |               The Location where the binary will be read from                |    1     |
|   64 KiB RAM   |                           The General Work RAM[^1]                           |    1     |
[^1]: Actual RAM size TBD

As for the EEPROM, I'll need to make a cheap EEPROM programmer, that turns out to not be that hard with the correct [chips](https://eu.mouser.com/ProductDetail/Texas-Instruments/SN74LS164NE4?qs=SL3LIuy2dWzMustM9SNFlQ%3D%3D), however more research is always needed. A nice to have for the board would be USB-C power.

> [!IMPORTANT]  
> The clock speed of the 6502 is To Be Determined at a later date and will be chosen accordingly to make sure the timings on the RAM are sufficient
