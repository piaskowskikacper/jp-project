#include <iostream>
#include <windows.h>
#include <fstream>
#include <sstream>

using namespace std;


string sprawdzenie_roku(string war){
	
	
bool git=false;	
	
short s;

int ktory_obieg=1;


do{

if(ktory_obieg>1){
cout << "Podaj rok wydania ksi¹¿ki: ";

cin >> war;

};

int lp = 0;

int bb = 0 ;



int lm =0;

int lbledow=0;

int lz = 0;



 for (char c : war){

            if( c == '.'){

                lp ++; 

				}

				

			else if( c == '0' || c == '1'){

                bb ++; 

				}

				

			else if(c== '-'){

				lm++;

			}

			

			else if (c!= '2' && c!= '3' && c!= '4' && c!= '5' && c!= '6' && c!= '7' && c!= '8' && c!= '9'){

				lbledow++;

			}

				

          lz++;      

        }

        



            

if (lbledow>0 || lp>1 || lm>1){

	cout << "Podano b³êdne dane wejœciowe!\n" << endl;

}        

    	

else	    

if (lz>1 && lp==1){

	if (lm==1){

		 if(war.c_str()[0]!='-')

		 cout << "Podano b³êdne dane wejœciowe!\n" << endl;

	

	else{

	cout << "Podano b³êdne dane wejœciowe!\n" << endl;}

}

else{

	cout << "Podano b³êdne dane wejœciowe!\n" << endl;}        }



else

if(bb==1 && lz==1 && lm ==0) {

	git=true;

}

else        

if (atoi(war.c_str()) != 0) {

	if (lm==1)	{

		 if(war.c_str()[0]!='-')

		 cout << "Podano b³êdne dane wejœciowe!\n" << endl;

	

	else{

	s = atoi(war.c_str());

if(s<=2020) git=true;
	else cout << "Nie dodajemy ksi¹¿ek z przysz³oœci! :) \n";
	
	
	}

}

	else{

	s = atoi(war.c_str());

	if(s<=2020) git=true;
	else cout << "Nie dodajemy ksi¹¿ek z przysz³oœci! :) \n";

       }
}
	   
ktory_obieg++;	   
	    
}while(!git);


return war;
}



void dodaj(){
	
	
	int start=1;
    int ileksiazek=0;
	long numer_kolejny;
    fstream plik;
    
    if(start==1){
    string line="";    
    plik.open("ksiazki.txt", ios::in);
	while(plik.good())
	{
    getline(plik, line);

    ileksiazek++;
	}
	numer_kolejny=(ileksiazek/7)+1;
	if (plik.is_open()) plik.close();
}
	
	
		
	int lk=1;
	string tekst="";
	plik.open("ksiazki.txt", ios::app);
	
	

	while(lk<8) {
		tekst="";
				
		if(lk==1 && plik.is_open()){	
			ostringstream ss;
			ss << numer_kolejny;
			string str = ss.str();
			plik << str+"\n";
		}
		
		if(lk==2 && plik.is_open()){
			cout<<"Podaj sygnaturê ksi¹¿ki: ";
			getline(cin, tekst);
			plik << tekst+"\n";
		}
		
		if(lk==3 && plik.is_open()){
			cout<<"Podaj autora ksi¹¿ki ksi¹¿ki: ";
			getline(cin, tekst);
			plik << tekst+"\n";
		}
		
		if(lk==4 && plik.is_open()){
			cout<<"Podaj tytu³ ksi¹¿ki: ";
			getline(cin, tekst);
			plik << tekst+"\n";
		}
		
		if(lk==5 && plik.is_open()){
			cout<<"Podaj ISBN ksi¹¿ki: ";
			getline(cin, tekst);
			plik << tekst+"\n";
		}
		
		if(lk==6 && plik.is_open()){
			cout<<"Podaj wydawnictwo ksi¹¿ki: ";
			getline(cin, tekst);
			plik << tekst+"\n";
		}
		
		if(lk==7 && plik.is_open()){
			
			cout<<"Podaj rok wydania ksi¹¿ki: ";
			
			getline(cin, tekst);
			
			string poprawione = sprawdzenie_roku(tekst);
			
			plik << poprawione+"\n";
		}
		
					
		lk++;
		}
		if (plik.is_open()) plik.close();
		
		cout << "\n Pomyœlnie dodano now¹ ksi¹¿kê do bazy danych. \n-----------------------------------------------------\n\n";
	}
	


