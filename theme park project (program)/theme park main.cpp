#include "package.h"
#include "gift.h"
#include "member.h"
#include "signup.h"
#include "signin.h"

#include<iostream>
#include<fstream>
#include<cstdlib>
#include<cctype>
#include <time.h>
#include<algorithm>
using namespace std;

//Gender in Male and Female format
string genVertify(char g) {
			switch(g){
				case 'M':return "Male";
				break;
				case 'F':return "Female";
				break;
			}
		}

//Gender addressing
string genAddress(char g) {
			switch(g){
				case 'M':return "Mr";
				break;
				case 'F':return "Mrs";
				break;
			}
		}
		
//Convert numerical status to string status for customer's convenience
string cardStatus(int s) {
			switch(s){
				case 1:return "Platinum";
				break;
				case 2:return "Golden";
				break;
			}
		}

istream& operator>>(istream &in,Member &o){
			cout<<"Enter Name:"<<endl;
			in>>o.name;
			system("cls");
			
			cout<<"Enter IC:"<<endl;
			in>>o.ic;
			system("cls");
			
			cout<<"Enter Gender (M/F):"<<endl;
			in>>o.gender;
			o.gender=toupper(o.gender);
			system("cls");
			
			cout<<"Enter Card's Status you wish to register for:"<<endl
				<<"1.Platinum (20% discount)"<<endl
				<<"2.Golden (10% discount)"<<endl;
				in>>o.status;
				system("cls");
				
				return in;
		}

ostream& operator<<(ostream &out, Member const &obj){
			out<<"Thank you "<<genAddress(obj.gender)<<" "<<obj.name<<" for registering for our membership card."<<endl<<endl
				<<"Here is your card's information, if there is a problem please key in 2 to edit, 1 to quit:"<<endl
				<<"====================================="<<endl
				<<"-------------------------------------"<<endl<<endl
				<<"Name: "<<obj.name<<endl
				<<"IC: "<<obj.ic<<endl
				<<"Membership Status: "<<cardStatus(obj.status)<<endl<<endl
				<<"-------------------------------------"<<endl
				<<"====================================="<<endl;
			return out;
		}
		
