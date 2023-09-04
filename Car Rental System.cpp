#include <iostream> //input/output
#include <fstream> // File
#include <unistd.h> //Sleep
#include <iomanip> //setting width
#include <ctime> //Time

using namespace std;
class Customer{
	public:
		string customer_name;
		int car_model;
		string car_Number;
};
class rent:public Customer{
	private:
		int number_days;
		int rent_fee;
		char str[200];
	public:
		rent();
		void welcome();
		void filereader(char carfile[20]);
		void data();
		void invoiceamount();
		void invoicerecord();
};

rent::rent(){
	number_days = 0;
	rent_fee = 0;
}

void rent::welcome(){
	ifstream inputfile("Welcome.txt");
	if (!inputfile){
		cout<<"can't open Welcome File.\n";
	}
	char str[1000];
	while (inputfile){
		inputfile.getline(str,1000);
		if(inputfile){
			cout<<str<<endl;
		}
		inputfile.close();
		cout<<"\nStarting the program Please wait....."<<endl;
		cout<<"Loading Up Files For You......."<<endl;
		system("CLS");
	}
}

void rent::filereader(char carfile[20]){
	ifstream inputfile;
	inputfile.open(carfile);
	if (inputfile){
		cout<<"Error in printing File"<<endl;
	}
	while(inputfile){
		inputfile.getline(str,200);
		if (inputfile){
			cout<<str<<endl;
		}
	}
}
void rent::data(){
	cout<<"\t\t\t\tEnter Your Name ";
	cin>>customer_name;
	cout<<endl;
	do{
		cout<<"\t\t\t\t________________"<<endl;
		cout<<"\t\t\t\tChoose a Car From the Options"<<endl;
		cout<<"\t\t\t\tChoose a number of car which you want"<<endl;
		cout<<"\t\t\t\t________________"<<endl;
		cout<<"\t\t\t\t1. Toyota 2021"<<endl;
		cout<<"\t\t\t\t2. Hyudai 2019"<<endl;
		cout<<"\t\t\t\t3. Ford 2020"<<endl;
		cout<<"\t\t\t\t________________"<<endl;
		cout<<"\t\t\t\tChoose"<<endl;
		cin>>car_model;
		cout<<endl;
		
		switch(car_model){
			case 1:
				system("CLS");
				cout<<"You have Choosen Toyota 2021"<<endl;
				filereader("Toyota.txt");
				break;
			case 2:
				system("CLS");
				cout<<"You have Choosen Hyudai 2021"<<endl;
				filereader("Hyudai.txt");
				break;
			case 3:
				system("CLS");
				cout<<"You have Choosen Ford 2021"<<endl;
				filereader("Ford.txt");
				break;
			default :cout<<"Please Choose any car between 1 to 3"<<endl;			
		}
	}while(car_model <1 && car_model <3 );
	
	cout<<"Please This all Information"<<endl;
	cout<<"Please Write Down your Car Number "<<endl;
	cin>>car_Number;
	cout<<"Number of days you wish to rent"<<endl;
	cin>>number_days;
	cout<<endl;
}
void rent::invoiceamount(){
	system("CLS");
	cout<<"Total Rent";
	if(car_model == 1){
		rent_fee=number_days*150;
	}
	if(car_model == 2){
		rent_fee=number_days*160;
	}
	if(car_model == 3){
		rent_fee=number_days*170;
	}
}

void rent::invoicerecord(){
	time_t now = time(0);
	char *date = ctime(&now);
	cout<< setw(80)<<date <<endl;
	cout<<"\n\t\t     Car Rental System - Customer Invoice "<<endl;
	cout<<"\t\t________________________________________________"<<endl;
	cout<<"\t\t________________________________________________"<<endl;
	cout<<"                Invoice No."<<"                           "<<setw(10)<<"#1001"<<endl;
	cout<<"                Customer_name"<<"                         "<<setw(10)<<customer_name<<endl;
	cout<<"                Car Model"<<"                             "<<setw(10)<<car_model<<endl;
	cout<<"                Car No."<<"                               "<<setw(10)<<car_Number<<endl;
	cout<<"                Number Of days"<<"                        "<<setw(10)<<number_days<<endl;
	cout<<"                Rental Amount"<<"                         "<<setw(10)<<rent_fee<<endl;
	cout<<"\t\t________________________________________________"<<endl;
	cout<<endl;
	cout<<"                Total Amount"<<"                          "<<setw(10)<<rent_fee<<endl;	
	cout<<"\t\t________________________________________________"<<endl;
}
int main(){
	
	rent rnt;
	rnt.welcome();
	rnt.data();
	rnt.invoiceamount();
	rnt.invoicerecord();
}
