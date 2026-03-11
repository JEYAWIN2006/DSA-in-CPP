#include <stdio.h>
#define MAX 10
#define MAXP 5
struct ticket{
    int train_no;
    char train_name[30];
    int no_of_passengers;
    char passenger_names[MAXP][30];
    long int phone_no;
    float price;
};
struct queue{
    struct ticket a[MAX];
    int front, rear;
};
void enqueue(struct queue *q);
void dequeue(struct queue *q);
void display(struct queue *q);
void enqueue(struct queue *q)
{
    int i;
    if (q->rear == MAX - 1){
        printf("Queue is full\n");
        return;
    }
    if (q->front == -1)
        q->front = 0;
    q->rear++;
    printf("Enter Train No: ");
    scanf("%d", &q->a[q->rear].train_no);
    printf("Enter Train Name: ");
    scanf("%s", q->a[q->rear].train_name);
    printf("Enter No of Passengers: ");
    scanf("%d", &q->a[q->rear].no_of_passengers);
    for (i = 0; i < q->a[q->rear].no_of_passengers; i++){
        printf("Enter Passenger %d Name: ", i + 1);
        scanf("%s", q->a[q->rear].passenger_names[i]);
    }
    printf("Enter Phone No: ");
   scanf("%ld", &q->a[q->rear].phone_no);
   printf("Enter Ticket Price: ");
   scanf("%f", &q->a[q->rear].price);
}
void dequeue(struct queue *q)
{
    if (q->front == -1 || q->front > q->rear)
    {
        printf("Queue is empty\n");
        return;
    }
    printf("\nTicket Cancelled:\n");
    printf("Train No: %d\n", q->a[q->front].train_no);
    q->front++;
    if (q->front > q->rear)
        q->front = q->rear = -1;
}
void display(struct queue *q)
{
    int i, j;
    if (q->front == -1){
        printf("No reservations available\n");
        return;
    }
    printf("\nTrain Ticket Reservations:\n");
    for (i = q->front; i <= q->rear; i++){
        printf("\nTrain No: %d", q->a[i].train_no);
        printf("\nTrain Name: %s", q->a[i].train_name);
        printf("\nNo of Passengers: %d", q->a[i].no_of_passengers);
        for (j = 0; j < q->a[i].no_of_passengers; j++) {
            printf("\nPassenger %d Name: %s",
                   j + 1, q->a[i].passenger_names[j]);
   }
        printf("\nPhone No: %ld", q->a[i].phone_no);
        printf("\nPrice: %.2f\n", q->a[i].price);
    }
}
int main(){
    struct queue q;
    int choice;
    q.front = q.rear = -1;
    do{
        printf("\n--- Train Ticket Reservation Management (QUEUE) ---\n");
        printf("1.Enqueue (Reserve Ticket)\n");
        printf("2.Dequeue (Cancel Ticket)\n");
        printf("3.Display Tickets\n");
        printf("0.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice){
        case 1: enqueue(&q); break;
        case 2: dequeue(&q); break;
        case 3: display(&q); break;
        case 0: printf("Exiting...\n"); break;
        default: printf("Invalid choice\n");
        }
    } while (choice != 0);

    return 0;
}
