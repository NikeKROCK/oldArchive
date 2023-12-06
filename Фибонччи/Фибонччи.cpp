#include <vector>
#include <iostream>
using namespace std;
void fill(vector<int>& a) {
	for (int i = 0; i < a.size(); i++) {
		if (i >= 2) {
			a[i] = a[i - 1] + a[i - 2];
		}
		else {
			
				a[i] = i;
			
		}
	}
}
int main()
{
	int ticks;
	cin >> ticks;
	while (ticks--) {
		int k;
		if (cin >> k) {
			vector<int> a(k+1);
			fill(a);
			cout << a[k]<<"\n";
		}
		else {
			break;
		}
	}
	return 0;
}


