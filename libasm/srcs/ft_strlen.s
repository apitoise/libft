global _ft_strlen

_ft_strlen:
	mov rax, 0
	call loopft

loopft:
	mov r8b, [rdi]
	cmp	r8b, 0
	je	end
	inc	rdi
	inc	rax
	jmp loopft

end :
	ret	
