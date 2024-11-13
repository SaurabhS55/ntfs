#include<bits/stdc++.h>
using namespace std;
double twt(double val1,double val2){
    return (val1 / (val1 + val2))*100;
}
double dwt(double total,double val){
    return (val / total) * 100;
}
int main(){
    ifstream in("input.csv");
    ofstream out("output.csv");
    string str,region;
    getline(in, str);
    vector<double> class1, class2;
    vector<string> regions;
    double val1, val2;
    while(getline(in,str)){
        stringstream ss(str);
        getline(ss, region, ',');
        ss >> val1;
        ss.ignore(1);
        ss >> val2;
        class1.push_back(val1);
        class2.push_back(val2);
        regions.push_back(region);
    }
    int n = regions.size();
    vector<double> class1_twt, class1_dwt, class2_twt, class2_dwt;
    // twt
    for (int i = 0; i < n;i++){
        class1_twt.push_back(twt(class1[i], class2[i]));
        class2_twt.push_back(twt(class2[i], class1[i]));
    }
    // dwt
    double s1 = accumulate(class1.begin(), class1.end(), 0.0);
    double s2 = accumulate(class2.begin(), class2.end(), 0.0);
    for (int i = 0; i < n;i++){
        class1_dwt.push_back(dwt(s1, class1[i]));
        class2_dwt.push_back(dwt(s2, class2[i]));
    }
    cout << "Regions\t|\tcnt_a\ttwt_a\tdwt_a\t|\tcnt_b\ttwt_b\tdwt_b" << endl;
    out << "Regions,cnt_a,twt_a,dwt_a,cnt_b,twt_b,dwt_b" << endl;
    for (int i = 0; i < n;i++){
        cout << regions[i]<<"\t|\t"<<class1[i]<<"\t"<<class1_twt[i]<<"\t"<<class1_dwt[i]<<"\t|\t"<<class2[i]<<"\t"<<class2_twt[i]<<"\t"<<class2_dwt[i] << endl;
        out << regions[i]<<","<<class1[i]<<","<<class1_twt[i]<<","<<class1_dwt[i]<<","<<class2[i]<<","<<class2_twt[i]<<","<<class2_dwt[i] << endl;
    }
    return 0;
}