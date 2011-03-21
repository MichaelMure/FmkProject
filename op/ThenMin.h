#ifndef THENMIN_H_
#define THENMIN_H_

#include "Then.h"

namespace op {
	template<class T>
	class ThenMin : public Then<T>{
	public:
		virtual T evaluate(const expr::Expression<T>* left, const expr::Expression<T>* right) const;
	};

	template<class T>
	T ThenMin <T>::evaluate(const expr::Expression<T>* left, const expr::Expression<T>* right) const
	{
		return std::min(left->evaluate(), right->evaluate());
	}

}
#endif /* THENMIN_H_ */
