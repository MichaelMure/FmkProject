#ifndef ISTRAPEZE_H_
#define ISTRAPEZE_H_

#include "Is.h"

namespace value {
	template<class T>
	class IsTrapeze  : public Is<T> {
	private:
		T min;
		T middleMin;
		T middleMax;
		T max;

	public:
		IsTrapeze(const T& min, const T& middleMin, const T& middleMax, const T& max)
		: min(min), middleMin(middleMin), middleMax(middleMax), max(max)
		{
		}

		T evaluate(const expr::Expression<T>* operand) const
		{
			T value = operand->evaluate();
			if(value <= this->min || value >= this->max)
				return 0;

			if(value >= this->middleMin && value <= this->middleMax)
				return 1;

			if(value <= this->middleMin)
				return  (this->middleMin - this->min) / (value - this->min);

			if(value > this->middleMax)
							return (this->middleMax - this->max) / (value - this->max) ;
		}

	};

}

#endif /* ISTRAPEZE_H_ */
