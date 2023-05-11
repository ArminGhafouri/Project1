#pragma once
#include<Pt3d.hxx>
#include<iostream>
#include"Tools.hxx"

#include<TopoDS_Shape.hxx>

class Box
{
private:
	Pt3d theCorner1_;
	Pt3d theCorner2_;


public:

	Box(Pt3d cor1, Pt3d cor2);
	inline void SetCor1(Pt3d core1) { theCorner1_ = core1; }
	inline void SetCor2(Pt3d core2) { theCorner2_ = core2; }
	inline Pt3d	 GetCor1()const { return theCorner1_; }
	inline Pt3d	 GetCor2()const { return theCorner2_; }
	void Plot(std::string filename);

	//TopoDS_Shape MakeBoxOne(Pt3d core1 , Pt3d core2);

};
