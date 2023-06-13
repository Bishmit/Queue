#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 20

struct Queue {
    int queue[MAX_SIZE];
    int front;
    int rear;
};

void initQueue(struct Queue* q) {
    q->front = 0;
    q->rear = -1;
    int i; 
     for (i = 0; i < MAX_SIZE; i++) {
        q->queue[i] = 0;
    }
}

int is_empty(struct Queue* q) {
    return (q->front > q->rear);
}

int is_full(struct Queue* q) {
    return (q->rear >= MAX_SIZE - 1);
}

void enqueue(struct Queue* q, int item) {
    if (is_full(q)) {
        printf("Queue overflow. Cannot enqueue more items.\n");
        return;
    }

    if (is_empty(q)) {
        q->front = 0;
        q->rear = 0;
    }

    q->rear++;
    q->queue[q->rear] = item;
}

int dequeue(struct Queue* q) {
    if (is_empty(q)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    int item = q->queue[q->front];
    if (q->front == q->rear) {
        q->front = 0;
        q->rear = -1;
    } else {
        q->front++;
    }

    return item;
}

int get_front(struct Queue* q) {
    if (is_empty(q)) {
        printf("Queue is empty.\n");
        return -1;
    }

    return q->queue[q->front];
}

int get_rear(struct Queue* q) {
    if (is_empty(q)) {
        printf("Queue is empty.\n");
        return -1;
    }

    return q->queue[q->rear];
}

void display_queue(struct Queue* q) {
    if (is_empty(q)) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    int i;

    for (i = q->front; i <= q->rear; i++) {
        printf("%d ", q->queue[i]);
    }

    printf("\n");
}


int main() {
    struct Queue q;
    initQueue(&q);
    int choice, item;

    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display Front\n");
        printf("4. Display Rear\n");
        printf("5. Display Queue\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the item to enqueue: ");
                scanf("%d", &item);
                enqueue(&q, item);
                break;
            case 2:
                item = dequeue(&q);
                if (item != -1)
                    printf("Dequeued item: %d\n", item);
                break;
            case 3:
                item = get_front(&q);
                if (item != -1)
                    printf("Front of the queue: %d\n", item);
                break;
            case 4:
                item = get_rear(&q);
                if (item != -1)
                    printf("Rear of the queue: %d\n", item);
                break;
            case 5:
                display_queue(&q);
                break;
            case 6:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    }

    return 0;
}

