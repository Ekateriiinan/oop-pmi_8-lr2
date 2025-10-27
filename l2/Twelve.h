#ifndef TWELVE_H
#define TWELVE_H

#include "Array.h"
#include <string>
#include <initializer_list>

class Twelve {
private:
    Array data;
    
    bool isValidDigit(unsigned char c) const;
    int charToValue(unsigned char c) const;
    unsigned char valueToChar(int value) const;
    void removeLeadingZeros();

public:
    Twelve();
    Twelve(const size_t& n, unsigned char t = '0');
    Twelve(const std::initializer_list<unsigned char>& t);
    Twelve(const std::string& t);
    Twelve(const Twelve& other);
    Twelve(Twelve&& other) noexcept;
    Twelve& operator=(const Twelve& other);
    Twelve& operator=(Twelve&& other) noexcept;
    ~Twelve() noexcept = default;
    
    size_t getSize() const;
    void print() const;
    std::string toString() const;
    
    Twelve add(const Twelve& other) const;
    Twelve subtract(const Twelve& other) const;
    Twelve copy() const;
    
    bool equals(const Twelve& other) const;
    bool lessThan(const Twelve& other) const;
    bool greaterThan(const Twelve& other) const;
};

#endif
