#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct Queue {
    int queue[MAX_SIZE];
    int front;
    int rear;
};

void initQueue(struct Queue* q) {
    q->front = -1;
    q->rear = -1;
}

int is_empty(struct Queue* q) {
    return (q->front == -1 && q->rear == -1);
}

int is_full(struct Queue* q) {
    return ((q->rear + 1) % MAX_SIZE == q->front);
}

void enqueue(struct Queue* q, int item) {
    if (is_full(q)) {
        printf("Queue is full. \n");
        return;
    }

    if (is_empty(q)) {
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % MAX_SIZE;
    }

    q->queue[q->rear] = item;
}

int dequeue(struct Queue* q) {
    if (is_empty(q)) {
        printf("Queue is empty.\n");
        return -1;
    }

    int item = q->queue[q->front];

    if (q->front == q->rear) {
        q->front = -1;
        q->rear = -1;
    } else {
        q->front = (q->front + 1) % MAX_SIZE;
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
    int i = q->front;
    while (i != q->rear) {
        printf("%d ", q->queue[i]);
        i = (i + 1) % MAX_SIZE;
    }
    printf("%d\n", q->queue[q->rear]);
}

int main() {
    struct Queue q;
    initQueue(&q);

    int choice;
    int item;

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

