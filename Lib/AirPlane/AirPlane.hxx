#pragma once
#include<Shape.hxx>
#include<TopoDS_Shape.hxx>



class AirPlane : public Shape
{

private:



	double theRadius_;


public:

	AirPlane(double radius);

	/*TopoDS_Shape*/void CreatAirPlane();
	TopoDS_Shape CreatAirPlaneREshape();
	TopoDS_Shape CreatAirPlaneREshape2();

	void rotatedpositive();
	void rotatednegative();
	TopoDS_Shape ShapeOfBody();











};