#include<bits/stdc++.h>
using namespace std;

vector<vector<pair<double, double>>> kmeans(const vector<double>& x, const vector<double>& y, int k) {
    int n = x.size();
    vector<pair<double, double>> centroids(k);
    for(int i = 0; i < k; i++) centroids[i] = {x[i], y[i]};
    
    vector<vector<pair<double, double>>> clusters(k);
    for(int it = 0; it < 10; it++) {
        for(auto& c : clusters) c.clear();
        
        for(int i = 0; i < n; i++) {
            int best = 0;
            double best_dist = hypot(x[i] - centroids[0].first, y[i] - centroids[0].second);
            for(int j = 1; j < k; j++) {
                double d = hypot(x[i] - centroids[j].first, y[i] - centroids[j].second);
                if(d < best_dist) {
                    best_dist = d;
                    best = j;
                }
            }
            clusters[best].push_back({x[i], y[i]});
        }
        
        for(int j = 0; j < k; j++) {
            if(!clusters[j].empty()) {
                double sum_x = 0, sum_y = 0;
                for(auto& p : clusters[j]) {
                    sum_x += p.first;
                    sum_y += p.second;
                }
                centroids[j] = {sum_x / clusters[j].size(), sum_y / clusters[j].size()};
            }
        }
    }
    cout << "\ncentroids:\n";
    for (int i = 0; i < k;i++){
        cout << centroids[i].first << " " << centroids[i].second << endl;
    }
        return clusters;
}

int main() {
    ifstream in("input.csv");
    vector<double> x, y;
    string str;
    while(getline(in, str)) {
        stringstream ss(str);
        string tmp;
        getline(ss, tmp, ',');
        x.push_back(stod(tmp));
        getline(ss, tmp, ',');
        y.push_back(stod(tmp));
    }
    int k;
    cout << "\nEnter number of clusters (k): " << endl;
    cin >> k;
    vector<vector<pair<double, double>>> clusters = kmeans(x, y, k);
    cout << "\nclusters: " << endl;
    for (int i = 0; i < clusters.size();i++){
        for (int j = 0; j < clusters[i].size();j++){
            cout << clusters[i][j].first << " " << clusters[i][j].second<<" ";
        }
        cout << endl;
    }
        return 0;
}
