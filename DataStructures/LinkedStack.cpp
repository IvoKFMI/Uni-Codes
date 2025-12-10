#include<iostream>

template<typename T>
class LStack
{
public:
    LStack();
    LStack(const LStack<T>&);
    LStack& operator=(const LStack<T>&);
    ~LStack();

    void push(const T& el);
    const T& peek() const;
    void pop();

    bool isEmpty() const;

private:
    struct Node
    {
        T data;
        Node* next;

        Node(const T& data)
        {
            this->data = data;
            next = nullptr;
        }
    };
    Node* head;

    void free();
    void copyFrom(const LStack<T>&)
};

template<typename T>
void LStack<T>::free()
{
    while(head)
    {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
    }
    head = nullptr;
}

template<typename T>
void LStack<T>::copyFrom(const LStack<T>& other)
{
    head = nullptr;
    if (other.isEmpty())
        return;

    Node* iterOther = other.head;

    head = new Node(iterOther->data);
    Node* iterThis = head;

    iterOther = iterOther->next;  

    while (iterOther) 
    {            
        iterThis->next = new Node(iterOther->data);
        iterThis = iterThis->next;
        iterOther = iterOther->next;
    }
}

template<typename T>
LStack<T>::LStack()
{
    head = nullptr;
}

template<typename T>
LStack<T>::LStack(const LStack<T>& other)
{
    copyFrom(other);
}

template<typename T>
LStack<T>& LStack<T>::operator=(const LStack<T>& other)
{
    if(this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

template<typename T>
LStack<T>::~LStack()
{
    free();
}

template<typename T>
bool LStack<T>::isEmpty() const
{
    head == nullptr;
}

template<typename T>
void LStack<T>::push(const T& el)
{
    if(isEmpty())
    {   
        head = new Node(el);
    }
    else
    {
        Node* toAdd = new Node(el);
        toAdd->next = head;
        head = toAdd;
    }
}

template<typename T>
const T& LStack<T>::peek() const
{
    return head->data;
}

template<typename T>
void LStack<T>::pop()
{
    if(isEmpty())
    {
        throw std::runtime_error("Empty stack!");
    }
    else if(head->next == nullptr)
    {
        delete head;
        head = nullptr
    }
    else
    {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
    }
}
int main()
{
    std::cout << "Hello world!";
}
