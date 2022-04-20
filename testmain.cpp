#include <iostream>
#include <functional>

class test {
public:
    int test1(int a, int b);
};
int test::test1(int a, int b) {
    return a + b;
}


int main() {
    test a;
    std::cout << a.test1(1, 2) << std::endl;


    std::function< int(int, int)> f = std::bind(&test::test1, a, 5, 6);
    std::cout << "test:" << f(1, 2) << std::endl;

    std::function< int(void)> f2 = std::bind(&test::test1, a, 3, 100);
    std::cout << "test2:" << f2() << std::endl;
}