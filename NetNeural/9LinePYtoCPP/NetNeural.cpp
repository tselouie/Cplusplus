#include <algorithm>   // transform
#include <cmath>       // exp
#include <cstdlib>     // srand, rand
#include <iomanip>     // setprecision
#include <iostream>
#include <numeric>     // inner_product
#include <vector>   // vectors vector<->, and matrices vector<vector<->>
#include "NeuralNetwork.h"



NeuralNetwork::NeuralNetwork(size_t t) {
	synaptic_weights.resize(t);
	srand(1);
	//initialize
	for (auto& e : synaptic_weights)
		e = 2. * rand() / double(RAND_MAX) - 1.;
	
	}

void NeuralNetwork::__sigmoid(vector<double>& output, vector<double>& input)
{
	transform(input.begin(), input.end(), output.begin(),
		[this](double i) { return __sigmoid(i); });
}
	

void NeuralNetwork::think(vector<double>&output, vector<vector<double>>&inputs)
{
	matMult(output, inputs, synaptic_weights);
	__sigmoid(output, output);
}

double NeuralNetwork::think(vector<double>& input)
{
	return __sigmoid(inner_product(input.begin(), input.end(), synaptic_weights.begin(), 0.));
}



void NeuralNetwork::train(vector<vector<double>> &training_set_inputs, vector<double> &training_set_outputs, int iterations)
{
	vector<double> output(training_set_outputs.size());
	vector<double> error(training_set_outputs.size());
	vector<vector<double>> training_set_inputsT;
	matTranspose(training_set_inputsT, training_set_inputs);
	vector<double> adjustments(training_set_inputs[0].size());


	for (int iteration = 0; iteration < iterations; iteration++) {

		think(output, training_set_inputs);

		transform(training_set_outputs.begin(), training_set_outputs.end(),
			output.begin(),
			error.begin(),
			[](double t, double o) { return t - o; });
		transform(error.begin(), error.end(),
			output.begin(),
			error.begin(),
			[this](double e, double o) { return e * __sigmoid_derivative(o); });

		matMult(adjustments, training_set_inputsT, error);

		transform(synaptic_weights.begin(), synaptic_weights.end(),
			adjustments.begin(),
			synaptic_weights.begin(),
			[](double w, double a) { return w + a; });
		
	}
}








