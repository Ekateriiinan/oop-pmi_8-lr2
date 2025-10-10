#ifndef ARRAY_H
#define ARRAY_H

#include <cstddef>

class Array {
private:
    size_t size;
    unsigned char* data;
public:
    Array();
    Array(const size_t& n, unsigned char t = 0);
    Array(const Array& other);
    Array(Array&& other) noexcept;
    Array& operator=(const Array& other);
    Array& operator=(Array&& other) noexcept;
    ~Array() noexcept;
    
    size_t getSize() const;
    unsigned char& at(size_t index);
    const unsigned char& at(size_t index) const;
};

#endif