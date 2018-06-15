#include "signup.h"
#include "member.h"
#include<iostream>
#include<fstream>
using namespace std;

void Signup::Register(){
			fstream regMember;
				regMember.open("Membership.txt",ios::out | ios::app);
				regMember<<name<<endl;
				regMember<<ic<<endl;
				regMember<<status<<endl;
				regMember<<gender<<endl<<endl;
				regMember.close();
				system("cls");
			}
