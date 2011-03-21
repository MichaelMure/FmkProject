#ifndef ISTRAPEZERIGHT_H_
#define ISTRAPEZERIGHT_H_

#include "Is.h"

namespace value {
	template<class T>
	class IsTrapezeRight  : public Is<T> {
	private:
		T min;
		T middleMin;
		T max;

	public:
		IsTrapezeRight(const T& min, const T& middleMin, const T& max)
		: min(min), middleMin(middleMin), max(max)
		{
		}

		T evaluate(const expr::Expression<T>* operand) const
		{
			T value = operand->evaluate();
			if(value <= this->min || value >= this->max)
				return 0;

			if(value >= this->middleMin)
				return 1;

			if(value <= this->middleMin)
				return  (this->middleMin - this->min) / (value - this->min);
		}

	};

}

#endif /* ISTRAPEZERIGHT_H_ */
