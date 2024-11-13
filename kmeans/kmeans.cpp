#include <bits/stdc++.h>

using namespace std;

struct Point {
    double x, y;
};

vector<Point> initializeCentroids(const vector<Point>& data, int k) {
    vector<Point> centroids;
    srand(time(0));
    for (int i = 0; i < k; ++i) {
        centroids.push_back(data[rand() % data.size()]);
    }
    return centroids;
}

vector<vector<Point>> assignClusters(const vector<Point>& data, const vector<Point>& centroids) {
    vector<vector<Point>> clusters(centroids.size());
    for (const auto& point : data) {
        double minDist = numeric_limits<double>::max();
        int minIndex = 0;

        for (int i = 0; i < centroids.size(); ++i) {
            double dist = sqrt(pow(point.x - centroids[i].x, 2) + pow(point.y - centroids[i].y, 2));
            if (dist < minDist) {
                minDist = dist;
                minIndex = i;
            }
        }
        clusters[minIndex].push_back(point);
    }
    return clusters;
}

vector<Point> updateCentroids(const vector<vector<Point>>& clusters) {
    vector<Point> newCentroids;
    for (const auto& cluster : clusters) {
        if (cluster.empty()) continue;

        double avgX = 0.0, avgY = 0.0;
        for (const auto& point : cluster) {
            avgX += point.x;
            avgY += point.y;
        }
        avgX /= cluster.size();
        avgY /= cluster.size();
        newCentroids.push_back({avgX, avgY});
    }
    return newCentroids;
}

vector<vector<Point>> kMeans(vector<Point>& data, int k,) {
    vector<Point> centroids = initializeCentroids(data, k);
    ofstream out("output.csv");

    for (int iter = 0; iter < maxIters; ++iter) {
        out << "\nIteration " << iter + 1 << ":\n";
        vector<vector<Point>> clusters = assignClusters(data, centroids);

        for (int i = 0; i < clusters.size(); ++i) {
            out << "Cluster " << i + 1 << " - Centroid: (" << centroids[i].x << ", " << centroids[i].y << ")\n";
            out << "Points: ";
            for (const auto& point : clusters[i]) {
                out << "(" << point.x << ", " << point.y << ") ";
            }
            out << "\n";
        }

        vector<Point> newCentroids = updateCentroids(clusters);
        if (newCentroids == centroids) break;

        centroids = newCentroids;
    }

    out << "\nFinal Clusters and Points:\n";
    for (int i = 0; i < centroids.size(); ++i) {
        out << "Cluster " << i + 1 << " - Centroid: (" << centroids[i].x << ", " << centroids[i].y << ")\n";
        out << "Points: ";
        for (const auto& point : clusters[i]) {
            out << "(" << point.x << ", " << point.y << ") ";
        }
        out << "\n";
    }

    out.close();
    return clusters;
}
int main() {
    int k = 3;

    vector<Point> data;
    ifstream in("input.csv");
    string line;
    while (getline(in, line)) {
        stringstream ss(line);
        string temp;
        Point point;
        getline(ss, temp, ',');
        point.x = stod(temp);
        getline(ss, temp, ',');
        point.y = stod(temp);
        data.push_back(point);
    }
    kMeans(data, k);
    return 0;
}