void listuj(){
	
	fstream plik;
	string line="", lista="(id | sygnatura | autor | tytu³ | ISBN | wydawnictwo | rok_wydania) \n ";
	int lk=1;
	
	plik.open("ksiazki.txt", ios::in);


	while(plik.good())
	{
    getline(plik, line);
    lista+=line+" | ";
	if(lk%7==0) {lista+="\n ";
	lk=0;}
	
    lk++;
	}
	if (plik.is_open()) plik.close();
	cout<<lista+" KONIEC LISTY \n-----------------------------------------------------\n\n";

};


void wyszukaj(){
	
	
	string s;
	bool inBlad;
    int wybor = 0;
	
		do {
    inBlad=false;
    cout << " Wyszukuj po: \n\n";
	cout << " 1. ID.\n 2. Tytu³.\n 3. ISBN. \n\n";
	cout << " Wybierz co chcesz zrobiæ: ";
    getline(cin,s);
    for (char c: s)
    {
        if (c >= '0' && c <= '9') {
            wybor = wybor * 10 + (c - '0');
        }
        
        
        
        else {
            inBlad=true;
            cerr << " WprowadŸ wartoœæ liczbow¹ z zakresu 1-3! \n";
            wybor=0;
            break;
        }
       
    } 
    
    if (wybor<1 || wybor>3) {
        	inBlad=true;
			cout<<" WprowadŸ wartoœæ liczbow¹ z zakresu 1-3! \n";
			wybor=0;
			
		}
    
        
} while (inBlad || s=="");
	
	string wyszukaj, line="";
	
	if(wybor==1){
		
		cout << " Podaj nr id poszukiwanej ksi¹¿ki: ";
	
	cin >> wyszukaj;
	string tmp="";
	 fstream plik;
	 plik.open("ksiazki.txt", ios::in);
	
	bool czy=false;
	
	while(plik.good() && !czy)
	{
    getline(plik, line);

    if(line==wyszukaj){
    	tmp+=line+" | ";
    	
    	for(int i=1;i<=6;i++){
    	getline(plik, line);
	
    	tmp+=line+" | ";
    }
    
		czy=true;
	}
	}
	
	
	if (plik.is_open()) plik.close();
	
	
	if(czy){
	cout << "\n\n(id | sygnatura | autor | tytu³ | ISBN | wydawnictwo | rok_wydania) \n";
	cout << tmp << "\n\n";
	cout << "-----------------------------------------------------\n\n";
	}
	else cout << "Nie znaleziono ksi¹¿ki. \n-----------------------------------------------------\n\n";
	}
	

	if(wybor==2){
		cout << " Podaj tytu³ poszukiwanej ksi¹¿ki: ";
	
	cin >> wyszukaj;
	string tmp="";
	 fstream plik;
	 plik.open("ksiazki.txt", ios::in);
	
	bool czy=false;
	int licznik=0;
	
	while(plik.good() && !czy)
	{
	licznik++;
    getline(plik, line);

	tmp+=line+" | ";

    if(line==wyszukaj){
    	
    	for(int i=1;i<=3;i++){
    	getline(plik, line);
	
    	tmp+=line+" | ";
    }
    
		czy=true;
	}
		
		else if(licznik==7) {
			licznik=0;
			tmp="";
		}
	
	}
	
	
	if (plik.is_open()) plik.close();
	
	
	if(czy){
	cout << "\n\n(id | sygnatura | autor | tytu³ | ISBN | wydawnictwo | rok_wydania) \n";
	cout << tmp << "\n\n";
	cout << "-----------------------------------------------------\n\n";
	}
	else cout << "Nie znaleziono ksi¹¿ki. \n-----------------------------------------------------\n\n";
	}

	if(wybor==3){
		cout << " Podaj ISBN poszukiwanej ksi¹¿ki: ";
	
	cin >> wyszukaj;
	string tmp="";
	 fstream plik;
	 plik.open("ksiazki.txt", ios::in);
	
	bool czy=false;
	int licznik=0;
	
	while(plik.good() && !czy)
	{
	licznik++;
    getline(plik, line);

	tmp+=line+" | ";

    if(line==wyszukaj){
    	
    	for(int i=1;i<=2;i++){
    	getline(plik, line);
	
    	tmp+=line+" | ";
    }
    
		czy=true;
	}
		
		else if(licznik==7) {
			licznik=0;
			tmp="";
		}
	
	}
	
	
	if (plik.is_open()) plik.close();
	
	
	if(czy){
	cout << "\n\n(id | sygnatura | autor | tytu³ | ISBN | wydawnictwo | rok_wydania) \n";
	cout << tmp << "\n\n";
	cout << "-----------------------------------------------------\n\n";
	}
	else cout << "Nie znaleziono ksi¹¿ki. \n-----------------------------------------------------\n\n";
	}

	
};


