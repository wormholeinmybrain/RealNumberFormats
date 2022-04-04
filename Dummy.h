// DummyClass.h : Include file for standard system include files,
// or project specific include files.


#pragma once
#ifndef DUMMY_H
#define DUMMY_H
#include "floatx.hpp"
/**
 * 
 */

/**
 * When DUMMY_IN_THE_WILDERNESS is defined, dummy class will be used
 * to verify the installation
 */
//#define DUMMY_IN_THE_WILDERNESS
//#define DOUBLE Dummy

/**
 * When VARIABLE_FLOATING_POINT_FLOATX is defined, floatx will be used
 */
#define VARIABLE_FLOATING_POINT_FLOATX

**
* When VARIABLE_FLOATING_POINT_SOFTFLOAT is defined, floatx will be used
*/
//#define VARIABLE_FLOATING_POINT_SOFTFLOAT

/**
 * When FIXED_POINT_FPM is defined, FPM will be used
 */
//#define FIXED_POINT_FPM

/**
 * Change EXPONENT to change the double precision floating point number
 * format
 */
#define AVAILABLE_BITS  63
#define EXPONENT        11
#define FRACTION        (AVAILABLE_BITS-EXPONENT)

/**
 * "#define Double Dummy" should always be set to substitute double
 */
#define DOUBLE Dummy

/**
 * "#define VFP (flx::floatx<EXPONENT, FRACTION, double>)" should be
 * set only when floatx is used
 */
#define VFP (flx::floatx<EXPONENT, FRACTION, double>)



class Dummy {
private:
    double content;
#ifndef DISABLE_OPERATION_STATISTICS
    static int numAdd;
    static int numMul;
    static int numDiv;
    static int numConv;
    static void clearAdd();
    static void clearMul();
    static void clearDiv();
    static void clearConv();
#endif


public:
#ifndef DISABLE_OPERATION_STATISTICS
    static void incrNumAdd();
    static void incrNumMul();
    static void incrNumDiv();
    static void incrNumConv();
    static void resetRecord();
    static void showRecord();
#endif
    //constexpr explicit Dummy():content{ 0.0 } {};
    /* Modified by Liu Jian on 06.03.2022
     * since DOUBLE is used in unnamed union, it can't
     * initialize properly with non-trivial default
     * constructor.
     */
    Dummy() = default;
    constexpr Dummy(double d) :content{ d } {};
    explicit Dummy(int i) :content{ (double)i } { incrNumConv();};
    explicit Dummy(unsigned long int uli):content{ (double)uli } {incrNumConv();};
    explicit Dummy(long int li) :content{ (double)li } { incrNumConv();};
    explicit Dummy(unsigned int ui):content{(double)ui } {incrNumConv();};
    explicit Dummy(long long unsigned int llui) :content{ (double)llui } { incrNumConv(); };
    void setContent(double d){content = d;};
    double getContent() { return content; };
    friend Dummy operator*(Dummy, Dummy);
    friend Dummy operator*(Dummy, double);
    friend Dummy operator*(double, Dummy);
    friend Dummy operator*(long int, Dummy);
    friend Dummy operator*(Dummy,long int);
    friend Dummy operator*(Dummy, int);
    friend Dummy operator*(int, Dummy);
    friend Dummy operator/(Dummy, Dummy);
    friend Dummy operator/(long int, Dummy);
    friend Dummy operator/(Dummy, long int);
    friend Dummy operator/(int, Dummy);
    friend Dummy operator/(Dummy, int);
    friend Dummy operator/(Dummy, double);
    friend Dummy operator/(double, Dummy);
    friend Dummy operator/(unsigned int, Dummy);
    double& operator~();                    //to eliminate warning from printf
    operator long int() {
        incrNumConv();
        return (long int)content;
    };
    operator double() {
        return content;
    }
    operator int() const{
        incrNumConv();
        return (int)content;
    }
    operator int() {
        incrNumConv();
        return (int)content;
    }
    operator unsigned int(){
        incrNumConv();
        return (unsigned int)content;
    }
    operator long unsigned int(){
        incrNumConv();
        return (long unsigned int)content;
    }
    operator float(){
        incrNumConv();
        return (float)content;
    }

    operator unsigned long long int(){
        incrNumConv();
        return (unsigned long long int)content;
    }


