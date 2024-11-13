#include<bits/stdc++.h>
using namespace std;

pair<double, double> findRegression(vector<double>& x, vector<double>& y) {
    int n = x.size();

    double mean_x = (double)accumulate(x.begin(), x.end(), 0.0) / n;
    double mean_y = (double)accumulate(y.begin(), y.end(), 0.0) / n;

    double temp1 = 0, temp2 = 0;
    for (int i = 0; i < n; i++) {
        temp1 += (x[i] - mean_x) * (y[i] - mean_y);
        temp2 += (x[i] - mean_x) * (x[i] - mean_x);
    }

    double m = temp1 / temp2;
    double c = mean_y - m * mean_x;

    return {m, c};
}

int main() {
    ifstream in("input.csv");
    vector<double> x, y;
    string str;
    getline(in, str);
    while(getline(in,str)){
        stringstream ss(str);
        string temp;
        getline(ss, temp, ',');
        x.push_back(stod(temp));
        getline(ss,temp,',');
        y.push_back(stod(temp));
    }
    auto [m, c] = findRegression(x, y);

    cout << "\nslope(m)= " << m << endl;
    cout << "Itercept(c)= " << c << endl;
    double val;
    cout << "Enter value (x): " << endl;
    cin >> val;
    cout << "For Value(x)" << val << " Prediction(y)= " << (m * val + c) << endl;
    return 0;
}