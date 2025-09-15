section .data

V: dq 1, 25, 3, 3, 4, 4, 4, 10, 10, 9

section .text

global _start

_start:
    mov rax, 0 ;; iterator
    
_LOOP:
    cmp rax, 10
    jge _OUT
    mov rbx, [V, rax * 8]
    and rbx, 1
    cmp rbx, 1
    je _FALSE
    add rdi, 1
_FALSE:
    add rax, 1
    jmp _LOOP
_OUT:
    mov rax, 60
    syscall