// In C++, a Pair is a simple template class provided by the Standard Template Library (STL)
//  to store a pair of values. It is defined in the <utility> header.

#include <iostream>
#include <utility> // for std::pair

int main() {
    // Creating a pair of integers
    std::pair<int, int> coordinates(3, 4);

    // Accessing the elements of the pair
    int x = coordinates.first;
    int y = coordinates.second;

    // Displaying the pair elements
    std::cout << "Coordinates: (" << x << ", " << y << ")\n";

    // Creating a pair of different types
    std::pair<std::string, double> student("Alice", 85.5);

    // Accessing the elements of the pair
    std::string studentName = student.first;
    double studentGrade = student.second;

    // Displaying the pair elements
    std::cout << "Student: " << studentName << ", Grade: " << studentGrade << "\n";

    // Pair as return type from a function
	// lambda takes no parameters (denoted by ()), and it returns a std::pair<int, int>. The -> arrow indicates the return type.
	//return std::make_pair(7, 10); }: This is the body of the lambda function
    auto getCoordinates = []() -> std::pair<int, int> {
        return std::make_pair(7, 10);
    };

    std::pair<int, int> newCoordinates = getCoordinates();
    std::cout << "New Coordinates: (" << newCoordinates.first << ", " << newCoordinates.second << ")\n";

    return 0;
}
