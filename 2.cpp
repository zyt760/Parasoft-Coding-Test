#include <iostream>
#include <vector>
#include <algorithm>
int N=(1+9)*9/2/3;
int coun=0;
using namespace std;
int main(){
	int a,b,c,d,e,f,g,h,i;
	vector<vector<int>> poss;
	vector<vector<vector<int>>> sol;
	for(int i=1;i<=9;i++){
		for(int j=1;j<=9;j++){
			if((i!=j)&&((N-i-j)!=i)&&((N-i-j)!=j)&&(N-i-j)>=1&&(N-i-j)<=9){
				poss.push_back({i,j,N-i-j});
			}
		}
	}
	for(int i=0;i<poss.size();i++){
		for(int j=0;j<poss.size();j++){
			vector<int>::iterator it;
			vector<int> v(10);
			vector<int> sortedi=poss[i];
			vector<int> sortedj=poss[j];
			sort (sortedi.begin(), sortedi.end());
			sort (sortedj.begin(), sortedj.end());
			it=set_intersection(sortedi.begin(),sortedi.end(),sortedj.begin(),sortedj.end(),v.begin());
			v.resize(it-v.begin());
			if(!v.empty())
			continue;
			for(int k=0;k<poss.size();k++){
				vector<int>::iterator it1,it2;
				vector<int> v1(10),v2(10);
				vector<int> sortedk=poss[k];
				sort (sortedk.begin(), sortedk.end());
				it1=set_intersection(sortedi.begin(),sortedi.end(),sortedk.begin(),sortedk.end(),v1.begin());
				it2=set_intersection(sortedj.begin(),sortedj.end(),sortedk.begin(),sortedk.end(),v2.begin());
				v1.resize(it1-v1.begin());
				v2.resize(it2-v2.begin());
				if(!v1.empty())
				continue;
				if(!v2.empty())
				continue;
				if((poss[i][0]+poss[j][0]+poss[k][0])!=N)
				continue;
				if((poss[i][1]+poss[j][1]+poss[k][1])!=N)
				continue;
				if((poss[i][2]+poss[j][2]+poss[k][2])!=N)
				continue;
				sol.push_back({poss[i],poss[j],poss[k]});
				coun++;
			}
		}
	}
	for(int i=0;i<sol.size();i++){
		for(int j=0;j<sol[i].size();j++){
			for(int k=0;k<sol[i][j].size();k++){
				cout<<sol[i][j][k];
			}
			cout<<endl;
		}
		cout<<endl;
	}
	cout<<"这样的常量有"<<N<<endl;
	cout<<"对应的填数法有"<<coun<<"种"<<endl;
	return 0;
}