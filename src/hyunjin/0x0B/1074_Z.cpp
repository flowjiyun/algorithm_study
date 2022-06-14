#include <iostream>
using namespace std;

int run(int n, int py, int px) {
	if (n == 0) return(0);

	int half = 1<<(n - 1);
	if (half > py && half > px)
		return (run(n - 1, py, px));
	else if (half > py && half <= px)
		return (half * half + run(n - 1, py, px - half));
	else if (half <= py && half > px)
		return (2 * half * half + run(n - 1, py - half, px));
	else if (half <= py && half <= px)
		return (3 * half * half + run(n - 1, py - half, px - half));
}

int main()
{
	int n, py, px;
	cin >> n >> py >> px;
	
	cout << run(n, py, px);
}
