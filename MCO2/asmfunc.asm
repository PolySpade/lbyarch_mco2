; assembly part using x86-64

section .data
divisor dq 255.0

section .text
bits 64
default rel ; to handle address relocation

global asm_imgCvtGrayIntToDouble

asm_imgCvtGrayIntToDouble:
;rcx - pointer to pointer int array
;rdx - pointer to pointer doubles array
;r8d - contains rows [integer]
;r9d - contains columns [integer]
;r10 - pointer to current row (int array)
;r11 - pointer to current row (double array)
;r12 - pointer to current column (int array)
;r13 - pointer to current column (double array)
;r14d - row counter
;r15d - column counter

    xor r14,r14;column counter
    xor r15,r15;row counter

    row_loop:
        mov r10, [rcx + r14 * 8]; rows [integer]
        mov r11, [rdx + r14 * 8]; rows [double]
        xor r15, r15
        ;check if maximum rows reach
        cmp r14d, r8d
        je end

        inc r14d
        jmp col_loop

    col_loop:
        lea r12, [r10 + r15 * 4]; columns [integer]
        lea r13, [r11 + r15 * 8]; columns [double]

        ;convert int to double
        mov eax, [r12]
        cvtsi2sd xmm0, eax
        
        ;divide by 255
        movsd xmm1, [divisor]
        VDIVSD xmm3, xmm0, xmm1

        movsd [r13], xmm3; store to double array

        inc r15d
        ;check if maximum columns reach
        cmp r15d, r9d
        je row_loop


        jmp col_loop

    end:
        ret


