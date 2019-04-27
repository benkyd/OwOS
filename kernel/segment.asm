.global SEGMENTS_RELOAD

SEGMENTS_RELOAD:
    ljmp $0x08, $reloadCS

reloadCS:
    movw $0x10, %ax
    movw %ax, %es
    movw %ax, %ss
    movw %ax, %ds
    movw %ax, %fs
    movw %ax, %gs
    ret
