#include <cstring>
#include<iostream>
#include<vector>
#include <algorithm> 
#include<cmath>
#include<string>
using namespace std;
int main()
{
	int s[2000], e[2000], acnum, i = 1, endtimebe = 0, index[1000],endtimeaf=99999, choose=0;//
	char c;
	while ((c = getchar()) != '\n') {
		if (c >= '0'&&c <= '9') {
			ungetc(c, stdin);
			cin >> acnum;
		}
	}
	while ((c = getchar()) != '\n') {
		if (c >= '0'&&c <= '9') {
			ungetc(c, stdin);
			cin >> s[i];
			i++;
		}
	}
	i = 1;
	while ((c = getchar()) != '\n') {
		if (c >= '0'&&c <= '9') {
			ungetc(c, stdin);
			cin >> e[i];
			i++;
		}
	}
	/*10
1 199 24 5 6 99 15 120 66 15
25 206 30 15 16 101 17 130 100 19*/
	int answernum = 0;
	int *allanswer = new int[1000];
	memset(allanswer, -1, 4*1000);
	for (int j = 1; j >=0; j++) {
		bool find = false;
		for (int ii = 1; ii < i; ii++) {
			if (s[ii] >= endtimebe&&e[ii] <= endtimeaf) { endtimeaf = e[ii]; index[j] = ii;  find = true;  }
		}
		endtimebe = endtimeaf;
		endtimeaf = 99999;
		if (find == false) { break; }
		
		allanswer[answernum ] = index[j];
		answernum += 1;
	}
	cout << answernum << endl;
	cout << "(";
	for (int i = 0; i >= 0; i++) {
		if (allanswer[i] <0)break;
		else { cout << allanswer[i] << " "; }
	}
	cout << ")";
	system("pause");

}
