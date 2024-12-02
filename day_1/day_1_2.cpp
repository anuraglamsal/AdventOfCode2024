#include<bits/stdc++.h>

using namespace std;

int main(){
	vector<int> list_1, list_2;
	ifstream file("day_1_input.txt");
	int a, b;
	while(file >> a >> b){
		list_1.push_back(a);
		list_2.push_back(b);
	}
	//sort(list_1.begin(), list_1.end());
	//sort(list_2.begin(), list_2.end());
	int sum = 0;
	for(int i=0; i<list_1.size(); ++i){
		sum += list_1[i] * count(list_2.begin(), list_2.end(), list_1[i]); 
	}
	cout << sum << endl;
}
