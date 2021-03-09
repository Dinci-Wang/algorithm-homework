#include <cstring>
#include<iostream>
#include<vector>
#include <algorithm> 
#include<cmath>
#include<string>
using namespace std;
int main()
{
	
	bool cc = false;
	int symbols[1001], rreegg = 0, n, small1index = 0, small2index = 0, heapnum = 0;
	int *heap = new int[100000000];
	memset(heap,-2,4*100000000);
	vector<int> word;
	vector<int> reg;
	char c, c2[2];

	while ((c = getchar()) != '\n')
	{
		if (c >= '0'&&c <= '9')
		{
			ungetc(c, stdin);
			cin >> n;
		}
	}
	while ((c = getchar()) != '\n')
	{
		if (c >= '0'&&c <= '9')
		{
			ungetc(c, stdin);
			cin >> symbols[rreegg];
			reg.push_back(symbols[rreegg]);
			rreegg++;
		}
	}
	sort(reg.begin(), reg.end());
	for (int i = reg.size() - 1; i >= 0; i--) {
		word.push_back(reg[i]);
	}
	int letdincisee,see1,see2;
	while (true) {
		vector<int> small1;
		vector<int> small2;
		vector<int> node;
		small1.push_back(word.back());
		
		word.pop_back();
		small2.push_back(word.back());
		
		word.pop_back();
		word.push_back(0);
		node.push_back(small1.back() + small2.back());
		int small12 = small1.back() + small2.back();
		for (int i = word.size() - 2; i >= 0; i--) {
			if (word[i] < node.back()) { word[i + 1] = word[i]; }
			else { word[i + 1] = node.back(); break; }
			if (i == 0) { word[i] = node.back(); }
		}
		for (int i = 0; i < heapnum; i++) {
			if (heap[i*10000+0] == small1.back() && small1.size() == 1) {
				for (int ii = 1; ii < 9999; ii++) {
					if (heap[i*10000+ii] == -2)break;
					small1.push_back(heap[i*10000+ii]);
				}
			}
			else if (heap[i*10000+0] == small2.back() && small2.size() == 1) {
				for (int ii = 1; ii < 9999; ii++) {
					if (heap[i * 10000 + ii] == -2)break;
					small2.push_back(heap[i * 10000 + ii]);
				}
			}
		}
		int putround = 0;
		if (small2.size() >= small1.size()) {
			putround = log(small2.size() + 1) / log(2);		
		}
		if (small2.size() < small1.size()) {
			putround = log(small1.size() + 1) / log(2);
		}
		int startfrom = 1;
		for (int i = 1; i <= putround; i++) {
			for (int ii = startfrom - 1; ii <= pow(2, i) - 2; ii++) {
				if (ii > small1.size() - 1) { node.push_back(-1); }
				else { node.push_back(small1[ii]); }
			}
			for (int ii = startfrom - 1; ii <= pow(2, i) - 2; ii++) {
				if (ii > small2.size() - 1) { node.push_back(-1); }
				else { node.push_back(small2[ii]); }
			}
			startfrom = startfrom * 2;
		}
		for (int i = 0; i < node.size(); i++) {
			heap[heapnum * 10000 + i] = node[i];
		}
		heapnum += 1;
		if (word.size() == 1) { letdincisee = heapnum;  break; }
	}
	cout <<n<< endl;
	for (int i = 0; i <= n-1; i++) {
		string str,answer;
		for (int ii = 0; ii <= 9999; ii++) {
			if (heap[(letdincisee-1) * 10000 + ii] == symbols[i] && heap[(letdincisee-1) * 10000 + (2 * ii+1)] < 0 && heap[(letdincisee-1) * 10000 + (2 * ii + 2)] < 0) {
				ii += 1;
				while (true) {
					if (ii% 2 == 0) { str += "0"; }
					else { str += "1"; }
					ii = ii / 2;
					
					if (ii <=1 )break;
				}
				break;
			}
		}
		for (int ii = str.size() - 1; ii >= 0; ii--) {
			answer += str[ii];
		}
		cout << answer<<" ";
	}
	system("pause");

}
