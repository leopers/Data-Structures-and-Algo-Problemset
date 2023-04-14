#include "digraph_adj.hpp"

#include <stdexcept>
#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

Digraph::Digraph(std::size_t n) :
  matrix_(n, std::vector<bool>(n, false))
{}

bool Digraph::edge_exists(std::size_t from, std::size_t to) const
{
  check_vertex(from);
  check_vertex(to);
  return matrix_[from][to];
}


void Digraph::add_edge(std::size_t from, std::size_t to)
{
  check_vertex(from);
  check_vertex(to);
  matrix_[from][to] = true;
}

void Digraph::rem_edge(std::size_t from, std::size_t to)
{
  check_vertex(from);
  check_vertex(to);
  matrix_[from][to] = false;
}


void Digraph::check_vertex(std::size_t v) const {
  if (v >= order())
    throw std::out_of_range{"vertex does not exist"};
}

std::vector<std::size_t>
  Digraph::successors(std::size_t v) const
{
  std::vector<std::size_t> s;
  for (std::size_t to = 0; to < order(); ++to)
    if (edge_exists(v, to))
      s.push_back(to);
  return s;
}

std::vector<std::size_t> Digraph::predecessors(std::size_t v) const{
  std::vector<std::size_t> s;
  for (std::size_t from = 0; from < order(); ++from)
    if (edge_exists(from, v))
      s.push_back(from);
  return s;
}

std::vector<std::size_t> Digraph::neighbors(std::size_t v) const{
  std::vector<std::size_t> s;
  for (std::size_t neib = 0; neib < order(); ++neib)
    if (edge_exists(neib, v) || edge_exists(v, neib))
      s.push_back(neib);
  return s;
}

std::size_t Digraph::order() const {
  return matrix_.size();
}

bool Digraph::acycle_dfs_test(std::size_t v, std::set<std::size_t> &visited, std::set<std::size_t> &terminated) const{
  visited.insert(v);
  for (auto x : successors(v)){
    if (terminated.find(x) != terminated.end()) continue;
    if (visited.find(x) == visited.end()){
      if(!acycle_dfs_test(x, visited, terminated)) return false;
    } 
    else return false;
  }
  terminated.insert(v);
  return true;
}

bool Digraph::acycle_test(std::set<std::size_t> &visited, std::set<std::size_t> &terminated) const{
  for (std::size_t i = 0; i < order(); ++i){
    if (terminated.find(i) == terminated.end()){
      if (!acycle_dfs_test(i, visited, terminated)) return false;
    }
  }
  return true;
}

void Digraph::top_order_dfs(std::size_t v, std::set<std::size_t> &visited, std::stack<std::size_t> &top_ord) const{
  visited.insert(v);
  for (auto x : successors(v)){
    if (visited.find(x) == visited.end()) top_order_dfs(x, visited, top_ord);
  }
  top_ord.push(v);
}

void Digraph::top_order(std::set<std::size_t> &visited, std::stack<std::size_t> &top_ord) const{
  for (std::size_t i = 0; i < order(); ++i){
    if (visited.find(i) == visited.end()){
      top_order_dfs(i, visited, top_ord);
    }
  }
}


