#ifndef MAMDANIDEFUZZ_H_
#define MAMDANIDEFUZZ_H_

#include "Defuzz.h"

namespace op {
	template<class T>
	class MamdaniDefuzz : public Defuzz<T>{
	public:
		virtual T evaluate(const expr::Expression<T>* left, const expr::Expression<T>* right) const;
		//virtual T  defuzz(const Shape shape) const =0;
	};

	template<class T>
	T MamdaniDefuzz <T>::evaluate(const expr::Expression<T>* left, const expr::Expression<T>* right) const
	{
		//return defuzz()
	}

}
#endif /* MAMDANIDEFUZZ_H_ */
