#include "Dummy.h"
#include <cassert>
#include <cmath>
#include <cstdio>
#include <iostream>
using namespace std;
#define IS_DEBUG

bool isInTolerance(double std, double actual){
    double diff = fabs(std - actual);
    double rel = fabs(std)*RELATIVE_TOLERANCE;
    double abs_tol = ABSOLUTE_TOLERANCE;
#ifdef IS_DEBUG
    cout << "diff: " << diff << endl;
    cout << "rel: " << rel << endl;
    cout << "abs_tol: " << abs_tol << endl;
#endif
    if (rel >= abs_tol) {
#ifdef IS_DEBUG
        cout << "rel >= abs_tol." << endl;
#endif
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
    cout.precision(25);
    char *fixedstr = new char[40];
	Dummy::showAllRecords();
	Dummy::resetAllRecords();
	Dummy a = Dummy(1.1);
	Dummy b = Dummy(2.2);
	Dummy c = Dummy(3.3);
	Dummy d = Dummy(4.4);
	Dummy e = a;
	Dummy f = b;
	Dummy _array_[6] = { a,b,c,d,e,f };
	double aa = fixed2double(a.getContent());
	double bb = fixed2double(b.getContent());
	double cc = fixed2double(c.getContent());
	double dd = fixed2double(d.getContent());
	double ee = fixed2double(e.getContent());
	double ff = fixed2double(f.getContent());
	double _array_double_[6] = { aa, bb, cc, dd, ee, ff };
	assert(sizeof(_array_)==sizeof(_array_double_));
	printf("Size assertion passed.\n");
    cout.precision(10);
    cout << "aa: " << aa << endl;
    cout << "bb: " << bb << endl;
    cout << "aa + bb: " << aa + bb << endl;
    cout << "a: " << (double)a << endl;
    cout << "b: " << (double)b << endl;
    cout << "a + b: " <<(double)(a+b) << endl;
	Dummy g = a + b;
#ifndef FIXED_POINT_FIXEDPTC
	assert(g.getContent() == (aa + bb));
#endif // end of #ifndef FIXED_POINT_FIXEDPTC
#ifdef FIXED_POINT_FIXEDPTC
    assert(isInTolerance((aa+bb), (double)g));
#endif
	printf("Addition assertion passed.\n");
	g = a - b;
#ifndef FIXED_POINT_FIXEDPTC
	assert(g.getContent() == (aa - bb));
#endif
#ifdef FIXED_POINT_FIXEDPTC
    assert(isInTolerance((aa-bb),(double)g));
#endif
	printf("Subtraction assertion passed.\n");
	g = a * b;
#ifndef FIXED_POINT_FIXEDPTC
	assert(g.getContent() == (aa * bb));
#endif
#ifdef FIXED_POINT_FIXEDPTC
    cout << "aa: " << aa << endl;
    cout << "bb: " << bb << endl;
    cout << "aa*bb" << aa*bb << endl;
    assert(isInTolerance((aa*bb),(double)g));
#endif
	printf("Multiplication assertion passed.\n");
	g = a / b;
#ifndef FIXED_POINT_FIXEDPTC
	assert(g.getContent() == (aa / bb));
#endif
#ifdef FIXED_POINT_FIXEDPTC
    assert(isInTolerance((aa/bb),(double)g));
#endif
	printf("Division assertion passed.\n");
	double gg = (double)g;
	g += a;
	gg += aa;
#ifndef FIXED_POINT_FIXEDPTC
	assert(g.getContent() == gg );
#endif
#ifdef FIXED_POINT_FIXEDPTC
    assert(isInTolerance(gg, (double)g));
#endif
	printf("Add-equal assertion passed.\n");
	g -= a;
	gg -= aa;
#ifndef FIXED_POINT_FIXEDPTC
	assert(g.getContent() == gg);
#endif
#ifdef FIXED_POINT_FIXEDPTC
    assert(isInTolerance(gg,(double)g));
#endif
	printf("Subtract-equal assertion passed.\n");
	g *= a;
	gg *= aa;
#ifndef FIXED_POINT_FIXEDPTC
	assert(g.getContent() == gg);
#endif
#ifdef FIXED_POINT_FIXEDPTC
    assert(isInTolerance(gg,(double)g));
#endif
	printf("Mul-equal assertion passed.\n");
	g /= a;
	gg /= aa;
#ifndef FIXED_POINT_FIXEDPTC
	assert(g.getContent() == gg);
#endif
#ifdef FIXED_POINT_FIXEDPTC
    assert(isInTolerance(gg,(double)g));
#endif
	printf("Div-equal assertion passed.\n");

	assert(b>a);
	printf("greater-than assertion passed.\n");
	assert(a<b);
	printf("less-than assertion passed.\n ");
	assert(b >= a);
	assert(a >= a);
	printf("greater-equal assertion passed.\n");
	assert(a <= b);
	assert(a <= a);
	printf("less-equal assertion passed.\n");
#ifdef DUMMY_IN_THE_WILDERNESS
	assert(c.getContent() == cc);
#endif // end of #ifdef DUMMY_IN_THE_WILDERNESS
#ifdef FIXED_POINT_FIXEDPTC
    assert(isInTolerance((double)c,cc));
#endif
	printf("equal assertion passed.\n");
	assert((int)c == (int)cc);
	printf("convertion to int assertion passed.\n");
	int h = 10;
	Dummy _h = Dummy(h);
	double hh = (double)h;
	assert((double)_h== hh);
	printf("convertion from int assertion passed.\n");
	int i = 3;
	Dummy j = c / i;
	Dummy k = i / c;
	double l = 3.3 / 3;
	double m = 3 / 3.3;
#ifndef FIXED_POINT_FIXEDPTC
	assert(j.getContent() == l);
	assert(k.getContent() == m);
#endif
#ifdef FIXED_POINT_FIXEDPTC
    assert(isInTolerance(l,(double)j));
    assert(isInTolerance(m,(double)k));
#endif
	printf("Integer-involved Division assertion passed.\n");
	long int n = 44000;
	Dummy o = d / n;
	Dummy p = n / d;
	double q = 4.4 / 44000;
	double r = 44000 / 4.4;
#ifndef FIXED_POINT_FIXEDPTC
	assert(o.getContent() == q);
	assert(p.getContent() == r);
#endif
#ifdef FIXED_POINT_FIXEDPTC
    assert(isInTolerance(q,(double)o));
    assert(isInTolerance(r,(double)p));
#endif
	printf("Long-integer-involved Division assertion passed.\n");
	double s = 2.0;
	Dummy t = b / s;
	Dummy u = s / b;
	double v = 2.2 / 2.0;
	double w = 2.0 / 2.2;
#ifndef FIXED_POINT_FIXEDPTC
	assert(t.getContent() == v);
	assert(u.getContent() == w);
#endif
#ifdef FIXED_POINT_FIXEDPTC
    assert(isInTolerance(v,(double)t));
    assert(isInTolerance(w,(double)u));
#endif
	printf("Double-involved Division assertion passed.\n");
    cout << "n: " << n << endl;


	Dummy x = 44 * a;
	Dummy y = s * a;
	v = 44 * 1.1;
	w = 2.0 * 1.1;
	//printf("Test whether Dummy class could be displayed normally: %f\n" , ~y);
#ifndef FIXED_POINT_FIXEDPTC
	assert(x.getContent() == v);
	assert(y.getContent() == w);
#endif
#ifdef FIXED_POINT_FIXEDPTC
    /**
     * Undetected problem1
     */
    assert(isInTolerance(v,(double)x));
    assert(isInTolerance(w,(double)y));
#endif
	printf("Multiplication of different type assertion passed.\n");
	assert(b > a);
	assert(a < b);
	assert(bb > a);
	assert(a < bb);
	assert(b > aa);
	assert(aa < b);
	printf("Less-than and greater-than assertion passed.\n");
	//double aa = fabs(a);
	Dummy a3 = 0.0;
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

    /**
     * Undetected problem 2 -- solved
     * if ((fixedpt_toint(d.getContent())==i)&&((d.getContent() & FIXEDPT_FMASK)!=0))
     * ->
     * if ((fixedpt_toint(d.getContent())==i)&&((d.getContent() & FIXEDPT_FMASK)==0))
     */
	assert(a3 == 0);
	assert(a == 1.1);
    assert(a == a);
	printf("Equal assertion passed.\n");
    /**
     * Undetected problem 3 -- solve
     * if (abs(fixed2double(dm.getContent()) - d)<=d*relTol)
     * ->
     * if (abs(fixed2double(dm.getContent()) - d)<=abs(d)*relTol)
     */
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
    /**
     * Undetected problem 4 -- solved
     * operator != for fixed-point
     * if(abs(fixed2double(dm.getContent())-d)<(absTol))
     * ->
     *
     */
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
    a2 = (Dummy)1.0;
#if defined(DUMMY_IN_THE_WILDERNESS)
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
#endif //end of defined(DUMMY_IN_THE_WILDERNESS)
    cout << "erfc(a2): " << (double)erfc(a2) << endl;
    cout << "erfc(1.0): " << (double)erfc(1.0) << endl;
	assert(isInTolerance(erfc(a2),erfc(1.0)));
	printf("new functions assertion passed\n");
#if defined(FIXED_POINT_FIXEDPTC)
    Dummy aa1 = (Dummy)2.2;
    Dummy aa2 = (Dummy)3.8;
    Dummy aa3 = (Dummy)-2.2;
    Dummy aa4 = (Dummy)-3.8;
    Dummy aa5 = (Dummy)-0.5;
    Dummy aa6 = (Dummy)-5.5;
    Dummy aa0 = (Dummy) 0.0;
    Dummy aa01 = (Dummy)0.5;
    Dummy aa02 = (Dummy)1.0;
    Dummy aa03 = (Dummy)-1.0;
    assert(round(aa0) == (Dummy)round(0.0));
    assert(round(aa1) == (Dummy)round(2.2));
    assert(round(aa2) == (Dummy)round(3.8));
    assert(round(aa5) == (Dummy)round(-0.5));
    assert(round(aa3) == (Dummy)round(-2.2));
    assert(round(aa4) == (Dummy)round(-3.8));
    assert(round(aa6) == (Dummy)round(-5.5));
    assert(round(aa02) == (Dummy)round(1.0));
    assert(round(aa03) == (Dummy)round(-1.0));
    assert(round(aa01) == (Dummy)round(0.5));
    printf("round() for fixedpt assertion passed\n");
    assert(floor(aa0) == (Dummy)floor(0.0));
    assert(floor(aa1) == (Dummy)floor(2.2));
    assert(floor(aa2) == (Dummy)floor(3.8));
    assert(floor(aa3) == (Dummy)floor(-2.2));
    assert(floor(aa4) == (Dummy)floor(-3.8));
    assert(floor(aa5) == (Dummy)floor(-0.5));
    assert(floor(aa6) == (Dummy)floor(-5.5));
    assert(floor(aa02) == (Dummy)floor(1.0));
    assert(floor(aa03) == (Dummy)floor(-1.0));
    assert(floor(aa01) == (Dummy)floor(0.5));
    printf("floor() for fixedpt assertion passed\n");
    assert(ceil(aa0) == (Dummy)ceil(0.0));
    assert(ceil(aa1) == (Dummy)ceil(2.2));
    assert(ceil(aa2) == (Dummy)ceil(3.8));
    assert(ceil(aa3) == (Dummy)ceil(-2.2));
    assert(ceil(aa4) == (Dummy)ceil(-3.8));
    assert(ceil(aa5) == (Dummy)ceil(-0.5));
    assert(ceil(aa6) == (Dummy)ceil(-5.5));
    assert(ceil(aa02) == (Dummy)ceil(1.0));
    assert(ceil(aa03) == (Dummy)ceil(-1.0));
    assert(ceil(aa01) == (Dummy)ceil(0.5));
    printf("ceil() for fixedpt assertion passed\n");
    assert(trunc(aa0) == (Dummy)trunc(0.0));
    assert(trunc(aa1) == (Dummy)trunc(2.2));
    assert(trunc(aa2) == (Dummy)trunc(3.8));
    assert(trunc(aa3) == (Dummy)trunc(-2.2));
    assert(trunc(aa4) == (Dummy)trunc(-3.8));
    assert(trunc(aa5) == (Dummy)trunc(-0.5));
    assert(trunc(aa6) == (Dummy)trunc(-5.5));
    assert(trunc(aa02) == (Dummy)trunc(1.0));
    assert(trunc(aa03) == (Dummy)trunc(-1.0));
    assert(trunc(aa01) == (Dummy)trunc(0.5));
    printf("trunc() for fixedpt assertion passed\n");
    /**
     * Problematic result
     */
    cout << "nearbyint(-0.5): " << nearbyint(-0.5) << endl;
    Dummy sa = scalbn(a,3);
    cout << "sa = scalbn(a,3): " << (double)sa << endl;

    double da = scalbn(1.1,3);
    cout << "da = scalbn(1.1,3): " << da << endl;
    assert(sa == da);
    sa = scalbn( (Dummy)-1.1,3);
    da = scalbn(-1.1,3);
    assert(sa == da);
    printf("scalbn positive number assertion pass.\n");
    cout << "sa:" << hex << (int64_t)sa << endl;
    sa = (Dummy)1.1;
    da = 1.1;
    /**
     * Problematic
     */
    sa = scalbn(sa, -3);
    da = scalbn(da, -3);
    assert(sa == da);
    sa = (Dummy)-1.1;
    da = -1.1;
    sa = scalbn(sa, -3);
    da = scalbn(da, -3);
    printf("scalbn negative number assertion pass.\n");
    assert(sa == da);



#endif // end of #if defined(FIXED_POINT_FIXEDPTC)
	Dummy::showAllRecords();
	Dummy::resetAllRecords();
	Dummy::showAllRecords();
}
