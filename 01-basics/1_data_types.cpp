#include <iostream>
#include <limits>

int main() {
    std::cout << "Data Type\tSize (bytes)\tMinimum\t\t\tMaximum\n";
    
    // char
    std::cout << "char\t\t" << sizeof(char) << "\t\t" << CHAR_MIN << "\t\t\t" << CHAR_MAX << std::endl;

    // short
    std::cout << "short\t\t" << sizeof(short) << "\t\t" << SHRT_MIN << "\t\t\t" << SHRT_MAX << std::endl;

    // int
    std::cout << "int\t\t" << sizeof(int) << "\t\t" << INT_MIN << "\t\t\t" << INT_MAX << std::endl;

    // long
    std::cout << "long\t\t" << sizeof(long) << "\t\t" << LONG_MIN << "\t\t" << LONG_MAX << std::endl;

    // long long
    std::cout << "long long\t" << sizeof(long long) << "\t\t" << LLONG_MIN << "\t\t" << LLONG_MAX << std::endl;

    // float
    std::cout << "float\t\t" << sizeof(float) << "\t\t" << std::numeric_limits<float>::lowest() << "\t\t\t" << std::numeric_limits<float>::max() << std::endl;

    // double
    std::cout << "double\t\t" << sizeof(double) << "\t\t" << std::numeric_limits<double>::lowest() << "\t\t\t" << std::numeric_limits<double>::max() << std::endl;

    // long double
    std::cout << "long double\t" << sizeof(long double) << "\t\t" << std::numeric_limits<long double>::lowest() << "\t\t\t" << std::numeric_limits<long double>::max() << std::endl;

    // bool
    std::cout << "bool\t\t" << sizeof(bool) << "\t\tN/A\t\t\tN/A\n";

    return 0;
}