int main(){
	
	//Declarations for Member class uses
	Signup signup;
	string name,ic,search,choice,memberReg;
	int c_member,c1,status=3;
	char gen;
	
	//Declarations for Package class uses
	int door, group, cTicket, aTicket, rcTicket, days, membership;
	
	cout << endl;
	
	cout << "Welcome to Euphoria Paradise!" << endl;
	cout << endl;
	
	cout << "Do you wish to buy outdoor, indoor or outdoor & indoor ticket?" << endl;
	cout << "1. outdoor" << endl;
	cout << "2. indoor" << endl;
	cout << "3. outdoor & indoor" << endl;
	cout << "Enter the number: ";
	cin >> door;
	cout << endl;
	system("cls");
	
	cout << "How many child, adult and retired citizen? " << endl;
	cout << "Enter the number of child: ";
	cin >> cTicket;
	cout << "Enter the number of adult: ";
	cin >> aTicket;
	cout << "Enter the number of retired citizen: ";
	cin >> rcTicket;
	cout << endl;
	system("cls");
	
	cout << "How many day(s) do you wish to stay? " << endl;
	cout << "Enter the day(s): ";
	cin >> days;
	cout << endl;
	system("cls");
	
	cout << "Are you a member of Euphoria Paradise? " << endl;
	cout << "1. Yes, I am a Platinum member." << endl;
	cout << "2. Yes, I am a Golden member." << endl;
	cout << "3. No, I am not registered member." << endl;
	cout << "Enter the number: ";	
	cin >> membership;
	cout << endl;
	system("cls");
	
	if(membership==1||membership==2)goto checkMember;
	//Ask for membership registration
	cout<<"Do you want to register for our membership now and experienced the benefits?(yes/no):"<<endl;
	cin>>memberReg;
	system("cls");
	transform(choice.begin(), choice.end(), choice.begin(),(int (*)(int))tolower); //change input to lowercase
	
	//User choose 1 is for membership registration
	if(memberReg=="yes"){
	do{
		cin>>signup;
		cout<<signup;
		cin>>c1;
		system("cls");
	}while(c1!=1);
	
	signup.Register();
	
	cout<<"Do you wish to verify your membership card?(yes/no):"<<endl;
	cin>>choice;
	system("cls");
	
	transform(choice.begin(), choice.end(), choice.begin(),(int (*)(int))tolower);
	if(choice=="yes")goto checkMember;
	else if (choice=="no") goto noCheck;
	}
	
	//if user choose 2 they can check their membership status.
	else if (memberReg=="no"){
		goto noCheck;
	checkMember:
		Signin signin;
		signin.Verify();
    	
    	search=signin.getSearch();
    	name=signin.getName();
    	
		if(name!=search){
		cout<<search<<" not found."; //User are notify if their username does not exist
		membership=3;
		goto noCheck;
		}
		ic=signin.getIc();
		gen=signin.getGen();
		status=signin.getStatus();
    	membership=status;
    	
    cout<<"Name: "<<name<<endl
        <<"IC:"<<ic<<endl
        <<"Card's Status:"<<cardStatus(status)<<endl
        <<"Gender:"<<genVertify(gen)<<endl<<endl;
    	
		//Sending Membership information for discount
		signup.setName(name);
		signup.setIC(ic);
		signup.setStatus(status);
		signup.setGen(gen);
		
		system("PAUSE");	
		system("cls");
	}
	
	noCheck:

	Package c(door, days, membership);
	Package a(door, days, membership);
	Package rc(door, days, membership);	
	
	c.setcTicket(cTicket);
	a.setaTicket(aTicket);
	rc.setrcTicket(rcTicket);
	c.setGroup(1);
	a.setGroup(2);
	rc.setGroup(3);
	
	Package *p = new Package(door, cTicket, aTicket, rcTicket, days, membership);
	
	cout << endl;
	cout << "*********************************************************" << endl;	
	cout << "			PURCHASE RESIT					" << endl;
	cout << endl;
	cout << "Door: " << p->getDoor() << endl;
	cout << "Day(s): " << days << endl;
	cout << "Package: " << p->getPackage() << endl;
	cout << "Status: " << p->getMembership() << endl;
	cout << endl;
	cout << "Group" << "\t\t\t" << "Number(s)" << "\t\t" << "Sub Price($)" << endl;
	cout << "---------------------------------------------------------" << endl;		 
	cout << "Child" << "\t\t\t" << cTicket << "\t\t\t" << c.printPrice() << endl;
	cout << "Adult" << "\t\t\t" << aTicket << "\t\t\t" << a.printPrice() << endl;
	cout << "Retired Citizen" << "\t\t" << rcTicket << "\t\t\t" << rc.printPrice() << endl;
	cout << "---------------------------------         ---------------" << endl;
	cout << "Overall price" << "\t\t\t\t\t" ;	
	if ((cTicket==0 && aTicket==2) && rcTicket==0) cout << p->printPrice(); 
	else if ((cTicket==2 && aTicket==2) && rcTicket==0) cout << p->printPrice(); 
	else cout << p->getTotalPrice() ; cout << endl;
	cout << "Discount" << "\t\t\t\t\t"  << rc.getDiscount() << endl;
	cout << "---------------------------------         ---------------" << endl;
	cout << "Discount price" << "\t\t\t\t\t"  << p->getDiscountPrice() << endl;
	cout << endl;
	cout << "*********************************************************" << endl;
	cout << endl;
	cout << endl;
	system("PAUSE");
	system("cls");
	
	Gift g(rc.getTotalPrice(), p);
	g.typeOfGift();
	system("PAUSE");
	system("cls");
	
	for(int i=0;i<100000;i++){
		if(i%2!=0){
		cout<<"== == == == == == == == == == == == =="<<endl
			<<"Thank you! Please come again."<<endl
			<<"  == == == == == == == == == == == == "<<endl;
			system("cls");
		}
		else if(i%2==0){
		cout<<"  == == == == == == == == == == == == "<<endl
			<<"Thank you! Please come again."<<endl				
			<<"== == == == == == == == == == == == =="<<endl;	
			system("cls");
		}
	}
	
	
	return 0;
}
