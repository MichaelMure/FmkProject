#ifndef SUGENOTHEN_H_
#define SUGENOTHEN_H_

#include "NaryExpression.h"

namespace op {
	template<class T>
	class SugenoThen : public op::Then<T>{
	public:
		SugenoThen();
		virtual T evaluate(expr::Expression<T> * left, expr::Expression<T>* right) const;
		virtual T premiseValue();
	private:
		T premise;
	};

	template<class T>
	SugenoThen <T>::SugenoThen()
		: premise(0)
	{
	}

	template<class T>
	T SugenoThen <T>::evaluate(expr::Expression<T>* left, expr::Expression<T>* right) const
	{
		this->premise = left->evaluate();
		return this->premise * right->evaluate();
	}

	template<class T>
	T SugenoThen <T>::premiseValue()
	{
		return premise;
	}
}
#endif /* SUGENOTHEN_H_ */
