#include "package.h"
#include "alacarte.h"
#include <iostream>
using namespace std;


int Package::count=0;
double Package::totalPrice=0;


		string Package::getDoor() 
		{
			if (door==1) return "outdoor";
			else if (door==2) return "indoor"; 
			else if (door==3) return "outdoor and indoor"; 
		}	
		string Package::getGroup() 
		{
			if (group==1) return "child";
			else if (group==2) return "adult";
			else if (group==3) return "retired citizen";
		}	
	
		int Package::getDays() {return days;}
		string Package::getPackage()
		{
			if ((cTicket==0 && aTicket==2) && rcTicket==0)
			{
				if (days==1) return "single day couple access package";
				else if (days==2) return "double days couple access package";
				else if (days==3) return "triple days couple access package";
				else return "multiple days couple access package";
			}
			else if ((cTicket==2 && aTicket==2) && rcTicket==0)
			{
				if (days==1) return "single day family access package";
				else if (days==2) return "double days family access package";
				else if (days==3) return "triple days family access package";
				else return "multiple days family access package";				
			}
			else
			{
				if (days==1) return "single day access package";
				else if (days==2) return "double days access package";
				else if (days==3) return "triple days access package";
				else return "multiple days access package";			
			}
		}
		string Package::getMembership() 
		{
			if (membership==1) return "Platinum member";
			else if (membership==2) return "Golden member";
			else if (membership==3) return "non-member";
			
		}
		double Package::getTotalPrice() 
		{
			return totalPrice;
		}
		string Package::getDiscount()
		{
			if (membership==1) return "20%";
			else if (membership==2) return "10%";
			else if (membership==3) return "0%";			
		}
		double Package::getDiscountPrice()
		{
			if (membership==1) 
			{	
				if ((cTicket==0 && aTicket==2) && rcTicket==0) return printPrice()*80/100;
				else if ((cTicket==2 && aTicket==2) && rcTicket==0) return printPrice()*80/100;
				else return getTotalPrice()*80/100;
			}
			else if (membership==2) 
			{	
				if ((cTicket==0 && aTicket==2) && rcTicket==0) return printPrice()*90/100;
				else if ((cTicket==2 && aTicket==2) && rcTicket==0) return printPrice()*90/100;
				else return getTotalPrice()*90/100;
			}		
			else if (membership==3) 
			{	
				if ((cTicket==0 && aTicket==2) && rcTicket==0) return printPrice();
				else if ((cTicket==2 && aTicket==2) && rcTicket==0) return printPrice();
				else return getTotalPrice();
			}
		}
		
		double Package::outdoorPrice()
		{
			if ((cTicket==0 && aTicket==2) && rcTicket==0) //couple's package
			{
				if (days==1) groupPrice=70*days;
				else if (days==2) groupPrice=68*days;
				else if (days==3) groupPrice=64*days;	
				else groupPrice=62*days;		
			}
			else if ((cTicket==2 && aTicket==2) && rcTicket==0) //family's package
			{
				if (days==1) groupPrice=120*days;
				else if (days==2) groupPrice=116*days;
				else if (days==3) groupPrice=108*days;
				else groupPrice=100*days;
			}
			else //neither couple or family package, proceed alacarte price (inherit from alacarte class)
			{
				groupPrice=outdoorA();
			}
			
			totalPrice += groupPrice;
			return groupPrice;
		}
		
		double Package::indoorPrice()
		{
			if ((cTicket==0 && aTicket==2) && rcTicket==0) //couple's package
			{
				if (days==1) groupPrice=35*days;
				else if (days==2) groupPrice=33*days;
				else if (days==3) groupPrice=30*days;
				else groupPrice=27*days;				
			}
			else if ((cTicket==2 && aTicket==2) && rcTicket==0) //family's package
			{
				if (days==1) groupPrice=80*days;
				else if (days==2) groupPrice=75*days;
				else if (days==3) groupPrice=60*days;
				else groupPrice=55*days;
			}
			else //neither couple or family package, proceed alacarte price (inherit from alacarte class)
			{
				groupPrice=indoorA();
			}			
			
			totalPrice += groupPrice;
			return groupPrice;
		}
		
		double Package::outdoorIndoorPrice()
		{
			if ((cTicket==0 && aTicket==2) && rcTicket==0) //couple's package
			{
				if (days==1) groupPrice=85*days;
				else if (days==2) groupPrice=82*days;
				else if (days==3) groupPrice=76*days;
				else groupPrice=70*days;				
			}
			else if ((cTicket==2 && aTicket==2) && rcTicket==0) //family's package
			{
				if (days==1) groupPrice=150*days;
				else if (days==2) groupPrice=145*days;
				else if (days==3) groupPrice=135*days;
				else groupPrice=125*days;
			}
			else //neither couple or family package, proceed alacarte price (inherit from alacarte class)
			{
				groupPrice=outInA();
			}
			
			totalPrice += groupPrice;
			return groupPrice;
		}
				
		double Package::printPrice()
		{
			double pri;
			
			if (door==1)
			{
				pri=outdoorPrice();
			}
			else if (door==2)
			{
				pri=indoorPrice();
			}
			else if (door==3)
			{
				pri=outdoorIndoorPrice();
			}
			else
			{
				cout << "The choice of door entered is incorrect." << endl;
			}
			
			return pri;
		}

