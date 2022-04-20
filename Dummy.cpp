// DummyClass.cpp : Defines the entry point for the application.
//
#include <cstdio>
#include "Dummy.h"
#include <cmath>
#include <climits>
using namespace std;
#ifndef DISABLE_OPERATION_STATISTICS
int Dummy::numAdd = 0;
int Dummy::numMul = 0;
int Dummy::numDiv = 0;
int Dummy::numConv = 0;
int Dummy::numElem = 0;
int Dummy::maxExponent = INT_MIN;
int Dummy::minExponent = INT_MAX;

//001
void Dummy::clearAdd() {
    numAdd = 0;
}

//002
void Dummy::clearMul() {
    numMul = 0;
}

//003
void Dummy::clearDiv() {
    numDiv = 0;
}

//004
void Dummy::clearConv() {
    numConv = 0;
}

//004-1
void Dummy::clearElem() {
    numElem = 0;
}

//005
void Dummy::clearMaxExpo(){
    maxExponent = INT_MIN;
}

//006
void Dummy::clearMinExpo(){
    minExponent = INT_MAX;
}

//007
void Dummy::incrNumAdd(){
    numAdd++;
}

//008
void Dummy::incrNumMul(){
    numMul++;
}

//009
void Dummy::incrNumDiv(){
    numDiv++;
}

//010
void Dummy::incrNumConv(){
    numConv++;
}

void Dummy::incrNumElem(){
    numConv++;
}

//011
void Dummy::resetRecord() {
    clearAdd();
    clearMul();
    clearDiv();
    clearConv();
    clearElem();
    printf("Record of operation reset. \n");
}

//012
void Dummy::showRecord() {
    printf("Number of Addition/Subtraction: %i \n", numAdd);
    printf("Number of Multiplication: %i \n", numMul);
    printf("Number of Division: %i \n", numDiv);
    printf("Number of Conversion to other data type: %i \n", numConv);
    printf("Number of Conversion to other data type: %i \n", numElem);
}

//013-a
void Dummy::recordExponent(const double d){
    int i = 0;
    frexp(d,&i);
    if(i>maxExponent)
        maxExponent = i;
    if(i<minExponent)
        minExponent = i;
}

//013-b
void Dummy::recordExponent(const fixedpt f) {
    int i = 0;
    frexp(fixedpt_tofloat(f),&i);
    if(i>maxExponent)
        maxExponent = i;
    if(i<minExponent)
        minExponent = i;
}

//014
void Dummy::resetExpoRecord(){
    clearMaxExpo();
    clearMinExpo();
    printf("Record of exponent reset. \n");
}

//015
void Dummy::showExpoRecord(){
    printf("Maximal Exponent Occurrence: %i\n", maxExponent);
    printf("Minimal Exponent Occurrence: %i\n", minExponent);
}

//016
void Dummy::resetAllRecords(){
    resetRecord();
    resetExpoRecord();
    printf("All records reset. \n");
}

//017
void Dummy::showAllRecords(){
    showRecord();
    showExpoRecord();
}
#endif
/**
 * Since the exponent is recorded at the time of initiation,
 * it doesn't need to be done for a second time.
*/
#ifndef FIXED_POINT_FIXEDPTC
//024
Dummy::operator int(){
#ifndef DISABLE_OPERATION_STATISTICS
    incrNumConv();
#endif
    return int(content);
}

//025
Dummy::operator int() const{
#ifndef DISABLE_OPERATION_STATISTICS
    incrNumConv();
#endif
    return int(content);
}

//026
Dummy::operator long int(){
#ifndef DISABLE_OPERATION_STATISTICS
    incrNumConv();
#endif
    return (long int)content;
}

//027
Dummy::operator unsigned int(){
#ifndef DISABLE_OPERATION_STATISTICS
    incrNumConv();
#endif
    return (unsigned int)content;
}

//028
Dummy::operator long unsigned int(){
#ifndef DISABLE_OPERATION_STATISTICS
    incrNumConv();
#endif
    return (long unsigned int)content;
}

//029
Dummy::operator unsigned long long int(){
#ifndef DISABLE_OPERATION_STATISTICS
    incrNumConv();
#endif
    return (unsigned long long int)content;
}

//030
Dummy::operator float(){
    return float(content);
}

//031
Dummy::operator bool(){
#ifndef DISABLE_OPERATION_STATISTICS
    incrNumConv();
#endif
    return bool(content);
}

/**
 * Dummy for test purpose
 */
#ifdef DUMMY_IN_THE_WILDERNESS
//032
Dummy::operator double(){
    return content;
}
//033
void Dummy::setContent(double d){
#ifndef DISABLE_OPERATION_STATISTICS
    recordExponent(d);
#endif
    content = d;
}

//034
double Dummy::getContent(){
    return content;
}
#endif //end of DUMMY_IN_THE_WILDERNESS

/**
 *  Floatx for experimenting different floating point number format
 */
