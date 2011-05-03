#ifndef MAMDANIDEFUZZ_H_
#define MAMDANIDEFUZZ_H_

#include "coreutils.h"
#include "BinaryExpression.h"

namespace op {
	template<class T>
	class MamdaniDefuzz : public expr::BinaryExpression<T>{
	public:
		MamdaniDefuzz(coreutils::Interval<T>* interval);

		virtual T evaluate(const expr::Expression<T>* left, const expr::Expression<T>* right) const;
		virtual T defuzz(coreutils::Shape<T> shape) const =0;

	private:
		coreutils::Interval<T> *interval;
	};

	template<class T>
	MamdaniDefuzz<T>::MamdaniDefuzz(coreutils::Interval<T> *interval)
	: interval(interval)
	{
	}

	template<class T>
	T MamdaniDefuzz<T>::evaluate(const expr::Expression<T>* left, const expr::Expression<T>* right) const
	{
		coreutils::Shape<T> sh = coreutils::Shape<T>(left, (expr::ValueModel<T>*) right, *this->interval);

		return defuzz(sh);
	}

}
#endif /* MAMDANIDEFUZZ_H_ */
