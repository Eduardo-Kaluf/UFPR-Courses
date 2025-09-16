
section .data

section .text

global _start

fat:
    push rbp
    mov rbp, rsp

    mov rbx, [rbp + 16] ;; rbx = n

    cmp rbx, 1
    je _OUT
    mov rcx, rbx
    push rbx
    sub rcx, 1
    push rcx
    call fat
    add rsp, 8
    pop rbx
    mul rbx

    pop rbp
    ret
_OUT:
    mov rax, 1

    pop rbp
    ret

_start:
    push rbp
    mov rbp, rsp

    push 4
    call fat
    add rsp, 8

    mov rdi, rax

    pop rbp
    mov rax, 60
    syscall
