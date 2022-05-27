





// function to add a vertex to the graph
void Graph::addVertex(string name){
    bool found = false;
    for(int i = 0; i < vertices.size(); i++){
        if(vertices[i]->name == name){
            found = true;
        }
    }
    if(found == false){
        vertex * v = new vertex;
        v->name = name;
        vertices.push_back(v);
    }
}

// function to add edge between two vertices
void Graph::addEdge(string v1, string v2){

    for(int i = 0; i < (int)vertices.size(); i++){
        if(vertices[i]->name == v1){
            for(int j = 0; j < (int)vertices.size(); j++){
                if(vertices[j]->name == v2 && i != j){
                    adjVertex av;
                    av.v = vertices[j];
                    vertices[i]->adj.push_back(av);
                    //another vertex for edge in other direction
                    adjVertex av2;
                    av2.v = vertices[i];
                    vertices[j]->adj.push_back(av2);
                }
            }
        }
    }
}

// function to visualize the graph
void Graph::displayEdges(){

    //loop through all vertices and adjacent vertices

    for(int i = 0; i < (int)vertices.size(); i++){

        cout<<vertices[i]->name<<" --> ";
        for(int j = 0; j < (int) vertices[i]->adj.size(); j++){
            cout << vertices[i]->adj[j].v->name << " ";
        }
        cout<<endl;
    }

}


void Graph::breadthFirstTraverse(string source){
    bool flag = false;
    vertex* ver;
    for(int i=0;i< (int) vertices.size(); i++) {
      if(vertices[i]->name == source){
        ver = vertices[i];
        ver->distance = 0;
        flag= true;
        break;
      }
    }
    if(flag == false){
        return;
    }
    ver->visited = true;
    queue <vertex*> queue1;
    queue1.push(ver);
    cout <<"Starting vertex (root): "<<ver->name <<"-> ";
    while(!queue1.empty()){
        // Dequeue a vertex from queue and print it
        vertex* n = queue1.front();
        queue1.pop();

        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it
        for (int i = 0; i<(int) n->adj.size(); ++i){
            if (!n->adj[i].v->visited) {
                n->adj[i].v->distance = n->distance + 1;
            cout <<n->adj[i].v->name <<"(" <<n->adj[i].v->distance<<")" <<" ";
                n->adj[i].v->visited = true;
                queue1.push(n->adj[i].v);
            }


        }
    }

}


void helperTraverse(vertex* vertices){


    vertices->visited = true;
    queue <vertex*> queue1;
    queue1.push(vertices);
    while(!queue1.empty()){
        // Dequeue a vertex from queue and print it
        vertex* n = queue1.front();
        queue1.pop();

        // Get all adjacent vertices of the dequeued
        // vertex s. If a adjacent has not been visited,
        // then mark it visited and enqueue it

        for (int i = 0; i<(int) n->adj.size(); ++i){
            if (!n->adj[i].v->visited) {
                helperTraverse(n->adj[i].v);
            }


        }
    }

}


int Graph::getConnectedComponents(){

    // To store the number of connected components
    int count = 0;
    //int num = (int) vertices.size();
    for (int i = 0; i <(int)vertices.size(); i++) {
        if (vertices[i]->visited == false) {
            helperTraverse(vertices[i]);
            count += 1;
        }
    }

    return count;
}
