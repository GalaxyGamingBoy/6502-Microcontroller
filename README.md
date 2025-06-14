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

## BOM

| Part Name                    | Supplier      | Usage                      | Quantity | Price / Qnt (€) | Price / Qnt ($) | Total Price ($) | Link                                                                                                             | Other (ie LCSC Part) |
|------------------------------|---------------|----------------------------|----------|-----------------|-----------------|-----------------|------------------------------------------------------------------------------------------------------------------|----------------------|
| W65C02S6TPG-14               | Mouser        | Processor                  | 2.00     | €11.11          | $12.83          | $25.66          | https://eu.mouser.com/ProductDetail/Western-Design-Center-WDC/W65C02S6TPG-14?qs=opBjA1TV903lvWo9AEKH5w%3D%3D     |                      |
| W65C22S6TPG-14               | Mouser        | I/O                        | 3.00     | €11.30          | $13.05          | $39.15          | https://eu.mouser.com/ProductDetail/Western-Design-Center-WDC/W65C22S6TPG-14?qs=opBjA1TV9038jNZ%252Bop8JdA%3D%3D |                      |
| AT28C256-15PU                | Mouser        | EEPROM                     | 2.00     | €11.04          | $12.75          | $25.50          | https://eu.mouser.com/ProductDetail/Microchip-Technology/AT28C256-15PU?qs=MAR%2F2X5XOp7eAU2%2FlNw9oA%3D%3D       |                      |
| AS6C62256-55PCN              | Mouser        | SRAM                       | 2.00     | €4.51           | $5.21           | $10.42          | https://eu.mouser.com/ProductDetail/Alliance-Memory/AS6C62256-55PCN?qs=LD2UibpCYJqgbIupMJnGTQ%3D%3D              |                      |
| SN74HCT00N                   | Mouser        | LOGIC GATE                 | 4.00     | €0.59           | $0.68           | $2.73           | https://eu.mouser.com/ProductDetail/Texas-Instruments/SN74HCT00N?qs=dQtLEVC3WoZXjES7t3OHbA%3D%3D                 |                      |
| 1.8432 MHz Crystal           | Mouser        | ACIA Crystal               | 2.00     | €1.32           | $1.52           | $3.05           | https://gr.mouser.com/ProductDetail/CTS-Electronic-Components/MP018B?qs=tjlMjqRIEYSLWN5wSKp3lw%3D%3D             |                      |
| 1MHz Crystal                 | Mouser        | Backup Clock               | 2.00     | €2.96           | $3.42           | $6.84           | https://eu.mouser.com/ProductDetail/ECS/ECS-100A-010?qs=GxOUx7aO6nwDnc3%252B6Ta2Kw%3D%3D                         |                      |
| W65C51N6TPG-14               | Mouser        | ACIA / SERIAL              | 3.00     | €8.77           | $10.13          | $30.38          | https://eu.mouser.com/ProductDetail/Western-Design-Center-WDC/W65C51N6TPG-14?qs=AgbsAOSw7WDdUCKSkUixbw%3D%3D     |                      |
| Shunt                        | Mouser        | Jumper Pin                 | 2.00     | €0.36           | $0.42           | $0.83           | https://eu.mouser.com/ProductDetail/Harwin/M7686-05?qs=%252Bk6%2F5FB6qrn2j2nK8fZfOA%3D%3D                        |                      |
| ZIF Socket (Optional)        | Grobotronics  | Quick EEPROM Removal       | 0.00     | €1.50           | $1.73           | $0.00           | https://grobotronics.com/zif-socket.html                                                                         |                      |
| Kapton Tape (Optional)       | Grobotronics  | Tape for Crystal Soldering | 0.00     | €1.80           | $2.08           | $0.00           | https://grobotronics.com/high-temperature-adhesive-tape-green-20mm-33m.html                                      |                      |
| Breadboard (Optional)        | Grobotronics  | External Board             | 0.00     | €2.80           | $3.23           | $0.00           | https://grobotronics.com/breadboard-830-tie-point-classic.html                                                   |                      |
| C1,C2,C3,C4,C5,C7,C9,C10,C11 | JLCPCB / LCSC | PCB Part                   | 18.00    | -               | $0.33           | $5.94           | https://lcsc.com                                                                                                 | C1590                |
| C6                           | JLCPCB / LCSC | PCB Part                   | 2.00     | -               | $0.31           | $0.62           | https://lcsc.com                                                                                                 | C1658                |
| C8                           | JLCPCB / LCSC | PCB Part                   | 4.00     | -               | $0.24           | $0.96           | https://lcsc.com                                                                                                 | C1691                |
| D1,D2                        | JLCPCB / LCSC | PCB Part                   | 4.00     | -               | $0.57           | $2.28           | https://lcsc.com                                                                                                 | C2286                |
| IC1                          | JLCPCB / LCSC | PCB Part                   | 2.00     | -               | $0.66           | $1.32           | https://lcsc.com                                                                                                 | C2332                |
| IC2,IC5                      | JLCPCB / LCSC | PCB Part                   | 4.00     | -               | $0.66           | $2.64           | https://lcsc.com                                                                                                 | C2332                |
| IC3,IC7                      | JLCPCB / LCSC | PCB Part                   | 4.00     | -               | $0.53           | $2.12           | https://lcsc.com                                                                                                 | C2874014             |
| IC4                          | JLCPCB / LCSC | PCB Part                   | 2.00     | -               | $0.53           | $1.06           | https://lcsc.com                                                                                                 | C2874014             |
| IC6,IC8                      | JLCPCB / LCSC | PCB Part                   | 4.00     | -               | $0.53           | $2.12           | https://lcsc.com                                                                                                 | C2874014             |
| J1,J2,J4,J7                  | JLCPCB / LCSC | PCB Part                   | 8.00     | -               | $0.49           | $3.92           | https://lcsc.com                                                                                                 | C18723047            |
| J3,J15                       | JLCPCB / LCSC | PCB Part                   | 4.00     | -               | $0.36           | $1.44           | https://lcsc.com                                                                                                 | C25503122            |
| J5,J8                        | JLCPCB / LCSC | PCB Part                   | 4.00     | -               | $0.45           | $1.80           | https://lcsc.com                                                                                                 | C18723052            |
| J6                           | JLCPCB / LCSC | PCB Part                   | 2.00     | -               | $0.06           | $0.12           | https://lcsc.com                                                                                                 | C92273               |
| J9                           | JLCPCB / LCSC | PCB Part                   | 2.00     | -               | $0.37           | $0.74           | https://lcsc.com                                                                                                 | C456012              |
| J10                          | JLCPCB / LCSC | PCB Part                   | 2.00     | -               | $0.48           | $0.96           | https://lcsc.com                                                                                                 | C431533              |
| J11                          | JLCPCB / LCSC | PCB Part                   | 2.00     | -               | $0.06           | $0.12           | https://lcsc.com                                                                                                 | C92273               |
| J12                          | JLCPCB / LCSC | PCB Part                   | 2.00     | -               | $0.05           | $0.10           | https://lcsc.com                                                                                                 | C7501275             |
| J14                          | JLCPCB / LCSC | PCB Part                   | 2.00     | -               | $0.06           | $0.12           | https://lcsc.com                                                                                                 | C92273               |
| R6                           | JLCPCB / LCSC | PCB Part                   | 2.00     | -               | $0.10           | $0.20           | https://lcsc.com                                                                                                 | C21190               |
| R3                           | JLCPCB / LCSC | PCB Part                   | 2.00     | -               | $0.11           | $0.22           | https://lcsc.com                                                                                                 | C22935               |
| R4,R5                        | JLCPCB / LCSC | PCB Part                   | 4.00     | -               | $0.11           | $0.44           | https://lcsc.com                                                                                                 | C23186               |
| R7                           | JLCPCB / LCSC | PCB Part                   | 2.00     | -               | $0.11           | $0.22           | https://lcsc.com                                                                                                 | C22962               |
| SW2                          | JLCPCB / LCSC | PCB Part                   | 2.00     | -               | $0.40           | $0.80           | https://lcsc.com                                                                                                 | C720477              |
| U1,U2                        | JLCPCB / LCSC | PCB Part                   | 4.00     | -               | $0.21           | $0.84           | https://lcsc.com                                                                                                 | C3034942             |
| U3                           | JLCPCB / LCSC | PCB Part                   | 2.00     | -               | $0.65           | $1.30           | https://lcsc.com                                                                                                 | C347197              |
| Y1                           | JLCPCB / LCSC | PCB Part                   | 2.00     | -               | $0.98           | $1.96           | https://lcsc.com                                                                                                 | C41361468            |
| R1,R8                        | JLCPCB / LCSC | PCB Part                   | 4.00     | -               | $0.10           | $0.40           | https://lcsc.com                                                                                                 | C22978               |
| C12                          | JLCPCB / LCSC | PCB Part                   | 2.00     | -               | $0.24           | $0.48           | https://lcsc.com                                                                                                 | C70225               |
| U4                           | JLCPCB / LCSC | PCB Part                   | 2.00     | -               | $0.70           | $1.40           | https://lcsc.com                                                                                                 | C239897              |
| PCB                          | JLCPCB / LCSC | PCB                        | 1.00     | -               | $14.00          | $14.00          | https://jlcpcb.com                                                                                               |                      |
| PCB ASSEMBLY                 | JLCPCB / LCSC | PCB                        | 1.00     | -               | $15.14          | $15.14          | https://jlcpcb.com                                                                                               |                      |
|                              |               |                            |          |                 |                 |                 |                                                                                                                  |                      |
| SHIPPING                     | Grobotronics  | SHIPPING                   |          | €0.00           | $0.00           |                 |                                                                                                                  |                      |
|                              | JLCPCB / LCSC |                            |          | -               | $29.58          |                 |                                                                                                                  |                      |
| VAT                          |               |                            | MOUSER   | €30.64          | $35.38          |                 |                                                                                                                  |                      |
|                              |               |                            | JLCPCB   | -               | $23.87          |                 |                                                                                                                  |                      |
| TOTAL / UNIT                 |               |                            |          |                 |                 | $210.32         |                                                                                                                  |                      |
| TOTAL                        |               |                            |          |                 |                 | $299.15         |                                                                                                                  |                      |
