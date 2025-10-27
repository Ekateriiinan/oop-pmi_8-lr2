#include "Twelve.h"

#include <algorithm>
#include <iostream>
#include <stdexcept>


bool Twelve::isValidDigit(unsigned char c) const {
    return (c >= '0' && c <= '9') || (c >= 'A' && c <= 'B') || (c >= 'a' && c <= 'b');
}

int Twelve::charToValue(unsigned char c) const {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'A' && c <= 'B') return c - 'A' + 10;
    if (c >= 'a' && c <= 'b') return c - 'a' + 10;
    return 0;
}

unsigned char Twelve::valueToChar(int value) const {
    if (value >= 0 && value <= 9) return '0' + value;
    if (value >= 10 && value <= 11) return 'A' + (value - 10);
    return '0';
}

void Twelve::removeLeadingZeros() {
    size_t start = 0;
    while (start < data.getSize() - 1 && data.at(start) == '0') {
        start++;
    }
    if (start > 0) {
        Array newData(data.getSize() - start);
        for (size_t i = 0; i < newData.getSize(); i++) {
            newData.set(i, data.at(start + i));
        }
        data = std::move(newData);
    }
}

bool Twelve::equals(const Twelve& other) const {
    if (data.getSize() != other.data.getSize()) {
        return false;
    }
    for (size_t i = 0; i < data.getSize(); i++) {
        if (data.at(i) != other.data.at(i)) {
            return false;
        }
    }
    return true;
}

bool Twelve::lessThan(const Twelve& other) const {
    if (data.getSize() != other.data.getSize()) {
        return data.getSize() < other.data.getSize();
    }
    for (size_t i = 0; i < data.getSize(); i++) {
        if (data.at(i) != other.data.at(i)) {
            return charToValue(data.at(i)) < charToValue(other.data.at(i));
        }
    }
    return false;
}

bool Twelve::greaterThan(const Twelve& other) const {
    if (data.getSize() != other.data.getSize()) {
        return data.getSize() > other.data.getSize();
    }
    for (size_t i = 0; i < data.getSize(); i++) {
        if (data.at(i) != other.data.at(i)) {
            return charToValue(data.at(i)) > charToValue(other.data.at(i));
        }
    }
    return false;
}

size_t Twelve::getSize() const {
    return data.getSize();
}

void Twelve::print() const {
    for (size_t i = 0; i < data.getSize(); i++) {
        std::cout << data.at(i);
    }
    std::cout << std::endl;
}

Twelve::Twelve() : data({'0'}) {}

Twelve::Twelve(const size_t& n, unsigned char t) : data(n, t) {
    if (!isValidDigit(t)) {
        throw std::invalid_argument("Invalid digit for twelve system");
    }
}

Twelve::Twelve(const std::initializer_list<unsigned char>& t) : data(t.size()) {
    size_t i = 0;
    for (auto it = t.begin(); it != t.end(); ++it, ++i) {
        if (!isValidDigit(*it)) {
            throw std::invalid_argument("Invalid digit for twelve system");
        }
        data.set(i, *it);
    }
    removeLeadingZeros();
}

Twelve::Twelve(const std::string& t) : data(t.length()) {
    for (size_t i = 0; i < data.getSize(); i++) {
        if (!isValidDigit(t[i])) {
            throw std::invalid_argument("Invalid digit for twelve system");
        }
        data.set(i, t[i]);
    }
    removeLeadingZeros();
}

Twelve::Twelve(const Twelve& other) : data(other.data) {}

Twelve::Twelve(Twelve&& other) noexcept : data(std::move(other.data)) {}

Twelve& Twelve::operator=(const Twelve& other) {
    if (this != &other) {
        data = other.data;
    }
    return *this;
}

Twelve& Twelve::operator=(Twelve&& other) noexcept {
    if (this != &other) {
        data = std::move(other.data);
    }
    return *this;
}

std::string Twelve::toString() const {
    std::string result;
    for (size_t i = 0; i < data.getSize(); i++) {
        result += data.at(i);
    }
    return result;
}

Twelve Twelve::add(const Twelve& other) const {
    std::string result;
    int carry = 0;
    
    size_t i = data.getSize();
    size_t j = other.data.getSize();
    
    while (i > 0 || j > 0 || carry > 0) {
        int sum = carry;
        
        if (i > 0) {
            sum += charToValue(data.at(--i));
        }
        if (j > 0) {
            sum += charToValue(other.data.at(--j));
        }
        
        carry = sum / 12;
        result = std::string(1, valueToChar(sum % 12)) + result;
    }
    
    return Twelve(result);
}

Twelve Twelve::subtract(const Twelve& other) const {
    if (this->lessThan(other)) {
        throw std::invalid_argument("Result would be negative");
    }
    std::string result;
    int borrow = 0;
    size_t i = data.getSize();
    size_t j = other.data.getSize();
    
    while (i > 0) {
        int top = charToValue(data.at(--i));
        int bottom = (j > 0) ? charToValue(other.data.at(--j)) : 0;
        if (borrow) {
            top--;
            borrow = 0;
        }
        if (top < bottom) {
            top += 12;
            borrow = 1;
        }
        result = std::string(1, valueToChar(top - bottom)) + result;
    }
    
    return Twelve(result);
}

Twelve Twelve::copy() const {
    return Twelve(*this);
}
