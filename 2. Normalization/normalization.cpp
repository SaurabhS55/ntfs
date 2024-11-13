#include<bits/stdc++.h>
using namespace std;

vector<double> min_max(vector<double> data,int n){
    double new_min, new_max;
    cout << "\n Enter new min and new max: ";
    cin >> new_min >> new_max;
    double old_min = *min_element(data.begin(), data.end());
    double old_max = *max_element(data.begin(), data.end());
    vector<double> ans;
    for (int i = 0;i<n;i++){
        double temp = (((data[i] - old_min) / (old_max - old_min)) * (new_max-new_min))+new_min;
        ans.push_back(temp);
    }
    return ans;
}

vector<double> z_score(vector<double> data,int n){
    double mean,sum=accumulate(data.begin(),data.end(),0.0);
    mean = sum / n;
    double sd = 0;
    for(double i:data){
        sd += (pow(i - mean, 2)) / (n-1);
    }
    sd = sqrt(sd);
    vector<double> ans;
    for (double i:data){
        double temp = (i - mean) / sd;
        ans.push_back(temp);
    }
    return ans;
}

int main(){
    ifstream in("input.csv");
    ofstream out("output.csv");
    string temp;
    int f = 0;
    in >> temp;
    vector<double> v;
    while(in){
        if(f==0){
            f = 1;
        }
        else{
            v.push_back(stod(temp));
        }
        in >> temp;
    }
    vector<double> ans;
    int ch;
    cout << "Normalization: " << endl;
    cout << "1. Min max" << endl;
    cout<<"2. Z-score"<<endl;
    cout << "Enter you choice: " << endl;
    cin >> ch;
    if(ch==1){
        ans = min_max(v, v.size());
    }
    else if(ch==2){
        ans = z_score(v, v.size());
    }
    cout<<"I/P\tNormalized_wt"<<endl;
    out << "I/P"<<","<<"Normalized_wt"<<endl;
    for(int i=0;i<ans.size();i++){
        cout << v[i] << "\t" << ans[i] << endl;
        out << v[i] << "," << ans[i] << endl;
    }
    return 0;
}