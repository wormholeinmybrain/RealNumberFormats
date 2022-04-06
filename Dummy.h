// DummyClass.h : Include file for standard system include files,
// or project specific include files.


#pragma once
#ifndef DUMMY_H
#define DUMMY_H
//#include "floatx.hpp"


/**
 * When DUMMY_IN_THE_WILDERNESS is defined, dummy class will be used
 * to verify the installation
 */
#define DUMMY_IN_THE_WILDERNESS
//#define DOUBLE Dummy


/**
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
 *
 * "#define VFP (flx::floatx<EXPONENT, FRACTION, double>)" should be
 * set only when floatx is used
 */
 /*
  * FloatX is abandoned for not being able to represent floating point
  * numbers with arbitrary combinations of exponent and fraction
#define VFP (flx::floatx<EXPONENT, FRACTION, double>)
*/


class Dummy {
#ifdef  DUMMY_IN_THE_WILDERNESS
private:
    double content;
#endif

#ifndef DISABLE_OPERATION_STATISTICS
    /**
     * Records of the minimum as well as the maximum
     * exponent of the floating point number
     */
    static int maxExponent;
    static int minExponent;

    /**
     * Records of the number of different kind of
     * operations
     */
    static int numAdd;
    static int numMul;
    static int numDiv;
    static int numConv;
    /**
     * Cleaning records of operations
     */
    static void clearAdd();                             //001
    static void clearMul();                             //002
    static void clearDiv();                             //003
    static void clearConv();                            //004
    /**
     * Cleaning record of exponent
     */
    static void clearMaxExpo();                         //005
    static void clearMinExpo();                         //006

#endif


public:
#ifndef DISABLE_OPERATION_STATISTICS
    /**
     * Recording methods for operations
     */
    static void incrNumAdd();                           //007
    static void incrNumMul();                           //008
    static void incrNumDiv();                           //009
    static void incrNumConv();                          //010
    static void resetRecord();                          //011
    static void showRecord();                           //012
    /**
     * Recording method for exponents
     */
    static void recordExponent(const double);           //013
    static void resetExpoRecord();                      //014
    static void showExpoRecord();                       //015

    static void resetAllRecords();                      //016
    static void showAllRecords();                       //017

#endif
    //constexpr explicit Dummy():content{ 0.0 } {};
    /* Modified by Liu Jian on 06.03.2022
     * since DOUBLE is used in unnamed union, it can't
     * initialize properly with non-trivial default
     * constructor.
     */
    Dummy() = default;

/**TODO
 * 1. remove all function declaration from dummy.h
 * 2. insert exponent recording methods as well as preprocessing directives
 * @param
 */


    constexpr Dummy(double d):content{d}{               //018
#ifndef DISABLE_OPERATION_STATISTICS
        recordExponent(d);
#endif
    };

    explicit Dummy(int i){                              //019
        content = double(i);
#ifndef DISABLE_OPERATION_STATISTICS
        recordExponent(content);
        incrNumConv();
#endif
    };

    explicit Dummy(long int li){                        //020
        content = double(li);
#ifndef DISABLE_OPERATION_STATISTICS
        recordExponent(content);
        incrNumConv();
#endif
    };

    explicit Dummy(unsigned int ui){                    //021
        content = double(ui);
#ifndef DISABLE_OPERATION_STATISTICS
        recordExponent(content);
        incrNumConv();
#endif
    };

    explicit Dummy(unsigned long int uli){              //022
        content = double(uli);
#ifndef DISABLE_OPERATION_STATISTICS
        recordExponent(content);
        incrNumConv();
#endif
    };

    explicit Dummy(long long unsigned int llui){        //023
        content = double(llui);
#ifndef DISABLE_OPERATION_STATISTICS
        recordExponent(content);
        incrNumConv();
#endif
    };

    operator int();                                     //024
    operator int() const;                               //025
    operator long int();                                //026
    operator unsigned int();                            //027
    operator unsigned long int();                       //028
    operator unsigned long long int();                  //029
    operator float();                                   //030
    operator double();                                  //031
    operator bool();                                    //032

    /**
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
    */
    //operator bool() {return (bool)content;};

