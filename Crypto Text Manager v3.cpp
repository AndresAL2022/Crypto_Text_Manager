#include<iostream>
#include<string.h>
#include<cmath>
#include<stdlib.h>
#include<iomanip>
#include<time.h>
#include<ctime>
#include<windows.h>
#include<cstdlib>
#include<string>
#include<fstream>
#include<vector>

#include"listDir.cpp"

using namespace std;

using std::cout; using std::cin;
using std::endl; using std::string;

void cryptov2();
void escribir();
void leer();
string encode(string cadena);
string decode(string cadenaencoded);

int main(){
	
	cryptov2();
	
}

void cryptov2(){
	
	cout<<"[==================== Cryptolock V3 Text Editor ===================]"<<endl<<endl;
	
	cout<<"	1. CryptoWriter"<<endl;
	cout<<"	2. CryptoReader"<<endl;
	cout<<endl;
	cout<<" [0] Return To Menu"<<endl<<endl;
	
	int op;
	
	cout<<" |> "; cin>>op;
	
	switch(op){
		
		case 1:
			
			escribir();
			
			cryptov2();
			
			break;
			
		case 2:
			
			leer();
			
			cryptov2();
			
			break;
			
		/*case 0:
			
			system("CLS");
			menuUI();
			
			break;*/
			
		default:
			
			cout<<endl<<"Opcion Incorrecta"<<endl;
			
			break;
		
	}
	
	cout<<endl;
	
	//menuUI();
	cryptov2();
	
}

void leer(){
	
	fstream archivo;
	
	cout<<endl;
	cout<<"==============================="<<endl;
	cout<<" Which One you Want to open?"<<endl<<endl;
	
	cout<<" 1. Use dataIn"<<endl;
	cout<<" 2. Use dataOut"<<endl;
	cout<<" 3. Own File (for messy people)"<<endl;
	cout<<endl;
	cout<<" [0] Exit to Main Menu"<<endl;
	cout<<"==============================="<<endl<<endl;
	
	int op;
	
	cout<<" |> "; cin>>op;
	
	switch(op){
		
		case 1:
			
				archivo.open("dataIn.txt", ios::in);
			
				if (!archivo) {
	
				cout <<endl<< "	Archivo No Encontrado!"<<endl;
	
				}
	
				else {
		
				char ch;
		
				cout<<endl<<" [========== Decoded Text ==========] "<<endl<<endl;

				while (1) {
			
					archivo>>ch;
			
					if (archivo.eof())
						
						break;
				
					//ch = decode(ch);
		
					string cadenadecoded = "";
	
					cadenadecoded += (char) (ch - 11);
					
					if(cadenadecoded=="·"){
						
						cout<<endl;
						cadenadecoded = "";
						
					}
					
					if(cadenadecoded=="|"){
						
						cout<<endl;
						cadenadecoded = "";
						
					}
		
					cout<<cadenadecoded;
			
				}

			}
	
			cout<<endl;
		
			archivo.close();
			
			break;
			
		case 2:
			
			archivo.open("dataOut.txt", ios::in);
			
			if (!archivo) {
	
				cout <<endl<< "	Archivo No Encontrado!"<<endl;
	
				}
	
				else {
		
				char ch;
		
				cout<<endl<<" [========== Decoded Text ==========] "<<endl<<endl;

				while (1) {
			
					archivo>>ch;
			
					if (archivo.eof())
						
						break;
				
					//ch = decode(ch);
		
					string cadenadecoded = "";
	
					cadenadecoded += (char) (ch - 11);
					
					if(cadenadecoded=="·"){
						
						cout<<endl;
						cadenadecoded = "";
						
					}
					
					if(cadenadecoded=="|"){
						
						cout<<endl;
						cadenadecoded = "";
						
					}
		
					cout<<cadenadecoded;
			
				}

			}
	
			cout<<endl;
		
			archivo.close();
			
			break;
			
		case 3:
			
			string filename;
			
			char list = 'n';
			
			cout<<"\n Do you want to list files? [y o n] |> "; cin>>list; cout<<endl;
			
			if(list=='y'){
				
				cout<<"----------------------------------------------"<<endl;
				listDir();
				cout<<"----------------------------------------------"<<endl;
				
			}
			
			cout<<"FileName -> "; cin>>filename;
			cout<<endl;
			
			archivo.open(filename.c_str(), ios::in);
			
			if (!archivo) {
	
				cout<<" ***********ERROR*************\n";
				cout<<" *    Archivo No Encontrado  *\n";
				cout<<" *****************************"<<endl;
				
				leer();
	
				}
	
				else {
		
				char ch;
		
				cout<<endl<<" [========== Decoded Text ==========] "<<endl<<endl;

				while (1) {
			
				    archivo>>ch;
			
					if (archivo.eof())
						
						break;
				
					//ch = decode(ch);
		
					string cadenadecoded = "";
	
					cadenadecoded += (char) (ch - 11);
					
					if(cadenadecoded=="·"){
						
						cout<<endl;
						cadenadecoded = "";
						
					}
					
					if(cadenadecoded=="|"){
						
						cout<<endl;
						cadenadecoded = "";
						
					}
		
					cout<<cadenadecoded;
			
				}

			}
	
			cout<<endl;
		
			archivo.close();
			
			break;
			
		/*default:
			
			cout<<endl<<"*************************";
			cout<<endl<<" Incorrect Option Buddy!"<<endl;
			cout<<" Choose Again :)"<<endl;
			cout<<"*************************"<<endl;
			
			leer();*/
		
	}
	
	
	
}

