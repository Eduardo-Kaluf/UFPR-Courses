section .data

PI: dq 3

section .text

global _start

mult:
    push rbp
    mov rbp, rsp

    mov rax, rdi
    mul rax ;; rax = r^2
    mov rbx, [PI]
    mul rbx ;; rax = r^2 * PI

    pop rbp
    ret

_start:
    push rbp
    mov rbp, rsp

    push 5
    mov rdi, [rbp - 8]
    call mult
    mov rdi, rax
    add rsp, 8

    pop rbp

    mov rax, 60
    syscall
