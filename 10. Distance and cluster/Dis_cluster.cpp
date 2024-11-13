#include<bits/stdc++.h>
using namespace std;
vector<double> findCentroid(vector<double> x,vector<double> y){
    return {accumulate(x.begin(), x.end(), 0.0) / (double)x.size(), accumulate(y.begin(), y.end(), 0.0) / (double)y.size()};
}
double distance(double x1,double y1,double x2,double y2){
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}
int main(){
    ifstream in("input.csv");
    string str;
    vector<double> x, y;
    while(getline(in,str)){
        stringstream ss(str);
        string tmp;
        getline(ss, tmp, ',');
        x.push_back(stod(tmp));
        getline(ss, tmp, ',');
        y.push_back(stod(tmp));
    }
    vector<double> c = findCentroid(x, y);
    cout <<"Centroids: {"<< c[0] << "," << c[1]<<"}"<< endl;
    int n = x.size();
    vector<vector<double>> v(n, vector<double>(n, 0.0));
    for (int i = 0; i < n;i++){
        for (int j = 0; j < i;j++){
            v[i][j] = distance(x[i], y[i], x[j], y[j]);
        }
        v[i][i] = 0.0;
    }
    for (int i = 0; i < n;i++){
        for (int j = 0; j <=i;j++){
            cout << fixed << setprecision(2) << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Distance of all points from centeroid [" << c[0] << "," << c[1] << "] : " << endl;
    vector<double> newc(2, 1e9 + 7);
    double d = 1e9;
    for (int i = 0; i < n;i++){
        double tmp = distance(c[0], x[i], c[1], y[i]);
        cout << "d[(" << x[i] << "," << y[i] << "),(" << c[0] << "," << c[1] << ")]= " << tmp << endl;
        if(tmp<d){
            d = tmp;
            newc[0] = x[i];
            newc[1] = y[i];
        }
    }
    cout << "Distance of all points from new centeroid [" << newc[0] << "," << newc[1] << "] : " << endl;
    for (int i = 0; i < n;i++){
        double tmp = distance(newc[0], x[i], newc[1], y[i]);
        cout << "d[(" << x[i] << "," << y[i] << "),(" << newc[0] << "," << newc[1] << ")]= " << tmp << endl;
    }
    return 0;
}