#ifdef VARIABLE_FLOATING_POINT_FLOATX
//032-v
Dummy::operator double(){
    return double(content);
}
//033-v
void Dummy::setContent(double d){
#ifndef DISABLE_OPERATION_STATISTICS
    recordExponent(d);
#endif
    content = VFP(d);
}

//034-v
double Dummy::getContent(){
    return content;
}
#endif //end of VARIABLE_FLOATING_POINT_FLOATX


/**
 * Need testing
 */
//035
bool Dummy::operator!() {
    return !content;
}

//036
Dummy operator*(Dummy d1,Dummy d2 ) {
    Dummy dum = Dummy(d1.getContent() * d2.getContent());
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumMul();
    Dummy::recordExponent(dum.getContent());
#endif
    return dum;
}

//037
Dummy operator*(Dummy dm,double d1) {
    Dummy dum = Dummy(dm.getContent() * d1);
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumMul();
    Dummy::recordExponent(dum.getContent());
#endif
    return dum;
}

//038
Dummy operator*(double d1, Dummy dm) {
    Dummy dum = Dummy(d1 * dm.getContent());
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumMul();
    Dummy::recordExponent(dum.getContent());
#endif
    return dum;
}

//039
Dummy operator*(Dummy d1,long int l) {
    Dummy dum = Dummy(d1.getContent() * (double)l);
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumConv();
    Dummy::incrNumMul();
    Dummy::recordExponent(dum.getContent());
#endif
    return dum;
}

//040
Dummy operator*(long int l, Dummy dm) {
    Dummy dum = Dummy((double)l* dm.getContent());
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumConv();
    Dummy::incrNumMul();
    Dummy::recordExponent(dum.getContent());
#endif
    return dum;
}

//041
Dummy operator*(int i, Dummy dm) {
    Dummy dum = Dummy((double)i* dm.getContent());
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumConv();
    Dummy::incrNumMul();
    Dummy::recordExponent(dum.getContent());
#endif
    return dum;
}

//042
Dummy operator*(Dummy dm, int i) {
    Dummy dum = Dummy((double)i* dm.getContent());
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumConv();
    Dummy::incrNumMul();
    Dummy::recordExponent(dum.getContent());
#endif
    return dum;
}

//043
Dummy operator/(Dummy d1, Dummy d2) {
    Dummy dum = Dummy(d1.getContent() / d2.getContent());
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumDiv();
    Dummy::recordExponent(dum.getContent());
#endif
    return dum;
}

//044
Dummy operator/(long int l, Dummy dm) {
    Dummy dum = Dummy((double)l / dm.getContent());
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumDiv();
    Dummy::incrNumConv();
    Dummy::recordExponent(dum.getContent());
#endif
    return dum;
}

//045
Dummy operator/(Dummy dm, long int l) {
    Dummy dum = Dummy(dm.getContent() / (double)l);
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumDiv();
    Dummy::incrNumConv();
    Dummy::recordExponent(dum.getContent());
#endif
    return dum;
}

//046
Dummy operator/(int i, Dummy dm) {
    Dummy dum = Dummy((double)i / dm.getContent());
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumDiv();
    Dummy::incrNumConv();
    Dummy::recordExponent(dum.getContent());
#endif
    return dum;
}

//047
Dummy operator/(Dummy dm, int i) {
    Dummy dum = Dummy( dm.getContent() / (double)i);
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumDiv();
    Dummy::incrNumConv();
    Dummy::recordExponent(dum.getContent());
#endif
    return dum;
}

//048
Dummy operator/(Dummy dm, double d) {
    Dummy dum = Dummy(dm.getContent() / d);
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumDiv();
    Dummy::recordExponent(dum.getContent());
#endif
    return dum;
}

//049
Dummy operator/(double d, Dummy dm) {
    Dummy dum = Dummy(d / dm.getContent());
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumDiv();
    Dummy::recordExponent(dum.getContent());
#endif
    return dum;
}

//050
Dummy operator/(unsigned int ui, Dummy d){
    Dummy dum = Dummy((double)ui/d.getContent());
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumDiv();
    Dummy::incrNumConv();
    Dummy::recordExponent(dum.getContent());
#endif
    return dum;
}
/*
double& Dummy::operator~() {
    return content;
}
*/
//051
Dummy operator-(Dummy d) {
    return Dummy(-d.getContent());
}

//052
Dummy operator-(Dummy d1, Dummy d2) {
    Dummy dum = Dummy(d1.getContent() - d2.getContent());
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
    Dummy::recordExponent(dum.getContent());
#endif
    return dum;
}

//053
Dummy operator-(Dummy dm, double d) {
    Dummy dum = Dummy(dm.getContent()-d);
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
    Dummy::recordExponent(dum.getContent());
#endif
    return dum;
}

//054
Dummy operator-(Dummy d, int i) {
    Dummy dum = Dummy(d.getContent() - (double)i);
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
    Dummy::incrNumConv();
    Dummy::recordExponent(dum.getContent());
#endif
    return dum;
}

