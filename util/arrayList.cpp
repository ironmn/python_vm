#include "arrayList.hpp"
#include "spdlog/spdlog.h"
template class ArrayList<int>;
template class ArrayList<double>;

template<typename T>
ArrayList<T>::ArrayList(int n)
{
    _length = n;
    _size = 0;
    _array = new T[n];
}

template<typename T>
void ArrayList<T>::expand()
{
    T *temp;
    temp = new T[_size];
    for (int i = 0; i < _size; i++) {
        temp[i] = _array[i];   
    }

    delete _array;
    _array = new T[_length << 1];

    for (int i = 0; i < _size; i++) {
        _array[i] = temp[i];
    }

    delete temp;

    _length <<= 1;

    spdlog::info("expand array to {}, size is {}", _length, _size);
}

template<typename T>
void ArrayList<T>::add(T t)
{
    if (_size >= _length) {
        expand();
    }
    _array[_size++] = t;
}

template<typename T>
void 
ArrayList<T>::insert(int index, T t) {
    if (index > _size) {
        spdlog::error("the index is greater than size {}", _size);
        return;
    }
    
    if (_size >= _length - 1) {
        expand();
    }
    //倒序遍历，这样可以不使用中间变量
    for (int i = _size ;i > index; i--) {
        _array[i] = _array[i - 1];
    }
    _array[index] = t;

    ++_size;
    spdlog::info("nsert object at index {} succussfully", index);

}

template<typename T>
void 
ArrayList<T>::set(int index, T t) 
{
    if (index > _size) {
        spdlog::error("the index is greater than size {}", _size);
        return;
    }
    
    _array[index] = t;
}

template<typename T>
int 
ArrayList<T>::length()
{
    return _length;

}

template<typename T>
T
ArrayList<T>::get(int index)
{
    if (index > _size) {
        spdlog::error("the index is greater than size {}", _size);
        return T();
    }
    
    return _array[index];
}

template<typename T>
int
ArrayList<T>::size()
{
    return _size;
}

template<typename T>
T 
ArrayList<T>::pop()
{
    T ans = _array[_size - 1];
    --_size;
    return ans;
}
