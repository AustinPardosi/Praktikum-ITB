#include "Kompleks.h"
#include <cstdio>

int Kompleks::n_kompleks = 0;

//int real;
//int imaginer;

Kompleks::Kompleks() {
	this->real = 0;
	this->imaginer = 0;
	n_kompleks++;
}
	
Kompleks::Kompleks(int real, int imaginer) {
	this->real = real;
	this->imaginer = imaginer;
	n_kompleks++;
}

int Kompleks::GetReal() const {
	return this->real;
}

int Kompleks::GetImaginer() const {
	return this->imaginer;
}

void Kompleks::SetReal(int x) {
	this->real = x;
}

void Kompleks::SetImaginer(int x) {
	this->imaginer = x;
}

// (a + bi) + (c + di) = (a+c) + (b+d)i
Kompleks operator+ (const Kompleks& a, const Kompleks& b) {
	Kompleks c;
	c.real = a.real + b.real;
	c.imaginer = a.imaginer + b.imaginer;
	return c;
	//turn Kompleks::Kompleks(a.real+b.real, a.imaginer()+b.imaginer());
}

// (a + bi) − (c + di) = (a−c) + (b−d)i
Kompleks operator- (const Kompleks& a, const Kompleks& b) {
	Kompleks c;
	c.real = a.real - b.real;
	c.imaginer = a.imaginer - b.imaginer;
	return c;
	//turn Kompleks::Kompleks(a.real-b.real, a.imaginer()-b.imaginer());
}

// (a + bi)(c + di) = (ac−bd) + (bc+ad)i
Kompleks operator* (const Kompleks& a, const Kompleks& b) {
	Kompleks c;
	c.real = a.real*b.real-a.imaginer*b.imaginer;
	c.imaginer = a.imaginer*b.real+a.real*b.imaginer;
	return c;
	//turn Kompleks::Kompleks(a.real*b.real-a.imaginer()*b.imaginer(), a.imaginer()*b.real()+a.real()*b.imaginer());
}

// (a + bi)(c) = (ac) + (bc)i
Kompleks operator* (const Kompleks& a, const int b) {
	Kompleks c;
	c.real = a.real*b;
	c.imaginer = a.imaginer*b;
	return c;
	//turn Kompleks::Kompleks(a.real*b), a.real*b);
}
	
Kompleks operator* (const int b, const Kompleks& a) {
	Kompleks c;
	c.real = a.real*b;
	c.imaginer = a.imaginer*b;
	return c;	
	//turn Kompleks::Kompleks(a.real*b), a.real*b);
}

int Kompleks::CountKompleksInstance() {
	return n_kompleks;
}

void Kompleks::Print() {
	printf("%d", this->real);
    if (this->imaginer > 0) {
	    printf("+");
    }
	printf("%d", this->imaginer);
	printf("i\n");
}










