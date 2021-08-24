#include <stdio.h>

int palindromo(char* a);


int main(void)
{
    char str[255] = "ammagamma";
    printf("la stringa è palindroma %d", palindromo(str));
    return 0;
}

//file.asm

.586
.model flat
.code
_palindromo proc
push ebp
mov ebp,esp
sub esp,8
push esi
push edi
push ebx
push ecx


mov ebx,dword ptr [ebp+8]
mov esi,-1
mov edi,-1

lunghezza:
inc esi
cmp dword ptr[ebx+esi],0 
je dopo
jmp lunghezza


dopo:
inc edi
dec esi

mov cl, byte ptr[ebx+edi]
cmp byte ptr [ebx+esi], cl
jne finenot
cmp esi, 0
je fineyes
jmp dopo

 
fineyes:
mov eax, 1
jmp fine

 
finenot:
mov eax, 0

 

fine:

pop ecx
pop ebx
pop edi
pop esi
mov esp,ebp
pop ebp
ret
_palindromo endp
end
