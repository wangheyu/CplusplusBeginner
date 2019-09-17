#ifndef __CRAZYFISH_MATRIX__
#define __CRAZYFISH_MATRIX__
 
#include <iostream>

std::vector<int>

std::list<double>


namespace CRAZYFISH{

    template<typename T> class Matrix;
    
    template<typename T>
    class Matrix
    {
    private:
	T *data;
	int row;
	int col;
    public:
	Matrix(){};
	Matrix(int _row);
	Matrix(int _row, int _col);
	Matrix(Matrix<T> &_obj);
	T get(int _i, int _j) const;
	~Matrix();
    };

    template<typename T>
    Matrix<T>::Matrix(int _row) : row(_row), col(_row)
    {
	int N = row * col;
	data = new T[col * row];
	for (int i = 0; i < N; i++ )
	    data[i] = i;
    };

    template<typename T> 
    T Matrix<T>::get(int _i, int _j) const
    {
	return data[_j * row + _i];
    };

    template<typename T>
    Matrix<T>::~Matrix()
    {
	delete(data);
    };
}

#else
\\Do nothing.
#endif
