#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student{
    int roll;
    char name[30];
    char course[30];
    struct student *next;
};
struct student *head = NULL;
void insert_beg();
void insert_end();
void insert_pos();
void display();
void search();
void delete_beg();
void delete_end();
void delete_pos();
void delete_by_roll();
void update_course();
void insert_beg()
{
    struct student *temp;
    temp = (struct student *)malloc(sizeof(struct student));
    printf("Enter Roll No, Name, Course: ");
    scanf("%d %s %s", &temp->roll, temp->name, temp->course);
    temp->next = head;
    head = temp;
}
void insert_end()
{
    struct student *temp, *r;
    temp = (struct student *)malloc(sizeof(struct student));
    printf("Enter Roll No, Name, Course: ");
    scanf("%d %s %s", &temp->roll, temp->name, temp->course);
    temp->next = NULL;
    if (head == NULL)
        head = temp;
    else
    {
        r = head;
        while (r->next != NULL)
            r = r->next;
        r->next = temp;
    }
}
void insert_pos()
{
    int pos, i;
    struct student *temp, *r;
    printf("Enter position: ");
    scanf("%d", &pos);
    temp = (struct student *)malloc(sizeof(struct student));
    printf("Enter Roll No, Name, Course: ");
    scanf("%d %s %s", &temp->roll, temp->name, temp->course);
    if (pos == 1)
    {
        temp->next = head;
        head = temp;
        return;
    }
    r = head;
    for (i = 1; i < pos - 1 && r != NULL; i++)
        r = r->next;
    if (r == NULL)
    {
        printf("Invalid position\n");
        free(temp);
    }
    else
    {
        temp->next = r->next;
        r->next = temp;
    }
}
void display()
{
    struct student *temp = head;
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    printf("\nRoll\tName\tCourse\n");
    while (temp != NULL)
    {
        printf("%d\t%s\t%s\n", temp->roll, temp->name, temp->course);
        temp = temp->next;
    }
}
void search()
{
    int roll;
    struct student *temp = head;
    printf("Enter roll number to search: ");
    scanf("%d", &roll);
    while (temp != NULL)
    {
        if (temp->roll == roll)
        {
            printf("Student Found: %s - %s\n", temp->name, temp->course);
            return;
        }
        temp = temp->next;
    }
    printf("Student not found\n");
}
void delete_beg()
{
    struct student *temp;
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    temp = head;
    head = head->next;
    free(temp);
}
void delete_end()
{
    struct student *temp, *prev;
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    } 
    if (head->next == NULL)
    {
        free(head);
        head = NULL;
        return;
    }
    temp = head;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
}
void delete_pos()
{
    int pos, i;
    struct student *temp, *prev;
    printf("Enter position to delete: ");
    scanf("%d", &pos);
    if (pos == 1)
    {
        delete_beg();
        return;
    }
    temp = head;
    for (i = 1; i < pos && temp != NULL; i++)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        printf("Invalid position\n");
    else
    {
        prev->next = temp->next;
        free(temp);
    }
}
void delete_by_roll()
{
    int roll;
    struct student *temp, *prev;
    printf("Enter roll number to delete: ");
    scanf("%d", &roll);
    temp = head;
    if (temp != NULL && temp->roll == roll)
    {
        head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->roll != roll)
    {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        printf("Student not found\n");
    else
    {
        prev->next = temp->next;
        free(temp);
    }}
void update_course()
{
    int roll;
    struct student *temp = head;
    printf("Enter roll number to update course: ");
    scanf("%d", &roll);
    while (temp != NULL)
    {
        if (temp->roll == roll)
        {
            printf("Enter new course: ");
            scanf("%s", temp->course);
            printf("Course updated successfully\n");
            return;
        }
        temp = temp->next;
    }
    printf("Student not found\n");
}
int main()
{
    int choice;
    do{
        printf("\n--- Student Enrollment Management ---\n");
        printf("1.Insert Begin\n2.Insert End\n3.Insert Position\n");
        printf("4.Display\n5.Search\n");
        printf("6.Delete Begin\n7.Delete End\n8.Delete Position\n");
        printf("9.Delete by Roll\n10.Update Course\n0.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1: insert_beg(); break;
        case 2: insert_end(); break;
        case 3: insert_pos(); break;
        case 4: display(); break;
        case 5: search(); break;
        case 6: delete_beg(); break;
        case 7: delete_end(); break;
        case 8: delete_pos(); break;
        case 9: delete_by_roll(); break;
        case 10: update_course(); break;
        case 0: printf("Exiting...\n"); break;
        default: printf("Invalid choice\n");
        }
    } while (choice != 0);

    return 0;
}
