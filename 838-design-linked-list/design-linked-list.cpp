class Node {
public:
    int val;      // Value stored in the node
    Node* next;   // Pointer to the next node in the list

    // Constructor to initialize node with a value and set next pointer to NULL
    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

class MyLinkedList {
public:
    Node* head;  // Pointer to the first node of the list
    Node* tail;  // Pointer to the last node of the list
    int size;    // Number of nodes in the list

    // Constructor to initialize an empty linked list
    MyLinkedList() {
        head = tail = NULL;
        size = 0;
    }
    
    // Get the value of the node at the given index (0-based)
    // Return -1 if index is invalid
    int get(int index) {
        if (index < 0 || index >= size) return -1;  // Check bounds
        
        if (index == 0) return head->val;           // Return head value if index is 0
        if (index == size - 1) return tail->val;    // Return tail value if index is last
        
        // Otherwise, traverse from head to the desired index
        Node* temp = head;
        for (int i = 1; i <= index; i++) {
            temp = temp->next;
        }
        return temp->val;
    }
    
    // Add a new node with value val at the head of the list
    void addAtHead(int val) {
        Node* temp = new Node(val);  // Create new node
        if (size == 0) {
            head = tail = temp;      // If list empty, head and tail point to new node
        } else {
            temp->next = head;       // New node points to current head
            head = temp;             // Update head to new node
        }
        size++;                      // Increase size
    }
    
    // Add a new node with value val at the tail of the list
    void addAtTail(int val) {
        Node* temp = new Node(val);  // Create new node
        if (size == 0) {
            head = tail = temp;      // If list empty, head and tail point to new node
        } else {
            tail->next = temp;       // Current tail points to new node
            tail = temp;             // Update tail to new node
        }
        size++;                      // Increase size
    }
    
    // Add a new node with value val before the index-th node in the list
    // If index equals size, the new node is appended at the end
    // If index is invalid (less than 0 or greater than size), do nothing
    void addAtIndex(int index, int val) {
        if (index < 0 || index > size) return;     // Check bounds
        
        if (index == 0) {
            addAtHead(val);                         // Insert at head
            return;
        }
        
        if (index == size) {
            addAtTail(val);                         // Insert at tail
            return;
        }

        // Insert in the middle
        Node* temp = new Node(val);
        Node* t = head;
        // Traverse to node just before the desired index
        for (int i = 1; i <= index - 1; i++) {
            t = t->next;
        }
        temp->next = t->next;  // New node points to next node at index
        t->next = temp;        // Previous node points to new node
        size++;                // Increase size
    }
    
    // Delete the index-th node in the list, if the index is valid
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;  // Check bounds
        
        if (index == 0) {
            // Remove head node
            Node* toDelete = head;
            head = head->next;  // Update head to next node
            delete toDelete;    // Free memory
            size--;
            if (size == 0) tail = NULL;  // If list empty, tail should be NULL
            return;
        }
        
        if (index == size - 1) {
            // Remove tail node
            Node* temp = head;
            // Traverse to node just before tail
            while (temp->next != tail) {
                temp = temp->next;
            }
            delete tail;         // Free old tail node
            tail = temp;         // Update tail to previous node
            tail->next = NULL;   // Tail's next pointer should be NULL
            size--;
            return;
        }
        
        // Remove a node in the middle
        Node* temp = head;
        // Traverse to node just before the one to delete
        for (int i = 1; i <= index - 1; i++) {
            temp = temp->next;
        }
        Node* toDelete = temp->next;
        temp->next = temp->next->next;  // Bypass node to delete
        delete toDelete;                 // Free memory
        size--;
    }
};
