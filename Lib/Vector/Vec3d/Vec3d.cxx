#include "Vec3d.hxx"
#include <iostream>


//Vec3d :: Vec3d(double u=0.0,double v=0.0,double w=0.0) 
//{
//	theW_ = w;
//	theU_ = u;
//	theV_ = v;
//}
//
//
//double Vec3d::GetW()const
//{
//	return theW_;
//}
//
//
//
//void Vec3d::SetW(double w)
//{
//	theW_ = w;
//}
//
//
//double Vec3d::GetU()const
//{
//	return theU_;
//}
//
//
//double Vec3d::GetV()const
//{
//	return theV_;
//}
//
//
//void Vec3d::SetU(double u)
//{
//	theU_ = u;
//}
//
//
//void Vec3d::SetV(double v)
//{
//	theV_ = v;
//}
//
//
//void Vec3d::Print()const
//{
//	std::cout << "(" << theU_ << ", " << theV_ << ", " << theW_ << ")" << std::endl;
//
//}
//
//
//double Vec3d::DotProduct(const Vec3d & b) const
// {
//	 double d;
//	 d = theU_*b.GetU() +theV_*b.GetV() + theW_ * b.GetW();
//	 return d;
//	 
// }
//
//
//
// Vec3d Vec3d::CrossProdtuct(const Vec3d & b)const
//
// {
//	 
//	 Vec3d v;
//	
//
//	 v.SetU(theV_ *b.GetW()  - theW_*b.GetV());
//	 v.SetV(-(theU_*b.GetW()) + theW_*b.GetU());
//	 v.SetW(theU_ * b.GetV() - theV_*b.GetU());
//	 
//	 return v;
//
//	 
// }

Vec3d::Vec3d(const Pt3d& p0, const Pt3d& p1)
{

	double u = (p1.GetX() - p0.GetX());
	double v = (p1.GetY() - p0.GetY());
	double w = (p1.GetZ() - p0.GetZ());

	theU_ = u;
	theV_ = v;
	theW_ = w;
}

Vec3d::Vec3d(double u, double v, double w)
	: Vec2d(u, v)
{
	theW_ = w;
}

//double Vec3d::GetW()const
//{
//	return theW_;
//}
//
//void Vec3d::SetW(double w)
//{
//	theW_ = w;
//}

double Vec3d::DotProduct(const Vec3d& b) const
{

	double d;
	d = theU_ * b.GetU() + theV_ * b.GetV() + theW_ * b.GetW();
	return d;

}

void Vec3d::Print()const
{
	std::cout << "(" << theU_ << ", " << theV_ << ", " << theW_ << ")" << std::endl;
}

Vec3d Vec3d::CrossProdtuct(const Vec3d& b)const

{

	Vec3d v;


	v.SetU(theV_ * b.GetW() - theW_ * b.GetV());
	v.SetV(-(theU_ * b.GetW()) + theW_ * b.GetU());
	v.SetW(theU_ * b.GetV() - theV_ * b.GetU());

	return v;


}

double Vec3d::Magnitude()const
{

	double mag;

	mag = (std::sqrt(theU_ * theU_) + (theV_ * theV_) + (theW_ * theW_));


	return mag;
}


double Vec3d::CalcTeta(const Vec3d& k)
{

	double teta = std::acos((DotProduct(k)) / (Magnitude() * k.Magnitude()));

	return teta;
}