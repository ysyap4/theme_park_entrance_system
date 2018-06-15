#include "gift.h"
#include "package.h"

#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

		
		void Gift::typeOfGift()
		{
			srand (time(NULL));
			smallGift = rand() % 3 + 1;
			mediumGift = rand() % 3 + 1;
			largeGift = rand() % 3 + 1;
			megaGift = rand() % 3 + 1;
						
			if (pack->getDiscountPrice() < 100)
			{
				if(smallGift==1) gift="sticker";
				else if(smallGift==2) gift="key chain";
				else if(smallGift==3) gift="Subway discount voucher (RM5)";
				
				cout << "Thanks for spending on Euphoria Paradise, you have been rewarded a mini gift!" << endl;
				cout << "The mini gift you got is " << gift << "." << endl;
				cout << "Enjoy your moment in Euphoria Paradise!" << endl;
			}
			else if (pack->getDiscountPrice()  >= 100 && pack->getDiscountPrice()  < 1000)
			{
				if(mediumGift==1) gift="popcorn coupon (grab for free at any Euphoria Paradise's' stall)";
				else if(mediumGift==2) gift="Avengers water bottle";
				else if(mediumGift==3) gift="couple's T-shirts (1 for male, 1 for female)";
				
				cout << "Thanks for spending on Euphoria Paradise, you have been rewarded a fine gift!" << endl;
				cout << "The fine gift you got is " << gift << "." << endl;
				cout << "Enjoy your moment in Euphoria Paradise!" << endl;				
			}
			else if (pack->getDiscountPrice()  >= 1000 && pack->getDiscountPrice()  < 2000)
			{
				if(largeGift==1) gift="The Hunger Games: Mockingjay - Part 2 movie ticket";
				else if(largeGift==2) gift="limited edition USB";
				else if(largeGift==3) gift="Burberry shopping voucher (RM100)";
							
				cout << "Thanks for spending on Euphoria Paradise, you have been rewarded a great gift!" << endl;
				cout << "The great gift you got is " << gift << "!" << endl;
				cout << "Enjoy your moment in Euphoria Paradise!" << endl;				
			}
			else if (pack->getDiscountPrice()  > 2000)
			{
				if(megaGift==1) gift="Louis Vuitton VIP shopping voucher (RM300)";
				else if(megaGift==2) gift="Taylor Swift 1989 World Tour concert ticket"; 
				else if(megaGift==3) gift="Deluxe Family package Jogoya Buffet (6 persons)";
				
				cout << "Thanks for spending on Euphoria Paradise, you have been rewarded a luxury gift!" << endl;
				cout << "The luxury gift you got is " << gift << "!!!" << endl;
				cout << "Enjoy your moment in Euphoria Paradise!!!" << endl;				
			}
		}
	

