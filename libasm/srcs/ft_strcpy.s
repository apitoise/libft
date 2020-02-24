global	_ft_strcpy

_ft_strcpy:
	xor	rcx, rcx

_loop:
	cmp rsi, 0
	je	_end
	mov r8b, BYTE [rsi + rcx]
	mov	BYTE [rdi + rcx], r8b
	cmp	r8b, 0
	je	_end
	inc	rcx
	jmp _loop

_end:
	mov	rax, rdi
	ret
