#include"Ellips.hxx"
#include<Vec2d.hxx>
#include<fstream>
#include<iostream>


//
//Ellips::Ellips(Pt2d focy1, Pt2d focy2,int nstep)
//{
//	theFocy1_ = focy1;
//	theFocy2_ = focy2;
//	theNstep_ = nstep;
//	theFocy1_.Print();
//	theFocy2_.Print();
//	std::cout << "number of step = " << nstep << std::endl;
//
//}
//
// 
//
//
//
//
//
//std::vector <Pt2d>  Ellips::CalcY()
//{
//
//	std::vector<Pt2d> points;
//
//
//
//	double dx = theLargD_ / theNstep_;
//	double xc;
//	double y;
//	double x0 = 0.0;
//
//	for (int i = 0; i <= theNstep_; i++)
//
//	{
//		xc =(x0) + i * dx;
//
//		y = std::sqrt(std::pow(theSmalD_ / 2, 2)) * (1 - ((xc * xc) / std::pow(theLargD_ / 2, 2)));
//
//
//		
//
//		double xfocy = theFocy1_.GetX();
//		double xfocy2 = theFocy2_.GetX();
//		double yfocy = theFocy1_.GetY();
//		double yfocy2 = theFocy2_.GetY();
//
//		Vec2d f0(Pt2d(xc, y), Pt2d(xfocy, yfocy));
//		Vec2d f1(Pt2d(-xc, y), Pt2d(xfocy2, yfocy2));
//
//
//
//		double mag = (f1.Magnitude())+(f0.Magnitude());
//
//		 
//        if (mag == theLargD_)
//		{
//			
//
//
//
//		//points.push_back(f2);
//		/*points.push_back(f3);
//		points.push_back(f4);
//		points.push_back(f5);*/
//
//		}
//
//	
//
//	}
//
//
//	return points;
//
//
//}
//
//
//
//
//
//
//void Ellips::Plot(std::string filename)
//{
//
//	std::fstream f(filename + ".plt", std::ios::out);
//	if (!f.is_open())
//	{
//		std::cout << "can not open this file" << std::endl;
//		return;
//	}
//	
//	f << "VARIABLES = X , Y" << std::endl;
//	f << "Zone T = Ellips" << std::endl;
//
//
//	std::vector<Pt2d> ellips = CalcY();
//
//
//	for (int i = 0; i < ellips.size(); i++)
//	{
//		double x = ellips[i].GetX();
//		double y = ellips[i].GetY();
//
//		f << x << "  " << y << std::endl;
//
//	}
//
//
//	f.close();
//
//
//
//}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////




Ellips::Ellips(Pt2d focy1, Pt2d focy2, int nstep)
{
	theFocy1_ = focy1;
	theFocy2_ = focy2;
	theNstep_ = nstep;
	theFocy1_.Print();
	theFocy2_.Print();
	std::cout << "number of step = " << nstep << std::endl;

}





std::vector <Pt2d>  Ellips::CalcYupperpoint(int n)
{

	std::vector<Pt2d> points;



	//double dx = 1.0 / theNstep_;
	
	    double x0 = -theLargD_/2.0;
		double dx = theLargD_ /n;

		//std::vector<Pt2d> pointss;

		for (int i = 0; i <= n ; i++)
		{
			double xc = x0 + i * dx;

			Pt2d point = Calcup(xc);

			//point.Scale(theLargD_/2.0);

			points.push_back(point);

		}



		return points;

}





//std::vector <Pt2d>  Ellips::CalcYlower()
//{
//
//	std::vector<Pt2d> points;
//
//
//
//	double dx = theLargD_ / theNstep_;
//	double xc;
//	double y;
//	double x0 = 0.0;
//
//	for (int i = 0; i <= theNstep_; i++)
//
//	{
//		xc = (x0)+i * dx;
//
//		y = -(std::sqrt((theSmalD_ * theSmalD_) * (1 - ((xc * xc) / ((theLargD_ / 2) * (theLargD_ / 2))))));
//
//
//		Pt2d point = (xc, y);
//
//		points.push_back(point);
//
//	}
//
//
//	return points;
//
//
//}




void Ellips::Plot(std::string filename, int n)
{

	std::fstream f(filename + ".plt", std::ios::out);
	if (!f.is_open())
	{
		std::cout << "can not open this file" << std::endl;
		return;
	}

	f << "VARIABLES = X , Y" << std::endl;
	f << "Zone T = upper" << std::endl;


	std::vector<Pt2d> ellips = CalcYupperpoint(n);


	for (int i = 0; i < ellips.size(); i++)
	{
		double x = ellips[i].GetX();
		double y = ellips[i].GetY();

		f << x << "  " << y << std::endl;

	}
	f << "VARIABLES = X , Y" << std::endl;
	f << "Zone T = lower" << std::endl;

	std::vector<Pt2d> lo0 = CalcYLowerpoint(n);

	for (int i = 0; i < lo0.size(); i++)
	{
		double x = lo0[i].GetX();
		double y = lo0[i].GetY();

		f << x << "  " << y << std::endl;


	}

	f.close();



}

std::vector<Pt2d> Ellips::CalcYLowerpoint(int n)
{


	std::vector<Pt2d> points;



	//double dx = 1.0 / theNstep_;

	double x0 = -theLargD_ / 2.0;
	double dx = theLargD_ / n;

	//std::vector<Pt2d> pointss;

	for (int i = 0; i <= n; i++)
	{
		double xc = x0 + i * dx;

		Pt2d point = Calclow(xc);
		//point.Scale(theLargD_/2.0);

		points.push_back(point);

	}



	return points;


}





Pt2d Ellips::Calcup(double xc)
{
	double xu;
	double yu;
	double y = std::sqrt((theSmalD_ * theSmalD_) * (1 - ((xc * xc) / ((theLargD_ / 2) * (theLargD_ / 2)))));

	
	
		
	 xu = xc;
	 yu = y;
	

	
	
	return Pt2d(xu, yu);
}




Pt2d Ellips::Calclow(double xc)
{
	double xu;
	double yu;
	double y = std::sqrt((theSmalD_ * theSmalD_) * (1 - ((xc * xc) / ((theLargD_ / 2) * (theLargD_ / 2)))));




	xu = xc;
	yu =-y;




	return Pt2d(xu, yu);
}