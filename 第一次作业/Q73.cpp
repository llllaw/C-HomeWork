#include<iostream>
#include<string>
using namespace std;
char trans[11][5] = {
	{},{}, { 'a', 'b', 'c' }, { 'd', 'e', 'f' }, { 'g', 'h', 'i' }, { 'j', 'k', 'l' }, { 'm', 'n', 'o' }, { 'p', 'q', 'r', 's' },
	{ 't', 'u', 'v' }, { 'w', 'x', 'y', 'z' }
};
int length;
string input;
string before = "";
void dfs(int i){
	if (i == length + 1){
		cout << before;
		cout << endl;
		return;
	}
	int num = input[i - 1] - '0';
	for (int j = 0;j<(strlen(trans[num]));j++){
		before += trans[num][j];
		dfs(i + 1);
		before = before.substr(0, before.size() - 1);
	}
}
int main(){
	int n;
	cin >> n;
	input = to_string(n);
	length = input.size();
	dfs(1);

}