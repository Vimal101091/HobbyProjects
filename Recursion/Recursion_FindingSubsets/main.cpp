#include <iostream>
#include <vector>

void print(std::vector<int>& subset)
{
    for(auto i : subset)
        std::cout << i << " ";
    std::cout << std::endl;
}

void Subsets(std::vector<int> set, int index)
{

    static std::vector<int> subset;
    for(size_t i = index; i < set.size(); ++i) {
        subset.push_back(set[i]);
        Subsets(set, ++index);
        print(subset);
        subset.pop_back();
    }
}

int main()
{
    std::vector<int> set = { 1, 2, 3, 4, 5, 6, 100};
    int index = 0;
    Subsets(set, index);
    return 0;
}
