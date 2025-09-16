
section .data

section .text

global _start

max:
    push rbp
    mov rbp, rsp

    cmp rsi, 1
    jne _OUT
    mov rax, [rdi]
    jmp _RET
_OUT:
    
    sub rsi, 1
    push qword [rdi, rsi * 8]

    call max

    pop rsi
    cmp rsi, rax
    jle _RET
    mov rax, rsi
_RET:
    pop rbp
    ret

_start:
    push rbp
    mov rbp, rsp

    sub rsp, 40
    mov qword [rsp], 2 ;; V[0]
    mov qword [rsp + 8], 5
    mov qword [rsp + 16], 1
    mov qword [rsp + 24], 5
    mov qword [rsp + 32], 4

    mov rdi, rsp
    mov rsi, 5
    call max

    mov rdi, rax

    add rsp, 40

    pop rbp

    mov rax, 60
    syscall
