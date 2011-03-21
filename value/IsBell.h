#ifndef ISBELL_H_
#define ISBELL_H_

#include "Is.h"
#include <math.h>

namespace value {
	template<class T>
	class IsBell  : public Is<T> {
	private:
		T a, b, center;

	public:
		IsBell(const T& a, const T& b, const T& center)
		: a(a), b(b), center(center)
		{
		}

		T evaluate(const expr::Expression<T>* operand) const
		{
			T value = operand->evaluate();

			return 1 / (1 + pow(abs((value - this->center) / this->a)), 2 * this->b);
		}

	};

}

#endif /* ISBELL_H_ */
