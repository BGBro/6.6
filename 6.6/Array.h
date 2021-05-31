#pragma once
#include <stdexcept>

using namespace std;

template <class T, size_t N1, size_t N2>
class Array
{
public:
	// ����
	typedef T value_type;
	typedef T& reference;
	typedef const T& const_reference;
	typedef size_t size_type;
	// ����� ������
	static const size_type static_size = N2 - N1;
	Array(const T& t = T()); // �����������
	size_type size() const // ��������� ������
	{
		return static_size;
	}
	// ������ �� ��������
	reference operator [] (const size_type& i)
	{
		rangecheck(i);
		return elem[i - N1];
	}
	const_reference operator [] (const size_type& i) const
	{
		rangecheck(i);
		return elem[i - N1];
	}

	//friend ostream&  operator << <>(ostream& os, Array& A)
	//{
	//	for (int i = N1; i < N2; i++)
	//		os << A[i] << ' ';
	//	os << endl;
	//	return os;
	//}

	//friend istream& operator >> (istream& is, Array& A)
	//{
	//	cout << "Input " << A.size() << " elements of Array" << endl;
	//	for (int i = N1; i < N2; i++) {
	//		cout << "element[" << i << "] = ";
	//		is >> A[i];
	//	}
	//	return is;
	//}
private:
	// �������� �������
	void rangecheck(const size_type& i) const
	{
		if (i >= size() + N1)
			throw range_error("Array: index out of range!");
	}
	// ����-�����
	T elem[N2-N1];
};
// ��������� ������������
// - �� ���� � ���� � ����, 
// �� � ���������� �������
template <class T, size_t N1, size_t N2>
Array<T, N1, N2>::Array(const T& t)
{
	for (int i = N1; i < N2; i++)
		elem[i - N1] = t;
}
template <class T, size_t N1, size_t N2>
ostream& operator << <>(ostream& os, Array<T, N1, N2>& A)
{
	for (int i = N1; i < N2; i++)
		os << A[i] << ' ';
	os << endl;
	return os;
}
template <class T, size_t N1, size_t N2>
istream& operator >> (istream& is, Array<T, N1, N2>& A)
{
	cout << "Input " << A.size() << " elements of Array" << endl;
	for (int i = N1; i < N2; i++) {
		cout << "element[" << i << "] = ";
		is >> A[i];
	}
	return is;
}