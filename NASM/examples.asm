
        global  examples
        section .text
examples:
; add
;        mov rax, 1
;        mov rbx, 2
;        add rax, rbx
;        ret                  ; return the value in rax

; subtract
;        mov rax, 1
;        mov rbx, 2
;        sub rax, rbx
;        ret                  ; return the value in rax

; multiply
;        mov rax, 2
;        mov rbx, 2
;        imul rax, rbx
;        ret                  ; return the value in rax

; divide
;        mov rdx, 9          ; move 9 into rdx (divident low bits)
;        mov rax, rdx        ; move 9 into rax
;        sar rdx, 63         ; and sign extend since 9 fits into low bits
;        mov rcx, 2          ; move 2 into rcx (divisor)
;        idiv rcx            ; divide rax:rdx by rcx --> quotient into rax
;;        mov rax, rdx        ; uncomment to move the remainder into rax
;        ret                  ; return the value in rax

;        mov eax, 9
;        cdq
;        mov ebx, 2
;        idiv ebx
;;        mov eax, edx        ; uncomment to move the remainder into eax (part of rax)
;        ret                  ; return the value in rax

; compare
;        mov rax, 1
;        mov rbx, 2
;        cmp rax, rbx        ; compare rax and rbx
;        setl al             ; check if rax < rbx - result must be stored in a byte sized register
;        movzx rax, al       ; move flag with zero extend
;        ret                  ; return the value in rax

; test
;        mov rax, -1
;        test rax, rax
;;        setz al             ; check if rbx is 0
;        sets al              ; check if rbx is negative
;        movzx rax, al        ; move flag with zero extend
;        ret                  ; return the value in rax


; translate to assembly
;  if(x+3 > y)
;    y++;
;  else
;    y = y*2;
;  return y;
;
;        mov rax, 0          ; set x to 0 or 1 to get different results
;        mov rbx, 3          ; set y
;        add rax, 3          ; x = x + 3
;        cmp rax, rbx        ; compare x and y
;        jng .else           ; if not greater than
;        inc rbx             ; increment y
;        jmp .done
;    .else:
;        sal rbx, 1          ; shift y by 1 (multiply by 2)
;    .done:
;        mov rax, rbx        ; return y
;        ret                 ; return the value in rax


; for loop
;   int x = 0;
;   for(i=0; i<3; i++)
;     x++;
;   return x;
;
;        mov rax, 0          ; x=0
;        mov rbx, 0          ; i=0
;        cmp rbx, 3          ; compare i and 3
;        jnl .done
;    .loop:
;        inc rax             ; x++
;        inc rbx             ; i++
;        cmp rbx, 3          ; compare i and 3
;        jl  .loop           ; repeat loop if less than
;    .done:
;        ret                  ; return the value in rax


; conditional move example
;  if(x+3 > y)
;    y++;
;  else
;    y = y*2;
;  return y;
;
;        mov rax, 0          ; set x to 0 or 1 to get different results
;        mov rbx, 3          ; set y
;        lea rcx, [rax+3]    ; x+3 and free up rax
;        lea rax, [rbx*2]    ; y*2
;        mov rdx, rbx        ; copy y
;        inc rdx             ; increment y
;        cmp rcx, rbx        ; compare x+3 and y
;        cmovg rax, rdx      ; change return if greater than
;        ret                 ; return the value in rax


;; function call
;        mov rdi, 1          ; first parameter
;        mov rsi, 2          ; second parameter
;        ; other parameters should be in rdx, rcx, r8, r9
;        ; let's assume they are and pass another paremeter via memory
;        push 3              ; put first memory parameter onto the stack
;        call .sum           ; after call, return value of sum in rax
;        pop rdi             ; remove stack parameters
;        ret                 ; return the value in rax
;
;    .sum:
;        mov rax, rdi        ; get first parameter
;        add rax, rsi        ; add second parameter
;        add rax, [rsp+8]    ; add third parameter
;        ret                 ; return value in rax



; function call with variables on the stack
        mov rdi, 1          ; first parameter
        mov rsi, 2          ; second parameter
        ; other parameters should be in rdx, rcx, r8, r9
        ; let's assume they are and pass another paremeter via memory
        push 3              ; put first memory parameter onto the stack
        call .sum           ; after call, return value of sum in rax
        pop rdi             ; remove stack parameters
        ret                 ; return the value in rax

    ; instead of using rax as our accumulator, we'll use the stack
    ; so we need to save the initial value of the stack and restore it
    .sum:
        push rbp            ; save the base pointer on the stack (at rsp+8)
        mov rbp, rsp        ; set up the rbp for the bottom of this frame
        push rdi            ; get first parameter (at rbp-8)
        push rsi            ; get second parameter (at rbp-16)
        mov rax, [rbp+16]   ; get third parameter into the return register
                            ; +16 because we incremented rsp when pushing rbp
        add rax, [rbp-8]    ; add first parameter
        add rax, [rbp-16]   ; add second parameter
        mov rsp, rbp        ; restore stack pointer to before we pushed parameters onto the stack
        pop rbp             ; remove rbp from the stack to restore rsp to initial value
        ret                 ; return value in rax
