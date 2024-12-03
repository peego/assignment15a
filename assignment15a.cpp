// Nic Davis
// CIS 1202 501
// December 2, 2024

#include <iostream>
#include <stdexcept>

using namespace std;

// Exception classes
class invalidCharacterException : public std::runtime_error {
public:
    invalidCharacterException() : std::runtime_error("Invalid character: not a letter") {}
};

class invalidRangeException : public std::runtime_error {
public:
    invalidRangeException() : std::runtime_error("Invalid range: resulting character is not a letter") {}
};

// Function to calculate character offset
char character(char start, int offset) {
    if (!isalpha(start)) {
        throw invalidCharacterException();
    }

    // Calculate target character
    char target = start + offset;

    // Check if target is a letter
    if (!isalpha(target)) {
        throw invalidRangeException();
    }

    return target;
}

// Driver function to test the character function
int main() {
    char start;
    int offset;

    // Sample test cases
    try {
        cout << "character('a', 1) = " << character('a', 1) << endl; // should return 'b'
        cout << "character('a', -1) = " << character('a', -1) << endl; // should throw exception
    } catch (const std::exception& e) {
        cout << e.what() << endl;
    }

    try {
        cout << "character('Z', -1) = " << character('Z', -1) << endl; // should return 'Y'
        cout << "character('?', 5) = " << character('?', 5) << endl; // should throw exception
    } catch (const std::exception& e) {
        cout << e.what() << endl;
    }

    try {
        cout << "character('A', 32) = " << character('A', 32) << endl; // should throw exception
    } catch (const std::exception& e) {
        cout << e.what() << endl;
    }

    return 0;
}
