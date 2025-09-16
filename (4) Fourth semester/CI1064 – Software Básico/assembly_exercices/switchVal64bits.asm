
section .data


section .text

global _start

switch:
    push rbp
    mov rbp, rsp

    push qword [rdi]
    mov rax, [rsi]
    mov [rdi], rax
    pop qword [rsi]

    pop rbp
    ret

_start:
    push rbp
    mov rbp, rsp

    push 10 ;; local a -> rbp - 8
    push 20 ;; local b -> rbp - 16

    mov rax, rbp
    sub rax, 8
    mov rdi, rax

    sub rax, 8
    mov rsi, rax

    call switch

    mov rdi, [rbp - 8]
    sub rdi, [rbp - 16]

    add rsp, 16
    
    pop rbp

    mov rax, 60
    syscall
