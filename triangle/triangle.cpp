#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
		if(nums.size()<3){
            return 0;
        }
        sort(nums.begin(), nums.end());

		vector<int>::iterator a,b;
		int sum=0;
		for(a=nums.begin();a<nums.end()-2;++a){
			for(b=a+1;b<nums.end()-1;++b){
                vector<int>::iterator tmp = lower_bound(b+1,nums.end(),(*a)+(*b));
                sum+=(tmp-b-1);
			}
		}
		return sum;
    }
};