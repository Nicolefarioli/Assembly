#include <stdio.h>
#include <stdlib.h>

unsigned conta_parole(char* s);

int main() {
	printf("%d\n", conta_parole("esempio di frase composta da sette parole"));
	getchar();
}

//file.asm
.586
.model flat
.code
_conta_parole proc

	push ebp
	mov ebp,esp
	push ebx
	push edi
	push esi

	mov eax,0
	mov esi,0
	mov edi,dword ptr[ebp+8]  ;metto la stringa in edi

	ciclo:
	cmp byte ptr[edi+8],0
	je contadiversa
	cmp byte ptr[edi+esi],32
	je conta

	inc esi
	jmp ciclo

	conta:
	inc eax
	inc esi
	jmp ciclo

	contadiversa:
	inc eax
	jmp fine

	fine:
	pop esi
	pop edi
	pop ebx
	mov esp,ebp
	pop ebp
	ret
	_conta_parole endp
	end
