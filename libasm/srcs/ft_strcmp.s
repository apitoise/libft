global _ft_strcmp

_ft_strcmp:
	xor	rcx, rcx
	xor	rdx, rdx

_begin:
	cmp	BYTE [rsi + rcx], 0
	je	_null
	cmp	BYTE [rdi + rcx], 0
	je	_null
	jmp	_compare

_null:
	mov	r9b, BYTE [rdi + rcx]
	cmp	r9b, BYTE [rsi + rcx]
	je	_equal
	jmp	_compare

_compare:
	cmp	rsi, 0
	je	_sup
	cmp	rdi, 0
	je	_inf
	mov	r8b, BYTE [rdi + rcx]
	cmp	r8b, BYTE [rsi + rcx]
	je	_incrementation
	jl	_inf
	jg	_sup

_incrementation:
	inc	rcx
	jmp	_begin

_equal:
	mov	rax, 0
	ret

_sup:
	mov	rax, 1
	ret

_inf:
	mov	rax, -1
	ret
