#ifndef SUGENOTHEN_H_
#define SUGENOTHEN_H_

#include "Then.h"

namespace op {
	template<class T>
	class SugenoThen : public Then<T> {
	public:
		SugenoThen();
		virtual T evaluate(const expr::Expression<T> * left, const expr::Expression<T>* right) const;
		virtual T premiseValue();
	private:
		mutable T premise;
	};

	template<class T>
	SugenoThen <T>::SugenoThen()
		: premise(0)
	{
	}

	template<class T>
	T SugenoThen <T>::evaluate(const expr::Expression<T>* left, const expr::Expression<T>* right) const
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
