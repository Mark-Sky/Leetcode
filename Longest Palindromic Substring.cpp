#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;

string solution(string x){
	string ret;
	int x_length = x.length();
	int DP[x_length][x_length];
	memset(DP, 0, sizeof(DP));
	
	int longest = 0;
	int longest_left;
	int longest_right;
	
	for(int i = 0; i < x_length; i++){
		DP[i][i] = 1;
		if(i > 0){
			if(x[i-1] == x[i]){
				DP[i-1][i] = 2;
				longest = 2;
				longest_left = i - 1;
				longest_right = i;	
			}
			else{
				DP[i-1][i] = 1;
			}
		}
	}
	
	
	for(int i = x_length - 3; i >= 0; i--){
		for(int j = x_length - 1; j > i + 1; j--){
			
			if(DP[i+1][j-1] == j - i - 1){
				//cout << i << " " << j << "\n";
					if(x[i] == x[j]){
						DP[i][j] = DP[i+1][j-1] + 2;
						if(DP[i][j] > longest){
							longest = DP[i][j];
							longest_left = i;
							longest_right = j;
						}
					}
					else{
						DP[i][j] = DP[i+1][j-1];
					}
				}
			else{
				DP[i][j] = DP[i+1][j-1];
				}
			
		}
	}
	
	
	//for(int i = 0; i < x_length; i++){
	//	for(int j = 0; j < x_length; j++){
	//		cout << DP[i][j] << " ";
	//	}
	//	cout << "\n";
	//}
	//cout << "longest_right = " << longest_right << "\n";
	//cout << "longest_left = " << longest_left << "\n";
	//cout << "longest = " << longest << "\n";
	if(longest == 0){
		ret = x[0];
	}else{
		
		if(longest == x_length){
			ret = x;
		} 
		else{
			ret = x.substr(longest_left, longest);
			
		}
	}
	
	return ret;
}



int main(){
	string x = "abbsdjaosjdsjdasdibwudodjhwb";
	cout << solution(x);
	return 0;
}