//055
Dummy operator-(double d, Dummy dm ) {
    Dummy dum = Dummy(d - dm.getContent());
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
    Dummy::recordExponent(dum.getContent());
#endif
    return dum;
}

//056
Dummy operator-(int i, Dummy d) {
    Dummy dum = Dummy((double) i - d.getContent());
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
    Dummy::incrNumConv();
    Dummy::recordExponent(dum.getContent());
#endif
    return dum;
}

//057
Dummy operator+(Dummy d1, Dummy d2) {
    Dummy dum = Dummy(d1.getContent()+d2.getContent());
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
    Dummy::recordExponent(dum.getContent());
#endif
    return dum;
}

//058
Dummy operator+(Dummy dm, double d) {
    Dummy dum = Dummy(dm.getContent() + d);
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
    Dummy::recordExponent(dum.getContent());
#endif
    return dum;
}

//059
Dummy operator+(Dummy d, int i) {
    Dummy dum = Dummy(d.getContent() + double(i));
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
    Dummy::incrNumConv();
    Dummy::recordExponent(dum.getContent());
#endif
    return dum;
}

//060
Dummy operator+(double d, Dummy dm) {
    Dummy dum = Dummy(d + dm.getContent() );
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
    Dummy::recordExponent(dum.getContent());
#endif
    return dum;
}

//061
Dummy operator+(int i, Dummy d) {
    Dummy dum = Dummy(double(i) + d.getContent());
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
    Dummy::incrNumConv();
    Dummy::recordExponent(dum.getContent());
#endif
    return dum;
}

//062
Dummy operator+(Dummy d) {
    return d;
}

//063
bool operator>=(Dummy d1, Dummy d2) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
#endif
    if (d1.getContent() >= d2.getContent())
        return true;
    else
        return false;
}

//064
bool operator>=(Dummy dm, double d) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
#endif
    if (dm.getContent() >= d)
        return true;
    else
        return false;
}

//065
bool operator>=(Dummy d, int i) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
    Dummy::incrNumConv();
#endif
    if (d.getContent() >= (double)i)
        return true;
    else
        return false;
}

//066
bool operator>=(Dummy d, long int li) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
    Dummy::incrNumConv();
#endif
    double dli = double(li);
    if (d.getContent() >= dli)
        return true;
    else
        return false;
}

//067
bool operator==(Dummy d1, Dummy d2) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
#endif
    if (d1.getContent() == d2.getContent())
        return true;
    else
        return false;
}

//068
bool operator==(Dummy dm, double d) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
#endif
    if (dm.getContent() == d)
        return true;
    else
        return false;
}

//069
bool operator==(Dummy d, int i) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
    Dummy::incrNumConv();
#endif
    if (d.getContent() == (double)i)
        return true;
    else
        return false;
}

//070
bool operator==(double d, Dummy dm ) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
#endif
    if (dm.getContent() == d)
        return true;
    else
        return false;
}

//071
bool operator<=(Dummy d1, Dummy d2) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
#endif
    if (d1.getContent() <= d2.getContent())
        return true;
    else
        return false;
}

//072
bool operator<=(Dummy dm, double d) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
#endif
    if (dm.getContent() <= d)
        return true;
    else
        return false;
}

//073
bool operator<=(Dummy d, int i) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
    Dummy::incrNumConv();
#endif
    if (d.getContent() <= (double)i)
        return true;
    else
        return false;
}

//074
bool operator<=(Dummy d, long int li) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
    Dummy::incrNumConv();
#endif
    double dli = double(li);
    if (d.getContent() <= dli)
        return true;
    else
        return false;
}

//075
bool operator<=(double d, Dummy dm) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
#endif
    if (d <= dm.getContent())
        return true;
    else
        return false;
}

//076
bool operator!=(Dummy d1, Dummy d2) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
#endif
    if (d1.getContent() != d2.getContent())
        return true;
    else
        return false;
}

//077
bool operator!=(Dummy dm, double d ) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
#endif
    if (dm.getContent() != d)
        return true;
    else
        return false;
}

//078
bool operator!=(Dummy d, int i) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
    Dummy::incrNumConv();
#endif
    if (d.getContent() != (double)i)
        return true;
    else
        return false;
}

//079
bool operator!=(double d, Dummy dm  ) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
#endif
    if ( d != dm.getContent())
        return true;
    else
        return false;
}

//080
bool operator>(Dummy d1, Dummy d2) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
#endif
    if (d1.getContent() > d2.getContent())
        return true;
    else
        return false;
}

//081
bool operator>(double d1, Dummy d2) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
#endif
    if (d1 > d2.getContent())
        return true;
    else
        return false;
}

//082
bool operator>(Dummy d1, double d2) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
#endif
    if (d1.getContent() > d2)
        return true;
    else
        return false;
}

