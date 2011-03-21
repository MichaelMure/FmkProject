#ifndef NOTMINUS1_H_
#define NOTMINUS1_H_

#include "Not.h"

namespace op {
	template<class T>
	class NotMinus1 : public Not<T>{
	public:
		virtual T evaluate(const expr::Expression<T>* operand) const;
	};

	template<class T>
	T NotMinus1<T>::evaluate(const expr::Expression<T>* operand) const
	{
		return 1 - operand->evaluate();
	}

}
#endif /* NOTMINUS1_H_ */
