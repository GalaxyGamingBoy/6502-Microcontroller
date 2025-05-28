# Journal

| Session | Date                  | Hours Spent |
| ------- | --------------------- | ----------- |
| **1**   | May 18, 2025          | 3           |
| **2**   | May 19, 2025          | 5           |
| **3**   | May 20, 2025          | 4           |
| **4**   | May 21, 2025          | 6           |
| **5**   | May 22, 2025          | 5           |
|         | **Total Hours Spent** | **23**      |

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

## Session 3: May 20, 2025 - EEPROM & SRAM
**_Hours Spent: 4_**

Today is a pretty light but fundamental day on designing the schematic. This is the first introduction of the SRAM and EEPROM modules, the RAM and ROM of our controller. 

Here is a schematic of how they are connected  
<img width="466" alt="Screenshot 2025-05-22 at 8 10 17 PM" src="https://github.com/user-attachments/assets/b6f8587e-6c37-4fe2-9fa1-e06b75b759bd" />


> [!NOTE]
> This schematic showcases a different memory mapping than the original that was switched on the 4th Session

The A0-A15 pins are directly connected to the 65C02 address bus while the `DQ0`-`DQ7` and `I/O0`-`I/O7` are connected to the data bus. The important thing to note here are the Chip Select and Chip Enable logic for the SRAM and EEPROM.

### Timings - EEPROM
The EEPROM I’m using, the AT28C256, has a read access time of 150ns. According to the 65C02 datasheet, the address setup time is 30ns. This means the total minimum delay for a read operation is around 180ns. Additionally, the logic gates involved introduce a worst-case propagation delay of 25ns each, resulting in a total of 50ns delay for the Chip Select signal to propagate through the logic circuitry.

That limits our clock speed to 4,3478MHz at the worst possible outcome

<img width="699" alt="Screenshot 2025-05-22 at 8 15 58 PM" src="https://github.com/user-attachments/assets/58a48617-7c81-4451-9db6-5460c57210ac" />  
<p style="text-align:center;">  
Figure: W65C02 timing diagram
</p>  

> [!warning] 
> The above times is only a guesstimate, don't take it for granted and I am not going through part of the R/W flow to discuss every delay

### Timings - SRAM
The SRAM module I'm using, the AS6C6225, has a read/write delay of approximately 55ns. Accounting for logic gate delays at worst environmental factors, which are again ~50ns, we can measure and confirm if our SRAM module is compatible with the controller.

The read part seems to be in line with what we expect, plenty of time for the clock and the read to happen. Now onto the write part, the other crucial part of why we need a RAM module.

Upon closer inspect to the write characteristics and timing cycle diagram we can spot a potential issue.
<img width="576" alt="Screenshot 2025-05-22 at 8 26 56 PM" src="https://github.com/user-attachments/assets/95f8e9e5-59e9-4a55-b4fa-358a9acd89cb" />  
<img width="657" alt="Screenshot 2025-05-22 at 8 24 49 PM" src="https://github.com/user-attachments/assets/e7bb2c41-b74f-433f-a4e0-3056bbf56948" />  
<p style="text-align:center;">
Figure: AS6C6225 Timing Table
</p>

The address can be invalidated before the write happens, meaning that there is a chance to write data in an unknown place in RAM and corrupt it. The recommended solution for this according to many forum posts and other designs from 6502.org many choose to tie the SRAM Clock Enable pin to the clock so it only write and stops writing before the address changes, The address hold time in this case is 10ns.

