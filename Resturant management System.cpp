#include<iostream>
#include<cstring>
#include<fstream>
#include<stdio.h>
#include<iomanip>
#include<stdlib.h>
#include <stdlib.h> 

using namespace std;

int rec_flag=0,no=0;
char rec_ind[5];
int fl=0;
int totalbill;
struct record
{
  char cost[15],ind[5];
  char  food_no[20],name[50];
  char items_available[15];
  
}rec[200],bufe[500],bufee[500];

struct tb
{
	char cost[50];
}bt[100];
struct index
{
    char food_no[20],ind[20];
}in[200],temp,tep[200];


void sort_index()
{
    int i,j;
    for(i=0;i<no-1;i++)
    for(j=0;j<no-i-1;j++)
    if(strcmp(in[j].food_no,in[j+1].food_no)>0)
    {
       temp=in[j];
       in[j]=in[j+1];
       in[j+1]=temp;
    }

}
void modi(char *food_no)
{
	int j=0;
	int flg=0;
	fstream file1,f2;
	
	file1.open("record1.txt",ios::in);
	       while(!file1.eof()){
		   
		  file1.getline(bufe[j].ind,5,'|');
		  file1.getline(bufe[j].food_no,20,'|');
		  file1.getline(bufe[j].name,20,'|');
		  file1.getline(bufe[j].cost,15,'|');
		  file1.getline(bufe[j].items_available,15,'\n');
		  
	       j++;
		   }
	j--;
	file1.close();
	    for(int i=0;i<j;i++)
       {
          if(strcmp(bufe[i].food_no,food_no)==0)
         {
          cout<<"enter the name to be modified: ";
          cin>>bufe[i].name;
          cout<<"enter the cost to be modified: ";
          cin>>bufe[i].cost;
          cout<<"enter the items_available to be modified: ";
          cin>>bufe[i].items_available;
        
          
          flg=1;
          
		  }
       }
                 if(flg==0)
                 {
				 cout<<"food_no not found\n";
				 return;
				 }
				 
				 else
				 {
				 f2.open("record1.txt",ios::out);	
			for(int i=0;i<j;i++)
			{
			
				 
				 
				 f2<<bufe[i].ind<<"|"<<bufe[i].food_no<<"|"<<bufe[i].name<<"|"<<bufe[i].cost<<"|"<<bufe[i].items_available<<"\n";
				 
			}
			
			f2.close();
				 }
				
			
			return;	 
				 
	 }	
	 
	 
	
void bilmodi(char *food_no,int remstck)
{
	char rmst[15];
	sprintf(rmst, "%d", remstck);

int j=0;
	int flg=0;
	fstream file1,f2;
	
	file1.open("record1.txt",ios::in);
	       while(!file1.eof()){
		   
		  file1.getline(bufe[j].ind,5,'|');
		  file1.getline(bufe[j].food_no,20,'|');
		  file1.getline(bufe[j].name,20,'|');
		  file1.getline(bufe[j].cost,15,'|');
		  file1.getline(bufe[j].items_available,15,'\n');
		  
	       j++;
		   }
	j--;
	file1.close();
	    for(int i=0;i<j;i++)
       {
          if(strcmp(bufe[i].food_no,food_no)==0)
         {
          sprintf(bufe[i].items_available, "%d", remstck);
          flg=1;
          
		  }
       }
                 if(flg==0)
                 {
				 //cout<<"uid not found\n";
				 return;
				 }
				 
				 else
				 {
				 f2.open("record1.txt",ios::out);	
			for(int i=0;i<j;i++)
			{
			
				 
				 
				 f2<<bufe[i].ind<<"|"<<bufe[i].food_no<<"|"<<bufe[i].name<<"|"<<bufe[i].cost<<"|"<<bufe[i].items_available<<"\n";
				 
			}
			
			f2.close();
				 }
				
			
			return;	 
			
	
	
}

void retrive_record(char *ind)
{
    for(int i=0;i<no;i++)
    {
      if(strcmp(rec[i].ind,ind)==0)
      {
          strcpy(rec_ind,ind);
          rec_flag=1;
          cout<<"\nrecord found:";
          if(fl==0)
         {
	        cout<<rec[i].food_no<<"|"<<rec[i].name<<"|"<<rec[i].cost<<"|"<<rec[i].items_available<<"\n";
         }
         else if (fl==1)
          {
               cout<<rec[i].items_available<<"\n";
           }
           
           
		   
		   else
		   {  int l,m,n,v,total,rmitems_available;
		      cout<<"Enter the total no of food items  required\n";
		      cin>>l;
		      			
		      m= atoi(rec[i].items_available);
		      v= atoi(rec[i].cost);
		      if(l<m)
		      {  rmitems_available=m-l;
		         totalbill=totalbill+l*v;
		        //cout<<"the total amount is : "<<total<<"\n";
		        bilmodi(rec[i].food_no,rmitems_available);
		       }
		     else
		         {cout<<"out of items_available: ";}
		   }
		
		   }
		}
		 
		   
          
          
          
	 
          
	 fl=0;
	  return;
      
   }
    



