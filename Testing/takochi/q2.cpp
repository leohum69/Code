#include <iostream>
#include <cstring>
using namespace std;

class node
{
public:
    string name;
    string aurthor;
    int year;
    string lang;
    int edition;

    node *next;
    node(string n, string a, int y, string lan, int edi)
    {
        name = n;
        aurthor = a;
        year = y;
        lang = lan;
        edition = edi;
        next = NULL;
    }
    node(const node &b1)
    {
        name = b1.name;
        aurthor = b1.aurthor;
        year = b1.year;
        lang = b1.lang;
        edition = b1.edition;
        next = b1.next;
    }
    void print()
    {
        cout << "Title : " << name << endl;
        cout << "Aurthor : " << aurthor << endl;
        cout << "Publictaion Year : " << year << endl;
        cout << "Edition : " << edition << endl;
        cout << "Language : " << lang << endl;
    }
};
class linklist
{
public:
    node *head;
    node *tail;

    linklist()
    {
        head = NULL;
        tail = NULL;
    }
    void insert(node book)
    {
        if (head == NULL)
        {
            head = new node(book);
            tail = head;
            return;
        }
        tail->next = new node(book);
        tail = tail->next;
    }
    void remove(int edi)
    {
        if (head == NULL)
        {
            return;
        }
        node *temp = head;
        if (head->edition == edi)
        {
            head = head->next;
            delete temp;
            return;
        }
        node *prev = NULL;
        bool chk = false;
        while (temp->next)
        {
            prev = temp;
            temp = temp->next;
            if (temp->edition == edi)
            {
                chk = true;
                break;
            }
        }
        if (!chk)
        {
            cout << "No edition found" << endl;
            return;
        }
        temp = temp->next;
        delete prev->next;
        prev->next = temp;
    }
    void print()
    {
        node *temp = head;
        while (temp)
        {
            temp->print();
            temp = temp->next;
        }
        cout << endl;
    }
};

class nodedouble
{
public:
    linklist l1;
    string name;
    nodedouble *next;

    nodedouble(const linklist &l2)
    {
        node *temp = l2.head;
        name = l2.head->name;
        while (temp)
        {
            l1.insert(*temp);
            temp = temp->next;
        }
        next = NULL;
    }
};

class doublel
{
public:
    nodedouble *head;
    nodedouble *tail;
    doublel()
    {
        head = NULL;
        tail = NULL;
    }
    void insert(nodedouble book)
    {
        if (head == NULL)
        {
            head = new nodedouble(book);
            tail = head;
            return;
        }
        tail->next = new nodedouble(book);
        tail = tail->next;
    }

    void print()
    {
        nodedouble *temp = head;
        while (temp->next != NULL)
        {
            temp->l1.print();
            temp = temp->next;
            cout << endl
                 << endl;
        }
    }
};

int main()
{
    cout << "Welcome to Fast Library System" << endl;
    cout << "What you want to do." << endl;
    cout << "1 - Insert a new Book with its first Edition." << endl;
    cout << "2 - Insert a new edition of an exsisting book." << endl;
    cout << "3 - Delete a sepecifc Edition of a book." << endl;
    cout << "4 - Print All books Along their Editions." << endl;
    cout << "5 - Search" << endl;

    int n;
    cin >> n;
    while (n < 0 || n > 5)
    {
        cout << "Invalid Input" << endl;
        cin >> n;
    }
    string name;
    string aurthor;
    int year;
    string lang;
    int edition;
    if (n == 1)
    {
        cout << "Enter the name of the book" << endl;
        cin >> name;
        cout << "Enter the name of the aurthor" << endl;
        cin >> aurthor;
        cout << "Enter the year of publication" << endl;

        cin >> year;
        cout << "Enter the language of the book" << endl;

        cin >> lang;
        cout << "Enter the edition of the book" << endl;

        cin >> edition;
        node book(name, aurthor, year, lang, edition);
        linklist l1;
        l1.insert(book);
        nodedouble book1(l1);
        doublel l2;
        l2.insert(book1);
        cout<<"Book successfully added"<<endl;
        l2.print();
    }
    else if (n == 2)
    {
    }

    return 0;
}