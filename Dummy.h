// DummyClass.h : Include file for standard system include files,
// or project specific include files.


#pragma once
#ifndef DUMMY_H
#define DUMMY_H
#include "floatx.hpp"
#include "fixedptc.h"


/**
 * The following 3 definitions of preprocessing directive are used to
 * determine which data format will be put into use, only one should
 * be defined at a time
 * 1.DUMMY_IN_THE_WILDERNESS, used to test the integrity of the package
 * under C++ compiler, which in this case is g++.
 * 2.VARIABLE_FLOATING_POINT_FLOATX, used to find out the most
 * appropriate format of floating point number with the help of external
 * library FloatX
 * 3.FIXED_POINT_FIXEDPT, used to find out the most appropriate format
 * of the fixed point number with the help of external library FIXEDPT
 * When DUMMY_IN_THE_WILDERNESS is defined, dummy class will be used
 * with a double type as single private data member
 */
//#define DUMMY_IN_THE_WILDERNESS

/**
 * When VARIABLE_FLOATING_POINT_FLOATX is defined, FloatX will substitute
 * double as the single private data member
 */
//#define VARIABLE_FLOATING_POINT_FLOATX //Tested 11.04.2022

/**
 * When FIXED_POINT_FIXEDPTC is defined, FIXEDPTC will substitute
 * double as the single private data member
 */
#define FIXED_POINT_FIXEDPTC

/**
 * Change EXPONENT to change the double precision floating point number
 * format
 */
#define AVAILABLE_BITS  63
#define EXPONENT        11
#define FRACTION        (AVAILABLE_BITS-EXPONENT)
/**
 * Dummy will be used as a host of different arithmetical core components
 * and therefore should always be defined.
 */
#define DOUBLE Dummy


/**
 * "#define VFP (flx::floatx<EXPONENT, FRACTION, double>)" should always
 * be set
 */
#define VFP flx::floatx<EXPONENT, FRACTION, double>
//VFP stands for variable floating point
//#define DOUBLE (flx::floatx<EXPONENT, FRACTION, double>)


#ifdef FIXED_POINT_FIXEDPTC
//This function is only used for 64-bits
static fixedpt double2fixed(double d1){                 //131
    int exp;
    double fraction = frexp(d1,&exp);
    if((exp > (FIXEDPT_WBITS-1))||(exp < (-FIXEDPT_FBITS))) {
        throw std::invalid_argument("floating point value outside of the range fixed-point representation");
    }
    long int temp = (long int)scalb(fraction,52);
    fixedpt result = temp >> (52 - exp - FIXEDPT_FBITS);
    return result;
}
//This function is only used for 64-bits
static double fixed2double(fixedpt f1){
    return (double) fixedpt_tofloat(f1);
}
#define MAX_FP_INT_PART ((FIXEDPT_WBITS>1)?((1<<(FIXEDPT_WBITS-1))-1):0)
#endif //end of FIXED_POINT_FIXEDPTC

/**
 * According to NGSPICE manual, the convergence criteria are either a relative
 * error of 0.1%, or an absolute error of 1.0e-12, whichever is larger, hence
 * the following macro as well as the tolerance function are defined
 */
#ifndef ABSOLUTE_TOLERANCE
const double ABSOLUTE_TOLERANCE = 0.5e-12;
#endif
#ifndef RELATIVE_TOLERANCE
const double RELATIVE_TOLERANCE = 0.5e-3;
#endif

class Dummy {
#ifdef  DUMMY_IN_THE_WILDERNESS
private:
    double content;
#endif //end of Dummy_IN_THE_WILDERNESS
#ifdef VARIABLE_FLOATING_POINT_FLOATX
private:
    flx::floatx<EXPONENT, FRACTION, double>content;
#endif //end of VARIABLE_FLOATING_POINT_FLOATX
#ifdef FIXED_POINT_FIXEDPTC
private:
    fixedpt content;
#endif //end of FIXED_POINT_FIXEDPTC

/*=============== static statistical methods ===============*/
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
    static int numElem;
    /**
     * Cleaning records of operations
     */
    static void clearAdd();                             //001
    static void clearMul();                             //002
    static void clearDiv();                             //003
    static void clearConv();                            //004
    static void clearElem();                            //004-1
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
    static void incrNumElem();                          //010-1

    static void resetRecord();                          //011
    static void showRecord();                           //012
    /**
     * Recording method for exponents
     */
    static void recordExponent(const double);           //013-a
    static void recordExponent(const fixedpt);          //013-b
    static void resetExpoRecord();                      //014
    static void showExpoRecord();                       //015

