// DummyClass.cpp : Defines the entry point for the application.
//
#include <stdio.h>
#include "Dummy.h"
//#include <iostream>
#include <cmath>
using namespace std;
#ifndef DISABLE_OPERATION_STATISTICS
int Dummy::numAdd = 0;
int Dummy::numMul = 0;
int Dummy::numDiv = 0;
int Dummy::numConv = 0;

void Dummy::showRecord() {
    printf("Number of Addition/Subtraction: %i \n", numAdd);
    printf("Number of Multiplication: %i \n", numMul);
    printf("Number of Division: %i \n", numDiv);
    printf("Number of Conversion to Integer: %i \n", numConv);

}

void Dummy::resetRecord() {
    clearAdd();
    clearMul();
    clearDiv();
    clearConv();
    printf("Record reset. \n");
}

void Dummy::clearAdd() {
    numAdd = 0;
}

void Dummy::clearMul() {
    numMul = 0;
}

void Dummy::clearDiv() {
    numDiv = 0;
}

void Dummy::clearConv() {
    numConv = 0;
}

void Dummy::incrNumAdd() {
    numAdd++;
}

void Dummy::incrNumMul() {
    numMul++;
}

void Dummy::incrNumDiv() {
    numDiv++;
}

void Dummy::incrNumConv() {
    numConv++;
}
#endif

Dummy operator*(Dummy d1,Dummy d2 ) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumMul();
#endif
    return Dummy(d1.getContent() * d2.getContent());
}

Dummy operator*(Dummy dm,double d) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumMul();
#endif
    return Dummy(dm.getContent() * d);
}

Dummy operator*(double d, Dummy dm) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumMul();
#endif
    return Dummy(d * dm.getContent());
}


Dummy operator*(Dummy d,long int l) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumConv();
    Dummy::incrNumMul();
#endif
    return Dummy(d.getContent() * (double)l);
}

Dummy operator*(long int l, Dummy d) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumConv();
    Dummy::incrNumMul();
#endif
    return Dummy((double)l* d.getContent());
}

Dummy operator*(int i, Dummy d) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumConv();
    Dummy::incrNumMul();
#endif
    return Dummy((double)i* d.getContent());
}

Dummy operator*(Dummy d, int i) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumConv();
    Dummy::incrNumMul();
#endif
    return Dummy((double)i* d.getContent());
}

Dummy operator/(long int l, Dummy dm) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumDiv();
    Dummy::incrNumConv();
#endif
    return Dummy((double)l / dm.getContent());
}

Dummy operator/(Dummy dm, long int l) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumDiv();
    Dummy::incrNumConv();
#endif
    return Dummy(dm.getContent() / (double)l);
}

Dummy operator/(int i, Dummy dm) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumDiv();
    Dummy::incrNumConv();
#endif
    return Dummy((double)i / dm.getContent());
}

Dummy operator/(Dummy dm, int i) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumDiv();
    Dummy::incrNumConv();
#endif
    return Dummy( dm.getContent() / (double)i);
}

Dummy operator/(Dummy dm, double d) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumDiv();
#endif
    return Dummy(dm.getContent() / d);
}

Dummy operator/(double d, Dummy dm) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumDiv();
#endif
    return Dummy(d / dm.getContent());
}
Dummy operator/(Dummy d1, Dummy d2) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumDiv();
#endif
    return Dummy(d1.getContent() / d2.getContent());
}

Dummy operator/(unsigned int ui, Dummy d){
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumDiv();
    Dummy::incrNumConv();
#endif
    return Dummy((double)ui/d.getContent());
}

double& Dummy::operator~() {
    return content;
}

bool operator>(Dummy d1, Dummy d2) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
#endif
    if (d1.getContent() > d2.getContent())
        return true;
    else
        return false;
}

bool operator>(Dummy d1, double d2) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
#endif
    if (d1.getContent() > d2)
        return true;
    else
        return false;
}

bool operator>(double d1, Dummy d2) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
#endif
    if (d1 > d2.getContent())
        return true;
    else
        return false;
}

bool operator<(Dummy d1, Dummy d2) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
#endif
    if (d1.getContent() < d2.getContent())
        return true;
    else
        return false;
}

