#ifndef BINARYEXPRESSION_H_
#define BINARYEXPRESSION_H_

#include "Expression.h"

namespace expr {

	template<class T>
	class BinaryExpression {
	public:
		virtual T evaluate(const Expression<T>* left, const Expression<T>* right) const =0;
	};

}

#endif /* BINARYEXPRESSION_H_ */
