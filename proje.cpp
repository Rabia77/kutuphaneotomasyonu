#include <iomanip> 
#include <cstring> 
#include <stdlib.h>
#include <conio.h>
#include <stdio.h> 
#include <fstream>                  
#include <iostream>

using namespace std;

struct kayit
{
	char ad[80];
	char soyad[80];
	char tc[11];
	char no[10];
} ;
struct kitapkyt
{
char kitapad[80];
char serino [80] ;
} ;

void kitapkayit();
void kitapara();
void kayitduzenle();
void kitapkayitlistele();
void kayitolustur();
void kitapkayitsil();

int main()
{
setlocale (LC_ALL,"Turkish") ; 

char anamenu;
char t;
char k;
char secim;

do{


cout<<"**********************ISUB� K�T�PHANES�NE HO� GELD�N�Z***************************" << endl << endl;
cout<<"Kay�d�n�z var m�?  (E/H)   " ;
t=getche() ;
cout<< endl;
if(t=='e'  || t=='E' )
{cout<<"**************NE YAPMAK �STERS�N�Z?**************" << endl;
cout<< "*          1-Kitap kay�d� yapma                 *" << endl;
cout<< "*          2-Kitap arama                        *" << endl;
cout<< "*          3-Kay�t d�zenleme                    *" << endl;
cout<< "*          4-Kitaplar�n kay�d�n� listeleme      *" << endl;
cout<< "*          5-kitap kay�d� silme                 *" << endl;
cout<< "*************************************************" << endl;
cin>>secim;
	switch(secim) 
	{
		case '1' : 
		{
		kitapkayit();
		break;	
		}
		case '2' : 
		{
		 kitapara()	;
		 break;
		}
		case '3' : 
		{
		 kayitduzenle()	;
		 break;
		}
		case '4' : 
		{
		 kitapkayitlistele()	;
		 break;
		}
		case '5' :
		{ 
		kitapkayitsil() ;
		break;
		}
		
		
		
	}


}
	else
{cout<< "Kay�t olu�turmak ister misiniz?  (E/H)   " ;
k=getche() ;
cout<< endl;	
	if(k=='e'  || k=='E' ){
    kayitolustur()	;
		
	}
	else{
		cout<<"Programdan ��kt�n�z..." << endl;
		break;
	}
}
		cout << "Anamen�ye d�nmek i�in a bas�n ��k�� yapmak i�in c ye bas�n..." <<endl ; 
	anamenu=getche();
	cout<<endl<<endl;
system("cls");
	
} while(anamenu=='a') ;

return 0;

}


kayit insan;
kitapkyt kitap; 

void kayitolustur()
{	
ofstream yaz("kutup.dat",ios::binary |ios::app);
	
char secim1;
int a1;

do{	cout << " Ad�n�z� giriniz:" ;
	cin>> insan.ad;

	cout << " Soyad�n�z� giriniz:";
	cin>> insan.soyad;

	cout << "TC kimlik numaran�z� giriniz:";
	cin>> insan.tc;

	cout << " ��renci numaran�z� giriniz:" << endl;
	cin>>insan.no;

	yaz.write((char*)&insan, sizeof(insan));	
	a1++;	
	
	cout<<"Ba�ka kay�t eklemek istiyor musunuz?    (E/H)";
	secim1=getche() ;
	cout<< endl;
} while(secim1=='e' || secim1=='E') ;
	cout << a1 << " tane kay�t tamamland�..." << endl;
	yaz.close();
	
}

void kitapkayit()
{
	ofstream yaz("kutup.dat",ios::binary |ios::app);
	char secim2;
	int a2=0;
	
	do{
       cout<<"Kay�t edece�niz kitab�n ad�n� giriniz:" ;
       cin>>kitap.kitapad ;
       cout<< endl;
       cout<<"Kay�t edece�niz kitab�n seri numaras�n� giriniz:" ;
       cin>>kitap.serino ;
       cout<< endl;
      
	yaz.write((char*)&kitap, sizeof(kitap));	
	a2++;	
	cout << "Ba�ka kitap eklemek ister misiniz? (E/H)" << endl;
	secim2=getche();
	cout << endl;
	}while(secim2=='e' || secim2=='E');
	
	cout << a2 << " tane kitap eklendi.." << endl;
	
	yaz.close();
	
}

void kitapkayitlistele()
{
	
	ifstream oku("kutup.dat",ios::binary |ios::app);
	
	oku.seekg(0,ios::end);
	int kayits=oku.tellg()/sizeof(kitap);
	cout << "Toplam yap�lan kitap kay�t say�s�:"<< kayits << endl;
	
	if(kayits>0)
	{
		for(int i=0; i<kayits;i++)
		{
			oku.seekg(i*sizeof(kitap));
			oku.read((char*)&kitap, sizeof(kitap));	
		
			cout << i+1 << ". G�R�LEN K�TABIN B�LG�LER�"<< endl;
			cout << "Ad�: "<< kitap.kitapad <<endl ;
			cout << "Seri numaras�: "<< kitap.serino <<endl ;
		
		}
		
		
	}
	else
	cout << "Kay�t olu�turulmad�..." << endl;

	oku.close();
}

