#ifndef FUZZYFACTORY_H_
#define FUZZYFACTORY_H_

#include "ExpressionFactory.h"
#include "UnaryShadowExpression.h"
#include "BinaryShadowExpression.h"

namespace expr {

	template <class T>
	class FuzzyFactory : public ExpressionFactory {
	public:
		FuzzyFactory(Not *opNot, And *opAnd, Or *opOr, Then *opThen, Agg *opAgg, Defuzz *opDefuzz);

		Expression<T> newAnd(Expression<T> l, Expression<T> r);
		Expression<T> newOr(Expression<T> l, Expression<T> r);
		Expression<T> newThen(Expression<T> l, Expression<T> r);
		Expression<T> newAgg(Expression<T> l, Expression<T> r);
		Expression<T> newDefuzz(Expression<T> l, Expression<T> r);
		Expression<T> newNot(Expression<T> o);
		Expression<T> newIs(Is<T> is, Expression<T> o);

		void changeAnd(And o);
		void changeOr(Or o);
		void changeThen(Then o);
		void changeAgg(Agg o);
		void changeDefuzz(Defuzz o);
		void changeNot(Not o);

	private:
		BinaryShadowExpression *opAnd, *opOr, *opThen, *opAgg, *opDefuzz;
		UnaryShadowExpression *opNot;

	};

	template<class T>
	FuzzyFactory::FuzzyFactory(Not *opNot, And *opAnd, Or *opOr, Then *opThen, Agg *opAgg, Defuzz *opDefuzz)
	: opNot(opNot), opAnd(opAnd), opOr(opOr), opThen(opThen), opAgg(opAgg), opDefuzz(opDefuzz)
	{
	}

	template<class T>
	Expression<T> FuzzyFactory::newAnd(Expression<T> l, Expression<T> r)
	{
		return new BinaryExpressionModel(opAnd, l, r);
	}

	template<class T>
	Expression<T> FuzzyFactory::newOr(Expression<T> l, Expression<T> r)
	{
		return new BinaryExpressionModel(opOr, l, r);
	}

	template<class T>
	Expression<T> FuzzyFactory::newThen(Expression<T> l, Expression<T> r)
	{
		return new BinaryExpressionModel(opThen, l, r);
	}

	template<class T>
	Expression<T> FuzzyFactory::newAgg(Expression<T> l, Expression<T> r)
	{
		return new BinaryExpressionModel(opAgg, l, r);
	}

	template<class T>
	Expression<T> FuzzyFactory::newDefuzz(Expression<T> l, Expression<T> r)
	{
		return new BinaryExpressionModel(opDefuzz, l, r);
	}

	template<class T>
	Expression<T> FuzzyFactory::newNot(Expression<T> o)
	{
		return new UnaryExpressionModel(opNot, o);
	}

	template<class T>
	Expression<T> FuzzyFactory::newIs(Is<T> is, Expression<T> o)
	{
		return new UnaryExpressionModel(is, o);
	}

	template<class T>
	void FuzzyFactory::changeAnd(And o)
	{

	}

	template<class T>
	void FuzzyFactory::changeOr(Or o)
	{

	}

	template<class T>
	void FuzzyFactory::changeThen(Then o)
	{

	}

	template<class T>
	void FuzzyFactory::changeAgg(Agg o)
	{

	}

	template<class T>
	void FuzzyFactory::changeDefuzz(Defuzz o)
	{

	}

	template<class T>
	void FuzzyFactory::changeNot(Not o)
	{

	}

}

#endif /* FUZZYFACTORY_H_ */
