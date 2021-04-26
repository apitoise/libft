global	_ft_strdup
extern	_ft_strlen
extern	_malloc
extern	_ft_strcpy
extern	__errno_location

_ft_strdup:
	push rdi
	call _ft_strlen
	pop	rdi
	mov	r8, rax
	inc	r8
	push rdi
	mov	rdi, r8
	call _malloc
	cmp	rax, 0
	je	_end
	pop	rsi
	mov	rdi, rax
	call _ft_strcpy
	

_end:
	neg	rax
	mov rdi, rax
	call __errno_location
	mov	[rax], rdi
	mov rax, -1
	ret
