#pragma once
template <class T>
class ProtectedValue
{
private:
	T value;
	unsigned code;
public:


	ProtectedValue<T>();
	ProtectedValue<T>& operator=(const ProtectedValue<T>& value);
	ProtectedValue(unsigned code, T value);

	T& getValue(unsigned code) const;

	int getCode() const;

};

template <class T>
ProtectedValue<T>::ProtectedValue()
{

}

template <class T>
ProtectedValue<T>::ProtectedValue(unsigned code, T value)
{
	this->code = code;
	this->value = value;
}

template <class T>
T& ProtectedValue<T>::getValue(unsigned code) const
{
	if (this->code == code)
	{
		return value;
	}
}

template <class T>
int ProtectedValue<T>::getCode() const
{
	return this->code;
}

template <class T>
ProtectedValue<T>& ProtectedValue<T>::operator=(const ProtectedValue<T>& value)
{
	if (this!=&value)
	{
		this->value = value.value;
		this->code = value.code;
	}

	return *this;
}
