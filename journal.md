# Journal

| Session | Date                  | Hours Spent |
| ------- | --------------------- | ----------- |
| **1**   | May 18, 2025          | 3           |
| **2**   | May 19, 2025          | 5           |
|         | **Total Hours Spent** | **8**       |


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

## Session 2: May 19, 2025 - The start of the Schematic
**_Hours Spent: 5_**

The main focus on today has mostly been documentation and putting a start on the PCB design. I focused on connecting the 2 fundamental parts of the project, the W65C02, which is the controller, to the W65C22, the Versatile Interface Adapter. Below is how the schematic is currently looking as well as a brief description on each component

![SCH_20250518](https://github.com/user-attachments/assets/ea9628f2-571f-4fdb-91d6-8411d9ea718a)

| Component            | Description                                                                                                        |
| -------------------- | ------------------------------------------------------------------------------------------------------------------ |
| W65C02               | The main chip, exposes the R/W pin, Data Bus and Address Bus for the other Components                              |
| VIA1                 | The first Versatile Interface Adapter for I/O operations. Exposes both ports on the VIA0_P bus                     |
| Decoupling Caps      | Stabilizes Power Supply Voltage, one cap for each IC                                                               |
| PWR PINS<br>VIA1 Pin | The header to expose the power to the future PCB                                                                   |
| PWR TGL              | The toggle switch for the power, defaults to disabled via a pull-down resistor                                     |
| OSCILLATOR           | Provides a clock signal for the ICs, Frequency is TBD but I'll start with 1MHz                                     |
| RESET BTN            | Allows for manual operation resets via bridging the ground voltage to the W65C02                                   |
| I/O Address Matching | Handles the chip select signal for the VIA. Currently the VIA is taking up the whole 0x4000 - 0x8000 memory block. |

The first drafts of the memory map have also been started, here is the current plan

| From   | To     | Usage          |
| ------ | ------ | -------------- |
| 0x0000 | 0x4000 | RAM[^2]        |
| 0x4000 | 0x8000 | I/O Operations |
| 0x8000 | 0xFFFF | ROM[^3]        |
[^2]: To Be Determined at a later date
[^3]: Subject to change but most likely will remain the same

> [!NOTE]  
> The memory map still needs a lot of work but I am for maximum efficiency on both ROM and RAM while keeping costs low.

So far so good, the documentation has been a non issue and is rather well written. The architecture is very simple to which makes it easier to implement than depend on already made solutions. 
