#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <ctime>
using namespace std;
class change
{
	public:
		string revision;
		string author;
		string comment;
		long time;
};
vector<change> read(string filename){
	vector<change> data;
	ifstream afile;
	afile.open(filename);
	string str; 
	getline(afile,str);
	while(!afile.eof())
	{ 
		getline(afile,str);
		string revision=str.substr(str.find("（")+2,str.find("）")-str.find("（")-2);
		string author=str.substr(str.find("$ ")+2,str.find(" \"")-str.find("$ ")-2);
		string comment=str.substr(str.find("\"")+1,str.find_last_of("\"")-str.find("\"")-1);
		string str1=str.substr(str.find("\" ")+2);
		int day=stoi(str1.substr(0,str1.find("-")));
		string month=str1.substr(str1.find("-")+1,str1.find_last_of("-")-str1.find("-")-1);
		int year=stoi(str1.substr(str1.find_last_of("-")+1,str1.find(" ")-str1.find_last_of("-")-1));
		int hour=stoi(str1.substr(str1.find(" ")+1,str1.find(":")-str1.find(" ")-1));
		int min=stoi(str1.substr(str1.find(":")+1,str1.find_last_of(" ")-str1.find(":")-1));
		string p=str1.substr(str1.find_last_of(" ")+1);
		change temp;
		temp.revision=revision;
		temp.author=author;
		temp.comment=comment;
		struct tm time;
		time.tm_min=min;
		if(p=="下午"){
			time.tm_hour=hour+12;
		}
		else{
			time.tm_hour=hour;
		}
		time.tm_mday=day;
		if(month=="一月") 
			time.tm_mon=0;
		if(month=="二月") 
			time.tm_mon=1;
		if(month=="三月")
			time.tm_mon=2;
		if(month=="四月")
			time.tm_mon=3;
		if(month=="五月")
			time.tm_mon=4;
		if(month=="六月")
			time.tm_mon=5;
		if(month=="七月")
			time.tm_mon=6;
		if(month=="八月")
			time.tm_mon=7;
		if(month=="九月")
			time.tm_mon=8;
		if(month=="十月")
			time.tm_mon=9;
		if(month=="十一月")
			time.tm_mon=10;
		if(month=="十二月")
			time.tm_mon=11;
		time.tm_year=year-1900;
		temp.time=mktime(&time);
		data.push_back(temp);
	}
	afile.close();
	return data;
};
int main()
{
	vector<change> data=read("1.txt");
	for(int i=0;i<data.size();i++){
		time_t rawtime=data[i].time;
		struct tm* timeinfo;
		char buffer[80];
		cout<<data[i].revision<<"\t"<<data[i].author<<"\t"<<data[i].comment<<"\t";
		timeinfo = localtime (&rawtime);
		strftime(buffer,80,"%c",timeinfo);
		puts (buffer);
	}
	return 0;
}