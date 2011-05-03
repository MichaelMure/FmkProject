#ifndef SHAPE_H_
#define SHAPE_H_

#include "expr.h"
#include "Interval.h"
#include <utility>

namespace coreutils {

	template<class T>
	class Shape {
	public:
		Shape(const expr::Expression<T> *expr, expr::ValueModel<T> *value, Interval<T> interval);
		virtual ~Shape() {};

		void start();
		bool hasNext();
		std::pair<T, T> next();

	private:
		const expr::Expression<T> *expr;
		expr::ValueModel<T> *value;
		Interval<T> interval;
	};

	template<class T>
	Shape<T>::Shape(const expr::Expression<T> *expr, expr::ValueModel<T> *value, Interval<T> interval)
	: expr(expr), value(value), interval(interval)
	{
	}

	template<class T>
	void Shape<T>::start()
	{
		this->interval.start();
	}

	template<class T>
	bool Shape<T>::hasNext()
	{
		return this->interval.hasNext();
	}

	template<class T>
	std::pair<T, T> Shape<T>::next()
	{
		T x = this->interval.next();
		this->value->setValue(x);
		T y = this->expr->evaluate();

		return std::make_pair<T, T>(x, y);
	}
}


#endif /* SHAPE_H_ */
