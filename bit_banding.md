Bit-banding is a unique and powerful feature available in ARM Cortex-M microcontrollers, designed to simplify and optimize bit manipulation in memory-mapped peripheral registers. It's particularly beneficial for embedded systems where precise control over individual bits within a register is essential. Here's an explanation of how bit-banding works and its advantages:
How Bit-Banding Works:
In a typical embedded system, you often need to read, modify, or write specific bits within a memory-mapped peripheral register. With bit-banding, ARM Cortex-M microcontrollers provide a mechanism to map individual bits of a memory location to unique addresses in a "bit-band region" of memory.
The process involves two key regions in memory:
1. Alias Region: This is the original memory-mapped peripheral register, where each bit has its conventional address.
2. Bit-Band Region: This is a separate region of memory, where each bit in the alias region is mapped to its own unique address.
Here's how it works:
To read or write a specific bit in the alias region, you access the corresponding bit in the bit-band region using its unique address.
When you read or write to the bit-band region, the hardware takes care of translating the operation back to the correct bit in the alias region automatically.
Example:
#include <stdint.h>

//! @brief Convert word address + bit position to bitband address.
//!
//! @param address  Word address containing of bit
//! @param bit      Bit offset (0 = LSB,  31 = MSB)
//! @return Address of bit in bitband region.

volatile uint32_t* getBitBandAddress(volatile void* address, int bit) {
    uint32_t addr = (uint32_t)address ;
    uint32_t word_band_base = addr & 0xf0000000 ;
    uint32_t bit_band_base = word_band_base | 0x02000000 ;
    uint32_t offset = addr - word_band_base ;

    return (volatile uint32_t*)(bit_band_base + (offset * 32) + (bit * 4)) ;
}
// Example usage 1: 160 bit array
uint32_t physical_memory[5] = {0} ;
uint32_t* bit_array = getBitBandAddress(physical_memory, 0) ;
int bit_array_length = sizeof(physical_memory) * CHAR_BIT ;
for (i = 0; i < bit_array_len; i++) {
    bit_array[i] = rand() % 2;
}
// Example usage 2: STM32 USART1 Tx Int Enable/Disable
uint32_t* tx_intr_enable_bit_addr = getBitBandAddress((&(USART1->CR1)), 7) ;

*tx_intr_enable_bit_addr = 0 ; // Disable Tx
*tx_intr_enable_bit_addr = 1 ; // Enable Tx
// Example usage 3: C++ reference version of example 2
uint32_t& tx_intr_enable_bit = *getBitBandAddress((&(USART1->CR1)), 7) ;

tx_intr_enable_bit = 0 ; // Disable Tx
tx_intr_enable_bit = 1 ; // Enable Tx
Advantages of Bit-Banding:
1. Atomic Bit Manipulation: Bit-banding allows you to perform atomic read-modify-write operations on individual bits without the need for masking, shifting, or other complex bit manipulation techniques. This ensures that other operations, even from interrupts, do not interfere with the bit you're modifying.
2. Code Simplification: Bit-banding simplifies code, making it more readable and less error-prone. You can directly manipulate individual bits in peripheral registers without bitwise operations or masking.
3. Faster Execution: Bit-banding can lead to faster execution because it eliminates the need for masking and shifting operations, which can be relatively slow on some microcontrollers. This is especially crucial in real-time systems with strict timing requirements.
4. Improved Code Efficiency: Code that uses bit-banding is often more efficient in terms of both code size and execution speed compared to equivalent code that relies on traditional bit manipulation techniques.
5. Simplified Debugging: Debugging can be more straightforward because you can inspect and modify individual bits in memory using standard memory access tools, such as debuggers or memory viewers.
It's important to note that bit-banding is a feature specific to ARM Cortex-M microcontrollers, and its availability may vary between different Cortex-M processor models. When working with these microcontrollers, understanding and utilizing bit-banding can greatly simplify your code and improve its performance, especially in scenarios where precise bit manipulation is required.

Reference: https://www.linkedin.com/pulse/bit-banding-arm-cortex-m-microcontrollers-uttam-basu/
