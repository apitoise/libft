global	_ft_read

_ft_read:
	mov	rax, 0x2000003
	jc	_err
	syscall
	ret

_err:
	mov	rax, -1
	ret
