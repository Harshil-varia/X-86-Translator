//
// Created by Harshil Varia on 18/03/2024.
//

#include <stdio.h>
#include <stdbool.h>
#include "xis.h"
#include "xtra.h"
#include "stdlib.h"


//print out the prologue before translation.
extern void prologue(){
    printf(".global test\ntest:\n \tpush %%rbp\n \tmov %%rsp, %%rbp\n");
    printf("L0:\n");
}

//print out the epilogue after translation.
extern void epilogue(){
    printf("\tpop %%rbp\n\tret");
}

// function to get the correct x86-64 bit register based on the index.
extern const char* get_x86_register(int x_register) {
    static const char *x86_registers[] = {
            "%rax", "%rbx", "%rcx", "%rdx", "%rsi", "%rdi", "%r8", "%r9",
            "%r10", "%r11", "%r12", "%r13", "%r14", "%r15", "%rbp", "%rsp"
    };

    // Check if X register is within valid range
    if (x_register >= 0 && x_register <= 15) {
        return x86_registers[x_register];
    } else {
        return NULL; // Invalid X register
    }

}

// function to get the correct x86-8 bit register based on the index.
extern const char* get_x86_register_8bit(int x_register) {
    static const char *x86_registers[] = {
            "%ah","%al", "%cl", "%dl", "%bl"
    };

    // Check if X register is within valid range
    if (x_register >= 0 && x_register <= 3) {
        return x86_registers[x_register];
    } else {
        return NULL; // Invalid X register
    }

}

