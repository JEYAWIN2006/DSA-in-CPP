#include<iostream>
using namespace std;
#include<stdlib.h>
#define max 100
#define initial 0
#define visited 1

class Graph 
{
    int adj[max][max];
    int state[max];
    int n;
    int stack[max];
    int top;
    int front;
    int rear;
    int queue[max];

public:
    Graph() 
	{
        top = -1;
        front = -1;
        rear = -1;
    }
    void create_graph();
    void DFSTraversal();
    void BFSTraversal();
    void DFS(int v);
    void BFS(int v);
    void push(int v);
    int pop();
    void enqueue(int x);
    int dequeue();
    int isEmpty_stack();
    int isEmpty_queue();
};

void Graph::create_graph() 
{
    int i, max_edges, origin, destin;
    cout << "Enter the number of vertices: ";
    cin >> n;
    max_edges = n * (n - 1);
    for (i = 1; i <= max_edges; i++)
	 {
        cout << "Enter edge (-1 -1 to quit): ";
        cin >> origin >> destin;
        if ((origin == -1) && (destin == -1))
            break;
        if (origin > n || destin > n || origin < 1 || destin < 1) 
		{
            cout << "Invalid edge" << endl;
            i--;
        } 
		else 
		{
            adj[origin][destin] = 1;
        }
    }
}

void Graph::DFSTraversal()
 {
    int v;
    for (v = 1; v <= n; v++)
        state[v] = initial;
    cout << "Enter starting node for depth first search: ";
    cin >> v;
    DFS(v);
    cout << "\n";
}

void Graph::BFSTraversal() 
{
    int v;
    for (v = 1; v <= n; v++)
        state[v] = initial;
    cout << "Enter starting node for breadth first search: ";
    cin >> v;
    BFS(v);
    cout << "\n";
}

void Graph::DFS(int v)
 {
    int i;
    push(v);
    while (!isEmpty_stack()) 
	{
        v = pop();
        if (state[v] != visited)
		{
            cout << v << " ";
            state[v] = visited;
            for (i = n ; i >= 1; i--) 
			{
                if (adj[v][i] == 1 && state[i] == initial)
                    push(i);
            }
        }
    }
}

void Graph::BFS(int v) 
{
    int i;
    cout << v << " ";
    enqueue(v);
    state[v] = visited;
    while (!isEmpty_queue()) 
	{
        v = dequeue();
        for (i=1; i<=n; i++) 
		{
            if (adj[v][i] == 1 && state[i] == initial)
			{
                enqueue(i);
                cout << i << " ";
                state[i] = visited;
            }
        }
    }
}

void Graph::push(int v)
 {
    if (top == max - 1) 
	{
        cout << "Stack is full" << endl;
    }
	else 
	{
        top++;
        stack[top] = v;
    }
}

int Graph::pop()
{
    if (top == -1) 
	{
        cout << "Stack is empty" << endl;
        return -1;
    }
	 else 
	 {
        int v = stack[top];
        top--;
        return v;
    }
}

void Graph::enqueue(int x)
 {
    if (rear == max - 1) 
	{
        cout << "Queue is full" << endl;
    } 
	else 
	{
        if (front == -1) 
			front = 0;
        rear++;
        queue[rear] = x;
    }
}

int Graph::dequeue()
 {
    if (front == -1 || front > rear) 
	{
        cout << "Queue is empty" << endl;
        return -1;
    }
	 else
	{
        int v = queue[front];
        front++;
        return v;
    }
}

int Graph::isEmpty_stack() 
{
    return (top == -1);
}

int Graph::isEmpty_queue()
{
    return (front == -1 || front > rear);
}

int main()
{
    Graph g;
    g.create_graph();
    g.DFSTraversal();
    g.BFSTraversal();
    return 0;
}

