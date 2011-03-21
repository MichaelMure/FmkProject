#ifndef ANDMIN_H_
#define ANDMIN_H_

#include "And.h"

namespace op {
	template<class T>
	class AndMin : public And<T>{
	public:
		virtual T evaluate(const expr::Expression<T>* left, const expr::Expression<T>* right) const;
	};

	template<class T>
	T AndMin<T>::evaluate(const expr::Expression<T>* left, const expr::Expression<T>* right) const
	{
		return std::min(left->evaluate(),right->evaluate());
	}

}
#endif /* ANDMIN_H_ */
