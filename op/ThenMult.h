#ifndef THENMULT_H_
#define THENMULT_H_

#include "Then.h"

namespace op {
	template<class T>
	class ThenMult : public Then<T>{
	public:
		virtual T evaluate(const expr::Expression<T>* left, const expr::Expression<T>* right) const;
	};

	template<class T>
	T ThenMult <T>::evaluate(const expr::Expression<T>* left, const expr::Expression<T>* right) const
	{
		return left->evaluate() * right->evaluate();
	}

}
#endif /* THENMULT_H_ */
