.586
.model flat
.code

_main proc

	push ebp
	mov ebp,esp
	push ebx 
	push eax
	push esi

		mov esi,0
		mov ebx,0

		ciclo:
		mov bl, byte ptr[ebx+esi]
		cmp bl, 'a'
		je incrementa
		cmp bl, 'e'
		je incrementa
		cmp bl, 'i'
		je incrementa
		cmp bl, 'o'
		je incrementa
		cmp bl, 'u'
		je incrementa
		cmp bl, 'A'
		je incrementa
		cmp bl, 'E'
		je incrementa
		cmp bl, 'I'
		je incrementa
		cmp bl, 'O'
		je incrementa
		cmp bl, 'U'
		je incrementa
		cmp bl,0
		je fine
		inc esi
		jmp ciclo


		incrementa:
			inc ebx
			inc esi
			jmp ciclo

	fine:
	mov eax,ebx

	pop esi
	pop eax
	pop ebx
	mov esp,ebp
	pop ebp
	ret
	_main endp
	end
  
  
  
#include <stdio.h>
#include <stdlib.h>
  
  int main(void) {

	char str[255] = "Ciao bElLa";
	int num = 0;
	char* p;
	p = &str[0];

  printf("Le vocali sono : %d", num);
	getchar();

}
