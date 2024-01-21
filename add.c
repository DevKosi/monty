#include "monty.h"

/**
 * add_top_two_elements - Adds the top two elements of the stack.
 * @head: Pointer to the stack head
 * @counter: Line number
 * Return: No return value
 */
void add_top_two_elements(stack_t **head, unsigned int counter)
{
    stack_t *current;
    int length = 0, sum;

    current = *head;

    while (current)
    {
        current = current->next;
        length++;
    }

    if (length < 2)
    {
        fprintf(stderr, "L%d: can't add, stack too short\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    current = *head;
    sum = current->n + current->next->n;
    current->next->n = sum;
    *head = current->next;
    free(current);
}

