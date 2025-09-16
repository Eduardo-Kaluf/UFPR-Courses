section .data

PI: dq 3

section .text

global _start

area:
    push rbp
    mov rbp, rsp

    mov rax, [rbp + 16]
    mul rax

    mov rbx, [PI]
    mul rbx

    pop rbp
    ret

_start:
    push 5 ;; local variable r = 5
    push 5
    call area
    add rsp, 8
    mov rdi, rax
    add rsp, 8
    mov rax, 60
    syscall
