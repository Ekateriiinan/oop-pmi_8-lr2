#include "Array.h"
#include <algorithm>
#include <stdexcept>

Array::Array() : size(0), data(nullptr) {}

Array::Array(const size_t& n, unsigned char t) : size(n), data(new unsigned char[n]) {
    std::fill(data, data + size, t);
}

Array::Array(const Array& other) : size(other.size), data(new unsigned char[other.size]) {
    std::copy(other.data, other.data + size, data);
}

Array::Array(Array&& other) noexcept : size(other.size), data(other.data) {
    other.size = 0;
    other.data = nullptr;
}

Array& Array::operator=(const Array& other) {
    if (this != &other) {
        delete[] data;
        size = other.size;
        data = new unsigned char[size];
        std::copy(other.data, other.data + size, data);
    }
    return *this;
}

Array& Array::operator=(Array&& other) noexcept {
    if (this != &other) {
        delete[] data;
        size = other.size;
        data = other.data;
        other.size = 0;
        other.data = nullptr;
    }
    return *this;
}

Array::~Array() noexcept {
    delete[] data;
}

size_t Array::getSize() const {
    return size;
}

unsigned char& Array::at(size_t index) {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}

const unsigned char& Array::at(size_t index) const {
    if (index >= size) {
        throw std::out_of_range("Index out of range");
    }
    return data[index];
}