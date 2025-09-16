section .data


section .text

global _start


fat:
    push rbp
    mov rbp, rsp

    cmp rdi, 1
    je _OUT

    push rdi
    sub rdi, 1
    call fat
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

    mov rdi, 3
    call fat
    mov rdi, rax

    pop rbp

    mov rax, 60
    syscall
