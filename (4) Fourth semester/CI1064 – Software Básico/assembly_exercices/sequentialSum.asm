section .data

START: .dq 2
END: .dq 20

section .text

global _start

_start:

    mov rbx, [START]
    mov rax, [END]
    xor rdi, rdi

    _LOOP:
        add rdi, rax

        sub rax, 1

        cmp rax, rbx
        jge LOOP


    mov rax, 60