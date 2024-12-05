#include<bits/stdc++.h>

using namespace std;

int main(){
	ifstream file_1("input_1");
	int page_1, page_2;
	char pipe;
	map<int, set<int>>ordering;
	while(file_1 >> page_1 >> pipe >> page_2){
		ordering[page_1].insert(page_2);
	}
	file_1.close();

	ifstream file_2("input_2");
	string line;
	vector<vector<int>>updates;
	while(getline(file_2, line)){
		vector<int>pages;
		stringstream ss(line);
		int page;
		char comma;
		while(ss >> page){
			pages.push_back(page);
			ss >> comma;
		}
		updates.push_back(pages);
	}
	file_2.close();

	int sum = 0;
	int size = updates.size();
	for(int i=0; i<size; ++i){
		int num_pages = updates[i].size();
		bool rules_comply = true;
		for(int j=0; j<num_pages; ++j){
			for(int k=j+1; k<num_pages; ++k){
				if(!ordering[updates[i][j]].count(updates[i][k])){
					rules_comply = false;
					swap(updates[i][j], updates[i][k]);
					k--;
				}
			}
		}
		if(!rules_comply){
			sum += updates[i][num_pages/2];
		}
	}
	cout << sum << endl;
}
