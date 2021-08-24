#include <stdio.h>
#include <stdlib.h>

int main() {

	int v[5] = { 1,2,3,4,5 };
	int sum = 0;

	printf("la somma degli elementi e' %d", sum);
	getchar();
}


//fine.asm

.586
.model flat
.code
_main proc

	push ebp
	mov ebp,esp
	push ebx 
	push eax
	push esi

	mov ebx, dword ptr[ebp+8]

	mov eax,0
	mov esi,0

	ciclo:
	cmp esi,dword ptr[ebp+12]
	je fine
	mov ecx,dword ptr[ebp+esi*4]
	add eax,ecx
	inc esi
	jmp ciclo


	fine:

	pop esi
	pop eax
	pop ebx
	mov esp,ebp
	pop ebp
	ret
	_main endp
	end


