section .data

A: dq 1 
B: dq 2
C: dq 1

section .text

global _start

verify:
    push rbp
    mov rbp, rsp

    push 0 ;; local variable delta, access via rbp - 8

    mov r15, [C]
    mov [rbp - 8], r15
    mov rax, [A]
    mul qword [rbp - 8]
    mov [rbp - 8], rax ;; delta = a * c

    mov rax, -4
    mul qword [rbp - 8]
    mov [rbp - 8], rax ;; delta = -4 * a * c

    mov rax, [B]
    mul rax
    add [rbp -8], rax ;; delta = b^2 - 4 * a * c

    cmp qword [rbp - 8], 0
    jl _FALSE
    mov rax, 1
    jmp _OUT
_FALSE:
    mov rax, 0
_OUT:
    add rsp, 8
    pop rbp
    ret

_start:
    call verify
    mov rdi, rax
    mov rax, 60
    syscall
