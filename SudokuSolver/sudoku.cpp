#include "sudoku.hpp"

int main(){
    Sudoku<std::size_t> game;
    game.read_sudoku();
    game.print_sudoku();
}