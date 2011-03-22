#ifndef UNARYEXPRESSIONMODEL_H_
#define UNARYEXPRESSIONMODEL_H_

#include <exception>
#include "UnaryExpression.h"
#include "Expression.h"

namespace expr {

	template <class T>
	class UnaryExpressionModel : public UnaryExpression<T>, public Expression<T> {
	public:
		UnaryExpressionModel(Expression<T>* operand, UnaryExpression<T>* _operator);
		virtual ~UnaryExpressionModel() {};

		T evaluate() const;
		T evaluate(const Expression<T>* operand) const;

	private:
		Expression<T>* _operand;
		UnaryExpression<T>* _operator;
	};

	template<class T>
	UnaryExpressionModel<T>::UnaryExpressionModel(Expression<T>* operand, UnaryExpression<T>* _operator)
	: _operand(operand), _operator(_operator)
	{
	}

	template<class T>
	T UnaryExpressionModel<T>::evaluate() const
	{
		if(this->_operand != NULL)
			return evaluate(this->_operand);

		throw(std::exception());
	}

	template<class T>
	T UnaryExpressionModel<T>::evaluate(const Expression<T>* operand)const
	{
		if(this->_operator != NULL)
			return this->_operator->evaluate(operand);

		throw(std::exception());
	}
}
#endif /* UNARYEXPRESSIONMODEL_H_ */
