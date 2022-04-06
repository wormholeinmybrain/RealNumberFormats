// DummyClass.cpp : Defines the entry point for the application.
//
#include <stdio.h>
#include "Dummy.h"
//#include <iostream>
#include <cmath>
#include <limits.h>
using namespace std;
#ifndef DISABLE_OPERATION_STATISTICS
int Dummy::numAdd = 0;
int Dummy::numMul = 0;
int Dummy::numDiv = 0;
int Dummy::numConv = 0;
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

//005
void Dummy::clearMaxExpo(){
    maxExponent = INT_MIN;
}

//006
void Dummy::clearMinExpo(){
    minExponent = INT_MAX;
}

//007
void Dummy::incrNumAdd() {
    numAdd++;
}

//008
void Dummy::incrNumMul() {
    numMul++;
}

//009
void Dummy::incrNumDiv() {
    numDiv++;
}

//010
void Dummy::incrNumConv() {
    numConv++;
}

//011
void Dummy::resetRecord() {
    clearAdd();
    clearMul();
    clearDiv();
    clearConv();
    printf("Record of operation reset. \n");
}

//012
void Dummy::showRecord() {
    printf("Number of Addition/Subtraction: %i \n", numAdd);
    printf("Number of Multiplication: %i \n", numMul);
    printf("Number of Division: %i \n", numDiv);
    printf("Number of Conversion to other data type: %i \n", numConv);
}

//013
void Dummy::recordExponent(const double d){
    int i = 0;
    frexp(d,&i);
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
#ifndef DISABLE_OPERATION_STATISTICS
    incrNumConv();
#endif
    return float(content);
}

//031
Dummy::operator double(){
    return content;
}

//032
Dummy::operator bool(){
#ifndef DISABLE_OPERATION_STATISTICS
    incrNumConv();
#endif
    return bool(content);
}


//033
bool Dummy::operator!() {
    return !content;
}

//034
void Dummy::setContent(double d){
#ifndef DISABLE_OPERATION_STATISTICS
    recordExponent(d);
#endif
    content = d;
}

//035
double Dummy::getContent(){
    return content;
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
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
#endif
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

//092
/** Not supported by SoftFlow **/
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
//================ end of to-do list =================
