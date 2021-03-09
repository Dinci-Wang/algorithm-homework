#include <cstring>
#include<iostream>
#include<vector>
#include <algorithm> 
#include<cmath>
#include<string>
using namespace std;
int main()
{
	bool cc = false;//陣列0不放東西
	int p[200],n;
	memset(p, 0, 4*200);
	int i = 1;
	char c,c2[2];
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
			cin >> p[i++];
		}
	}
	int r[2000], s[2000];
		memset(r,0,4*2000);
		memset(s, 0, 4*2000);
	p[0] = 0;
	for (int i = 1; i <= n; i++) {
		r[i]=p[i];
	}
	for (int j = 1; j <= n; j++) {
		int q = -1;
		int dinci = r[0];
		for (int i = 1; i <= j; i++) {
			if (q < r[i] + r[j - i]) {
				q = r[i] + r[j - i];
				s[j] = i;
			}
		}
		r[j] = q;
	}
	int n1=n,rodnum=0;
	cout << "price: " << r[n] << endl;
	for (n; n != 0; n -= s[n]) {
		rodnum += 1;
	}
	cout << rodnum << endl;
	cout <<"rod: "<<n1<< " cut:" ;
	for (n1; n1 != 0; n1 -= s[n1]) {
		cout << s[n1] <<" ";
	}
	
	
	
	system("pause");

}
