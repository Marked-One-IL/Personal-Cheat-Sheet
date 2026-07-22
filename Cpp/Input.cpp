#include <iostream>
#include <string>
#include <sstream>
#include <type_traits>

static std::string input(const char *s)
{
    std::cout << s;
    std::string buffer;
    std::getline(std::cin, buffer);
    return buffer;
}

template <typename T>
static T input(const char *s)
{
    while (true) 
    {
        std::istringstream ss (input(s));
        T value {};
        if (!(ss >> value) || (ss >> std::ws, !ss.eof())) 
        {
            std::cout << "Invalid input! Try again.\n";
            continue;
        }
        return value;
    }
}

int main()
{
    std::cout << input("Enter your name: ") << '\n';
    std::cout << input<int>("Enter your age: ") << '\n';
    std::cout << input<float>("Enter your height: ") << '\n';
    return 0;    
}