//083
bool operator>(Dummy d, int i) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
    Dummy::incrNumConv();
#endif
    double di = double(i);
    if (d.getContent() > di)
        return true;
    else
        return false;
}

//084
bool operator<(Dummy d1, Dummy d2) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
#endif
    if (d1.getContent() < d2.getContent())
        return true;
    else
        return false;
}

//085
bool operator<(Dummy d1, double d2) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
#endif
    if (d1.getContent() < d2)
        return true;
    else
        return false;
}

//086
bool operator<(double d1, Dummy d2) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
#endif
    if (d1 < d2.getContent())
        return true;
    else
        return false;
}

//087
bool operator<(Dummy d, int i) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
    Dummy::incrNumConv();
#endif
    double di = double(i);
    if (d.getContent() < di)
        return true;
    else
        return false;
}

//088
Dummy Dummy::operator+=(Dummy d) {
    content = content + d.content;
#ifndef DISABLE_OPERATION_STATISTICS
    incrNumAdd();
    recordExponent(content);
#endif
    return Dummy(content);
}

//089
Dummy Dummy::operator-=(Dummy d) {
    content = content - d.content;
#ifndef DISABLE_OPERATION_STATISTICS
    incrNumAdd();
    recordExponent(content);
#endif
    return Dummy(content);
}

//090
Dummy Dummy::operator*=(Dummy d) {
    content = content * d.content;
#ifndef DISABLE_OPERATION_STATISTICS
    incrNumMul();
    recordExponent(content);
#endif
    return Dummy(content);
}

//091
Dummy Dummy::operator/=(Dummy d) {
    content = content / d.content;
#ifndef DISABLE_OPERATION_STATISTICS
    incrNumDiv();
    recordExponent(content);
#endif
    return Dummy(content);
}
/*
#ifdef VARIABLE_FLOATING_POINT_FLOATX
//091.5-1
Dummy Dummy::operator=(Dummy& dm){
    content = dm.content;
#ifndef DISABLE_OPERATION_STATISTICS
    recordExponent(content);
#endif
    return *this;
}

//091.5-2
Dummy Dummy::operator=(const double d){
    content = VFP(d);
#ifndef DISABLE_OPERATION_STATISTICS
    recordExponent(content);
#endif
    return *this;
}


//091.5-3
Dummy Dummy::operator=(const float f){
    content = VFP(f);
#ifndef DISABLE_OPERATION_STATISTICS
    recordExponent(content);
#endif
    return *this;
}

#endif
*/
//092
DOUBLE fabs(DOUBLE a){
    return (DOUBLE)((double)fabs((double)a));
}

DOUBLE trunc(DOUBLE a){
    return (DOUBLE)((double)trunc((double)a));
}

DOUBLE atan2(DOUBLE a,DOUBLE b){
    return (DOUBLE)((double)atan2((double)a,(double)b));
}

DOUBLE floor(DOUBLE a){
    return (DOUBLE)((double)floor((double)a));
}

DOUBLE log10(DOUBLE a){
    return (DOUBLE)((double)log10((double)a));
}

DOUBLE hypot(DOUBLE a,DOUBLE b){
    return (DOUBLE)((double)hypot((double)a,(double)b));
}

DOUBLE log(DOUBLE a){
    return (DOUBLE)((double)log((double)a));
}

DOUBLE exp(DOUBLE a){
    return (DOUBLE)((double)exp((double)a));
}

DOUBLE cos(DOUBLE a){
    return (DOUBLE)((double)cos((double)a));
}

DOUBLE sin(DOUBLE a){
    return (DOUBLE)((double)sin((double)a));
}

DOUBLE cosh(DOUBLE a){
    return (DOUBLE)((double)cosh((double)a));
}

DOUBLE sinh(DOUBLE a){
    return (DOUBLE)((double)sinh((double)a));
}

DOUBLE tan(DOUBLE a){
    return (DOUBLE)((double)tan((double)a));
}

DOUBLE tanh(DOUBLE a){
    return (DOUBLE)((double)tanh((double)a));
}

DOUBLE atan(DOUBLE a){
    return (DOUBLE)((double)atan((double)a));
}

DOUBLE ceil(DOUBLE a){
    return (DOUBLE)((double)ceil((double)a));
}

DOUBLE nearbyint(DOUBLE a){
    return (DOUBLE)((double)nearbyint((double)a));
}

DOUBLE pow(DOUBLE a,DOUBLE b){
    return (DOUBLE)((double)pow((double)a,(double)b));
}

DOUBLE pow(double a,DOUBLE b){
    return (DOUBLE)((double)pow(a,(double)b));
}

DOUBLE pow(DOUBLE a,double b){
    return (DOUBLE)((double)pow((double)a,b));
}
DOUBLE sqrt(DOUBLE a){
    return (DOUBLE)((double)sqrt((double)a));
}

DOUBLE isnan(DOUBLE a){
    return (DOUBLE)((double)isnan((double)a));
}

