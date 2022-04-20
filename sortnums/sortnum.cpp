#include <vector>
#include <algorithm>
using namespace std;
class Solution {

public:
    int findUnsortedSubarray(vector<int>& nums) {

		vector<int> sortnums(nums);

		sort(sortnums.begin(), sortnums.end());
		int i=0,j=nums.size()-1;
		while(i<j){
			if(nums[i]==sortnums[i]){
				++i;
			} else if(nums[j]==sortnums[j]){
                --j;
            } else {
                break;
            }
		}
		if(i>=j){return 0;}
		return j-i+1;
    }
};