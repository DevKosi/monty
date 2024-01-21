#include "monty.h"

/**
 * push_node - Adds a node to the stack
 * @head: Pointer to the stack head
 * @counter: Line number
 * Return: No return value
 */
void push_node(stack_t **head, unsigned int counter)
{
    int num, j = 0, flag = 0;

    if (bus.arg)
    {
        if (bus.arg[0] == '-')
            j++;

        for (; bus.arg[j] != '\0'; j++)
        {
            if (bus.arg[j] > '9' || bus.arg[j] < '0')
                flag = 1;
        }

        if (flag == 1)
        {
            fprintf(stderr, "L%d: usage: push integer\n", counter);
            fclose(bus.file);
            free(bus.content);
            free_stack(*head);
            exit(EXIT_FAILURE);
        }
    }
    else
    {
        fprintf(stderr, "L%d: usage: push integer\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    num = atoi(bus.arg);

    if (bus.lifi == 0)
        add_node_to_stack(head, num);
    else
        add_node_to_queue(head, num);
}

