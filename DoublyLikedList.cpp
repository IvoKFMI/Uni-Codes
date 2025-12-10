#include<iostream>

template<typename T>
class DLL
{
private:
    struct Node
    {
        T data;
        Node* next;
        Node* prev;
        Node(const T& data)
        {
            this->data = data;
            next = nullptr;
            prev = nullptr;
        }
    };
    Node* head;
    Node* tail;

    void copyFrom(const DLL<T>& other);
    void free();

public:
    DLL();
    DLL(const DLL<T>& other);
    DLL& operator=(const DLL<T>& other);
    ~DLL();

    void pushFront(const T& el);
    void pushBack(const T& el);

    void popFront();
    void popBack();

    const T& front() const;
    const T& back() const;

    T& front();
    T& back();

    size_t getSize() const;
    bool isEmpty() const;

    size_t size = 0;

    class Iterator
    {
    public:
        friend class DLL;
        Iterator() : ptr(nullptr){}
        Iterator(Node* _ptr) : ptr(_ptr){}
        T& operator*() const
        {
            return ptr->data;
        }
        Iterator& operator++()
        {
            ptr = ptr->next;
            return *this;
        }
        Iterator& operator--()
        {
            ptr = ptr->prev;
            return *this;
        }
        bool operator!=(const Iterator& other)
        {
            return ptr != other.ptr;
        }
        bool operator==(const Iterator& other)
        {
            return ptr == other.ptr;
        }
        
    private:
        Node* ptr;
    };

    Iterator begin()
    {
        return Iterator(head);
    }

    Iterator end()
    {
        return Iterator(nullptr);
    }

    Iterator begin() const
    {
        return Iterator(head);
    }

    Iterator end() const
    {
        return Iterator(nullptr);
    }

};

//1->2->3
template<typename T>
void DLL<T>::pushFront(const T& el)
{   
    Node* toAdd = new Node(el);
    if(isEmpty())
    {
        head = tail = toAdd;
    }
    else
    {
        toAdd->next = head;
        head->prev = toAdd;
        head = toAdd;
    }
    ++size;
}

template<typename T>
void DLL<T>::pushBack(const T& el)
{
    Node* toAdd = new Node(el);
    if(isEmpty())
    {
        head = tail = toAdd;
    }
    else
    {
        tail->next = toAdd;
        toAdd->prev = tail;
        tail = toAdd;
    }
    ++size;
}

template<typename T>
void DLL<T>::popFront()
{
    if(isEmpty())
        throw std::runtime_error("Empty list!");
    
    if(head == tail)
    {
        delete head;
        head = tail = nullptr;
    }
    else
    {
        Node* toDelete = head;
        head = head->next;
        head->prev = nullptr;
        delete toDelete;
    }
    --size;
}

template<typename T>
void DLL<T>::popBack()
{
    if(isEmpty())
        throw std::runtime_error("Empty list!");
    
    if(head == tail)
    {
        delete head;
        head = tail = nullptr;
    }
    else
    {
        Node* toDelete = tail;
        tail = tail->prev;
        tail->next = nullptr;
        delete toDelete;
    }
    --size;
}

template<typename T>
const T& DLL<T>::front() const
{
    if(isEmpty())
        throw std::runtime_error("Empty list!");
    
    return head->data;
}

template<typename T>
const T& DLL<T>::back() const
{
    if(isEmpty())
        throw std::runtime_error("Empty list!");
    
    return tail->data;
}

template<typename T>
T& DLL<T>::front()
{
    if(isEmpty())
        throw std::runtime_error("Empty list!");
    
    return head->data;
}

template<typename T>
T& DLL<T>::back() 
{
    if(isEmpty())
        throw std::runtime_error("Empty list!");
    
    return tail->data;
}

template<typename T>
size_t DLL<T>::getSize() const
{
    return size;
}

template<typename T>
bool DLL<T>::isEmpty() const
{
    return size == 0;
}

template<typename T>
DLL<T>::DLL() : head(nullptr), tail(nullptr){}

template<typename T>
DLL<T>::DLL(const DLL<T>& other)
{
    copyFrom(other);
}

template<typename T>
DLL<T>& DLL<T>::operator=(const DLL<T>& other)
{
    if(this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

template<typename T>
DLL<T>::~DLL()
{
    free();
}

template<typename T>
void DLL<T>::copyFrom(const DLL<T>& other)
{
    Node* iterOther = other.head()
    while(iterOther != nullptr)
    {
        pushBack(iterOther->data);
        iterOther = iterOther->next;
    }
}

template<typename T>
void DLL<T>::free()
{
    while(head != nullptr)
    {
        Node* toDel = head;
        head = head->next;
        delete toDel;
    }
    size = 0;
}
int main()
{
    std::cout << "Hello world!";
}