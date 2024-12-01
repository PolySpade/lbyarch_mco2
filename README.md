# Performance Comparison: C vs x86-64 Assembly for Image Grayscale Conversion

### TAN, Richmond Teri T.
### XU, Donald G.

---

## Project Overview

This project compares the performance of a *C* implementation and an *x86-64* Assembly implementation for converting an image from grayscale integer values to grayscale double-precision floating-point values. The goal is to analyze the performance of both implementations and validate their outputs for correctness.

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
  - OS/Hardware: [Fill in your system details here]
    - Operating System: Windows 11
    - Processor: AMD Ryzen 5 3500X 6-Core Processor 3.70 GHz
    - Memory: 32GB DDR4 2400 MT/s
    - Graphics Card: NVIDIA GeForce RTX 2070
    - Storage: 2TB HDD

### Performance Results

| Image Dimensions (Height x Width) | C (ms) | x86-64 (ms) |
|---|---|---|
| 10 x 10 | 0.000000 | 0.000000 |
| 100 x 100 | 0.033333 | 0.000000 |
| 1000 x 1000 | 4.200000 | 1.233333 |

### Analysis
- The C implementation is straightforward and optimized for portability, making it easier to write and debug. However, its performance may lag behind an optimized x86 Assembly implementation.
- The x86 Assembly implementation may exhibit significant performance improvements due to lower-level optimizations, particularly in the handling of loops and memory access patterns.
- Based on the average execution times, *x86-64* outperforms *C* in processing the given image dimensions. *x86-64*'s efficiency can be attributed to its specialized instruction set and optimized algorithms for image processing tasks.

---

### Sample Output Screenshot

![image](https://github.com/user-attachments/assets/a32dc653-5b9f-4d7d-bb8c-98b5a0f493df)

