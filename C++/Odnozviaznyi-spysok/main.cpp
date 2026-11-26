#include <iostream>
using namespace std;

class List
{
private:
    struct Node
    {
        int data;
        Node* next;
    };

    Node* head;

public:
    List()
    {
        head = nullptr;
    }

    ~List()
    {
        while (head != nullptr)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void insert(int pos, int value)
    {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (pos == 0)
        {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* current = head;

        for (int i = 0; i < pos - 1 && current != nullptr; i++)
            current = current->next;

        if (current == nullptr)
        {
            delete newNode;
            cout << "Nekorektna pozytsiia!" << endl;
            return;
        }

        newNode->next = current->next;
        current->next = newNode;
    }

    void remove(int pos)
    {
        if (head == nullptr || pos < 0)
        {
            cout << "Nekorektna pozytsiia!" << endl;
            return;
        }

        if (pos == 0)
        {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;

        for (int i = 0; i < pos - 1 && current != nullptr; i++)
            current = current->next;

        if (current == nullptr || current->next == nullptr)
        {
            cout << "Nekorektna pozytsiia!" << endl;
            return;
        }

        Node* temp = current->next;
        current->next = temp->next;
        delete temp;
    }

    int& operator[](int pos)
    {
        if (pos < 0)
            throw out_of_range("Nekorektna pozytsiia");

        Node* current = head;

        for (int i = 0; i < pos && current != nullptr; i++)
            current = current->next;

        if (current == nullptr)
            throw out_of_range("Nekorektna pozytsiia");

        return current->data;
    }

    friend ostream& operator<<(ostream& out, const List& list)
    {
        Node* current = list.head;

        while (current != nullptr)
        {
            out << current->data << " ";
            current = current->next;
        }

        return out;
    }
};

int main()
{
    List list;

    list.insert(0, 10);
    list.insert(1, 20);
    list.insert(2, 30);
    list.insert(1, 15);

    cout << "Spysok: " << list << endl;

    cout << "Element z indeksom 2: " << list[2] << endl;

    list.remove(1);

    cout << "Pislia vydalennia: " << list << endl;

    list[0] = 100;

    cout << "Pislia zminy elementa: " << list << endl;

    return 0;
}
