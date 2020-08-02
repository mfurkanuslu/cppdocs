#include <memory>

namespace ns1
{

    struct Obj
    {
    };

    void function(Obj obj)
    {
    }

    void function(Obj *obj)
    {
    }

    void function2(void *, void *)
    {
    }

} // namespace ns1

namespace ns2
{
    struct Obj
    {
    };

    void function(Obj *obj, void *other)
    {
    }

    void function2(void *, void *)
    {
    }
} // namespace ns2

namespace nso
{
    void function(void *)
    {
    }
} // namespace nso

int main(int argc, char const *argv[])
{
    function(ns1::Obj{});
    function(new ns1::Obj{});
    nso::function(new ns1::Obj{});
    function(new ns2::Obj{}, new ns1::Obj{});
    //function(new ns1::Obj{}, new ns1::Obj{});
    //function2(new ns1::Obj{}, new ns2::Obj{});
    return 0;
}
