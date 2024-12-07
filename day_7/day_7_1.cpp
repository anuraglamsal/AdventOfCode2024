#include<bits/stdc++.h>

using namespace std;

bool backtracking(vector<int>curr_nums, long long test, long long res, int curr_idx){
	if(curr_idx != curr_nums.size()){
		res += curr_nums[curr_idx];
		if(!backtracking(curr_nums, test, res, curr_idx + 1)){
			res -= curr_nums[curr_idx];
			res *= curr_nums[curr_idx];
			if(!backtracking(curr_nums, test, res, curr_idx + 1)){
				return false;
			}
		}
	}
	else if(res != test){
		return false;
	}
	return true;
}

int main(){
	ifstream file("input");
	string line;
	vector<vector<int>>nums;
	vector<long long>tests;
	// use getline to read a whole line. The stream reading technique
	// also considers whitespace as a stop point, but getline only 
	// considers new line as stop point. 
	while(getline(file, line)){
		/*int colon_pos = line.find(':');
		long long test_val = stoll(line.substr(0, colon_pos));
		tests.push_back(test_val);
		stringstream line_stream(line.substr(colon_pos + 1));
		int num;*/

		// I prefer this although the above one works.
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
	// parsing took forever
	long long sum = 0;
	for(int i=0; i<nums.size(); ++i){
		if(backtracking(nums[i], tests[i], 0, 0)){
			sum += tests[i];
		}
	}
	cout << sum << endl;
}
