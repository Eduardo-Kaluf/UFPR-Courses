section .data

section .text

binomial:
    push rbp
    mov rbp, rsp

    cmp rsi, 0
    jl _IN1
    cmp rsi, rdi
    jle _OUT1
_IN1:
    mov rax, 0
    jmp _RET

_OUT1:
    cmp rsi, 0
    je _IN2
    cmp rsi, rdi
    jne _OUT2
_IN2:
    mov rax, 1
    jmp _RET

_OUT2:
    sub rdi, 1
    push rdi
    push rsi
    call binomial
    pop rsi
    pop rdi
    sub rsi, 1
    push rax
    call binomial
    pop rbx
    add rax, rbx

_RET:
    pop rbp
    ret

global _start

_start:
    push rbp
    mov rbp, rsp

    push 5 ;; local n = 5 rbp - 8
    push 2 ;; local k = 2 rbp - 16

    mov rdi, [rbp - 8]
    mov rsi, [rbp - 16]
    call binomial

    mov rdi, rax

    add rsp, 16
    pop rbp

    mov rax, 60
    syscall
