%macro rw 4
mov rax, %1
mov rdi, %2
mov rsi, %3
mov rdx, %4
syscall
%endmacro

%macro read 2
rw 0, 0, %1, %2
%endmacro

%macro write 2
rw 1, 1, %1, %2
%endmacro

section .data
msg db "The mean of the numbers is: "
msgLen equ $-msg

dot db "."
newLine db 10

array dd 22.42,10.50,1.67,50.73,98.41
num dd 10000.0
divisor dd 5.0

section .bss
mean1 resb 1
mean2 rest 1

count1 resb 1
count2 resb 1
temp resb 1

section .text
global _start
_start:
; Set counter to 5
mov cl, 05
; Pointer to array in rsi
mov rsi, array
; Initialize stack
finit
; Load zero to the top of the stack
fldz
sum:
; Add and store the sum to the top of stack
fadd dword[rsi]
add rsi, 04
dec cl
jnz sum

; We now have the sum in the top of stack
; Divide the top of stack by our divisor (5 in this case as we have 5 numbers)
fdiv dword[divisor]
; Now we have the mean stored in the top of stack
; Copy the top of stack to mean
fst dword[mean1]
; Multiply the top of stack by 10000.0
fmul dword[num]
; Copy new top of stack to mean2
fbstp tword[mean2]
; Create a pointer to mean2 in rbp
mov rbp, mean2

call display

mov rax, 60
mov rdi, 0
syscall

display:
write msg, msgLen
add rbp, 9
; For 80 bits of BCD
mov byte[count1], 10
above:
cmp byte[rbp], 00
je skip
cmp byte[count1], 02
jne print
write dot, 1
print:
mov al, byte[rbp]
mov byte[count2], 2
again:
rol al, 04
mov byte[rbp], al
and al, 0Fh
cmp al, 09h
jbe down
add al, 07h
down:
add al, 30h
mov byte[temp], al
write temp, 1
mov al, byte[rbp]
dec byte[count2]
jnz again
skip:
dec rbp
dec byte[count1]
jnz above
write dot, 1
write newLine, 1
ret