
#include<iostream>
#include<iomanip>
#include<fstream>
#include<sstream>
#include<cmath>
#include<cstdlib>
#include<string>
#include<list>
#include <forward_list>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include <array>
#include <regex>
#include<random>
#include<stdexcept>


using namespace std;

class tt {
public:
	double dou;
	char ch;
};
class t {
public:
	tt l();
};
tt t::l() {
	char m;
	cin >> m;
		switch (m) {
		case 'q':
			return tt{ 7.1 , m };
		case '.':
		case '0': case '1': case '2': case '3': case '4':
		case '5': case '6': case '7': case '8': case '9':
		{
			cin.putback(m);
			double a;
			cin >> a;
			return tt{ a, 't'};
		}
		default	:
			cout<<"NO";
		}
}
int main() {
	t v;
	cout << v.l().dou;
}





