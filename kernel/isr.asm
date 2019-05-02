.align   4
.global ISR0
.global ISR1
.global ISR2
.global ISR3
.global ISR4
.global ISR5
.global ISR6
.global ISR7
.global ISR8
.global ISR9
.global ISR10
.global ISR11
.global ISR12
.global ISR13
.global ISR14
.global ISR15
.global ISR16
.global ISR17
.global ISR18
.global ISR19
.global ISR20
.global ISR21
.global ISR22
.global ISR23
.global ISR24
.global ISR25
.global ISR26
.global ISR27
.global ISR28
.global ISR29
.global ISR30
.global ISR31

ISR0:
    cli
    push $0
    push $0
    jmp ISR_FAULT

ISR1:
    cli
    push $0
    push $1
    jmp ISR_FAULT

ISR2:
    cli
    push $0
    push $2
    jmp ISR_FAULT

ISR3:
    cli
    push $0
    push $3
    jmp ISR_FAULT

ISR4:
    cli
    push $0
    push $4
    jmp ISR_FAULT

ISR5:
    cli
    push $0
    push $5
    jmp ISR_FAULT

ISR6:
    cli
    push $0
    push $6
    jmp ISR_FAULT

ISR7:
    cli
    push $0
    push $7
    jmp ISR_FAULT

ISR8:
    cli
    push $8
    jmp ISR_FAULT

ISR9:
    cli
    push $9
    jmp ISR_FAULT

ISR10:
    cli
    push $10
    jmp ISR_FAULT

ISR11:
    cli
    push $11
    jmp ISR_FAULT

ISR12:
    cli
    push $12
    jmp ISR_FAULT

ISR13:
    cli
    push $13
    jmp ISR_FAULT

ISR14:
    cli
    push $14
    jmp ISR_FAULT

ISR15:
    cli
    push $15
    jmp ISR_FAULT

ISR16:
    cli
    push $16
    jmp ISR_FAULT

ISR17:
    cli
    push $17
    jmp ISR_FAULT

ISR18:
    cli
    push $18
    jmp ISR_FAULT

ISR19:
    cli
    push $19
    jmp ISR_FAULT

ISR20:
    cli
    push $20
    jmp ISR_FAULT

ISR21:
    cli
    push $21
    jmp ISR_FAULT

ISR22:
    cli
    push $22
    jmp ISR_FAULT

ISR23:
    cli
    push $23
    jmp ISR_FAULT

ISR24:
    cli
    push $24
    jmp ISR_FAULT

ISR25:
    cli
    push $25
    jmp ISR_FAULT

ISR26:
    cli
    push $26
    jmp ISR_FAULT

ISR27:
    cli
    push $27
    jmp ISR_FAULT

ISR28:
    cli
    push 28
    jmp ISR_FAULT

ISR29:
    cli
    push $29
    jmp ISR_FAULT

ISR30:
    cli
    push $30
    jmp ISR_FAULT

ISR31:
    cli
    push $31
    jmp ISR_FAULT

.extern FaultHandler
ISR_FAULT:
    pusha
    push %ds
    push %es
    push %fs
    push %gs
    movw $0x10,%ax
    movw %ax,%ds
    movw %ax,%es
    movw %ax,%fs
    movw %ax,%gs
    movl %esp,%eax
    pushl %eax
    call FaultHandler
    popl %eax
    popl %gs
    popl %fs
    popl %es
    popl %ds
    popa
    addl $8,%esp
    iret

.global ISR_DEFAULT
.extern DEFAULT_ISR
ISR_DEFAULT:
    pushal
    pushw %ds
    pushw %es
    pushw %fs
    pushw %gs
    pushl %ebx
    movw $0x10,%bx
    movw %bx,%ds
    popl %ebx

    cld /* C code following the sysV ABI requires DF to be clear on function entry */
    call DEFAULT_ISR

    popw %gs
    popw %fs
    popw %es
    popw %ds
    popal
    iret

.global ISR_KBD
.extern KeyboardHandler
ISR_KBD:
    pushal
    pushw %ds
    pushw %es
    pushw %fs
    pushw %gs
    pushl %ebx
    movw $0x10,%bx
    movw %bx,%ds
    popl %ebx

    cld /* C code following the sysV ABI requires DF to be clear on function entry */
    call KeyboardHandler

    popw %gs
    popw %fs
    popw %es
    popw %ds
    popal
    iret

