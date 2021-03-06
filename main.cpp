#include <iostream>
#include "expr.h"
#include "op.h"
#include "value.h"
#include "coreutils.h"

using namespace expr;
using namespace std;
using namespace op;
using namespace value;
using namespace coreutils;

void testOp()
{
	/* Test Value */
	ValueModel<float> *vm1 = new ValueModel<float>(3);
	ValueModel<float> *vm2 = new ValueModel<float>(39);
	cout << vm1->evaluate() << endl;
	cout << vm2->evaluate() << endl;

	/* Test Operator */
	AggMax<float>* aggmax = new AggMax<float>();
	AggPlus<float>* aggplus = new AggPlus<float>();
	AndMin<float>* andmin = new AndMin<float>();
	AndMult<float>* andmult = new AndMult<float>();
	//CogDefuzz<float>* cogdefuzz = new CogDefuzz<float>();
	NotMinus1<float>* notminus1 = new NotMinus1<float>();
	OrMax<float>* ormax = new OrMax<float>();
	OrPlus<float>* orplus = new OrPlus<float>();
	//SugenoDefuzz<float>* sugenodefuzz = new SugenoDefuzz<float>();
	ThenMin<float>* thenmin = new ThenMin<float>();
	ThenMult<float>* thenmult = new ThenMult<float>();

	BinaryExpressionModel<float> a(vm1, vm2, aggmax);
	cout << a.evaluate() << endl;
	BinaryExpressionModel<float> b(vm1, vm2, aggplus);
	cout << b.evaluate() << endl;
	BinaryExpressionModel<float> c(vm1, vm2, andmin);
	cout << c.evaluate() << endl;
	BinaryExpressionModel<float> d(vm1, vm2, andmult);
	cout << d.evaluate() << endl;
	UnaryExpressionModel<float> e(vm1, notminus1);
	cout << e.evaluate() << endl;
	BinaryExpressionModel<float> j(vm1, vm2, ormax);
	cout << j.evaluate() << endl;
	BinaryExpressionModel<float> g(vm1, vm2, orplus);
	cout << g.evaluate() << endl;
	BinaryExpressionModel<float> h(vm1, vm2, thenmin);
	cout << h.evaluate() << endl;
	BinaryExpressionModel<float> i(vm1, vm2, thenmult);
	cout << i.evaluate() << endl;
	//BinaryExpressionModel<float> j(vm1, vm2, orplus);
	//cout << j.evaluate() << endl;

	delete vm1;
	delete vm2;
	delete orplus;
}

void testTriangle()
{
	cout << "Test Triangle";

	//Is
	IsTriangle<float> tri = IsTriangle<float>(5, 10, 15);
	ValueModel<float> vm = ValueModel<float>(0);
	UnaryExpressionModel<float> expr = UnaryExpressionModel<float>(&vm, &tri);

	float s;
	while(true)
	{
		cout << "vm : ";cin >> s;
		vm.setValue(s);
		cout << "tips -> " << expr.evaluate() << endl;
	}

}

void testMamdani()
{
	//utils
	Interval<float> interval = Interval<float>(5, 25, 1);

	//operators
	NotMinus1<float> opNot;
	AndMin<float> opAnd;
	OrMax<float> opOr;
	ThenMin<float> opThen;
	AggMax<float> opAgg;
	CogDefuzz<float> opMamdani = CogDefuzz<float>(&interval);
	SugenoDefuzz<float> opSugeno = SugenoDefuzz<float>();

	vector<float> coef;
	coef.push_back(1);
	coef.push_back(1);
	SugenoConclusion<float> opConclusion = SugenoConclusion<float>(&coef);

	//fuzzy expession factory
	FuzzyFactory<float> f	(&opNot,&opAnd,&opOr,&opThen,&opAgg,&opMamdani, &opSugeno, &opConclusion);

	//membership function
	IsTriangle<float> poor(-5,0,5);
	IsTriangle<float> good(0,5,10);
	IsTriangle<float> excellent(5,10,15);
	IsTriangle<float> cheap(0,5,10);
	IsTriangle<float> average(10,15,20);
	IsTriangle<float> generous(20,25,30);

	//values
	ValueModel<float> service(0);
	ValueModel<float> tips(0);

	Expression<float> *r =
			f.newAgg(
					f.newAgg(
							f.newThen(
									f.newIs(&service,&poor),
									f.newIs(&tips,&cheap)
							),
							f.newThen(
									f.newIs(&service,&good),
									f.newIs(&tips,&average)
							)
					),
					f.newThen(
							f.newIs(&service,&excellent),
							f.newIs(&tips,&generous)
					)
			);

	//defuzzification
	Expression<float> *system = f.newMamdani(r,&tips);

	//apply input
	float s;
	while(true)
	{
		cout << "service : ";cin >> s;
		service.setValue(s);
		cout << "tips -> " << system->evaluate() << endl;
	}
}

void testSugeno()
{
	//utils
	Interval<float> interval = Interval<float>(5, 25, 1);

	//operators
	NotMinus1<float> opNot;
	AndMin<float> opAnd;
	OrMax<float> opOr;
	SugenoThen<float> opThen;
	AggMax<float> opAgg;
	CogDefuzz<float> opMamdani = CogDefuzz<float>(&interval);
	SugenoDefuzz<float> opSugeno = SugenoDefuzz<float>();

	vector<float> coef;
	coef.push_back(1);
	coef.push_back(1);
	SugenoConclusion<float> opConclusion = SugenoConclusion<float>(&coef);

	//fuzzy expession factory
	FuzzyFactory<float> f	(&opNot,&opAnd,&opOr,&opThen,&opAgg,&opMamdani, &opSugeno, &opConclusion);

	//membership function
	IsTriangle<float> poor(-5,0,5);
	IsTriangle<float> good(0,5,10);
	IsTriangle<float> excellent(5,10,15);
	IsTriangle<float> rancid(-5,0,5);
	IsTriangle<float> delicious(5,10,15);

	//values
	ValueModel<float> service(0);
	ValueModel<float> food(0);

	//Sugeno conclu
	vector<const Expression<float>*> SCservicefood;
	SCservicefood.push_back(&service);
	SCservicefood.push_back(&food);

	vector<const Expression<float>*> SCservice;
	SCservice.push_back(&service);

	//Regles
	vector<const Expression<float>*> regles;

	regles.push_back(
				f.newThen(
						f.newOr(
							f.newIs(&service, &poor),
							f.newIs(&food, &rancid)
						),
						f.newConclusion(&SCservicefood)
				)
			);

	regles.push_back(
					f.newThen(
							f.newIs(&service, &good),
							f.newConclusion(&SCservice)
					)
				);

	regles.push_back(
					f.newThen(
							f.newOr(
								f.newIs(&service, &excellent),
								f.newIs(&food, &delicious)
							),
							f.newConclusion(&SCservicefood)
					)
				);

	//defuzzification
	Expression<float> *system = f.newSugeno(&regles);

	//apply input
	float s;
	while(true)
	{
		cout << "service : ";cin >> s;
		service.setValue(s);
		cout << "food : ";cin >> s;
		food.setValue(s);
		cout << "tips -> " << system->evaluate() << endl;
	}
}

int main() {
	//testTriangle();
	testOp();
	//testMamdani();
	testSugeno();

	return 0;
}
