section .data

IDADE: dq 12

section .text

global _start

_start:
    add rax, 60
    mov rbx, [IDADE]
    cmp rbx, 18
    jl _OUT
    add rdi, 1
    syscall
_OUT:
    add rdi, 0
    syscall