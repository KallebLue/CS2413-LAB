typedef struct {
    int* queue1;  // First queue used for stack operations
    int* queue2;  // Second queue used for transferring elements
    int front1;    // Front pointer for queue1
    int rear1;     // Rear pointer for queue1
    int front2;    // Front pointer for queue2
    int rear2;     // Rear pointer for queue2
    int capacity;  // Capacity of the queues (fixed size)
} MyStack;

// Function to create a new stack
MyStack* myStackCreate() {
    MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
    stack->capacity = 100;
    // Allocate memory for the two queues (queue1 and queue2)
    stack->queue1 = (int*)malloc(stack->capacity * sizeof(int));
    stack->queue2 = (int*)malloc(stack->capacity * sizeof(int));
    // Initialize both queues as empty
    stack->front1 = stack->rear1 = -1;
    stack->front2 = stack->rear2 = -1; 
    
    return stack;
}

// Function to push an element onto the stack
void myStackPush(MyStack* obj, int x) {
    // Insert the element into queue1
    obj->queue1[++obj->rear1] = x;
    
    // If queue1 was empty, set front1 to 0
    if (obj->front1 == -1) obj->front1 = 0;
}

// Function to pop an element from the stack
int myStackPop(MyStack* obj) {
    // Move all elements from queue1 to queue2, except the last one
    while (obj->front1 != obj->rear1) {
        obj->queue2[++obj->rear2] = obj->queue1[obj->front1++];
    }

    // The last element remaining in queue1 is the top of the stack
    int popped = obj->queue1[obj->front1];
    
    // Reset queue1 to indicate it is empty
    obj->front1 = obj->rear1 = -1;
    
    // Swap queue1 and queue2.
    int* tempQueue = obj->queue1;
    obj->queue1 = obj->queue2;
    obj->queue2 = tempQueue;
    
    // Reset queue2 pointers
    obj->front1 = (obj->rear2 == -1) ? -1 : 0;
    obj->rear1 = obj->rear2;
    obj->front2 = obj->rear2 = -1;
    return popped;
}

// Function to get the top element of the stack without removing it
int myStackTop(MyStack* obj) {
    return obj->queue1[obj->rear1];
}

// Function to check if the stack is empty
bool myStackEmpty(MyStack* obj) {
    // The stack is empty if queue1 is empty
    return obj->rear1 == -1;
}

// Function to free the memory allocated for the stack
void myStackFree(MyStack* obj) {
    free(obj->queue1);
    free(obj->queue2);
    free(obj);
}


/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/
