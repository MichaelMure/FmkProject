#ifndef INTERVAL_H_
#define INTERVAL_H_

namespace coreutils {

	template<class T>
	class Interval {
	public:
		Interval(T min, T max, T step);
		virtual ~Interval(){};

		void start();
		bool hasNext();
		T next();

	private:
		T min, max, step, current;
	};

	template<class T>
	Interval<T>::Interval(T min, T max, T step)
	: min(min), max(max), step(step), current(min)
	{
	}

	template<class T>
	void Interval<T>::start()
	{
		this->current = this->min;
	}

	template<class T>
	bool Interval<T>::hasNext()
	{
		return (this->current <= this->max);
	}

	template<class T>
	T Interval<T>::next()
	{
		if((this->current) > this->max)
			throw(std::exception());

		T value = this->current;
		this->current += this->step;
		return value;
	}
}

#endif /* INTERVAL_H_ */
