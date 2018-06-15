#ifndef GIFT_H
#define GIFT_H
#include "package.h"

#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

class Gift
{
	private:
		double totalPrice;
		string gift; 
		int smallGift, mediumGift, largeGift, megaGift;
		Package *pack;
	public:
		Gift() {gift="";}
		Gift(double tp, Package *p) {this->totalPrice=tp , pack=p;}
		void setTotalPrice(double tp) {totalPrice=tp;}
		void setGift(string g) {gift=g;}
		double getTotalPrice() {return totalPrice;}
		string getGift() {return gift;}
		
		void typeOfGift();
		
};

#endif
