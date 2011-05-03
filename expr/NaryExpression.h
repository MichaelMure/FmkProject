#ifndef NARYEXPRESSION_H_
#define NARYEXPRESSION_H_

#include "Expression.h"

namespace expr {

	template<class T>
	class NaryExpression {
	public:
		virtual T evaluate(std::vector<const Expression<T>*> operands) const =0;
	};

}

#endif /* NARYEXPRESSION_H_ */
