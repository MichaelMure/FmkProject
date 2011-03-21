#ifndef IS_H_
#define IS_H_

#include "UnaryExpression.h"

namespace value {
	template<class T>
	class Is  : public expr::UnaryExpression<T> {

	};
}

#endif /* IS_H_ */
