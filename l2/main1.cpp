#include <iostream>
#include "Twelve.h"

int main() {
    try {
        Twelve num1;
        std::cout << "num1 (default): ";
        num1.print();
        
        Twelve num2("A1B");
        std::cout << "num2 (from string): ";
        num2.print();
        
        Twelve num3({'1', 'A', '2', 'B'});
        std::cout << "num3 (from initializer list): ";
        num3.print();
        
        Twelve num4(4, '5');
        std::cout << "num4 (size with value): ";
        num4.print();
        
        Twelve num5 = num2.copy();
        std::cout << "num5 (copy of num2): ";
        num5.print();
        
        Twelve a("1A3");
        Twelve b("B2");
        
        std::cout << "a: ";
        a.print();
        std::cout << "b: ";
        b.print();
        
        Twelve sum = a.add(b);
        std::cout << "a + b: ";
        sum.print();
        
        Twelve diff = a.subtract(b);
        std::cout << "a - b: ";
        diff.print();
        
        std::cout << "a equals b: " << a.equals(b) << std::endl;
        std::cout << "a less than b: " << a.lessThan(b) << std::endl;
        std::cout << "a greater than b: " << a.greaterThan(b) << std::endl;
        
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}