#include "monty.h"

/**
 * execute_opcode - Executes the opcode
 * @content: Line content
 * @stack: Pointer to the stack
 * @counter: Line number
 * @file: Pointer to monty file
 * Return: 0 if successful, 1 if the opcode is unknown
 */
int execute_opcode(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
    instruction_t opcodes[] = {
        {"push", f_push}, {"pall", f_pall}, {"pint", f_pint},
        {"pop", f_pop},
        {"swap", f_swap},
        {"add", f_add},
        {"nop", f_nop},
        {"sub", f_sub},
        {"div", f_div},
        {"mul", f_mul},
        {"mod", f_mod},
        {"pchar", f_pchar},
        {"pstr", f_pstr},
        {"rotl", f_rotl},
        {"rotr", f_rotr},
        {"queue", f_queue},
        {"stack", f_stack},
        {NULL, NULL}
    };

    unsigned int i = 0;
    char *opcode;

    opcode = strtok(content, " \n\t");

    if (opcode && opcode[0] == '#')
        return 0;

    bus.arg = strtok(NULL, " \n\t");

    while (opcodes[i].opcode && opcode)
    {
        if (strcmp(opcode, opcodes[i].opcode) == 0)
        {
            opcodes[i].f(stack, counter);
            return 0;
        }
        i++;
    }

    if (opcode && opcodes[i].opcode == NULL)
    {
        fprintf(stderr, "L%d: unknown instruction %s\n", counter, opcode);
        fclose(file);
        free(content);
        free_stack(*stack);
        exit(EXIT_FAILURE);
    }

    return 1;
}

