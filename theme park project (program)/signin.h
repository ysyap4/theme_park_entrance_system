#ifndef SIGNIN_H
#define SIGNIN_H
#include "member.h"
#include <iostream>
using namespace std;

class Signin:public Member{

		private:
			string search;
			
		public:	
			string getSearch(){return search;}
			void Verify();
};

#endif
