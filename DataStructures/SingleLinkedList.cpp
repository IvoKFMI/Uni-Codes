#include<iostream>

template<typename T>
class SLL
{
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

    Node* head = nullptr;
    Node* tail = nullptr;
    size_t size = 0;

    void copyFrom(const SLL<T>& other);
    void free();

public:
    SLL();
    SLL(const SLL<T>& other);
    SLL& operator=(const SLL<T>& other);
    ~SLL();

    void pushFront(const T& el);
    void pushBack(const T& el);

    void popFront();

    const T& front() const;
    const T& back() const;

    T& front();
    T& back();

    size_t getSize() const;
    bool isEmpty() const;

    void print() const;

    class Iterator
    {
    public:
        Iterator() : ptr(nullptr){}
        Iterator(Node* ptr)
        {
            this->ptr = ptr;
        }

        T& operator*() const
        {
            return ptr->data;
        }

        Iterator& operator++()
        {
            ptr = ptr->next;
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
        return Iterator(tail->next);
    }
     
};

// 1->2->3->4    (8)
template<typename T>
void SLL<T>::pushFront(const T& el)
{
    Node* toAdd = new Node(el);
    if(isEmpty())
    {
        head = tail = toAdd;
    }
    else
    {
        toAdd->next = head;
        head = toAdd;
    }
    ++size;

}

template<typename T>
void SLL<T>::pushBack(const T& el)
{
    Node* toAdd = new Node(el);
    if(isEmpty())
    {
        head = tail = toAdd;
    }
    else
    {
        tail->next = toAdd;
        tail = toAdd;
    }
    ++size;
}

template<typename T>
void SLL<T>::popFront()
{
    if(isEmpty())
        throw std::runtime_error("Empty list!");
    
    if(head == tail)
    {
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
    }
    --size;
}

template<typename T>
const T& SLL<T>::front() const
{
    if(isEmpty())
         throw std::runtime_error("Empty list!");
    
    return head->data;
}

template<typename T>
T& SLL<T>::front() 
{
    if(isEmpty())
         throw std::runtime_error("Empty list!");
    
    return head->data;
}

template<typename T>
const T& SLL<T>::back() const
{
    if(isEmpty())
         throw std::runtime_error("Empty list!");
    
    return tail->data;
}

template<typename T>
T& SLL<T>::back() 
{
    if(isEmpty())
         throw std::runtime_error("Empty list!");
    
    return tail->data;
}

template<typename T>
size_t SLL<T>::getSize() const
{
    return size;
}

template<typename T>
bool SLL<T>::isEmpty() const
{
    return size == 0;
}

template<typename T>
void SLL<T>::print() const
{
    Node* iter = head;
    while(iter != nullptr)
    {
        std::cout << iter->data << " ";
        iter = iter->next;
    }
    std::cout << std::endl;
}


// head -> 1 -> 2 -> 3 -> nullptr
template<typename T>
void SLL<T>::copyFrom(const SLL<T>& other)
{
    Node* iterOther = other.head;
    while(iterOther != nullptr)
    {
        pushBack(iterOther->data);
        iterOther = iterOther->next;
    }
    size = other.size;
}

template<typename T>
void SLL<T>::free()
{
    while(head != nullptr)
    {
        Node* toDelete = head;
        head = head->next;
        delete toDelete;
    }
    size = 0;
}

template<typename T>
SLL<T>::SLL()
{
    this->head = nullptr;
    this->tail = nullptr;
    size = 0;
}

template<typename T>
SLL<T>::SLL(const SLL<T>& other)
{
    copyFrom(other);
}

template<typename T>
SLL<T>& SLL<T>::operator=(const SLL<T>& other)
{
    if(this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

template<typename T>
SLL<T>::~SLL()
{
    free();
}




int main()
{
    SLL<int> p;
    p.pushBack(1);
    p.pushBack(2);
    p.pushBack(3);
    p.pushBack(4);
    p.pushBack(5);
    p.pushFront(3);
    p.pushFront(4);
    p.popFront();

    p.print();
    std::cout << p.front() << ", " << p.back() << std::endl;


    for(auto it = p.begin(); it != p.end(); ++it)
    {
        std::cout << *it << " ";
    }
}
