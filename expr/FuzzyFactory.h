#ifndef FUZZYFACTORY_H_
#define FUZZYFACTORY_H_

#include "expr.h"
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

		Expression<T>* newAnd(Expression<T>* l, Expression<T>* r);
		Expression<T>* newOr(Expression<T>* l, Expression<T>* r);
		Expression<T>* newThen(Expression<T>* l, Expression<T>* r);
		Expression<T>* newAgg(Expression<T>* l, Expression<T>* r);
		Expression<T>* newDefuzz(Expression<T>* l, Expression<T>* r);
		Expression<T>* newNot(Expression<T>* o);
		Expression<T>* newIs(Expression<T>* o, value::Is<T>* is);

		void changeAnd(op::And<T>* o);
		void changeOr(op::Or<T>* o);
		void changeThen(op::Then<T>* o);
		void changeAgg(op::Agg<T>* o);
		void changeDefuzz(op::Defuzz<T>* o);
		void changeNot(op::Not<T>* o);

	private:
		UnaryExpression<T> *opNot;
		BinaryExpression<T> *opAnd, *opOr, *opThen, *opAgg, *opDefuzz;
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
	Expression<T>* FuzzyFactory<T>::newAnd(Expression<T>* l, Expression<T>* r)
	{
		return new BinaryExpressionModel<T>(l, r, opAnd);
	}

	template<class T>
	Expression<T>* FuzzyFactory<T>::newOr(Expression<T>* l, Expression<T>* r)
	{
		return new BinaryExpressionModel<T>(l, r, opOr);
	}

	template<class T>
	Expression<T>* FuzzyFactory<T>::newThen(Expression<T>* l, Expression<T>* r)
	{
		return new BinaryExpressionModel<T>(l, r, opThen);
	}

	template<class T>
	Expression<T>* FuzzyFactory<T>::newAgg(Expression<T>* l, Expression<T>* r)
	{
		return new BinaryExpressionModel<T>(l, r, opAgg);
	}

	template<class T>
	Expression<T>* FuzzyFactory<T>::newDefuzz(Expression<T>* l, Expression<T>* r)
	{
		return new BinaryExpressionModel<T>(l, r, opDefuzz);
	}

	template<class T>
	Expression<T>* FuzzyFactory<T>::newNot(Expression<T>* o)
	{
		return new UnaryExpressionModel<T>(o, opNot);
	}

	template<class T>
	Expression<T>* FuzzyFactory<T>::newIs(Expression<T>* o, value::Is<T>* is)
	{
		return new UnaryExpressionModel<T>(o, is);
	}

	template<class T>
	void FuzzyFactory<T>::changeAnd(op::And<T>* o)
	{
		this->opAnd = o;
	}

	template<class T>
	void FuzzyFactory<T>::changeOr(op::Or<T>* o)
	{
		this->opOr = o;
	}

	template<class T>
	void FuzzyFactory<T>::changeThen(op::Then<T>* o)
	{
		this->opThen = o;
	}

	template<class T>
	void FuzzyFactory<T>::changeAgg(op::Agg<T>* o)
	{
		this->opAgg = o;
	}

	template<class T>
	void FuzzyFactory<T>::changeDefuzz(op::Defuzz<T>* o)
	{
		this->opDefuzz = o;
	}

	template<class T>
	void FuzzyFactory<T>::changeNot(op::Not<T>* o)
	{
		this->opNot = o;
	}

}

#endif /* FUZZYFACTORY_H_ */
