#include <stdio.h>
#include <stdlib.h>

// structure for each node in a linked list
struct list_element {
    char *name;
    struct list_element *next;
};

// returns a pointer to the new list element
struct list_element *list_append(struct list_element *head, char *name);

int main()
{
    struct list_element head = { NULL, NULL }; // initialize empty list

    list_append(&head, "first name");
    list_append(&head, "first name");
    list_append(&head, "third");
    list_append(&head, "fourth");

    struct list_element *n = head.next;
    while (n->next != NULL) {
        printf("%s\n", n->name);
        n = n->next;
    }
    printf("%s\n", n->name);
    
    return EXIT_SUCCESS;
}

// insert name at the end of the list
struct list_element *list_append(struct list_element *head, char *name)
{
    // create a new list element
    struct list_element *new_el = (struct list_element *) malloc(sizeof(int));
    new_el->name = name;
    new_el->next = NULL;

    printf("sizeof(struct list_element) = %lu\n", sizeof(struct list_element));
    printf("new_el = %p\n", new_el);
    printf("&new_el->name = %p\n", &new_el->name);
    printf("&new_el->arr = %p\n", &new_el->arr);
    printf("&new_el->next = %p\n", &new_el->next);
    
    // add this new list element to the end
    struct list_element *cur = head;
    while (cur->next != NULL) {
        cur = cur->next;
    }
    cur->next = new_el;
    
    // return pointer to that element
    return new_el;
}