int search_index(char *food_no)
{
      int flag=0;
      for(int i=0;i<no;i++)
      {
	  if(strcmp (in[i].food_no,food_no)==0)
	  {
 	     retrive_record(in[i].ind);
	     flag=1;
	  }
      }
      if(flag)
	  return 1;
      else
	  return -1;
}

int search_food_no(char *food_no,int j)
{
      int flag=0;
      for(int i=0;i<j;i++)
      {
	  if(strcmp (rec[i].food_no,food_no)==0)
	  {
	     flag=1;break;
	  }
      }
      if(flag)
	  return 1;
      else
	  return -1;
}

void items_available1(char *st_food_no)
        {   fl=1;
	int q=search_index(st_food_no);
		if(q==1)
		   cout<<"\nSearch successful, Results found\n";
		else
		   cout<<"\nSearch not successful, Results not found\n";
       
       
}


void bill(char *st_food_no)
        {   fl=3;
	int q=search_index(st_food_no);
		if(q==1)
		   cout<<"\nbill successful and amount paid\n Thank you \n";
		   
		else
		   cout<<"\nbill  not successful and amount not paid \n Please try again\n";
		   
       
       
}

void cbill()
{ int r=0,j=0;
totalbill=0;

	
char food_id[5];
	cout<<"enter the no of food items  to be billed\n";
cin>>r;
for(int i=0;i<r;i++)
{
	fl=3;
	cout<<"enter the food_id \n";
	cin>>food_id;
	
	int q=search_index(food_id);
	
		
	}	
	
	cout<<"total bill is : Rs: "<<totalbill;
	
	
	
}
void delet(char *st_food_no)
{
      rec_flag=0;
      int fr=0;
      search_index(st_food_no);
      if(!rec_flag)
      {
	 cout<<"\ndeletion failed\nrecord not found";
	 return;
      }
      for(int i=0;i<no;i++)
      {
	 if(strcmp(rec[i].ind,rec_ind)==0)
	  {   fr=i; break;}
      }
      for(int i=fr;i<no-1;i++)
      {
	 rec[i]=rec[i+1];
	 char str[3];
	 //itoa(i,str,10);
	sprintf(str,"%d",i);
	 strcpy(rec[i].ind,str);
      }
      no--;
      fstream f1,f2;
      f1.open("record1.txt",ios::out);
      f2.open("index1.txt",ios::out);
      for(int i=0;i<no;i++)
      {
      strcpy(in[i].food_no,rec[i].food_no);
      strcpy(in[i].ind,rec[i].ind);
      }
      sort_index();
      for(int i=0;i<no;i++)
      {
      f1<<rec[i].ind<<"|"<<rec[i].food_no<<"|"<<rec[i].name<<"|"<<rec[i].cost<<"|"<<rec[i].items_available<<"\n";
      f2<<in[i].food_no<<"|"<<in[i].ind<<"\n";
      }
      f1.close();
      f2.close();
      cout<<"\n deletion successful\n";
}

