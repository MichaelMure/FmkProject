#ifndef SUGENOCONCLUSION_H_
#define SUGENOCONCLUSION_H_

#include <exception>
#include "NaryExpression.h"

namespace op {
	template<class T>
	class SugenoConclusion : public expr::NaryExpression<T>{
	public:
		SugenoConclusion(std::vector<T> coef);
		virtual T evaluate(std::vector<expr::Expression<T>*> *operands) const;
	private:
		std::vector<T> coeff;
	};

	template<class T>
	SugenoConclusion <T>::SugenoConclusion(std::vector<T> _coeff)
	: coeff(_coeff)
	{
	}

	template<class T>
	T SugenoConclusion <T>::evaluate(std::vector<expr::Expression<T>*> *operands) const
	{
		typename std::vector<T>::iterator itcoef = this->coeff.begin();
		typename std::vector<expr::Expression<T>*>::iterator itexpr = operands->begin();
		T z = 0;

		for(;itexpr != operands.end() && itcoef != this->coeff.end();
		    itexpr++, itcoef++)
		{
			T eval = (*itexpr)->evaluate();
			z += *itcoef * eval;
		}

		if(itexpr != operands.end())
			throw(std::exception());

		return z;
	}
}
#endif /* SUGENOCONCLUSION_H_ */
