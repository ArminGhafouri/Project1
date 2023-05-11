#pragma once
#include<Shape.hxx>
#include<Pt3d.hxx>
#include<string>
#include<vector>
#include<Vec3d.hxx>

//namespace std  //name
//{
//	calss vector;
//}

class TopoDS_Vertex;
class Curve3d;
class TopoDS_Shape;
class TopoDS_Face;


class ConeTwo : Shape
{
private:

	double theRadius_;
	double theHeight_;
	Pt3d theCenter_;
	Vec3d theDirection_;


public:

	ConeTwo(const Pt3d& center, double radius, double height, Vec3d direct);


	inline Pt3d GetCenter()const { return theCenter_; }
	inline void SetCenter(Pt3d& center) { theCenter_ = center; }

	inline double GetRadius()const { return theRadius_; }
	inline void SetRadius(double radius) { theRadius_ = radius; }

	inline double GetHeight()const { return theHeight_; }
	inline void SetHeight(double height) { theHeight_ = height; }

	inline void SetDirection(Vec3d dir) { theDirection_ = dir; }
	inline Vec3d GetDirection()const { return theDirection_; }

	Curve3d CreateCurveOfBody();
	void PlotByRevolve(std::string filename);


	std::vector<TopoDS_Vertex> CreatOCVertex();
	//TopoDS_Shape BuildOCShape();
	TopoDS_Shape BuildOCShape2();
	std::vector<TopoDS_Face> CreatALLFace();
    void Plot(std::string filename);
	
	Curve3d CreateTestCurveOfBody();
	void TestPlotByRevolve(std::string filename);

};