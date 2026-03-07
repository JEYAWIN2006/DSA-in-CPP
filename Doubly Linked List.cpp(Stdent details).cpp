#include<iostream>
using namespace std;
class listadt
{
    struct Student
    {
        int rollNo;
        int marks;
        Student *next;
        Student *Prev;
    }*head;

public:
    listadt()
    {
        head = NULL;
    }
    
    void insert_end(int rollNo, int marks);
    void insert_beg(int rollNo, int marks);
    void insert_pos(int rollNo, int marks, int pos);
    void delete_student(int rollNo);
    void display();        
};

void listadt::insert_end(int rollNo, int marks)
{
    Student *temp, *r;
    if (head == NULL)
    {
        temp = new Student;
        temp->rollNo = rollNo;
        temp->marks = marks;
        temp->next = NULL;
        temp->Prev = NULL;
        head = temp;
    }
    else
    {
        temp = head;
        while (temp->next != NULL)
        temp = temp->next;
        r = new Student;
        r->rollNo = rollNo;
        r->marks = marks;
        r->next = NULL;
        r->Prev = temp;
        temp->next = r;
    }
}

void listadt::insert_beg(int rollNo, int marks)
{
    Student *temp;
    temp = new Student;
    temp->rollNo = rollNo;
    temp->marks = marks;
    temp->next = head;
    temp->Prev = NULL;
    if (head != NULL) 
    {
        head->Prev = temp;
    }
    head = temp;
}

void listadt::insert_pos(int rollNo, int marks, int pos)
{
    Student *temp, *r;
    temp = head;
    for (int i = 1; i < (pos - 1); i++)
    {
        if (temp == NULL) 
        {
            return;
        }
        temp = temp->next;
    }
    r = new Student;
    r->rollNo = rollNo;
    r->marks = marks;
    r->next = temp->next;
    if (temp->next != NULL)
    {
        temp->next->Prev = r;
    }
    temp->next = r;
    r->Prev = temp;
}

void listadt::delete_student(int rollNo)
{
    Student *temp = head;
    if (head != NULL && head->rollNo == rollNo)
    {
        Student *temp = head;
        head = head->next;
        if (head != NULL)
        {
            head->Prev = NULL;
        }
        delete temp;
        return;
    }

    while (temp != NULL)
    {
        if (temp->rollNo == rollNo)
        {
            if (temp->Prev != NULL)
            {
                temp->Prev->next = temp->next;
            }
            if (temp->next != NULL)
            {
                temp->next->Prev = temp->Prev;
            }
            delete temp;
            return;
        }
        temp = temp->next;
    }
}

void listadt::display()
{
    Student *temp;
    temp = head;
    while (temp != NULL)
    {
        cout << "Roll No: "<< temp->rollNo <<",Marks:"<<temp->marks<<endl;
        temp = temp->next;
    }
}

int main()
{
    listadt ob;
    ob.insert_end(1, 85);
    ob.insert_end(2, 90);
    ob.insert_end(3, 78);
    ob.insert_beg(4, 88);
    ob.insert_beg(5, 95);
    ob.insert_pos(6, 82, 3);
    ob.delete_student(2);
    ob.display();
    return 0;
}

