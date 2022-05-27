

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
void Graph::addEdge(string v1, string v2,int num){

    for(int i = 0; i < (int)vertices.size(); i++){
        if(vertices[i]->name == v1){
            for(int j = 0; j < (int)vertices.size(); j++){
                if(vertices[j]->name == v2 && i != j){
                    adjVertex av;
                    av.weight = num;
                    av.v = vertices[j];
                    vertices[i]->adj.push_back(av);
                    //another vertex for edge in other direction
                    adjVertex av2;
                    av2.weight = num;
                    av2.v = vertices[i];
                    vertices[j]->adj.push_back(av2);
                }
            }
        }
    }
}

void DFTraversal(vertex *n)
{
    n->visited = true;
    stack <vertex*> stack1;
    stack1.push(n);

  while(!stack1.empty()){
      // pop a vertex from stack and print it
      vertex* n = stack1.top();
      cout<< n->name << " --> ";

      stack1.pop();

      // Get all adjacent vertices of the dequeued
      // vertex s. If a adjacent has not been visited,
      // then mark it visited and enqueue it
      for (int i = 0; i<(int) n->adj.size(); ++i){
          if (!n->adj[i].v->visited) {

              DFTraversal(n->adj[i].v);
          }

            //n->adj[i].v->distance = n->distance + n->adj[i].weight;

      }


  }

}

void Graph::depthFirstTraversal(string source){

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
    DFTraversal(ver);
    cout << "Done";

}


vertex* Graph::DijkstraAlgorithm(string start, string end){
    bool flag = false;
    bool flag1 = false;

    vertex* startv;
    vertex* endv;
    for(int i=0;i< (int) vertices.size(); i++) {
        if(vertices[i]->name == start){
        startv = vertices[i];
        startv->distance = 0;
        flag= true;
        continue;
        }
        if(vertices[i]->name == end){
        endv = vertices[i];
        //endv->distance = 0;
        flag1= true;

        continue;
        }
    }

    if(flag == false || flag1 == false){
        return NULL;
    }

    vector <vertex*> solved;
    startv->visited = true;
    solved.push_back(startv);

    while (!endv->visited){


        int smallest = 10000000;
        vertex* temp = NULL;
        for(int j = 0; j <(int) solved.size();j++){
            vertex* n = solved[j];
            //loop over A adj list and mark the closest one.
            for (int i = 0; i<(int) n->adj.size(); ++i){

                if (!n->adj[i].v->visited){
                        int distance = n->distance + n->adj[i].weight;
                    if(distance < smallest){
                        temp = n->adj[i].v;
                        smallest = distance;
                        n->adj[i].v->pred = n;
                    }
                }
            }




        }
        temp->distance = smallest;
        //temp->pred = pred;
        temp->visited = true;
        solved.push_back(temp);
    }
    return endv;
 }






 void Graph::shortestpath(string start, string end)
 {
     for(int i = 0; i <(int) vertices.size();i++){
         vertices[i]->visited = false;
     }
        bool flag = false;
     bool flag1 = false;

     vertex* startv;
     vertex* endv;
     for(int i=0;i< (int) vertices.size(); i++) {
         if(vertices[i]->name == start){
         startv = vertices[i];
         startv->distance = 0;
         flag= true;
         continue;
         }
         if(vertices[i]->name == end){
         endv = vertices[i];
         //endv->distance = 0;
         flag1= true;

         continue;
         }
     }

     if(flag == false || flag1 == false){
         return ;
     }
     vertex* temp = endv;
     int size = (int) vertices.size();
     vertex* arr[size];
     int counter = 0;
     while (temp != startv){
         arr[counter] = temp;
         counter ++;
         temp = temp->pred;
         if(temp == startv){
             arr[counter] = temp;
         }
     }
     while(counter >=0){


         cout << arr[counter]->name <<" ";
         counter = counter-1;
     }


 }
