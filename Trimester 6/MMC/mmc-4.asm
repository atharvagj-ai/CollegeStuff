section .data
msg1 db "Base Address: "
msgl1 equ $-msg1
msg2 db "Offset: "
msgl2 equ $-msg2
msg3 db "Global Descriptor Table Register:",10
msgl3 equ $-msg3
msg4 db "Interrupt Descriptor Table Register:",10
msgl4 equ $-msg4
msg5 db "Local Descriptor Table Register:",10
msgl5 equ $-msg5
msg6 db "Task Register:",10
msgl6 equ $-msg6
msg7 db "Machine Status Word:",10
msgl7 equ $-msg7
newl db 10


%macro operate 4        ;Macro to perform read, write and terminate operations
mov rax,%1
mov rdi,%2
mov rsi,%3
mov rdx,%4
syscall
%endmacro


section .bss
gdtlimit resw 1
GDTR resq 1
idtlimit resw 1
IDTR resq 1
LDTR resw 1
TR resw 1
MSW resw 1
res64 resb 16
res16 resb 4
temp resb 1


section .text
global _start
_start:
operate 1,1,msg3,msgl3
operate 1,1,msg1,msgl1
mov esi,GDTR
sgdt [gdtlimit]
mov rax,[esi]
call Display64      ;Call Display64 Procedure
operate 1,1,newl,1

operate 1,1,msg2,msgl2
mov esi,gdtlimit
;sgdtlimit [esi]
mov  ax,[esi]
call Display16      ;Call Display16 Procedure
operate 1,1,newl,1

operate 1,1,msg4,msgl4
operate 1,1,msg1,msgl1
mov esi,IDTR
sidt [idtlimit]
mov rax,[esi]
call Display64      ;Call Display64 Procedure
operate 1,1,newl,1

operate 1,1,msg2,msgl2
mov esi,idtlimit
;sidtlimit [esi]
mov  ax,[esi]
call Display16      ;Call Display16 Procedure
operate 1,1,newl,1

operate 1,1,msg5,msgl5
operate 1,1,msg2,msgl2
mov esi,LDTR
sldt [esi]
mov  ax,[esi]
call Display16      ;Call Display16 Procedure
operate 1,1,newl,1

operate 1,1,msg6,msgl6
operate 1,1,msg2,msgl2
mov esi,TR
str [esi]
mov  ax,[esi]
call Display16      ;Call Display16 Procedure
operate 1,1,newl,1

operate 1,1,msg7,msgl7
operate 1,1,msg2,msgl2
mov esi,MSW
smsw [esi]
mov  ax,[esi]
call Display16      ;Call Display16 Procedure
operate 1,1,newl,1

operate 60,0,0,0    ;Terminate the program


Display64:
    mov bp,16       ;Set pointer to 16 because 16 bytes ie 64 bits
again1: rol rax,4
    mov [res64],rax     ;Store rax to res64
    and rax,0Fh
    cmp rax,09h
    jbe down1       ;If rax>09h jump to down1
    add rax,07h
down1:  add rax,30h
    mov byte[temp],al
    operate 1,1,temp,1  ;Print temp
    mov rax,[res64]     ;move value in res64 to rax 
    dec bp          ;Decrement counter 
    jnz again1      ;If counter isn't 0 jump to again1
ret             ;Return control

Display16:
    mov bp,4        ;Set pointer to 4 because 4 bytes ie 16 bits
again2: rol ax,4
    mov [res16],ax      ;Store ax to res16
    and ax,0Fh
    cmp ax,09h
    jbe down2       ;If ax>09h jump to down2
    add ax,07h
down2:  add ax,30h
    mov byte[temp],al
    operate 1,1,temp,1  ;Print temp
    mov ax,[res16]      ;move value in res16 to ax
    dec bp          ;Decrement counter
    jnz again2      ;If counter isn't 0 jump to again2
ret
