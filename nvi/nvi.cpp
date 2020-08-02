#include <iostream>
#include <memory>

class base
{
public:
    void doo()
    {
        std::cout << "begin\n";
        dooImpl();
        std::cout << "end\n";
    }

protected:
    virtual void dooImpl() = 0;
};

class derived : public base
{
    void dooImpl() override
    {
        std::cout << "impl\n";
    }
};

int main(int argc, char const *argv[])
{
    std::unique_ptr<base> p = std::make_unique<derived>();
    p->doo();
    return 0;
}
