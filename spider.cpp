//Analysis of Algorithm project 3 itsy bitsy spider problem
#include<iostream>
#include<fstream>
#include<string>
#include<queue>

using namespace std;

//print path
string printDirectionPath(vector<int>& path, int mazeRow, int mazeColumn){

    int size = path.size();
    int i = 0;
    string answer = "";

    for (; i < size; i++){
        int vertexIndex = path[i];
        int nextVertex = path[i + 1];

        //direction
        int north = vertexIndex - mazeColumn;
        int east = vertexIndex + 1;
        int south = vertexIndex + mazeColumn;
        int west = vertexIndex - 1;
        int up = vertexIndex + (mazeColumn * mazeRow);
        int down = vertexIndex - (mazeColumn * mazeRow);

        if (nextVertex == north){
            answer = answer + "N ";
        }
        if(nextVertex == east){
            answer = answer + "E ";
        }
        if (nextVertex == south){
            answer = answer + "S ";
            }
        if(nextVertex == west)
            answer = answer + "W ";
        if (nextVertex == up)
            answer = answer + "U ";
        if(nextVertex == down)
            answer = answer + "D ";
    }
    cout << endl;
    return answer;
}// end printDirectionPath
 
//check if visted
int isNotVisited(int x, vector<int>& path)
{
    int size = path.size();
    for (int i = 0; i < size; i++)
        if (path[i] == x)
            return 0;
    return 1;
}
 
//BFS find paths... changed so only one solution..remove if condition on printDirectionPath to see alternative paths
string findpaths(vector<vector<int> >& g, int startVertex, int goalVertex, int num_of_vertex, int mazeRow, int mazeColumn){
    queue<vector<int> > queue;
 
    // path vector to store the current path
    vector<int> path;
    path.push_back(startVertex);
    queue.push(path);
    
    int j = 0;
    string answer = "";

    while (!queue.empty()) {
        path = queue.front();
        queue.pop();
        int last = path[path.size() - 1];

        //just get one of the possible solutions. remove if (j=0) to see more
        if (j == 0){
            //if last vertex is reached, print path
            if (last == goalVertex){
                answer = printDirectionPath(path, mazeRow, mazeColumn);
                j++;
            }
        }
        //go to all nodes connect to currVertex then push new path to queue
        for (int i = 0; i < g[last].size(); i++) {
            if (isNotVisited(g[last][i], path)) {
                vector<int> newpath(path);
                newpath.push_back(g[last][i]);
                queue.push(newpath);
            }
        }
    }
    return answer;
}


int main(){
    fstream mazeFile;
    queue<int> qInput;
    string preline = "";   //  before removing spaces and \n
    string line = "";   //final input string
    char c;

    mazeFile.open("input.txt"); //  read file
    if(mazeFile.is_open()){
        while(!mazeFile.eof()){
            mazeFile.get(c);
            if(c != ' ' && c != '\n'){
                int temp = (int)c - 48;
                qInput.push(temp);
            }
        }
    }
    mazeFile.close();

    //starting maze values
    //maze dimensions
    int mazeLevel = 0;
    int mazeRow = 0;
    int mazeColumn = 0;
    //start position
    int startLevel = 0;
    int startRow = 0;
    int startColumn = 0;
    //goal position
    int goalLevel = 0;
    int goalRow = 0;
    int goalColumn = 0;

    //get dimensions of maze
    for (int i = 0; i < 3; i++){
        if (i == 0){
            mazeLevel = qInput.front();
        }else if(i == 1){
            mazeRow = qInput.front();
        }else if(i == 2){
            mazeColumn = qInput.front();
        }
        qInput.pop();
    }//end for
    
    //position of start 
    for (int i = 0; i < 3; i++){
        if (i == 0){
            startLevel = qInput.front();
        }else if(i == 1){
            startRow = qInput.front();
        }else if(i == 2){
            startColumn = qInput.front();
        }
        qInput.pop();
    }//end for

    //position of goal
    for (int i = 0; i < 3; i++){
        if (i == 0){
            goalLevel = qInput.front();
        }else if(i == 1){
            goalRow = qInput.front();
        }else if(i == 2){
            goalColumn = qInput.front();
        }
        qInput.pop();
    }//end for

    //start vertex
    int startVertex = startLevel * (mazeRow * mazeColumn) + (startRow * mazeRow) + startColumn;
    //goal vertex
    int goalVertex = goalLevel * (mazeRow * mazeColumn) + (goalRow * mazeRow) + goalColumn;

    //number of vertex on graph
    int num_of_vertex = mazeLevel * mazeRow * mazeColumn;
    int vertexIndex = 0;

    vector<vector<int>> g;
    g.resize(num_of_vertex);

    //going though maze
    while(!qInput.empty()){
    //store vertex values for possible direction and link
        int nextVertex = 0;
        int direction = 0;

        for(int i = 0; i < 6; i++){
            direction = qInput.front();
            // 0   1     2    3     4  5
            //north,south,east,west,up,down
            //north
            if(i == 0)
                if(direction == 1){
                    nextVertex = vertexIndex - mazeColumn;
                    g[vertexIndex].push_back(nextVertex);
                }
            //east
            if(i == 1)
                if(direction == 1){
                    nextVertex = vertexIndex + 1;
                    g[vertexIndex].push_back(nextVertex);
                }
            //south
            if(i == 2)
                if(direction == 1){
                    nextVertex = vertexIndex + mazeColumn;
                    g[vertexIndex].push_back(nextVertex);
                }
            //west
            if(i == 3)
                if(direction == 1){
                    nextVertex = vertexIndex - 1;
                    g[vertexIndex].push_back(nextVertex);;
                }
            //up
            if(i == 4)
                if(direction == 1){
                    nextVertex = vertexIndex + (mazeColumn * mazeRow);
                    g[vertexIndex].push_back(nextVertex);
                }
            //down
            if(i == 5)
                if(direction == 1){
                    nextVertex = vertexIndex - (mazeColumn * mazeRow);
                    g[vertexIndex].push_back(nextVertex);
                }
            qInput.pop();
        }//end for
        vertexIndex++;
    }//end for
    
    string answer = findpaths(g, startVertex, goalVertex, num_of_vertex, mazeRow, mazeColumn);
    cout << answer;
    
    //output file
    fstream output;
    output.open("output.txt", ios::out);
    if(!output){
        cout << "file not created";
    }
    else{
        cout << "file created";
        output << answer;
        output.close();
    }

    return 0;





}//end main