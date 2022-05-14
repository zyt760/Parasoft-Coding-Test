#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int first = 0; first < n; ++first) {
            if (first > 0 && nums[first] == nums[first - 1]) {
                continue;
            }
            int third = n - 1;
            int target = -nums[first];
            for (int second = first + 1; second < n; ++second) {
                if (second > first + 1 && nums[second] == nums[second - 1]) {
                    continue;
                }
                while (second < third && nums[second] + nums[third] > target) {
                    --third;
                }
                if (second == third) {
                    break;
                }
                if (nums[second] + nums[third] == target) {
                    ans.push_back({nums[first], nums[second], nums[third]});
                }
            }
        }
        return ans;
    };
int main()
{
	int x;
	vector<int> nums;
	cout<<"nums = [";
	while(cin>>x){
		nums.push_back(x);
		cin.get();
	}
	vector<vector<int>> ans;
	ans=threeSum(nums);
	cout<<"[";
	for( unsigned int i = 0; i < ans.size(); i++)
    {
    	cout<<"[";
        for( unsigned int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] ;
            if(j<ans[i].size()-1)
            cout<<"," ;
        }
        cout << "]";
        if(i<ans.size()-1)
    	cout<<","; 
    }
    cout<<"]";
	return 0;
}