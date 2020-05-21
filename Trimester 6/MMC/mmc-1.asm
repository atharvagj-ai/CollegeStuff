; Macro to display values
%macro print 2
mov rax, 1
mov rdi, 1
mov rsi, %1
mov rdx, %2
syscall
%endmacro

; Section for uninitialized data
section .bss
count resb 1
displayBuffer resb 4

; Section for initialized data
section .data
array db 24h, 27h, 0Bh, 0Fh, 17h
msg db "Sorted array is: "
msgLength equ $-msg
newLine db 10
comma db ", "
exclamation db "!"

section .text
global _start
_start:

; 5 counts (as outer loop)
mov bl, 05h

l1:
; Create 2 pointers to array, increment 1 so as to check consecutive elements
mov rsi, array
mov rdi, array
inc rdi
; 4 counts (as inner loop)
mov cl, 04h

l2:
; Compare consecutive elements, swap if not in order
mov al, [rsi]
cmp al, [rdi]
jbe l3
xchg al, [rdi]
mov [rsi], al

l3:
; After one iteration, increment both pointers, decrement counters
inc rsi
inc rdi
dec cl
jnz l2
dec bl
jnz l1
; Jump only if not zero, i.e. keep running the loop until counter reaches 0

; Display message
print msg, msgLength
; Pointer to array in rsi
mov rsi, array
; Set count to 5
mov byte[count], 5
display:
; Copy to register bh, push to stack, call procedure, pop from stack
mov bh,[rsi]
push rsi
call proc
; Print result given from procedure
print displayBuffer, 2
mov cl, [count]
dec cl
jz nocomma
print comma, 2
nocomma:
pop rsi
; Increment pointer, decrement counter, loop again if not 0
inc rsi
dec byte[count]
jnz display
print exclamation, 1
print newLine, 1

; Exit syscall
mov rax, 60
mov rdi, 0
syscall

; Procedure to get the value for us to display
proc:
mov rsi, displayBuffer
mov cl, 2
label:
rol bx, 4
mov al, bl
and al, 0Fh
cmp al, 09h
jbe down
add al, 07h
            
down:
add al, 30h
mov [rsi], al
inc rsi
dec cl
jnz label       
ret
       
