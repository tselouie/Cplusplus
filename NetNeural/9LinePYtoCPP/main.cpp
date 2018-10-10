#include <algorithm>   // transform
#include <cmath>       // exp
#include <cstdlib>     // srand, rand
#include <iomanip>     // setprecision
#include <iostream>
#include <numeric>     // inner_product
#include <vector>   // vectors vector<->, and matrices vector<vector<->>
#include "NeuralNetwork.h"

void vectorPrint(vector<double>& V) {
	for (auto col : V)
		cout << col << " ";
	cout << "\n";
};



int main()

{
	NeuralNetwork neural_network(3);
	cout << "Random starting synaptic weights: ";
	vectorPrint(neural_network.synaptic_weights);

	vector<vector<double>>training_set_inputs = { { 0, 0, 1 },{ 1, 1, 1 },{ 1, 0, 1 },{ 0, 1, 1 } };
	vector<double> training_set_outputs = { 0, 1, 1, 0 };
	
	neural_network.train(training_set_inputs, training_set_outputs, 10000);
	cout << "New synaptic weights after training: ";

	vectorPrint(neural_network.synaptic_weights);
	cout << "Considering new situation [1, 0, 0] -> ?: ";
	vector<double> newInput = { 1, 0, 0 };
	cout << neural_network.think(newInput) << endl;


}