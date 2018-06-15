#ifndef PACKAGE_H
#define PACKAGE_H
#include "alacarte.h"
#include <iostream>
using namespace std;


class Package:public Alacarte
{
	private:
		static double totalPrice;
		static int count;
	public:

		Package(int dr, int dy, int ms):Alacarte(dr,dy,ms){door=dr; days=dy; membership=ms;}
		Package(int dr, int ct, int at, int rct, int dy, int ms):Alacarte(dr,dy,ms){this->door=dr; this->cTicket=ct; this->aTicket=at; this->rcTicket=rct; this->days=dy; this->membership=ms;}
		
		string getDoor();
		string getGroup();
		int getDays();
		string getPackage();
		string getMembership();
		double getTotalPrice();
		string getDiscount();
		double getDiscountPrice();
		
		double outdoorPrice();
		double indoorPrice();
		double outdoorIndoorPrice();
		double printPrice();


};

#endif
