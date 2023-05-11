#include"Pt2d.hxx"
#include <iostream>

using namespace std;

Pt2d::Pt2d(double x, double y)
{
	theX_ = x;
	theY_ = y;
}

double Pt2d::GetX()const
{
	return theX_;
}
double Pt2d::GetY() const
{
	return theY_;
}

void Pt2d::SetX(double x)
{
	theX_ = x;
}

void Pt2d::SetY(double y)
{
	theY_ = y;
}

void Pt2d::Print() const
{
	cout << "(" << theX_ << ", " << theY_ << ")\n";
}

Pt2d Pt2d::operator+(const Pt2d& p2)const
{
	Pt2d p3;
	p3.SetX(theX_ + p2.GetX());
	p3.SetY(theY_ + p2.GetY());

	return p3;
}

Pt2d Pt2d::operator-(const Pt2d& p2)const
{
	Pt2d p4;
	p4.SetX(theX_ - p2.GetX());
	p4.SetY(theY_ - p2.GetY());
	return p4;
}

Pt2d Pt2d::operator*(const Pt2d& p2)const
{
	Pt2d p5;
	p5.SetX(theX_ * p2.GetX());
	p5.SetY(theY_ * p2.GetY());
	return p5;
}

Pt2d Pt2d::operator/(const Pt2d& p2)const
{
	Pt2d p6;
	p6.SetX(theX_ / p2.GetX());
	p6.SetY(theY_ / p2.GetY());
	return p6;
}

//Pt2d Pt2d::operator/()


void Pt2d::Scale(double s)
{
	 
	theX_ *= s;
	theY_ *= s;

}