#include<Naca4Digits.hxx>
#include<iostream>
#include<fstream>


Naca4Digits::Naca4Digits(int digits, double chord)
{
	theChord_ = chord;


	int t = digits % 100;
	theT_ = (t / 100.0)/* * chord*/;


	int p = digits / 100;
	int p0 = p % 10;
	theP_ = (p0 / 10.0)/* * chord*/;



	int m = p / 10 ;
	theM_ = (m / 100.0) /** chord*/;


	std::cout << " t = " << theT_ << ", p = " << theP_ << ", m = " << theM_ << std::endl;

}

double Naca4Digits::CalcYt(double xc)
{
	double yt = 5.0 * theT_ * ((0.2969 * sqrt(xc)) - (0.1260 *xc) - (0.3516 * xc * xc) +
		(0.2843 * xc * xc * xc) - (0.1036 * xc * xc * xc * xc));


	return yt;
}



double Naca4Digits::CalcYc(double xc)
{

	double yc;

	if (xc >= 0.0 && xc <= theP_)
	{
		 yc = (theM_/ (theP_ * theP_)) * (2.0 * theP_ * xc - (xc * xc));

	}
	else if (xc > theP_ && xc <= 1.0)
	{
		yc = ((theM_) / std::pow(1.0 - theP_, 2.0)) *
			((1.0 - 2.0 * theP_) + (2.0 * theP_ * xc) - (xc * xc));

	}



	return yc;
}




double Naca4Digits::CalcDyDx(double xc)

{
	double dy_dx;


	if (xc >= 0.0 && xc <= theP_)
	{
		dy_dx = ((2.0 * theM_) / (theP_ * theP_)) * (theP_ - xc);
	}

	else if (xc > theP_ && xc <= 1.0)
	{
		dy_dx = ((2.0 * theM_) / std::pow (1.0 - theP_ , 2.0)) * (theP_ - xc);
	}


	return dy_dx;
}



double Naca4Digits::CalcTheta(double xc)
{

	return std::atan(CalcDyDx(xc));
}


Pt2d Naca4Digits::CalcUpper(double xc)
{

	if (theM_ == 0.0)
	{
		return Pt2d(xc, CalcYt(xc));

	}



	double yt = CalcYt(xc);
	double theta = CalcTheta(xc);

	double xu = xc - yt * std::sin(theta);
	double yu = CalcYc(xc) + yt * std::cos(theta);

	return Pt2d(xu , yu);
}



Pt2d Naca4Digits::CalcLower(double xc)
{
	if (theM_ == 0.0)
	{
		return Pt2d(xc, -CalcYt(xc));


	}

	double yt = CalcYt(xc);
	double theta = CalcTheta(xc);

	double xl = xc + yt * std::sin(theta);
	double yl = CalcYc(xc) - yt * std::cos(theta);

	return Pt2d(xl, yl);
}




std::vector<Pt2d> Naca4Digits::CalcUpperPoints(int n)
{
	double dx = 1.0 / n;

	std::vector<Pt2d> points;

	for (int i = 0; i <= n; i++)
	{
		double xc = i * dx;

		Pt2d point = CalcUpper(xc);
		point.Scale(theChord_);

		points.push_back(point);

	 }



	return points;
}

std::vector<Pt2d> Naca4Digits::CalcLowerPoints(int n)
{

	double dx = 1.0 / n;
	std::vector<Pt2d> points;
	for (int i = 0; i <= n; i++)
	{
		double xc = i * dx;
		Pt2d point = CalcLower(xc);
		point.Scale(theChord_);
		points.push_back(point);
	}

	return points;

}


void Naca4Digits::Plot(std::string FileName, int n)
{
	std::fstream f( FileName + ".plt", std::ios::out);
		if (!f.is_open())
		{
			std::cout << "can not open this file" << std::endl;
			return;
		}

		f << "VARIABLES = X , Y" << std::endl;
		f << "Zone T = upper" << std::endl;
		
		std::vector<Pt2d> up0 = CalcUpperPoints(n);

		for (int i = 0; i < up0.size(); i++)
		{
			double x = up0[i].GetX();
			double y = up0[i].GetY();

			f << x << "  " << y << std::endl;



		}


		f << "VARIABLES = X , Y" << std::endl;
		f << "Zone T = lower" << std::endl;

		std::vector<Pt2d> lo0 = CalcLowerPoints(n);

		for (int i = 0; i < lo0.size(); i++)
		{
			double x = lo0[i].GetX();
			double y = lo0[i].GetY();

			f << x << "  " << y << std::endl;


		}
		f.close();

}
