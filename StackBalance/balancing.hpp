#ifndef BALANCING_HPP
#define BALANCING_HPP

#include <iostream>
#include <vector>

template <typename T>
class Stack
{
private:
    std::vector<T> values;

public:
    bool if_balanced()
    {
        std::size_t i = 0;
        T value_;
        while (std::cin >> value_)
        {
            values.push_back(value_);
            if (values[values.size() - 1] != '(' && values[values.size() - 1] != ')' && values[values.size() - 1] != '[' && values[values.size() - 1] != ']' && values[values.size() - 1] != '{' && values[values.size() - 1] != '}')
            {
                values.pop_back();
                continue;
            }

            if (values[values.size() - 1] == ')')
            {
                if ((values[values.size() - 2] != '(') || values.size() <= 1)
                {
                    return false;
                }
                else
                {
                    values.pop_back();
                    --i;
                    values.pop_back();
                    continue;
                }
            }

            if (values[values.size() - 1] == '}')
            {
                if ((values[values.size() - 2] != '{') || values.size() <= 1)
                {
                    return false;
                }
                else
                {
                    values.pop_back();
                    --i;
                    values.pop_back();
                    continue;
                }
            }

            if (values[values.size() - 1] == ']')
            {
                if ((values[values.size() - 2] != '[') || values.size() <= 1)
                {
                    return false;
                }
                else
                {
                    values.pop_back();
                    --i;
                    values.pop_back();
                    continue;
                }
            }
            ++i;
        }
        if(values.size()%2 == 0) return true;
        return false;
    }
};

#endif