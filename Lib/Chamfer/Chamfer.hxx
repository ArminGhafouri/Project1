#pragma once
#include<Shape.hxx>
#include<TopoDS_Shape.hxx>
#include<vector>




class Chamfer
{

private:

	TopoDS_Shape  theShape_;
	double  theLong_;
	std::vector<int> theIndex_;



public:

	Chamfer(const TopoDS_Shape& shape, double radius, const std::vector<int>& in);

	inline void SetShape(TopoDS_Shape sh) { theShape_ = sh; }
	inline void SetRadius(double rad) { theLong_ = rad; }
	inline TopoDS_Shape GetShape()const { return theShape_; }
	inline double	GetRadius()const { return theLong_; }


	TopoDS_Shape ApplyChamfer();
	void PlotChamfer(std::string filename);
	
};