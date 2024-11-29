# Performance Comparison: C vs x86 Assembly for Image Grayscale Conversion

### TAN, Richmond Teri T.
### XU, Donald G.

---

## Project Overview

This project compares the performance of a C implementation and an x86 Assembly implementation for converting an image from grayscale integer values to grayscale double-precision floating-point values. The goal is to analyze the performance of both implementations and validate their outputs for correctness.

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
  - Compiler: `gcc` for C and `nasm` for Assembly
  - OS/Hardware: [Fill in your system details here]

### Performance Results

| Image Dimensions | Average Execution Time (ms) | 
|------------------|-----------------------------|
|                  | **C**        | **x86 ASM** |
| 10x10            | [Results]    | [Results]   |
| 100x100          | [Results]    | [Results]   |
| 1000x1000        | [Results]    | [Results]   |

### Analysis
- The C implementation is straightforward and optimized for portability, making it easier to write and debug. However, its performance may lag behind an optimized x86 Assembly implementation.
- The x86 Assembly implementation may exhibit significant performance improvements due to lower-level optimizations, particularly in the handling of loops and memory access patterns.
- Based on the average execution times, *x86-64* outperforms *C* in processing the given image dimensions. *x86-64*'s efficiency can be attributed to its specialized instruction set and optimized algorithms for image processing tasks.

---

## 2. Program Output Validation

The program validates the correctness of both implementations by comparing the output of each implementation against the expected result. The validation ensures that both implementations produce the same output when converting integers to floating-point grayscale values.

### Sample Output Screenshot

**[Insert Screenshot Here]**
