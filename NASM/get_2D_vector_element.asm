
        global  get_2D_vector_element
        section .text
get_2D_vector_element:
        push rbp            ; save the base pointer on the stack (at rsp+8)
        mov rbp, rsp        ; set up the rbp for the bottom of this frame

        ; rdi contains vector pointer
        ; rsi contains i - row number
        ; rdx contains j - column number
        ; vector structures are 24 bytes long
        ; ints are 4 bytes long

        imul rsi, 24            ; compute row offset (i * vector size)
        add rdi, rsi            ; compute row pointer
        mov rax, [rdi]          ; read address at row pointer
        lea rax, [rax + rdx*4]  ; add element offset (j * int size)
        mov rax, [rax]          ; read stored value

        mov rsp, rbp        ; restore stack pointer to before we pushed parameters onto the stack
        pop rbp             ; remove rbp from the stack to restore rsp to initial value
        ret                 ; return value in rax
