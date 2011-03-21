#include <iostream>
#include "expr/expr.h"
#include "op/op.h"
#include "value/value.h"

using namespace expr;
using namespace std;
using namespace op;

void testOp()
{
	/* Test Value */
	ValueModel<int> *vm1 = new ValueModel<int>(3);
	ValueModel<int> *vm2 = new ValueModel<int>(39);
	cout << vm1->evaluate() << endl;
	cout << vm2->evaluate() << endl;

	/* Test Operator */
	AggMax<int>* aggmax = new AggMax<int>();
	AggPlus<int>* aggplus = new AggPlus<int>();
	AndMin<int>* andmin = new AndMin<int>();
	AndMult<int>* andmult = new AndMult<int>();
	//CogDefuzz<int>* cogdefuzz = new CogDefuzz<int>();
	NotMinus1<int>* notminus1 = new NotMinus1<int>();
	OrMax<int>* ormax = new OrMax<int>();
	OrPlus<int>* orplus = new OrPlus<int>();
	//SugenoDefuzz<int>* sugenodefuzz = new SugenoDefuzz<int>();
	ThenMin<int>* thenmin = new ThenMin<int>();
	ThenMult<int>* thenmult = new ThenMult<int>();

	BinaryExpressionModel<int> a(vm1, vm2, aggmax);
	cout << a.evaluate() << endl;
	BinaryExpressionModel<int> b(vm1, vm2, aggplus);
	cout << b.evaluate() << endl;
	BinaryExpressionModel<int> c(vm1, vm2, andmin);
	cout << c.evaluate() << endl;
	BinaryExpressionModel<int> d(vm1, vm2, andmult);
	cout << d.evaluate() << endl;
	UnaryExpressionModel<int> e(vm1, notminus1);
	cout << e.evaluate() << endl;
	BinaryExpressionModel<int> j(vm1, vm2, ormax);
	cout << j.evaluate() << endl;
	BinaryExpressionModel<int> g(vm1, vm2, orplus);
	cout << g.evaluate() << endl;
	BinaryExpressionModel<int> h(vm1, vm2, thenmin);
	cout << h.evaluate() << endl;
	BinaryExpressionModel<int> i(vm1, vm2, thenmult);
	cout << i.evaluate() << endl;
	//BinaryExpressionModel<int> j(vm1, vm2, orplus);
	//cout << j.evaluate() << endl;

	delete vm1;
	delete vm2;
	delete orplus;
}

void testExample()
{
	//operators
	NotMinus1<int> opNot;
	AndMin<int> opAnd;
	OrMax<int> opOr;
	ThenMin<int> opThen;
	CogDefuzz<int> opDefuzz;

	//fuzzy expession factory
	FuzzyFactory<int> f	(&opNot,&opAnd,&opOr,&opThen,&opOr,&opDefuzz);

	//membership function
	IsTriangle<int> poor(-5,0,5);
	IsTriangle<int> good(0,5,10);
	IsTriangle<int> excellent(5,10,15);
	IsTriangle<int> cheap(0,5,10);
	IsTriangle<int> average(10,15,20);
	IsTriangle<int> generous(20,25,30);

	//values
	Value<int> service(0);
	Value<int> food(0);
	BoundedValue tips(0,0,30,1);

	Expression *r =
			f.NewAgg(
					f.NewAgg(
							f.NewThen(
									f.NewIs(&service,&poor),
									f.NewIs(&tips,&cheap)
							),
							f.NewThen(
									f.NewIs(&service,&good),
									f.NewIs(&tips,&average)
							)
					),
					f.NewThen(
							f.NewIs(&service,&excellent),
							f.NewIs(&tips,&generous)
					)
			);

	//defuzzification
	Expression *system = f.NewDefuzz(&tips,r);

	//apply input
	float s;
	while(true)
	{
		cout << "service : ";cin >> s;
		service.SetValue(s);
		cout << "tips -> " << system->Evaluate() << endl;
	}
}

int main() {
	testOp();
	testExample();

	return 0;
}
