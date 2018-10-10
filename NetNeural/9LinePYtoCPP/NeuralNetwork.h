#pragma once
#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H
#include <vector>
using namespace std;



class NeuralNetwork {
	

public:
	void matTranspose(vector<vector<double>>& Y, vector<vector<double>>& X) {
		size_t rows = X.size();    //  number of rows    for matrix X
		size_t cols = X[0].size(); //  number of columns for matrix X
		Y.resize(cols);             // set nunber of rows for Y
		for (auto&e : Y)             // set nunber of cols for each row of Y
			e.resize(rows);
		for (size_t r = 0; r < rows; r++)   // copy data
			for (size_t c = 0; c < cols; c++)
				Y[c][r] = X[r][c];
	}
	void matMult(vector<double>& Y, vector<vector<double>>& M, vector<double>& X) { // Y = M * X
		for (size_t i = 0; i < M.size(); i++)

			Y[i] = inner_product(M[i].begin(), M[i].end(), X.begin(), 0.);
	}
		vector<double> synaptic_weights;
		NeuralNetwork(size_t);
		double __sigmoid(double x) { return 1. / (1. + exp(-x)); }
		void __sigmoid(vector<double>&output, vector<double> &input);
		double __sigmoid_derivative(double x) { return x*(1. - x); }
		void train(vector<vector<double>>&, vector<double> &,int iterations);
		void think(vector<double>&, vector <vector<double>>&);
		double think(vector<double>&input);
	

	};









#endif // NEURALNETWORK_H