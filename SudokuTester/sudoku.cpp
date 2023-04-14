#include <iostream>
#include <array>

template <typename T>
class Sudoku
{
public:
    void read_sudoku()
    {
        for (std::size_t i = 0; i < 9u; ++i){
            for (std::size_t j = 0; j < 9u; ++j)
            {
                std::cin >> values[i][j];
            }
        }
    }

    bool is_sudoku()
    {
        for (std::size_t i = 0; i < 9; ++i)
        {
            for (std::size_t j = 0; j < 9; ++j)
            {
                if (values[i][j] < 1 || values[i][j] > 9)
                    return false;
            }
        }

        for (std::size_t i = 1; i < 10; ++i)
        {
            for (std::size_t j = 0; j < 9; ++j)
            {
                std::size_t count = 0;
                for (std::size_t k = 0; k < 9; ++k)
                {
                    if (values[j][k] == i)
                        ++count;
                }
                if (count == 0)
                    return false;
            }
        }

        for (std::size_t i = 1; i < 10; ++i)
        {
            for (std::size_t j = 0; j < 9; ++j)
            {
                std::size_t count = 0;
                for (std::size_t k = 0; k < 9; ++k)
                {
                    if (values[k][j] == i)
                        ++count;
                }
                if (count == 0)
                    return false;
            }
        }

        for (std::size_t i = 1; i < 10; ++i)
        {
            for (std::size_t a = 0; a < 9; a+=3)
            {
                for (std::size_t b = 0; b < 9; b+=3)
                {
                    std::size_t count = 0;
                    for (std::size_t w = a; w - a < 3; ++w)
                    {
                        for (std::size_t k = b; k - b < 3; ++k)
                        {
                            if (values[w][k] == i)
                                ++count;
                        }
                    }
                    if (count == 0) return false;
                }
            }
        }

        return true;
    };

private:
    std::array<std::array<T, 9u>, 9u> values;
};

int main(){
    Sudoku<std::size_t> game;

    game.read_sudoku();

    if(game.is_sudoku()) std::cout << "VALID" << '\n';
    else std::cout << "INVALID" << '\n';
}