#ifndef UNARYSHADOWEXPRESSION_H_
#define UNARYSHADOWEXPRESSION_H_

#include "UnaryExpression.h"

namespace expr {

	template <class T>
	class UnaryShadowExpression : public UnaryExpression<T> {
	public:
		UnaryShadowExpression(UnaryExpression<T>* target);
		virtual ~UnaryShadowExpression() {};

		T evaluate(const Expression<T>* operand) const;
		void setTarget(UnaryExpression<T> *target);

	private:
		UnaryExpression<T>* target;
	};

	template<class T>
	UnaryShadowExpression<T>::UnaryShadowExpression(UnaryExpression<T>* target)
	: target(target)
	{
	}

	template<class T>
	T UnaryShadowExpression<T>::evaluate(const Expression<T>* operand) const
	{
		return this->target->evaluate(operand);
	}

	template<class T>
	void UnaryShadowExpression<T>::setTarget(UnaryExpression<T> *target)
	{
		this->target = target;
	}
}

#endif /* UNARYSHADOWEXPRESSION_H_ */
