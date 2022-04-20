
#include <fstream>
#include <iostream>

int main() {
    std::ifstream infile("test.log");
    if (!infile.is_open()) {
        std::cout << "读取文件失败" << std::endl;
        return -1;
    }
    std::string buf;
    while (std::getline(infile, buf)) {
        std::cout << buf << std::endl;
    }
    return 0;
}