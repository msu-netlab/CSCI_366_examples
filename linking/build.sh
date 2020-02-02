#!/bin/bash

cpp main.c /tmp/main.i 
/usr/lib/gcc/x86_64-linux-gnu/7/cc1 /tmp/main.i -o /tmp/main.s
as -o /tmp/main.o /tmp/main.s 

cpp sum.c /tmp/sum.i 
/usr/lib/gcc/x86_64-linux-gnu/7/cc1 /tmp/sum.i -o /tmp/sum.s
as -o /tmp/sum.o /tmp/sum.s 

gcc -o prog /tmp/main.o /tmp/sum.o


