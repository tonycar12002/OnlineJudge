/*
Author: Tony Hsiao
Date: 2019/05/07
Topic: 207. Course Schedule
Speed: 20 ms, 13MB
Note:  Directed acyclic graph(DAG) + DFS
*/
class Solution {
private:
    vector<vector<int>> graph;
    vector<int> visited; // 1 = visitied, 2 = visiting

public:
    bool ExistCycle(int node_index){
        if(visited[node_index] == 2) // if no ccycle => visiting is impossible
            return true;
        else if(visited[node_index] == 1)
            return false;

        visited[node_index] = 2;
        for(int i=0;i<graph[node_index].size();i++)
            if(visited[graph[node_index][i]] == 2 || ExistCycle(graph[node_index][i]))
                return true;
        
        visited[node_index] = 1;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        graph = vector<vector<int>>(numCourses);
        visited = vector<int>(numCourses, 0);

        for(int i=0;i<prerequisites.size();i++)
            graph[prerequisites[i][1]].push_back(prerequisites[i][0]);

        for(int i=0;i<numCourses;i++)
            if(ExistCycle(i))
                return false;

        return true;
    }
};