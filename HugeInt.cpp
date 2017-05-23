#include"HugeInt.h"
#include<iostream>
#include<sstream> 
#include<string>
using namespace std;
HugeInt::HugeInt(){};
HugeInt::HugeInt(long long a){
	
stringstream convert;
convert << a;
string ss;
convert >> ss;
int i=0;
for( i=-1+ss.length();i>=0;i--) array[i]=ss.at(i)-'0';



};

// 將string Z轉成 integer 
HugeInt::HugeInt(string b){
	int i;
	for(i=0;i<b.length();i++)
	{
	  array[i]=b.substr(b.length()-i-1,1);
	}	
}

//輸入x 然後轉成矩陣 
istream	&operator >> (istream &in, HugeInt &CIN ){
	string s;
	in >> s;
	for(int i=0;i<s.length();i++) CIN.array[i]=s.at(i)-'0';
	
}

//定義+的OPERATOR 
HugeInt HugeInt::operator+(HugeInt n)
{
	HugeInt Q;
	for(int i=0;i<50;i++)
	{
		Q.array[i]=array[i]+n.array[i];
		if(array[i]+n.array[i]>=10)
		{
			Q.array[i]=Q.array[i]-10;
			n.array[i+1]++;
		}
	}
	return Q;	
}

//定義=的operator 
HugeInt HugeInt::operator=(HugeInt r)
{
	for(int i=0;i<50;i++)
   {
	  	array[i]=r.array[i];
   }
}


//-
HugeInt HugeInt::operator-(HugeInt nn)
{
    int A=0,B=0,i=0;
    HugeInt W;
	for(i=49;i>0;i--)
	{
	  if(array[i]!=0&&nn.array[i]==0)
	  { ++A;
	  	break;
	  }
    }
    if(A==1)
    {
    	for(int i=0;i<50;i++)
    	{ 
    	  if(array[i]<nn.array[i])
    	  {
    	  	array[i]=array[i]+10;
    	  	array[i+1]--;
    	  	array[i]-nn.array[i];
		  }
		  else
		  {
		  	 W.array[i]=array[i]-nn.array[i];
		  }
    	 
    	  
		}
	}
    for(i=49;i>0;i--)
	{
	  if(array[i]==0&&nn.array[i]!=0)
	  { ++B;
	  	break;
	  }
    }
     if(B==1)
    {
    	for(int i=0;i<50;i++)
    	{
    		if(nn.array[i]<array[i])
    		{
    			nn.array[i]=nn.array[i]+10;
    			nn.array[i+1]--;
    			W.array[i]=nn.array[i]-array[i];
			}
			else
			{
			  W.array[i]=nn.array[i]-array[i];	
			}
    	  
		}
	}
}

//define cout operator 
ostream	&operator >> (ostream &out, HugeInt &COUT ){
	int i;
	for(i=0;i<50;i++)
	out << 	COUT.array[i];

	return out;
}
	
