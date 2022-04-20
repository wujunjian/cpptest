#include <iostream>
#pragma pack(1)
struct LinkOffsetInfo{     
       uint64_t link_id;
       uint64_t offset;        //该link对应的相对于linkbody起始位置的偏移量
       uint32_t offset1;        //该link对应的相对于linkbody起始位置的偏移量
       uint64_t offset2;        //该link对应的相对于linkbody起始位置的偏移量
};

struct BAC {
    char c;
    int n;
    char b;
};


int main(){
    std::cout<<sizeof(LinkOffsetInfo)<<std::endl;
    std::cout<<sizeof(BAC)<<std::endl;
}