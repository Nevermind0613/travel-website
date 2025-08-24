#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {
    struct Node *head = NULL, *temp = NULL, *newnode;
    int i, value;
    int n;
    printf("Total values u want give:");
    scanf("%d",&n);
    printf("Total %d values are taken.\n",n);
    for(i = 0; i < n; i++) {
        printf("Enter value: ");
        scanf("%d", &value);
        // Use malloc for even index
        if(i % 2 == 0) {
            newnode = (struct Node*)malloc(sizeof(struct Node));
        } 
        else {//Use calloc for odd index
            newnode = (struct Node*)calloc(1, sizeof(struct Node));
        }
        if(newnode == NULL) {
            printf("Memory not allocated.\n");
            exit(0);
        }
        newnode->data = value;  
        newnode->next = NULL;   
        if(head == NULL) {
            head = newnode;
            temp = head;
        } else {
            temp->next = newnode;
            temp = newnode;
        }
    }
    printf("Linked List: ");
    temp = head;
    while(temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
    return 0;
}
