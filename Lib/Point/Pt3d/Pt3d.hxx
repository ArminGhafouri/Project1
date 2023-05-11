#pragma once
#include <Pt2d.hxx>

class Pt3d : public Pt2d
{
private:

	double theZ_;

public:
	Pt3d(double  x = 0.0, double y = 0.0, double z = 0.0);

	//Pt3d(double x, double y, double z);   ////newww

	double GetZ() const;
	void SetZ(double);
	void Print() const override;

	/* Pt3d operator+(const Pt3d& p2);
	 Pt3d operator-(const Pt3d& p2);
	 Pt3d operator*(const Pt3d& p2);
	 //friend Pt2d operator/(const Pt2d& p2, const Pt2d& p2);
	 Pt3d operator/(const Pt3d& p2);*/

};


