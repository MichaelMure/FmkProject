#ifndef FUZZYFACTORY_H_
#define FUZZYFACTORY_H_

#include "ExpressionFactory.h"
#include "UnaryShadowExpression.h"
#include "BinaryShadowExpression.h"
#include "op.h"

namespace expr {

	template <class T>
	class FuzzyFactory : public ExpressionFactory<T> {
	public:
		FuzzyFactory(op::Not<T> *opNot,
					op::And<T> *opAnd,
					op::Or<T> *opOr,
					op::Then<T> *opThen,
					op::Agg<T> *opAgg,
					op::Defuzz<T> *opDefuzz);

		Expression<T> newAnd(Expression<T> l, Expression<T> r);
		Expression<T> newOr(Expression<T> l, Expression<T> r);
		Expression<T> newThen(Expression<T> l, Expression<T> r);
		Expression<T> newAgg(Expression<T> l, Expression<T> r);
		Expression<T> newDefuzz(Expression<T> l, Expression<T> r);
		Expression<T> newNot(Expression<T> o);
		Expression<T> newIs(value::Is<T> is, Expression<T> o);

		void changeAnd(op::And<T> o);
		void changeOr(op::Or<T> o);
		void changeThen(op::Then<T> o);
		void changeAgg(op::Agg<T> o);
		void changeDefuzz(op::Defuzz<T> o);
		void changeNot(op::Not<T> o);

	private:
		BinaryShadowExpression<T> *opAnd, *opOr, *opThen, *opAgg, *opDefuzz;
		UnaryShadowExpression<T> *opNot;

	};

	template<class T>
	FuzzyFactory<T>::FuzzyFactory(op::Not<T> *opNot,
						op::And<T> *opAnd,
						op::Or<T> *opOr,
						op::Then<T> *opThen,
						op::Agg<T> *opAgg,
						op::Defuzz<T> *opDefuzz)
	: opNot(opNot), opAnd(opAnd), opOr(opOr), opThen(opThen), opAgg(opAgg), opDefuzz(opDefuzz)
	{
	}

	template<class T>
	Expression<T> FuzzyFactory<T>::newAnd(Expression<T> l, Expression<T> r)
	{
		return new BinaryExpressionModel<T>(opAnd, l, r);
	}

	template<class T>
	Expression<T> FuzzyFactory<T>::newOr(Expression<T> l, Expression<T> r)
	{
		return new BinaryExpressionModel<T>(opOr, l, r);
	}

	template<class T>
	Expression<T> FuzzyFactory<T>::newThen(Expression<T> l, Expression<T> r)
	{
		return new BinaryExpressionModel<T>(opThen, l, r);
	}

	template<class T>
	Expression<T> FuzzyFactory<T>::newAgg(Expression<T> l, Expression<T> r)
	{
		return new BinaryExpressionModel<T>(opAgg, l, r);
	}

	template<class T>
	Expression<T> FuzzyFactory<T>::newDefuzz(Expression<T> l, Expression<T> r)
	{
		return new BinaryExpressionModel<T>(opDefuzz, l, r);
	}

	template<class T>
	Expression<T> FuzzyFactory<T>::newNot(Expression<T> o)
	{
		return new UnaryExpressionModel<T>(opNot, o);
	}

	template<class T>
	Expression<T> FuzzyFactory<T>::newIs(value::Is<T> is, Expression<T> o)
	{
		return new UnaryExpressionModel<T>(is, o);
	}

	template<class T>
	void FuzzyFactory<T>::changeAnd(op::And<T> o)
	{

	}

	template<class T>
	void FuzzyFactory<T>::changeOr(op::Or<T> o)
	{

	}

	template<class T>
	void FuzzyFactory<T>::changeThen(op::Then<T> o)
	{

	}

	template<class T>
	void FuzzyFactory<T>::changeAgg(op::Agg<T> o)
	{

	}

	template<class T>
	void FuzzyFactory<T>::changeDefuzz(op::Defuzz<T> o)
	{

	}

	template<class T>
	void FuzzyFactory<T>::changeNot(op::Not<T> o)
	{

	}

}

#endif /* FUZZYFACTORY_H_ */
