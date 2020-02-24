global _ft_strcmp

_ft_strcmp:
	mov	rax, 0
	mov	al,	[rdi]
	mov	bl,	[rsi]
	cmp	al, bl
	jne	_return
	inc	rdi
	inc	rsi
	mov	bl, [rsi]
	cmp	bl, 0
	je	_check
	jne	_ft_strcmp

_check:
	mov	al, [rdi]
	cmp	al, 0
	jne	_ft_strcmp
	ret	

_return:
	sub	rax, rbx
	ret
