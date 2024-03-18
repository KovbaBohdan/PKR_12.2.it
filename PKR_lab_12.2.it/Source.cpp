#include <iostream>

using namespace std;

typedef int Info;
struct Elem
{
    Elem* link;
    Info  info;
};

void Input(Elem*& first, Elem*& last, Info value)
{
    Elem* tmp = new Elem;
    tmp->info = value;
    tmp->link = NULL;
    if (last != NULL)
        last->link = tmp;
    last = tmp;
    if (first == NULL)
        first = tmp;
}

Info Delete(Elem*& first, Elem*& last)
{
    Elem* tmp = first->link;
    Info value = first->info;
    delete first;
    first = tmp;
    if (first == NULL)
        last = NULL;
    return value;
}

void PrintList(Elem* first)
{
    Elem* current = first;
    while (current != NULL)
    {
        cout << current->info << " ";
        current = current->link;
    }
    cout << endl;
}

void DeleteBefore(Elem*& first, Info value)
{
    Elem* a = NULL;
    Elem* b = first;

    while (b != NULL && b->info != value)
    {
        a = b;
        b = b->link;
    }

    while (first != b)
    {
       Elem* tmp = first;
       first = first->link;
       delete tmp;
    }
}

int main()
{
    Elem* first = NULL, *last = NULL;
    int n = 20;
    for (int i = 1; i < n + 1; i++) {
        Input(first, last, i);
    }
    
    PrintList(first);
    
    int value;
    cout << "Input value" << endl;
    cin >> value;
    cout << "Result:" << endl;
    DeleteBefore(first, value);
    
    for (int i = 0; i < n; i++)
    {
        cout << Delete(first, last) << " ";
    }

    return 0;
}



