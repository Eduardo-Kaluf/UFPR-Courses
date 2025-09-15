section .data

I: dq 0
M: dq 0
V: dq 10, 30, 5, 10, 50

section .text

global _start
    
_start:
    mov rbx, [I]
    mov rdi, [M]

_LOOP1:
    cmp rbx, 5
    jge _OUT
    cmp [V, rbx * 8], rdi
    jle _FALSE
    mov rdi, [V, rbx * 8]
_FALSE:
    add rbx, 1
    jmp _LOOP1
_OUT:
    add rax, 60
    syscall