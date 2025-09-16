section .data

SIZE: dq 9
;; we will not use GRID as global
;; it's just to simplify the declaration
GRID:
    dq  1, 5, 3, 0, 2, 0, 6, 0, 0
    dq  9, 0, 0, 3, 0, 5, 0, 0, 1
    dq  0, 0, 1, 8, 0, 6, 4, 0, 0
    dq  0, 0, 8, 1, 0, 2, 9, 0, 0
    dq  7, 0, 0, 0, 0, 0, 0, 0, 8
    dq  0, 0, 6, 7, 0, 8, 2, 0, 0
    dq  0, 0, 2, 6, 0, 9, 5, 0, 0
    dq  8, 0, 0, 2, 0, 3, 0, 0, 9
    dq  0, 0, 5, 0, 1, 0, 3, 0, 0

space: db ' '
newline: db 10 ; ASCII code for a newline character

section .text

global _start
global isSafe
global printGrid
global solveSudoku

printGrid:
    push rbp
    mov rbp, rsp
    sub rsp, 16

    mov r12, rdi
    
    xor r8, r8

.row_loop:
    cmp r8, 9
    jge .done
    
    xor r9, r9

.col_loop:
    cmp r9, 9
    jge .print_newline
    
    mov rax, r8     ; rax = i
    imul rax, 9     ; rax = i * 9
    add rax, r9     ; rax = i * 9 + j
    shl rax, 3      ; rax = (i * 9 + j) * 8 (for quadwords)
    
    mov rbx, [r12 + rax] ; rbx = grid[i][j]
    add rbx, '0'         ; Convert number (0-9) to ASCII character ('0'-'9')

    ; Store the character in memory to get its address
    mov [rsp - 8], rbx

    ; Syscall to write the character
    mov rax, 1           ; syscall number for write
    mov rdi, 1           ; file descriptor 1 is stdout
    lea rsi, [rsp - 8]   ; address of the character to print
    mov rdx, 1           ; number of bytes to write
    syscall

    ; Syscall to write a space
    mov rax, 1
    mov rdi, 1
    mov rsi, space
    mov rdx, 1
    syscall
    
    inc r9
    jmp .col_loop

.print_newline:
    ; Syscall to write a newline character
    mov rax, 1
    mov rdi, 1
    mov rsi, newline
    mov rdx, 1
    syscall
    
    inc r8
    jmp .row_loop

.done:
    mov rsp, rbp
    pop rbp
    ret

isSafe:
    push rbp
    mov rbp, rsp

    mov r10, [SIZE]

    mov r8, 0
_LOOP1:
    cmp r8, r10
    jge _OUT1

    mov rax, rsi
    mov rbx, r10
    mul rbx
    add rax, r8
    cmp [rdi + rax * 8], rcx
    jne _FALSE1
    mov rax, 0
    jmp _isSafe_RET
_FALSE1:
    add r8, 1
    jmp _LOOP1

_OUT1:
    mov r8, 0
_LOOP2:
    cmp r8, r10
    jge _OUT2

    mov rax, r8
    mov rbx, r10
    mul rbx
    add rax, rdx
    cmp [rdi + rax * 8], rcx
    jne _FALSE2
    mov rax, 0
    jmp _isSafe_RET
_FALSE2:
    add r8, 1
    jmp _LOOP2

_OUT2:
    mov r8, rdx ;; r8 = rdx (col)
    xor rdx, rdx
    mov rax, rsi
    mov rbx, 3
    div rbx ;; row / 3
    mov rax, rsi 
    sub rax, rdx ;; row - row % 3
    mov r11, rax ;; startRow

    xor rdx, rdx
    mov rax, r8
    mov rbx, 3
    div rbx ;; col / 3
    mov rax, r8 
    sub rax, rdx ;; col - col % 3
    mov r12, rax ;; startCol

    mov rdx, r8

    mov r8, 0 ;; i
LOOP_I:
    cmp r8, 3
    jge _OUT_I
    mov r9, 0 ;; j
LOOP_J:
    cmp r9, 3
    jge _OUT_J
    mov rax, r8
    add rax, r11
    mov rbx, r10
    mul rbx
    mov rbx, r9
    add rbx, r12
    add rax, rbx
    cmp [rdi + rax * 8], rcx
    jne _CONTINUE1
    mov rax, 0
    jmp _isSafe_RET
_CONTINUE1:
    add r9, 1
    jmp LOOP_J
_OUT_J:
    add r8, 1
    jmp LOOP_I

_OUT_I:
    mov rax, 1

_isSafe_RET:
    pop rbp
    ret

solveSudoku:
    push rbp
    mov rbp, rsp

    mov r13, 0 ;; row
    mov r14, 0 ;; col
    mov r15, 1 ;; num

    push 0 ;; rbp - 8 -> foundEmpty
    
    mov r10, [SIZE]
_LOOP_ROW:
    cmp r13, r10
    jge _OUT_ROW

    mov r14, 0
_LOOP_COL:
    cmp r14, r10
    jge _OUT_COL

    mov rax, r13
    mov rbx, r10
    mul rbx
    add rax, r14
    cmp qword [rdi + rax * 8], 0
    jne _CONTINUE2
    mov qword [rbp - 8], 1
    jmp _OUT_ROW

_CONTINUE2:
    add r14, 1
    jmp _LOOP_COL
_OUT_COL:
    add r13, 1
    jmp _LOOP_ROW

_OUT_ROW:

    cmp qword [rbp - 8], 0
    jne _LOOP_NUM
    mov rax, 1
    jmp _solveSudoku_RET

_LOOP_NUM:
    cmp r15, r10
    jg _BACKTRACK

    mov rsi, r13
    mov rdx, r14
    mov rcx, r15
    call isSafe

    cmp rax, 1
    jne _FALSE_IS_SAFE

    mov rax, r13
    mov rbx, r10
    mul rbx
    add rax, r14
    mov [rdi + rax * 8], r15

    call solveSudoku

    cmp rax, 1
    jne _FALSE_SOLVE_SUDOKU
    mov rax, 1
    jmp _solveSudoku_RET

_FALSE_SOLVE_SUDOKU:
    mov rax, r13
    mov rbx, r10
    mul rbx
    add rax, r14
    mov qword [rdi + rax * 8], 0

_FALSE_IS_SAFE:
    add r15, 1
    jmp _LOOP_NUM

_BACKTRACK:
    mov rax, 0

_solveSudoku_RET:
    mov rsp, rbp
    pop rbp
    ret

_start:
    push rbp
    mov rbp, rsp

    mov rdi, GRID
    call solveSudoku

    cmp rax, 1

    mov rdi, GRID  ; rdi points to the now-solved grid
    call printGrid ; Print the solved grid

_success:
    mov rdi, 0
    jmp _exit

_failure:
    mov rdi, 1

_exit:
    pop rbp
    mov rax, 60
    syscall