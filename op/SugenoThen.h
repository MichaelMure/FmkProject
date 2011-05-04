/*
 * SugenoThen.h
 *
 *  Created on: 4 mai 2011
 *      Author: chtitux
 */

#ifndef SUGENOTHEN_H_
#define SUGENOTHEN_H_

#include "NaryExpression.h"

namespace op {
	template<class T>
	class SugenoThen : public op::Then<T>{
	public:
		SugenoThen(T);
		virtual T evaluate(expr::Expression<T> * left, expr::Expression<T>* right) const;
		virtual T premiseValue();
	private:
		T premValue;
	};

	template<class T>
	SugenoThen <T>::SugenoThen(T _premiseValue):
		premValue(_premiseValue) {}

	template<class T>
	T SugenoThen <T>::evaluate(expr::Expression<T>* left, expr::Expression<T>* right) const
	{
		// TODO : Coder evaluate de Sugeno
	}

	template<class T>
	T SugenoThen <T>::premiseValue()
	{
		return premValue;
	}
}
#endif /* SUGENOTHEN_H_ */
