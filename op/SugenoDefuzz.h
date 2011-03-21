#ifndef SUGENODEFUZZ_H_
#define SUGENODEFUZZ_H_

#include "Defuzz.h"

namespace op {
	template<class T>
	class SugenoDefuzz : public Defuzz<T>{
	public:
		virtual T evaluate(const expr::Expression<T>* left, const expr::Expression<T>* right) const;
	};

	template<class T>
	T SugenoDefuzz <T>::evaluate(const expr::Expression<T>* left, const expr::Expression<T>* right) const
	{

	}

}
#endif /* SUGENODEFUZZ_H_ */
