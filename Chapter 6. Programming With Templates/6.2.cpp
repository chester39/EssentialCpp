//
//  Essential C++
//      Stanley Lippman
//      Chen Chen @ January 12th, 2014
//

#include <fstream>
#include "Matrix.h"

using namespace std;

template <typename Type>
inline ostream &operator<<(ostream &os, const Matrix<Type> &mat)
{
	return mat.Print(os);
}

template <typename Type>
Matrix<Type> operator+(const Matrix<Type> &mat1, const Matrix<Type> &mat2)
{
	Matrix<Type> result(mat1);
	result += mat2;
	return result;
}

template <typename Type>
Matrix<Type> operator*(const Matrix<Type> &mat1, const Matrix<Type> &mat2)
{
	Matrix<Type> result(mat1.Rows(), mat2.Cols());
	for (int ix = 0; ix < mat1.Rows(); ++ix) {
		for (int jx = 0; jx < mat1.Cols(); ++jx) {
			result(ix, jx) = 0;
			for (int kx = 0; kx < mat1.Cols(); ++kx)
				result(ix, jx) += mat1(ix, kx) * mat2(kx, jx);
		}
	}
	return result;
}

template <typename Type>
Matrix<Type> &Matrix<Type>::operator=(const Matrix &temp)
{
	if (this != &temp) {
		myRows = temp.myRows;
		myColmuns = temp.myColmuns;
		int size = myColmuns * myRows;
		delete [] myMatrix;
		myMatrix = new Type[size];
		for (int i = 0; i < size; ++i)
			myMatrix[i] = temp.myMatrix[i];
	}
	return *this;
}

template <typename Type>
void Matrix<Type>::operator+=(const Matrix &mat)
{
	int matrixSize = Cols() * Rows();
	for (int ix = 0; ix < matrixSize; ++ix)
		(*(myMatrix + ix)) += (*(mat.myMatrix + ix));
}

template <typename Type>
ostream &Matrix<Type>::Print(ostream &os) const
{
	int matrixSize = Cols() * Rows();
	int col = Cols();
	for (int ix = 0; ix < matrixSize; ++ix) {
		if (ix % col == 0)
			os << endl;
		os << *(myMatrix + ix) << ' ';
	}
	os << endl;
	return os;
}

int main(int argc, char *argv[])
{
	ofstream writeFile("E:\\¼ÆËã»ú\\±à³Ì\\Essential C++\\EssentialC++\\EssentialC++\\TestFile_6.2.txt");
	if (!writeFile.is_open()) {
		cerr << "Sorry, the file fails to read!" << endl;
		return -1;
	}
	Matrix<float> identity(4, 4);
	writeFile << "Matrix identity: " << endl << identity << endl;
	float arr1[16] = {
		1.0, 0.0, 0.0, 0.0,
		0.0, 1.0, 0.0, 0.0,
		0.0, 0.0, 1.0, 0.0,
		0.0, 0.0, 0.0, 1.0
	};
	for (int i = 0, j = 0; i < 4; ++i)
		for (int k = 0; k < 4; ++k)
			identity(i, k) = arr1[j++];
	writeFile << "Matrix identity now: " << endl << identity << endl;
	Matrix<float> mat1(identity);
	writeFile << "Matrix 1: " << endl << mat1 << endl;
	Matrix<float> mat2(8, 12);
	writeFile << "Matrix 2 8*12: " << endl << mat2 << endl;
	mat2 = mat1;
	writeFile << "Matrix 2 now: " << endl << mat2 << endl;
	float arr2[16] = {
		1.3f, 0.4f, 2.6f, 8.2f,
		6.2f, 1.7f, 1.3f, 8.3f,
		4.2f, 7.4f, 2.7f, 1.9f,
		6.3f, 8.1f, 5.6f, 6.6f
	};
	Matrix<float> mat3(4, 4);
	for (int ix = 0, jx = 0; ix < 4; ++ix)
		for (int kx = 0; kx < 4; ++kx)
			identity(ix, kx) = arr2[jx++];
	writeFile << "Matrix 3: " << endl << mat3 << endl;
	Matrix<float> mat4 = mat3 * identity;
	writeFile << "Matrix 4: " << endl << mat4 << endl;
	Matrix<float> mat5 = mat3 + mat4;
	writeFile << "Matrix 5: " << endl << mat5 << endl;
	mat3 += mat4;
	writeFile << "Matrix 3 now: " << endl << mat3 << endl;
	return 0;
}