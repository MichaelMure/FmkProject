#ifndef ANDMULT_H_
#define ANDMULT_H_

#include "And.h"

namespace op {
	template<class T>
	class AndMult : public And<T>{
	public:
		virtual T evaluate(const expr::Expression<T>* left, const expr::Expression<T>* right) const;
	};

	template<class T>
	T AndMult<T>::evaluate(const expr::Expression<T>* left, const expr::Expression<T>* right) const
	{
		return left->evaluate() * right->evaluate();
	}

}
#endif /* ANDMULT_H_ */
