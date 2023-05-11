#pragma once

//#pragma once
//#include<shape.hxx>
//#include<Pt2d.hxx>
//
//class Naca2412 : public Shape
//{
//private:
//    double Yc;
//    double Xu, Yu;
//    double Xl, Yl;
//    double tetha;
//    double Dyc_to_Dx;
//    double Yt;
//
//
//
//public:
//    Naca0012(const Pt2d& cor_lead = Pt2d(), const Pt2d& cor_trail = Pt2d(), const Pt2d& center = Pt2d()); //n ta pt2d?
//    double Ave_Line_yc(double m_maximum_vatar, double p_makan_max, double x);
//    Pt2d Up(double x_up, double y_up);
//    Pt2d Down(double x_down, double y_down);
//    double Half_Thickness_yt(double max_thickness, double x);
//    
//
//};



#pragma once
#include<shape.hxx>
#include<Pt2d.hxx>
#include<Vec2d.hxx>
#include<vector>

class Naca2412 : public Shape
{
private:

    double Max_Cam;
    double Chord;
    double Thick;
    double Xc;
    double theP_;
    int nStep = 100;
    std::vector<double> theTetaV_;
    std::vector<double> theYcV_;
    std::vector<double> theYtV_;
    std::vector <Pt2d> theUpperP_;
    std::vector <Pt2d> theLowerP_;


public:

    Naca2412(const double& max_loc, const double& max_cam, const double& chord);             //n ta pt2d?
    void SetMax_Cam(double max_camber) { Max_Cam = max_camber; }
    void SetXc(double location) { Xc = location; }
    void SetChord(double chord) { Chord = chord; }
    void SetP(double location_of_max_camber) { theP_ = location_of_max_camber; }
    void SetThickness(double max_thickness) { Thick = max_thickness; }
    double GetMax_Cam()const { return Max_Cam; }
    double GetChord()const { return Chord; }
    double GetP()const { return theP_; }
    double GetThick()const { return Thick; }
    double GetXc()const { return Xc; }

    //double yc(double m_maximum_vatar, double p_makan_max, double xc);

    std::vector<double> CalcTet();
    std::vector<double> Yc();
    std::vector<double>Yt();
    std::vector <Pt2d> Up();
    std::vector <Pt2d> Down();


};