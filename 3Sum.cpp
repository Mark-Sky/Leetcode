#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


vector<vector<int> > threeSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int> > ret;
	for(int i = 0; i < nums.size(); i ++){
		if(i > 0 && nums[i] == nums[i-1]){
			continue;
		}
		int left = i + 1;
		int right = nums.size() - 1;
		while(left < right){
			int sum = nums[i] + nums[left] + nums[right];
			if(sum > 0){
				right -= 1;	
			}
			else if(sum < 0){
				left += 1;
			}
			else{
				int fit_a[3] = {nums[i], nums[left], nums[right]};
				for(int i = 0; i < 3; i++){
					cout << fit_a[i];
				}
				cout << "\n";
				vector<int> fit(fit_a, fit_a + 3);
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
	
	
	return ret;    
}


int main(){
	int nums[6] = {0,0,0,0,-1,-4};
	vector<int> A(nums, nums + 4);
	threeSum(A);
}
