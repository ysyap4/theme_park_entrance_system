#ifndef MEMBER_H
#define MEMBER_H

#include <iostream>
using namespace std;

class Member{
	protected:
		string name;
		string ic;
		int status;
		char gender;
	public:
		//default constructor
		Member();
		//Oh look, another constructor
		Member(string ,string ,int ,char);
		//accessor and mutators
		void setName(string n){name=n;}
		void setIC(string i){ic=i;}
		void setStatus(int s){status=s;}
		void setGen(char g){gender=g;}
		string getName(){return name;}
		string getIc(){return ic;}
		int getStatus(){return status;}
		char getGen(){return gender;}
		
		//cin function for class
		friend istream& operator>>(istream &,Member &);
		//cout function for class
		friend ostream& operator<<(ostream &, Member const &);
};

#endif

