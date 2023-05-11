#pragma once
#include<Pt3d.hxx>
#include<Vec3d.hxx>
#include<Tools.hxx>
#include<TopoDS_Shape.hxx>
#include<GeomToStep_MakePolyline.hxx>
#include<BRepPrimAPI_MakeRevolution.hxx>
#include<BRepPrim_Wedge.hxx>
#include<BRepBuilderAPI_Transform.hxx>
#include<Curve3d.hxx>
#include<Shape.hxx>



class Model : public Shape
{

private:

	double theRadiusOFCylinder_;
	double theLongBody_;
	Pt3d   theOrigin_;
	double theDegreeOfConicNose_;

public:

	Model(Pt3d theOrigin, double nosetetha, double radiuscylinder, double totallLong);


	inline void SetRadiusCylinder(double RadiusCylinder_) { theRadiusOFCylinder_ = RadiusCylinder_; }
	inline void SetLongBody(double longafterbody) {theLongBody_ = longafterbody; }
	inline void SetDegreeOfNoise(double degreeofnose) { theDegreeOfConicNose_ = degreeofnose; }
    inline void SetOrgin(Pt3d orig) { theOrigin_ = orig; }

	inline double GetRadiusCylinder()const { return theRadiusOFCylinder_; }
	inline double GetLongBody()const { return theLongBody_; }
	inline double GetDegreeOfNoise()const { return theDegreeOfConicNose_; }
    inline Pt3d GetOrigin()const { return theOrigin_; }


	

	
	TopoDS_Vertex CreatOCvertex1();
	TopoDS_Vertex CreatOCvertex2();
	TopoDS_Vertex CreatOCvertex3();
	TopoDS_Vertex CreatOCvertex4();

	TopoDS_Edge CreatOCedge1();
	TopoDS_Edge CreatOCedge2();
	TopoDS_Edge CreatOCedge3();
	TopoDS_Edge CreatOCedge4();






	//void PlotLine(std::string filename);
	//TopoDS_Shape WedgeOCcreat()const;
	/*void RevolvMo(std::string filename, int deg, int nu, int nv);*/


	//void Plot(std::string filename, int nu, int nv);

	TopoDS_Shape CreateOCWedge()const;
	TopoDS_Shape CreateOCsurfaceConic(int deg0);
	Curve3d CreateCurveOCModel();

	void Plot(std::string filename);
	void Plot2(int deg0 , std::string filename);

	






};