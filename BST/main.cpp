#include "BST.hpp"
#include <sstream>

int main(){
    BST<int> tree;

    std::string line;
    while (std::getline(std::cin, line)){
        int ins;
        char comm;
        std::istringstream sstring(line);
        sstring >> comm >> ins;

        switch(comm){
            case 'p':
            tree.print_tree();
            break;

            case 'i':
            tree.insert(ins);
            break;

            case 'r':
            tree.remove(ins);
            break;

            case 's':
            if(tree.search(ins)) std::cout<<"true\n";
            else std::cout<<"false\n";
            break;

            case 'h':
            std::cout << tree.tree_height() << '\n';
            break;
        }
    }
}