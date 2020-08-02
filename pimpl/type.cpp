#include "type.hpp"

struct type::impl
{
    int val;
    bool flag;
    void operationOne();
    void operationTwo();
};

type::type()
    : m_pImpl(std::make_unique<type::impl>())
{
}

void type::operation()
{
    m_pImpl->val = 0;
    m_pImpl->flag = true;
    m_pImpl->operationOne();
    m_pImpl->operationTwo();
}

type::~type()
{
}