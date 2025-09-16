section .data

section .text

global _start


gcd: 
    push rbp
    mov rbp, rsp

    cmp rsi, 0
    jne _FALSE
    mov rax, rdi
    jmp _RET

_FALSE:
    xor rdx, rdx
    mov rax, rdi
    div rsi

    mov rdi, rsi
    mov rsi, rdx
    call gcd

_RET:
    pop rbp
    ret

_start:
    push rbp
    mov rbp, rsp

    push 270
    push 192

    mov rdi, [rbp - 8]
    mov rsi, [rbp - 16]

    call gcd

    mov rdi, rax

    add rsp, 16

    pop rbp

    mov rax, 60
    syscall
