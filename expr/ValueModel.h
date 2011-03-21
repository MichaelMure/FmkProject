#ifndef VALUEMODEL_H_
#define VALUEMODEL_H_

#include "Expression.h"

namespace expr {

	template <class T>
	class ValueModel : public Expression<T> {
	public:
		ValueModel(const T value);
		virtual ~ValueModel() {};

		void setValue(const T& value);
		T evaluate() const;

	private:
		T _value;
	};

	template<class T>
	ValueModel<T>::ValueModel(const T value)
	: _value(value)
	{
	}

	template<class T>
	void ValueModel<T>::setValue(const T& value)
	{
		this->_value = value;
	}

	template<class T>
	T ValueModel<T>::evaluate() const
	{
		return this->_value;
	}
}

#endif /* VALUEMODEL_H_ */
