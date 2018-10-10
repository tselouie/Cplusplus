//Louie Tse
//027168103
//Neural Network in 13 Lines (Gradient Descent)

//import numpy as np
#include <algorithm>   // transform
#include <cmath>       // exp
#include <cstdlib>     // srand, rand
#include <iomanip>     // setprecision for 8 decimal places
#include <iostream>    // cout
#include <numeric>     // inner_product
#include <string>
#include <vector>      // VECTORS: vector<T>, and MATRICES: vector<vector<T>>
#include "13NN.h"

using namespace std;

typedef double      T;
typedef vector<T>   VEC;
typedef vector<VEC> MAT;


//X = np.array([[0, 0, 1], [0, 1, 1], [1, 0, 1], [1, 1, 1]])
//y = np.array([[0, 1, 1, 0]]).T

void app() {

	// activation fxns
	auto  sigmoid = [](T x) { return 1. / (1. + exp(-x)); };
	auto  sigmoid_d = [](T x) { return 1. * (1. - x); };
	//decl
	MAT X = { { 0,0,1 },{ 0,1,1 },{ 1,0,1 },{ 1,1,1 } }; // inputs
	VEC y = { 0,       1,       1,       0 }; // outputs for each input



	srand(1);

	//alpha, hidden_dim = (0.5, 4)

	//synapse_0 = 2 * np.random.random((3, hidden_dim)) - 1
	//synapse_1 = 2 * np.random.random((hidden_dim, 1)) - 1

	MAT SYN0(X[0].size());
	for (auto& row : SYN0) {
		row.resize(X.size());
		for (auto& e : row)
			e = 2. * rand() / T(RAND_MAX) - 1.;
	}

	SYN0 = { { -0.65574186,  0.48403685,  0.15024961,  0.70966555 },
	{ 0.39048786,  0.71387262,  0.30957705, -0.94685097 },
	{ 0.90481615, -0.25597275, -0.08337071,  0.91104228 } };


	VEC SYN1(X.size());
	for (auto& e : SYN1)
		e = 2. * rand() / T(RAND_MAX) - 1.;

	SYN1 = { { 0.21878741 },{ -0.14103906 },{ -0.30949997 },{ -0.84109348 } };

	//for j in xrange(60000) :

	int  iterations = 60000;
	cout << "iterations=" << iterations << "\n";
	MAT XT;
	matTransposeMake(XT, X);
	matTranspose(XT, X);

	MAT layer_1;
	layer_1.resize(X.size());
	for (auto& row : layer_1)
		row.resize(X.size());

	MAT L1T;
	matTransposeMake(L1T, layer_1);

	VEC layer_2(layer_1.size());

	VEC layer_2_delta(layer_1.size());

	MAT layer_1_delta(layer_1.size());
	for (auto& row : layer_1_delta)
		row.resize(layer_1[0].size());

	VEC temp(layer_2_delta.size());

	MAT TEMP(XT.size()); // SYN0 += X.T.dot(L1_DELTA) matMult(TEMP, XT, L1_DELTA)
	for (auto& row : TEMP)
		row.resize(layer_1_delta[0].size());


	for (int iter = 0; iter < iterations; iter++) { // training for loop


	//	layer_1 = 1 / (1 + np.exp(-(np.dot(X, synapse_0))))
		matMult(layer_1, X, SYN0);
		for (auto& row : layer_1)
			for (auto& col : row)
				col = sigmoid(col);
	
	//	layer_2 = 1 / (1 + np.exp(-(np.dot(layer_1, synapse_1))))
		matMult(layer_2, layer_1, SYN1);
		for (auto& e : layer_2)
			e = sigmoid(e);

	//	layer_2_delta = (layer_2 - y)*(layer_2*(1 - layer_2))
		transform(y.begin(), y.end(), layer_2.begin(), layer_2_delta.begin(), [](T y, T l2) { return (l2 - y) *(l2*(1-l2)); });
	//	layer_1_delta = layer_2_delta.dot(synapse_1.T) * (layer_1 * (1 - layer_1))
		matMult(layer_1_delta, layer_2_delta, SYN1);

		for (size_t r = 0; r < layer_1_delta.size(); r++)
			for (size_t c = 0; c < layer_1_delta[0].size(); c++) {
				layer_1_delta[r][c] = layer_1_delta[r][c] * sigmoid_d(layer_1[r][c]);
			}

	//	synapse_1 -= (alpha * layer_1.T.dot(layer_2_delta))

		matMult(TEMP, L1T, layer_2_delta);
		for (size_t r = 0; r < TEMP.size(); r++)
			for (size_t c = 0; c < TEMP[0].size(); c++) {
				SYN1[r] -= TEMP[r][c];
			}

	//	synapse_0 -= (alpha * X.T.dot(layer_1_delta))
		matMult(TEMP, XT, layer_1_delta);
		for (size_t r = 0; r < TEMP.size(); r++)
			for (size_t c = 0; c < TEMP[0].size(); c++)
				SYN0[r][c] -= TEMP[r][c];
	}

	cout << "SYN0:\n";
	matPrint(SYN0);
	cout << "\nSYN1:";
	vecPrint(SYN1);

	cout << "\nlayer_1:\n";
	matPrint(layer_1);
	cout << "\nlayer_2:";
	vecPrint(layer_2);
}

int main()
{
	try {
		app();

	}
	catch (const string e) {
		cerr << e << "\n";
	}
	catch (const char* e) {
		cerr << e << "\n";
	}
	return 0;
}
