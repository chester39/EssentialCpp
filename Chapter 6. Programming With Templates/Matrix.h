//
//  Essential C++
//      Stanley Lippman
//      Chen Chen @ January 12th, 2014
//

#ifndef MATRIX_H_
#define MATRIX_H_

#include <iostream>

using namespace std;

template <typename Type>
class Matrix
{
	friend Matrix<Type> operator+(const Matrix<Type> &, const Matrix<Type> &);
	friend Matrix<Type> operator*(const Matrix<Type> &, const Matrix<Type> &);

public:
	Matrix(const Matrix &temp)
	{
		myRows = temp.myRows;
		myColmuns = temp.myColmuns;
		int size = myColmuns * myRows;
		myMatrix = new Type[size];
		for (int i = 0; i < size; ++i)
			myMatrix[i] = temp.myMatrix[i];
	}
	Matrix(int rows, int colmuns) : myRows(rows), myColmuns(colmuns)
	{
		int size = myColmuns * myColmuns;
		myMatrix = new Type[size];
		for (int i = 0; i < size; ++i)
			myMatrix[i] = Type();
	}
	~Matrix()
	{
		delete [] myMatrix;
	}
	int Rows() const
	{
		return myRows;
	}
	int Cols() const
	{
		return myColmuns;
	}
	Type &operator()(int row, int colmun)
	{
		return myMatrix[row * Cols() + colmun];
	}
	const Type &operator()(int row, int colmun) const
	{
		return myMatrix[row * Cols() + colmun];
	}
	bool SameSize(const Matrix &mat) const
	{
		return Rows() == mat.Rows() && Cols() == mat.Cols();
	}
	bool Comfortable(const Matrix &mat) const
	{
		return Cols() == mat.Rows;
	}
	Matrix &operator=(const Matrix &);
	void operator+=(const Matrix &);
	ostream &Print(ostream &) const;

protected:
	int myRows;
	int myColmuns;
	Type *myMatrix;
};

#endif