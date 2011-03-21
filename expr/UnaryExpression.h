#ifndef UNARYEXPRESSION_H_
#define UNARYEXPRESSION_H_

namespace expr {

	template<class T>
	class UnaryExpression {
	public:
		virtual T evaluate(const Expression<T>* operand) const =0;
	};

}

#endif /* UNARYEXPRESSION_H_ */
