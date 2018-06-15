#include "member.h"

#include <iostream>
using namespace std;


Member::Member(){ 
		name="";
		ic="";
		status=0;
		gender=' ';
		}
		
Member::Member(string n,string i,int s,char g){
			name=n;
			ic=i;
			status=s;
			gender=g;
		}

