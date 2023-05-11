//#include"Naca2412.hxx"
// 
//
//#include<iostream>
//#include<math.hxx>
//
//
//
//
//
//
//
//double Naca2412::Ave_Line_yc(double m_maximum_vatar, double p_makan_max, double x)
//{
//	
//	if (x>= 0 && x <= p_makan_max)
//	{
//		double yc0 = (m_maximum_vatar / (p_makan_max * p_makan_max)) * (2 * p_makan_max * x - (x * x));
//		return yc0;
//	}
//	else
//	{
//		double yc1 = ((m_maximum_vatar) / (1 - p_makan_max) * (1 - p_makan_max)) *
//			((1 - 2 * p_makan_max) + (2 * p_makan_max * x) - (x * x));
//		return yc1;
//	}
//
//}
//
//double Naca2412::Half_Thickness_yt(double max_thickness, double x)
//{
//	double yt = 5 * max_thickness * ((0.2969 * sqrt(x)) - (0.1260 * x) - (0.3516 * x * x) + 
//		(0.2843 * x * x * x) - (0.1015 * x * x * x * x));
//	return yt;
//
//}
//
//












//double Naca2412::yc (double m_maximum_vatar, double p_makan_max, double xc)
//{
//
//	if (xc >= 0 && xc <= p_makan_max)
//	{
//		double yc0 = (m_maximum_vatar / (p_makan_max * p_makan_max)) * (2 * p_makan_max * xc - (xc * xc));
//		return yc0;
//	}
//	else
//	{
//		double yc1 = ((m_maximum_vatar) / (1 - p_makan_max) * (1 - p_makan_max)) *
//			((1 - 2 * p_makan_max) + (2 * p_makan_max * xc) - (xc * xc));
//		return yc1;
//	}
//
//}
//











//double Naca2412::dy_dx(double k, double r, double p, double xc)
//{
//	
//	if (xc >= 0 && xc < r)
//	{
//		double dri = ((k / 6) * (xc * xc * xc) - (3 * r * xc * xc)
//			+ (r * r * (3 - r) * xc));
//		return dri;
//	}
//
//	else if (xc >= r && xc < 1)
//	{
//		double dri0 = ((k / 6) * r * r * r * (1 - xc));
//		return dri0;
//	}
//
//	else 
//	{
//		cout << "error";
//		return 0;
//	}



	////if (xc >= 0 && xc < r)
	////{
	////	double dri = ((k / 6) * (xc * xc * xc) - (3 * r * xc * xc)
	////		+ (r * r * (3 - r) * xc));
	////		return dri;
	////}

	////else        
	////{
	////	double dri0 = ((k / 6) * r * r * r * (1 - xc));
	////		return dri0;
	////}
//
//}




//double Naca2412::dy_dx()
//{
//	double tet;
//	
//
//	if (Xc >= 0 && Xc <= theP_)
//	{
//		double dri = ((2 * Max_Cam) / theP_ * theP_) * (theP_ - Xc);
//		return dri;
//	}
//
//	else if (Xc > theP_ && Xc <= 1)
//	{
//		double dri0 = ((2 * Max_Cam) / (1 - (theP_ * theP_))) * (theP_ - Xc);
//		tet = dri0;
//
//		return dri0;
//	}
//
//	else
//	{
//		cout << "error" << endl;
//		return 0;
//	}
//	 
//	
//
//}


//////std::vector<double> Naca2412::CalcTetha()
//////{
//////	theTetaV_.clear();
//////	//friend bool sin();
//////
//////	double tet;
//////	double dy_dx;
//////	double dx = Chord / nStep;
//////	double x0 = 0.0;
//////
//////
//////	for (int i = 0; i <= nStep; i++)
//////	{
//////		Xc = x0 + i * dx;
//////
//////		if (Xc >= 0 && Xc <= theP_)
//////		{
//////			dy_dx = ((2 * Max_Cam) / (theP_ * theP_)) * (theP_ - Xc);
//////		}
//////
//////		else if (Xc > theP_ && Xc <= 1)
//////		{
//////			dy_dx = ((2 * Max_Cam) / (1 - (theP_ * theP_))) * (theP_ - Xc);
//////		}
//////		tet = atan(dy_dx);
//////		theTetaV_.push_back(tet);
//////
//////	}
//////	
//////
//////		
//////
//////	/*	else
//////		{
//////			cout << "error" << endl;
//////			
//////		}*/
//////
//////
//////		return theTetaV_;
//////
//////}
//////
//////
//////
//////Pt2d Naca2412::Up()
//////{
//////
//////
//////
//////	CalcTetha();
//////
//////		//double xu = ((Xc)-(Yt() * sin(CalcTetha())));
//////		double xu = ((Xc)-(Yt() * sin(theTetaV_[I])));
//////	    
//////
//////		double yu = ((Yc() + (Yt() * cos(CalcTetha()))));
//////		
//////
//////
//////	return Pt2d(xu,yu);
//////}
//////
//////
//////Pt2d Naca2412::Down()
//////
//////{
//////
//////	CalcTetha();
//////
//////	double xl = ((Xc)-(Yt() * sin(CalcTetha())));
//////	
//////	double yl = ((Yc() - (Yt() * cos(CalcTetha()))));
//////	
//////
//////	return Pt2d(xl,yl);
//////}
//////
//////
//////





