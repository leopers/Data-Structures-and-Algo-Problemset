#include "digraph_adj.hpp"
#include <iostream>

int main(){
    std::size_t order;
    std::cin >> order;
    Digraph gr(order);

    std::size_t a, b;
    while(std::cin >> a >> b){
        gr.add_edge(a, b);
    }

    std::set<std::size_t> visited1;
    std::set<std::size_t> terminated;
    if(gr.acycle_test(visited1, terminated)){
        std::set<std::size_t> visited2;
        std::stack<std::size_t> top_ord;
        gr.top_order(visited2, top_ord);

        while(!top_ord.empty()){
            std::cout << top_ord.top() << ' ';
            top_ord.pop();
        }

        std::cout << '\n';
    }
    else std::cout << '\n';
}