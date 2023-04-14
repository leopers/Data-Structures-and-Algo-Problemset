#include <vector>
#include <stack>
#include <set>

class Digraph {
public:
  Digraph(std::size_t n); //construtor

  bool edge_exists(std::size_t from, std::size_t to) const;

  void add_edge(std::size_t from, std::size_t to);
  void rem_edge(std::size_t from, std::size_t to);

  std::vector<std::size_t> predecessors(std::size_t v) const;
  std::vector<std::size_t> successors(std::size_t v) const;
  std::vector<std::size_t> neighbors(std::size_t v) const;

  std::size_t order() const;

  bool acycle_dfs_test(std::size_t v, std::set<std::size_t> &visited, std::set<std::size_t> &terminated) const;

  bool acycle_test(std::set<std::size_t> &visited, std::set<std::size_t> &terminated) const;

  void top_order_dfs(std::size_t v, std::set<std::size_t> &visited, std::stack<std::size_t> &top_ord) const;

  void top_order(std::set<std::size_t> &visited, std::stack<std::size_t> &top_ord) const;

private:
  void check_vertex(std::size_t) const;

  std::vector<std::vector<bool>> matrix_;
};




