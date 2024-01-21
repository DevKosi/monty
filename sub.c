#include "monty.h"

/**
 * f_sub - Subtracts the top element from the second top element of the stack.
 * @head: Stack head
 * @counter: Line number
 * Return: No return
 */
void f_sub(stack_t **head, unsigned int counter)
{
    stack_t *aux;
    int result, num_nodes;

    aux = *head;

    for (num_nodes = 0; aux != NULL; num_nodes++)
        aux = aux->next;

    if (num_nodes < 2)
    {
        fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    aux = *head;
    result = aux->next->n - aux->n;
    aux->next->n = result;
    *head = aux->next;
    free(aux);
}

