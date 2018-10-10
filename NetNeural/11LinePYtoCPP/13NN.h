//import numpy as np
#include <algorithm>   // transform
#include <cmath>       // exp
#include <cstdlib>     // srand, rand
#include <iomanip>     // setprecision for 8 decimal places
#include <iostream>    // cout
#include <numeric>     // inner_product
#include <string>
#include <vector>      // VECTORS: vector<T>, and MATRICES: vector<vector<T>>

using namespace std;

typedef double      T;
typedef vector<T>   VEC;
typedef vector<VEC> MAT;

void vecPrint(VEC& V) {
	for (auto col : V)
		cout << setprecision(8) << col << " ";
	cout << "\n";
}
void matPrint(MAT& M) {
	for (auto row : M)
		vecPrint(row);
}

void matTransposeMake(MAT& Y, MAT& X) {
	size_t rows = X.size();    //  number of rows    for matrix X
	size_t cols = X[0].size(); //  number of columns for matrix X
	Y.resize(cols);             // set number of rows for Y
	for (auto&e : Y)             // set number of cols for each row of Y
		e.resize(rows);
}

void matTranspose(MAT& Y, MAT& X) {
	for (size_t r = 0; r < X.size(); r++)   // copy data
		for (size_t c = 0; c < X[0].size(); c++)
			Y[c][r] = X[r][c];
}


void matMult(VEC& y, MAT& M, VEC& x) { // vec y = mat M * vec x
	for (size_t r = 0; r < M.size(); r++)
		y[r] = inner_product(M[r].begin(), M[r].end(), x.begin(), 0.); // YES! mat row inner product vec, use double (0.) for IP sum
}
void matMult_NotUsed(VEC& y, VEC& x, MAT& M) { // vec y = vec x * mat M
	for (size_t r = 0; r < M.size(); r++) {
		double sum = 0;
		for (size_t c = 0; c < y.size(); c++)
			sum += x[c] * M[r][c];                                       // YES! vec inner product mat col
		y[r] = sum;
	}
}
void matMult(MAT& C, MAT& A, MAT& B) { // mat C = mat A * mat B
	if (A[0].size() != B.size())
		throw string("matMult: cannot matrix multiply A*B: A(")
		+ to_string(A.size()) + "x" + to_string(A[0].size()) +
		") columns not equal to B("
		+ to_string(B.size()) + "x" + to_string(B[0].size()) + ") rows";
	for (size_t r = 0; r < A.size(); r++)
		for (size_t c = 0; c < B[0].size(); c++) {
			double sum = 0;
			for (size_t k = 0; k < A[0].size(); k++)
				sum += A[r][k] * B[k][c];
			C[r][c] = sum;
		}
}
void matMult(MAT& C, VEC& a, VEC& b) { // mat C = vec a * vec b  (OUTER PRODUCT of two vectors)
	for (size_t r = 0; r < a.size(); r++)
		for (size_t c = 0; c < b.size(); c++) {
			C[r][c] = a[r] * b[c];
		}
}

void matMult(MAT& C, MAT& a, VEC& b) { // mat a = mat c * vec b  
	for (size_t r = 0; r < C.size(); r++)
		for (size_t c = 0; c < b.size(); c++) {
			a[r][c] = C[r][c] * b[c];
		}
}