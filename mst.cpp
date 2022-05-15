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
		
		// Parse list of verticies
		std::pair<int, int> v[numV];
		for (int i = 0; i < numV; i++) {
			is >> v[i].first;
			is >> v[i].second;
		}
		
		// Matrix for debug visualization
		int G[numV][numV];
		memset(G, 0, sizeof(G));
		
		int total = 0;
		int added[numV];
		memset(added, -1, sizeof(added));
		
		for (int i = 0; i < numV - 1; i++) {
			int closest = 0;
			int dist = INT_MAX;
			for (int j = 0; j < numV; j++) {
				if (i != added[j] && i != j) {
					int currDist = getDist(v[i].first, v[j].first, v[i].second, v[j].second);
					if (currDist < dist) {
						closest = j;
						dist = currDist;
					}
				}
			}
			// Populate debug matrix
			G[i][closest] = dist;

			total += dist;

			added[i] = closest;
		}
		
		printf("Test case %i: MST weight %i\n\n", numCases, total);
		
		// Print debug matrix
		for (int j = 0; j < numV; j++) {
			for (int k = 0; k < numV; k++)
				std::cout << G[j][k] << ", ";
			std::cout << std::endl;
		}
		std::cout << std::endl;
	}
	// Close file after loop
	is.close();
}
