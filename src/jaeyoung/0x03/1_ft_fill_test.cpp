#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main () {

	// 백터 생성
	vector<int> v(8);

	// 1번째 위치부터 4번째 위치까지 1로 할당
	fill (v.begin(), v.begin()+4, 1);

	// 5번째 위치부터 끝까지 2로 할당
	fill (v.begin()+4, v.end(), 2);

	cout << "v contains :";
	for (vector<int>::iterator it=v.begin(); it!=v.end(); ++it)
		cout << ' ' << *it;
	cout << '\n';


	// 배열 생성
	int a[8] = {0,};

	// 1번째 위치부터 4번째 위치까지 1로 할당
	fill (a, a + 4, 1);

	// 5번째 위치부터 끝까지 2로 할당
	fill (a + 4, a + sizeof(a)/sizeof(int), 2);

	printf("a contains :");
	for (int i = 0; i<sizeof(a)/sizeof(int); i++)
		printf(" %d", a[i]);
	printf("\n");

	return 0;
}