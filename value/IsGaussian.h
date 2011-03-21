#ifndef ISGAUSSIAN_H_
#define ISGAUSSIAN_H_

#include "Is.h"
#include <math.h>

namespace value {
	template<class T>
	class IsGaussian  : public Is<T> {
	private:
		T sigma;
		T center;

	public:
		IsGaussian(const T& sigma, const T& center)
		: sigma(sigma), center(center)
		{
		}

		T evaluate(const expr::Expression<T>* operand) const
		{
			T value = operand->evaluate();

			return exp(-((value - this->center) * (value - this->center)) / (2 * this->sigma * this->sigma));
		}

	};

}

#endif /* ISGAUSSIAN_H_ */
