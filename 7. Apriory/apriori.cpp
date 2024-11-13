#include<bits/stdc++.h>
using namespace std;

int getSupport(vector<set<string>>& data,set<string>& item){
    int c = 0;
    for(set<string> st:data){
        if(includes(st.begin(),st.end(),item.begin(),item.end())){
            c++;
        }
    }
    return c;
}

set<set<string>> getKthItemset(vector<set<string>>& freq,int k){
    set<set<string>> itemset;
    for (int i = 0; i < freq.size();i++){
        for (int j = i + 1; j < freq.size();j++){
            set<string> temp(freq[i]);
            temp.insert(freq[j].begin(), freq[j].end());
            if(temp.size()==k){
                itemset.insert(temp);
            }
        }
    }
    return itemset;
}

void apriory(vector<set<string>>& data,double minSupcnt){
    set<set<string>> itemset;
    for(set<string> st:data){
        for(string s:st){
            itemset.insert({s});
        }
    }
    cout << itemset.size() << endl;
    vector<set<string>> frequentItemset;
    cout << "1-frequent itemset: " << endl;
    for(set<string> st:itemset){
        int sup_cnt = getSupport(data, st);
        if(sup_cnt>=minSupcnt){
            frequentItemset.push_back(st);
            cout << "[";
            for(string s:st){
                cout << s << ",";
            }
            cout << "] : " << sup_cnt << endl;
        }
    }
    cout << endl;
    int k = 2;
    while(!itemset.empty()){
        itemset.clear();
        itemset = getKthItemset(frequentItemset, k);
        frequentItemset.clear();
        if(itemset.empty())break;
        cout << k<<"-frequent itemset: " << endl;
        for(set<string> st:itemset){
            int sup_cnt = getSupport(data, st);
            if(sup_cnt>=minSupcnt){
                frequentItemset.push_back(st);
                cout << "[";
                for(string s:st){
                    cout << s << ",";
                }
                cout << "] : " << sup_cnt << endl;
            }
        }
        k++;
        cout << endl;
    }
}

int main(){
    ifstream in("input.csv");
    string str;
    vector<set<string>> data;
    int size = 0;
    while(getline(in,str)){
        size++;
        stringstream ss(str);
        set<string> st;
        string tmp;
        while(getline(ss,tmp,',')){
            st.insert(tmp);
        }
        data.push_back(st);
    }
    double min_sup;
    cout << "\nEnter min support: " << endl;
    cin >> min_sup;
    double minSupcnt = (min_sup * size) / 100;
    cout << "Minimum Support count: " << minSupcnt << endl;
    apriory(data, minSupcnt);
    return 0;
}