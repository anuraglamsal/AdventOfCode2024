#include<bits/stdc++.h>

using namespace std;

bool backtracking(vector<int>curr_nums, long long test, long long res, int curr_idx){
	if(curr_idx != curr_nums.size()){
		res += curr_nums[curr_idx];
		if(!backtracking(curr_nums, test, res, curr_idx + 1)){
			res -= curr_nums[curr_idx];
			res *= curr_nums[curr_idx];
			if(!backtracking(curr_nums, test, res, curr_idx + 1)){
				res /= curr_nums[curr_idx];
				string num_1 = to_string(res);
				string num_2 = to_string(curr_nums[curr_idx]);
				string cat = num_1 + num_2;
				try{ // if cat is above long long limit, then you don't have to continue searching.
				     // The "test" inputs aren't that big. 
					res = stoll(cat);
					if(!backtracking(curr_nums, test, res, curr_idx + 1)){
						return false;
					}
				}
				catch(exception){
					return false;
				}
			}
		}
	}
	else{
		if(res != test){
			return false;
		}
	}
	return true;
}

int main(){
	ifstream file("input");
	string line;
	vector<vector<int>>nums;
	vector<long>tests;
	while(getline(file, line)){
		long long test_val;
		char colon;
		stringstream line_stream(line);
		line_stream >> test_val >> colon;
		tests.push_back(test_val);
		vector<int> curr_nums;
		int num;
		while(line_stream >> num){
			curr_nums.push_back(num);
		}
		nums.push_back(curr_nums);
	}

	long long sum = 0;
	for(int i=0; i<nums.size(); ++i){
		if(backtracking(nums[i], tests[i], 0, 0)){
			sum += tests[i];
		}
	}
	cout << sum << endl;
}
