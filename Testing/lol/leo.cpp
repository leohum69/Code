#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <pthread.h>
#include <ctime>
#include <fstream>
using namespace std;

#define SHM_SIZE 1024

struct Node
{
    int data;
    Node *next;

    Node(int data) : data(data), next(nullptr) {}
};

// Define the Stack class
class Stack
{
private:
    Node *top; // Pointer to the top of the stack

public:
    // Constructor to initialize the stack
    Stack() : top(nullptr) {}

    // Destructor to free memory
    ~Stack()
    {
        while (!isEmpty())
        {
            pop();
        }
    }

    // Function to check if the stack is empty
    bool isEmpty()
    {
        return top == nullptr;
    }

    // Function to push an element onto the stack
    void push(int data)
    {
        Node *newNode = new Node(data);
        newNode->next = top;
        top = newNode;
    }

    // Function to pop an element from the stack
    int pop()
    {
        if (isEmpty())
        {
            std::cerr << "Stack underflow\n";
            exit(EXIT_FAILURE);
        }
        int poppedData = top->data;
        Node *temp = top;
        top = top->next;
        delete temp;
        return poppedData;
    }

    // Function to peek the top element of the stack
    int peek()
    {
        if (isEmpty())
        {
            std::cerr << "Stack is empty\n";
            exit(EXIT_FAILURE);
        }
        return top->data;
    }

    // Function to display the stack elements
    void display()
    {
        if (isEmpty())
        {
            std::cout << "Stack is empty\n";
            return;
        }
        Node *current = top;
        while (current)
        {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << "\n";
    }
};

int main()
{

    pid_t p1;
    p1 = fork();
    if (p1 == 0)
    {
        ifstream fin;
        Stack lol;
        int x;
        fin.open("file1.txt");
        while (!fin.eof())
        {
            fin >> x;
            lol.push(x);
        }
        lol.display();

        int shmid;
        key_t key = 1234;
        Stack *shmptr;
        if ((shmid = shmget(key, SHM_SIZE, IPC_CREAT | S_IRUSR | S_IWUSR)) == -1)
        {

            perror("shmget");

            exit(EXIT_FAILURE);
        }
        shmptr = (Stack *)shmat(shmid, NULL, 0);
        
        // shmctl(shmid, IPC_RMID, NULL);
        shmdt(shmptr);
    }
    else
    {
        wait(NULL);
        int shmid;

        key_t key = 1234; // Unique key for shared memory segment

        Stack *shm_ptr;

        // Create a shared memory segment or obtain the identifier if it already exists

        if ((shmid = shmget(key, SHM_SIZE, IPC_CREAT | S_IRUSR | S_IWUSR)) == -1)
        {

            perror("shmget");

            exit(EXIT_FAILURE);
        }
        // Attach the shared memory segment to the sender's address space

        shm_ptr = (Stack *)shmat(shmid, NULL, 0);

        shm_ptr->display();
    }

    return 0;
}