    bool operator!();                                   //033
    //void setContent(double d){content = d;};
    void setContent(double);                            //034
    double getContent();                                //035
    friend Dummy operator*(Dummy, Dummy);               //036
    friend Dummy operator*(Dummy, double);              //037
    friend Dummy operator*(double, Dummy);              //038
    friend Dummy operator*(long int, Dummy);            //039
    friend Dummy operator*(Dummy,long int);             //040
    friend Dummy operator*(Dummy, int);                 //041
    friend Dummy operator*(int, Dummy);                 //042
    friend Dummy operator/(Dummy, Dummy);               //043
    friend Dummy operator/(long int, Dummy);            //044
    friend Dummy operator/(Dummy, long int);            //045
    friend Dummy operator/(int, Dummy);                 //046
    friend Dummy operator/(Dummy, int);                 //047
    friend Dummy operator/(Dummy, double);              //048
    friend Dummy operator/(double, Dummy);              //049
    friend Dummy operator/(unsigned int, Dummy);        //050
    friend Dummy operator-(Dummy);                      //051
    friend Dummy operator-(Dummy, Dummy);               //052
    friend Dummy operator-(Dummy, double);              //053
    friend Dummy operator-(Dummy, int);                 //054
    friend Dummy operator-(double, Dummy);              //055
    friend Dummy operator-(int, Dummy);                 //056
    friend Dummy operator+(Dummy, Dummy);               //057
    friend Dummy operator+(Dummy, double);              //058
    friend Dummy operator+(Dummy, int);                 //059
    friend Dummy operator+(double, Dummy);              //060
    friend Dummy operator+(int, Dummy);                 //061
    friend Dummy operator+(Dummy);                      //062
    friend bool operator>=(Dummy,Dummy);                //063
    friend bool operator>=(Dummy, double);              //064
    friend bool operator>=(Dummy, int);                 //065
    friend bool operator>=(Dummy, long int);            //066
    friend bool operator==(Dummy, Dummy);               //067
    friend bool operator==(Dummy, double);              //068
    friend bool operator==(Dummy, int);                 //069
    friend bool operator==(double, Dummy);              //070
    friend bool operator<=(Dummy, Dummy);               //071
    friend bool operator<=(Dummy, double);              //072
    friend bool operator<=(Dummy, int);                 //073
    friend bool operator<=(Dummy, long int);            //074
    friend bool operator<=(double, Dummy);              //075
    friend bool operator!=(Dummy, Dummy);               //076
    friend bool operator!=(Dummy, double);              //077
    friend bool operator!=(Dummy, int);                 //078
    friend bool operator!=(double, Dummy);              //079
    friend bool operator>(Dummy, Dummy);                //080
    friend bool operator>(double, Dummy);               //081
    friend bool operator>(Dummy, double);               //082
    friend bool operator>(Dummy, int);                  //083
    friend bool operator<(Dummy, Dummy);                //084
    friend bool operator<(Dummy, double);               //085
    friend bool operator<(double, Dummy);               //086
    friend bool operator<(Dummy, int);                  //087

    Dummy operator+=(Dummy);                            //088
    Dummy operator-=(Dummy);                            //089
    Dummy operator*=(Dummy);                            //090
    Dummy operator/=(Dummy);                            //091
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


DOUBLE fabs(DOUBLE);                                    //092
DOUBLE atan2(DOUBLE,DOUBLE);                            //093
DOUBLE floor(DOUBLE);                                   //094
DOUBLE log10(DOUBLE);                                   //095
DOUBLE hypot(DOUBLE,DOUBLE);                            //096
DOUBLE log(DOUBLE);                                     //097
DOUBLE exp(DOUBLE);                                     //098
DOUBLE cos(DOUBLE);                                     //099
DOUBLE sin(DOUBLE);                                     //100
DOUBLE cosh(DOUBLE);                                    //101
DOUBLE sinh(DOUBLE);                                    //102
DOUBLE tan(DOUBLE);                                     //103
DOUBLE tanh(DOUBLE);                                    //104
DOUBLE atan(DOUBLE);                                    //105
DOUBLE ceil(DOUBLE);                                    //106
DOUBLE nearbyint(DOUBLE);                               //107
DOUBLE pow(DOUBLE,DOUBLE);                              //108
DOUBLE pow(double,DOUBLE);                              //109
DOUBLE pow(DOUBLE,double);                              //110
DOUBLE sqrt(DOUBLE);                                    //111
DOUBLE isnan(DOUBLE);                                   //112
DOUBLE logb(DOUBLE);                                    //113
DOUBLE scalbn(DOUBLE,int);                              //114
DOUBLE asin(DOUBLE);                                    //115
DOUBLE acos(DOUBLE);                                    //116
DOUBLE trunc(DOUBLE);                                   //117
DOUBLE atanh(DOUBLE);                                   //118
DOUBLE acosh(DOUBLE);                                   //119
DOUBLE asinh(DOUBLE);                                   //120
DOUBLE round(DOUBLE);                                   //121
DOUBLE abs(DOUBLE);                                     //122
DOUBLE modf(DOUBLE, DOUBLE*);                           //123
DOUBLE modf(double, DOUBLE*);                           //124





DOUBLE frexp(DOUBLE r, int* exp);                       //125
int fpclassify(DOUBLE d);                               //126
bool isfinite(DOUBLE d);                                //127
bool isnormal(DOUBLE d);                                //128
bool isinf(DOUBLE d);                                   //129
DOUBLE erfc(DOUBLE d);                                  //130

#endif // !DUMMY_H
