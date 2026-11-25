#pragma once
#include <cstddef>

struct ControlBlock
{
    std::size_t ref_count;
    ControlBlock()
    {
        ref_count = 0;
    }
};

template <typename T>
class SharedPtr
{
private:
    T *ptr;
    ControlBlock *control;

public:
    SharedPtr();
    SharedPtr(T *ptr);
    SharedPtr(const SharedPtr<T> &other);
    ~SharedPtr();
    T *get() const;
    std::size_t use_count() const;
    T& operator*() const;
    T* operator->() const;
    explicit operator bool() const; 
    SharedPtr<T>& operator=(const SharedPtr<T>& other);
    SharedPtr(SharedPtr<T>&& other);
    SharedPtr<T>& operator=(SharedPtr<T>&& other);
    void reset(T* new_ptr = nullptr);
    void swap(SharedPtr<T>& other);
    SharedPtr<T>& operator=(std::nullptr_t);
};

#include "shared_ptr.cpp"