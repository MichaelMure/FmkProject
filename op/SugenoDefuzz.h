#ifndef SUGENODEFUZZ_H_
#define SUGENODEFUZZ_H_

#include "NaryExpression.h"

namespace op {
	template<class T>
	class SugenoDefuzz : public expr::NaryExpression<T>{
	public:
		virtual T evaluate(std::vector<expr::Expression<T>*> operands) const;
	};

	template<class T>
	T SugenoDefuzz <T>::evaluate(std::vector<expr::Expression<T>*> operands) const
	{
		//TODO
		return 0;
	}

}
#endif /* SUGENODEFUZZ_H_ */
