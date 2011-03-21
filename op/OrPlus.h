#ifndef ORPLUS_H_
#define ORPLUS_H_

#include "Or.h"

namespace op {
	template<class T>
	class OrPlus : public Or<T>{
	public:
		virtual T evaluate(const expr::Expression<T>* left, const expr::Expression<T>* right) const;
	};

	template<class T>
	T OrPlus<T>::evaluate(const expr::Expression<T>* left, const expr::Expression<T>* right) const
	{
		return left->evaluate() + right->evaluate();
	}

}
#endif /* ORPLUS_H_ */
