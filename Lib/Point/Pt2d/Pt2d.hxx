#pragma once

class Pt2d
{
protected:
	double theX_;
	double theY_;

public:
	Pt2d(double  x = 0.0, double y = 0.0);

	double GetX()const;
	double GetY()const;
	void SetX(double x);
	void SetY(double y);

	virtual void Print() const;

	Pt2d operator+(const Pt2d& p2) const;
	Pt2d operator-(const Pt2d& p2)const;
	Pt2d operator*(const Pt2d& p2)const;
	//friend Pt2d operator/(const Pt2d& p2, const Pt2d& p2);
	Pt2d operator/(const Pt2d& p2)const;
	void Scale(double s);

};

