#ifndef SUGENODEFUZZ_H_
#define SUGENODEFUZZ_H_

#include "NaryExpression.h"
#include "SugenoThen.h"

namespace op {
	template<class T>
	class SugenoDefuzz : public expr::NaryExpression<T>{
	public:
		virtual T evaluate(std::vector<const expr::Expression<T>*> *operands) const;
	};

	template<class T>
	T SugenoDefuzz <T>::evaluate(std::vector<const expr::Expression<T>*> *operands) const
	{
		typename std::vector<const expr::Expression<T>*>::const_iterator it = operands->begin();
		T num = 0;
		T denum = 0;

		for(; it != operands->end(); it++)
		{
			num += (*it)->evaluate();
		}

		for(it = operands->begin(); it != operands->end(); it++)
		{
			denum += ((SugenoThen<T>*) (*it))->premiseValue();
		}

		if(denum != 0)
			return num/denum;
		else
			return 0;
	}

}
#endif /* SUGENODEFUZZ_H_ */