With that in consideration we have landed in this clock chip arrangement
![6502Microcontroller-MemoryMatching](https://github.com/user-attachments/assets/d1026305-0e8b-4404-b3d2-0270763e7448)

> [!NOTE]
> This schematic showcases a different memory mapping than the original that was switched on the 4th Session but the idea is the same

## Session 4: May 21, 2025 - Memory Rework, PD, Crystal, IO, ACIA, EEPROM Programmer
**_Hours Spent: 6_**

Lots of changes today on the schematic, first and foremost I discovered and spend a lot of time reading the [6502 Primer](https://wilsonminesco.com/6502primer/), which has been a massive help.

A lot of time today was spent trying to figure out not intutive and cross checking that the SRAM timings work fine. I also spent a lot of time researching the correct footprints from LCSC that I will need to have in order to begin the design of the PCB module.

The most important change for today is the reworked memory map which priorities RAM space than ROM space. Here is a map of the new memory space:

| From   | To     | Usage |
| ------ | ------ | ----- |
| 0x0000 | 0x7FFF | SRAM  |
| 0x8400 | 0x87FF | ACIA1 |
| 0x8800 | 0x8FFF | ACIA0 |
| 0x9000 | 0x9FFF | VIA1  |
| 0xA000 | 0xBFFF | VIA0  |
| 0xC000 | 0xFFFF | ROM   |

![6502Microcontroller-MemoryMatching](https://github.com/user-attachments/assets/d1026305-0e8b-4404-b3d2-0270763e7448)

Another thing I wanted to tackle today are the I/O ports and expansion slots, as such I hooked up both the VIA's and ACIA's pins to headers on the board. I also exposed the power pins and interrupt handlers. Last thing to note is the addition of a header of rows that expand a modular interface of the address and data lines of the 6502 for further expansion using flex cables. [^4]

![6502Microcontroller-Connectors](https://github.com/user-attachments/assets/2f69c4ec-c515-42b1-9590-a8189b178e3d)

The board will also contain a EEPROM Programmer controlled by a RPI pico using [picoprom](github.com/gfoot/picoprom?tab=readme-ov-file)

![6502Microcontroller-EEPROM Programmer](https://github.com/user-attachments/assets/3bccf6e8-ed48-4551-a2f5-5b70a78e0b51)

The final board revision will contain 2x VIAs and 2x ACIAs for a lot of I/O opportunities and serial.

> [!info] 
> A cool feature I will try to implement is on the fly program execution using serial

![6502Microcontroller-IO](https://github.com/user-attachments/assets/b5fef0bb-743d-4e72-83b9-a8dff2bd747e)

Now for the main board design, I've also added a USB-C & DC Barrel Jack power source. For the Interrupts I have exposed a header that using jumper cables one will be able to select where the interrupt gets chosen from. Last thing to note is that the crystal oscillator now exposes a header for override the board oscillator with an external

![6502Microcontroller](https://github.com/user-attachments/assets/5d55f149-d996-4ec2-a4f2-f499ea7c2578)

[^4]: May be removed for speed and PCB implementation reasons, see 6502 primer

## Session 5: May 22, 2025 - Schematic Polishing, Decoupling Capacitors
**_Hours Spent: 5_**

Today was a lot of important progress on polishing the kicad schematics and adding all the needed capacitors as well as a voltage step down converter for the DC Barrel Jack.

Before this moment I haven't checked the Electric Rule Checker at all, and after I did I was in for a shock. At least 100+ violations of `Bus graphically connected but is not a member of that bus`. Hmm that was a bit suspicious, last time I used KiCad buses I never got that error

After a bit of investigation work, [this](https://forum.kicad.info/t/solved-bus-graphically-connected-but-is-not-a-member-of-that-bus/39761/2) forum post clued me in to what was happening. Since the last time I used KiCad buses was a while ago on an older version for platform control the buses on the newer kicad version were updated. After painstakingly rerouting all of the schematic wire I was still getting bus violations, but to duplicate entries?

After a lot of head scratching the issue was my bus alias definitions, it turns out the nested bus names also act as local/global variables to the schematic. Oops...

<img width="1582" alt="KiCad Bus Alias" src="https://github.com/user-attachments/assets/a34dacaf-2d8e-461a-b191-82e2d099676a" />


I've also spend some time today on assigning proper footprints and getting the necessary LCSC footprint parts to every component, that process was very time consuming because I had to export every easyeda part by hand. Thankfully, or not, I decided to use the included DIP Socket footprints of KiCad thinking that they were going to work okay.

<img width="1547" alt="KiCad Footprints" src="https://github.com/user-attachments/assets/1caf1cd3-a6d3-4f3f-9e83-b80886a6849e" />


> [!NOTE]
> The screenshot was taken after the fact because I accidentally deleted the original one, woops
