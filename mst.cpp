//
//  mst.cpp
//  HW4
//
//  Created by Nils Streedain on 5/14/22.
//

#include <iostream>
#include <fstream>
#include <math.h>
#include <queue>

int main() {
	// Open file and loop while not at end
	std::ifstream is("graph.txt");
	
	// Loop over each case in txt file
	int numCases;
	is >> numCases;
	for (int c = 1; c <= numCases; c++) {
		int numV;
		is >> numV;
		
		// Parse list of verticies coordinantes
		std::pair<int, int> v[numV];
		for (int i = 0; i < numV; i++)
			is >> v[i].first >> v[i].second;
		
		// Create Min Priority Queue of Nodes (distance, adjacent)
		std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
		
		// Base values for pq while loop
		int total = 0;
		bool added[numV];
		pq.push(std::make_pair(0, 0));
		
		// Loop over each Node in queue, starting with those of min distance.
		for (std::pair<int, int> curr; !pq.empty(); curr = pq.top(), pq.pop()) {
			int adj = curr.second;
			
			// If node has not been added to MST, inc total weight
			if (!added[adj]) {
				added[adj] = 1;
				total += curr.first;
				
				// Add curr adjacent nodes to queue
				for (int i = 0; i < numV; i++) if (!added[i])
					pq.push(std::make_pair(round(hypot(v[i].first - v[adj].first, v[i].second - v[adj].second)), i));
			}
		}
		printf("Test case %i: MST weight %i\n\n", c, total);
	}
}
