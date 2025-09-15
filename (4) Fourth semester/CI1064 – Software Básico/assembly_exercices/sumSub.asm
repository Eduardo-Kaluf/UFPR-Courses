section .data

A: dq 10
B: dq 5

section .text


global _start


sum:
    push rbp
    mov rbp, rsp

    mov rax, [A]
    add rax, [B]

    pop rbp
    ret

sub:
    push rbp
    mov rbp, rsp

    mov rax, [A]
    sub rax, [B]

    pop rbp
    ret

_start:
    call sum
    mov [A], rax
    call sub
    mov [B], rax
    call sum
    mov rdi, rax
    mov rax, 60
    syscall
