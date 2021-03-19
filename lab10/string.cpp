/* Q4) Write a program to overload [ ] for a string object to get the particular character with a given string value.
 */

#include <iostream>
#include <cstring>

class String {
    char str[128];

    public:
    String(const char* s) {
        strcpy(str, s);
    }

    char operator [](int n) {
        return str[n];
    }
};

int main(void) {
    String str("The quick brown fox jumps over the lazy dog");
    std::cout << "str[4] : \'" << str[4] << "\'\n";
    return 0;
}
