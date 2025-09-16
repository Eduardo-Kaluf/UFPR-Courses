section .data

V: dq 2, 5, 8, 12, 16, 23, 38, 56, 72, 91

section .text

global _start

binSearch:
    push rbp
    mov rbp, rsp

    cmp rdx, rsi
    jl _RET_NOT_FOUND

    mov rax, rdx
    sub rax, rsi
    mov rbx, 2
    mov r8, rdx
    xor rdx, rdx
    div rbx
    mov rdx, r8
    add rax, rsi ;; rax = left + (right - left) / 2 [middle]
    
    push rax ;; mid as local variable

    cmp [rdi, rax * 8], rcx
    jne _LEFT
    add rsp, 8
    jmp _RET_BIN

_LEFT:
    cmp [rdi, rax * 8], rcx
    jl _RIGHT
    sub rax, 1
    mov rdx, rax
    call binSearch
    add rsp, 8
    jmp _RET_BIN
_RIGHT:
    add rax, 1
    mov rsi, rax
    call binSearch
    add rsp, 8
    jmp _RET_BIN

_RET_NOT_FOUND:
    mov rax, -1

_RET_BIN:
    pop rbp
    ret

_start:
    push rbp
    mov rbp, rsp

    mov rdi, V
    mov rsi, 0
    mov rdx, 9
    mov rcx, 23

    call binSearch

    cmp rax, -1
    jne _FOUND
    mov rdi, rax ;; consider as printf(NOT FOUND)
    jmp _RET
_FOUND:
    mov rdi, rax ;; consider as printf(FOUND AT INDEX), even tough
                 ;; they are the same

_RET:
    pop rbp

    mov rax, 60
    syscall


;int binarySearch(int arr[], int left, int right, int key) {
;  
;    if (right >= left) {
;
;        int mid = left + (right - left) / 2;
;
;        if (arr[mid] == key)
;            return mid;
;
;        if (arr[mid] > key)  {
;            return binarySearch(arr, left, mid - 1, key);
;        }
;
;        return binarySearch(arr, mid + 1, right, key);
;    }
;
;    return -1;
;}