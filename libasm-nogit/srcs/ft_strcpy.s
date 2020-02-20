global	_ft_strcpy

_ft_strcpy:
	mov	r8b, [rsi]
	cmp	r8b, 0
	je	end
	mov [rdi], r8b
	inc	rdi
	inc	rsi
	jmp _ft_strcpy

end:
	mov r8b, 0
	mov	[rdi], r8b
	mov	rax, rdi
	ret
