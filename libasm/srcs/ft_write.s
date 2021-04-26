global	_ft_write
extern	__errno_location

_ft_write:
	mov	rax, 0x2000004
	jc	_error
	syscall
	ret

_error:
	neg	rax
	mov rdi, rax
	call __errno_location
	mov [rax], rdi
	mov	rax, -1
	ret
