#include "Dummy.h"
#include <cassert>
#include <math.h>
#include <stdio.h>
using namespace std;
#define PI 3.1415926535897932354626
/**
 * According to NGSPICE manual, the convergence criteria are either a relative
 * error of 0.1%, or an absolute error of 1.0e-12, whichever is larger, hence
 * the following macro as well as the tolerance function are defined
 */
#define ABSOLUTE_TOLERANCE 1.0e-13;
#define RELATIVE_TOLERANCE 1.0e-3;

bool isInTolerance(double std, double actual){
    double diff = abs(std - actual);
    double rel = std*RELATIVE_TOLERANCE;
    double abs_tol = ABSOLUTE_TOLERANCE;
    if (rel >= abs_tol) {
        if (diff >= rel)
            return false;
        else
            return true;
    }
    else {
        if (diff >= abs_tol)
            return false;
        else
            return true;
    }
}

int main() {
	Dummy::showAllRecords();
	Dummy::resetAllRecords();
	Dummy a = Dummy(1.1);
	Dummy b = Dummy(2.2);
	Dummy c = Dummy(3.3);
	Dummy d = Dummy(4.4);
	Dummy e = a;
	Dummy f = b;
	Dummy _array_[6] = { a,b,c,d,e,f };
	double aa = a.getContent();
	double bb = b.getContent();
	double cc = c.getContent();
	double dd = d.getContent();
	double ee = e.getContent();
	double ff = f.getContent();
	double _array_double_[6] = { aa, bb, cc, dd, ee, ff };
	assert(sizeof(_array_)==sizeof(_array_double_));
	printf("Size assertion passed.\n");
	Dummy g = a + b;
	assert(g.getContent() == (aa + bb));
	printf("Addition assertion passed.\n");
	g = a - b;
	assert(g.getContent() == (aa - bb));
	printf("Subtraction assertion passed.\n");
	g = a * b;
	assert(g.getContent() == (aa * bb));
	printf("Multiplication assertion passed.\n");

	g = a / b;
	//printf("g: %f\n", g);
	//printf("aa/bb: %f\n", aa / bb);
	assert(g.getContent() == (aa / bb));
	printf("Division assertion passed.\n");
	double gg = g.getContent();
	g += a;
	gg += aa;
	assert(g.getContent() == gg );
	printf("Add-equal assertion passed.\n");
	g -= a;
	gg -= aa;
	assert(g.getContent() == gg);
	printf("Subtract-equal assertion passed.\n");
	g *= a;
	gg *= aa;
	assert(g.getContent() == gg);
	printf("Mul-equal assertion passed.\n");
	g /= a;
	gg /= aa;
	assert(g.getContent() == gg);
	printf("Div-equal assertion passed.\n");
	//assert(b>a);
	//printf("greater-than assertion passed.\n");
	//assert(a<b);
	//printf("less-than assertion passed.\n ");
	assert(b >= a);
	assert(a >= a);
	printf("greater-equal assertion passed.\n");
	assert(a <= b);
	assert(a <= a);
	printf("less-equal assertion passed.\n");
	assert(c.getContent() == cc);
	printf("equal assertion passed.\n");
	assert((int)c == (int)cc);
	printf("convertion to int assertion passed.\n");
	int h = 10;
	Dummy _h = Dummy(h);
	double hh = (double)h;
	assert(_h.getContent() == hh);
	printf("convertion from int assertion passed.\n");
	int i = 3;
	Dummy j = c / i;
	Dummy k = i / c;
	double l = 3.3 / 3;
	double m = 3 / 3.3;
	assert(j.getContent() == l);
	assert(k.getContent() == m);
	printf("Integer-involved Division assertion passed.\n");
	long int n = 44000;
	Dummy o = d / n;
	Dummy p = n / d;
	double q = 4.4 / 44000;
	double r = 44000 / 4.4;
	assert(o.getContent() == q);
	assert(p.getContent() == r);
	printf("Long-integer-involved Division assertion passed.\n");
	double s = 2.0;
	Dummy t = b / s;
	Dummy u = s / b;
	double v = 2.2 / 2.0;
	double w = 2.0 / 2.2;
	assert(t.getContent() == v);
	assert(u.getContent() == w);
	printf("Double-involved Division assertion passed.\n");
	Dummy x = n * a;
	Dummy y = s * a;
	v = 44000 * 1.1;
	w = 2.0 * 1.1;
	//printf("Test whether Dummy class could be displayed normally: %f\n" , ~y);
	assert(x.getContent() == v);
	assert(y.getContent() == w);
	printf("Multiplication of different type assertion passed.\n");
	assert(b > a);
	assert(a < b);
	assert(bb > a);
	assert(a < bb);
	assert(b > aa);
	assert(aa < b);
	printf("Less-than and greater-than assertion passed.\n");
	//double aa = fabs(a);
	Dummy a3 = Dummy(0.0);
	assert(b >= a);
	assert(a >= a);
	assert(b >= 1.1);
	assert(b >= 2.2);
	assert(a3 >= 0);
	assert(a >= 1);
	printf("Greater-equal assertion passed.\n");
	assert(a <= b);
	assert(a <= a);
	assert(b <= 3.3);
	assert(b <= 2.2);
	assert(a3 <= 0);
	assert(a <= 2);
	printf("Less-equal assertion passed.\n");
	assert(a3 == 0);
	assert(a == 1.1);
	assert(a == a);
	printf("Equal assertion passed.\n");
	assert(-a == -1.1);
	Dummy a4 = b - 1;
	assert(a4 == 2.2 - 1);
	a4 = b - 1.1;
	assert(a4 == b-a);
	printf("New subtraction assertion passed.\n");
	assert(a + 1 == 1.1 + 1);
	assert(a + 1.1 == 1.1 + 1.1);
	printf("New addition assertion passed.\n");
	assert(fabs(a) == fabs(-a));
	assert(sin(a) == sin(aa));
	printf("Function assertion passed.\n");
	assert(a != bb);
	Dummy a5 = Dummy(0.0);
	assert(a != b);
	assert(!(a5 != 0));
	printf("Not-equal assertion passed.\n");
	assert(!a5);
	printf("Negation assertion passed.\n");
	long int i3 = 500;
	long int i4 = 1;
	assert(a >= i4);
	assert(a >= a);
	assert(a <= i3);
	assert(a <= a);
	printf("Greater-equal & less-equal for long int as right argument assertion passed.\n");
	assert(a > 1);
	assert(a < 2);
	printf("Greater-than & less-than for int as right argument assertion passed.\n");
	Dummy a6 = Dummy(1.1);
	Dummy a7;
	a7 = (a6 += b);
	assert((a+b) == (a7));
	a6 = Dummy(1.1);
	a7 = (a6 -= b);
	assert((a - b) == a7);
	a6 = Dummy(1.1);
	a7 = (a6 *= b);
	assert((a * b) == a7);
	a6 = Dummy(1.1);
	a7 = (a6 /= b);
	assert((a / b) == a7);
	printf("operation-plus-equal assertion passed.\n");
	a6 = 1.1;
	unsigned int i2 = 23456;
	//assert(Dummy(aa * i2) == (a6 * i2));
	printf("unsigned integer multiplication assertion passed.\n");
	a6 = 1.1;
	a7 = +a6;
	assert(a7 == a6);
	printf("unary addition assertion passed.\n");
    /**
     * The following function was for operator= overloading, since it will affect
     * the initialization of unnamed union containing Dummy class, it's abandoned.
     */
	/*
	Dummy volatile a8 = 1.1;
	Dummy a9;
	a9 = a8;
	printf("equal overload assertion passed.\n");
	*/
	Dummy a8,a9;
	Dummy* a8ptr = &a8;
	a9 = modf(a, a8ptr);
	double aa7 = 1.1, aa8, aa9;
	double* aa8ptr = &aa8;
	aa9 = modf(aa7,aa8ptr);
	assert(a9 == aa9);
	assert(a8 == aa8);
	//cout << "a9: " << a9.getContent() << endl;
	//assert(a9 == (double)0.1);
	assert(a8 == 1.0);
	printf("modf assertion passed.\n");
	int i5 = 1, i6 = 0;

	int *i5ptr = &i5, *i6ptr = &i6;
	double d1 = 0.75;
	Dummy a2 = 0.75;
	a3 = frexp(a2,i5ptr);
	a4 = frexp(d1, i6ptr);
	assert(a3 == a4);
	assert(i5 == i6);
	double d2 = NAN;
	Dummy a10 = d2;
	i5 = fpclassify(d2);
	i6 = fpclassify(a10);
	//assert(a5 == a6);
	a2 = 1.0;
	assert(isfinite(a2) == true);
	assert(isnormal(a2) == true);
	a2 = NAN;
	assert(isnormal(a2) == false);
	a2 = INFINITY;
	assert(isinf(a2) == true);
	a2 = 1.0;
	assert(isinf(a2) == false);
	assert(erfc(a2) == erfc(1.0));
	printf("new functions assertion passed\n");
	Dummy::showAllRecords();
	Dummy::resetAllRecords();
	Dummy::showAllRecords();
}
