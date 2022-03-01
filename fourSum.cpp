#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


vector<vector<int> > fourSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    vector<vector<int> > ret;
	for(int i = 0; i < nums.size(); i ++){
		if(i > 0 && nums[i] == nums[i-1]){
			continue;
		}
		for(int j = i + 1; j < nums.size(); j ++){
			if(j > i + 1 && nums[j] == nums[j-1]){
				continue;
			}
			int left = j + 1;
			int right = nums.size() - 1;
			while(left < right){
				long sum = nums[i] + nums[j] + nums[left] + nums[right] - target;
				if(sum > 0){
					right -= 1;	
				}
				else if(sum < 0){
					left += 1;
				}
				else{
					int fit_a[4] = {nums[i], nums[j], nums[left], nums[right]};
					for(int i = 0; i < 4; i++){
						cout << fit_a[i];
					}
					cout << "\n";
					vector<int> fit(fit_a, fit_a + 4);
					ret.push_back(fit);
					while(left < right){
						if(nums[left] == nums[left+1]){
							left += 1;
						}
						if(nums[right] == nums[right-1]){
							right -= 1;
						}
						else{
							break;
						}
					}
					left += 1;
					right -= 1;
			}
		}
		}
		
	}
	
	
	return ret;    
}


int main(){
	int nums[5] = {2,2,2,2,2};
	vector<int> A(nums, nums + 5);
	fourSum(A, 8);
}
