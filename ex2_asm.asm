.MODEL  SMALL
.stack 100h

.data
    Napis1          DB     "To jest pierwszy napis",'$'
    DL_NAPIS1       DW     23
    Napis2          DB     "To jest drugi napis",'$'
    DL_NAPIS2       DW     20
    Napis3          DB     ?
    DL_NAPIS3       DW     ?

.code
Start:
    mov ax, @data
    mov ds, ax

    xor ax, ax
    mov dx, OFFSET Napis1
    mov ah, 09h
    int 21h

    xor ax, ax
    mov dx, OFFSET Napis2
    mov ah, 09h
    int 21h

    mov ax, DL_NAPIS1
    mov bx, DL_NAPIS2
    add ax, bx
    mov DL_NAPIS3, ax

    mov ax, 4C00h
    int 21h

END Start
