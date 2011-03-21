#ifndef ISTRAPEZELEFT_H_
#define ISTRAPEZELEFT_H_

#include "Is.h"

namespace value {
	template<class T>
	class IsTrapezeLeft  : public Is<T> {
	private:
		T min;
		T middleMax;
		T max;

	public:
		IsTrapezeLeft(const T& min, const T& middleMax, const T& max)
		: min(min), middleMax(middleMax), max(max)
		{
		}

		T evaluate(const expr::Expression<T>* operand) const
		{
			T value = operand->evaluate();
			if(value <= this->min || value >= this->max)
				return 0;

			if(value <= this->middleMax)
				return 1;

			if(value > this->middleMax)
				return (this->middleMax - this->max) / (value - this->max) ;
		}

	};

}

#endif /* ISTRAPEZELEFT_H_ */
