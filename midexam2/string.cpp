#include <iostream>
#include <cstring>

class String
{
private:
    char small_buffer[23];
    char *heap_data;
    size_t string_size;
    size_t string_capacity;
    bool is_small;

public:
    String() : small_buffer(), heap_data(nullptr), string_size(0), string_capacity(22), is_small(true) {}

    ~String()
    {
        if (!is_small)
        {
            delete[] heap_data;
        }
    }
    String(const char *str)
        : small_buffer(), heap_data(nullptr),
          string_size(0), string_capacity(22), is_small(true)
    {
        if (str == nullptr)
            return;

        size_t length = strlen(str);

        if (length <= 22)
        {
            string_size = length;
            strcpy(small_buffer, str);
        }
       else
        {
            is_small = false;
            string_size = length;
            string_capacity = length * 2; 

            heap_data = new char[string_capacity + 1];
            strcpy(heap_data, str);
        }
    }
    size_t size() const
    {
        return string_size;
    }
    size_t capacity() const
    {
        return string_capacity;
    }

    String(const String &other)
        : small_buffer(), heap_data(nullptr),
          string_size(other.string_size),
          string_capacity(other.string_capacity),
          is_small(other.is_small)
    {
        if (other.is_small)
        {
            strcpy(small_buffer, other.small_buffer);
        }
        else
        {
            heap_data = new char[string_capacity + 1];
            strcpy(heap_data, other.heap_data);
        }
    }
    char &operator[](size_t index)
    {
        if (is_small == true)
            return small_buffer[index];
        else
            return heap_data[index];
    }
    const char &operator[](size_t index) const
    {
        if (is_small)
            return small_buffer[index];
        else
            return heap_data[index];
    }
    String &operator=(const String &other)
    {

        if (this == &other)
            return *this;

        if (is_small && other.is_small) // small -> small
        {
            strcpy(small_buffer, other.small_buffer);
            string_size = other.string_size;
        }
        else if (is_small && !other.is_small) // small -> large
        {
            char *ptr = new char[other.string_capacity + 1];
            strcpy(ptr, other.heap_data);
            heap_data = ptr;
            string_size = other.string_size;
            string_capacity = other.string_capacity;
            is_small = false;
        }
        else if (!is_small && other.is_small) // large -> small
        {
            delete[] heap_data;
            heap_data = nullptr;
            strcpy(small_buffer, other.small_buffer);
            string_size = other.string_size;
            string_capacity = 22;
            is_small = true;
        }
        else // large -> large
        {
            if (string_capacity >= other.string_size)
            {
                strcpy(heap_data, other.heap_data);
                string_size = other.string_size;
            }
            else if (string_capacity < other.string_size)
            {
                char *ptr = new char[other.string_capacity + 1];
                strcpy(ptr, other.heap_data);
                delete[] heap_data;
                heap_data = ptr;
                string_size = other.string_size;
                string_capacity = other.string_capacity;
            }
        }
        return *this;
    }
    String(String &&other) /// exmp. String str1("looooong text"); String str2 = std::move(str1);
    {                      /// other = str1; this = str2
        if (other.is_small)
        {
            strcpy(small_buffer, other.small_buffer);
            string_size = other.string_size;
            string_capacity = 22;
            is_small = true;
        }
        else
        {
            heap_data = other.heap_data;
            string_size = other.string_size;
            string_capacity = other.string_capacity;
            is_small = false;

            other.heap_data = nullptr;
        }

        other.string_size = 0;
        other.string_capacity = 22;
        other.is_small = true;
        other.small_buffer[0] = '\0';
    }
    String &operator=(String &&other)
    {
        if (this == &other)
            return *this;

        if (!is_small)
            delete[] heap_data;

        if (other.is_small)
        {
            strcpy(small_buffer, other.small_buffer);
        }
        else
        {
            heap_data = other.heap_data;
            other.heap_data = nullptr;
        }

        string_size = other.string_size;
        string_capacity = other.string_capacity;
        is_small = other.is_small;

        other.string_size = 0;
        other.string_capacity = 22;
        other.is_small = true;
        other.small_buffer[0] = '\0';

        return *this;
    }
    const char *c_str() const
    {
        if (is_small)
            return small_buffer;
        else
            return heap_data;
    }
    bool empty() const
    {
        return string_size == 0;
    }
    void clear()
    {
        string_size = 0;

        if (is_small)
            small_buffer[0] = '\0';
        else
            heap_data[0] = '\0';
    }
    void reserve(size_t new_capacity)
    {
        if (new_capacity <= string_capacity)
            return;

        size_t next_cap = string_capacity * 2;
        if (next_cap < new_capacity)
            next_cap = new_capacity;

        char *p = new char[next_cap + 1];

        if (is_small)
            strcpy(p, small_buffer);
        else
            strcpy(p, heap_data);

        if (!is_small)
            delete[] heap_data;

        heap_data = p;
        is_small = false;
        string_capacity = next_cap;
    }
    void resize(size_t new_size)
    {
        if (new_size > string_capacity)
            reserve(new_size);

        else if (new_size == string_size)
            return;

        else if (new_size < string_size)
        {
            if (is_small)
                small_buffer[new_size] = '\0';
            else
                heap_data[new_size] = '\0';

            string_size = new_size;
        }
        if (new_size > string_size)
        {
            if (is_small)
            {
                for (size_t i = string_size; i < new_size; i++)
                    small_buffer[i] = '\0';
            }
            else
            {
                for (size_t i = string_size; i < new_size; i++)
                    heap_data[i] = '\0';
            }

            string_size = new_size;
        }

        if (is_small)
            small_buffer[string_size] = '\0';
        else
            heap_data[string_size] = '\0';
    }
    void push_back(char ch)
    {
        if (string_size + 1 > string_capacity)
        {
            reserve(string_size + 1);
        }

        if (is_small)
        {
            small_buffer[string_size] = ch;
            string_size++;
            small_buffer[string_size] = '\0';
        }
        else
        {
            heap_data[string_size] = ch;
            string_size++;
            heap_data[string_size] = '\0';
        }
    }
    void pop_back()
    {
        if (string_size == 0)
            return;

        string_size--;

        if (is_small)
            small_buffer[string_size] = '\0';
        else
            heap_data[string_size] = '\0';
    }
    void append(const String &other)
    {
        if (other.string_size == 0)
            return;

        String temp(other);

        size_t new_size = string_size + temp.string_size;

        if (new_size > string_capacity)
            reserve(new_size);

        if (is_small)
        {
            if (temp.is_small)
            {
                for (size_t i = 0; i < temp.string_size; i++)
                    small_buffer[string_size + i] = temp.small_buffer[i];
            }
            else
            {
                for (size_t i = 0; i < temp.string_size; i++)
                    small_buffer[string_size + i] = temp.heap_data[i];
            }
        }
        else
        {
            if (temp.is_small)
            {
                for (size_t i = 0; i < temp.string_size; i++)
                    heap_data[string_size + i] = temp.small_buffer[i];
            }
            else
            {
                for (size_t i = 0; i < temp.string_size; i++)
                    heap_data[string_size + i] = temp.heap_data[i];
            }
        }

        string_size = new_size;

        if (is_small)
            small_buffer[string_size] = '\0';
        else
            heap_data[string_size] = '\0';
    }
    void print() const
    {
        for (size_t i = 0; i < string_size; ++i)
        {
            std::cout << (*this)[i];
        }
        std::cout << '\n';
    }
    String &operator+=(const String &other)
    {
        append(other);
        return *this;
    }
    String operator+(const String &other) const
    {
        String result(*this);
        result.append(other);
        return result;
    }
    bool operator==(const String &other) const
    {
        if (this->string_size != other.string_size)
            return false;

        if (strcmp(this->c_str(), other.c_str()) == 0)
            return true;

        return false;
    }

