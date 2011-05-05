#ifndef NARYEXPRESSIONMODEL_H_
#define NARYEXPRESSIONMODEL_H_

#include <exception>
#include "Expression.h"
#include "NaryExpression.h"


namespace expr {

	template <class T>
	class NaryExpressionModel : public NaryExpression<T>, public Expression<T> {
	public:
		NaryExpressionModel(std::vector<const Expression<T>*> *operands, NaryExpression<T>* _operator);
		virtual ~NaryExpressionModel() {};

		T evaluate() const;
		T evaluate(std::vector<const Expression<T>*> *operands) const;

	private:
		std::vector<const Expression<T>*> *_operands;
		NaryExpression<T> *_operator;
	};

	template<class T>
	NaryExpressionModel<T>::NaryExpressionModel(std::vector<const Expression<T>*> *_operands, NaryExpression<T>* _operator)
	: _operands(_operands), _operator(_operator)
	{
	}

	template<class T>
	T NaryExpressionModel<T>::evaluate() const
	{
		if(this->_operands != NULL)
			return this->evaluate(this->_operands);

		throw(std::exception());
	}

	template<class T>
	T NaryExpressionModel<T>::evaluate(std::vector<const Expression<T>*> *operands) const
	{
		if(this->_operator != NULL)
			return this->_operator->evaluate(operands);

		throw(std::exception());
	}
}

#endif /* NARYEXPRESSIONMODEL_H_ */
