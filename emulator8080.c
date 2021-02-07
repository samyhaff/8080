#include <stdio.h>
#include <stdlib.h>

   typedef struct ConditionCodes {    
    uint8_t  z:1;    
    uint8_t  s:1;    
    uint8_t  p:1;    
    uint8_t  cy:1;    
    uint8_t  ac:1;    
    uint8_t  pad:3;    
   } ConditionCodes;    

   typedef struct State {    
    uint8_t a;    
    uint8_t b;    
    uint8_t c;    
    uint8_t d;    
    uint8_t e;    
    uint8_t h;    
    uint8_t l;    
    uint16_t sp;    
    uint16_t  pc;    
    uint8_t *memory;    
    struct ConditionCodes cc;    
    uint8_t  int_enable;    
   } State;   

void unimplemented(State *state) {
    printf("unimplemented opcode");
    exit(1);
}

int emulate(State *state) {
    // opcode points to the memory adress pc
    unsigned char *opcode = &state->memory[state->pc];

    switch (*opcode) {
        case 0x00: break;
        case 0x01: 
            state->c = opcode[1];
            state->b = opcode[2];
            state->pc += 2;
            break;
        default: unimplemented(state); break;
    }
    state->pc+=1
}
