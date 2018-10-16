#pragma once

template <class T>

class TVector
{
	protected:
	 T* vector;
	 int length;
	public:
		TVector();
		TVector(TVector &A);
		TVector(T* s, int _length);
		~TVector();

		int GetLength();
		TVector<T>& DeleteVector();
		TVector<T>& Resize(int n);

		TVector<T> operator+(TVector<T> &A);
		TVector<T> operator-(TVector<T> &A);
		T operator* (TVector<T> &A);
		TVector<T> operator*(T a);
		TVector<T> operator/(T a);
		TVector<T>& operator=(TVector<T> &A);
		T& operator[](int i);

		template <class T>
		friend std::istream& operator >> (std::istream& A, TVector<T>& B);
		template <class T>
		friend std::ostream& operator << (std::ostream& A, TVector<T>& B);
}
// ---------------------------------------------------------------------------
template <class T>
TVector<T>::TVector()
{
  vector = 0;
  length = 0;
}
// ---------------------------------------------------------------------------
template <class T>
TVector<T>::TVector(TVector &A)
{
  length = A.length;
  if (length != 0)
  {
    vector = new T [length];
    for (int i = 0; i < length; i++)
      vector[i] = A.vector[i];
  }
  else
    vector = 0;
}
// ---------------------------------------------------------------------------
template <class T>
TVector<T>::TVector(T* s, int _length)
{
  dlina = _length;
  vector = new T [length];
  for (int i = 0; i < length; i++)
    vector[i] = s[i];
}
// ---------------------------------------------------------------------------
template <class T>
TVector<T>::~TVector()
{
  length = 0;
  if (vector != 0)
    delete []vector;
}
// ---------------------------------------------------------------------------
template <class T>
int TVector<T>::GetLength()
{
  return length;
}
// ---------------------------------------------------------------------------
template <class T>
TVector<T>& TVector<T>::DeleteVector()
{
  length = 0; 
  if (vector != 0)
    delete []vector;
  return *this;
}
// ---------------------------------------------------------------------------
template <class T>
TVector<T>& TVector<T>::Resize(int n)
{
	if ((n == length) || (n < 0))
		return *this;
	T* buff = 0;
	if (length != 0)
	{
		buff = new T [length];
		for (int i = 0; i < length; i++)
			buff[i] = vector[i];
		delete []vector;
	}
	if (n > 0)
	{
		
		vector = new T [n];
		for (int i = 0; i < min(n, length); i++)
			vector[i] = buff[i];
		if (length < n)
		for (int i = length; i < n; i++)
			vector[i] = 0;
		length = n;
		delete []buff;
	}
	else 
	{
		vector = 0;
		length = 0;
	}
	return *this;
	}
  // ---------------------------------------------------------------------------
  template <class T>
  TVector<T> TVector<T>::operator+(TVector<T> &A)
  {
    TVector<T> S;
    if (length == A.length)
    {
      if (length == 0)
        S.vector = 0;
      else
      {
        S.length = length;
        S.vector = new T[length];
        for (int i = 0; i < length; i++)
          S.vector[i] = vector[i] + A.vector[i];
      }
    }
    else
      throw 1;
    return S;
  }
  // ---------------------------------------------------------------------------
  template <class T>
  TVector<T> TVector<T>::operator-(TVector<T> &A)
  {
    TVector<T> S;
    if (length == A.length)
    {
      if (length == 0)
        S.vector = 0;
      else
      {
        S.length = length;
        S.vector = new T[length];
        for (int i = 0; i < length; i++)
          S.vector[i] = vector[i] - A.vector[i];
      }
    }
    else
      throw 1;
    return S;
  }
  // ---------------------------------------------------------------------------
  template <class T>
  T TVector<T>::operator*(TVector<T> &A)
  {
    T sum = 0;
    if (length == A.length)
    {
      if (length == 0)
        return sum;
      else
      {
        for (int i = 0; i < length; i++)
          sum += vector[i] * A.vector[i];
      }
    }
    else
      throw 1;
    return sum;
  }
  // ---------------------------------------------------------------------------
  template <class T>
  TVector<T> TVector<T>::operator*(T a)
  {
    TVector<T> S;
    if (length == 0)
      S.vector = 0;
    else
    {
      S.length = length;
      S.vector = new T[length];
      for (int i = 0; i < length; i++)
        S.vector[i] = vector[i] * a;
    }
    return S;
  }
  // ---------------------------------------------------------------------------
  template <class T>
  TVector<T> TVector<T>::operator/(T a)
  {
    TVector<T> S;
    if (a != 0)
    {
      if (length == 0)
        S.vector = 0;
      else
      {
        S.length = length;
        S.vector = new T[length];
        for (int i = 0; i < length; i++)
          S.vector[i] = vector[i] / a;
      }
    }
    return S;
  }
  // ---------------------------------------------------------------------------
  template <class T>
  TVector<T>& TVector<T>::operator=(TVector<T> &A)
  {
    if (this != &A)
    {
      length = A.length;
      if (length != 0)
      {
        if (vector != 0)
          delete []vector;
        vector = new T [length];
        for (int i = 0; i < length; i++)
          vector[i] = A.vector [i];
      }
      else
      {
        if (vector != 0)
          delete []vector;
        vector = 0;
      }
    }
    return *this;
  }
  // ---------------------------------------------------------------------------
  template <class T>
  T& TVector<T>::operator[](int i)
  {
    if (i >= 0 && i <= length)
      return vector[i];
    throw 1;
  }
  // ---------------------------------------------------------------------------
  template <class T>
  std::istream& operator>>(std::istream &A, TVector<T> &B)
  {
    std::cout << "Vvedite Vector:\nDlina: "; 
	A >> B.length;
    B.vector = new T [B.length];
	std::cout << "Znachenie:\n"; 
    for (int i = 0; i < B.length; i++)
    {
      A >> B.vector[i];
    }
    return A;
  }
  // ---------------------------------------------------------------------------
  template <class T>
  std::ostream& operator<<(std::ostream &A, TVector<T> &B)
  {
    A << "dlina = "<<B.length << "\n";
    for (int i = 0; i < B.length; i++)
      A << B.vector[i] << " ";
    return A;
  }
  // ---------------------------------------------------------------------------