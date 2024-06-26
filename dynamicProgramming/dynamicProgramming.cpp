#include <iostream>
#include <vector>

using namespace std;

int matrix_chain_order(int p[], int n);
void print_opt_parens(int **s, int i, int j, char& name);



int main() {
	

	cout << "\nSample Input 1: ";
	int testArr[] = { 10, 20, 30, 40, 30 };
	const int arrSize = sizeof(testArr) / sizeof(int);
	matrix_chain_order(testArr, arrSize);


	cout << "\n\nSample Input 2: ";
	int testArr2[] = { 4, 10, 3, 12, 20, 7 };
	const int arrSize2 = sizeof(testArr2) / sizeof(int);
	// cout << "Size: " << arrSize << endl;
	matrix_chain_order(testArr2, arrSize2);
	


	


	return 0;
	
}


int matrix_chain_order(int p[], int n) {
	int** m = new int*[n]; // rows for m
	int** s = new int*[n]; // rows for s


	for (int i = 1; i < n; i++) {
		m[i] = new int[n] {0}; // collumns for m
		s[i] = new int[n] {0}; // collumns for m

		//cout << "Sep: " << m[i][i] << endl;
		//cout << "Com: " << m[i,i] << endl; // Commas dont work, similar to simply cout << arr, it would just give address
	}

	//for (int i = 0; i < n; i++) {

	//	for (int j = 0; j < n; j++) { // testing to see if initial creation of new arr were filled with 0s
	//		m[i][j] = 0; // collumns
	//		s[i][j] = 0;

	//	}
	//}

	
	for (int l = 2; l < n; l++) {

		for (int i = 1; i < n - l + 1; i++) {
			
			int j = i + l - 1;
			m[i][j] = INT_MAX; // 'infinity' , i used the maximums numbers allowed for ints on compiler
			
			for (int k = i; k <= j - 1; k++) {
				int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];

				if (q < m[i][j]) {
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}


	char name = 'A';
	print_opt_parens(s, 1, n-1, name); // we need n - 1 because we aren't using the final collumn/first row
	cout << "\nOptimal Cost is: " << m[1][n - 1]; // same issue here

	//reallocating memory
	//delete[] m[n];
	//delete[] s[n - 1];
	return 0;
}

void print_opt_parens(int **s, int i, int j, char &name) {
	if (i == j) {
		cout << name++;

		return;
	}
	cout << "(";
	print_opt_parens(s, i, s[i][j], name);
	print_opt_parens(s, s[i][j] + 1, j, name);
	cout << ")";
}



// using [i, j] instead of [i][j], personal error from reading psuedocode

//int matrix_chain_order(int p[], const int n) {
//	int** m = new int* [n]; // rows for s
//	int** s = new int* [n]; // rows for s
//
//
//	for (int i = 1; i < n; i++) {
//		m[i, i] = new int{ 0 }; // collumns
//		s[i, i] = new int{ 0 };
//	}
//
//	for (int l = 2; l <= n; l++) {
//		for (int i = 1; i < n - l + 1; i++) {
//
//			int j = i + l - 1;
//			*m[i, j] = INT_MAX;
//
//			for (int k = i; k <= j - 1; k++) {
//				int q = *m[i, k] + *m[k + 1, j] + p[i - 1] * p[k] * p[i];
//
//				if (q < *m[i, j]) {
//					*m[i, j] = q;
//					*s[i, j] = k;
//				}
//			}
//		}
//	}
//
//
//	char name = 'A';
//	print_opt_parens(**s, 1, n, name);
//	cout << "\nOptimal Cost is: " << m[1, n];
//
//
//	delete m;
//	delete s;
//	return 0;
//}