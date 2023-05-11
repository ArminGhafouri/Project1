#include "Pt3d.hxx"
#include <iostream>


Pt3d::Pt3d(double x, double y, double z) : Pt2d(x, y)
{
	theZ_ = z;

}



//Pt3d::Pt3d(double x, double y, double z)  /////new
//{
//
//	theX_ = x;
//	theY_ = y;
//	theZ_ = z;
//
//}


double Pt3d::GetZ()const
{
	return theZ_;
}



void Pt3d::SetZ(double z)
{
	theZ_ = z;
}



void Pt3d::Print()const
{
	std::cout << "(" << theX_ << ", " << GetY() << ", " << theZ_ << ")" << std::endl;

}