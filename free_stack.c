#include "monty.h"

/**
 * free_stack - Frees a doubly linked list (stack)
 * @head: Pointer to the head of the stack
 */
void free_stack(stack_t *head)
{
    stack_t *current, *temp;

    current = head;

    while (current)
    {
        temp = current->next;
        free(current);
        current = temp;
    }
}

