# LBYARCH MCO2 README

### Group 8:
### TAN, Richmond Teri T.
### XU, Donald G.

---

## Project Overview

To develop a C and x86-64 assembly program to efficiently convert grayscale images from integer-based representation to double-precision floating-point representation.

---

## 1. Execution Time and Performance Analysis

### Test Setup
- **Tested on**: Image arrays of dimensions:
  - 10x10
  - 100x100
  - 1000x1000
- **Number of runs**: 30 for each test case.
- **Environment**: 
  - Programming Language: C
  - Assembly Language: x86-64
  - Compiler: *gcc* for C and *nasm* for Assembly
  - OS/Hardware:
    - Operating System: Windows 11
    - Processor: AMD Ryzen 5 3500X 6-Core Processor 3.70 GHz
    - Memory: 32GB DDR4 2400 MT/s
    - Graphics Card: NVIDIA GeForce RTX 2070
    - Storage: 2TB HDD

### Performance Results

| Image Dimensions (Height x Width) | x86-64 (ms) |
|---|---|
| 10 x 10 | 0.000000 |
| 100 x 100 | 0.000000 |
| 1000 x 1000 | 1.433333 |

### Analysis
- While hand-coded assembly can potentially outperform C in specific scenarios, modern compilers often generate highly optimized code. Assembly's platform-specific nature, low-level complexity, and development time often outweigh potential performance gains. C offers portability, readability, and faster development, making it a more practical choice for most software development tasks.

---

### Sample Output Screenshot

![image](https://github.com/user-attachments/assets/6685ffaf-9250-4b1c-a764-096c5a0a4ded)


