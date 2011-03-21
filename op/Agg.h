#ifndef AGG_H_
#define AGG_H_

#include "BinaryExpression.h"

namespace op {
	template<class T>
	class Agg  : public expr::BinaryExpression<T> {

	};

}
#endif /* AGG_H_ */
