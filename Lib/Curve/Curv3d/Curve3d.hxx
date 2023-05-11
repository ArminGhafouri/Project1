#pragma once
#include<Shape.hxx>
#include<iostream>
#include<vector>
#include<Pt3d.hxx>
#include<Geom_Curve.hxx>
#include<TColgp_Array1OfPnt.hxx>
  


class Curve3d : public Shape
{

private:

	std::vector<Pt3d> thePts_;
	std::vector<double> theU_;
	int theDegree_;

public:

	Curve3d(){}

	Curve3d(int Deg, std::vector<Pt3d> pts);
	void SetDegree(int deg) { theDegree_ = deg; }
	int GetDegree()const { return theDegree_; }
	std::vector<Pt3d>GetPts()const { return thePts_; }
	std::vector<double>GetU()const { return theU_; }
	void SetPts(const std::vector<Pt3d>& pts) { thePts_ = pts; }
	void SetU(const std::vector<double>& u) { theU_ = u; }

	void CalcTheU();
	void Plot(std::string filename, int n);

	Handle(Geom_Curve) CreateOCCurve()const;

	std::vector<int> CalcMutiplicities()const;
	std::vector<double> CalcKnots() const;


};