#pragma once
#include "Vector3.h"

class FractionalHex
{
public:
	FractionalHex(double q_in, double r_in, double s_in);
	~FractionalHex();

	//UNION
	union {
		//struct as qrs accessable with . operator
		struct {
			double  q, r, s;		
		};		
		//array accessable with [] operator
		double data[3];
	};
};

