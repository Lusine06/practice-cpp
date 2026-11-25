#include "shared_ptr.h"

template <typename T>
SharedPtr<T>::SharedPtr()
    : ptr(nullptr), control(nullptr) {}

template <typename T>
SharedPtr<T>::SharedPtr(T *ptr)
    : ptr(ptr), control(nullptr)
{
    if (ptr != nullptr)
    {
        try
        {
            control = new ControlBlock();
            control->ref_count = 1;
        }
        catch (...)
        {
            delete ptr;
            throw;
        }
    }
}

template <typename T>
SharedPtr<T>::SharedPtr(const SharedPtr<T> &other) // exmp SharedPtr<int> p2(p1);
{
    ptr = other.ptr;
    control = other.control;
    if (control != nullptr)
        control->ref_count += 1;
}

template <typename T>
SharedPtr<T>::~SharedPtr()
{
    if (control != nullptr)
    {
        control->ref_count--;

        if (control->ref_count == 0)
        {
            delete ptr;
            delete control;
        }
    }
}

template <typename T>
T *SharedPtr<T>::get() const
{
    return ptr;
}

template <typename T>
std::size_t SharedPtr<T>::use_count() const
{
    if (control == nullptr)
        return 0;
    else
        return control->ref_count;
}

template <typename T>
T &SharedPtr<T>::operator*() const
{
    return *ptr;
}

template <typename T>
T *SharedPtr<T>::operator->() const
{
    return ptr;
}

template <typename T>
SharedPtr<T>::operator bool() const
{
    if (ptr == nullptr)
        return false;
    else
        return true;
}

template <typename T>
SharedPtr<T> &SharedPtr<T>::operator=(const SharedPtr<T> &other)
{
    if (this == &other)
        return *this;

    if (control != nullptr)
    {
        control->ref_count--;

        if (control->ref_count == 0)
        {
            delete ptr;
            delete control;
        }
    }

    ptr = other.ptr;
    control = other.control;

    if (control != nullptr)
        control->ref_count++;

    return *this;
}

template <typename T>
SharedPtr<T>::SharedPtr(SharedPtr<T> &&other)
{
    ptr = other.ptr;
    control = other.control;
    other.ptr = nullptr;
    other.control = nullptr;
}

template <typename T>
SharedPtr<T> &SharedPtr<T>::operator=(SharedPtr<T> &&other)
{
    if (this == &other)
        return *this;

    if (control != nullptr)
    {
        control->ref_count--;

        if (control->ref_count == 0)
        {
            delete ptr;
            delete control;
        }
    }

    ptr = other.ptr;
    control = other.control;

    other.ptr = nullptr;
    other.control = nullptr;

    return *this;
}

template <typename T>
void SharedPtr<T>::swap(SharedPtr<T> &other)
{
    T *temp_ptr = ptr;
    ptr = other.ptr;
    other.ptr = temp_ptr;

    ControlBlock *temp_control = control;
    control = other.control;
    other.control = temp_control;
}

template <typename T>
void SharedPtr<T>::reset(T *new_ptr)
{
    if (ptr == new_ptr)
        return;

    SharedPtr<T> tmp(new_ptr);
    swap(tmp); 
} // destr. deletes tmp 

template <typename T>
SharedPtr<T> &SharedPtr<T>::operator=(std::nullptr_t)
{
    if (control != nullptr)
    {
        control->ref_count--;

        if (control->ref_count == 0)
        {
            delete ptr;
            delete control;
        }
    }

    ptr = nullptr;
    control = nullptr;

    return *this;
}
