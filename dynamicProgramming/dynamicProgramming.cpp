#include <iostream>

using namespace std;


int matrix_chain_order(int p,int n);
void print_opt_parens(int& s, int i, int j, int& name);

int main() {





	return 0;
	
}


int matrix_chain_order(int p, int n) {


}

void print_opt_parens(int& s, int i, int j, int& name) {
	if (i == j) {
		cout << name++;

		return;
	}
	cout << "(";
	print_opt_parens(s, i, s[i, j], name);
	print_opt_parens(s, i, s[i, j], name);
	cout << ")";
}