#include <stdio.h>
#include <stdlib.h>

int disassemble(char *buffer, int pc) {
    char *code = &buffer[pc];
    int opbytes = 1;

    printf("%04x ", pc);
    switch (*code) {
        case 0x00: printf("NOP"); break;
        case 0x01: printf("LXI B,%02x%02x", code[2], code[1]); opbytes=3; break;    
        case 0x02: printf("STAX B"); break;
        case 0x03: printf("INX B"); break;
        case 0x04: printf("INR B"); break;
        case 0x05: printf("DCR B"); break;
        case 0x06: printf("MVI B, %02x", code[1]); opbytes=2; break;
        case 0x07: printf("RLC"); break;
        case 0x09: printf("DAD B"); break;
        case 0x0a: printf("LDAX B"); break;
        case 0x0b: printf("DCX B"); break;
        case 0x0c: printf("INR C"); break;
        case 0x0d: printf("DCR C"); break;
        default: printf("pas fini"); break;
    }
    printf("\n");
    return opbytes;
}

int main (int argc, char**argv) {
    FILE *f= fopen(argv[1], "rb");    
    if (f==NULL) {    
        printf("error: Couldn't open %s\n", argv[1]);    
        exit(1);    
    }    

    //Get the file size and read it into a memory buffer    
    fseek(f, 0L, SEEK_END);    
    int fsize = ftell(f);    
    fseek(f, 0L, SEEK_SET);    

    unsigned char *buffer=malloc(fsize);    

    fread(buffer, fsize, 1, f);    
    fclose(f);    

    // for (int i = 0; i < fsize; i++)
    //     printf("%d\n", buffer[i]); 

    int pc = 0; // program counter

    while (pc < fsize) {
        pc += disassemble(buffer, pc);
    }

    return 0;    
}    
