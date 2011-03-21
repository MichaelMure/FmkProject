#ifndef EXPRESSION_H_
#define EXPRESSION_H_

namespace expr {

	template<class T>
	class Expression {
	public:
		virtual T evaluate() const =0;
	};

}

#endif /* EXPRESSION_H_ */
