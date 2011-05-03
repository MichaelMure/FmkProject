#ifndef EXPRESSIONFACTORY_H_
#define EXPRESSIONFACTORY_H_

#include "value.h"
#include "expr.h"
#include <set>

namespace expr {

	template <class T>
	class ExpressionFactory {
	public:
		ExpressionFactory();
		virtual ~ExpressionFactory();

		Expression<T>* Hold(Expression<T>*);
		ValueModel<T>* newValue(value::Is<T>*);
		UnaryExpressionModel<T>* newUnary(UnaryExpression<T>* ope, Expression<T>* o);
		BinaryExpressionModel<T>* newBinary(BinaryExpression<T>* ope, Expression<T>* l, Expression<T>* r);
		NaryExpressionModel<T>* newNary(NaryExpression<T>* ope, std::vector<Expression<T>*> operands);

	private:
		std::set<Expression<T>* > *memory;
	};

	template<class T>
	ExpressionFactory<T>::ExpressionFactory()
	: memory(new std::set<Expression<T>* >)
	{
	}

	template<class T>
	ExpressionFactory<T>::~ExpressionFactory() {
		delete this->memory;
	}

	template<class T>
	Expression<T>* ExpressionFactory<T>::Hold(Expression<T>* e)
	{
		this->memory->insert(e);
		return e;
	}

	template<class T>
	ValueModel<T>* ExpressionFactory<T>::newValue(value::Is<T>* v)
	{
		return new ValueModel<T>(v);
	}

	template<class T>
	UnaryExpressionModel<T>* ExpressionFactory<T>::newUnary(UnaryExpression<T>* ope, Expression<T>* o)
	{
		return new UnaryExpressionModel<T>(ope, o);
	}

	template<class T>
	BinaryExpressionModel<T>* ExpressionFactory<T>::newBinary(BinaryExpression<T>* ope, Expression<T>* l, Expression<T>* r)
	{
		return new BinaryExpressionModel<T>(ope, l, r);
	}

	template<class T>
	NaryExpressionModel<T>* ExpressionFactory<T>::newNary(NaryExpression<T>* ope, std::vector<Expression<T>*> operands)
	{
		return new NaryExpressionModel<T>(ope, operands);
	}
}

#endif /* EXPRESSIONFACTORY_H_ */
