#pragma once
#include<Shape.hxx>
#include<TopoDS_Shape.hxx>

class AirPlaneTwo : public Shape
{

private:



	double theRadius_;





public:

	AirPlaneTwo(double radius);

	/*void CreatAirPlane();

	void rotatedpositive();
	void rotatednegative();*/
	void ShapeOfBody();
	void ShapeOfbus();
	void ShapeOfBody2();











};