#ifndef COGDEFUZZ_H_
#define COGDEFUZZ_H_

#include "MamdaniDefuzz.h"

namespace op {
	template<class T>
	class CogDefuzz : public MamdaniDefuzz<T>{
	public:
		CogDefuzz(coreutils::Interval<T>* interval);

		virtual T defuzz(coreutils::Shape<T> shape) const;
	};

	template<class T>
	CogDefuzz<T>::CogDefuzz(coreutils::Interval<T> *interval)
	: MamdaniDefuzz<T>(interval)
	{
	}

	template<class T>
	T CogDefuzz <T>::defuzz(coreutils::Shape<T> shape) const
	{
		T num = 0;
		T denom = 0;
		std::pair<T, T> value;

		shape.start();

		while (shape.hasNext())
		{
			value = shape.next();

			num += value.first * value.second;
			denom += value.second;
		}

		if (denom == 0)
			return 0;

		return num / denom;
	}

}
#endif /* COGDEFUZZ_H_ */
