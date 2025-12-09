#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

typedef struct {
    int id;
    char orderName[50];
    int prepTime;
} Customer;

typedef struct {
    Customer queue[MAX];
    int front;
    int rear;
    int count;
} CounterQueue;

void initQueue(CounterQueue *q);
int isFull(CounterQueue *q);
int isEmpty(CounterQueue *q);
void enqueue(CounterQueue *q, Customer c);
Customer dequeue(CounterQueue *q);
void displayQueue(CounterQueue q, int n);
int totalWaitingTime(CounterQueue q);
int findBestCounter(CounterQueue q[], int n);

void initQueue(CounterQueue *q) {
    q->front = 0;
    q->rear = -1;
    q->count = 0;
}

int isFull(CounterQueue *q) {
    return q->count == MAX;
}

int isEmpty(CounterQueue *q) {
    return q->count == 0;
}

void enqueue(CounterQueue *q, Customer c) {
    if (isFull(q)) {
        printf("Queue is full!\n");
        return;
    }
    q->rear = (q->rear + 1) % MAX;
    q->queue[q->rear] = c;
    q->count++;
}

Customer dequeue(CounterQueue *q) {
    Customer temp = {-1, "NONE", 0};
    if (isEmpty(q)) {
        printf("Queue is empty!\n");
        return temp;
    }
    temp = q->queue[q->front];
    q->front = (q->front + 1) % MAX;
    q->count--;
    return temp;
}

void displayQueue(CounterQueue q, int n) {
    printf("\n--- Counter %d Queue ---\n", n);
    if (q.count == 0) {
        printf("EMPTY\n");
        return;
    }
    int i = q.front;
    for (int j = 0; j < q.count; j++) {
        printf("Customer ID: %d | Order: %s | Prep: %d mins\n",
               q.queue[i].id, q.queue[i].orderName, q.queue[i].prepTime);
        i = (i + 1) % MAX;
    }
}

int totalWaitingTime(CounterQueue q) {
    int sum = 0;
    int i = q.front;
    for (int j = 0; j < q.count; j++) {
        sum += q.queue[i].prepTime;
        i = (i + 1) % MAX;
    }
    return sum;
}

int findBestCounter(CounterQueue q[], int n) {
    int minTime = totalWaitingTime(q[0]);
    int index = 0;
    for (int i = 1; i < n; i++) {
        int t = totalWaitingTime(q[i]);
        if (t < minTime) {
            minTime = t;
            index = i;
        }
    }
    return index;
}

int main() {
    CounterQueue counters[3];
    for (int i = 0; i < 3; i++)
        initQueue(&counters[i]);

    int choice, idCounter = 1;

    while (1) {
        printf("\n===============================");
        printf("\n FAST FOOD DRIVE-THRU SIMULATION ");
        printf("\n===============================\n");

        printf("1. Add New Customer\n");
        printf("2. Serve Customer\n");
        printf("3. Display All Counters\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            Customer c;
            c.id = idCounter++;

            printf("Enter Order Name: ");
            scanf("%s", c.orderName);

            printf("Enter Preparation Time (minutes): ");
            scanf("%d", &c.prepTime);

            int best = findBestCounter(counters, 3);

            enqueue(&counters[best], c);

            printf("\nCustomer %d assigned to Counter %d (Best Queue)\n",
                   c.id, best + 1);
        }

        else if (choice == 2) {
            int c;
            printf("Serve from which counter (1-3): ");
            scanf("%d", &c);

            if (c < 1 || c > 3) {
                printf("Invalid counter!\n");
                continue;
            }

            Customer served = dequeue(&counters[c - 1]);

            if (served.id != -1) {
                printf("\nServing Customer %d | Order: %s\n",
                       served.id, served.orderName);
            }
        }

        else if (choice == 3) {
            for (int i = 0; i < 3; i++)
                displayQueue(counters[i], i + 1);
        }

        else if (choice == 4) {
            printf("\nExiting Simulation...\n");
            break;
        }

        else {
            printf("Invalid Choice!\n");
        }
    }

    return 0;
}