//  function that translate each instruction from X assembly to X86-64 Assembly.
extern void translatorFile(FILE *f){
    //declare all necessary variables.
    unsigned short buffer[2]; // Using unsigned short type
    size_t len;
    char *registerS; // source register
    char *registerD; // destination register
    int programCounter=0;
    int flagValue; //flag register value
    int valOperated;

    // buffer[0] >> 8) >> 4  First 4 significant bit
    // (buffer[0] >> 8) & 0x0F Last 4 significant bit

    prologue(); // print out prologue

    bool debugFlag=false;

    while ((len = fread(buffer, sizeof(unsigned short), 1, f)) > 0) {
        if ((buffer[0] >> 8)==0x00 && (buffer[0] & 0xFF)==0x00) {
            break; // 0x00 0x00 (stop looping)..
        }
        bool fourBytesRead=false; // if four bytes were read from the file

        switch (buffer[0] & 0xFF) {
            case I_RET:
                printf("\tret \n");
                break;
            case I_CLD:
                debugFlag=false;
                break;
            case I_STD:
                debugFlag=true;
                break;
            case I_NEG:
                printf("\tneg ");
                registerS=get_x86_register((buffer[0] >> 8) >> 4 );
                printf("%s \n",registerS);
                break;
            case I_NOT:
                printf("\tnot ");
                registerS=get_x86_register((buffer[0] >> 8) >> 4 );
                printf("%s \n",registerS);
                break;
            case I_PUSH:
                printf("\tpush ");
                registerS=get_x86_register((buffer[0] >> 8) >> 4 );
                printf("%s \n",registerS);
                break;
            case I_POP:
                printf("\tpop ");
                registerS=get_x86_register((buffer[0] >> 8) >> 4 );
                printf("%s \n",registerS);
                break;
            case I_JMPR:
            case I_OUT:
                printf("\tpush %%rdi\n");
                registerS=get_x86_register((buffer[0] >> 8) >> 4 );
                printf("\tmov %s, %%rdi \n",registerS);
                printf("\tcall outchar \n");
                printf("\tpop %%rdi\n");
                break;
            case I_INC:
                printf("\tinc ");
                registerS=get_x86_register((buffer[0] >> 8) >> 4 );
                printf("%s\n",registerS);
                break;
            case I_DEC:
                printf("\tdec ");
                registerS=get_x86_register((buffer[0] >> 8) >> 4 );
                printf("%s\n",registerS);
                break;
            case I_BR:
                printf("\ttest ");
                printf("$0x0001, %%r15\n");
                printf("\tmov ");
                flagValue=flagValue & 0x0001;
                printf("$%d, %%r15\n",flagValue );
                if(flagValue){
                    printf("\tjmp ");
                    int valOperated= ((buffer[0] >> 8) >> 4 ) <<4 | (buffer[0] >> 8) & 0x0F ;
                    printf("L%d\n",programCounter+valOperated);
                }
                break;
            case I_JR:
                printf("\tjmp ");
                int valOperated= ((buffer[0] >> 8) >> 4 ) <<4 | (buffer[0] >> 8) & 0x0F ;
                printf("L%d\n",programCounter+valOperated);
                break;
            case I_ADD:
                printf("\tadd ");
                registerS=get_x86_register((buffer[0] >> 8) >> 4 );
                registerD=get_x86_register((buffer[0] >> 8) & 0x0F );
                printf("%s, %s\n",registerS,registerD);
                break;
            case I_SUB:
                printf("\tsub ");
                registerS=get_x86_register((buffer[0] >> 8) >> 4 );
                registerD=get_x86_register((buffer[0] >> 8) & 0x0F );
                printf("%s, %s\n",registerS,registerD);
                break;
            case I_MUL:
                printf("\timul ");
                registerS=get_x86_register((buffer[0] >> 8) >> 4 );
                registerD=get_x86_register(((buffer[0] >> 8)) & 0x0F );
                printf("%s, %s\n",registerS,registerD);
                break;
            case I_DIV:
                printf("\tidiv ");
                registerS=get_x86_register((buffer[0] >> 8) >> 4 );
                registerD=get_x86_register(((buffer[0] >> 8)) & 0x0F );
                printf("%s, %s\n",registerS,registerD);
                break;
            case I_AND:
                printf("\tand ");
                registerS=get_x86_register((buffer[0] >> 8) >> 4 );
                registerD=get_x86_register((buffer[0] >> 8) & 0x0F );
                printf("%s, %s\n",registerS,registerD);
                break;
            case I_OR:
                printf("\tor ");
                registerS=get_x86_register((buffer[0] >> 8) >> 4 );
                registerD=get_x86_register((buffer[0] >> 8) & 0x0F );
                printf("%s, %s\n",registerS,registerD);
                break;
            case I_XOR:
                printf("\txor ");
                registerS=get_x86_register((buffer[0] >> 8) >> 4 );
                registerD=get_x86_register((buffer[0] >> 8) & 0x0F );
                printf("%s, %s\n",registerS,registerD);
                break;
            case I_TEST:
                printf("\tmov ");
                int flagVal = ((buffer[0] >> 8) >> 4 )  & ((buffer[0] >> 8) & 0x0F) ;
                if(flagVal!=0){
                    printf("$%d, %%r15\n",1);
                    flagValue=1;
                }else{
                    printf("$%d, %%r15\n",0);
                    flagValue=0;
                }
                break;
            case I_CMP:
                printf("\tmov ");
                if(((buffer[0] >> 8) >> 4) < ((buffer[0] >> 8) & 0x0F)){
                    printf("$%d, %%r15\n",1);
                    flagValue=1;
                }else{
                    printf("$%d, %%r15\n",0);
                    flagValue=0;
                }
                break;
            case I_EQU:
                printf("\tmov ");
                if(((buffer[0] >> 8) >> 4) == ((buffer[0] >> 8) & 0x0F)){
                    printf("$%d, %%r15\n",1);
                    flagValue=1;
                }else{
                    printf("$%d, %%r15\n",0);
                    flagValue=0;
                }
                break;
            case I_MOV:
                printf("\tmov ");
                registerS=get_x86_register((buffer[0] >> 8) >> 4 );
                registerD=get_x86_register((buffer[0] >> 8) & 0x0F );
                printf("%s, %s\n",registerS,registerD );
                break;
            case I_LOAD:
                printf("\tmov ");
                registerS=get_x86_register((buffer[0] >> 8) >> 4 );
                registerD=get_x86_register((buffer[0] >> 8) & 0x0F );
                printf("(%s), %s\n",registerS,registerD);
                break;
            case I_STOR:
                printf("\tmov ");
                registerS=get_x86_register((buffer[0] >> 8) >> 4 );
                registerD=get_x86_register((buffer[0] >> 8) & 0x0F );
                printf("%s, (%s)\n",registerS,registerD);
                break;
            case I_LOADB:
                printf("\tmovb ");
                registerS=get_x86_register((buffer[0] >> 8) >> 4 );
                registerD=get_x86_register_8bit((buffer[0] >> 8) & 0x0F );
                printf("(%s), %s\n",registerS,registerD);
                break;
            case I_STORB:
                printf("\tmovb ");
                registerS=get_x86_register_8bit((buffer[0] >> 8) >> 4 );
                registerD=get_x86_register((buffer[0] >> 8) & 0x0F );
                printf("%s, (%s)\n",registerS,registerD);
                break;
            case I_LOADA:
                printf("\tmova ");
                registerS=get_x86_register((buffer[0] >> 8) >> 4 );
                registerD=get_x86_register_8bit((buffer[0] >> 8) & 0x0F );
                printf("(%s), %s\n",registerS,registerD);
                break;
            case I_STORA:
                printf("\tmova ");
                registerS=get_x86_register_8bit((buffer[0] >> 8) >> 4 );
                registerD=get_x86_register((buffer[0] >> 8) & 0x0F );
                printf("%s, (%s)\n",registerS,registerD);
                break;
            case I_JMP:
                printf("\tjmp ");
                fread(buffer, sizeof(unsigned short), 1, f);
                valOperated= ((buffer[0] & 0xFF) << 8 )  | (buffer[0] >> 8);
                printf("L%d\n",valOperated);
                fourBytesRead=true;
                break;
            case I_CALL:
                printf("\tcall ");
                fread(buffer, sizeof(unsigned short), 1, f);
                valOperated= ((buffer[0] & 0xFF) << 8 )  | (buffer[0] >> 8);
                printf("L%d\n",valOperated);
                fourBytesRead=true;
                break;
            case I_LOADI:
                printf("\tmov ");
                registerS=get_x86_register((buffer[0] >> 8) >> 4 );
                fread(buffer, sizeof(unsigned short), 1, f);
                valOperated= ((buffer[0] & 0xFF) << 8 )  | (buffer[0] >> 8);
                printf("$%d, %s\n",valOperated,registerS);
                fourBytesRead=true;
                break;

        }

        // keep track of Labels.
        if(fourBytesRead){
            programCounter+=4;
            printf("L%d:\n",programCounter);
        }else if(!fourBytesRead && !debugFlag) {
            programCounter += 2;
            printf("L%d:\n", programCounter);
        }else if(!fourBytesRead && debugFlag){
            programCounter+=2;
            printf("L%d:\n",programCounter);
        }

        // if debug flag is on print this..
        if(debugFlag ) { printf("\tcall debug\n");}
    }


    fclose(f); // close the file

    epilogue(); //  print out the epilogue.


}