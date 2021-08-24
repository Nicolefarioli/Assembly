//main
#include <stdio.h>
#include <stdlib.h>

void vocali(char* s, char c);

int main() {
	char s[] = "la mamma ha fatto da mangiare";
	vocali(s, 'e');
	puts(s);
	getchar();
}

//file.asm

.586
.model flat
.code
_sostituzione_vocali proc

	push ebp
	mov ebp,esp
	push ebx
	push edi
	push esi


	mov ebx,dword ptr[ebp+8]
	mov edi,0
	mov al,byte ptr[ebp+12]

	ciclo:
	cmp byte ptr[ebp+edi],0
	je fine
	cmp byte ptr[ebp+edi],'a'
	je sostituisci
	cmp byte ptr[ebp+edi],'e'
	je sostituisci
	cmp byte ptr[ebp+edi],'i'
	je sostituisci
	cmp byte ptr[ebp+edi],'o'
	je sostituisci
	cmp byte ptr[ebp+edi],'u'
	je sostituisci
	cmp byte ptr[ebp+edi],'A'
	je sostituisci
	cmp byte ptr[ebp+edi],'E'
	je sostituisci
	cmp byte ptr[ebp+edi],'I'
	je sostituisci
	cmp byte ptr[ebp+edi],'O'
	je sostituisci
	cmp byte ptr[ebp+edi],'U'
	je sostituisci

	inc edi
	jmp ciclo

	sostituisci:
	mov byte ptr[ebp+edi],al
	inc edi


	fine:
	pop esi
	pop edi
	pop ebx
	mov esp,ebp
	pop ebp
	ret
	_sostituzione_vocali endp
	end