DOUBLE logb(DOUBLE a){
    return (DOUBLE)((double)logb((double)a));
}

DOUBLE scalbn(DOUBLE a,int i){
    return (DOUBLE)((double)scalbn((double)a,i));
}

DOUBLE asin(DOUBLE a){
    return (DOUBLE)((double)asin((double)a));
}

DOUBLE acos(DOUBLE a){
    return (DOUBLE)((double)acos((double)a));
}

DOUBLE atanh(DOUBLE a){
    return (DOUBLE)((double)atanh((double)a));
}

DOUBLE acosh(DOUBLE a){
    return (DOUBLE)((double)acosh((double)a));
}

DOUBLE asinh(DOUBLE a){
    return (DOUBLE)((double)asinh((double)a));
}

DOUBLE round(DOUBLE a){
    return (DOUBLE)((double)round((double)a));
}

DOUBLE abs(DOUBLE a){
    return (DOUBLE)((double)abs((double)a));
}


DOUBLE modf(DOUBLE para, DOUBLE* intpart) {
    double m = 0.0;
    double* mPtr = &m;
    DOUBLE a = (DOUBLE)((double)modf((double)para, mPtr));
    intpart->setContent(m);
    return a;
}

DOUBLE modf(double para, DOUBLE* intpart) {
    double m = 0.0;
    double* mPtr = &m;
    DOUBLE a = (DOUBLE)((double)modf(para, mPtr));
    intpart->setContent(m);
    return a;
}
//====== The functions mentioned in to-do, tested =======
DOUBLE frexp(DOUBLE r, int* exp) {
    return (DOUBLE)((double)frexp((double)r, exp));
}

int fpclassify(DOUBLE d) {
    return fpclassify((double)d);
}

bool isfinite(DOUBLE d) {
    return isfinite((double)d);
}

bool isnormal(DOUBLE d) {
    return isnormal((double)d);
}

bool isinf(DOUBLE d) {
    return isinf((double)d);
}

DOUBLE erfc(DOUBLE d) {
    return (DOUBLE)((double)erfc((double)d));
}
#endif // end of #ifndef FIXED_POINT_FIXEDPTC

#ifdef FIXED_POINT_FIXEDPTC
/**
 * Since the Newton-Raphson Method used in NGSPICE is using an
 * absolute tolerance of 1.0e-12 as the smallest convergence
 * criterion, 0.5e-12 will be used as threshold here to determine
 * whether two numbers are equal
 */
 /*
const fixedpt ABSOLUTE_TOLERANCE_FIXEDPT = double2fixed(0.5e-12);
  */
//024-f
Dummy::operator int(){
    return fixedpt_toint(content);
}

//025-f
Dummy::operator int() const{
    return fixedpt_toint(content);
}

//026-f
Dummy::operator long int(){
    return (long int)fixedpt_toint(content);
}

//027-f
Dummy::operator unsigned int(){
    return (unsigned int)fixedpt_abs(fixedpt_toint(content));
}

//028-f
Dummy::operator long unsigned int(){
    return (long unsigned int)fixedpt_abs(fixedpt_toint(content));
}

//029-f
Dummy::operator unsigned long long int(){
    return (unsigned long long int)fixedpt_abs(fixedpt_toint(content));
}

//030-f
Dummy::operator float(){
#ifndef DISABLE_OPERATION_STATISTICS
    incrNumConv();
#endif //end fo DISABLE_OPERATION_STATISTICS
    return fixedpt_tofloat(content);
}

//031-f
Dummy::operator bool() {
    return bool(content);
}

//032-f
Dummy::operator double(){
    return fixed2double(content);
}
//033-f-a
void Dummy::setContent(double d){
#ifndef DISABLE_OPERATION_STATISTICS
    incrNumConv();
    recordExponent(d);
#endif
    content = double2fixed(d);
}

//034-f
fixedpt Dummy::getContent(){
#ifndef DISABLE_OPERATION_STATISTICS
    incrNumConv();
#endif
    return content;
}

//035-f
bool Dummy::operator!() {
    return !content;
}

//036-f
Dummy operator*(Dummy d1,Dummy d2 ) {
    Dummy dum = Dummy(fixedpt_mul(d1.getContent(), d2.getContent()));
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumMul();
    Dummy::recordExponent(dum.getContent());
#endif
    return dum;
}

//037-f
Dummy operator*(Dummy dm,double d1) {
    Dummy dum = Dummy(fixedpt_mul(dm.getContent(), double2fixed(d1)));
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumConv();
    Dummy::incrNumMul();
    Dummy::recordExponent(dum.getContent());
#endif
    return dum;
}

//038-f
Dummy operator*(double d1, Dummy dm) {
    Dummy dum = Dummy(fixedpt_mul(double2fixed(d1), dm.getContent()));
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumConv();
    Dummy::incrNumMul();
    Dummy::recordExponent(dum.getContent());
#endif
    return dum;
}

