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
					op::MamdaniDefuzz<T> *opMamdani,
					op::SugenoDefuzz<T> *opSugeno,
					op::SugenoConclusion<T> *opConclusion);

		Expression<T>* newAnd(Expression<T>* l, Expression<T>* r);
		Expression<T>* newOr(Expression<T>* l, Expression<T>* r);
		Expression<T>* newThen(Expression<T>* l, Expression<T>* r);
		Expression<T>* newAgg(Expression<T>* l, Expression<T>* r);
		Expression<T>* newMamdani(Expression<T>* l, Expression<T>* r);
		Expression<T>* newSugeno(std::vector<const Expression<T>*> *operands);
		Expression<T>* newConclusion(std::vector<const Expression<T>*> *operands);
		Expression<T>* newNot(Expression<T>* o);
		Expression<T>* newIs(Expression<T>* o, value::Is<T>* is);

		void changeAnd(op::And<T>* o);
		void changeOr(op::Or<T>* o);
		void changeThen(op::Then<T>* o);
		void changeAgg(op::Agg<T>* o);
		void changeMamdani(op::MamdaniDefuzz<T>* o);
		void changeSugeno(op::SugenoDefuzz<T>* o);
		void changeConclusion(op::SugenoConclusion<T>* o);
		void changeNot(op::Not<T>* o);

	private:
		UnaryShadowExpression<T> *opNot;
		BinaryShadowExpression<T> *opAnd, *opOr, *opThen, *opAgg, *opMamdani;
		NaryShadowExpression<T> *opSugeno, *opConclusion;
	};

	template<class T>
	FuzzyFactory<T>::FuzzyFactory(op::Not<T> *opNot,
						op::And<T> *opAnd,
						op::Or<T> *opOr,
						op::Then<T> *opThen,
						op::Agg<T> *opAgg,
						op::MamdaniDefuzz<T> *opMamdani,
						op::SugenoDefuzz<T> *opSugeno,
						op::SugenoConclusion<T> *opConclusion)
	: opNot(new UnaryShadowExpression<T>(opNot)),
	  opAnd(new BinaryShadowExpression<T>(opAnd)),
	  opOr(new BinaryShadowExpression<T>(opOr)),
	  opThen(new BinaryShadowExpression<T>(opThen)),
	  opAgg(new BinaryShadowExpression<T>(opAgg)),
	  opMamdani(new BinaryShadowExpression<T>(opMamdani)),
	  opSugeno(new NaryShadowExpression<T>(opSugeno)),
	  opConclusion(new NaryShadowExpression<T>(opConclusion))
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
	Expression<T>* FuzzyFactory<T>::newMamdani(Expression<T>* l, Expression<T>* r)
	{
		return new BinaryExpressionModel<T>(l, r, opMamdani);
	}

	template<class T>
	Expression<T>* FuzzyFactory<T>::newSugeno(std::vector<const Expression<T>*> *operands)
	{
		return new NaryExpressionModel<T>(operands, opSugeno);
	}

	template<class T>
	Expression<T>* FuzzyFactory<T>::newConclusion(std::vector<const Expression<T>*> *operands)
	{
		return new NaryExpressionModel<T>(operands, opConclusion);
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
		this->opAnd->setTarget(o);
	}

	template<class T>
	void FuzzyFactory<T>::changeOr(op::Or<T>* o)
	{
		this->opOr->setTarget(o);
	}

	template<class T>
	void FuzzyFactory<T>::changeThen(op::Then<T>* o)
	{
		this->opThen->setTarget(o);
	}

	template<class T>
	void FuzzyFactory<T>::changeAgg(op::Agg<T>* o)
	{
		this->opAgg->setTarget(o);
	}

	template<class T>
	void FuzzyFactory<T>::changeMamdani(op::MamdaniDefuzz<T>* o)
	{
		this->opMamdani->setTarget(o);
	}

	template<class T>
	void FuzzyFactory<T>::changeSugeno(op::SugenoDefuzz<T>* o)
	{
		this->opSugeno->setTarget(o);
	}

	template<class T>
	void FuzzyFactory<T>::changeConclusion(op::SugenoConclusion<T>* o)
	{
		this->opConclusion->setTarget(o);
	}

	template<class T>
	void FuzzyFactory<T>::changeNot(op::Not<T>* o)
	{
		this->opNot->setTarget(o);
	}

}

#endif /* FUZZYFACTORY_H_ */
