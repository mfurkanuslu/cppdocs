#include <iostream>

template <class Derived>
class CRTP
{
public:
    void doo()
    {
        static_cast<Derived &>(*this).dooImpl();
    }

private:
};

class Derived1 : public CRTP<Derived1>
{
    friend class CRTP;

protected:
    void dooImpl()
    {
        std::cout << "d1\n";
    }
};

class Derived2 : public CRTP<Derived2>
{
    friend class CRTP;

protected:
    void dooImpl()
    {
        std::cout << "d2\n";
    }
};

int main(int argc, char const *argv[])
{
    Derived1 d1{};
    d1.doo();
    Derived2 d2{};
    d2.doo();
    return 0;
}
