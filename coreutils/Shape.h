#ifndef SHAPE_H_
#define SHAPE_H_

namespace coreutils {

	template<class T>
	class Shape {
	public:
		Shape(...);
		virtual ~Shape() {};

		void start();
		bool hasNext();
		pair<T, T> next();

	private:
		vector<T> x;
		vector<T> y;
		int current;
	};

}


#endif /* SHAPE_H_ */
