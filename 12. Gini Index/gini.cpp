#include<bits/stdc++.h>
using namespace std;

class DataSet{
    public:
        unordered_map<string, string> mp;
        DataSet() {};
};

double findGini(vector<DataSet>& data,string attr){
    unordered_map<string,int> freq;
    for(DataSet d:data){
        for(auto i:d.mp){
            if(i.first==attr){
                freq[i.second]++;
            }
        }
    }
    int n = data.size();
    double ans = 0.0;
    for(auto i:freq){
        double pi = (double)i.second / n;
        ans += pow(pi, 2);
    }
    return 1 - ans;
}

double findGiniIndex(vector<DataSet>& data,string attr,string target){
    double target_gini = findGini(data, target);
    cout << "Target Gini: " << target_gini<<endl;
    unordered_map<string,int> freq;
    for(DataSet d:data){
        for(auto i:d.mp){
            if(i.first==attr){
                freq[i.second]++;
            }
        }
    }
    int n = data.size();
    double ans = 0.0;
    for(auto i:freq){
        double pi = (double)i.second / n;
        vector<DataSet> temp;
        for(DataSet d:data){
            if(d.mp[attr]==i.first){
                temp.push_back(d);
            }
        }
        ans += (pi * findGini(temp, target));
    }
    return ans;
}

int main(){
    ifstream in("input.csv");
    string line;
    getline(in, line);
    vector<string> header;
    stringstream ss(line);
    string temp;
    while(getline(ss,temp,',')){
        header.push_back(temp);
    }
    vector<DataSet> data;
    while(getline(in,line)){
        DataSet d;
        stringstream ss1(line);
        string temp;
        vector<string> v;
        while(getline(ss1,temp,',')){
            v.push_back(temp);
        }
        for (int i = 0; i < header.size();i++){
            d.mp[header[i]] = v[i];
        }
        data.push_back(d);
    }
    string target=header.back();
    cout << target << endl;
    header.pop_back();
    for(string attr:header){
        cout <<"\nGini Index of " << attr << " :"<<endl;
        double gini = findGiniIndex(data,attr,target);
        cout<<"Gini Index(S,"<<attr<<") = "<<gini<<endl;
    }
    return 0;
}