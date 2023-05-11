#pragma once
#include<Vec2d.hxx>
#include<Pt3d.hxx>




//class Vec3d 
//{
//
//	private:
//		double theW_;
//		double theU_;
//		double theV_;
//
//	public:
//
//		Vec3d(double u,double v,double w);
//		
//		double GetU()const;
//		double GetV()const;
//		double GetW()const;
//		void   SetW(double w);
//		void   SetU(double u);
//		void   SetV(double v);
//		void   Print() const ;
//		double DotProduct(const Vec3d & b)const;
//		Vec3d CrossProdtuct(const Vec3d & b)const;
//		
//
//
//};


class Vec3d : public Vec2d
{

protected:

	double theW_;

public:
	Vec3d(double u = 0.0, double v = 0.0, double w = 0.0);
	Vec3d(const Pt3d& p0, const Pt3d& p1);
	inline double GetW()const { return theW_; }
	inline void SetW(double w) { theW_ = w; }
	void Print() const override;

	double DotProduct(const Vec3d& b)const;
	Vec3d CrossProdtuct(const Vec3d& b)const;

	double Magnitude()const;
	double CalcTeta(const Vec3d& k);

};
