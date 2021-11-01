#include <iostream>
#include <vector>
#include <algorithm>
#define for(i,a,b) for(int i = a; i < b; i++)
using namespace std;

int middle(int a, int b, int s) {
	if (a < b) {
		return (a + b) / 2;
	}
	else if (a > b){
		if (a + b == s + 1)
			return 1;
		else if (a + b <= s)
			return (a + b + s) / 2;
		else
			return (a + b - s) / 2;
			
	}	
}
int main() {
	int size;
	int per_num;
	cin >> size >> per_num;
	int n;
	int s;
	int l;
	int a;
	vector<int> num(per_num);
	vector<int> seat(size);
	vector<int> temp;
	for (i, 0, per_num) {
		cin >> num[i];
	}
	for (i, 0, per_num) {
		auto it = find(seat.begin(), seat.end(), num[i]);
		if (temp.size() == 0) {
			seat[0] = num[i];
			temp.push_back(1);
			cout << num[i] << " " << 1 << endl;
		}
		else if (it != seat.end()) {
			seat[distance(seat.begin(), it)] = 0;
			auto it2 = find(temp.begin(), temp.end(), distance(seat.begin(), it) + 1);
			temp.erase(it2);
		}
		else{
			sort(temp.begin(), temp.end());
			if (temp.size() == 1) {
				s = temp[0] + 1;
				l = temp[0] - 1;
				if (l == 0)
					l = size;
			}
			else {
				s = temp[0];
				l = temp[1];
				a = l - s;
				for (k, 1, temp.size()) {
					if (k + 1 == temp.size()) {
						if (a < size - temp[k] + temp[0]) {
							s = temp[k];
							l = temp[0];
						}
					}
					else {
						if (a < temp[k + 1] - temp[k]) {
							s = temp[k];
							l = temp[k + 1];
							a = l - s;
						}
					}
				}	
			}
			if (temp.size() != seat.size()) {
				n = middle(s, l, size);
				seat[n - 1] = num[i];
				temp.push_back(n);
				cout << num[i] << " " << n << endl;
			}
			
		}
	}	
}