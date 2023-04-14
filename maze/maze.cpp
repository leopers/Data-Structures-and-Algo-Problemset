#include <iostream>
#include <array>
#include <vector>

struct maze{
    int n;
    int** positions;
};

struct position{
    int i, j;
};

void read_maze(maze& m){
    std::cin >> m.n;

    m.positions = new int*[m.n];
    for(int i = 0; i < m.n; ++i)
        m.positions[i] = new int[m.n];

    for (int i = 0; i < m.n; ++i){
        for (int j = 0; j < m.n; ++j)
            std::cin >> m.positions[i][j];
    }
}

void destroy_maze(maze m){
    for (int i = 0; i < m.n; ++i)
        delete[] m.positions[i];
    delete[] m.positions; 
}

std::vector<position> solve_maze(maze& m, position pos)
{
    if (pos.i < 0 || pos.i >= m.n || pos.j < 0 || pos.j >= m.n || m.positions[pos.i][pos.j] == 1)
        return {};

    if (pos.i == m.n - 1 && pos.j == m.n - 1)
        return {pos};

    std::array<position, 4> tries = {{
        position{pos.i - 1, pos.j},
        position{pos.i + 1, pos.j},
        position{pos.i, pos.j - 1},
        position{pos.i, pos.j + 1},
    }};

    for (const auto next : tries){
        m.positions[pos.i][pos.j] = 1;
        auto partial = solve_maze(m, next);
        if (partial.empty())
            continue;
        else{
            partial.insert(partial.begin(), pos);
            return partial;
        }
    }
    return {};
}

int main(){
    maze maze;
    read_maze(maze);

    auto path = solve_maze(maze, {0, 0});
    for (auto pos : path)
        std::cout << pos.i << ' ' << pos.j << '\n';

    destroy_maze(maze);
}
