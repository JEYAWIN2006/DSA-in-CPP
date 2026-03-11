#include <stdio.h>
#define MAX 10
#define MAXP 5   
struct ticket
{
    int train_no;
    char train_name[30];
    int no_of_passengers;
    char passenger_names[MAXP][30];   
    long int phone_no;
    float price;
};
struct stack
{
    struct ticket a[MAX];
    int top;
};
void push(struct stack *s);
void pop(struct stack *s);
void display(struct stack *s);
void push(struct stack *s)
{
    int i;
    if (s->top == MAX - 1){
        printf("Stack is full\n");
        return;
    }
    s->top++;
    printf("Enter Train No: ");
    scanf("%d", &s->a[s->top].train_no);
    printf("Enter Train Name: ");
    scanf("%s", s->a[s->top].train_name);
    printf("Enter No of Passengers: ");
    scanf("%d", &s->a[s->top].no_of_passengers);
    for (i = 0; i < s->a[s->top].no_of_passengers; i++)
    {
        printf("Enter Passenger %d Name: ", i + 1);
        scanf("%s", s->a[s->top].passenger_names[i]);
    }
    printf("Enter Phone No: ");
    scanf("%ld", &s->a[s->top].phone_no);
    printf("Enter Ticket Price: ");
    scanf("%f", &s->a[s->top].price);
}
void pop(struct stack *s)
{
    if (s->top == -1)
    {
        printf("Stack is empty\n");
        return;
    }
    printf("\nTicket Cancelled:\n");
    printf("Train No: %d\n", s->a[s->top].train_no);
    s->top--;
}
void display(struct stack *s)
{
    int i, j;

    if (s->top == -1)
    {
        printf("No reservations available\n");
        return;
    }

    printf("\nTrain Ticket Reservations:\n");
    for (i = s->top; i >= 0; i--){
        printf("\nTrain No: %d", s->a[i].train_no);
        printf("\nTrain Name: %s", s->a[i].train_name);
        printf("\nNo of Passengers: %d", s->a[i].no_of_passengers);
        for (j = 0; j < s->a[i].no_of_passengers; j++){
            printf("\nPassenger %d Name: %s", j + 1,
                   s->a[i].passenger_names[j]);
        }
        printf("\nPhone No: %ld", s->a[i].phone_no);
        printf("\nPrice: %.2f\n", s->a[i].price);
    }
}
int main()
{
    struct stack s;
    int choice;
    s.top = -1;
    do{
        printf("\n--- Train Ticket Reservation Management ---\n");
        printf("1.Push (Reserve Ticket)\n");
        printf("2.Pop (Cancel Ticket)\n");
        printf("3.Display Tickets\n");
        printf("0.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice){
        case 1: push(&s); break;
        case 2: pop(&s); break;
        case 3: display(&s); break;
        case 0: printf("Exiting...\n"); break;
        default: printf("Invalid choice\n");
        }
    } while (choice != 0);
     return 0;
}
