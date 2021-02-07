/* TODO fix parity */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// tags
typedef struct ConditionCodes {    
    uint8_t  z:1; // zero
    uint8_t  s:1; // sign
    uint8_t  p:1; // parity   
    uint8_t  cy:1; // carry   
    uint8_t  ac:1; // auxillary carry, useless for space invaders
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
        /* case 0x01: */ 
        /*     state->c = opcode[1]; */
        /*     state->b = opcode[2]; */
        /*     state->pc += 2; */
        /*     break; */

        // ARITHMETIC
        case 0x80: {
            uint16_t answer = (uint16_t) state->a + (uint16_t) state->b;
            state->cc.z = ((answer && 0xff) == 0);
            state->cc.s = ((answer && 0x80) != 0);
            state->cc.cy = (answer > 0xff);
            state->cc.p = Parity(answer & 0xff);
            state->a = answer & 0xff;
            break;
        }
        case 0x81: {
            uint16_t answer = (uint16_t) state->a + (uint16_t) state->c;
            state->cc.z = ((answer && 0xff) == 0);
            state->cc.s = ((answer && 0x80) != 0);
            state->cc.cy = (answer > 0xff);
            state->cc.p = Parity(answer & 0xff);
            state->a = answer & 0xff;
            break;
        }
        case 0x82: {
            uint16_t answer = (uint16_t) state->a + (uint16_t) state->d;
            state->cc.z = ((answer && 0xff) == 0);
            state->cc.s = ((answer && 0x80) != 0);
            state->cc.cy = (answer > 0xff);
            state->cc.p = Parity(answer & 0xff);
            state->a = answer & 0xff;
            break;
        }
        case 0x83: {
            uint16_t answer = (uint16_t) state->a + (uint16_t) state->e;
            state->cc.z = ((answer && 0xff) == 0);
            state->cc.s = ((answer && 0x80) != 0);
            state->cc.cy = (answer > 0xff);
            state->cc.p = Parity(answer & 0xff);
            state->a = answer & 0xff;
            break;
        }
        case 0x84: {
            uint16_t answer = (uint16_t) state->a + (uint16_t) state->h;
            state->cc.z = ((answer && 0xff) == 0);
            state->cc.s = ((answer && 0x80) != 0);
            state->cc.cy = (answer > 0xff);
            state->cc.p = Parity(answer & 0xff);
            state->a = answer & 0xff;
            break;
        }
        case 0x85: {
            uint16_t answer = (uint16_t) state->a + (uint16_t) state->l;
            state->cc.z = ((answer && 0xff) == 0);
            state->cc.s = ((answer && 0x80) != 0);
            state->cc.cy = (answer > 0xff);
            state->cc.p = Parity(answer & 0xff);
            state->a = answer & 0xff;
            break;
        }
        // case 0x86
        case 0x87: {
            uint16_t answer = (uint16_t) state->a + (uint16_t) state->a;
            state->cc.z = ((answer && 0xff) == 0);
            state->cc.s = ((answer && 0x80) != 0);
            state->cc.cy = (answer > 0xff);
            state->cc.p = Parity(answer & 0xff);
            state->a = answer & 0xff;
            break;
        }
        case 0x88:  {
            uint16_t answer = (uint16_t) state->a + (uint16_t) state->b + state->cc.cy;
            state->cc.z = ((answer && 0xff) == 0);
            state->cc.s = ((answer && 0x80) != 0);
            state->cc.cy = (answer > 0xff);
            state->cc.p = Parity(answer & 0xff);
            state->a = answer & 0xff;
            break;
        }
        case 0x89:  {
            uint16_t answer = (uint16_t) state->a + (uint16_t) state->c + state->cc.cy;
            state->cc.z = ((answer && 0xff) == 0);
            state->cc.s = ((answer && 0x80) != 0);
            state->cc.cy = (answer > 0xff);
            state->cc.p = Parity(answer & 0xff);
            state->a = answer & 0xff;
            break;
        }
        case 0x8a:  {
            uint16_t answer = (uint16_t) state->a + (uint16_t) state->d + state->cc.cy;
            state->cc.z = ((answer && 0xff) == 0);
            state->cc.s = ((answer && 0x80) != 0);
            state->cc.cy = (answer > 0xff);
            state->cc.p = Parity(answer & 0xff);
            state->a = answer & 0xff;
            break;
        }
        case 0x8b:  {
            uint16_t answer = (uint16_t) state->a + (uint16_t) state->e + state->cc.cy;
            state->cc.z = ((answer && 0xff) == 0);
            state->cc.s = ((answer && 0x80) != 0);
            state->cc.cy = (answer > 0xff);
            state->cc.p = Parity(answer & 0xff);
            state->a = answer & 0xff;
            break;
        }
        case 0x8c:  {
            uint16_t answer = (uint16_t) state->a + (uint16_t) state->h + state->cc.cy;
            state->cc.z = ((answer && 0xff) == 0);
            state->cc.s = ((answer && 0x80) != 0);
            state->cc.cy = (answer > 0xff);
            state->cc.p = Parity(answer & 0xff);
            state->a = answer & 0xff;
            break;
        }
        case 0x8d:  {
            uint16_t answer = (uint16_t) state->a + (uint16_t) state->l + state->cc.cy;
            state->cc.z = ((answer && 0xff) == 0);
            state->cc.s = ((answer && 0x80) != 0);
            state->cc.cy = (answer > 0xff);
            state->cc.p = Parity(answer & 0xff);
            state->a = answer & 0xff;
            break;
        }
        // case 0x8e
        case 0x8f:  {
            uint16_t answer = (uint16_t) state->a + (uint16_t) state->a + state->cc.cy;
            state->cc.z = ((answer && 0xff) == 0);
            state->cc.s = ((answer && 0x80) != 0);
            state->cc.cy = (answer > 0xff);
            state->cc.p = Parity(answer & 0xff);
            state->a = answer & 0xff;
            break;
        }

        default: unimplemented(state); break;
    }
    state->pc+=1;
}

int main() {
    return 0;
}
