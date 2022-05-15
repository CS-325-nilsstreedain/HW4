//
//  old.cpp
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
		
		int G[numV][numV];
		memset(G, 0, sizeof(G));
		
		int total = 0;
		int added[numV];
		memset(added, -1, sizeof(added));
		
		
//		for (int i = 0; i < numV; i++) {
//			int closest;
//			int dist = INT_MAX;
//			for (int j = 0; j < numV; j++) {
////				if (added[i] != j && i != j) {
//				if (!added[j] && i != j) {
//					int currDist = getDist(v[i].first, v[j].first, v[i].second, v[j].second);
//					if (currDist < dist) {
//						closest = j;
//						dist = currDist;
//					}
//				}
//			}
//			G[i][closest] = dist;
//
//			if (i < numV - 1)
//				total += dist;
//
//			added[i] = 1;
//		}
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
			G[i][closest] = dist;

			total += dist;

			added[i] = closest;
		}
		
		std::cout << total << std::endl;
		
//		// Construct distance matrix from verticies
//		int G[numV][numV];
//		for (int j = 0; j < numV; j++)
//			for (int k = 0; k < numV; k++) {
//				int d1 = v[j].first - v[k].first;
//				int d2 = v[j].second - v[k].second;
//				G[j][k] = round(sqrt(d1 * d1 + d2 * d2));
//			}
//
		// Print distance matrix
		for (int j = 0; j < numV; j++) {
			for (int k = 0; k < numV; k++)
				std::cout << G[j][k] << "\t";
			std::cout << std::endl;
		}
		std::cout << std::endl;
//
//
//		int added[numV];
//		for (int j = 0; j < numV; j++)
//			added[j] = 0;
		
//		for (int j = 0; j < numV - 1; j++) {
//			for (int k = 0; k < numV; k++) {
//				<#statements#>
//			}
//		}
	}
	// Close file after loop
	is.close();
}
