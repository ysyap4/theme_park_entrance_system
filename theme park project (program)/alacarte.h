#ifndef ALACARTE_H
#define ALACARTE_H

#include <iostream>
using namespace std;

class Alacarte{
	protected:
		int door, group, ticket, days, membership,cTicket, aTicket, rcTicket;
		double groupPrice;
		
	public: 
		//default constructor
	
																
		//constructor
		Alacarte(int dr, int dy, int ms) {door=dr; days=dy; membership=ms;}		
		
		//price allocation for different kind of tickets
		void setcTicket(int c){cTicket=c;}
		void setaTicket(int a){aTicket=a;}
		void setrcTicket(int rc){rcTicket=rc;}
		void setDoor(int dr) {door=dr;}
		void setGroup(int gr) {group=gr;}		
		void setDays(int dy) {days=dy;}
		void setMembership(int ms) {membership=ms;}
		
		double outdoorA();
		double indoorA();
		double outInA();
};

#endif
