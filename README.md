# General Purpose 6502 Microcontroller

The 6502-Based Microcontroller is a custom-built, general-purpose development board powered by the 8-bit W65C02S processor, offering a retro yet powerful platform for exploring low-level computing. Featuring 32 KiB of RAM, 16 KiB of EEPROM storage, 32 GPIO pins, dual serial interfaces, and a 4 MHz adjustable clock, brings hardware of the Apple I era to run on an on par level to an Arduino Uno. This project is designed with attention to compatibility and serves as an education platform in interacting and understanding low-level protocols, like I2C or SPI, and embedded systems with hands-on hardware, minimizing abstractions.

## Why?
Ever wanted to use the Apple I or NES like an Arduino? The one thing in common with both of these platforms is the 8-bit processor known as the 6502 or it’s modern cousin the W65C02S. I was always fascinated by the multiple features it has even as such an old microprocessor. Thus I decided to build my own 6502 powered microcontroller that is inspired by this

## Features

- 32 GPIO Pins
- 16 KiB of EEPROM Storage
- 32 KiB RAM
- 2x Serial Interface

_Want to see the progress and the making of the project? Check [journal.md]_

## Bill of Materials (BOM) for 2 Units
BOM is available [here](https://docs.google.com/spreadsheets/d/e/2PACX-1vSp7wmMJoBrFsNmcZfdQle1DgGpygNZzK69nfCzy5W3IegrDRIj2T4DXEuusGqE_R13mvxW_oDpiJff/pubhtml?gid=0&single=true)

## CAD
The CAD is avainable in OnShape [here](https://cad.onshape.com/documents/d6cc344b12fedad0d9fb37e9/w/bafa9b4189d3c45a687e4c0f/e/759885ef1089c42301fe9ef4) or the exported files in the `6502 GPMC/` folder.

## Schematic & PCB
The Schematic and PCB is available in the 6502-Microcontroller-Kicad folder in this repo. It is made using KiCad. 
> [!NOTE]
> You might have to import some libraries, every library is included in the KiCad GitHub

![image](https://github.com/user-attachments/assets/c7d117e9-a89a-4248-a3b2-7378e12661e8)
![6502 GPMC Case](https://github.com/user-attachments/assets/3533e070-2ea0-4ffe-9ed2-0b4e10293507)

## Code
On the root directory of this repository there is a `sample_project/` directory with all the starting files you need to assemble code for this microcontroller.  

### Steps
1. Install CC65
2. Run `make` in project directory
3. Flash `.bin` file to EEPROM
4. Done!
