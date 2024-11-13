#include<bits/stdc++.h>
using namespace std;

class DataSet{
    public:
        unordered_map<string, string> mp;
        DataSet() {};
};
double entropy(vector<DataSet>& data,string target){
    unordered_map<string,int> freq;
    for(DataSet d:data){
        freq[d.mp[target]]++;
    }
    int n = data.size();
    double entropy;
    for(auto i:freq){
        double pi =(double) i.second / n;
        entropy -= (pi * log2(pi));
    }
    return entropy;
}
double info_gain(vector<DataSet>& data,string attr,string target){
    double target_entropy=entropy(data,target);
    cout << "Target Entropy: " << target_entropy<<endl;
    unordered_map<string, int> freq;
    for(DataSet d:data){
        freq[d.mp[attr]]++;
    }
    int n = data.size();
    double attr_entropy=0.0;
    for(auto i:freq){
        double pi = (double)i.second / n;
        vector<DataSet> subset;
        for(DataSet d:data){
            if(d.mp[attr]==i.first){
                subset.push_back(d);
            }
        }
        attr_entropy += (pi * entropy(subset, target));
    }
    cout << "Attribute Entropy of "<<attr<<"= "<< attr_entropy << endl;
    return target_entropy-attr_entropy;
}
int main(){
    ifstream in("input.csv");
    string str,temp;
    getline(in, str);
    vector<string> header;
    for(char c:str){
        if(c==','){
            header.push_back(temp);
            temp="";
            continue;
        }
        temp.push_back(c);
    }
    header.push_back(temp);
    vector<DataSet> data;
    while(getline(in,str)){
        DataSet d;
        temp = "";
        int i = 0;
        for(char c:str){
            if(c==','){
                d.mp[header[i]] = temp;
                i++;
                temp="";
                continue;
            }
            temp.push_back(c);
        }
        d.mp[header[i]] = temp;
        data.push_back(d);
    }
    string target=header.back();
    header.pop_back();
    for(string attr:header){
        cout <<"\nInfo gain of " << attr << " :"<<endl;
        double gain = info_gain(data,attr,target);
        cout<<"Gain(S,"<<attr<<") = "<<gain<<endl;
    }
    return 0;
}