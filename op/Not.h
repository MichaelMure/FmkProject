#ifndef NOT_H_
#define NOT_H_

#include "UnaryExpression.h"

namespace op {
	template<class T>
	class Not  : public expr::UnaryExpression<T> {

	};

}
#endif /* NOT_H_ */
