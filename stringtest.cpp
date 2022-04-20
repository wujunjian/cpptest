#include<string>
#include <boost/archive/iterators/base64_from_binary.hpp>
#include <boost/archive/iterators/binary_from_base64.hpp>
#include <boost/archive/iterators/transform_width.hpp>
#include<iostream>
#include<sstream>
#include<cstring>

using namespace std;

bool Base64Decode(std::string& outPut, const std::string& inPut) {
    typedef boost::archive::iterators::transform_width<boost::archive::iterators::binary_from_base64<std::string::const_iterator>, 8, 6> Base64DecodeIter;
    std::stringstream result;
    try {
        std::copy(Base64DecodeIter(inPut.begin()), Base64DecodeIter(inPut.end()), ostream_iterator<char>(result));
    } catch (std::exception &e) {
        printf("%s exception: %s", inPut.c_str(), e.what());
        return false;
    } catch (...) {
        return false;
    }
    outPut = result.str();
    return outPut.empty() == false;

}
int main(){
	cout << "__func__:" << __func__ <<endl;
	string in = "TVRRME1UUTBOak01TkRrd05UTTVNell4Tnc9PQ==";
	string out = "567567";
	cout << "inPut is:" << in << endl;
	cout << "out is:" << out.size() << endl;
	Base64Decode(out,in);
	cout << "inPut is:" << in << endl;
	cout << "out is:" << out.data() << " " << out.size() << endl;
	cout << "out is:" << out.c_str() << " " << strlen(out.c_str()) << endl;

	cout<<"==="<<endl;
	for(char b:out){
		printf("%X\n",b);
	}

	return 0;
}
