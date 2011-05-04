/*
 * SugenoConclusion.h
 *
 *  Created on: 4 mai 2011
 *      Author: chtitux
 */

#ifndef SUGENOCONCLUSION_H_
#define SUGENOCONCLUSION_H_

#include "NaryExpression.h"

namespace op {
	template<class T>
	class SugenoConclusion : public expr::NaryExpression<T>{
	public:
		SugenoConclusion(std::vector<T>);
		virtual T evaluate(std::vector<expr::Expression<T>*> operands) const;
	private:
		std::vector<T> coeff;
	};

	template<class T>
	SugenoConclusion <T>::SugenoConclusion(std::vector<T> _coeff):
		coeff(_coeff) {}

	template<class T>
	T SugenoConclusion <T>::evaluate(std::vector<expr::Expression<T>*> operands) const
	{
		// TODO Coder SugenoConclusion::evaluate()
	}
}
#endif /* SUGENOCONCLUSION_H_ */
