#ifndef ORMAX_H_
#define ORMAX_H_

#include "Or.h"

namespace op {
	template<class T>
	class OrMax : public Or<T>{
	public:
		virtual T evaluate(const expr::Expression<T>* left, const expr::Expression<T>* right) const;
	};

	template<class T>
	T OrMax <T>::evaluate(const expr::Expression<T>* left, const expr::Expression<T>* right) const
	{
		return std::max(left->evaluate(), right->evaluate());
	}

}
#endif /* ORMAX_H_ */
