// vector::back
#include <iostream>
#include <vector>
#include <functional>
#include <thread>

int main()
{
    std::vector<std::vector<int>> myvector(3);
    myvector[0].push_back(1);
    myvector.push_back(myvector[0]);
    myvector.push_back(myvector[0]);
    std::cout << myvector.size() << std::endl;
    for (auto& v : myvector) {
        std::cout << v.size() << std::endl;
    }

    return 0;
}
