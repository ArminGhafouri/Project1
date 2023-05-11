
#pragma once
#include<Pt2d.hxx>

class Vec
{
protected:
	 


public:
	Vec();
	//Vec2d(double u, double v);
	////Vec2d(const Pt2d & p0, const Pt2d& p1);
	//double GetU()const;
	//double GetV()const;
	//void SetU(double u);
	//void SetV(double v);
	///virtual void Print()const;

	virtual double DotProduct()const = 0;

	//Vec2d CrossProduct(const Vec2d& b)const;


};
