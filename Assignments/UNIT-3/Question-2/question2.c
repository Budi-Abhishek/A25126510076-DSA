#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node
{  char data[50];
    struct Node *prev;
    struct Node *next;
};
struct Node *head = NULL;
struct Node *tail = NULL;
struct Node *current = NULL;
struct Node* createNode(char value[])
{  struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    strcpy(newNode->data, value);
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(char value[])
{   struct Node *newNode = createNode(value);
    if (head == NULL)
    {       head = tail = newNode;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    current = newNode;
}

void insertAtEnd(char value[])
{   struct Node *newNode = createNode(value);

    if (head == NULL)
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    current = newNode;
}
void moveForward()
{
    if (current == NULL)
    {
        printf("List is empty\n");
    }
    else if (current->next == NULL)
    {
        printf("Already at the last page\n");
    }
    else
    {
        current = current->next;
        printf("Current page: %s\n", current->data);
    }
}

void moveBackward()
{   if (current == NULL)
      {     printf("List is empty\n");
      }
    else if (current->prev == NULL)
    {
        printf("Already at the first page\n");
    }
    else
    {
        current = current->prev;
        printf("Current page: %s\n", current->data);
    }
}

void deletePage(char value[])
{   struct Node *temp = head;
    while (temp != NULL && strcmp(temp->data, value) != 0)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {   printf("Page not found\n");
         return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;
    else
        tail = temp->prev;

    if (current == temp)
    {
        if (temp->next != NULL)
            current = temp->next;
        else
            current = temp->prev;
    }
    free(temp);
    printf("Page deleted successfully\n");
}

void displayForward()
{   struct Node *temp = head;
    if (head == NULL)
    {  printf("List is empty\n");
        return;
    }
    printf("Pages from first to last:\n");
    while (temp != NULL)
    {
        printf("%s <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void displayBackward()
{   struct Node *temp = tail;
    if (tail == NULL)
    {   printf("List is empty\n");
        return;
    }
    printf("Pages from last to first:\n");
    while (temp != NULL)
    {
        printf("%s <-> ", temp->data);
        temp = temp->prev;
    }
    printf("NULL\n");
}

int main()
{
    int choice;
    char value[50];
    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Insert At Beginning\n");
        printf("2. Insert At End\n");
        printf("3. Move Forward\n");
        printf("4. Move Backward\n");
        printf("5. Delete Page\n");
        printf("6. Display Pages\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter page name: ");
                scanf("%49s", value);
                insertAtBeginning(value);
                break;

            case 2:
                printf("Enter page name: ");
                scanf("%49s", value);
                insertAtEnd(value);
                break;

            case 3:
                moveForward();
                break;

            case 4:
                moveBackward();
                break;

            case 5:
                printf("Enter page to delete: ");
                scanf("%49s", value);
                deletePage(value);
                break;

            case 6:
                displayForward();
                displayBackward();
                break;

            case 7:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
