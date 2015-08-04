//
//  Essential C++
//      Stanley Lippman
//      Chen Chen @ December 29th, 2014
//
 
#ifndef EXAMPLE_H_
#define EXAMPLE_H_

template <typename Type>
class Example
{
public:
	Example(const Type &min, const Type &max);
	Example(const Type *array, int size);
	Type opeartor[](int index);
	bool opeartor==(const Example &) const;
	bool Insert(const Type *, int);
	bool Insert(Type &);
	Type Min() const
	{
		return _min;
	}
	Type Max() const
	{
		return _max;
	}
	void Min(const Type &);
	void Max(const Type &);
	int Count(const Type &value) const;

private:
	int _size;
	Type *parray;
	Type _min;
	Type _max;
};

#endif