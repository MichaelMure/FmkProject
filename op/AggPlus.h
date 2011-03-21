#ifndef AGGPLUS_H_
#define AGGPLUS_H_

#include "Agg.h"

namespace op {
	template<class T>
	class AggPlus : public Agg<T>{
	public:
		virtual T evaluate(const expr::Expression<T>* left, const expr::Expression<T>* right) const;
	};

	template<class T>
	T AggPlus <T>::evaluate(const expr::Expression<T>* left, const expr::Expression<T>* right) const
	{
		return left->evaluate() + right->evaluate();
	}

}
#endif /* AGGPLUS_H_ */
