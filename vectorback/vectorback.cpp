// vector::back
#include <iostream>
#include <vector>
#include <functional>
#include <thread>

void changebackref(int& i) {
    i = 100;
}

int main()
{
    std::vector<int> myvector;

    myvector.push_back(10);
    myvector.push_back(9);
    myvector.push_back(8);
    myvector.push_back(7);
    myvector.push_back(6);
    myvector.push_back(5);
    myvector.push_back(4);

    while (myvector.back() != 0)
    {
        myvector.push_back(myvector.back() - 1);
    }

    std::cout << "myvector contains:";
    for (unsigned i = 0; i < myvector.size(); i++)
        std::cout << ' ' << myvector[i];
    std::cout << '\n';


    int& b = myvector.back();
    b = 100;
    std::cout << "myvector contains:";
    for (unsigned i = 0; i < myvector.size(); i++)
        std::cout << ' ' << myvector[i];
    std::cout << '\n';

    std::vector<int> myvector2;
    std::vector<std::thread> threads;
    // std::vector<std::function<void(void)>> funcs;
    myvector2.reserve(100);
    for (int i = 0;i < 100;++i) {
        myvector2.push_back(i);
        auto& ii = myvector2.back();
        // threads.push_back(std::thread(std::bind(changebackref, std::ref(myvector2.back()))));
        // threads.push_back(std::thread(std::bind(changebackref, myvector2[i])));
        // threads.push_back(std::thread(std::bind(changebackref, std::ref(myvector2[i]))));
        threads.push_back(std::thread(std::bind(changebackref, std::ref(ii))));
    }

    // for (int i = 0;i < myvector2.size();++i) {
        // threads.push_back(std::thread(std::bind(changebackref, std::ref(myvector2[i]))));
    // }
    for (auto& t : threads) {
        t.join();
    }
    for (auto& m2 : myvector2) {
        std::cout << m2 << ' ';
    }

    return 0;
}