int main()
{
      fstream file1,file2;
      int choice;
      char ind[5],st_food_no[20],name[20],cost[5],items_available[5],food_no[20];
      string username,Name,ch,iN;
      string password,cpassword,newpassword;
      int z=0,x=0,w=0;
      file2.open("index1.txt",ios::out|ios::app);
      file1.open("record1.txt",ios::out|ios::app);
      file1.close();
      file2.close();
      int i;
      
      
      
      
      
      file2.open("index1.txt",ios::in);
      while(!file2.eof())
      {
      	file2.getline(tep[z].food_no,20,'|');
      	file2.getline(tep[z].ind,5,'\n');
		  z++;
      	
	  }
      z--;
      no=z;
      cout<<no;
      file2.close();
      file2.open("index1.txt",ios::in);
      	file1.open("record1.txt",ios::in);
      if(no!=0)
      {
      while(!file2.eof())
      {
      	file2.getline(in[x].food_no,20,'|');
      	file2.getline(in[x].ind,5,'\n');
		  x++;
      	
	  }	
      	
       while(!file1.eof())
      {
      	file1.getline(rec[w].ind,5,'|');
		  file1.getline(rec[w].food_no,20,'|');
		  file1.getline(rec[w].name,20,'|');
		  file1.getline(rec[w].cost,15,'|');
		  file1.getline(rec[w].items_available,15,'\n');
		 
      	w++;
	  }	
      	
      	x--;
      	w--;
      	
      	
      	
	  }
      file1.close();
      	file2.close();

  cout<<"\n\n\n\t\t\t\t#############################################"<<endl;
	  cout<<"\n\t\t\t\t#   Welcome to Restaurant management  System   #"<<endl;
	  cout<<"\n\t\t\t\t##############################################";
	  do
	
	  {
	  
         cout<<"\n\t\t\t\t\tPlease Login to Continue\t"<<endl;	
	cout << "\n\t\t\t\t\tUser Name: ";
	cin>>username;
	if (username == "suveda") {
	cout << "\n\t\t\t\t\tPassword: ";
	cin>>password;
	cout<<"\n\n\t\t\t\t%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%"<<endl;
	cout<<endl;
	if (password != "suveda") {
		system("cls");
		
	cout << "\n\n\t\t\t\tinvalid password. try again." <<endl;
	
	}
	} else {
		system("cls");
		
	cout << "\n\n\t\t\t\tinvalid username. try again." <<endl;
	
	}
	if(password == "suveda"){
	system("cls");	
      
      
      
      
      
      
      
      
         
      for(;;)
      {
      cout<<"\n ENTER YOUR OPTION \n1:ADD NEW FOOD ITEM\n2 SEARCH FOR FOOD ITEM \n3:DELETE FOOD ITEMS \n4:MENU \n5:items_available OF FOOD ITEMS \n6:MODIFY\n7:BILLING\n8:EXIT \n";
      cin>>choice;
      switch(choice)
      {
	 case 1:{ 
		file1.open("record1.txt",ios::app|ios::out);
		if(!file1)
		{
		  cout<<"File creation error\n";
		  exit(0);
		}
		int n;
		cout<<"enter no of food items\n";
		cin>>n;
		cout<<"enter the details\n";
		
		  for(i=no;i<no+n;i++)
		  {
		  cout<<"\nenter  food item:";

		  cout<<"\nfood_no:";
		  cin>>rec[i].food_no;
		  cout<<"\nname:";
		  cin>>rec[i].name;
		  cout<<"\ncost:";
		  cin>>rec[i].cost;
		  cout<<"\nitems_available:";
		  cin>>rec[i].items_available;
		 
    	
    
		    
		file1<<i<<"|"<<rec[i].food_no<<"|"<<rec[i].name<<"|"<<rec[i].cost<<"|"<<rec[i].items_available<<"\n";
	   }
	       file1.close();
	       no=no+n;
	       
	       file2.open("index1.txt",ios::out);
	       file1.open("record1.txt",ios::in);
	       for(i=0;i<no;i++)
	       {
		  file1.getline(ind,5,'|');
		  file1.getline(food_no,20,'|');
		  file1.getline(name,20,'|');
		  file1.getline(cost,15,'|');
		  file1.getline(items_available,15,'\n');
		  
		  
		  strcpy(rec[i].ind,ind);
		  strcpy(in[i].food_no,food_no);
		  strcpy(in[i].ind,ind);
	       }
	       sort_index();
	       
	       
	       
	       cout<<"\nafter sorting index file contents are\n";
	       for(i=0;i<no;i++)
	       cout<<in[i].food_no<<"|"<<in[i].ind<<"\n";
	       for(i=0;i<no;i++)
	       {
		   file2<<in[i].food_no<<"|"<<in[i].ind<<"\n";
	       }
	       
	       file1.close();
	       file2.close();
	       break;
		}
	 case 2:{
		cout<<"\nEnter food_no of food item whose result is to be displayed\n";
		cin>>st_food_no;
		int q=search_index(st_food_no);
		if(q==1)
		   cout<<"\nSearch successful, Results found\n";
		else
		   cout<<"\nSearch not successful, Results not found\n";
		break;
		}
	 case 3:{
		cout<<"Enter food_no of food item whose record is to be deleted\n";
		cin>>st_food_no;
		delet(st_food_no);
		break;
		}
	 case 4:{
	 	 
		  cout<<"*******************MENU************************\n";
	      fstream f1;
	      f1.open("record1.txt",ios::in);
	      if(!f1)
	      {system("COLOR 5");
	      	
	      cout<<"err\\\\\\\\\\\\\\\\n";
	      exit(0);
	      }
	      
	      int i=0;
	      cout<<"food_no:"<<"\t"<<"name:"<<"\t\t\t"<<"cost:"<<"\t\t"<<endl;
	      while(i!=no)

	       {
		  f1.getline(ind,5,'|');
		  f1.getline(food_no,20,'|');
		  f1.getline(name,20,'|');
		  f1.getline(cost,15,'|');
		  f1.getline(items_available,15,'\n');
		  
		  cout<<food_no<<"\t\t"<<name<<"\t\t\t"<<cost<<"\t\t"<<endl;
		  i++;
	       }
		  break;
		}
	case 5:{
		
		cout<<"enter food item food_no whose items_available is to be displayed \n";
		cin>>st_food_no;
		items_available1(st_food_no);
		break;
	}	
	
		case 6:{
			char a[20];
		 cout<<"\enter the food_no to be modified: ";
		cin>>a;
		modi(a);
		break;
		 
		}
		case 7:{
		 //cout<<"enter food item food_no \n";
		//cin>>st_food_no;
		//bill(st_food_no);
		cbill();
		break;
		}
		case 8:{
		 cout<<"\nending program";
		
		 exit(0);
		}
	 default:
		 cout<<"\nInvalid\n";
		 break;
	 }
     }
}
}while(password!="suveda");
return 0;
}

