#ifndef BINARYEXPRESSIONMODEL_H_
#define BINARYEXPRESSIONMODEL_H_

#include <exception>
#include "Expression.h"
#include "BinaryExpression.h"


namespace expr {

	template <class T>
	class BinaryExpressionModel : public BinaryExpression<T>, public Expression<T> {
	public:
		BinaryExpressionModel(Expression<T>* left, Expression<T>* right, BinaryExpression<T>* _operator);
		virtual ~BinaryExpressionModel() {};

		T evaluate() const;
		T evaluate(const Expression<T>* left, const Expression<T>* right) const;

	private:
		Expression<T> *_left, *_right;
		BinaryExpression<T>* _operator;
	};

	template<class T>
	BinaryExpressionModel<T>::BinaryExpressionModel(Expression<T>* left, Expression<T>* right, BinaryExpression<T>* _operator)
	: _left(left), _right(right), _operator(_operator)
	{
	}

	template<class T>
	T BinaryExpressionModel<T>::evaluate() const
	{
		if(this->_left != NULL && this->_right != NULL)
			return evaluate(this->_left, this->_right);

		throw(std::exception());
	}

	template<class T>
	T BinaryExpressionModel<T>::evaluate(const Expression<T>* left, const Expression<T>* right)const
	{
		if(this->_operator != NULL)
			return this->_operator->evaluate(left, right);

		throw(std::exception());
	}
}
#endif /* BINARYEXPRESSIONMODEL_H_ */
