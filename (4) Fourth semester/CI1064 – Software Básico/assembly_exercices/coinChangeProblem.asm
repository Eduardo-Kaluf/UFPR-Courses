section .data

COINS: dq 1, 5, 10, 25

section .text


global _start

countChange:
    push rbp
    mov rbp, rsp

    cmp rdx, 0
    jne _OUT_1
    mov rax, 1
    jmp _RET

_OUT_1:
    cmp rdx, 0
    jge _OUT_2
    mov rax, 0
    jmp _RET

_OUT_2:
    cmp rsi, 0
    jg _OUT_3
    cmp rdx, 0
    jle _OUT_3
    mov rax, 0
    jmp _RET

_OUT_3:
    push rsi
    push rdx
    sub rsi, 1
    call countChange
    pop rdx
    pop rsi
    push rax
    mov r8, rsi
    sub r8, 1
    sub rdx, [rdi, r8 * 8]
    call countChange
    pop rbx
    add rax, rbx
_RET:
    pop rbp
    ret

_start:
    push rbp
    mov rbp, rsp

    push COINS
    push 4
    push 30

    mov rdi, [rbp - 8]
    mov rsi, [rbp - 16]
    mov rdx, [rbp - 24]
    call countChange
    mov rdi, rax

    add rsp, 24

    pop rbp

    mov rax, 60
    syscall
