#include "signin.h"
#include "member.h"
#include <iostream>
#include<fstream>
using namespace std;


void Signin::Verify(){	
		cout<<"Enter your name:"<<endl;
					cin>>search;
					system("cls");
					
					ifstream regMember;
					regMember.open("Membership.txt");
					string line;
					while (getline(regMember,line)){
				        if (line.find(search) != string::npos) {
				        	name=line;
							regMember>>ic;
							regMember.ignore();
							regMember>>status;
							regMember.ignore();
							regMember>>gender;
				        }
				        
				    }
			}
