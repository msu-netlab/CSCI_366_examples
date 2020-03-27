
        global  get_rect_area
        section .text
get_rect_area:
        push rbp            ; save the base pointer on the stack (at rsp+8)
        mov rbp, rsp        ; set up the rbp for the bottom of this frame

        ; rdi contains the structure pointer
        ; structure is
        ; struct rect {
        ;   int llx;        -> 4 bytes
        ;   int lly;        -> 4 bytes
        ;   char color;     -> 1 byte stored in 8 bytes to align for the doubles
        ;   double width;   -> 8 bytes
        ;   double height;  -> 8 bytes
        ; };

        movsd xmm0, [rdi+16]
        movsd xmm1, [rdi+24]
        mulsd xmm0, xmm1

        mov rsp, rbp        ; restore stack pointer to before we pushed parameters onto the stack
        pop rbp             ; remove rbp from the stack to restore rsp to initial value
        ret                 ; return value in rax
