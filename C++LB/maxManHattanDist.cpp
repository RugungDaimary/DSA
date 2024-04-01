#include<bits/stdc++.h>
using namespace std;
//maximum Manhattan Distance between two pair points and give that pair points whcih give maximum dist
int maxManhattanDist(vector<pair<int,int>>&distance){
    int n=distance.size();
    int maxSum=INT_MIN;
    int minSum=INT_MAX;
    int maxDiff=INT_MIN;
    int minDiff=INT_MAX;
    pair<int,int>maxSumPoints;
    pair<int,int>minSumPoints;
    pair<int,int>maxDiffPoints;
    pair<int,int>minDiffPoints;
    for(int i=0;i<n;i++){
        int sum=distance[i].first+distance[i].second;
        int diff=distance[i].first - distance[i].second;
        if(sum>maxSum){
            maxSum=sum;
            maxSumPoints={distance[i].first,distance[i].second};

        }
        if(sum<minSum){
            minSum=sum;
            minSumPoints = {distance[i].first, distance[i].second};
        }
        if(diff>maxDiff){
            maxDiff=diff;
            maxDiffPoints = {distance[i].first, distance[i].second};
        }
        if(diff<minDiff){
            minDiff=diff;
            minDiffPoints = {distance[i].first, distance[i].second};
        }
    }
    int result1=maxSum-minSum;
    int result2=maxDiff-minDiff;
    cout<<"Points are ";
    if(result1>result2){
        cout<<"("<<maxSumPoints.first<<","<<maxSumPoints.second<<")";
        cout<< "(" << minSumPoints.first << "," << minSumPoints.second << ")"<<endl ;
    }else{
        cout<< "(" << maxDiffPoints.first << "," << maxDiffPoints.second << ")" ;
        cout<< "(" << minDiffPoints.first << "," << minDiffPoints.second << ")" << endl;
    }
    return max(result1,result2);

}

int main(){
    vector<pair<int, int>> v{{-1, 2}, {-4, 6}, {3, -4}, {-2, -4}};
   int result=maxManhattanDist(v);
    cout<<"Maximum Manhattan Distance is "<<result<<endl;
    
    return 0;
}