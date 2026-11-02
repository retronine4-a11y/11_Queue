#include <iostream>
#include <conio.h>
using namespace std;

template <typename T>
class Queue
{
private:
    struct Node
    {
        T data;
        int priority;
        Node* next;

        Node(T value, int p)
        {
            data = value;
            priority = p;
            next = nullptr;
        }
    };

    Node* head;

public:
    Queue()
    {
        head = nullptr;
    }

    ~Queue()
    {
        while (head != nullptr)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void Add(T value, int priority)
    {
        Node* newNode = new Node(value, priority);

        if (head == nullptr || priority > head->priority)
        {
            newNode->next = head;
            head = newNode;
        }
        else
        {
            Node* current = head;

            while (current->next != nullptr &&
                current->next->priority >= priority)
            {
                current = current->next;
            }

            newNode->next = current->next;
            current->next = newNode;
        }

        cout << "Document added to queue!" << endl;
    }

    void Print()
    {
        if (head == nullptr)
        {
            cout << "Queue is empty!" << endl;
            return;
        }

        cout << endl;
        cout << "Printing document: " << head->data << endl;
        cout << "Priority: " << head->priority << endl;

        Node* temp = head;
        head = head->next;
        delete temp;

        cout << "Printing completed!" << endl;
    }

    void Show()
    {
        if (head == nullptr)
        {
            cout << "Queue is empty!" << endl;
            return;
        }

        Node* current = head;

        cout << endl << "Documents in queue:" << endl;

        while (current != nullptr)
        {
            cout << "File: " << current->data;
            cout << " | Priority: " << current->priority << endl;

            current = current->next;
        }
    }

    bool IsEmpty()
    {
        return head == nullptr;
    }
};

int main()
{
    Queue<string> printer;
    int choice;

    do
    {
        system("cls");
        cout << endl;
        cout << "===== PRINTER MENU =====" << endl;
        cout << "1. Add document" << endl;
        cout << "2. Print document" << endl;
        cout << "3. Show queue" << endl;
        cout << "0. Exit" << endl;
        cout << "Your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            system("cls");
            string filename;
            int position;
            int priority;

            cout << "Enter file name: ";
            cin >> filename;

            cout << endl;
            cout << "Choose your position:" << endl;
            cout << "1. Guest" << endl;
            cout << "2. Administrator" << endl;
            cout << "3. Manager" << endl;
            cout << "4. Director" << endl;
            cout << "Your choice: ";
            cin >> position;

            switch (position)
            {
            case 1:
                priority = 1;
                break;
            case 2:
                priority = 2;
                break;
            case 3:
                priority = 3;
                break;
            case 4:
                priority = 4;
                break;
            default:
                cout << "Invalid position!" << endl;
                break;
            }

            if (position >= 1 && position <= 4)
            {
                printer.Add(filename, priority);
            }

            break;
        }

        case 2:
            system("cls");
            printer.Print();
            _getch();
            break;

        case 3:
            system("cls");
            printer.Show();
            _getch();
            break;

        case 0:
            cout << "Program finished!" << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 0);
}