    static void resetAllRecords();                      //016
    static void showAllRecords();                       //017

#endif
/*============== static statistical methods ends =============*/
    //constexpr explicit Dummy():content{ 0.0 } {};
    /* Modified by Liu Jian on 06.03.2022
     * since DOUBLE is used in unnamed union, it can't
     * initialize properly with non-trivial default
     * constructor.
     */
    Dummy() = default;


#ifdef DUMMY_IN_THE_WILDERNESS
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
#endif //end of DUMMY_IN_THE_WILDERNESS

/**
  * The function set for FloatX, the "v" behind the number means variable floating point
  */
#ifdef VARIABLE_FLOATING_POINT_FLOATX
    Dummy(VFP v):content{v}{                            //018-1-v
#ifndef DISABLE_OPERATION_STATISTICS
        recordExponent(v);
#endif
    }
   Dummy(double d){                                     //018-v
        content = VFP(d);
#ifndef DISABLE_OPERATION_STATISTICS
        recordExponent(d);
#endif
    };

    explicit Dummy(int i){                              //019-v
        content = VFP(i);
#ifndef DISABLE_OPERATION_STATISTICS
        recordExponent(content);
        incrNumConv();
#endif
    };

    explicit Dummy(long int li){                        //020-v
        content = VFP(li);
#ifndef DISABLE_OPERATION_STATISTICS
        recordExponent(content);
        incrNumConv();
#endif
    };

    explicit Dummy(unsigned int ui){                    //021-v
        content = VFP(ui);
#ifndef DISABLE_OPERATION_STATISTICS
        recordExponent(content);
        incrNumConv();
#endif
    };

    explicit Dummy(unsigned long int uli){              //022-v
        content = VFP(uli);
#ifndef DISABLE_OPERATION_STATISTICS
        recordExponent(content);
        incrNumConv();
#endif
    };

    explicit Dummy(long long unsigned int llui){        //023-v
        content = VFP(llui);
#ifndef DISABLE_OPERATION_STATISTICS
        recordExponent(content);
        incrNumConv();
#endif
    };
#endif //end of VARIABLE_FLOATING_POINT_FLOATX

 /**
  * The function set for FIXEDPT, the "f" behind the number means fixed point
  */
#ifdef FIXED_POINT_FIXEDPTC

    Dummy(fixedpt f):content{f}{                            //018-1-f
#ifndef DISABLE_OPERATION_STATISTICS
        recordExponent(fixedpt_tofloat(f));
#endif //end of DISABLE_OPERATION_STATISTICS
    }
    
    explicit Dummy(double d){                                        //018-f
        content = double2fixed(d);
#ifndef DISABLE_OPERATION_STATISTICS
        recordExponent(d);
#endif //end of DISABLE_OPERATION_STATISTICS
    };

    explicit Dummy(int i){                                  //019-f
        long int limit = ((long int)1) << FIXEDPT_WBITS;
        if(i >= limit || i <= -limit )
            throw std::invalid_argument("Input larger than acceptable range");
        content = fixedpt_fromint(i);
#ifndef DISABLE_OPERATION_STATISTICS
        recordExponent(fixedpt_tofloat(content));
        incrNumConv();
#endif //end of DISABLE_OPERATION_STATISTICS
    };
/*
    explicit Dummy(long int li){                            //020-f
        long int limit = ((long int)1) << FIXEDPT_WBITS;
        if(li >= limit || li <= -limit )
            throw std::invalid_argument("Input larger than acceptable range");
        content = fixedpt_fromint(li);
#ifndef DISABLE_OPERATION_STATISTICS
        recordExponent(fixedpt_tofloat(content));
        incrNumConv();
#endif //end of DISABLE_OPERATION_STATISTICS
    };
*/
    explicit Dummy(unsigned int ui){                        //021-f
        long int limit = ((long int)1) << FIXEDPT_WBITS;
        if(ui >= limit)
            throw std::invalid_argument("Input larger than acceptable range");
        content = fixedpt_fromint(ui);
#ifndef DISABLE_OPERATION_STATISTICS
        recordExponent(fixedpt_tofloat(content));
        incrNumConv();
#endif //end of DISABLE_OPERATION_STATISTICS
    };