void escribir(){
	
	ofstream archivo;
	
	char resp;
	
	cout<<endl<<" Do u want to use default OutFile [dataOut.txt]?	(y|n)"<<endl<<endl;
	
	cout<<" |> "; cin>>resp;
	
	cout<<endl;
	
	if(resp=='y'){
		
		string nombrearchivo = "dataOut.txt", frase;
		
		cout<<" [/help] Shows Commands for Editor"<<endl<<endl;
	
		//cout<<"nombre del archivo -> ";
		//getline(cin,nombrearchivo);
	
		archivo.open(nombrearchivo.c_str(), ios::out);
	
		if(archivo.fail()){
		
			cout<<endl<<" F leyendo el archivo";
			cout<<endl;
			cryptov2();
		
		}
	
		string rpt;
	
		do{
		
			fflush(stdin);
			cout<<" > ";
			getline(cin, frase);
			rpt = frase;
			frase += "·";
			
			if(rpt=="/help"){
				
				frase=="";
				
				cout<<"\n========== Help Section =========="<<endl;
				cout<<endl;
				cout<<" /exit Exits Savin All Data"<<endl;
				cout<<" /help Displays List of Commands"<<endl;
				cout<<endl;
				cout<<"===================================="<<endl<<endl;
				
			}
			
		    /*else if(rpt=="/space"){
				
				frase = encode("|");
				archivo<<frase<<endl;
				
			}*/
			
			else if(rpt=="/exit"){
				
				
				
			}
			
			else{
				
				frase = encode(frase);
				archivo<<frase<<endl;
				
			}
			
			
		}while(rpt != "/exit");
	
		archivo.close();
		
	}
	
	else if(resp=='n'){
		
		string nombrearchivo, frase;
	
		cout<<endl<<"nombre del archivo -> "; cin>>nombrearchivo;
		//getline(cin,nombrearchivo);
		
		cout<<endl;
	
		archivo.open(nombrearchivo.c_str(), ios::out);
	
		if(archivo.fail()){
		
			cout<<endl<<"F leyendo el archivo";
			cout<<endl;
			cryptov2();
		
		}
	
		string rpt;
	
		do{
		
			fflush(stdin);
			cout<<" > ";
			getline(cin, frase);
			rpt = frase;
			frase += "·";
			
			if(rpt=="/help"){
				
				frase=="";
				
				cout<<"\n========== Help Section =========="<<endl;
				cout<<endl;
				cout<<" /exit Exits Savin All Data"<<endl;
				cout<<" /help Displays List of Commands"<<endl;
				cout<<endl;
				cout<<"===================================="<<endl<<endl;
				
			}
			
		    /*else if(rpt=="/space"){
				
				frase = encode("|");
				archivo<<frase<<endl;
				
			}*/
			
			else if(rpt=="/exit"){
				
				
				
			}
			
			else{
				
				frase = encode(frase);
				archivo<<frase<<endl;
				
			}
			
			
		}while(rpt != "/exit");
	
		archivo.close();
	
		archivo.close();
		
	}
	
	else{
		
		cout<<endl<<"*************************";
		cout<<endl<<" Incorrect Option Buddy!"<<endl;
		cout<<" Choose Again :)"<<endl;
		cout<<"*************************"<<endl;
			
		escribir();
		
	}
	
	
	
}

string encode(string cadena){
	
	string cadenacoded = "";
	
	for(int i=0; i<cadena.length(); i++){
		
		cadenacoded += (char) (cadena[i] + 11);
		
	}
	
	return cadenacoded;
	
}

string decode(string cadenacoded){
	
	string cadenadecoded = "";
	
	for(int i=0; i<cadenacoded.length(); i++){
		
		cadenadecoded += (char) (cadenacoded[i] - 11);
		
	}
	
	return cadenadecoded;
	
}

