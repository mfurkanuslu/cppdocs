#include <iostream>
#include <exception>

class Resource
{
public:
    void acquire()
    {
        std::cout << "resource acquired.\n";
    }
    void release()
    {
        std::cout << "resource released.\n";
    }

private:
};

class ResourceOwner
{
public:
    explicit ResourceOwner();
    ~ResourceOwner();

private:
    Resource m_resource;
};

ResourceOwner::ResourceOwner()
{
    m_resource.acquire();
}

ResourceOwner::~ResourceOwner()
{
    m_resource.release();
}

void doSomething()
{
    throw std::runtime_error("an error occured while doing something.");
}

void doSomethingWithResource()
{
    ResourceOwner ro{};
    doSomething();
}

int main(int argc, char const *argv[])
{
    try
    {
        doSomethingWithResource();
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}
