### LLP
- **Part:** Microchip Polarfire MPF500T
- **Type:** FPGA
- **CPU:** Tiger - 1x Microchip MIV_RV32IMAF_L1 Soft CPU @100MHz
- **Architecture:** Tiger 🐅 - 32-bit RISC-V RV32IMAF
- **Cache:** 8kB I$ / 8kB D$ L1 cache
- **RAM:** 4GB (240MB addressable) DDR4-1600 (dev kit) / 8GB ECC DDR4-3200 (prototype Rev2+)
- **Storage:** 64MB SPI Flash (dev kit) / 64MB SPI Flash + 128MB NOR Flash (prototype)
- **FRAM(CDS):** None (dev kit) / 512KB redundant FRAM (prototype)
- **OS:** FreeRTOS
- **Development Kit:** Sundance SE201

Note: Previously used "Tabby🐈" MIV_RV32 3.0 soft CPU was RV32IMC with no cache

### HLP
- **Part:** Xilinx Zynq Ultrascale+
- **Type:** PSoC (Hardware CPU + FPGA)
- **CPU:** 4x ARM A53 @1GHz(approx) / 2x ARM R5F
- **Architecture:** 64-bit Aarch64 (ARMv8-A) / 32-bit ARMv7-R
- **Cache:** 32kB I$ / 32kB D$ L1 cache, 1MB L2 cache
- **RAM:** 4GB DDR4-3200 (dev kit) / 8GB ECC DDR-3200 (prototype)
- **Storage:** 8GB SD Card (dev kit) / 8GB NAND Flash (prototype)
- **FRAM(CDS):** None (dev kit) / 512KB redundant FRAM (prototype)
- **OS:** Xilinx Petalinux (RT_PREEMPT)
- **Development Kit:** Xilinx ZCU102

### Simplified System View
Note this is a massive oversimplification, there are multiple different serial, 
ethernet, and power busses, but this is the basic picture.
``` 
      _______            _______       _____    _____    _____    _____    _____
     |       |          |       |     | 1.n |  | 1.n |  | 1.n |  |     |  |     |
     |  HLP  |          |  LLP  |     | SOL |  | PDX |  | ADC |  | BPP |  | GNC |
     |_______|          |_______|     |_____|  |_____|  |_____|  |_____|  |_____|
      |  |  |            |  |  |        |        |        |        |        |
<-----|  |  |------------|  |  |--------|--------|--------|--------|--------|
PLD Eth  |   Backplane Eth  |                      Serial
         v                  v
       Serial             Serial
         to                 to
       Devices            Devices
```
