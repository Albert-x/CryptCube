#include <iostream>
#include <fstream>
#include <cstring>
#include <cmath>
#include "SelectTerm.h"
using namespace std;
class DICTIONARY
{private:
  char *eng_path,*chi_path;
  char *index_path;
  int index[53];
  int last_of_chi;//用于存放chinese.txt中最后一个单词的位置
  
  
public:
  ifstream eng_file,chi_file,index_file;
  int cur_position;
  int chi_leng,eng_leng;
  int flag;//0 表示前一次查的是英文，1 表示前一次查的是中文
public:
	DICTIONARY()
	{eng_path="english.txt";
	 chi_path="chinese.txt";
	 index_path="index.txt";
	 eng_file.open(eng_path,ios::in);
     chi_file.open(chi_path,ios::in);
     index_file.open(index_path,ios::in);
	 cur_position=0;
	 flag=0;
     for (int i=0;i<53;i++)
	    index_file>>index[i];
     index_file>>eng_leng>>chi_leng>>last_of_chi;
	}


 

		      


  int eng_to_chi(char *english,int time)//time表示是否为递归调用   ////这里修改了
  {eng_file.clear();
   char dic_eng[150];
   int head,tail,temp_pos=-1;
   if (english[0]>=97 && english[0]<=122)
      {head=index[english[0]-'a'+26];
       tail=index[english[0]-'a'+27];
      }
      else if(english[0]>=65 && english[0]<=90)
	  {head=index[english[0]-'A'];
	   tail=index[english[0]-'A'+1];
	  }
	  
   int mid=(head+tail)/2;

	  while (mid % eng_leng!=0)
		  --mid;
   eng_file.seekg(mid);
   int num_of_head_equal_tail=0;
   int english_leng=strlen(english);
	  while (num_of_head_equal_tail <=2)
	  {eng_file.getline(dic_eng,150,'|');
	   if(strncmp(dic_eng,english,english_leng)==0)
             temp_pos=int(eng_file.tellg())-strlen(dic_eng)-2;
	      if(strcmp(dic_eng,english)==0)
		  {cur_position=int(eng_file.tellg())-strlen(dic_eng)-2;
		    return cur_position;
	      }
          else if (strcmp(dic_eng,english)>0)
		  {tail=mid;
		   mid=(head+tail)/2;
		      while(mid % eng_leng !=0)
				  --mid;
		   eng_file.seekg(mid);
		  }
		  else
          {head=mid;
		   mid=(head+tail)/2;
		      while(mid % eng_leng !=0)
				  ++mid;
		   eng_file.seekg(mid);
		  }
       if (tail-head==eng_leng)
		 ++num_of_head_equal_tail;
	  }
     char temp_english[100];
	 strcpy(temp_english,english);
     int position=cur_position;  
	 if (time==1)
     {   
		if (english[0]>=65 && english[0]<=90)
		    temp_english[0]=char(temp_english[0]+32);
		else 
		    temp_english[0]=char(temp_english[0]-32);
	 eng_to_chi(temp_english,2);
	 }
	 else 
		 return cur_position;
     
	 if (cur_position==position && temp_pos!=-1)
	    cur_position=temp_pos;
	 
  return cur_position;
  }
	
 

int chi_to_eng(char *chinese)
  {char dic_chi[200];
   int head=0,tail=last_of_chi;
   int mid=(head+tail)/2;
   
	  while (mid % chi_leng!=0)
		  --mid;
	 
   chi_file.seekg(mid);
   bool found=false;
   int num_of_head_equal_tail=0;
   int chinese_leng=strlen(chinese);
   int temp_pos=-1;//比如查找单词为boy，而找到的为boyer，
               //则先把boyer这个单词的位置存起来，如果没有boy这个单词，则回到boyer把这个单词输出
	  while (found==false && num_of_head_equal_tail <=2)
	  {chi_file.getline(dic_chi,200,'|');
	  //cout<<dic_chi<<endl;
	      if(strncmp(dic_chi,chinese,chinese_leng)==0)
             temp_pos=int(chi_file.tellg())-strlen(dic_chi)-2;
	      if(strcmp(dic_chi,chinese)==0)
		  {cur_position=int(chi_file.tellg())-strlen(dic_chi)-2;
		   return cur_position;
		  }
          else if (strcmp(dic_chi,chinese)>0)
		  {tail=mid;
		   mid=(head+tail)/2;
		      while(mid % chi_leng !=0)
				  --mid;
		   chi_file.seekg(mid);
		  }
		  else
          {head=mid;
		   mid=(head+tail)/2;
		      while(mid % chi_leng !=0)
				  ++mid;
		   chi_file.seekg(mid);
		  }
          if (tail-head==chi_leng)
		    ++num_of_head_equal_tail;
	  }
	  if (found==false && temp_pos !=-1)
	     cur_position=temp_pos;
	  

	  return cur_position;
  }

bool modify(char *english,char *chinese)
{fstream out_eng_file(eng_path,ios::in|ios::out);
  ofstream out_chi_file(chi_path,ios::app);
  char dic_eng[150];
   int head,tail;
	  if (english[0]>=97 && english[0]<=122)
      {head=index[english[0]-'a'+26];
       tail=index[english[0]-'a'+27];
      }
      else if(english[0]>=65 && english[0]<=90)
	  {head=index[english[0]-'A'];
	   tail=index[english[0]-'A'+1];
	  }
	int mid=(head+tail)/2;
       while (mid % eng_leng!=0)
		  --mid;
   eng_file.seekg(mid);
   int num_of_head_equal_tail=0;
	 while (num_of_head_equal_tail <=2)
	  {eng_file.getline(dic_eng,150,'|');
	      if(strcmp(dic_eng,english)==0)
		  {char temp_chinese[400];
		   eng_file.getline(temp_chinese,400,'|');
		   out_eng_file.seekp(int(eng_file.tellg())-1);
		   out_eng_file<<';';
		   out_eng_file<<chinese<<"(only for you)";
		   out_eng_file<<'|';
		   return true;
		  }
          else if (strcmp(dic_eng,english)>0)
		  {tail=mid;
		   mid=(head+tail)/2;
		      while(mid % eng_leng !=0)
				  --mid;
		   eng_file.seekg(mid);
		  }
		  else
          {head=mid;
		   mid=(head+tail)/2;
		      while(mid % eng_leng !=0)
				  ++mid;
		   eng_file.seekg(mid);
		  }

        if (tail-head==eng_leng)
		    ++num_of_head_equal_tail;
	  }
      return false;
}



    

   ~DICTIONARY(){eng_file.close();chi_file.close();index_file.close();}
};

 
		 
		    


		   


	 


 
  