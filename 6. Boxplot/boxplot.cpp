#include<bits/stdc++.h>
using namespace std;

void boxplot(vector<double> v,int n){
    int m = (0 + n-1) / 2;
    int m1 = (0 + (m - 1)) / 2;
    int m2 = ((m + 1) + (n - 1)) / 2;
    double q2 = (n%2)?v[m]:(v[m]+v[m+1])/2;
    double q1 = v[m1];
    double q3 = v[m2];
    double iqr=q3-q1;
    double lower_limit = q1 - (1.5 * iqr);
    double upper_limit = q3 + (1.5 * iqr);
    vector<double> outliers;
    for(double i:v){
        if(i<lower_limit || i>upper_limit){
            outliers.push_back(i);
        }
    }
    cout << "Boxplot: " << endl;
    cout << "data: ";
    for(double i:v)
        cout << i << " ";
    cout << endl;
    cout << "Q2: " << q2<<endl;
    cout << "Q1: " << q1 << endl;
    cout << "Q3: " << q3<<endl;
    cout << "IQR: " << iqr << endl;
    cout << "Lower limit: " << lower_limit << endl;
    cout << "Upper limit: " << upper_limit << endl;
    cout << "Outliers: [";
    for(double i:outliers){
        cout << i << ", ";
    }
    cout << "]" << endl;
}
int main(){
    ifstream in("input.csv");
    double temp;
    vector<double> v;
    in >> temp;
    while(in){
        v.push_back(temp);
        in >> temp;
    }
    sort(v.begin(), v.end());
    boxplot(v, v.size());
    return 0;
}