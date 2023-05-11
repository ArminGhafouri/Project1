#include"Triangle.hxx"
#include<fstream>

Triangle::Triangle(const Pt2d& cor1, const Pt2d& cor2, const Pt2d& cor3)
{
	Corner1_ = cor1;
	Corner2_ = cor2;
	Corner3_ = cor3;

}

double Triangle::CalcArea() const
{
	/*Pt2d theU_ , theV_;
	theU_ = Corner1_.GetX() - Corner2_.GetX();
	theV_= Corner1_.GetY() - Corner2_.GetY();
	Vec2d Vec1;
	Vec1.SetU(theU_);
	Vec1.SetV(theV_);*/

	Vec2d Vec1(Corner1_, Corner2_);
	Vec2d Vec2(Corner1_, Corner3_);


	Vec2d cross = Vec1.CrossProdtuct(Vec2);

	double s = cross.Magnitude();

	double Area = s / 2.0;

	return Area;

}

double Triangle::CalcPerimeter() const
{
	Vec2d v1(Corner1_, Corner2_);
	Vec2d v2(Corner2_, Corner3_);
	Vec2d v3(Corner3_, Corner1_);

	double perimeter = v1.Magnitude() + v2.Magnitude() + v3.Magnitude();

	return perimeter;

}


void Triangle::Plot(std::string filename)
{

	std::fstream f(filename + ".plt", std::ios::out);
	if (!f.is_open())
	{
		std::cout << "can not open this file" << std::endl;

		return;

	}
	
	f << "VARIABLES = X Y" << std::endl;
	f << "ZONE T = Triangle" << std::endl;

	f << Corner1_.GetX() << "  " << Corner1_.GetY()<<std::endl;
	f << Corner2_.GetX() << "  " << Corner2_.GetY()<<std::endl;
	f << Corner3_.GetX() << "  " << Corner3_.GetY()<<std::endl;

	f << Corner1_.GetX() << "  " << Corner1_.GetY() << std::endl;

	f.close();

}



//std::vector<Pt2d> Triangle::CalcCor1(int n)
//{
//
//	std::vector<Pt2d> points;
//
//	Vec2d p0(Corner1_, Corner2_);
//	double p1 = p0.Magnitude();
//	double dx = p1 / n;
//	
//	double x0 = Corner1_.GetX();
//
//	for (int i = 0; i <= n; i++)
//	{
//
//		double xc = x0 + i * dx;
//		
//		Pt2d point = xc;
//
//		points.push_back(point);
//
//	 }
//   return std::vector<Pt2d>();
//   }


//Pt2d Triangle::CalcUp()
//{
//	double xu;
//	double yu;
//	double y = std::sqrt((theSmalD_ * theSmalD_) * (1 - ((xc * xc) / ((theLargD_ / 2) * (theLargD_ / 2)))));
//
//
//
//
//	xu = xc;
//	yu = y;
//
//
//
//
//	return Pt2d(xu, yu);
// 
//}