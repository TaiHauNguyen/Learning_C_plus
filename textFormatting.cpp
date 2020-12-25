#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int textFormatting(vector<int> starting, vector<int> ending, vector<char> style);

int textFormatting(vector<int> starting, vector<int> ending, vector<char> style) {
	vector<vector<char> > res;
	vector<char> temp{0,0,0};
	vector<int> st;
	vector<int> en;
	int cnt = 0;
	for (int i = 0; i < 2*style.size(); i++) {
		res.push_back(temp);
	}
	for (int i = 0; i < style.size(); i++) {
		if ('b' == style[i]) {
			for (int x = starting[i]; x <= ending[i]; x++) {
				res[x - 1][0] = 'b';
			}
		}
		else if ('i' == style[i]) {
			for (int x = starting[i]; x <= ending[i]; x++) {
				res[x - 1][1] = 'i';
			}
		}
		else if ('u' == style[i]) {
			for (int x = starting[i]; x <= ending[i]; x++) {
				res[x - 1][2] = 'u';
			}
		}
		else {
			;// meo biet.. neu so luong style nhieu hon b,u,i => Teo
		}
	}

	temp.push_back('b');
	temp.push_back('i');
	temp.push_back('u');
	// count 'b', 'i', 'u' => Loop nhieu vl => Tim cach khac thong minh hon coi...
	for (int j = 0; j < temp.size(); j++) {
		int i = 0;
		while (i < res.size())
		{
			while (temp[j] != res[i][0] && ++i < res.size());
			if (i < res.size()) {
				st.push_back(i);
				while (temp[j] == res[i][0] && ++i < res.size());
				en.push_back(i - 1);
				cnt++;
			}
		}
	}
	
	// count selection .... Lai chay vong loop ak?... rip
	int cnt_selec = 0;
	for (int j = 0; j < st.size() - 1; j++) {
		for (int k = j + 1; k < st.size(); k++) {
			if (st[j] == st[k] && en[j] == en[k]) {
				cnt_selec++;
			}
		}
	}
	return 2*cnt - cnt_selec;
}




int main()
{
	vector<int> starting{1,3,9,5,9};
	vector<int> ending{5,8,10,6,10};
	vector<char> style{'b','i','b','i','u'};
	cout << textFormatting(starting, ending, style);
	cout << endl;
	return 0;
}