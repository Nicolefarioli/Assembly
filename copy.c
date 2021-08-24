#include <stdio.h>
#include <string.h>

#define DEST_SIZE 40

int main()
{
	char src[] = "Look Here";
	char dest[DEST_SIZE] = "Unimaginable";

	char *p = dest + 5;

	strcpy(p, src);
	printf(dest);

	return 0;
}


//file.asm

.586
.model flat
.code
_copy proc

	push ebp
	mov ebp,esp
	push ebx
	push esi
	push edi

	mov esi,dword ptr[ebp+8]
	mov edi, dowrd ptr[ebp+12]

	ciclo:
	mov al,byte ptr[esi]
	mov byte ptr[edi],al
	inc esi
	inc edi

	cmp al,0
	je ciclo

	pop edi
	pop esi
	pop ebx
	mov esp,ebp
	pop ebp
	ret
	_copy endp
	end
