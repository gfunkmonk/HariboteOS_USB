[BITS 32]
        GLOBAL  api_fseek

[SECTION .text]

api_fseek:    ; void api_fseek(int fhandle, int offset, int mode);
        PUSH    EBX
        MOV     EDX, 23
        MOV     EAX, [ESP + 8]  ; fhandle
        MOV     EBX, [ESP + 12] ; offset
        MOV     ECX, [ESP + 16] ; mode
        INT     0x40
        POP     EBX
        RET