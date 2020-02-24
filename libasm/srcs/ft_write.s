global	_ft_write

_ft_write:
	cmp	rsi, 0
	je	_error
	mov	rax, 0x2000004
	syscall
	ret

_error:
	mov	rax, -1
	ret
