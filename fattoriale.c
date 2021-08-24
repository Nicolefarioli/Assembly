#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int n;
  printf("Inserire un intero >= 0 : ");
  scanf("%d", &n);
  printf("Il fattoriale di %d e' %d\n", n, fattoriale(n));
  return 0;
}


//file.asm

.586
.model flat
.code
_fattoriale proc

	
	push ebp
	mov ebp,esp
	push ebx
	push esi
	push edi
	
	mov ebx, dword ptr[ebp+8] ;src
	mov ecx, dword ptr[ebp+12] ;dest
	mov esi,0 ;esi=0

	ciclo:
	cmp esi,dword ptr[ebp+16]
	je fine
	call fattoriale
	mov sword ptr[ecx+esi*4],eax
	inc esi
	jmp ciclo

	fine:
	mov eax,0
	pop edi
	pop esi
	pop ebx
	mov esp,ebp
	pop ebp
	ret
	_fattoriale endp
	end

	fattoriale proc
	mov eax, dword ptr[ebx+esi*4]
	mov esi, dword ptr[ebx+esi*4]

	cmp dword ptr[ebx+esi*4],0
	je zero
	cmp dword ptr[ebx+esi*4],1
	je zero

	CicloFatt:
	dec edi
	cmp edi,1
	je EndCicloFatt
	imul edi
	jmp CicloFatt

	zero:
	mov eax,1

	EndCicloFatt:
	ret
	fatto endp
	end