//039-f
Dummy operator*(Dummy d1,long int l) {
    Dummy dum = Dummy(double2fixed(fixed2double(d1)*double(l)));
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumConv();
    Dummy::incrNumConv();
    Dummy::incrNumConv();
    Dummy::incrNumMul();
    Dummy::recordExponent(dum.getContent());
#endif
    return dum;
}

//040-f
Dummy operator*(long int l, Dummy d1) {
    Dummy dum = Dummy(double2fixed(double(l)*fixed2double(d1)));
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumConv();
    Dummy::incrNumConv();
    Dummy::incrNumConv();
    Dummy::incrNumMul();
    Dummy::recordExponent(dum.getContent());
#endif
    return dum;
}

//041-f
Dummy operator*(int i, Dummy dm) {
    Dummy dum = Dummy(fixedpt_mul( fixedpt_fromint(i), dm.getContent()));
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumMul();
    Dummy::recordExponent(dum.getContent());
#endif
    return dum;
}

//042-f
Dummy operator*(Dummy dm, int i) {
    Dummy dum = Dummy(fixedpt_mul( fixedpt_fromint(i), dm.getContent()));
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumMul();
    Dummy::recordExponent(dum.getContent());
#endif
    return dum;
}

//043-f
Dummy operator/(Dummy d1, Dummy d2) {
    Dummy dum = Dummy(fixedpt_div(d1.getContent() , d2.getContent()));
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumDiv();
    Dummy::recordExponent(dum.getContent());
#endif
    return dum;
}

//044-f
Dummy operator/(long int l, Dummy dm) {
    if(l > MAX_FP_INT_PART )
        throw std::invalid_argument("floating point value outside of the range fixed-point representation");
    Dummy dum = Dummy(fixedpt_div(fixedpt_fromint(l),dm.getContent()));
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumDiv();
    Dummy::recordExponent(dum.getContent());
#endif
    return dum;
}

//045-f
Dummy operator/(Dummy dm, long int l) {
    if(l > MAX_FP_INT_PART)
        throw std::invalid_argument("floating point value outside of the range fixed-point representation");
    Dummy dum = Dummy(fixedpt_div(dm.getContent(), fixedpt_fromint(l)));
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumDiv();
    Dummy::recordExponent(dum.getContent());
#endif
    return dum;
}

//046-f
Dummy operator/(int i, Dummy dm) {
    if(i > MAX_FP_INT_PART)
        throw std::invalid_argument("floating point value outside of the range fixed-point representation");
    Dummy dum = Dummy(fixedpt_div(fixedpt_fromint(i) , dm.getContent()));
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumDiv();
    Dummy::recordExponent(dum.getContent());
#endif
    return dum;
}

//047-f
Dummy operator/(Dummy dm, int i) {
    if(i > MAX_FP_INT_PART)
        throw std::invalid_argument("floating point value outside of the range fixed-point representation");
    Dummy dum = Dummy(fixedpt_div(dm.getContent() ,fixedpt_fromint(i)));
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumDiv();
    Dummy::recordExponent(dum.getContent());
#endif
    return dum;
}


//048-f
Dummy operator/(Dummy dm, double d) {
    fixedpt pd = double2fixed(d);
    Dummy dum = Dummy(fixedpt_div(dm.getContent() , pd));
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumDiv();
    Dummy::incrNumConv();
    Dummy::recordExponent(dum.getContent());
#endif
    return dum;
}

//049-f
Dummy operator/(double d, Dummy dm) {
    fixedpt pd = double2fixed(d);
    Dummy dum = Dummy(fixedpt_div(pd,dm.getContent()));
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumDiv();
    Dummy::incrNumConv();
    Dummy::recordExponent(dum.getContent());
#endif
    return dum;
}

//050-f
Dummy operator/(unsigned int ui, Dummy d){
    int i;
    if (ui <= (unsigned int)INT_MAX)
        i = (int)ui;
    else if (ui >= (unsigned int)INT_MIN)
        i = -(int)~ui - 1;
    else
        i = INT_MIN;
    if(i > MAX_FP_INT_PART)
        throw std::invalid_argument("floating point value outside "
                                    "of the range fixed-point representation");
    Dummy dum = Dummy(fixedpt_div(fixedpt_fromint(i),d.getContent()));
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumDiv();
    Dummy::incrNumConv();
    Dummy::recordExponent(dum.getContent());
#endif
    return dum;
}

//051-f
Dummy operator-(Dummy d) {
    return {-d.getContent()};
}

//052-f
Dummy operator-(Dummy d1, Dummy d2) {
    Dummy dum = Dummy(fixedpt_sub(d1.getContent() , d2.getContent()));
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
    Dummy::recordExponent(dum.getContent());
#endif
    return dum;
}

//053-f
Dummy operator-(Dummy dm, double d) {
    Dummy dum = Dummy(fixedpt_sub(dm.getContent(), double2fixed(d)));
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
    Dummy::incrNumConv();
    Dummy::recordExponent(dum.getContent());
#endif
    return dum;
}

