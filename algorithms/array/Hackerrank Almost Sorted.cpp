#include <bits/stdc++.h>
using namespace std;


bool isSorted(vector<int> & v){
	for(int i = 1; i < v.size(); ++i){
		if(v[i] < v[i - 1]){
			return false;
		}
	}
	return true;
}

void solve(vector<int> & v){
	
	vector<int> aux = v;
	int n = aux.size();
	sort(aux.begin(), aux.end());
	if(aux == v){
		cout << "yes\n";
		return;
	}

	int left = -1, right = -1;
	for(int i = 0; i < n; ++i){
		if(aux[i] != v[i]){
			left = i;
			break;
		}
	}

	for(int i = n - 1; i >= 0; --i){
		if(aux[i] != v[i]){
			right = i;
			break;
		}
	}

	swap(v[left], v[right]);
	if(isSorted(v)){
		cout << "yes\n";
		cout << "swap " << left + 1 << " " << right + 1 << '\n';
		return;
	}
	
	swap(v[left], v[right]);

	for(int i = left + 1; i <= right; ++i){
		if(v[i] > v[i - 1]){
			cout << "no\n";
			return;
		}
	}

	cout << "yes\n";
	cout << "reverse " << left + 1 << " " << right + 1 << '\n';

}


int main(){
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0; i < n; ++i){
		cin >> v[i];
	}
	solve(v);
}


