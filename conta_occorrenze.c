.586
.model flat
.code
_contaoccorrenze proc

push ebp
mov ebp,esp
sub esp,8
push esi
push edi
push ebx
push ecx

 

mov ebx,dword ptr [ebp+8] ;puntatore alla stringa messo in ebx (primo elemento)
mov ecx,dword ptr [ebp+12] ;puntatore alla parola messo in ecx (primo elemento)
mov esi,-1 ;usato per scorrere la stringa
mov edi,-1 ;usato per scorrere la parola
mov eax,0
push eax

 

ciclon:            ;controlliamo se si parte da uno spazio
mov edi,-1
inc esi
mov dl,byte ptr[ebx+esi]
cmp dl,0
je fine
cmp dl,' '
jne ciclon

 

ciclogrande:
inc esi
inc edi
mov dl,byte ptr[ebx+esi+1] ;metto in dl il carattere dopo quello che ci serve nella stringa
cmp dl,0
je fine
mov al, byte ptr [ecx+edi] ;metto in al il carattere della parola
mov dl,byte ptr[ebx+esi] ;metto in dl il carattere della stringa
cmp al, 0
je incrementor
cmp al,dl
jne scorrerefinoallafine
jmp ciclogrande

 

scorrerefinoallafine:
inc esi
cmp dl,0
je fine
mov dl,byte ptr[ebx+esi+1] ;metto in dl il carattere della stringa
cmp dl,' '
je ciclon
jmp scorrerefinoallafine

 


incrementor:
mov dl,byte ptr[ebx+esi]
cmp dl, ' '
je incremento
pop eax
dec eax
push eax

 

incremento:
pop eax
inc eax
push eax
dec esi
jmp ciclon
fine:
pop eax

 


pop ecx
pop ebx
pop edi
pop esi
mov esp,ebp
pop ebp
ret
_contaoccorrenze endp
end
