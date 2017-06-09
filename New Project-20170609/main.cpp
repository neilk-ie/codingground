#include <iostream>
#include <cmath>
using namespace std;
void duplicate (double a[][3],double b[][3]);
void transpose(double a[][3], double b[][3]);
void multiply(double a[][3], double b);
void print(double a[][3]);
void matrix_(double a[][3], double b[], double c[]);
void show_matrix(string, double*);

int main()
{
    int debug = 1;
	double inverse[3][3], determinant, inverse1[3][3], correct[3];
	double matrix[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
	double answer[3] = {6, 15, 24};
	
	//cout << "Enter three simultaneous equations in the form of the coefficients of the x, y and z variables followed by their totals" << endl;
	//cin >> matrix[0][0] >> matrix[0][1] >> matrix[0][2] >> answer[0];
	//cin >> matrix[1][0] >> matrix[1][1] >> matrix[1][2] >> answer[1];
	//cin >> matrix[2][0] >> matrix[2][1] >> matrix[2][2] >> answer[2];

    if(debug) { show_matrix("matrix[0]", matrix[0]); };
    if(debug) { show_matrix("matrix[1]", matrix[1]); };
    if(debug) { show_matrix("matrix[2]", matrix[2]); };
    if(debug) { show_matrix("answer", answer); };
    

	inverse[0][0] = matrix[1][1] * matrix[2][2] - matrix[1][2] * matrix[2][1];
	inverse[0][1] = matrix[1][0] * matrix[2][2] - matrix[1][2] * matrix[2][0];
	inverse[0][2] = matrix[1][0] * matrix[2][1] - matrix[1][1] * matrix[2][0];
	inverse[1][0] = matrix[0][1] * matrix[2][2] - matrix[0][2] * matrix[2][1];
	inverse[1][1] = matrix[0][0] * matrix[2][2] - matrix[0][2] * matrix[2][0];
	inverse[1][2] = matrix[0][0] * matrix[2][1] - matrix[0][1] * matrix[2][0];
	inverse[2][0] = matrix[0][1] * matrix[1][2] - matrix[1][1] * matrix[0][2];
	inverse[2][1] = matrix[0][0] * matrix[1][2] - matrix[1][0] * matrix[0][2];
	inverse[2][2] = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];

    if(debug) { show_matrix("inverse[0]", inverse[0]); };
    if(debug) { show_matrix("inverse[1]", inverse[1]); };
    if(debug) { show_matrix("inverse[2]", inverse[2]); };

	determinant = (matrix[0][0] * matrix[1][1] * matrix[2][2] +
	               matrix[0][1] * matrix[1][2] * matrix[2][0] +
	               matrix[0][2] * matrix[1][0] * matrix[2][1]) -
	              (matrix[0][2] * matrix[1][1] * matrix[2][0] +
	               matrix[0][0] * matrix[1][2] * matrix[2][1] +
	               matrix[0][1] * matrix[1][0] * matrix[2][2]);

    if(debug) { cout << "determinant = " << determinant << endl; };


	inverse[0][1] = -inverse[0][1];
	inverse[1][0] = -inverse[1][0];
	inverse[1][2] = -inverse[1][2];
	inverse[2][1] = -inverse[2][1];


	duplicate(inverse1, inverse);
	transpose(inverse, inverse1);
	multiply(inverse, determinant);
	matrix_(inverse, answer, correct);

	cout << "  x =  " << correct[0] << "  y  =  " << correct[1] << "  z  =  " << correct[2] << endl;

    return 0;
}

void show_matrix(string name, double* m) {
    cout << name << " = " << "[" << m[0] << ", " << m[1] << ", " << m[2] << "]" << endl;
}

void duplicate(double a[][3], double b[][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int k = 0; k < 3; k++)
			a[i][k] = b[i][k];
	}
}

void transpose(double a[][3], double b[][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int k = 0; k < 3; k++)
			a[k][i] = b[i][k];
	}
}

void multiply(double a[][3], double b)
{
	for (int i = 0; i < 3; i++)
	{
		for (int k = 0; k < 3; k++)
			a[i][k] = a[i][k]/b;
	}
}

void print(double a[][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int k = 0; k < 3; k++)
			cout << a[i][k] << "  ";

		cout << endl;

	}
}

void matrix_(double a[][3], double b[], double c[])
{
	for (int i = 0; i < 3; i++)
	{
		c[i] = a[i][0] * b[0] + a[i][1] * b[1] + a[i][2] * b[2];

	}
}
