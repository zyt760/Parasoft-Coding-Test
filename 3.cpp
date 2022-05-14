#include <iostream>
#include <vector>
#include <shlwapi.h>
using namespace std;
int dirnum=0,filenum=0,cnum=0,hnum=0;
void getAllFiles(string path, vector<string>& files)
{
	long hFile = 0;
	struct _finddata_t fileinfo;
	string p;
	if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1)
	{
		do
		{
			if ((fileinfo.attrib &  _A_SUBDIR))
			{
				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
				{
					files.push_back(p.assign(path).append("/").append(fileinfo.name));
					dirnum++;
					getAllFiles(p.assign(path).append("/").append(fileinfo.name), files);
				}
			}
			else
			{
				files.push_back(p.assign(path).append("/").append(fileinfo.name));
				string cata=fileinfo.name;
				if(cata.substr(cata.find_last_of('.')+1)=="c")
				cnum++;
				if(cata.substr(cata.find_last_of('.')+1)=="h")
				hnum++;
				filenum++;
			}
		} while (_findnext(hFile, &fileinfo) == 0); 
		_findclose(hFile);
	}
}
int main()
{
  string DATA_DIR = "D:/Example";
  vector<string> files;
  getAllFiles(DATA_DIR, files);
  int size = files.size();
  for (int i = 0; i<size; i++)
  {
      cout << files[i] << endl;
  }
  cout<<"Example������Ŀ¼��������Example��������Ϊ"<<dirnum<<endl;
  cout<<"Example�������ļ�����Ϊ"<<filenum<<endl;
  cout<<"����Դ�ļ�(.c��׺�ļ�)����Ϊ"<<cnum<<endl;
  cout<<"����ͷ�ļ�(.h��׺�ļ�)����Ϊ"<<hnum<<endl;
  return 0;
}