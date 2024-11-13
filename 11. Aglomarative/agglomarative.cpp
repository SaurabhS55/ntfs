#include<bits/stdc++.h>
using namespace std;
pair<int,int> findMinDistance(vector<vector<double>>& v,int n){
    int x=0, y=0;
    double d = 1e9 + 7;
    for (int i = 0;i<n;i++){
        for (int j = 0; j < n;j++){
            if(i!=j && (v[i][j]<d)){
                d = v[i][j];
                x = i;
                y = j;
            }
        }
    }
    return {x, y};
}
void agglomarative(vector<vector<double>>& v,int n){
    vector<vector<int>> clusters;
    for (int i = 0; i < n;i++){
        clusters.push_back({i});
    }
    cout << "\n Initial matrix: " << endl;
    for (int i = 0; i < n;i++){
        for (int j = 0; j <= i;j++){
            cout << fixed << setprecision(2) << v[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;
    cout << "\nSingle linkage: " << endl;
    while (clusters.size() > 2)
    {
        pair<int, int> p = findMinDistance(v, v.size());
        int x = p.first, y = p.second;
        for(int x : clusters[x]) {
            clusters[y].push_back(x);
        }
        clusters.erase(clusters.begin() + y);

        for (int i = 0; i < v.size(); i++)
        {
            if (i != x && i != y)
            {
                double temp = min(v[x][i], v[y][i]);
                v[i][x] = v[x][i] = temp;
            }
        }
        v.erase(v.begin() + y);
        for (auto& i : v)
        {
            i.erase(i.begin() + y);
        }
        for (int i = 0; i < v.size(); i++)
        {
            for (int j = 0; j <= i; j++)
            {
                cout << fixed << setprecision(2) << v[i][j] << "\t";
            }
            cout << endl;
        }
        cout << endl
             << endl;
        }
}
int main(){
    ifstream in("input.csv");
    vector<vector<double>> v;
    string str;
    while(getline(in,str)){
        stringstream ss(str);
        string tmp;
        vector<double> t;
        while(getline(ss,tmp,',')){
            t.push_back(stod(tmp));
        }
        v.push_back(t);
    }
    int n = v.size();
        agglomarative(v, n);
        return 0;
}