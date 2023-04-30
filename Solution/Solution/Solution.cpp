#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int N = 100;
    int G = 3;

    int** adj_matrix = new int* [N];
    for (int i = 0; i < N; i++) {
        adj_matrix[i] = new int[N]();
    }

    int* num_connections = new int[N]();
    srand(time(NULL));

    while (true) {
        bool all_connected = true;
        for (int i = 0; i < N; i++) {
            if (num_connections[i] < G) {
                all_connected = false;
                int node = rand() % N;
                if (node != i && num_connections[node] < G && adj_matrix[i][node] == 0 && adj_matrix[node][i] == 0) {
                    adj_matrix[i][node] = 1;
                    adj_matrix[node][i] = 1;
                    num_connections[i]++;
                    num_connections[node]++;
                }
            }
        }
        if (all_connected) {
            break;
        }
    }

    cout << "1 done\n";
    ofstream outfile("J100.txt");
    outfile << N << " " << (N * G) / 2 << " 0\n";
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (adj_matrix[i][j] == 1) {
                outfile << i << "   " << j << " 1\n";
            }
        }
    }
    outfile.close();

    for (int i = 0; i < N; i++) {
        delete[] adj_matrix[i];
    }
    delete[] adj_matrix;
    delete[] num_connections;

    return 0;
}
