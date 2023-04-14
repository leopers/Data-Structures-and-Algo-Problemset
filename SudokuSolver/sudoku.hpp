#ifndef SUDOKU_HPP
#define SUDOKU_HPP

#include <iostream>
#include <array>

template <typename T>
class Sudoku{
public:
    void read_sudoku(){
        for (std::size_t i = 0; i < 9u; ++i){
            for (std::size_t j = 0; j < 9u; ++j){
                std::cin >> values[i][j];
            }
        }
    }

    bool is_ok(std::size_t i, std::size_t j, std::size_t n){
        return(
            row_safe(i, n) &&
            col_safe(j, n) &&
            box_safe(i - (i%3), j - (j%3), n)
        );
    }

    bool row_safe(std::size_t i, std::size_t n){
        for(std::size_t j = 0; j < 9; ++j){
            if(values[i][j] == n){
                return false;
            }
        }
        return true;
    }

    bool col_safe(std::size_t j, std::size_t n){
        for(std::size_t i = 0; i < 9; ++i){
            if(values[i][j] == n){
                return false;
            }
        }
        return true;
    }

    bool box_safe(std::size_t i, std::size_t j, std::size_t n){
        for(std::size_t w = 0; w < 3; ++w){
            for(std::size_t k = 0; k < 3; ++k){
                if(values[i+w][j+k] == n) return false;
            } 
        }
        return true;
    }


    bool solve_sudoku(std::size_t i, std::size_t j){
        if(i == 8 && j == 9) return true;

        if(j == 9){
            i++;
            j = 0;
        }

        if(values[i][j] > 0) return solve_sudoku(i, ++j);

        for(std::size_t n = 1; n<=9; ++n){
            if(is_ok(i, j, n)){
                values[i][j] = n;
                if (solve_sudoku(i, j+1)) return true;
            }
            values[i][j] = 0;
        }

        return false;
    }

    void print_sudoku(){
        if (solve_sudoku(0, 0) == true){
            for(std::size_t i = 0; i < 9; ++i){
                for(std::size_t j = 0; j < 9; j++){
                    std::cout << values[i][j] << " ";
                }
                std::cout << '\n';
            }
        }
        
        return;
    }

private:
    std::array<std::array<T, 9u>, 9u> values;
};

#endif