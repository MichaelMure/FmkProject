#ifndef DEFUZZ_H_
#define DEFUZZ_H_

#include "BinaryExpression.h"

namespace op {
	template<class T>
	class Defuzz  : public expr::BinaryExpression<T> {

	};

}
#endif /* DEFUZZ_H_ */
