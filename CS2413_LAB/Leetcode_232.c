


typedef struct {
    int* stack1;  // Stack for pushing elements
    int* stack2;  // Stack for popping elements
    int front1;    // Front (top) index for stack1
    int front2;    // Front (top) index for stack2
    int capacity;  // Capacity of the stacks
} MyQueue;

// Function to create a new MyQueue
MyQueue* myQueueCreate() {
    MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
    obj->capacity = 100;
    obj->stack1 = (int*)malloc(obj->capacity * sizeof(int));
    obj->stack2 = (int*)malloc(obj->capacity * sizeof(int));
    obj->front1 = -1;  // set stacks as empty
    obj->front2 = -1;  
    return obj;
}

// Function to push an element into the queue
void myQueuePush(MyQueue* obj, int x) {
    obj->stack1[++(obj->front1)] = x;  // Push to stack1
}

// Function to pop the front element from the queue
int myQueuePop(MyQueue* obj) {
    if (obj->front2 == -1) {
        // Transfer elements from stack1 to stack2
        while (obj->front1 != -1) {
            obj->stack2[++(obj->front2)] = obj->stack1[(obj->front1)--];
        }
    }

    if (obj->front2 == -1) {
        return -1;  // The queue is empty
    }

    return obj->stack2[(obj->front2)--];  // Pop from stack2
}

// Function to peek at the front element of the queue
int myQueuePeek(MyQueue* obj) {
    if (obj->front2 == -1) {
        // Transfer elements from stack1 to stack2
        while (obj->front1 != -1) {
            obj->stack2[++(obj->front2)] = obj->stack1[(obj->front1)--];
        }
    }
    // check if queue is empty
    if (obj->front2 == -1) {
        return -1;  // The queue is empty
    }
    // return front data
    return obj->stack2[obj->front2];  // Peek from stack2
}

// Function to check if the queue is empty
bool myQueueEmpty(MyQueue* obj) {
    return obj->front1 == -1 && obj->front2 == -1;
}

// Function to free the allocated memory for the queue
void myQueueFree(MyQueue* obj) {
    free(obj->stack1);
    free(obj->stack2);
    free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);
 
 * int param_2 = myQueuePop(obj);
 
 * int param_3 = myQueuePeek(obj);
 
 * bool param_4 = myQueueEmpty(obj);
 
 * myQueueFree(obj);
*/
