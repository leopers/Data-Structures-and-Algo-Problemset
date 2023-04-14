#ifndef BTREE_HPP
#define BTREE_HPP

#include <cstddef>
#include <vector>
#include <stdexcept>
#include <optional>
#include <iostream>

template <typename T>
void preorder_copy(std::vector<std::optional<T>>& tree, std::size_t i, std::size_t j){
    if (i >= tree.size())
        return;

    tree[i] = tree[j];
    preorder_copy(tree, 2 * i + 1, 2 * j + 1);
    preorder_copy(tree, 2 * i + 2, 2 * j + 2);
}

template <typename T>
class BST{
public:
    void insert(const T &value){
        insert_recursive(0, value);
    }

    void remove(const T &value){
        remove_recursive(0, value);
    }

    bool search(const T &value) const{
        return search_recursive(0, value);
    }

    void print_tree() const{
        print_tree_recursive(0);
        std::cout << '\n';
    }

    int tree_height() const{
        return height(0);
    }

private:
    void print_tree_recursive(std::size_t i) const{
        if (!node_exists(i)){
            std::cout << "()";
            return;
        }
        std::cout << "(" << values_[i].value();
        print_tree_recursive(2 * i + 1);
        print_tree_recursive(2 * i + 2);
        std::cout << ")";
    }

    bool search_recursive(std::size_t pos, const T &value) const{

        if (pos >= values_.size() || !values_[pos].has_value())
            return false;

        if (values_[pos].value() == value)
            return true;

        return search_recursive(value < values_[pos].value() ? 2 * pos + 1 : 2 * pos + 2, value);
    }

    void insert_recursive(std::size_t pos, const T &value){ 

        if (pos >= values_.size()){
            values_.resize(std::max(2 * values_.size() + 1, pos + 1));

            values_[pos] = value;
            return;
        }

        if (!values_[pos].has_value()){
            values_[pos] = value;
            return;
        }

        if (values_[pos].value() == value)
            return;

        return insert_recursive(value < values_[pos].value() ? 2 * pos + 1 : 2 * pos + 2, value);
    }

    void remove_recursive(std::size_t pos, const T &value){

        if (pos >= values_.size() || !values_[pos].has_value())
            return;

        if (values_[pos] == value){
            
            if (is_leaf(pos)){
                values_[pos] = std::nullopt;
                return;
            }

            if (number_of_children(pos) == 1){
                std::size_t c = child(pos);
                preorder_copy(values_, pos, c);
                return;
            }

            std::size_t c = left_most(2 * pos + 2); 
            values_[pos] = values_[c];
            remove_recursive(c, values_[c].value());
        }

        remove_recursive(value < values_[pos] ? 2 * pos + 1 : 2 * pos + 2,value);
    }

    std::size_t number_of_children(std::size_t pos) const{
        std::size_t n = 0;
        if (node_exists(2 * pos + 1))
            ++n;
        if (node_exists(2 * pos + 2))
            ++n;
        return n;
    }

    bool node_exists(std::size_t pos) const {
    return pos < values_.size() &&
      values_[pos].has_value();
  }

    bool is_leaf(std::size_t pos) const{
        return number_of_children(pos) == 0;
    }

    std::size_t child(std::size_t pos) const{
        if (node_exists(2 * pos + 1))
            return 2 * pos + 1;
        if (node_exists(2 * pos + 2))
            return 2 * pos + 2;
        throw std::runtime_error{"no child found"};
    }

    std::size_t left_most(std::size_t pos) const{
        if (!node_exists(2 * pos + 1))
            return pos;
        return left_most(2 * pos + 1);
    }

    int height(std::size_t pos) const{
        if(!node_exists(pos)) return -1;
        if(is_leaf(pos)) return 0;

        return 1 + std::max(height(2*pos+1), height(2*pos+2));
    }

    std::vector<std::optional<T>> values_;
};
#endif