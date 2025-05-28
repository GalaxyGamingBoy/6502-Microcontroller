.struct VIA0
    .org $A000

    RB     .byte        ; $A000 - Register B (Input/Output)
    RA     .byte        ; $A001 - Register A (Input/Output)
    DDRB   .byte        ; $A002 - Data Direction Register B
    DDRA   .byte        ; $A003 - Data Direction Register A
    T1CL   .byte        ; $A004 - Timer 1 Counter Low
    T1CH   .byte        ; $A005 - Timer 1 Counter High
    T1LL   .byte        ; $A006 - Timer 1 Latch Low
    T1LH   .byte        ; $A007 - Timer 1 Latch High
    T2CL   .byte        ; $A008 - Timer 2 Counter Low
    T2CH   .byte        ; $A009 - Timer 2 Counter High
    SR     .byte        ; $A00A - Shift Register
    ACR    .byte        ; $A00B - Auxiliary Control Register
    PCR    .byte        ; $A00C - Peripheral Control Register
    IFR    .byte        ; $A00D - Interrupt Flag Register
    IER    .byte        ; $A00E - Interrupt Enable Register
    RANH   .byte        ; $A00F - Register A No Handshake
.endstruct

.struct VIA1
    .org 9000

    RB     .byte        ; $9000 - Register B (Input/Output)
    RA     .byte        ; $9001 - Register A (Input/Output)
    DDRB   .byte        ; $9002 - Data Direction Register B
    DDRA   .byte        ; $9003 - Data Direction Register A
    T1CL   .byte        ; $9004 - Timer 1 Counter Low
    T1CH   .byte        ; $9005 - Timer 1 Counter High
    T1LL   .byte        ; $9006 - Timer 1 Latch Low
    T1LH   .byte        ; $9007 - Timer 1 Latch High
    T2CL   .byte        ; $9008 - Timer 2 Counter Low
    T2CH   .byte        ; $9009 - Timer 2 Counter High
    SR     .byte        ; $900A - Shift Register
    ACR    .byte        ; $900B - Auxiliary Control Register
    PCR    .byte        ; $900C - Peripheral Control Register
    IFR    .byte        ; $900D - Interrupt Flag Register
    IER    .byte        ; $900E - Interrupt Enable Register
    RANH   .byte        ; $900F - Register A No Handshake
.endstruct

.struct ACIA0
    .org $8800

    DATA   .byte        ; $8800 - Data Register
    STATUS .byte        ; $8801 - Status Register
    CMD    .byte        ; $8802 - Command Register
    CTRL   .byte        ; $8803 - Control Register
.endstruct

.struct ACIA1
    .org $8400

    DATA   .byte        ; $8400 - Data Register
    STATUS .byte        ; $8401 - Status Register
    CMD    .byte        ; $8402 - Command Register
    CTRL   .byte        ; $8403 - Control Register
.endstruct