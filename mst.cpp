//
//  mst.cpp
//  HW4
//
//  Created by Nils Streedain on 5/14/22.
//

#include <iostream>
#include <fstream>
#include <utility>
#include <math.h>
#include <queue>


int getDist(int x1, int x2, int y1, int y2) {
	int d1 = x1 - x2;
	int d2 = y1 - y2;
	return round(sqrt(d1 * d1 + d2 * d2));
}

int main(int argc, const char * argv[]) {
	// Open file and loop while not at end
	std::ifstream is("graph.txt");
	
	int numCases;
	is >> numCases;
	for (int c = 1; c <= numCases; c++) {
		int numV;
		is >> numV;
		
		// Parse list of verticies cords
		std::pair<int, int> v[numV];
		for (int i = 0; i < numV; i++) {
			is >> v[i].first;
			is >> v[i].second;
		}
		
		std::vector<std::vector<std::pair<int, int>>> G;
		G.resize(numV);
		for (int i = 0; i < numV; i++) {
			G[i].resize(numV);
			for (int j = 0; j < numV; j++)
				G[i][j] = std::make_pair(getDist(v[i].first, v[j].first, v[i].second, v[j].second), j);
		}
		
		std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
		
		pq.push(std::make_pair(0, 0));
		
		bool added[numV];
		memset(added, 0, sizeof(numV));
		
		int total = 0;
		
		while (!pq.empty()) {
			std::pair<int, int> curr = pq.top();
			pq.pop();
			
			int dist = curr.first;
			int next = curr.second;
			
			if (!added[next]) {
				total += dist;
				added[next] = true;
				
				for (std::pair<int, int>& adj : G[next]) {
					int adjNext = adj.second;
					if (!added[adjNext])
						pq.push(adj);
				}
			}
		}
		
		printf("Test case %i: MST weight %i\n\n", numCases, total);
	}
	// Close file after loop
	is.close();
}
