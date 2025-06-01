## Memory Alignment in C
Memory alignment refers to the way data is arranged and accessed in memory. Most processors
are optimized to read and write data at specific memory addresses, typically aligned to the size of
the data type. For example:

- A char (1 byte) can be accessed at any memory address.
- A short (2 bytes) should be accessed at addresses that are multiples of 2.
- An int (4 bytes) should be accessed at addresses that are multiples of 4.

1.  Aligned memory access means that the data is located at an address that matches its size, which
allows the processor to read or write the data in a single operation. 
2.  Misaligned access can lead to performance penalties or even hardware exceptions on some systems.

### Why Alignment Matters
1. Performance: Accessing aligned data is faster because the processor can read or write the data
in a single operation. Misaligned access may require multiple operations, increasing latency.
2. Hardware Requirements: Some architectures strictly require aligned access, and accessing
misaligned data can cause faults or exceptions.
3. Memory Efficiency: Proper alignment can also impact the efficiency of memory usage, as
misaligned access can lead to wasted cycles.

### Structure Padding
Structure padding is a technique used by compilers to ensure that the members of a structure are
properly aligned in memory. This often results in extra bytes being added between members or at
the end of the structure. 

For example:
```c
struct example {
char a; // 1 byte
int b; // 4 bytes
char c; // 1 byte
};
```
Example Layout Without Padding : Without padding, the memory layout might look like this (assuming no padding):

Address | Content
--- | ---
0x00a |
0x01b | (part)
0x02b | (part)
0x03b | (part)
0x04b | (part)
0x05c |

Example Layout With Padding: To align `int b` on a 4-byte boundary, padding bytes are added:

Address | Content
--- | ---
0x00a |
0x01  | (padding)
0x02  | (padding)
0x03  | (padding)
0x04b |
0x05b |
0x06b |
0x07b |
0x08c |


Proper alignment and padding ensure efficient data access and manipulation, which is crucial for
the performance and stability of embedded systems.