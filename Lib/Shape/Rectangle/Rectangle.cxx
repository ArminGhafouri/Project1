#include"Rectangle.hxx"
#include <iostream>
#include <fstream>




Rectangle::Rectangle(const Pt2d& cor1, const Pt2d& cor2)
{
	Corner1_ = cor1;
	Corner2_ = cor2;
}


Rectangle::Rectangle(const Pt2d& center, double height, double width)
{

	Pt2d cor1;

	double x0 = center.GetX() - width / 2;
	double y0 = center.GetY() - height / 2;
	cor1.SetX(x0);
	cor1.SetY(y0);
	Corner1_ = cor1;



	Pt2d cor2;
	double x1 = center.GetX() + width / 2;
	double y1 = center.GetY() + height / 2;
	cor2.SetX(x1);
	cor2.SetY(x1);
	Corner2_ = cor2;

}




double Rectangle::CalcArea()
{

	double wid = CalcWidth();
	double heigh = CalcHeight();

	double Area = wid * heigh;
	return Area;
}

double Rectangle::CalcPeri()
{
	double wid = CalcWidth();
	double heigh = CalcHeight();

	double Peri = 2 * (wid + heigh);
	return Peri;

}

double Rectangle::CalcWidth() const
{
	double wid = std::abs(Corner2_.GetX() - Corner1_.GetX());
	return wid;
}

double Rectangle::CalcHeight() const
{
	double heigh = std::abs(Corner2_.GetY() - Corner1_.GetY());
	return heigh;
}


std::vector<std::vector<Rectangle>> Rectangle::Mesh(int nx, int ny)
{
	std::vector<std::vector<Rectangle>> results;

	double dx = CalcWidth() / nx;
	double dy = CalcHeight() / ny;
	Pt2d c1;
	Pt2d c2; 


	//corner3.SetX(Corner1_.GetX() + dx);
	//corner3.SetY(Corner1_.GetY() + dy);



	for (int i=0; i < nx ; i++)
	{
		std::vector<Rectangle> result;
		c1.SetX(i * dx);
		c2.SetX((i + 1) * dx);


		for (int j = 0 ; j < ny ;j++)
		{
			c1.SetY(j * dy);
			c2.SetY((j + 1) * dy);

			Rectangle rec1(c1, c2);
			
			result.push_back(rec1);
			
		}

		//Rectangle rec1(c1, c2);
		results.push_back(result);



	}

	return results;
}







void Rectangle::plot( std::string filename,int nx,int ny)
{
	std::fstream MyFile(filename + ".plt", std::ios::out);
	if (!MyFile.is_open())
	{
		std::cout << "file can not open" << std::endl;
		return;
	}
	

	MyFile << "Variables =  X Y" << std::endl;

	std::vector<std::vector<Rectangle>> results = Mesh(nx, ny);
	/*double row1 = results.size();*/
	int Eleman = ny * nx;
	int Node = (nx + 1) * (ny + 1);

	MyFile << "Zone N = " << Node << " , " << "E = " << Eleman << " , " << "DataPacking = point" << " , " 
		   << "ZoneType = FEQUADRILATERAL"<< std::endl;

	for (int i = 0; i <= nx; i++)
	{

		
		for (int j = 0; j <= ny; j++)
		{


			if (i == nx && j == ny)
			{
				Pt2d p = results[i-1][j-1].GetCorner2();
				MyFile << p.GetX() << "  " << p.GetY() << std::endl;
			}


			else if (i == nx)
			{
				Pt2d p1 = results[i - 1][j].GetCorner1();
				Pt2d p2 = results[i-1][j].GetCorner2();
				MyFile << p2.GetX() << "  " << p1.GetY() << std::endl;



			}

			else if (j == ny)
			{
				Pt2d p1 = results[i][j-1].GetCorner1();
				Pt2d p2 = results[i][j-1].GetCorner2();
				MyFile << p1.GetX() << "  " << p2.GetY() << std::endl;

			}


			else
			{

             Pt2d p = results[i][j].GetCorner1();
			 MyFile << p.GetX() << "  " << p.GetY() << std::endl;

			}
			


		}


	}

	for (int i = 0; i < nx; i++)
    {



		for (int j = 0; j < ny; j++)
		{


			int index1 = i * (ny + 1) + j + 1;
			int index2 = (i + 1) * (ny + 1) + j + 1;
			int index3 = index2 + 1;
			int index4 = index1 + 1;

			MyFile << index1 << "  " << index2 << "  " << index3 << "  " << index4 << std::endl;


		}


	}





	MyFile.close();

}