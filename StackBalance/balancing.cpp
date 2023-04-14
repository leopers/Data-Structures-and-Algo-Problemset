#include "balancing.hpp"

int main(){
    Stack<char> stack;

    if(stack.if_balanced() == false) std::cout << "ERR" << '\n';
    else std::cout << "OK" << '\n';
}