    bool operator!=(const String &other) const
    {
        return !(*this == other);
    }

    bool operator<(const String &other) const
    {
        if (strcmp(this->c_str(), other.c_str()) < 0)
            return true;
        else
            return false;
    }

    bool operator<=(const String &other) const
    {
        if (*this < other || *this == other)
            return true;
        else
            return false;
    }
    bool operator>(const String &other) const
    {
        if (strcmp(this->c_str(), other.c_str()) > 0)
            return true;
        else
            return false;
    }
    bool operator>=(const String &other) const
    {
        if (*this > other || *this == other)
            return true;
        else
            return false;
    }
};

#include <iostream>
#include <utility>

// Այստեղ քո String դասի սահմանումն է (իր print() մեթոդով)

int main()
{
    std::cout << "Small buffer \n";
    String s1("Hello");
    s1.print();
    std::cout << "size: " << s1.size() << " , capacity: " << s1.capacity() << "\n\n";

    std::cout << "Exactly 22 characters \n";
    String s22("1234567890123456789012");
    s22.print();
    std::cout << "size: " << s22.size() << ", capacity: " << s22.capacity() << "\n\n";

    std::cout << "heap \n";
    String s_large("123456789012345678901234567");
    s_large.print();
    std::cout << "size: " << s_large.size() << ", capacity: " << s_large.capacity() << "\n\n";

    std::cout << "Small -> Heap \n";
    s22.push_back('!');
    s22.print();
    std::cout << "size: " << s22.size() << ", capacity: " << s22.capacity() << "\n\n";

    std::cout << " Small -> Heap \n";
    String s_add(" , adding new words to show the result \n");
    s1.append(s_add);
    s1.print();
    std::cout << "size: " << s1.size() << ", capacity: " << s1.capacity() << "\n\n";

    std::cout << "Large -> Small \n";
    String s_short("tiny");
    s_large = s_short;
    s_large.print();
    std::cout << "size: " << s_large.size() << ", capacity: " << s_large.capacity() << "\n\n";

    std::cout << "Small -> Large \n";
    String s_another_large("randomforexperiment123456789876541");
    s_short = s_another_large;
    s_short.print();
    std::cout << "size: " << s_short.size() << ", capacity: " << s_short.capacity() << "\n\n";

    std::cout << "Move constructor and clear() \n";
    String s_moved(std::move(s_short));
    std::cout << "moved: ";
    s_moved.print();
    std::cout << "moved size: " << s_moved.size() << ", capacity: " << s_moved.capacity() << "\n";

    std::cout << "source after move -> empty: " << s_short.empty()
              << ", size: " << s_short.size()
              << ", capacity: " << s_short.capacity() << "\n";

    s_moved.clear();
    s_moved.push_back('A');
    std::cout << "after clear + push_back('A'): ";
    s_moved.print();
    std::cout << "size: " << s_moved.size() << ", capacity: " << s_moved.capacity() << "\n";

    return 0;
}