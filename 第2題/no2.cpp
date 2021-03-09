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
int  n,bagw,bags;
int *price = new int[2000],*space=new int[2000],*weight=new int[2000];
memset(price, 0, 4*2000);
memset(space, 0, 4*2000);
memset(weight, 0, 4*2000);
price[0] = 0;
weight[0] = 0;
space[0] = 0;
int it = 1;
int *king = new int [100000000];
memset(king, -1, 4*100000000);

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
		cin >> bagw;
	}
}
while ((c = getchar()) != '\n')
{
	if (c >= '0'&&c <= '9')
	{
		ungetc(c, stdin);
		cin >> bags;
	}
}

while ((c = getchar()) != '\n')
{
	if (c >= '0'&&c <= '9')
	{
		ungetc(c, stdin);
		cin >> price[it++];
	}
}
it = 1;
while ((c = getchar()) != '\n')
{

	if (c >= '0'&&c <= '9')
	{
		ungetc(c, stdin);
		cin >> weight[it++];
	}
}
it = 1;
while ((c = getchar()) != '\n')
{
	if (c >= '0'&&c <= '9')
	{
		ungetc(c, stdin);
		cin >> space[it++];
	}
}
for (int i = 0; i <= n; i++) {
	for (int ii = 0; ii <= bagw; ii++) {
		for (int iii = 0; iii <= bags; iii++) {
	
			
			int index = 1000000 * i + 1000 * ii + iii;
			if (i == 0 || ii == 0 || iii == 0) { king[index] = 0; }
			else {
				if (weight[i] > ii || space[i] > iii) {
					king[index] = king[index - 1000000];
				}
				else {
					int thisprice = price[i] + king[index -  1000000 - 1000 * weight[i] - space[i]];
					if (king[index - 1000000] > thisprice) { 
						king[index] = king[index -1000000];
					}
					else { king[index] = thisprice; }
				}
			}
		}
	}
}
int answer = king[1000000 * n + 1000 * bagw + bags];
int outputitem = 0, outputprice = 0;
int outputstr[100];
memset(outputstr, 0, 4*100);
while (true) {
	if (n == 0)break;
if (king[1000000 * n + 1000 * bagw + bags] != king[1000000 * (n-1) + 1000 * bagw + bags]) {
bagw = bagw - weight[n]; bags = bags - space[n]; 
outputstr[outputitem] = n;
outputitem += 1;
outputprice += price[n];
answer = king[1000000 * (n-1) + 1000 * bagw + bags];
}
n -= 1;
}
cout << outputprice << endl;
cout << outputitem << endl;
cout << "(";
for (int i=outputitem-1; i >= 0; i--) {
	cout << outputstr[i] << ",";
}
cout << ")" << endl;


system("pause");
} 
