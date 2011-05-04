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
		virtual T evaluate(expr::Expression<T> *, expr::Expression<T> *) const;
		virtual T premiseValue();
	private:
		T premiseValue;
	};

	template<class T>
	T SugenoThen <T>::evaluate(expr::Expression<T> *left, expr::Expression<T> *right) const
	{

	}

	template<class T>
	T SugenoThen <T>::premiseValue()
	{
		return premiseValue;
	}
}
#endif /* SUGENOTHEN_H_ */
