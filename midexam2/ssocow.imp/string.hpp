#pragma once

#include <iostream>
#include <cstring>
#include <utility>
#include <vector>

class String
{
private:
    struct Rep
    {
        size_t refcount;
        size_t capacity;
    };

    union 
    {
        char small_buffer[23];
        Rep *rep;
    };

    size_t size_and_flag;

    bool is_small() const;
    void set_size(size_t n);

    static char *chars(Rep *r);
    static Rep *allocate(size_t cap);

    char *data();

    void release();
    void make_unique();

public:
    String();
    ~String();

    String(const char *str);

    size_t size() const;
    size_t capacity() const;
    size_t use_count() const;

    String(const String &other);

    char &operator[](size_t index);
    const char &operator[](size_t index) const;

    String &operator=(const String &other);

    String(String &&other) noexcept;
    String &operator=(String &&other) noexcept;

    const char *c_str() const;
    bool empty() const;

    void clear();
    void reserve(size_t new_capacity);
    void resize(size_t new_size);
    void push_back(char ch);
    void pop_back();
    void append(const String &other);
    void print() const;

    String &operator+=(const String &other);
    String operator+(const String &other) const;

    bool operator==(const String &other) const;
    bool operator!=(const String &other) const;
    bool operator<(const String &other) const;
    bool operator<=(const String &other) const;
    bool operator>(const String &other) const;
    bool operator>=(const String &other) const;
};

