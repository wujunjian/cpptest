#include <memory>
#include <iostream>
using namespace std;

class PublishHandler {
public:
    PublishHandler() { multi_cache_manager_.reset(new int(100)); }
    std::shared_ptr<int> multi_cache_manager_;
};

int main(int argc, char** argv) {
    std::shared_ptr<PublishHandler> a(new PublishHandler);
    std::cout << "===" << *a->multi_cache_manager_ << std::endl;
    PublishHandler* b = &(*a);

    *a->multi_cache_manager_ = 200;
    std::cout << "===" << *a->multi_cache_manager_ << std::endl;

    std::cout << "===" << *b->multi_cache_manager_ << std::endl;
    return 0;
}