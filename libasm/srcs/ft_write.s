global	_ft_write

_ft_write:
	mov	rax, 0x2000004
	jc	_error
	syscall
	ret

_error:
	mov	rax, -1
	ret
