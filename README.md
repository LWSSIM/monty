# Monty OPCODE interperter

## LIFO and FIFO

**LIFO (Last In, First Out)** and **FIFO (First In, First Out)** are two common principles used to manage data in data structures.

- **LIFO**: The last element added to the data structure is the first one to be removed. It operates like a stack of plates - the last plate you put on the stack is the first one you pick up.

### *In C, LIFO behavior can be implemented using an array as a stack*
```C
/*LIFO (Stack) Example*/
#include <stdio.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int value) {
    if (top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = value;
}

int pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack[top--];
}
```
- **FIFO**: The first element added is the first one to be removed. It is analogous to a queue of people waiting in line - the person who arrived first is the first to leave.

### *For FIFO behavior, a simple queue implementation can be done with an array:*
```C
/*FIFO (Queue) Example*/
#include <stdio.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == MAX_SIZE - 1) {
        printf("Queue overflow\n");
        return;
    }
    if (front == -1)
        front = 0;
    queue[++rear] = value;
}

int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue underflow\n");
        return -1;
    }
    return queue[front++];
}
```

## Stack

A **stack** is a data structure that follows the LIFO principle. Elements are added and removed from the same end, known as the "top" of the stack. Stacks are used when the order of elements is crucial and the most recently added element needs to be processed first.

**Common implementations of stacks:**
- **Array-based implementation:** Using arrays to store elements with a pointer indicating the top.
- **Linked list-based implementation:** Using a linked list where each node points to the next node.

**Use cases:**
- Function call management (call stack in programming languages).
- Undo mechanisms in applications.
- Expression evaluation (e.g., parsing mathematical expressions).

### *In C, a stack can be implemented using an array:*
```C
/*Stack Implementation using Array*/
#include <stdio.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int value) {
    if (top == MAX_SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = value;
}

int pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack[top--];
}
```

## Queue

A **queue** is a data structure that follows the FIFO principle. Elements are added at one end, known as the "rear," and removed from the other end, known as the "front" or "head." Queues are used when the order of elements is important, and the oldest element needs to be processed first.

**Common implementations of queues:**
- **Array-based implementation:** Using arrays to store elements with pointers indicating the front and rear.
- **Linked list-based implementation:** Using a linked list with pointers for the front and rear.

**Use cases:**
- Print job management in printers.
- Task scheduling in operating systems.
- Breadth-first search in graph algorithms.

### *For a queue, we can use a similar array-based implementation:*
```C
/*Queue Implementation using Array*/
#include <stdio.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == MAX_SIZE - 1) {
        printf("Queue overflow\n");
        return;
    }
    if (front == -1)
        front = 0;
    queue[++rear] = value;
}

int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue underflow\n");
        return -1;
    }
    return queue[front++];
}
```
## Global Variables

Using global variables should be done judiciously, as they can lead to issues such as unintended side effects and reduced code maintainability. Here are some best practices:

- **Minimize global variables:** Use global variables only when necessary, and try to keep their number to a minimum.
- **Avoid mutable global state:** If you use global variables, make them immutable whenever possible to avoid unintended modifications.
- **Document global variables:** Clearly document the purpose and usage of global variables in comments.
- **Use constants:** If the global variable represents a constant value, consider declaring it as a constant to prevent accidental modifications.

### *In C, global variables can be declared outside of any function.*
```C
// Global Variables Example
#include <stdio.h>

int globalVar = 42; // Global variable

int main() {
    printf("Global variable value: %d\n", globalVar);
    return 0;
}
```
