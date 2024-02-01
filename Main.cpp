#include <iostream>
#include <cstdio>
using namespace std;
int fx[9] = { 0,-1,1,0,0,1,1,-1,-1 };
int fy[9] = { 0,0,0,-1,1,1,-1,1,-1 };
int ans, n, a[15][15], b[101][101];
void walk(int x, int y)
{
	if (x == 1 && y == n)//是否到达终点
	{
		ans++;
		return;
	}
	for (int i = 1; i <= 8; i++)
	{
		int nx = x + fx[i];
		int ny = y + fy[i];
		if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && a[nx][ny] == 0 && !b[nx][ny])
		{
			b[nx][ny] = 1;
			walk(nx, ny);
			b[nx][ny] = 0;
		}
	}
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> a[i][j];
		}
	}
	a[1][1] = 1;
	walk(1, 1);
	cout<<ans;
}