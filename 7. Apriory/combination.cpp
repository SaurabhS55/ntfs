#include<bits/stdc++.h>
using namespace std;
ofstream out("output.csv");
void combinations(vector<string> v,int mask){
    for (int i = 0; i < v.size();i++){
        if(mask & (1<<i)){
            out << v[i] << " ";
        }
    }
    out << endl;
}
int main(){
    ifstream in("input.csv");
    set<string> st;
    string str;
    while(getline(in,str)){
        stringstream ss(str);
        string tmp;
        while(getline(ss,tmp,',')){
            st.insert(tmp);
        }
    }
    vector<string> v(st.begin(),st.end());
    int n=v.size();
    long long int c = (1 << n) ;
    for (int i = 1; i <=c;i++){
        combinations(v, i);
    }
    return 0;
}