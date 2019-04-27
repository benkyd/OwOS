# OwOS
# Copyright Benjamin Kyd (c) 2019

# declare constants for the multiboot header
.set ALIGN,    1<<0                     # align loaded modules on page boundaries
.set MEMINFO,  1<<1                     # provide memory map
.set FLAGS,    ALIGN | MEMINFO          # this is the Multiboot 'flag' field
.set MAGIC,    0x1BADB002               #'magic number' lets bootloader find the header
.set CHECKSUM, -(MAGIC + FLAGS)         # checksum of above, to prove we are multiboot

.section .multiboot
.align 4
.long MAGIC
.long FLAGS
.long CHECKSUM
 
.section .bss
.align 16
stack_bottom:
.skip 16384   # 16 KiB
stack_top:

.section .text
.global _start
.type _start, @function

_start:
    # Settup stack
	mov $stack_top, %esp
	push %ebx
	push %eax

	call kernel_main

	cli
1:	hlt
	jmp 1b


.global INIT_FPU
.type INIT_FPU, @function

INIT_FPU:
    # FPU Config
    VAL_037F:
        .hword 0x037F
    VAL_037E:
        .hword 0x037E
    VAL_037A:
        .hword 0x037A
    # Configure FPU
    cli
    mov %cr0, %ecx
    or $0b00110010, %ecx
    and $0xFFFFFFFB, %ecx
    mov %ecx, %cr0
    fldcw VAL_037F
    fldcw VAL_037E
    fldcw VAL_037A
    fninit

.size _start, . - _start
