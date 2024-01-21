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


cout<<"**********************ISUBÜ KÜTÜPHANESÝNE HOÞ GELDÝNÝZ***************************" << endl << endl;
cout<<"Kayýdýnýz var mý?  (E/H)   " ;
t=getche() ;
cout<< endl;
if(t=='e'  || t=='E' )
{cout<<"**************NE YAPMAK ÝSTERSÝNÝZ?**************" << endl;
cout<< "*          1-Kitap kayýdý yapma                 *" << endl;
cout<< "*          2-Kitap arama                        *" << endl;
cout<< "*          3-Kayýt düzenleme                    *" << endl;
cout<< "*          4-Kitaplarýn kayýdýný listeleme      *" << endl;
cout<< "*          5-kitap kayýdý silme                 *" << endl;
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
{cout<< "Kayýt oluþturmak ister misiniz?  (E/H)   " ;
k=getche() ;
cout<< endl;	
	if(k=='e'  || k=='E' ){
    kayitolustur()	;
		
	}
	else{
		cout<<"Programdan çýktýnýz..." << endl;
		break;
	}
}
		cout << "Anamenüye dönmek için a basýn çýkýþ yapmak için c ye basýn..." <<endl ; 
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

do{	cout << " Adýnýzý giriniz:" ;
	cin>> insan.ad;

	cout << " Soyadýnýzý giriniz:";
	cin>> insan.soyad;

	cout << "TC kimlik numaranýzý giriniz:";
	cin>> insan.tc;

	cout << " Öðrenci numaranýzý giriniz:" << endl;
	cin>>insan.no;

	yaz.write((char*)&insan, sizeof(insan));	
	a1++;	
	
	cout<<"Baþka kayýt eklemek istiyor musunuz?    (E/H)";
	secim1=getche() ;
	cout<< endl;
} while(secim1=='e' || secim1=='E') ;
	cout << a1 << " tane kayýt tamamlandý..." << endl;
	yaz.close();
	
}

void kitapkayit()
{
	ofstream yaz("kutup.dat",ios::binary |ios::app);
	char secim2;
	int a2=0;
	
	do{
       cout<<"Kayýt edeceðniz kitabýn adýný giriniz:" ;
       cin>>kitap.kitapad ;
       cout<< endl;
       cout<<"Kayýt edeceðniz kitabýn seri numarasýný giriniz:" ;
       cin>>kitap.serino ;
       cout<< endl;
      
	yaz.write((char*)&kitap, sizeof(kitap));	
	a2++;	
	cout << "Baþka kitap eklemek ister misiniz? (E/H)" << endl;
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
	cout << "Toplam yapýlan kitap kayýt sayýsý:"<< kayits << endl;
	
	if(kayits>0)
	{
		for(int i=0; i<kayits;i++)
		{
			oku.seekg(i*sizeof(kitap));
			oku.read((char*)&kitap, sizeof(kitap));	
		
			cout << i+1 << ". GÝRÝLEN KÝTABIN BÝLGÝLERÝ"<< endl;
			cout << "Adý: "<< kitap.kitapad <<endl ;
			cout << "Seri numarasý: "<< kitap.serino <<endl ;
		
		}
		
		
	}
	else
	cout << "Kayýt oluþturulmadý..." << endl;

	oku.close();
}

void kitapara()
{

	ifstream oku("kutup.dat",ios::binary |ios::app);
	
	oku.seekg(0,ios::end);
	int kayits=oku.tellg()/sizeof(kitap);


cout <<"Aranan kitabýn seri numarasýný giriniz"<< endl;
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
			cout <<  "*BULUNAN KÝTAP BÝLGÝLERÝ*"<< endl;
			cout << "Kitap adý: "<< kitap.kitapad<<endl ;
			cout << "Kitap seri numarasý: "<< kitap.serino <<endl ;
		
		    }
		}
		
		
	}
	else
	cout << "Kayýt bulunamadý..." << endl;

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
	
     cout<<"Kayýdýný sileceðiniz kitabýn seri numarasýný giriniz: ";
     cin>>serino;

     for(int i=0;i<kayitsayisi;i++)
     {
            oku.seekg(i*sizeof(kitap));
			oku.read((char*)&kitap, sizeof(kitap));
			
     if(strcmp(kitap.serino,serino)==0)
       {
                 cout<<endl;
                 cout<<"Kitabýn";
                 cout<<"\nAdý : "<<kitap.kitapad<< endl;
                  cout<<"\nSeri numarasý: "<<kitap.serino<<endl;

                
         	 				  
                cout<<"\n\nSilmek istediðiniz kayýt bu mu? (E/H): ";
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
               cout<<"\nKayýt silindi."<<endl;
    }
    else
    {
               remove("Yedek.dat");
               cout<<"\nKayýt bulunamadý..."<<endl;                  
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
		
     cout<<"Kaydýný düzenleyeceðiniz öðrencinin TC kimilik numarasýný giriniz: ";
     cin>>tc;

     for(int i=0;i<kayitsayisi;i++)
     {
            oku.seekg(i*sizeof(insan));
			oku.read((char*)&insan, sizeof(insan));
			
     		if(strcmp(insan.tc,tc)==0)
     		  {
     		  	
                 cout<<endl;
                 cout<<"*ÖÐRENCÝNÝN*";
                 cout<<"\nAdý : "<<insan.ad<<endl;
                 cout<<"\nSoyadý : "<<insan.soyad<<endl;
                 cout<<"\nTC kimlik numarasý : "<<insan.tc<<endl;
                 cout<<"\nÖðrenci numarasý: "<< insan.no<< endl;
                
                 
                  cout<<"\n\nDüzenleek istediðiniz öðrenci bu mu? (E/H) : ";
                  secim4=getche();
                  if(secim4 == 'E' || secim4 == 'e')
                  {
                     	var=true;
                        ofstream dosya("Yedek.dat",ios::app|ios::binary);
                        cout << "\nÖðrenci adýný giriniz:";
						cin>> insan.ad;
						cout<< endl;
						cout << "Öðrenci soyadýný giriniz:" ;
						cin>> insan.soyad;
						cout<< endl;
						cout << "Örencinin TC kimlik numarasýný giriniz:" ;
						cin>>insan.tc;
						cout<< endl;
						cout << "Öðrenci numarasýný giriniz:";
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
               cout<<"\nKayýt düzenlendi."<<endl;
    }
    else
    {
               remove("Yedek.dat");
               cout<<"\nKayýt bulunamadý..."<<endl;                  
    }

}

































































































































