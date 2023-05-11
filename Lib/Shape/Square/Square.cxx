#include"Square.hxx"
#include<fstream>


Squar::Squar(const Pt2d& cor, double a)
{
	theCorner_ = cor;
	theA_ = a;

}



double Squar::CalcArea()
{
	double Area = theA_ * theA_;
	return Area;

}



double Squar::CalcPeri()
{
	double Peri = 4.0 * theA_;
	return Peri;

}



void Squar::Plot(std::string filename)
{
	std::fstream MyFile(filename + ".plt", std::ios::out);

	if (!MyFile.is_open())
	{
		std::cout << "file not open" << std::endl;
		return;
	}

	MyFile << "Variable X , Y" << std::endl;
	MyFile << "Zone T  = Square" << std::endl;

	MyFile << theCorner_.GetX() << "  " << theCorner_.GetY() << std::endl;
	MyFile << theCorner_.GetX()+theA_ << "  " << theCorner_.GetY() << std::endl;
	MyFile << theCorner_.GetX()+theA_ << "  " << theCorner_.GetY()+theA_ << std::endl;
	MyFile << theCorner_.GetX() << "  " << theCorner_.GetY()+theA_ << std::endl;
	MyFile << theCorner_.GetX() << "  " << theCorner_.GetY() << std::endl;


	MyFile.close();
}
