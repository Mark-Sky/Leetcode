//
// Created by zqf on 2021/5/5.
//
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {

public:
    int End,Start,Medium,Target,now;
    vector<int> Answer;

    vector<int> NumsCopy;

    void Init(vector<int>nums){
        for(int i = 0; i <nums.size(); ++i){
            NumsCopy.push_back(nums[i]);
        }

    }
    int FindIndex(int Value ,int repeat){
        //cout << "size = "<<NumsCopy.size()<<"\n";
        //cout<<"Value ="<<Value<<"\n";
        for (int i = 0; i < NumsCopy.size(); ++i) {
            //cout << "copy =" << NumsCopy[i] << "\n";
            if(NumsCopy[i] == Value && i != repeat)
                return i;
        }
        return 0;
    }

    void DivideSearch(vector<int>& nums) {

        /*cout << "D.Start = " << Start<<"\n";
        cout << "D.medium = " << Medium<<"\n";
        cout << "D.END = " << End<<"\n";
        cout << "now = " << nums[now]<<'\n';
        cout << "Medium =  "<< nums[Medium]<< "\n\n";*/
        if (nums[now] + nums[Medium] == Target) {
            Answer.push_back(FindIndex(nums[now],-1));
            Answer.push_back(FindIndex(nums[Medium],Answer[0]));
            return;
        } else if (nums[now] + nums[Medium] > Target) {
            End = Medium;
            if(Medium == (Start + End) / 2){
                return ;
            }
            Medium = (Start + End) / 2;
            return DivideSearch(nums);
        } else if (nums[now] + nums[Medium] < Target){
            Start = Medium;
            if(Medium == (Start + End) / 2){
                return ;
            }
            Medium = (Start + End) / 2;
            return DivideSearch(nums);
        }
    }

    vector<int> twoSum(vector<int>& nums, int target) {
        Target = target;
        Init(nums);
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size(); i++){
            Start = i;
            End = nums.size();
            Medium = (Start + End)/2;
            now = i;
            DivideSearch(nums);
            if(Answer.size())
                break;
        }
        return Answer;
    }

};
int main(){
    Solution s;
    int Array[] = {3,2,3};
    vector<int> nums;
    for(int i=0;i < 3; i++){
        nums.push_back(Array[i]);
    }
    vector<int> answer = s.twoSum(nums , 6);
    for (int i = 0; i < 2; ++i) {
        cout << answer[i] << "\n";
    }
}