//054-f
Dummy operator-(Dummy d, int i) {
    if(i > MAX_FP_INT_PART)
        throw std::invalid_argument("floating point value outside "
                                    "of the range fixed-point representation");
    fixedpt f = fixedpt_sub(d.getContent(), fixedpt_fromint(i));
    Dummy dum = Dummy(f);
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
    Dummy::incrNumConv();
    Dummy::recordExponent(dum.getContent());
#endif
    return dum;
}

//055-f
Dummy operator-(double d, Dummy dm ) {
    Dummy dum = Dummy(fixedpt_sub(double2fixed(d), dm.getContent()));
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumConv();
    Dummy::incrNumAdd();
    Dummy::recordExponent(dum.getContent());
#endif
    return dum;
}

//056-f
Dummy operator-(int i, Dummy d) {
    if(i > MAX_FP_INT_PART)
        throw std::invalid_argument("floating point value outside "
                                    "of the range fixed-point representation");
    fixedpt f = fixedpt_sub(fixedpt_fromint(i),d.getContent());
    Dummy dum = {f};
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
    Dummy::recordExponent(dum.getContent());
#endif
    return dum;
}

//057-f
Dummy operator+(Dummy d1, Dummy d2) {
    Dummy dum = {fixedpt_add(d1.getContent(),d2.getContent())};
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
    Dummy::recordExponent(dum.getContent());
#endif
    return dum;
}

//058-f
Dummy operator+(Dummy dm, double d) {
    Dummy dum = {fixedpt_add(dm.getContent() ,double2fixed(d))};
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
    Dummy::incrNumConv();
    Dummy::recordExponent(dum.getContent());
#endif
    return dum;
}

//059-f
Dummy operator+(Dummy d, int i) {
    if(i > MAX_FP_INT_PART)
        throw std::invalid_argument("floating point value outside "
                                    "of the range fixed-point representation");
    fixedpt f = fixedpt_add(d.getContent(), fixedpt_fromint(i));
    Dummy dum = {f};
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
    Dummy::recordExponent(dum.getContent());
#endif
    return dum;
}

//060-f
Dummy operator+(double d, Dummy dm) {
    Dummy dum = {fixedpt_add(double2fixed(d),dm.getContent())};
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
    Dummy::incrNumConv();
    Dummy::recordExponent(dum.getContent());
#endif
    return dum;
}

//061-f
Dummy operator+(int i, Dummy d) {
    if(i > MAX_FP_INT_PART)
        throw std::invalid_argument("floating point value outside "
                                    "of the range fixed-point representation");
    fixedpt f = fixedpt_add(d.getContent(), fixedpt_fromint(i));
    Dummy dum = {f};
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
    Dummy::recordExponent(dum.getContent());
#endif
    return dum;
}

//062-f
Dummy operator+(Dummy d) {
    return d;
}

//063-f
bool operator>=(Dummy d1, Dummy d2) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
#endif
    if (d1.getContent() >= d2.getContent())
        return true;
    else
        return false;
}

//064-f
bool operator>=(Dummy dm, double d) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
    Dummy::incrNumConv();
#endif
    if (dm.getContent() >= double2fixed(d))
        return true;
    else
        return false;
}

//065-f
bool operator>=(Dummy d, int i) {
    if(i > MAX_FP_INT_PART)
        throw std::invalid_argument("floating point value outside "
                                    "of the range fixed-point representation");
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
#endif
    if (d.getContent() >= fixedpt_fromint(i))
        return true;
    else
        return false;
}

//066-f
bool operator>=(Dummy d, long int li) {
    if(li > MAX_FP_INT_PART)
        throw std::invalid_argument("floating point value outside "
                                    "of the range fixed-point representation");
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
#endif
    fixedpt dli = li << FIXEDPT_FBITS;
    if (d.getContent() >= dli)
        return true;
    else
        return false;
}

//067-f
bool operator==(Dummy d1, Dummy d2) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
#endif
    if (d1.getContent() == d2.getContent())
        return true;
    else
        return false;
}

//068-f

bool operator==(Dummy dm, double d) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
    Dummy::incrNumConv();
#endif
    double absTol = ABSOLUTE_TOLERANCE;
    if (abs(fixed2double(dm.getContent()) - d)<=absTol)
        return true;
    else
        return false;
}

//069-f
bool operator==(Dummy d, int i) {
    if(i > MAX_FP_INT_PART)
        throw std::invalid_argument("floating point value outside "
                                    "of the range fixed-point representation");
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
#endif
    if ((fixedpt_toint(d.getContent())==i)&&((d.getContent() & FIXEDPT_FMASK)!=0))
        return true;
    else
        return false;
}

//070-f
bool operator==(double d, Dummy dm ) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
    Dummy::incrNumConv();
