%macro operate 4
mov rax, %1
mov rdi, %2
mov rsi, %3
mov rdx, %4
syscall
%endmacro

section .data

msg1 db "Error occurred!", 10
msg1Len equ $-msg1
msg2 db "File has been copied successfully!", 10
msg2Len equ $-msg2

section .bss

fname1 resb 15
fd1 resq 1
fname2 resb 15
fd2 resq 1
buff resb 512
buffLen resq 1

section .txt
global _start
_start:
pop r8
cmp r8, 3
jne error
pop r8
pop r8
mov rsi, fname1
above:
mov al, [r8]
cmp al, 00
je next
mov [esi], al
inc r8
inc esi
jmp above
next:
pop r8
mov esi, fname2
above2:
mov al, [r8]
cmp al, 00
je next2
mov [esi], al
inc r8
inc esi
jmp above2
next2:
operate 2, fname1, 0, 0777q
mov [fd1], rax
mov rbx, rax
operate 0, rbx, buff, 512
mov [buffLen], rax
operate 1, rbx, buff, [buffLen]
operate 85, fname2, 0777q, 0
operate 2, fname2, 2, 0777q
mov [fd2], rax
mov rbx, rax
operate 1, rbx, buff, [buffLen]
mov [buffLen], rax
operate 3, rbx, 0, 0
operate 3, [fd1], 0, 0
operate 1, 1, msg2, msg2Len
jmp end
error: operate 1, 1, msg1, msg1Len
end: operate 60, 0, 0, 0