#ifndef AGGMAX_H_
#define AGGMAX_H_

#include "Agg.h"

namespace op {
	template<class T>
	class AggMax : public Agg<T>{
	public:
		virtual T evaluate(const expr::Expression<T>* left, const expr::Expression<T>* right) const;
	};

	template<class T>
	T AggMax <T>::evaluate(const expr::Expression<T>* left, const expr::Expression<T>* right) const
	{
		return std::max(left->evaluate(), right->evaluate());
	}

}
#endif /* AGGMAX_H_ */
