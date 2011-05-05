#ifndef NARYSHADOWEXPRESSION_H_
#define NARYSHADOWEXPRESSION_H_

#include "NaryExpression.h"

namespace expr {

	template <class T>
	class NaryShadowExpression : public NaryExpression<T> {
	public:
		NaryShadowExpression(NaryExpression<T>* target);
		virtual ~NaryShadowExpression() {};

		T evaluate(std::vector<const Expression<T>*> *operands) const;
		void setTarget(NaryExpression<T> *target);

	private:
		NaryExpression<T>* target;
	};

	template<class T>
	NaryShadowExpression<T>::NaryShadowExpression(NaryExpression<T>* target)
	: target(target)
	{
	}

	template<class T>
	T NaryShadowExpression<T>::evaluate(std::vector<const Expression<T>*> *operands) const
	{
		return this->target->evaluate(operands);
	}

	template<class T>
	void NaryShadowExpression<T>::setTarget(NaryExpression<T> *target)
	{
		this->target = target;
	}
}


#endif /* NARYSHADOWEXPRESSION_H_ */
