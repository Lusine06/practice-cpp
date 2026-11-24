
#include "string.hpp"

bool String::is_small() const { return (size_and_flag & 1) == 0; }

void String::set_size(size_t n) { size_and_flag = (n << 1) | (size_and_flag & 1); }

char *String::chars(Rep *r) { return reinterpret_cast<char *>(r + 1); }

String::Rep *String::allocate(size_t cap)
{
    Rep *r = static_cast<Rep *>(::operator new(sizeof(Rep) + cap + 1));
    r->refcount = 1;
    r->capacity = cap;
    return r;
}

char *String::data()
{
    if (is_small())
        return small_buffer;
    else
        return chars(rep);
}

void String::release()
{
    if (!is_small())
    {
        if (--rep->refcount == 0)
            ::operator delete(rep);
    }
}

void String::make_unique()
{
    if (is_small() || rep->refcount == 1)
        return;

    Rep *r = allocate(rep->capacity);
    memcpy(chars(r), chars(rep), size() + 1);
    rep->refcount--;
    rep = r;
}


String::String() : small_buffer(), size_and_flag(0) {}

String::~String()
{
    release();
}

String::String(const char *str)
    : small_buffer(), size_and_flag(0)
{
    if (str == nullptr)
        return;

    size_t length = strlen(str);

    if (length <= 22)
    {
        size_and_flag = length << 1;
        memcpy(small_buffer, str, length + 1);
    }
    else
    {
        Rep *r = allocate(length * 2);
        memcpy(chars(r), str, length + 1);
        rep = r;
        size_and_flag = (length << 1) | 1;
    }
}

size_t String::size() const
{
    return size_and_flag >> 1;
}

size_t String::capacity() const
{
    if (is_small())
        return 22;
    else
        return rep->capacity;
}

size_t String::use_count() const 
{
    if (is_small())
        return 0;
    else
        return rep->refcount;
}

String::String(const String &other)
    : small_buffer(), size_and_flag(other.size_and_flag)
{
    if (other.is_small())
    {
        memcpy(small_buffer, other.small_buffer, other.size() + 1);
    }
    else
    {
        rep = other.rep; 
        rep->refcount++;
    }
}

char &String::operator[](size_t index)
{
    make_unique(); 
    return data()[index];
}

const char &String::operator[](size_t index) const
{
    if (is_small())
        return small_buffer[index];
    else
        return chars(rep)[index];
}

String &String::operator=(const String &other)
{
    if (this == &other)
        return *this;

    if (is_small() && other.is_small())
    {
        memcpy(small_buffer, other.small_buffer, other.size() + 1);
        size_and_flag = other.size_and_flag;
    }
    else if (is_small() && !other.is_small())
    {
        rep = other.rep;
        rep->refcount++;
        size_and_flag = other.size_and_flag;
    }
    else if (!is_small() && other.is_small())
    {
        release();
        memcpy(small_buffer, other.small_buffer, other.size() + 1);
        size_and_flag = other.size_and_flag;
    }
    else
    {
        other.rep->refcount++; 
        release();
        rep = other.rep;
        size_and_flag = other.size_and_flag;
    }
    return *this;
}

String::String(String &&other) noexcept
    : small_buffer(), size_and_flag(0)
{
    if (other.is_small())
    {
        memcpy(small_buffer, other.small_buffer, other.size() + 1);
    }
    else
    {
        rep = other.rep; 
    }
    size_and_flag = other.size_and_flag;

    other.size_and_flag = 0;
    other.small_buffer[0] = '\0';
}

String &String::operator=(String &&other) noexcept
{
    if (this == &other)
        return *this;

    release();

    if (other.is_small())
    {
        memcpy(small_buffer, other.small_buffer, other.size() + 1);
    }
    else
    {
        rep = other.rep;
    }
    size_and_flag = other.size_and_flag;

    other.size_and_flag = 0;
    other.small_buffer[0] = '\0';

    return *this;
}

const char *String::c_str() const
{
    if (is_small())
        return small_buffer;
    else
        return chars(rep);
}

bool String::empty() const
{
    return size() == 0;
}

void String::clear()
{
    if (!is_small() && rep->refcount > 1)
    {
        release();
        size_and_flag = 0;
        small_buffer[0] = '\0';
        return;
    }

    size_and_flag &= 1;
    data()[0] = '\0';
}

void String::reserve(size_t new_capacity)
{
    if (new_capacity <= capacity())
        return;

    size_t next_cap = capacity() * 2;
    if (next_cap < new_capacity)
        next_cap = new_capacity;

    Rep *p = allocate(next_cap);

    memcpy(chars(p), c_str(), size() + 1);

    release();

    rep = p; 
    size_and_flag |= 1;
}

void String::resize(size_t new_size)
{
    if (new_size > capacity())
        reserve(new_size);

    else if (new_size == size())
        return;

    make_unique();
    char *d = data();

    if (new_size > size())
    {
        for (size_t i = size(); i < new_size; i++)
            d[i] = '\0';
    }

    set_size(new_size);
    d[size()] = '\0';
}

void String::push_back(char ch)
{
    if (size() + 1 > capacity())
    {
        reserve(size() + 1);
    }

    make_unique();
    char *d = data();

    d[size()] = ch;
    set_size(size() + 1);
    d[size()] = '\0';
}

void String::pop_back()
{
    if (size() == 0)
        return;

    make_unique();

    set_size(size() - 1);
    data()[size()] = '\0';
}

void String::append(const String &other)
{
    if (other.size() == 0)
        return;

    String temp(other); 

    size_t new_size = size() + temp.size();

    if (new_size > capacity())
        reserve(new_size);

    make_unique();
    char *d = data();
    const char *src = temp.c_str();

    for (size_t i = 0; i < temp.size(); i++)
        d[size() + i] = src[i];

    set_size(new_size);
    d[size()] = '\0';
}

void String::print() const
{
    for (size_t i = 0; i < size(); ++i)
    {
        std::cout << (*this)[i];
    }
    std::cout << '\n';
}

String &String::operator+=(const String &other)
{
    append(other);
    return *this;
}

String String::operator+(const String &other) const
{
    String result(*this);
    result.append(other);
    return result;
}

bool String::operator==(const String &other) const
{
    if (this->size() != other.size())
        return false;

    if (memcmp(this->c_str(), other.c_str(), size()) == 0)
        return true;

    return false;
}

bool String::operator!=(const String &other) const
{
    return !(*this == other);
}

bool String::operator<(const String &other) const
{
    if (strcmp(this->c_str(), other.c_str()) < 0)
        return true;
    else
        return false;
}

bool String::operator<=(const String &other) const
{
    if (*this < other || *this == other)
        return true;
    else
        return false;
}

bool String::operator>(const String &other) const
{
    if (strcmp(this->c_str(), other.c_str()) > 0)
        return true;
    else
        return false;
}

bool String::operator>=(const String &other) const
{
    if (*this > other || *this == other)
        return true;
    else
        return false;
}
