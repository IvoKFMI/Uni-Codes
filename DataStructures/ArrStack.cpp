#include<iostream>

template<typename T>
class ArrStack
{
public:
    ArrStack();
    ArrStack(const ArrStack<T>& other);
    ArrStack& operator=(const ArrStack<T>& other);
    ~ArrStack();

    size_t getSize() const;
    size_t getCap() const;

    bool isEmpty() const;

    void push(const T& el);
    void pop();
    const T& peek() const;

    class Iterator
    {
    public:
        friend class ArrStack;

        Iterator() : ptr(nullptr){}
        Iterator(T* ptr) : ptr(ptr){}

        T& operator*()
        {
            return *ptr;
        }

        Iterator& operator++()
        {
            ++ptr;
            return *this;
        }

        Iterator operator++(int)
        {
            Iterator tmp = *this;
            ++ptr;
            return tmp;
        }

        bool operator==(const Iterator& other) const
        {
            return ptr == other.ptr;
        }
        bool operator!=(const Iterator& other) const
        {
            return ptr != other.ptr;
        }
        
        
    private:
        T* ptr;
    };

    Iterator begin()
    {
        return Iterator(data);
    }

    Iterator end()
    {
        return Iterator(data + size);
    }

    const Iterator cBegin() const
    {
        return Iteartor(data);
    }

    const Iterator cEnd() const
    {
        return Iterator(data + size);
    }

private:
    T* data = nullptr;
    size_t size = 0;
    size_t capacity = 0;

    void copyFrom(const ArrStack<T>& other);
    void free();
    void resize();
    
};

template<typename T>
void ArrStack<T>::copyFrom(const ArrStack<T>& other)
{
    data = new T[other.capacity];
    for(size_t i = 0; i < other.size; i++)
    {
        data[i] = other.data[i];
    }
    size = other.size;
    capacity =  other.capacity;
    
}

template<typename T>
void ArrStack<T>::free()
{
    delete[] data;
}

template<typename T>
void ArrStack<T>::resize()
{
    T* newData = new T[capacity * 2];
    for(size_t i = 0; i < size; i++)
    {
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity *= 2;

}

template<typename T>
ArrStack<T>::ArrStack() : size(0), capacity(4) 
{
    data = new T[capacity];
}

template<typename T>
ArrStack<T>::ArrStack(const ArrStack<T>& other)
{
    copyFrom(other);
}

template<typename T>
ArrStack<T>& ArrStack<T>::operator=(const ArrStack<T>& other)
{
    if(this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

template<typename T>
ArrStack<T>::~ArrStack()
{
    free();
}

template<typename T>
size_t ArrStack<T>::getSize() const
{
    return size;
}

template<typename T>
size_t ArrStack<T>::getCap() const
{
    return capacity;
}

template<typename T>
bool ArrStack<T>::isEmpty() const
{
    return size == 0;
}

template<typename T>
void ArrStack<T>::push(const T& el)
{
    if(size == capacity)
        resize();

    data[size] = el;
    size++;

}

template<typename T>
void ArrStack<T>::pop()
{
    if(isEmpty())
        throw std::runtime_error("Stack is empty!");
    
        --size;
}

template<typename T>
const T& ArrStack<T>::peek() const
{
    if(isEmpty())
        throw std::runtime_error("Stack is empty!");

    return data[size - 1];
}
 
int main()
{

    ArrStack<int> p;
    p.push(1);
    p.push(2);
    p.push(3);
    p.push(4);
    p.push(5);

    for(auto it = p.begin(); it != p.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    p.pop();
    for(auto it = p.begin(); it != p.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    std::cout << p.peek();
    

}
