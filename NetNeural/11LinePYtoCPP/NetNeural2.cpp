#include <algorithm>   // transform
#include <cmath>       // exp
#include <cstdlib>     // srand, rand
#include <iomanip>     // setprecision
#include <iostream>
#include <numeric>     // inner_product
#include <string>
#include <vector>      // vectors vector<->, and matrices vector<vector<->>

using namespace std;
typedef double T;
typedef vector<T> VEC;
typedef vector<VEC> MAT;


void app() {
	//define sigmoid
	auto sigmoid = [](T x) {return 1. / (1. + exp(-x)); };
	//define sigmoid deriv
	auto sigmoid_d = [](T x) {return 1. * (1. - x); };


	//PY np.array([[0, 0, 1], [1, 1, 1], [1, 0, 1], [0, 1, 1]])
	//PY np.array([[0, 1, 1, 0]]).T
	MAT X = {{ 0, 0, 1 }, { 1, 1, 1 }, { 1, 0, 1 }, { 0, 1, 1 }}
	VEC y = { 0,1,1,0 };
	//PY np.random.seed(1)
	srand(1);

	MAT SYN0(X.size());
	for (auto& row : SYN0)
		row.resize(X[0].size();
	VEC syn1(X.size());
	for (auto& row : SYN0)
		for (auto& col : row)
			col = 2. * (rand() / double(RAND_MAX)) - 1.);
	for (auto& e : syn1)
		e = 2. * (rand() / double(RAND_MAX)) - 1.);

	//syn0 = 2 * np.random.random((3, 4)) - 1

	SYN0 = {-0.16595599,0.44064899,-0.99977125, -0.39533485};

	//syn1 = 2 * np.random.random((4, 1)) - 1
	syn1 = {};



	int iterate = 60000;

	for (int iteration = 0; iteration < iterate; iteration++) {
		//	l1 = 1 / (1 + np.exp(-(np.dot(X, syn0))))	
		MAT L1(X.size());
		for(auto& row : L1)
			row.resize(SYN0.size());
		matMult(L1, X, SYN0);
		for (auto& row : L1)
			for (auto& col : row)
				col = sigmoid(col);

		cout << "L1\n";
		matPrint(L1);

		//	l2 = 1 / (1 + np.exp(-(np.dot(l1, syn1))))

		VEC l2(L1.size()));
		matMult(l2, L1, syn1);
		for (auto& e : l2)
			e = sigmoid(e);
		cout << "l2 :";
		vecPrint(l2);
	

		

		//	l2_delta = (y - l2)*(l2*(1 - l2))
		VEC l2_delta(y.size());
		transform(y.begin(), y.end(), l2.begin(), l2_delta.begin(), [sigmoid_d](T y, T l2) {return (y - l2)*sigmoid_d(l2); });
		cout << "l2_delta: ";
		vecPrint(l2_delta);


		//	l1_delta = l2_delta.dot(syn1.T) * (l1 * (1 - l1))	
		MAT L1_DELTA(syn1.size()));
		for (auto& row : L1_DELTA)
			row.resize(l2_delta.size());
		matMult(L1_DELTA, l2_delta,syn1);
		MAT TEMP = L1;
		for (auto& row : TEMP)
			for (auto& col : row)
				col = sigmoid_d(col);
		for (size_t r = 0; r < TEMP.size()); r++)
		for (size_t c = 0; c < TEMP[0].size()); c++)
		L1_DELTA[r][c] = L1_DELTA[r][c] * TEMP[r][c];
			cout << " L1_DELTA: \n";
		matPrint(L1_DELTA);

		//	syn1 += l1.T.dot(l2_delta)

		//	syn0 += X.T.dot(l1_delta)


			exit(1);
	}

}


int main() {
	try {
		app();
	}
	catch (string* e) {
		cerr << e << "\n";
	}
}



//int main(int argc, char*argv[])
//{
//	auto vectorPrint = [](vector<double>& V) {
//		for (auto col : V)
//			cout << col << " ";
//		cout << "\n";
//	};
//	auto matrixPrint = [vectorPrint](vector<vector<double>>& M) {
//		for (auto row : M)
//			vectorPrint(row);
//	};
//	auto matTranspose = [](vector<vector<double>>& Y, vector<vector<double>>& X) {
//		size_t rows = X.size();    //  number of rows    for matrix X
//		size_t cols = X[0].size(); //  number of columns for matrix X
//		Y.resize(cols);             // set nunber of rows for Y
//		for (auto&e : Y)             // set nunber of cols for each row of Y
//			e.resize(rows);
//		for (size_t r = 0; r < rows; r++)   // copy data
//			for (size_t c = 0; c < cols; c++)
//				Y[c][r] = X[r][c];
//	};
//








	

//	vector<double> synaptic_weights0(training_set_inputs[0].size());
//	for (auto& e : synaptic_weights0)
//		e = 2. * rand() / double(RAND_MAX) - 1.;
//
//	vector<double> synaptic_weights1(training_set_inputs[0].size() + 1);
//	for (auto& e : synaptic_weights1)
//		e = 2. * rand() / double(RAND_MAX) - 1.;
//
//	vector<vector<double>> training_set_inputsT;
//	matTranspose(training_set_inputsT, training_set_inputs);
//
//	vector<double> l1(training_set_outputs.size());
//	vector<double> l2(training_set_outputs.size());
//	vector<double> correction(training_set_outputs.size());
//	auto matMult = [](vector<double>& Y, vector<vector<double>>& M, vector<double>& X) { // Y = M * X
//		for (size_t i = 0; i < M.size(); i++)
//			Y[i] = inner_product(M[i].begin(), M[i].end(), X.begin(), 0.);
//	};
//
//	
//
//	int iterate = 60000;
//
//	for (int iteration = 0; iteration < iterate; iteration++) {
//
//
//		matMult(l1, training_set_inputs, synaptic_weights0);             
//		transform(l1.begin(), l1.end(),
//			l1.begin(),
//			[](double element) { return 1. / (1. + exp(-element)); });
//
//		matMult(l2, training_set_inputs, synaptic_weights1);
//		transform(l2.begin(), l2.end(),
//			l2.begin(),
//			[](double element) { return 1. / (1. + exp(-element)); });
//
//	}
//	transform(training_set_outputs.begin(), training_set_outputs.end(),   // prediction error * sigmoid derivative
//		synaptic_weights1.begin(),
//		synaptic_weights1.begin(),
//		[](double t, double o) { return (t - o) * o * (1. - o); }
//	);
//	matMult(correction, training_set_inputsT, synaptic_weights1);                    // weight correction
//	transform(synaptic_weights1.begin(), synaptic_weights1.end(),           // update weights
//		correction.begin(),
//		synaptic_weights1.begin(),
//		[](double weight, double correction) { return weight += correction; }
//	);
//}
//
//	transform(training_set_outputs.begin(), training_set_outputs.end(),   // prediction error * sigmoid derivative
//		synaptic_weights0.begin(),
//		synaptic_weights0.begin(),
//		[](double t, double o) { return (t - o) * o * (1. - o); }
//	);
//	matMult(correction, training_set_inputsT, synaptic_weights0);                    // weight correction
//	transform(synaptic_weights0.begin(), synaptic_weights0.end(),           // update weights
//		correction.begin(),
//		synaptic_weights.begin(),
//		[](double weight, double correction) { return weight += correction; }
//	);
//}


//for j in xrange(60000) :


