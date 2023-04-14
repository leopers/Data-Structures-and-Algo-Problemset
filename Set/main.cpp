#include <iostream>
#include <vector>
#include <string>
#include <sstream>

bool bsearch(std::vector<int> v, int key, int begin, int end);

class IntSet{
private:

public:
    std::vector<int> elements;

    void read_set(){
        std::string line;
        std::getline(std::cin, line);
        std::stringstream is(line);

        for (int x; is >> x;)
            elements.push_back(x);
    }

    void define_set(std::vector<int>& def){
        elements = def;
    }

    std::size_t magnitude() const{
        return elements.size();
    }

    void print_sum(std::vector<int>& v) const{
        std::size_t pos1 = 0; 
        std::size_t pos2 = 0;

        while(pos1 < elements.size() && pos2 < v.size()){
            if(elements[pos1] < v[pos2]){
                std::cout << elements[pos1] << ' ';
                ++pos1;
            }
            else if(elements[pos1] == v[pos2]){
                std::cout << elements[pos1] << ' ';
                ++pos1;
                ++pos2;
            }
            else{
                std::cout << v[pos2] << ' ';
                ++pos2;
            }
        }
        for(; pos1 < elements.size(); ++pos1){
            std::cout << elements[pos1] << ' ';
        }
        for(; pos2 < v.size(); ++pos2){
            std::cout << v[pos2] << ' ';
        }
        std::cout << '\n';
    }

    void print_intersection(std::vector<int>& v) const{
        std::size_t pos1 = 0; 
        std::size_t pos2 = 0;

        while(pos1 < elements.size() && pos2 < v.size()){
            if(elements[pos1] < v[pos2]){
                ++pos1;
            }
            else if(elements[pos1] == v[pos2]){
                std::cout << elements[pos1] << ' ';
                ++pos1;
                ++pos2;
            }
            else{
                ++pos2;
            }
        }
        std::cout << '\n';
    };

    void print_difference(std::vector<int>& v) const{
        std::size_t pos1 = 0; 
        std::size_t pos2 = 0;

        while(pos1 < elements.size() && pos2 < v.size()){
            if(elements[pos1] < v[pos2]){
                std::cout << elements[pos1] << ' ';
                ++pos1;
            }
            else if(elements[pos1] == v[pos2]){
                ++pos1;
                ++pos2;
            }
            else{
                ++pos2;
            }
        }
        for (; pos1 < elements.size(); ++pos1){
            std::cout << elements[pos1] << ' ';
        }
        std::cout << '\n';
    }

    void print_inters_magnitude(std::vector<int>& v) const{
        int a = 0;
        for (std::size_t i = 0; i < v.size(); ++i){
            if(bsearch(elements, v[i], 0, elements.size())) ++a;
        }
        std::cout << a << '\n';
    }
};

bool bsearch(std::vector<int> v, int key, int begin, int end){
    if(v.size() == 0) return false;
    while(begin <= end){
        int mid = begin + (end-begin) / 2;

        if(v[mid] == key) return true;

        if(v[mid] < key) begin = mid + 1;

        else end = mid - 1;
    }

    return false;
}

 int main(){
    IntSet ConjA, ConjB, ConjF;
    std::vector<int> v = {1, 2, 3, 5, 8, 13, 21, 34, 55};
    ConjF.define_set(v);

    ConjA.read_set();
    ConjB.read_set();

    std::cout << ConjA.magnitude() << '\n' << ConjB.magnitude() << '\n';
    ConjA.print_sum(ConjB.elements);
    ConjA.print_intersection(ConjB.elements);
    ConjA.print_difference(ConjB.elements);
    ConjB.print_difference(ConjA.elements);
    ConjA.print_inters_magnitude(ConjF.elements);
    ConjB.print_inters_magnitude(ConjF.elements);
 }
