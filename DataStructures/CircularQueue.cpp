#include<iostream>

template<typename T>
class Queue
{
public:
    Queue();
    Queue(const Queue<T>&);
    Queue& operator=(const Queue<T>&);
    ~Queue();

    bool isEmpty() const;
    void enqueue(const T& el);
    void dequeue();
    const T& peek() const;

private:
    T* arr;
    size_t size;
    size_t capacity;

    size_t getIter;
    size_t putIter;

    void copyFrom(const Queue<T>&);
    void free();
    void resize();
};

template<typename T>
bool Queue<T>::isEmpty() const
{
    return size == 0;
}

template<typename T>
void Queue<T>::enqueue(const T& el)
{
    if(size == capacity)
        resize();
    
    data[putIter] = el;
    (++putIter) %= capacity;
    size++;
}


template<typename T>
void Queue<T>::dequeue()
{
    if(isEmpty())
        throw std::runtime_error("Empty queue!");

    size--;
    (++getIter) %= capacity;
}

template<typename T>
const T& Queue<T>::peek() const
{
    if(isEmpty())
        throw std::runtime_error("Empty queue!");

    return arr[getIter];
}

template<typename T>
Queue<T>::Queue()
{
    capacity = 4;
    arr = new T[capacity];
    size = 0;
    getIter = 0;
    putIter = 0;
}

template<typename T>
Queue<T>::Queue(const Queue<T>& other)
{
    copyFrom(other);
}

template<typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other)
{
    if(this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

template<typename T>
Queue<T>::~Queue()
{
    free();
}

template<typename T>
void Queue<T>::copyFrom(const Queue<T>& other)
{
    arr = new T[other.capacity];
    for(int i = other.getIter; i != other.putIter; (i+=1)%=other.capacity)
    {
        arr[i] = other.arr[i];
    }

    size = other.size;
    capacity = other.capacity;

    getIter = other.getIter;
    putIter = other.putIter;
}

template<typename T>
void Queue<T>::free()
{
    delete[] arr;
    size = capacity = 0;
}

template<typename T>
void Queue<T>::resize()
{
    size_t newCap = capacity * 2;
    size_t currentCap = capacity;

    T* temp = new T[newCap];

    for(int i = 0; i < currentCap; i++)
    {
        temp[i] = peek();
        dequeue();
    }

    getIter = 0;
    putIter = capacity;

    size = capacity;
    capacity *= 2;

    delete[] arr;
    arr = temp;
}

int main()
{
    std::cout << "Hello world!";
}
