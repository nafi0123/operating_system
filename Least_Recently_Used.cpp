#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void lruPageReplacement(int frames, vector<int> referenceString) {
    vector<int> memory;
    int pageFaults = 0, hits = 0;

    for (int page : referenceString) {
        auto it = find(memory.begin(), memory.end(), page);
        if (it != memory.end()) {
            hits++;
            memory.erase(it);
            memory.push_back(page);
        } else {
            pageFaults++;
            if (memory.size() >= frames) {
                memory.erase(memory.begin());
            }
            memory.push_back(page);
        }

        cout << "Page: " << page << " -> Memory: ";
        for (int m : memory) cout << m << " ";
        cout << endl;
    }

    cout << "\nTotal Page Faults: " << pageFaults << endl;
    cout << "Total Hits: " << hits << endl;
}

int main() {
    int frames = 3;
    vector<int> referenceString = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2};

    cout << "LRU Page Replacement Simulation\n";
    cout << "Frames: " << frames << endl;
    cout << "Reference String: ";
    for (int page : referenceString) cout << page << " ";
    cout << "\n\n";

    lruPageReplacement(frames, referenceString);

    return 0;
}