#include"Naca2412.hxx"
#include<iostream>
#include<math.hxx>


using namespace std;



Naca2412::Naca2412(const double& chord,const double& max_loc, const double& thick )
{	

	Chord = chord;
	theP_ = max_loc;
	Thick = thick;
	
}



std::vector<double> Naca2412::Yc()
{
	for (int i = 0; i <= nStep; i++)
	{

		double yc;


		if (Xc >= 0 && Xc <= theP_)
		{
			yc = (Max_Cam / (theP_ * theP_)) * (2 * theP_ * Xc - (Xc * Xc));
			
		}
		else if(Xc > theP_  &&  Xc <= 1)
		{
			 yc = ((Max_Cam) / (1 - theP_) * (1 - theP_)) *
				((1 - 2 * theP_) + (2 * theP_ * Xc) - (Xc * Xc));
		
		}


		theYcV_.push_back(yc);
	}

	return theYcV_;
}





std::vector<double> Naca2412::Yt()
{

	double yt;


	for (int i = 0; i <= nStep; i++)
	{

		 yt = 5 * Thick * ((0.2969 * sqrt(Xc)) - (0.1260 * Xc) - (0.3516 * Xc * Xc) +
		(0.2843 * Xc * Xc * Xc) - (0.1015 * Xc * Xc * Xc * Xc));

	
		theYtV_.push_back(yt);

	}
	
	return theYtV_;
	
}


//
//vector<double> Naca2412::Yc()
//{
//
//	if (Xc >= 0 && Xc <= theP_)
//	{
//		double yc0 = (Max_Cam / (theP_ * theP_)) * (2 * theP_ * Xc - (Xc * Xc));
//		return yc0;
//
//	}
//	else
//	{
//		double yc1 = ((Max_Cam) / (1 - theP_) * (1 - theP_)) *
//			((1 - 2 * theP_) + (2 * theP_ * Xc) - (Xc * Xc));
//		return yc1;
//
//	}
//
//}
//
//


	//std::vector<double> Naca2412::CalcTetha()
	//{
	//	return std::vector<double>();
	//}


	std::vector<double> Naca2412::CalcTet()

	{

		theTetaV_.clear();

		//vector< double> theTetaV_;
		


		double tet;
		double dy_dx;
		double dx = Chord / nStep;
		double x0 = 0.0;


		for (int i = 0; i <= nStep; i++)
		{
			Xc = x0 + i * dx;

			if (Xc >= 0 && Xc <= theP_)
			{
				dy_dx = ((2 * Max_Cam) / (theP_ * theP_)) * (theP_ - Xc);
			}

			else if (Xc > theP_ && Xc <= 1)
			{
				dy_dx = ((2 * Max_Cam) / (1 - (theP_ * theP_))) * (theP_ - Xc);
			}


			tet = atan(dy_dx);

			 theTetaV_.push_back(tet);

		}


		return theTetaV_;

	}



	//Pt2d Naca2412::Up()
	//{

	//	CalcTet();

	//	//double xu = ((Xc)-(Yt() * sin(CalcTetha())));

	//	double xu = ((Xc)-(Yt() * sin(theTetaV_[I])));


	//	double yu = ((Yc() + (Yt() * cos(CalcTetha()))));



	//	return Pt2d(xu, yu);

	//}


	std::vector <Pt2d> Naca2412::Up()
	{
		for (int i = 0; i <= nStep; i++)

		{
			
			double xu = ((Xc)-(theYtV_[i] * sin(theTetaV_[i])));

			double yu = ((theYcV_[i] + (theYtV_[i] * cos(theTetaV_[i]))));

			Pt2d up(xu, yu);
				
			theUpperP_.push_back(up);
		}

		return theUpperP_;
	}





	std::vector <Pt2d> Naca2412::Down()
	{
		for (int i = 0; i <= nStep; i++)

		{

			double xl = ((Xc) + (theYtV_[i] * sin(theTetaV_[i])));

			double yl = ((theYcV_[i] - (theYtV_[i] * cos(theTetaV_[i]))));

			Pt2d lp(xl, yl);
			
			theLowerP_.push_back(lp);
		}


		return theLowerP_;
	}









	/*Pt2d Naca2412::Down()

	{

		CalcTet();

		double xl = ((Xc)-(Yt() * sin(CalcTetha())));

		double yl = ((Yc() - (Yt() * cos(CalcTetha()))));


		return Pt2d(xl, yl);
	}*/