void kitapara()
{

	ifstream oku("kutup.dat",ios::binary |ios::app);
	
	oku.seekg(0,ios::end);
	int kayits=oku.tellg()/sizeof(kitap);


cout <<"Aranan kitab�n seri numaras�n� giriniz"<< endl;
char serino[80];
cin>> serino;
 		
	if(kayits>0)
	{
		for(int i=0; i<kayits;i++)
		{
			
			oku.seekg(i*sizeof(kitap));
			oku.read((char*)&kitap, sizeof(kitap));
			
			if(strcmp(kitap.serino,serino)==0)
			{
			cout <<  "*BULUNAN K�TAP B�LG�LER�*"<< endl;
			cout << "Kitap ad�: "<< kitap.kitapad<<endl ;
			cout << "Kitap seri numaras�: "<< kitap.serino <<endl ;
		
		    }
		}
		
		
	}
	else
	cout << "Kay�t bulunamad�..." << endl;

	oku.close();
}

void kitapkayitsil()
{
	 char serino[80];
     char secim3= ' ';
     bool var=false;
     
    ifstream oku("kutup.dat",ios::binary |ios::app);
	
	oku.seekg(0,ios::end);

	int kayitsayisi=oku.tellg()/sizeof(kitap);
	
     cout<<"Kay�d�n� silece�iniz kitab�n seri numaras�n� giriniz: ";
     cin>>serino;

     for(int i=0;i<kayitsayisi;i++)
     {
            oku.seekg(i*sizeof(kitap));
			oku.read((char*)&kitap, sizeof(kitap));
			
     if(strcmp(kitap.serino,serino)==0)
       {
                 cout<<endl;
                 cout<<"Kitab�n";
                 cout<<"\nAd� : "<<kitap.kitapad<< endl;
                  cout<<"\nSeri numaras�: "<<kitap.serino<<endl;

                
         	 				  
                cout<<"\n\nSilmek istedi�iniz kay�t bu mu? (E/H): ";
                 secim3=getche();
            if(secim3 == 'H' || secim3 == 'h')
              {      
			    kitapkyt y_kitap;
                ofstream y_dosya("Yedek.dat",ios::app|ios::binary);
                
                strcpy(y_kitap.kitapad,kitap.kitapad);
                strcpy(y_kitap.serino,kitap.serino);
                
                        
                y_dosya.write((char*)&kitap, sizeof(kitap));
                y_dosya.close();
              }
            if(secim3=='e'||secim3=='E')
              {
   			   	var=true;
  		 	  }
        }
             else
             {
                kitapkyt y_kitap;
              ofstream y_dosya("Yedek.dat",ios::app|ios::binary);
              
                strcpy(y_kitap.kitapad,kitap.kitapad);
                strcpy(y_kitap.serino,kitap.serino);
                
                        
                y_dosya.write((char*)&kitap, sizeof(kitap));
                y_dosya.close();
            
             }
     }
    oku.close();
    if(var)
    {
               remove("kutup.dat");
               rename("Yedek.dat","kutup.dat");
               cout<<"\nKay�t silindi."<<endl;
    }
    else
    {
               remove("Yedek.dat");
               cout<<"\nKay�t bulunamad�..."<<endl;                  
    }
	
	
}

void kayitduzenle()
{
	 char tc[80];
     char secim4= ' ';
     bool var=false;
     
    ifstream oku("kutup.dat",ios::binary |ios::app);
	
	oku.seekg(0,ios::end);

	int kayitsayisi=oku.tellg()/sizeof(insan);
		
     cout<<"Kayd�n� d�zenleyece�iniz ��rencinin TC kimilik numaras�n� giriniz: ";
     cin>>tc;

     for(int i=0;i<kayitsayisi;i++)
     {
            oku.seekg(i*sizeof(insan));
			oku.read((char*)&insan, sizeof(insan));
			
     		if(strcmp(insan.tc,tc)==0)
     		  {
     		  	
                 cout<<endl;
                 cout<<"*��RENC�N�N*";
                 cout<<"\nAd� : "<<insan.ad<<endl;
                 cout<<"\nSoyad� : "<<insan.soyad<<endl;
                 cout<<"\nTC kimlik numaras� : "<<insan.tc<<endl;
                 cout<<"\n��renci numaras�: "<< insan.no<< endl;
                
                 
                  cout<<"\n\nD�zenleek istedi�iniz ��renci bu mu? (E/H) : ";
                  secim4=getche();
                  if(secim4 == 'E' || secim4 == 'e')
                  {
                     	var=true;
                        ofstream dosya("Yedek.dat",ios::app|ios::binary);
                        cout << "\n��renci ad�n� giriniz:";
						cin>> insan.ad;
						cout<< endl;
						cout << "��renci soyad�n� giriniz:" ;
						cin>> insan.soyad;
						cout<< endl;
						cout << "�rencinin TC kimlik numaras�n� giriniz:" ;
						cin>>insan.tc;
						cout<< endl;
						cout << "��renci numaras�n� giriniz:";
						cin>> insan.no ;
						cout << endl;
		  
                        dosya.write((char*)&insan, sizeof(insan));
                        dosya.close();
            	  }
            	 else
                 	{
                         kayit y_insan;
                         ofstream y_dosya;
                         y_dosya.open("Yedek.dat",ios::app|ios::binary);
                         
                    	 strcpy(y_insan.ad,insan.ad);
            			 strcpy(y_insan.soyad,insan.soyad);
            			 strcpy(y_insan.tc,insan.tc);
             			 strcpy(y_insan.no,insan.no);
                         
             			 y_dosya.write((char*)&y_insan, sizeof(y_insan));
                         y_dosya.close();
                   }
     }
 }
    oku.close();
    if(var)
    {
               remove("kutup.dat");
               rename("Yedek.dat","kutup.dat");
               cout<<"\nKay�t d�zenlendi."<<endl;
    }
    else
    {
               remove("Yedek.dat");
               cout<<"\nKay�t bulunamad�..."<<endl;                  
    }

}

































































































































