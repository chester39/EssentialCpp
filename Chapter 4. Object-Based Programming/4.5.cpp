//
//  Essential C++
//      Stanley Lippman
//      Chen Chen @ December 23rd, 2014
//

#include "Matrix.h"

using namespace std;

inline ostream &operator<<(ostream &os, const Matrix &mat)
{
	return mat.Print(os);
}

Matrix operator+(const Matrix &mat1, const Matrix &mat2)
{
	Matrix result(mat1);
	result += mat2;
	return result;
}

Matrix operator*(const Matrix &mat1, const Matrix &mat2)
{
	Matrix result;
	for (int ix = 0; ix < mat1.Rows(); ++ix) {
		for (int jx = 0; jx < mat1.Cols(); ++jx) {
			result(ix, jx) = 0;
			for (int kx = 0; kx < mat1.Cols(); ++kx)
				result(ix, jx) += mat1(ix, kx) * mat2(kx, jx);
		}
	}
	return result;
}

void Matrix::operator+=(const Matrix &mat)
{
	for (int ix = 0; ix < 4; ++ix)
		for (int jx = 0; jx < 4; ++jx)
			myMatrix[ix][jx] += mat.myMatrix[ix][jx];
}

ostream &Matrix::Print(ostream &os) const
{
	int num = 0;
	for (int ix = 0; ix < 4; ++ix) {
		for (int jx = 0; jx < 4; ++jx, ++num) {
			if (num && !(num % 8))
				os << endl;
			os << myMatrix[ix][jx] << ' ';
		}
	}
	os << endl;
	return os;
}

Matrix::Matrix(const float *array)
{
	int arrayIndex = 0;
	for (int ix = 0; ix < 4; ++ix)
		for (int jx = 0; jx < 4; ++jx)
			myMatrix[ix][jx] = array[arrayIndex++];

}

Matrix::Matrix(float a11, float a12, float a13, float a14,
	float a21, float a22, float a23, float a24,
	float a31, float a32, float a33, float a34,
	float a41, float a42, float a43, float a44)
{
	myMatrix[0][0] = a11;
	myMatrix[0][1] = a12;
	myMatrix[0][2] = a13;
	myMatrix[0][3] = a14;
	myMatrix[1][0] = a21;
	myMatrix[1][1] = a22;
	myMatrix[1][2] = a23;
	myMatrix[1][3] = a24;
	myMatrix[2][0] = a31;
	myMatrix[2][1] = a32;
	myMatrix[2][2] = a33;
	myMatrix[2][3] = a34;
	myMatrix[3][0] = a41;
	myMatrix[3][1] = a42;
	myMatrix[3][2] = a43;
	myMatrix[3][3] = a44;
}

int main(int argc, char *argv[])
{
	Matrix mat1;
	cout << "Matrix 1: " << endl << mat1 << endl;
	float arr1[16] = {
		1.0, 0.0, 0.0, 0.0,
		0.0, 1.0, 0.0, 0.0,
		0.0, 0.0, 1.0, 0.0,
		0.0, 0.0, 0.0, 1.0
	};
	Matrix identity(arr1);
	cout << "Matrix identity: " << endl << identity << endl;
	Matrix mat2(identity);
	mat1 = identity;
	cout << "Matrix 2: " << endl << mat2 << endl;
	cout << "Matrix 1: " << endl << mat1 << endl;
	float arr2[16] = {
		1.3f, 0.4f, 2.6f, 8.2f,
		6.2f, 1.7f, 1.3f, 8.3f,
		4.2f, 7.4f, 2.7f, 1.9f,
		6.3f, 8.1f, 5.6f, 6.6f
	};
	Matrix mat3(arr2);
	cout << "Matrix 3: " << endl << mat3 << endl;
	Matrix mat4 = mat3 * identity;
	cout << "Matrix 4: " << endl << mat4 << endl;
	Matrix mat5 = mat3 + mat4;
	cout << "Matrix 5: " << endl << mat5 << endl;
	mat3 += mat4;
	cout << "Matrix 3: " << endl << mat3 << endl;
	return 0;
}