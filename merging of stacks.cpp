#include <iostream>
#define max 10
#define strmax 50 // Assuming maximum length of string is 50 characters
using namespace std;

class Stack {
    char a[max][strmax]; // stack array to store strings
    int top;
public:
    Stack() {
        top = -1;
    }
    void push(const char* x);
    char* pop();
    void display();
    bool isEmpty();
};

void Stack::push(const char* x) {
    if(top == max - 1) {
        cout << "Stack is full" << endl;
    } else {
        top++;
        int i = 0;
        while(x[i] != '\0') {
            a[top][i] = x[i];
            i++;
        }
        a[top][i] = '\0'; // Null-terminate the string
    }
}

char* Stack::pop() {
    if(top == -1) {
        cout << "Stack is empty" << endl;
        return nullptr;
    } else {
        return a[top--];
    }
}

void Stack::display() {
    if(top == -1) {
        cout << "Stack is empty" << endl;
        return;
    }
    for(int i = top; i >= 0; i--) {
        cout << a[i] << " ";
    }
    cout << endl;
}

bool Stack::isEmpty() {
    return top == -1;
}

void reverseString(Stack &s, Stack &reversedStack) {
    while(!s.isEmpty()) {
        reversedStack.push(s.pop());
    }
}

void mergeStacks(Stack &s1, Stack &s2, Stack &mergedStack) {
    while(!s1.isEmpty()) {
        mergedStack.push(s1.pop());
    }
    while(!s2.isEmpty()) {
        mergedStack.push(s2.pop());
    }
}

int main() {
    Stack s1, s2, mergedStack;
    
    // Pushing strings onto the first stack
    s1.push("Hello");
    s1.push("World");
    cout << "Original Stack (s1):" << endl;
    s1.display();
    
    // Reversing the string by pushing into another stack
    reverseString(s1, s2);
    cout << "Reversed Stack (s2):" << endl;
    s2.display();
    
    // Merging the original and reversed stacks into a third stack
    mergeStacks(s1, s2, mergedStack);
    cout << "Merged Stack:" << endl;
    mergedStack.display();
    
    return 0;
}
