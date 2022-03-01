#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    int min = 1e4;
    int min_ret = 0;
    
    
    
	for(int i = 0; i < nums.size() - 1; i ++){
		
		int left = i + 1;
		int right = nums.size() - 1;
		int local_min = 1e4;
		int local_ret = 0;
		while(left < right){
			
			int distance = (nums[i] + nums[left] + nums[right] - target);
			if(local_min > abs(distance)){
				local_min = abs(distance);
				local_ret = nums[i] + nums[left] + nums[right];
			}
			
			if(left + 1 < right){
				int right_dis = (nums[i] + nums[left] + nums[right - 1] - target);
				int left_dis = (nums[i] + nums[left + 1] + nums[right] - target);
				if(abs(right_dis) > abs(left_dis)){
					left ++;
				}else{
					right --;
				}
			}else{
				break;
			}
			
		}
		if(local_min < min){
			min = local_min;
			min_ret = local_ret;
		}
	}
	
	
	return min_ret;    
}


int main(){
	int nums[4] = {0,0,0, 1};
	vector<int> A(nums, nums + 3);
	cout << threeSumClosest(A, 0);
}
