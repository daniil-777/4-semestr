#pragma warning(disable:4996) 

#include<iostream>
#include <map>
#include <fstream>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <iostream>
#include <string>
#include <cstring>
#include <cstdint>

using namespace std;

string strToGood(string &s);
void outAnswer(int n);

map<string, int> out;

string strToGood(string &s) {
	string ans;
	for (int i = 0; i < s.size(); ++i) {
		if (s[i] >= 'A' && s[i] <= 'Z') {
			ans.push_back(s[i] - 'A' + 'a');
		}
		else {
			ans.push_back(s[i]);
		}
	}

	char endStr = ans[ans.size() - 1];

	if (endStr != 47 && (endStr < 'a' || endStr > 'z')) {
		ans.pop_back();
	}
	return ans;
}

void outAnswer(int n) {
	vector <pair <int, string> > 
		ans;
	for (map <string, int>::iterator i = out.begin(); i != out.end(); i++) {
		ans.push_back(make_pair(-(*i).second, (*i).first));
	}

	sort(ans.begin(), ans.end());

	for (int i = 0; i < min(n, (int)ans.size()); i++) {
		cout << ans[i].second << " finding on the text a mount " << -ans[i].first << endl;
	}
}
int main()
{
	int n;

	cin >> n;

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	string s;
	while (cin >> s){
		if (strToGood(s).size() >= 1) {
			out[strToGood(s)]++;
		}
	}

	outAnswer(n);
	return 0;
}
