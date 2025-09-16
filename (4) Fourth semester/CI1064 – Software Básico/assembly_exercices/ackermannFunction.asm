section .data

section .text

global _start:

ackermann:
    push rbp
    mov rbp, rsp    

    cmp rdi, 0
    jne _OUT_1
    add rsi, 1
    mov rax, rsi
    jmp _RET

_OUT_1:
    cmp rsi, 0
    jne _OUT_2
    sub rdi, 1
    mov rsi, 1
    call ackermann
    jmp _RET

_OUT_2:
    push rdi
    sub rsi, 1
    call ackermann
    pop rdi
    sub rdi, 1
    mov rsi, rax
    call ackermann

_RET:
    pop rbp
    ret


_start:
    push rbp
    mov rbp, rsp

    push 4 ;; local m = 3 -> rbp - 8
    push 3 ;; local n = 2 -> rbp - 16

    mov rdi, [rbp - 8]
    mov rsi, [rbp - 16]
    call ackermann
    mov rdi, rax

    add rsp, 16

    mov rax, 60
    syscall
