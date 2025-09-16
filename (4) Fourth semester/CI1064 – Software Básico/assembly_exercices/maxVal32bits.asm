section .data

section .text

global _start

max:
    push rbp
    mov rbp, rsp

    mov rbx, [rbp + 24] ;; &v
    mov rcx, [rbp + 16] ;; n

    cmp rcx, 1
    jne _OUT
    mov rax, [rbx]
    jmp _RET

_OUT:
    sub rcx, 1
    push qword [rbx, rcx * 8]
    push rbx
    push rcx
    call max
    add rsp, 16
    pop rdx
    cmp rdx, rax
    jle _RET
    mov rax, rdx
    pop rbp
    ret


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

    push rsp
    push 5
    call max
    add rsp, 16

    mov rdi, rax

    add rsp, 40

    pop rbp

    mov rax, 60
    syscall
