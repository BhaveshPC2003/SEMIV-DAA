#include<iostream>
#include<climits>

using namespace std;

const int  N = 20;
int edges[N][N];

//Structure that contains all necessary attr of a vertex
struct vertex{
    int name = -1;
    bool visited = false;
    int d = INT_MAX;
    int pred = -1;
};

//Helper function for swapping
void swap(struct vertex *x,struct vertex *y){
    struct vertex temp = *x;
    *x = *y;
    *y = temp;
}

//Implementing Priority using Min Heap
class PriorityQueue{
    private:
    struct vertex *arr;
    int size;
    int capacity;

    public:
    PriorityQueue(int n){
        arr = new struct vertex[n];
        size = 0;
        capacity = n;
    }
    int parent(int i){
        return (i-1)/2;
    }
    int left_child(int i){
        return (2*i) + 1;
    }
    int right_child(int i){
        return (2*i) + 2;
    }
    bool empty(){
        if(size == 0)
            return true;
        return false;
    }
    void insert(struct vertex v){
        if(size == capacity){
            cout << "Queue Overflow" << endl;
            return;
        }
        int i = size;
        arr[i] = v;
        size++;
        while(i>0 && arr[parent(i)].d > arr[i].d){
            swap(&arr[parent(i)],&arr[i]);
            i = parent(i);
        }
    }
    void heapify(int index){
        if(size <= 1)
            return;
        int smallest = index;
        int left = left_child(index);
        int right = right_child(index);
        if(left < size && arr[left].d < arr[index].d){
            smallest = left;
        }
        if(right < size && arr[right].d < arr[smallest].d){
            smallest = right;
        }
        if(smallest != index){
            swap(&arr[smallest],&arr[index]);
            heapify(smallest);
        }
        return;
    }   
    int extract_min(){
        if(size == 0){
            cout << "Queue Empty" << endl;
            return -1;
        }
        int root = arr[0].name;
        swap(&arr[size-1],&arr[0]);
        size--;
        heapify(0);
        return root;
    }
    void decrease_key(int name,int d){
        int i = 0;
        while(name != arr[i].name)
            i++;
        arr[i].d = d;
        while(i>0 && arr[parent(i)].d > arr[i].d){
            swap(&arr[parent(i)],&arr[i]);
            i = parent(i);
        }
    }
};

//Helper function to relax a vertex
int relax(int u,int v,struct vertex *vertices){
    if(vertices[v].d > vertices[u].d + edges[u][v]){
        vertices[v].d = vertices[u].d + edges[u][v];
        vertices[v].pred = u;
        return vertices[v].d;
    }
    return 0;
}

//Dijkstra function to find shortes path
void dijkstra(int src,int n,struct vertex *vertices){
    PriorityQueue Q(n);
    vertices[src].d = 0;
    vertices[src].name = src;
    for(int i=0;i<n;i++){
        vertices[i].name = i;
        Q.insert(vertices[i]);
    }
    while(!Q.empty()){
        int u = Q.extract_min();
        vertices[u].visited = true;
        for(int i=0;i<n;i++){
            if(edges[u][i] == 0)
                continue;
            int d = relax(u,i,vertices);
            if(d > 0){
                Q.decrease_key(i,d);
            }
    }
    }
}

//To display attr of all vertices
void display(struct vertex *v,int n){
    cout << "V \t P \t D" << endl;
    for(int i=0;i<n;i++){
        cout << i << " \t " << v[i].pred << " \t " << v[i].d << endl;
    }
}

int main(){
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;
    struct vertex vertices[n];
    int edges_count;
    cout << "Enter number of edges" << endl;
    cin >> edges_count;
    cout << "Enter edge (x->y):w- " << endl;
    for(int i=0;i<edges_count;i++){
        int x,y,w;
        cin >> x;
        cin >> y;
        cin >> w;
        edges[x][y] = w;
    }   
    dijkstra(0,n,vertices);
    cout << endl;
    display(vertices,n);
}