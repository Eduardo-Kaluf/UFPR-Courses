section .data

section .text

global _start

switch:
    ;; a = param1 access via rbp + 24
    ;; b = param2 access via rbp + 16
    push rbp
    mov rbp, rsp

    mov rax, [rbp + 24] ;; rax = &a
    mov rbx, [rbp + 16] ;; rbx = &b

    push qword [rax] ;; local variable temp = *a

    mov rcx, [rbx]
    mov [rax], rcx

    pop rcx
    mov [rbx], rcx

    pop rbp
    ret

_start:
    push rbp
    mov rbp, rsp

    push 10 ;; a = 10 -> rbp - 8
    push 20 ;; b = 20 -> rbp - 16

    mov rax, rbp
    sub rax, 8
    push rax
    sub rax, 8
    push rax
    call switch
    add rsp, 16
    
    mov rdi, [rbp - 8]
    sub rdi, [rbp - 16]

    add rsp, 16

    pop rbp

    mov rax, 60
    syscall
