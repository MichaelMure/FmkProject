#ifndef BINARYSHADOWEXPRESSION_H_
#define BINARYSHADOWEXPRESSION_H_

#include "BinaryExpression.h"

namespace expr {

	template <class T>
	class BinaryShadowExpression : public BinaryExpression<T> {
	public:
		BinaryShadowExpression(BinaryExpression<T>* target);
		virtual ~BinaryShadowExpression() {};

		T evaluate(const Expression<T>* l, const Expression<T>* r) const;
		void setTarget(BinaryExpression<T> *target);
		BinaryExpression<T>* getTarget();

	private:
		BinaryExpression<T>* target;
	};

	template<class T>
	BinaryShadowExpression<T>::BinaryShadowExpression(BinaryExpression<T>* target)
	: target(target)
	{
	}

	template<class T>
	T BinaryShadowExpression<T>::evaluate(const Expression<T>* l, const Expression<T>* r) const
	{
		return this->target->evaluate(l, r);
	}

	template<class T>
	void BinaryShadowExpression<T>::setTarget(BinaryExpression<T> *target)
	{
		this->target = target;
	}

	template<class T>
	BinaryExpression<T>* BinaryShadowExpression<T>::getTarget()
	{
		return this->target;
	}
}

#endif /* BINARYSHADOWEXPRESSION_H_ */