    friend Dummy operator-(Dummy);
    friend Dummy operator-(Dummy, Dummy);
    friend Dummy operator-(Dummy, double);
    friend Dummy operator-(Dummy, int);
    friend Dummy operator-(double, Dummy);
    friend Dummy operator-(int, Dummy);
    friend Dummy operator+(Dummy, Dummy);
    friend Dummy operator+(Dummy, double);
    friend Dummy operator+(Dummy, int);
    friend Dummy operator+(double, Dummy);
    friend Dummy operator+(int, Dummy);
    friend Dummy operator+(Dummy);
    friend bool operator>=(Dummy,Dummy);
    friend bool operator>=(Dummy, double);
    friend bool operator>=(Dummy, int);
    friend bool operator>=(Dummy, long int);
    friend bool operator==(Dummy, Dummy);
    friend bool operator==(Dummy, double);
    friend bool operator==(Dummy, int);
    friend bool operator==(double, Dummy);
    friend bool operator<=(Dummy, Dummy);
    friend bool operator<=(Dummy, double);
    friend bool operator<=(Dummy, int);
    friend bool operator<=(Dummy, long int);
    friend bool operator<=(double, Dummy);
    friend bool operator!=(Dummy, Dummy);
    friend bool operator!=(Dummy, double);
    friend bool operator!=(Dummy, int);
    friend bool operator!=(double, Dummy);
    friend bool operator>(Dummy, Dummy);
    friend bool operator>(double, Dummy);
    friend bool operator>(Dummy, double);
    friend bool operator>(Dummy, int);
    friend bool operator<(Dummy, Dummy);
    friend bool operator<(Dummy, double);
    friend bool operator<(double, Dummy);
    friend bool operator<(Dummy, int);
    bool operator!();
    operator bool() {return (bool)content;};
    Dummy operator+=(Dummy);
    Dummy operator-=(Dummy);
    Dummy operator*=(Dummy);
    Dummy operator/=(Dummy);
    //The overloaded "=" methods are referenced to the following stackoverflow question:
    //https://stackoverflow.com/questions/60660058
    // /c-assign-operator-to-copy-between-volatile-and-non-volatile-instances-of-a-cla
    /*
    volatile Dummy& operator = (const volatile Dummy& dm) volatile {
        content = dm.content;
        return *this;
    }

    Dummy& operator = (const Dummy& dm) {
        content = dm.content;
        return *this;
    }

    volatile Dummy& operator = (const Dummy& dm) volatile {
        content = dm.content;
        return *this;
    }

    Dummy& operator = (const volatile Dummy& dm) {
        content = dm.content;
        return *this;
    }
     */
};

DOUBLE fabs(DOUBLE);
DOUBLE atan2(DOUBLE,DOUBLE);
DOUBLE floor(DOUBLE);
DOUBLE log10(DOUBLE);
DOUBLE hypot(DOUBLE,DOUBLE);
DOUBLE log(DOUBLE);
DOUBLE exp(DOUBLE);
DOUBLE cos(DOUBLE);
DOUBLE sin(DOUBLE);
DOUBLE cosh(DOUBLE);
DOUBLE sinh(DOUBLE);
DOUBLE tan(DOUBLE);
DOUBLE tanh(DOUBLE);
DOUBLE atan(DOUBLE);
DOUBLE ceil(DOUBLE);
DOUBLE nearbyint(DOUBLE);
DOUBLE pow(DOUBLE,DOUBLE);
DOUBLE pow(double,DOUBLE);
DOUBLE pow(DOUBLE,double);
DOUBLE sqrt(DOUBLE);
DOUBLE isnan(DOUBLE);
DOUBLE logb(DOUBLE);
DOUBLE scalbn(DOUBLE,int);
DOUBLE asin(DOUBLE);
DOUBLE acos(DOUBLE);
DOUBLE trunc(DOUBLE);
DOUBLE atanh(DOUBLE);
DOUBLE acosh(DOUBLE);
DOUBLE asinh(DOUBLE);
DOUBLE round(DOUBLE);
DOUBLE abs(DOUBLE);
DOUBLE modf(DOUBLE, DOUBLE*);
DOUBLE modf(double, DOUBLE*);

// Done: These functions need implementations or there will be linker errors!
DOUBLE frexp(DOUBLE r, int* exp);
int fpclassify(DOUBLE d);
bool isfinite(DOUBLE d);
bool isnormal(DOUBLE d);
bool isinf(DOUBLE d);
DOUBLE erfc(DOUBLE d);

#endif // !DUMMY_H
