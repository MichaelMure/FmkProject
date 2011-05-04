#ifndef ISTRIANGLE_H_
#define ISTRIANGLE_H_

#include "Is.h"

namespace value {
	template<class T>
	class IsTriangle  : public Is<T> {
	private:
		T min;
		T middle;
		T max;

	public:
		IsTriangle(const T& min, const T& middle, const T& max)
		: min(min), middle(middle), max(max)
		{
		}

		T evaluate(const expr::Expression<T>* operand) const
		{
			T value = operand->evaluate();

			if(value <= this->min || value >= this->max)
				return 0;

			if(value <= this->middle)
				return (value - this->min) / (this->middle - this->min);

			if(value > this->middle)
				return 1 - (value - this->middle) / (this->max - this->middle);

			return 0;
		}

	};

}
#endif /* ISTRIANGLE_H_ */
