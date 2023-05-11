//#pragma once
//#include<Curve3d.hxx>
//#include<Pt3d.hxx>
//#include<Shape.hxx>
//#include<Tools.hxx>
//#define Tools_HEADER
//
//
//
//class Test:public Shape
//{
//private:
//
//	Curve3d theCurve1_;
//	Curve3d theCurve2_;
//
//
//public:
//
//	inline void SetCur1(Curve3d core1) { theCurve1_ = core1; }
//	inline void SetCur2(Curve3d core2) { theCurve2_ = core2; }
//	inline Curve3d	 GetCur1()const { return theCurve1_; }
//	inline Curve3d	 GetCur2()const { return theCurve2_; }
//	
//
//	Test(Curve3d c1, Curve3d c2);
//
//	void IntersectionOfTwoCurves();
//	TopoDS_Shape IntersectionOfCurvesAndSurfaces();
//	//void print();
//	void plot(std::string filename);
//	void PointOfGeom();
//
//
//	TopoDS_Shape Trim();
//	TopoDS_Shape NurbsSurface();
//	void BSplineCurve();
//
//};