#endif
    double absTol = ABSOLUTE_TOLERANCE;
    if (abs(fixed2double(dm.getContent()) - d)<=absTol)
        return true;
    else
        return false;
}

//071-f
bool operator<=(Dummy d1, Dummy d2) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
#endif
    if (fixedpt_sub(d1.getContent(),d2.getContent())<=0)
        return true;
    else
        return false;
}

//072-f
bool operator<=(Dummy dm, double d) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
    Dummy::incrNumConv();
#endif
    if (fixedpt_sub(dm.getContent(), double2fixed(d))<=0)
        return true;
    else
        return false;
}

//073-f
bool operator<=(Dummy d, int i) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
    Dummy::incrNumAdd();
#endif
    int fi = fixedpt_toint(d.getContent());
    if(fi > i)
        return false;
    else{
        if(fi < i)
            return true;
        else{
            if((d.getContent()&FIXEDPT_FMASK)==0)
                return true;
            else
                return false;
        }
    }
}

//074-f
bool operator<=(Dummy d, long int li) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
#endif
    long int fli = fixedpt_toint(d.getContent());
    if(fli > li)
        return false;
    else{
        if(fli < li)
            return true;
        else{
            if((d.getContent()&FIXEDPT_FMASK)==0)
                return true;
            else
                return false;
        }
    }
}

//075-f
bool operator<=(double d, Dummy dm) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
    Dummy::incrNumConv();
#endif
    if (d <= fixed2double(dm.getContent()))
        return true;
    else
        return false;
}

//076-f
bool operator!=(Dummy d1, Dummy d2) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
#endif
    if (d1.getContent() != d2.getContent())
        return true;
    else
        return false;
}

//077-f
bool operator!=(Dummy dm, double d ) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
    Dummy::incrNumConv();
#endif
    double absTol = ABSOLUTE_TOLERANCE;
    if (abs(fixed2double(dm.getContent())-d)<(absTol))
        return true;
    else
        return false;
}

//078-f
bool operator!=(Dummy d, int i) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
#endif
    if ((fixedpt_toint(d.getContent())==i)&&(d.getContent()&FIXEDPT_FMASK)==0)
        return true;
    else
        return false;
}

//079-f
bool operator!=(double d, Dummy dm  ) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
    Dummy::incrNumConv();
#endif
    double absTol = ABSOLUTE_TOLERANCE;
    if ((abs(fixed2double(dm.getContent()))-d)<(absTol))
        return true;
    else
        return false;
}

//080-f
bool operator>(Dummy d1, Dummy d2) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
#endif
    if (d1.getContent()>d2.getContent())
        return true;
    else
        return false;
}

//081-f
bool operator>(double d1, Dummy dm) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
    Dummy::incrNumConv();
#endif
    if (d1 > fixed2double(dm.getContent()))
        return true;
    else
        return false;
}

//082-f
bool operator>(Dummy dm, double d2) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
    Dummy::incrNumConv();
#endif
    if (fixed2double(dm.getContent()) > d2)
        return true;
    else
        return false;
}

//083-f
bool operator>(Dummy d, int i) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
#endif
    long int li = fixedpt_fromint(i);
    if(d.getContent() > li)
        return true;
    else
        return false;
}

//084
bool operator<(Dummy d1, Dummy d2) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
#endif
    if (d1.getContent() < d2.getContent())
        return true;
    else
        return false;
}

//085-f
bool operator<(Dummy d1, double d2) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
    Dummy::incrNumConv();
#endif
    if (fixed2double(d1.getContent()) < d2)
        return true;
    else
        return false;
}

//086-f
bool operator<(double d1, Dummy d2) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
#endif
    if (d1 < fixed2double(d2.getContent()))
        return true;
    else
        return false;
}

//087-f
bool operator<(Dummy d, int i) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
    Dummy::incrNumConv();
#endif
    if (fixedpt_toint(d.getContent()) < i)
        return true;
    else
        return false;
}
//====//
//088
Dummy Dummy::operator+=(Dummy d) {
    content = content + d.content;
#ifndef DISABLE_OPERATION_STATISTICS
    incrNumAdd();
    recordExponent(content);
#endif
    return {content};
}

//089
Dummy Dummy::operator-=(Dummy d) {
    content = content - d.content;
#ifndef DISABLE_OPERATION_STATISTICS
    incrNumAdd();
    recordExponent(content);
#endif
    return {content};
}

//090
Dummy Dummy::operator*=(Dummy d) {
    content = content * d.content;
#ifndef DISABLE_OPERATION_STATISTICS
    incrNumMul();
    recordExponent(content);
#endif
    return {content};
}

//091
Dummy Dummy::operator/=(Dummy d) {
    content = content / d.content;
#ifndef DISABLE_OPERATION_STATISTICS
    incrNumDiv();
    recordExponent(content);
#endif
    return {content};
}





#endif //end of #ifdef FIXED_POINT_FIXEDPTC

//================ end of to-do list =================





