#include "alacarte.h"
#include<iostream>
using namespace std;

double Alacarte::outdoorA(){
			if (group==1)
				{
					if (days==1) groupPrice=30*cTicket*days;
					else if (days==2) groupPrice=28*cTicket*days;
					else if (days==3) groupPrice=24*cTicket*days;
					else groupPrice=20*cTicket*days;
				}
				else if (group==2)
				{
					if (days==1) groupPrice=40*aTicket*days;
					else if (days==2) groupPrice=38*aTicket*days;
					else if (days==3) groupPrice=34*aTicket*days;
					else groupPrice=30*aTicket*days;
				}
				else if (group==3)
				{
					if (days==1) groupPrice=20*rcTicket*days;
					else if (days==2) groupPrice=18*rcTicket*days;
					else if (days==3) groupPrice=14*rcTicket*days;
					else groupPrice=10*rcTicket*days;
				}
				else
				{
					cout << "The group doesn't exists. Please try again." << endl;
				}
				return groupPrice;
}


double Alacarte::indoorA(){
				if (group==1)
				{
					if (days==1) groupPrice=20*cTicket*days;
					else if (days==2) groupPrice=18*cTicket*days;
					else if (days==3) groupPrice=14*cTicket*days;
					else groupPrice=10*cTicket*days;
				}
				else if (group==2)
				{
					if (days==1) groupPrice=25*aTicket*days;
					else if (days==2) groupPrice=23*aTicket*days;
					else if (days==3) groupPrice=19*aTicket*days;
					else groupPrice=16*aTicket*days;
				}
				else if (group==3)
				{
					if (days==1) groupPrice=15*rcTicket*days;
					else if (days==2) groupPrice=13*rcTicket*days;
					else if (days==3) groupPrice=9*rcTicket*days;
					else groupPrice=6*rcTicket*days;
				}
				else
				{
					cout << "The group doesn't exists. Please try again." << endl;
				}
				return groupPrice;
}
				
double Alacarte::outInA(){
				if (group==1)
				{
					if (days==1) groupPrice=40*cTicket*days;
					else if (days==2) groupPrice=38*cTicket*days;
					else if (days==3) groupPrice=34*cTicket*days;
					else groupPrice=30*cTicket*days;
				}
				else if (group==2)
				{
					if (days==1) groupPrice=50*aTicket*days;
					else if (days==2) groupPrice=48*aTicket*days;
					else if (days==3) groupPrice=44*aTicket*days;
					else groupPrice=40*aTicket*days;					
				}
				else if (group==3)
				{
					if (days==1) groupPrice=30*rcTicket*days;
					else if (days==2) groupPrice=28*rcTicket*days;
					else if (days==3) groupPrice=24*rcTicket*days;
					else groupPrice=20*rcTicket*days;
					
				}
				else
				{
					cout << "The group doesn't exists. Please try again." << endl;
				}
				return groupPrice;
}
