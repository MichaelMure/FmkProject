#ifndef COGDEFUZZ_H_
#define COGDEFUZZ_H_

#include "MamdaniDefuzz.h"

namespace op {
	template<class T>
	class CogDefuzz : public MamdaniDefuzz<T>{
	public:
		virtual T evaluate(const expr::Expression<T>* left, const expr::Expression<T>* right) const;
	};

	template<class T>
	T CogDefuzz <T>::evaluate(const expr::Expression<T>* left, const expr::Expression<T>* right) const
	{

	}

}
#endif /* COGDEFUZZ_H_ */
