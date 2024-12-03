#include<bits/stdc++.h>

using namespace std;

int main(){
	ifstream file("input");
	ostringstream buff;
	buff << file.rdbuf();
	file.close();
	string ins = buff.str();
	int sum = 0;
	bool _do = true;
	for(int i=0; i<ins.length()-7; ++i){
		if(ins.substr(i, 4) == "mul(" && _do){
			int digit_count_1 = 0;
			while(ins[i+4+digit_count_1]>='0' && ins[i+4+digit_count_1]<='9' && digit_count_1<3){
				digit_count_1++;
			}
			if(ins[i+4+digit_count_1]==','){
				digit_count_1++;
				int digit_count_2 = 0;
				while(ins[i+4+digit_count_1+digit_count_2]>='0' && ins[i+4+digit_count_1+digit_count_2]<='9' && digit_count_2<3){
					digit_count_2++;
				}
				if(ins[i+4+digit_count_1+digit_count_2]==')'){
					int num_1 = stoi(ins.substr(i+4, digit_count_1));
					int num_2 = stoi(ins.substr(i+4+digit_count_1, digit_count_2));
					sum += num_1*num_2;
				}
			}
		}
		else if(ins.substr(i, 4) == "do()"){
			_do = true;
		}
		else if(ins.substr(i, 7) == "don't()"){
			_do = false;
		}
	}
	cout << sum << endl;
}
