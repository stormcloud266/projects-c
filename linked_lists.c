#include <stdio.h>
#include <stdlib.h>

// `typedef` is a keyword used in C to define a new type. It allows you to create an alias for a more complex type definition.

// `struct` is a keyword in C used to define a composite data type called structure. It groups multiple variables of different 
// data types under a single name. In this case, the structure is defining a "node" of a linked list.

typedef struct Node {  // Start defining a new structure type named 'Node'.

    int data;  // Within the structure, declare an integer variable 'data'. 
               // This variable will hold the actual value that we want to store in the node.

    struct Node* next;  // Declare a pointer named 'next' of type 'struct Node'. 
                        // This pointer will point to the next node in the linked list. 
                        // If it is the last node in the list, it will point to NULL.

} Node;  // End of 'Node' structure definition. 
         // Now, instead of referring to this structure as 'struct Node', 
         // you can simply use the name 'Node' because of the `typedef`.


// This function is used to dynamically allocate memory for a new node and initialize it with the given data.
Node* createNewNode(int data) {
    // Dynamically allocate memory for a new node using the 'malloc' function.
    // The size of the memory allocated is the size of a Node, as determined by the 'sizeof' function.
    Node* newNode = (Node*)malloc(sizeof(Node));

    // Check if memory allocation was successful.
    if (!newNode) {
        printf("Memory allocation failed!\n");
        return NULL;  // If memory allocation failed, return NULL.
    }

    newNode->data = data;  // Set the 'data' field of the new node with the given data.
    newNode->next = NULL;  // Initialize the 'next' pointer of the new node to NULL.

    return newNode;  // Return the pointer to the newly created node.
}

// This function is used to insert a node at the beginning of the linked list.
void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNewNode(data);  // Create a new node with the given data.
    newNode->next = *head;  // Point the 'next' field of the new node to the current first node (i.e., the current head).
    *head = newNode;  // Update the head of the list to point to the new node.
}

// This function appends (or adds) a node to the end of the linked list.
void append(Node** head, int data) {
    Node* newNode = createNewNode(data);  // Create a new node with the given data.

    // If the linked list is empty, make the new node the head of the list.
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    // If the list is not empty, traverse to the end of the list.
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    // Point the 'next' field of the last node to the new node.
    temp->next = newNode;
}

// This function displays the elements of the linked list.
void display(Node* head) {
    Node* temp = head;  // Start from the head of the list.
    
    // Traverse the list and print each node's data until the end of the list is reached.
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;  // Move to the next node.
    }

    printf("NULL\n");  // Indicate the end of the list.
}

// This function releases (or frees) the memory allocated for the linked list, preventing memory leaks.
void freeList(Node* head) {
    Node* temp;

    // Traverse the list and free each node.
    while (head != NULL) {
        temp = head;  // Store the current node.
        head = head->next;  // Move to the next node.
        free(temp);  // Release the memory of the stored node.
    }
}

// The 'main' function is the entry point of the program.
int main() {
    Node* head = NULL;  // Initialize the head of the linked list to NULL, indicating an empty list.

    // Insert and append nodes to the linked list.
    insertAtBeginning(&head, 5);
    insertAtBeginning(&head, 3);
    append(&head, 7);
    append(&head, 9);

    display(head);  // Display the linked list.

    freeList(head);  // Free the memory allocated for the linked list.

    return 0;  // End the program with a status code of 0 (indicating success).
}
