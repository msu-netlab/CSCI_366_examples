
        global  get_2D_array_element
        section .text
get_2D_array_element:
        push rbp            ; save the base pointer on the stack (at rsp+8)
        mov rbp, rsp        ; set up the rbp for the bottom of this frame

        ; rdi contains array pointer
        ; rsi contains i - row number
        ; rdx contains j - column number
        ; row size is 3 elements
        ; ints are 4 bytes long

        mov rax, rsi            ; get i
;        imul rax, 3             ; compute C*i (C=3 is the number of columns)
        sal rax, 1
        add rax, rsi
        add rax, rdx            ; add j
        sal rax, 2              ; multiply by L (L=4 is the int element size)
        add rax, rdi            ; add the array base address
        mov rax, [rax]          ; read stored value

        mov rsp, rbp        ; restore stack pointer to before we pushed parameters onto the stack
        pop rbp             ; remove rbp from the stack to restore rsp to initial value
        ret                 ; return value in rax