bool operator<(Dummy d1, double d2) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
#endif
    if (d1.getContent() < d2)
        return true;
    else
        return false;
}

bool operator<(double d1, Dummy d2) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
#endif
    if (d1 < d2.getContent())
        return true;
    else
        return false;
}

Dummy operator-(Dummy d) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
#endif
    return Dummy(-d.getContent());
}

Dummy operator-(Dummy d1, Dummy d2) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
#endif
    return Dummy(d1.getContent() - d2.getContent());
}

Dummy operator-(Dummy dm, double d) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
#endif
    return Dummy(dm.getContent()-d);
}

Dummy operator-(Dummy d, int i) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
    Dummy::incrNumConv();
#endif
    return Dummy(d.getContent() - (double)i);
}

Dummy operator-(double d, Dummy dm ) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
#endif
    return Dummy(d - dm.getContent());
}

Dummy operator-(int i, Dummy d) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
    Dummy::incrNumConv();
#endif
    return Dummy((double) i - d.getContent());
}

Dummy operator+(Dummy d1, Dummy d2) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
#endif
    return Dummy(d1.getContent()+d2.getContent());
}

Dummy operator+(Dummy dm, double d) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
#endif
    return Dummy(dm.getContent() + d);
}

Dummy operator+(Dummy d, int i) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
    Dummy::incrNumConv();
#endif
    return Dummy(d.getContent() + double(i));
}

Dummy operator+(double d, Dummy dm) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
#endif
    return Dummy(dm.getContent() + d);
}

Dummy operator+(int i, Dummy d) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
    Dummy::incrNumConv();
#endif
    return Dummy(d.getContent() + double(i));
}

Dummy operator+(Dummy d) {
    return d;
}

bool operator>=(Dummy d1, Dummy d2) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
#endif
    if (d1.getContent() >= d2.getContent())
        return true;
    else
        return false;
}

bool operator>=(Dummy dm, double d) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
#endif
    if (dm.getContent() >= d)
        return true;
    else
        return false;
}

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

bool operator<=(Dummy d1, Dummy d2) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
#endif
    if (d1.getContent() <= d2.getContent())
        return true;
    else
        return false;
}

bool operator<=(Dummy dm, double d) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
#endif
    if (dm.getContent() <= d)
        return true;
    else
        return false;
}

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

bool operator<=(double d, Dummy dm) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
#endif
    if (d <= dm.getContent())
        return true;
    else
        return false;
}

bool operator==(Dummy d1, Dummy d2) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
#endif
    if (d1.getContent() == d2.getContent())
        return true;
    else
        return false;
}

bool operator==(Dummy dm, double d) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
#endif
    if (dm.getContent() == d)
        return true;
    else
        return false;
}

bool operator==(double d, Dummy dm ) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
#endif
    if (dm.getContent() == d)
        return true;
    else
        return false;
}

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

bool operator!=(Dummy d1, Dummy d2) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
#endif
    if (d1.getContent() != d2.getContent())
        return true;
    else
        return false;
}

bool operator!=(Dummy dm, double d ) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
#endif
    if (dm.getContent() != d)
        return true;
    else
        return false;
}

bool operator!=(double d, Dummy dm  ) {
#ifndef DISABLE_OPERATION_STATISTICS
    Dummy::incrNumAdd();
#endif
    if ( d != dm.getContent())
        return true;
    else
        return false;
}

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

Dummy Dummy::operator+=(Dummy d) {
#ifndef DISABLE_OPERATION_STATISTICS
    incrNumAdd();
#endif
    content = content + d.content;
    return Dummy(content);
}

Dummy Dummy::operator-=(Dummy d) {
#ifndef DISABLE_OPERATION_STATISTICS
    incrNumAdd();
#endif
    content = content - d.content;
    return Dummy(content);
}

Dummy Dummy::operator*=(Dummy d) {
#ifndef DISABLE_OPERATION_STATISTICS
    incrNumMul();
#endif
    content = content * d.content;
    return Dummy(content);
}

Dummy Dummy::operator/=(Dummy d) {
#ifndef DISABLE_OPERATION_STATISTICS
    incrNumDiv();
#endif
    content = content / d.content;
    return Dummy(content);
}

bool Dummy::operator!() {
    return !content;
}

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
