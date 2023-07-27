assembly
section .data

hello db 'Hello, Holberton,', 10;

section .text
global _start

_start:
; write syscall
mov eax, 1
mov edi, 1
mov esi, hello
mov edx, 17
syscall

; exit syscall
mov eax, 60
xor edi, edi
syscall
