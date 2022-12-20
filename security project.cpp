#include<iostream>
#include<fstream>
#include<sstream>
#include<string>

using namespace std;

int main()
{
	int a, i=0;
	string text, old, password1, password2, pass, name, password0, age,user,word,word1;
	string creds[2], cp[2];
	
	cout<<"         SECURTITY SYSTEM    "<<endl;
	
	cout<<"--------------------------------"<<endl<<endl;
	cout<<"|       1.Register             |"<<endl;
	cout<<"|       2.login                |"<<endl;
	cout<<"|       3.change password      |"<<endl;
	cout<<"|_______4.End Program _________|"<<endl<<endl;
	
	do{
		cout<<endl<<endl;
		cout<<"Enter your choise:";
		cin>>a;
		switch(a)
		{
			
			case 1:{
				cout<<"-----Register------"<<endl;
				cout<<"Please enter user name:"<<endl;
				cin>>name;
				cout<<"Please enter the password:"<<endl;
				cin>>password0;
				cout<<"Please enter your age:"<<endl;
				cin>>age;
				
				/* for storing this data we creat a file*/
				
				ofstream of1;     /*ofstrem is use for writing purpose*/
				of1.open("file.txt");
				if(of1.is_open()){
					of1<<name<<"\n";
					of1<<password0;
					cout<<"Registration is successful"<<endl;
				}
				
				break;
			}
			
			case 2:{
				i=0;
				cout<<"-----Login--------"<<endl;
				
				ifstream of2; /*ifstream is used for reading the file*/
				of2.open("file.txt");
				cout<<"Please enter your username:"<<endl;
				cin>>user;
				cout<<"PLease enter the password:"<<endl;
				cin>>pass;
				
				if(of2.is_open())
				{
					while(!of2.eof())
					{
						while(getline(of2, text)){ /*using getline functon to read file line by line*/ 
						istringstream iss(text); /*istringstream is use to stream the string and store it using extraction oprator*/ 
						iss>>word; /*iss is extraction oprator for storing the string*/
						creds[i]=word;
						i++; /*for storing user name and password will we store in different position*/	
						}
						
						if(user==creds[0] && pass==creds[1]) /*here we are matching the username stored on 0th position and pass sotred in 1 position*/ 
						{
							cout<<"----Login Successful-----"<<endl;
							cout<<endl<<endl;
							
							cout<<"Details:"<<endl;
							
							cout<<"username: "+ name<<endl;
							cout<<"Password: "+ pass<<endl;
							cout<<"Age: "+ age<<endl;
						}
						
						else{
							cout<<endl<<endl;
							cout<<"Incorrect Credentials"<<endl;
							cout<<"-----1. Press 2 to Login-----"<<endl;
							cout<<"-----2. Press 3 to change password"<<endl;
							break;
						}
					}
				}
				break;
			}
			
			case 3:{
				i=0;
				
				cout<<"-------change password-----"<<endl;
				
				ifstream of0;
				of0.open("file.txt");
				cout<<"Enter the old password:"<<endl;
				cin>>old;
				if(of0.is_open())
				{
					while(of0.eof())
					{
						while(getline(of0, text)){
							istringstream iss(text);
							iss>>word1;
							cp[i]=word1;
							i++;
						}
						if(old==cp[1])  /*comparing passsword stored on 1 position*/
						{
							of0.close(); /* for closing previous file*/
							
							ofstream of1; /*opning new file*/
							if(of1.is_open())
							{
								
								cout<<"Enter your new password:"<<endl;
								cin>>password1;
								cout<<"Enter your password again:"<<endl;
								cin>>password2;
								
								if(password1==password2)
								{
									/*overwriting passsword*/
									of1<<cp[0]<<"\n";
									of1<<password1;
									cout<<"PASSWORD CHANGED SUCCESSFULLY"<<endl; 
								}
								else{
									of1<<cp[0]<<"\n";
									of1<<old;
									cout<<"Password do not match "<<endl;
								}
							}
							
						}
						else{
							cout<<"PLease enter a valid password"<<endl;
							break;
						}
					}
				}
				break;
			}
			
			case 4:
				{
					cout<<"------THANK YOU-------"<<endl;
					break;
				}
				
				default:
					cout<<"Enter a valid choice"<<endl;
		}
	}
	
	while(a!=4);
	return 0;
	
	 
}
