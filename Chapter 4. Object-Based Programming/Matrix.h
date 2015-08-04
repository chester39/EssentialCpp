//
//  Essential C++
//      Stanley Lippman
//      Chen Chen @ December 23rd, 2014
//

#ifndef MATRIX_H_
#define MATRIX_H_

#include <iostream>

using namespace std;

class Matrix
{
	friend Matrix operator+(const Matrix &, const Matrix &);
	friend Matrix operator*(const Matrix &, const Matrix &);

public:
	Matrix(const float *);
	Matrix(float = 0.0, float = 0.0, float = 0.0, float = 0.0,
		float = 0.0, float = 0.0, float = 0.0, float = 0.0,
		float = 0.0, float = 0.0, float = 0.0, float = 0.0,
		float = 0.0, float = 0.0, float = 0.0, float = 0.0);
	int Rows() const
	{
		return 4;
	}
	int Cols() const
	{
		return 4;
	}
	float operator()(int row, int colmun) const
	{
		return myMatrix[row][colmun];
	}
	float &operator()(int row, int colmun)
	{
		return myMatrix[row][colmun];
	}
	void operator+=(const Matrix &);
	ostream &Print(ostream &) const;

private:
	float myMatrix[4][4];
};

#endif