#include <iostream>
#include <type_traits>

template <typename T, std::enable_if_t<std::is_same<T, int>::value, int> = 0>
void func(T v)
{
    std::cout << "intse\n";
}

template <typename T, std::enable_if_t<!std::is_same<T, int>::value, int> = 0>
void func(T v)
{
    std::cout << "degilse\n";
}

int main(int argc, char const *argv[])
{
    func(3);
    func("3");
    return 0;
}
