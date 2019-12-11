/*
 * complex.h
 *
 *  Created on: Dec 10, 2019
 *      Author: fernando
 */

#ifndef COMPLEX_H_
#define COMPLEX_H_

#include "common.h"

/** a simple complex type */
template<typename real_t>
struct complex {
	/** real and imaginary part */
	real_t re, im;

	__DEVICE_HOST__ complex(float re, float im = 0) {
		this->re = re;
		this->im = im;
	}

	// operator overloads for complex numbers
	__DEVICE_HOST__
	complex operator+(const complex &b) {
		return complex(this->re + b.re, this->im + b.im);
	}
	__DEVICE_HOST__
	complex operator-() { //const complex &a) {
		return complex(-this->re, -this->im);
	}
	__DEVICE_HOST__
	complex operator-(const complex &b) {
		return complex(this->re - b.re, this->im - b.im);
	}
	__DEVICE_HOST__
	complex operator*(const complex &b) {
		return complex(this->re * b.re - this->im * b.im,
				this->im * b.re + this->re * b.im);
	}

	__DEVICE_HOST__
	real_t abs2() {
		return this->re * this->re + this->im * this->im;
	}

	__DEVICE_HOST__
	complex operator/(const complex &b) {
		float invabs2 = 1 / abs2(b);
		return complex((this->re * b.re + this->im * b.im) * invabs2,
				(this->im * b.re - b.im * this->re) * invabs2);
	}  // operator/

};
// struct complex

#endif /* COMPLEX_H_ */
