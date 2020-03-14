#pragma once
#include<iostream>
template <typename T, typename U>
class Tuple {
public:
	T x;
	U y;
	Tuple(T x, U y):x(x),y(y) {
	}
};

