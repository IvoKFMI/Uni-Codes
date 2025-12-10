#include<iostream>
#include<stdexcept>

template<typename T>
class myVec
{
public:
    myVec();
    myVec(const myVec&);
    myVec& operator=(const myVec&);
    ~myVec();

    size_t getSize() const;
    size_t getCap() const;
    bool isEmpty() const;

    T& operator[](int idx);
    const T& operator[](int idx) const;

    void pushBack(const T& value);
    void popBack();

    T& back();
    const T& back() const;
    T& front();
    const T& front() const;

    class Iterator
    {
    public:
    friend class myVec;
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

    const Iterator cbegin() const
    {
        return Iterator(data);
    }

    Iterator end()
    {
        return Iterator(data + size);
    }

    const Iterator cend() const
    {
        return Iterator(data + size);
    }


private:
    T* data = nullptr;
    size_t size = 0;
    size_t capacity = 0;
    void copyFrom(const myVec&);
    void free();
    void resize();

};

template<typename T>
void myVec<T>::copyFrom(const myVec<T>& other)
{
    data = new T[other.capacity];
    for(size_t i = 0; i < other.size; i++)
    {
        data[i] = other.data[i];
    }
    capacity = other.capacity;
    size = other.size;
}

template<typename T>
void myVec<T>::free()
{
    delete[] data;
    data = nullptr;
    size = 0;
    capacity = 0;
}

template<typename T>
void myVec<T>::resize()
{
    if(capacity == 0)
        capacity = 1;

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
myVec<T>::myVec()
{
    capacity = 4;
    size = 0;
    data = new T[capacity];
}

template<typename T>
myVec<T>::myVec(const myVec<T>& other)
{
    copyFrom(other);
}

template<typename T>
myVec<T>& myVec<T>::operator=(const myVec<T>& other)
{
    if(this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

template<typename T>
myVec<T>::~myVec()
{
    free();
}

template<typename T>
size_t myVec<T>::getSize() const
{
    return size;
}

template<typename T>
size_t myVec<T>::getCap() const
{
    return capacity;
}

template<typename T>
bool myVec<T>::isEmpty() const
{
    return size == 0;
}

template<typename T>
T& myVec<T>::operator[](int idx)
{
    return data[idx];
}

template<typename T>
const T& myVec<T>::operator[](int idx) const
{
    return data[idx];
}

template<typename T>
void myVec<T>::pushBack(const T& value)
{
    if(size == capacity)
        resize();

    data[size] = value;
    size++;
}

template<typename T>
void myVec<T>::popBack()
{
    if(isEmpty())
        throw std::out_of_range("Empty array!");
    
    size--;
}

template<typename T>
T& myVec<T>::front()
{
    return data[0];
}

template<typename T>
const T& myVec<T>::front() const
{
    return data[0];
}

template<typename T>
T& myVec<T>::back()
{
    return data[size - 1];
}

template<typename T>
const T& myVec<T>::back() const
{
    return data[size - 1];
}


int main()
{

    myVec<int> p;
    p.pushBack(1);
    p.pushBack(2);
    p.pushBack(3);
    p.pushBack(4);
    p.pushBack(5);

    for(auto it = p.begin(); it != p.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}
