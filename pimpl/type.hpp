#pragma once

#include <memory>

class type
{
public:
    explicit type();
    void operation();
    ~type();

private:
    struct impl;
    std::unique_ptr<impl> m_pImpl;
};