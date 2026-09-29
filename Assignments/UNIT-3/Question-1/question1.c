#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL;
struct Node* createNode(int value)
{  struct Node *newNode = malloc(sizeof(struct Node));
    if (newNode == NULL)
    {  printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(int value)
{   struct Node *newNode = createNode(value);
    newNode->next = head;
    head = newNode;
}

void insertAtEnd(int value)
{
    struct Node *newNode = createNode(value);

    if (head == NULL)
    {    head = newNode;
    }
    else
    {  struct Node *temp = head;
        while (temp->next != NULL)
                    temp = temp->next;
        temp->next = newNode;
    }
}

void insertAfter(int key, int value)
{   struct Node *temp = head;
    while (temp != NULL && temp->data != key)
                  temp = temp->next;

    if (temp == NULL)
    {
        printf("Key %d not found\n", key);
        return;
    }
    struct Node *newNode = createNode(value);
    newNode->next = temp->next;
    temp->next = newNode;
    displayList();
}

void deleteValue(int value)
{
    struct Node *temp = head;
    struct Node *prev = NULL;
    while (temp != NULL && temp->data != value)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
    {
        printf("Value %d not found\n", value);
        return;
    }

    if (prev == NULL)
        head = temp->next;
    else
        prev->next = temp->next;
    
    free(temp);
    displayList();
}

void searchValue(int value)
{
    struct Node *temp = head;
    int pos = 1;
    while (temp != NULL)
    {
        if (temp->data == value)
        {
            printf("Value %d found at position %d\n",
                   value, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Value %d not found in the list\n", value);
}

void displayList()
{
    if (head == NULL)
    {   printf("List is empty\n");
        return;
    }
    printf("List elements: ");
    struct Node *temp = head;
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    int choice, value, key;
    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert After Key\n");
        printf("4. Delete Value\n");
        printf("5. Search Value\n");
        printf("6. Display List\n");
        printf("7. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;

            case 3:
                printf("Enter key: ");
                scanf("%d", &key);
                printf("Enter value: ");
                scanf("%d", &value);
                insertAfter(key, value);
                break;

            case 4:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteValue(value);
                break;

            case 5:
                printf("Enter value to search: ");
                scanf("%d", &value);
                searchValue(value);
                break;

            case 6:
                displayList();
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
