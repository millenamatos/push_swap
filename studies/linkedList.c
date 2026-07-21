#include <stdlib.h>
#include <stdio.h>

typedef struct s_node
{
    int value;
    struct s_node *next;
}   t_node;

t_node *new_node(int value)
{
    t_node *new;

    new = malloc(sizeof(t_node));
    if (!new)
        return (NULL);
    new->value = value;
    new->next = NULL;
    return (new);
}

void linkedList(void)
{
    t_node *head;
    t_node *node2;
    t_node *node3;
    t_node *node4;
    t_node *current;

    head = new_node(10);
    node2 = new_node(20);
    node3 = new_node(30);
    node4 = new_node(40);

    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    current = head;
    while (current)
    {
        printf("%d ", current->value);
        current = current->next;
    }
    printf("\n");

    free(head);
    free(node2);
    free(node3);
    free(node4);
}

int main(void)
{
    linkedList();
    return(0);
}