void usun(){
	
	
	int start=1;
    int ileksiazek=0, ksiazki;
    fstream plik;
    
    if(start==1){
    string line="";    
    plik.open("ksiazki.txt", ios::in);
	while(plik.good())
	{
    getline(plik, line);

    ileksiazek++;
	}
	ksiazki=(ileksiazek/7);
	if (plik.is_open()) plik.close();

	cout << "W bibliotece znajduje siê " << ksiazki<< " ksi¹¿êk. Podaj numer id ksi¹¿ki któr¹ chcesz usun¹æ: ";
	
	int lk=1;
	
	int usun=0;
	cin >> usun;
	
	plik.open("ksiazki.txt", ios::in);

	string tmp ="";
	
	int i=1;
		
	while(plik.good())
	{
    getline(plik, line);
    
    if(i<(usun*7-6)){
    	 tmp += line+"\n";
    	i++;
	}
	else if(i>=(usun*7-6) && i<=(usun*7)){
		tmp+="---\n";
		i++;
	}
	else if(line==""){
		break;
	}
	
	
	else{
		tmp+=line+"\n";
		i++;
	}
     
	}
	
	if (plik.is_open()) plik.close();
	
	ofstream plik2;
	
	plik2.open("ksiazki.txt", ios::trunc );
	plik2 << tmp;
	if (plik.is_open()) plik.close();
	
	cout << " Usuniêto ksi¹¿kê o id " << usun << " z bazy danych.\n\n";
	
}};



int main(int argc, char** argv) {
	
	SetConsoleCP( 852 );
    setlocale ( LC_ALL, "" );
    
    cout<<" Witaj w programie do obs³ugi naszej biblioteki. \n\n";
    
    bool koniec;
    
    do{ 
	 
    koniec=false;
    
	cout<<" Wybierz co chcesz zrobiæ\n\n Menu: \n 1. Dodaj ksi¹¿kê. \n 2. Listuj ksi¹¿ki. \n 3. Wyszukaj ksi¹¿kê. \n 4. Usuñ ksi¹¿kê. \n\n 5. WyjdŸ. \n\n";
	
	
	string s;
    bool inBlad;
    int wybor = 0;
    
    
    
    
  
	
	do {
    inBlad=false;
    cout<<" Wybierz co chcesz zrobiæ: ";
    getline(cin,s);
    for (char c: s)
    {
        if (c >= '0' && c <= '9') {
            wybor = wybor * 10 + (c - '0');
        }
        
        
        
        else {
            inBlad=true;
            cerr << " WprowadŸ wartoœæ liczbow¹ z zakresu 1-5! \n";
            wybor=0;
            break;
        }
       
    } 
    
    if (wybor<1 || wybor>5) {
        	inBlad=true;
			cout<<" WprowadŸ wartoœæ liczbow¹ z zakresu 1-5! \n";
			wybor=0;
			
		}
    
        
} while (inBlad || s=="");
	
	
	switch (wybor)
{
case 1:
    dodaj();
    wybor=0;
   break;
case 2:
    listuj();
    wybor=0;
   break;
case 3:
    wyszukaj();
    wybor=0;
   break;
case 4:
    usun();  
	wybor=0; 
 break;
case 5:
    koniec=true;  
    cout<<" \n ¯egnaj!";
   break;
default:
    break;
}
	
}while(!koniec);
			
	return 0;
}

