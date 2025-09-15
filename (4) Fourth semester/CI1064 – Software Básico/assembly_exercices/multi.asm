section .data

V: dq 10
T: dq 5

section .text

global _start

multi:
    push rbp
    mov rbp, rsp

    push 1 ;; local variable m, access via rbp - 8
    mov r8, [T]
    push 2 ;; local variable i, access via rbp - 16

_LOOP:
    cmp [rbp - 16], r8
    jg _OUT

    mov rdx, 0
    mov rax, [V]
    mov rbx, [rbp - 16]
    div rbx

    cmp rdx, 0 ;; compare the remainder

    jne _FALSE
    add qword [rbp - 8], 1
_FALSE:
    add qword [rbp - 16], 1
    jmp _LOOP

_OUT:
    add rsp, 8
    pop rax

    pop rbp
    ret

_start:
    call multi
    mov rdi, rax
    mov rax, 60
    syscall
