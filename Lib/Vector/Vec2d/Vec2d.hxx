#pragma once
#include<Pt2d.hxx>

class Vec2d
{
protected:

	double theU_;
	double theV_;

public:

	Vec2d(double u = 0.0, double v = 0.0);
	Vec2d(const Pt2d& p0, const Pt2d& p1);

	double GetU()const;
	double GetV()const;
	void SetU(double u);
	void SetV(double v);

	virtual void Print()const;
	double DotProduct(const Vec2d& b)const;
	Vec2d Scale(double scale1)const;
	Vec2d CrossProdtuct(const Vec2d& b)const;
	double Magnitude();


};