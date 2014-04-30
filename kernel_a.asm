[BITS 16]       ; budeme pracovať v 16-bitovóm režime (RealMode)
[EXTERN _main]  ; fce main() z kernel.c, C pri kompiláci
                ; do OBJ pridava podtržítko pred každý názov fce
[GLOBAL start]  ; štart bude možno použiť aj inde

start:
  call _main    ; zavoláme main() z kernel.c
  jmp $         ; halt PC -> ničoco ako 'halt: jmp halt'
