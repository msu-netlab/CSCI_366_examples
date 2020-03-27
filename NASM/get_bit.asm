
        global  get_bit
        section .text
get_bit:
        push rbp            ; save the base pointer on the stack (at rsp+8)
        mov rbp, rsp        ; set up the rbp for the bottom of this frame

        ; rdi contains data
        ; rsi contains mask

        and rdi, rsi        ; and data and mask
        cmp rdi, 0          ; check if any bits set in rdi
        setg al
        movsx rax, al       ; move result to rax

        mov rsp, rbp        ; restore stack pointer to before we pushed parameters onto the stack
        pop rbp             ; remove rbp from the stack to restore rsp to initial value
        ret                 ; return value in rax
