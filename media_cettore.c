#include <stdio.h>
#include <stdlib.h>

int main() {
	int v[10] = { 1,2,3,4,5,6,7,8,9,10 };
	printf("la media e' : %d", media(v, 10));
	getchar();
}



__declspec(naked) int media(int *v, int lunghezza) {
	__asm {

		push ebp
		mov ebp, esp

		push edi
		push esi
		push ebx

		mov edx, 0
		mov esi, 0
		mov edi, 0
		mov ebx, dword ptr[ebp + 12]
		mov eax, dword ptr[ebp + 8]

		ciclo:
		cmp edi, ebx
			je fine

			add edx, dword ptr[eax + edi * 4]
			inc edi

			jmp ciclo

			fine :
		mov eax, edx
			cdq
			idiv ebx

			pop ebx
			pop esi
			pop edi
			mov esp, ebp
			pop ebp

			ret

	}

}