    explicit Dummy(unsigned long int uli){                  //022-f
        long int limit = ((long int)1) << FIXEDPT_WBITS;
        if(uli >= limit)
            throw std::invalid_argument("Input larger than acceptable range");
        content = fixedpt_fromint(uli);
#ifndef DISABLE_OPERATION_STATISTICS
        recordExponent(fixedpt_tofloat(content));
        incrNumConv();
#endif //end of DISABLE_OPERATION_STATISTICS
    };

    explicit Dummy(long long unsigned int llui){            //023-f
        long int limit = ((long int)1) << FIXEDPT_WBITS;
        if(llui>= limit)
            throw std::invalid_argument("Input larger than acceptable range");
        content = fixedpt_fromint(llui);
#ifndef DISABLE_OPERATION_STATISTICS
        recordExponent(fixedpt_tofloat(content));
        incrNumConv();
#endif //end of DISABLE_OPERATION_STATISTICS
    };
#endif //end of FIXED_POINT_FIXEDPTC

    operator int();                                     //024
    operator int() const;                               //025
    operator long int();                                //026
    operator unsigned int();                            //027
    operator unsigned long int();                       //028
    operator unsigned long long int();                  //029
    operator float();                                   //030
    operator bool();                                    //031
    operator double();                                  //032

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

    void setContent(double);                            //033
    //void setContent(double d){content = d;};
#ifndef FIXED_POINT_FIXEDPTC
    double getContent();                                //034
#endif //end of not def FIXED_POINT_FIXEDPTC

#ifdef  FIXED_POINT_FIXEDPTC
    fixedpt getContent();                               //034-f
#endif // end of def FIXED_POINT_FIXEDPTC
    bool operator!();                                   //035
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
    /**
     * The reason for no overloaded operator= is that there are multiple cases
     * of unnamed union that contain Dummy class, adding overloaded operator=
     * will lead to the unions can not be initialized.
     */
     /*
#ifdef VARIABLE_FLOATING_POINT_FLOATX
    Dummy operator=(Dummy&);                      //091.5-1
    Dummy operator=(const double);                      //091.5-2
    //Dummy operator=(const float);                       //091.5-3
#endif // end of VARIABLE_FLOATING_POINT_FLOATX
      */
};

/**
 * Elementary Functions
 */
DOUBLE acos(DOUBLE);                                    //092
DOUBLE acosh(DOUBLE);                                   //093
DOUBLE asin(DOUBLE);                                    //094
DOUBLE asinh(DOUBLE);                                   //095
DOUBLE atan(DOUBLE);                                    //096
DOUBLE atan2(DOUBLE,DOUBLE);                            //097
DOUBLE atanh(DOUBLE);                                   //098
DOUBLE cos(DOUBLE);                                     //099
DOUBLE cosh(DOUBLE);                                    //100
DOUBLE exp(DOUBLE);                                     //101
DOUBLE hypot(DOUBLE,DOUBLE);                            //102
DOUBLE log(DOUBLE);                                     //103
DOUBLE logb(DOUBLE);                                    //104
DOUBLE log10(DOUBLE);                                   //105
DOUBLE pow(DOUBLE,DOUBLE);                              //106
DOUBLE pow(double,DOUBLE);                              //107
DOUBLE pow(DOUBLE,double);                              //108
DOUBLE sin(DOUBLE);                                     //109
DOUBLE sinh(DOUBLE);                                    //110
DOUBLE sqrt(DOUBLE);                                    //111
DOUBLE tan(DOUBLE);                                     //112
DOUBLE tanh(DOUBLE);                                    //113


DOUBLE abs(DOUBLE);                                     //114
DOUBLE ceil(DOUBLE);                                    //115
DOUBLE fabs(DOUBLE);                                    //116
DOUBLE floor(DOUBLE);                                   //117
DOUBLE frexp(DOUBLE r, int* exp);                       //118
DOUBLE isnan(DOUBLE);                                   //119
DOUBLE modf(DOUBLE, DOUBLE*);                           //120
DOUBLE modf(double, DOUBLE*);                           //121
DOUBLE nearbyint(DOUBLE);                               //122
DOUBLE round(DOUBLE);                                   //123
DOUBLE scalbn(DOUBLE,int);                              //124
DOUBLE trunc(DOUBLE);                                   //125


int fpclassify(DOUBLE d);                               //126
bool isfinite(DOUBLE d);                                //127
bool isnormal(DOUBLE d);                                //128
bool isinf(DOUBLE d);                                   //129
DOUBLE erfc(DOUBLE d);                                  //130



#endif // !DUMMY_H
