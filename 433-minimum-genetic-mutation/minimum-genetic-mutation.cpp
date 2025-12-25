class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        // 📌 STEP 1: Build gene bank set for O(1) lookup
        unordered_set<string> geneBank(bank.begin(), bank.end());
        
        // Early exit: if target doesn't exist, impossible!
        if (geneBank.find(endGene) == geneBank.end()) {
            return -1;
        }
        
        char mutations[] = {'A', 'C', 'G', 'T'};
        int mutationCount = 0;
        
        // 📌 STEP 2: BFS Setup
        queue<string> q;
        q.push(startGene);
        
        // 📌 STEP 3: Level-by-level BFS
        while (!q.empty()) {
            int levelSize = q.size();
            
            for (int i = 0; i < levelSize; i++) {
                string gene = q.front();
                q.pop();
                
                // Found the target!
                if (gene == endGene) {
                    return mutationCount;
                }
                
                // 📌 STEP 4: Try all possible single-char mutations
                for (int index = 0; index < 8; index++) {
                    char original = gene[index];
                    
                    for (char mutation : mutations) {
                        gene[index] = mutation;
                        
                        // Valid mutation found in bank?
                        if (geneBank.count(gene)) {
                            q.push(gene);
                            geneBank.erase(gene); // Mark as visited and not needed again
                        }
                    }
                    gene[index] = original; // Restore
                }
            }
            mutationCount++; // Completed one level = one mutation
        }
        
        return -1; // No path found
    }
};