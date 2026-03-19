#include <stdio.h>

struct linkedlist {
    int value;
    struct linkedlist *next;
};

int main() {
    struct linkedlist node1;
    struct linkedlist node2;

    node1.value = 10;
    node2.value = 20;

    node1.next = &node2;
    node2.next = NULL;

    printf("Node 1: %d\n", node1.value);
    printf("Node 2: %d\n", node1.next->value);

    return 0;
}
