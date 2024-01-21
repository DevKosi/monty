#include "monty.h"

/**
 * divide_top_two_elements - Divides the top two elements of the stack.
 * @head: Pointer to the stack head
 * @counter: Line number
 * Return: No return value
 */
void divide_top_two_elements(stack_t **head, unsigned int counter)
{
    stack_t *current;
    int length = 0, result;

    current = *head;

    while (current)
    {
        current = current->next;
        length++;
    }

    if (length < 2)
    {
        fprintf(stderr, "L%d: can't div, stack too short\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    current = *head;

    if (current->n == 0)
    {
        fprintf(stderr, "L%d: division by zero\n", counter);
        fclose(bus.file);
        free(bus.content);
        free_stack(*head);
        exit(EXIT_FAILURE);
    }

    result = current->next->n / current->n;
    current->next->n = result;
    *head = current->next;
    free(current);
}

