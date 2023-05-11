#pragma once
#include<Shape.hxx>
#include<TopoDS_Shape.hxx>
#include<TopoDS_Edge.hxx>
#include<vector>




class Fillet
{

private:


	TopoDS_Shape  theShape_;
	double  theRadius_;
	std::vector<int> theIndex_;
	

public:

	Fillet(const TopoDS_Shape& shape, double radius , const std::vector<int>& in);

	inline void SetShape(TopoDS_Shape sh) { theShape_ = sh;}
	inline void SetRadius(double rad) { theRadius_ = rad;}
	inline TopoDS_Shape GetShape()const { return theShape_;}
	inline double	GetRadius()const { return theRadius_;}

	int NumberOfEdge(const TopoDS_Shape shape);
	int NumberOfFace(const TopoDS_Shape shape);

	TopoDS_Shape ApplyFillet();
	void PlotFillet(std::string filename);


	//void PlotFilletFace(std::string filename);

	

	/***************************************************************************************/

	//TopoDS_Shape ApplyFilletFace();
	std::vector<TopoDS_Edge> FindEdges(std::vector<int> index);
	TopoDS_Shape ApplyFilletTow();
	void PlotFilletTwo(std::string filename);

};