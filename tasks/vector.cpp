
#include <iostream>
#include <string>
#include <cstdlib>

/// ClassName<type> objectname example Vector<int> v1, Vector<std::string> v2
template <typename T>
class Vector
{
private:
    T *data;
    size_t size;
    size_t capacity;

public:
    Vector()
    {
        size = 0;
        capacity = 1;
        data = new T[capacity];
    }

    // (Copy Constructor)
    Vector(const Vector &other)
    {
        size = other.size;
        capacity = other.capacity;
        data = new T[capacity];
        for (size_t i = 0; i < size; i++)
        {
            data[i] = other.data[i];
        }
    }

    ~Vector()
    {
        delete[] data;
        data = nullptr;
    }

    void push_back(T value)
    {
        if (size == capacity)
        {
            size_t new_cap = capacity * 2;
            T *new_data = new T[new_cap];

            for (size_t i = 0; i < size; i++)
                new_data[i] = data[i];

            delete[] data;
            data = new_data;
            capacity = new_cap;
        }

        data[size++] = value;
    }

    void pop_back()
    {
        if (size > 0)
            size--;
        else
            std::cout << "Warning! The vector is already empty \n";
    }

    T &operator[](size_t index)
    {
        if (index >= size)
        {
            std::cout << "Error: Index out of bounds! \n";
            std::exit(1);
        }
        return data[index];
    }

    const T &operator[](size_t index) const
    {
        if (index >= size)
        {
            std::cout << "Error: Index out of bounds! \n";
            std::exit(1);
        }
        return data[index];
    }

    Vector operator+(const Vector &other) const
    {
        Vector result;

        if (this->size != other.size)
        {
            std::cout << "Error: Vectors must be of the same size to be added!\n";
            return result;
        }

        for (size_t i = 0; i < this->size; i++)
        {
            result.push_back(this->data[i] + other.data[i]);
        }

        return result;
    }

    // (=)
    Vector &operator=(const Vector &other)
    {
        if (this == &other)
        {
            return *this;
        }

        delete[] data;

        size = other.size;
        capacity = other.capacity;

        data = new T[capacity];
        for (size_t i = 0; i < size; i++)
        {
            data[i] = other.data[i];
        }

        return *this;
    }

    //  (+=)
    Vector &operator+=(const Vector &other)
    {
        if (this->size != other.size)
        {
            std::cout << "Warning! The vectors aren't the same size \n";
            return *this;
        }

        for (size_t i = 0; i < size; i++)
            this->data[i] += other.data[i];

        return *this;
    }

    // (==)
    bool operator==(const Vector &other) const
    {
        if (this->size != other.size)
        {
            return false;
        }
        for (size_t i = 0; i < size; i++)
            if (data[i] != other[i])
            {
                return false;
            }
        return true;
    }

    // (!=)
    bool operator!=(const Vector &other) const
    {
        return !(*this == other);
    }

    size_t ret_size() const
    {
        return size;
    }

    size_t ret_cap() const
    {
        return capacity;
    }
};

int main()
{

    Vector<int> v1;
    v1.push_back(5);
    v1.push_back(20);
    v1.push_back(100);

    Vector<int> v2;
    v2.push_back(1);
    v2.push_back(2);
    v2.push_back(3);

    if (v1 == v2)
        std::cout << "v1 and v2 are equal (==)\n";
    else
        std::cout << "v1 and v2 are NOT equal (!=)\n";

    Vector<int> v5;
    
    v5 = v1;

    std::cout << "v5 elements: ";
    for (size_t i = 0; i < v5.ret_size(); i++)
        std::cout << v5[i] << " ";
    std::cout << "\n\n";

    v1 += v2;

    std::cout << "v1 after v1 += v2: ";
    for (size_t i = 0; i < v1.ret_size(); i++)
        std::cout << v1[i] << " ";
    std::cout << "\n\n";

    // double
    Vector<double> v_double;
    v_double.push_back(5.5);
    v_double.push_back(20.12);
    v_double.push_back(100.99);
    v_double[2] = 20.100;

    std::cout << "v_double elements: ";
    for (size_t i = 0; i < v_double.ret_size(); i++)
        std::cout << v_double[i] << " ";
    std::cout << "\n\n";

    // std::string
    Vector<std::string> v_str;
    v_str.push_back("Hello");
    v_str.push_back("World");
    v_str.push_back("C++");
    v_str.push_back("Task");


    v_str.pop_back();

    std::cout << "v_str elements: ";
    for (size_t i = 0; i < v_str.ret_size(); i++)
        std::cout << v_str[i] << " ";
    std::cout << "\n";

    return 0;
}