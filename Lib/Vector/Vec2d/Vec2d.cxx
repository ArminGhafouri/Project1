#include"Vec2d.hxx"
#include<Pt2d.hxx>
#include<iostream>
#include<math.hxx>

Vec2d::Vec2d(double u, double v)
{
	theU_ = u;
	theV_ = v;
}

Vec2d::Vec2d(const Pt2d& p0, const Pt2d& p1)
{
	double u = (p1.GetX() - p0.GetX());
	double v = (p1.GetY() - p0.GetY());

	theU_ = u;
	theV_ = v;

}

//Vec2d(const Pt2d & p0, const Pt2d& p1)
//{
//	theU_ = p1.GetX() - p0.GetX();
//	theV_ = p1.GetY() - p0.GetY();
//
//}


double Vec2d::GetU()const
{
	return theU_;
}

double Vec2d::GetV()const
{
	return theV_;
}

void Vec2d::SetU(double u)
{
	theU_ = u;
}


void Vec2d::SetV(double v)
{
	theV_ = v;
}

void Vec2d::Print()const
{
	std::cout << "(" << theU_ << ", " << theV_ << ")" << std::endl;

}


double Vec2d::DotProduct(const Vec2d& b)const
{
	double r;

	r = theU_ * b.GetU() + theV_ * b.GetV();

	return r;
}


Vec2d Vec2d::Scale(double scale1)const
{

	Vec2d s;

	s.SetU(theU_ * scale1);
	s.SetV(theV_ * scale1);

	return s;

}

Vec2d Vec2d::CrossProdtuct(const Vec2d& b)const
{
	Vec2d h;

	h.SetU(theU_ * b.GetV());
	h.SetV(-b.GetU() * theV_);

	return h;

}


/*Vec2d s ;

	s.SetU(theU_ * b.GetV());
	s.SetV(-b.GetU() *theV_);

	return s;*/


double Vec2d::Magnitude()
{

	double mag = (sqrt(theU_ * theU_ + theV_ * theV_));

	return mag;
}


