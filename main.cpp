#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

std::unordered_set<uint64_t> used;

std::vector<uint32_t> split_long(uint64_t n)
{
    std::vector<uint32_t> res;
    while(n)
    {
        res.emplace_back(uint32_t(n % 10));
        n /= 10;
    }
    return res;
}

uint64_t restore_long(const std::vector<uint32_t>& split)
{
    uint64_t mult = 1;
    uint64_t res = 0;

    for (auto it = split.crbegin(); it != split.crend(); ++it)
    {
        res += *it * mult;
        mult *= 10;
    }

    return res;
}

void permutate(std::vector<uint32_t> split, std::unordered_set<uint64_t>& permutations)
{
    std::sort(split.begin(), split.end());
    uint64_t test = restore_long(split);
    auto it = used.find(test);
    if (it == used.end())
    {
        used.emplace(test);
        permutations.emplace(restore_long(split));
        while(std::next_permutation(split.begin(), split.end()))
        {
            permutations.emplace(restore_long(split));
        }
    }
}

int main()
{
    uint64_t n = 123456789;   
    std::vector<uint32_t> split = split_long(n);

    std::unordered_set<uint64_t> permutations{};
    permutate(split, permutations);
    
    for (auto it = split.begin(); it != split.end(); ++it)
    {
        std::vector<uint32_t> rotated_split(split.size());
        std::rotate_copy(split.begin(), it, split.end(), rotated_split.begin());
        for (auto i = rotated_split.begin() + 1; i != rotated_split.end(); ++i)
        {
            permutate(std::vector<uint32_t>(i, rotated_split.end()), permutations);
        }
    }

    // Print all of the permutations if needed:
    /*
    for (auto p : permutations)
    {
        cout << p << endl;
    }
    */
    
    cout << "Number of permutations: " << permutations.size() << endl;

    return 0;
}