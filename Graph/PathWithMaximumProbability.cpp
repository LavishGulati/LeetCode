typedef pair<int, double> pid;
#define f first
#define s second
#define mp make_pair
#define pb push_back

class Solution {
public:
    struct MaxHeapNode{
        int v;
        double dist;

        MaxHeapNode(int v, double dist){
            this->v = v;
            this->dist = dist;
        }
    };

    struct MaxHeap{
        int size, capacity, *pos;
        MaxHeapNode **arr;

        MaxHeap(int capacity){
            this->pos = new int[capacity];
            this->size = 0;
            this->capacity = capacity;
            this->arr = new MaxHeapNode *[capacity];
        }
    };

    void swapMaxHeapNode(MaxHeapNode **a, MaxHeapNode **b){
        MaxHeapNode *t = *a;
        *a = *b;
        *b = t;
    }

    void maxHeapify(MaxHeap *maxHeap, int id){
        int largest, left, right;
        largest = id;
        left = 2*id+1;
        right = 2*id+2;

        if(left < maxHeap->size && maxHeap->arr[left]->dist > maxHeap->arr[largest]->dist){
            largest = left;
        }
        if(right < maxHeap->size && maxHeap->arr[right]->dist > maxHeap->arr[largest]->dist){
            largest = right;
        }

        if(largest != id){
            MaxHeapNode *largestNode = maxHeap->arr[largest];
            MaxHeapNode *idNode = maxHeap->arr[id];

            maxHeap->pos[largestNode->v] = id;
            maxHeap->pos[idNode->v] = largest;

            swapMaxHeapNode(&maxHeap->arr[largest], &maxHeap->arr[id]);
            maxHeapify(maxHeap, largest);
        }
    }

    MaxHeapNode *extractMax(MaxHeap *maxHeap){
        if(!(maxHeap->size)){
            return NULL;
        }

        MaxHeapNode *root = maxHeap->arr[0];
        MaxHeapNode *lastNode = maxHeap->arr[maxHeap->size-1];
        maxHeap->arr[0] = lastNode;

        maxHeap->pos[root->v] = maxHeap->size-1;
        maxHeap->pos[lastNode->v] = 0;

        --maxHeap->size;
        maxHeapify(maxHeap, 0);
        return root;
    }

    void increaseKey(MaxHeap *maxHeap, int v, double dist){
        int i = maxHeap->pos[v];
        maxHeap->arr[i]->dist = dist;

        while(i && maxHeap->arr[i]->dist > maxHeap->arr[(i-1)/2]->dist){
            maxHeap->pos[maxHeap->arr[i]->v] = (i-1)/2;
            maxHeap->pos[maxHeap->arr[(i-1)/2]->v] = i;
            swapMaxHeapNode(&maxHeap->arr[i], &maxHeap->arr[(i-1)/2]);
            i = (i-1)/2;
        }
    }

    bool isInMaxHeap(MaxHeap *maxHeap, int v){
        if(maxHeap->pos[v] < maxHeap->size){
            return true;
        }
        return false;
    }

    double *dijkstra(vector<pid> *graph, int src, int n){
        double *dist = new double[n];
        int *par = new int[n];
        MaxHeap *maxHeap = new MaxHeap(n);

        for(int i = 0; i < n; i++){
            dist[i] = 0;
            maxHeap->arr[i] = new MaxHeapNode(i, dist[i]);
            maxHeap->pos[i] = i;
        }

        par[src] = -1;
        dist[src] = 1;
        increaseKey(maxHeap, src, 1);
        maxHeap->size = n;

        while(maxHeap->size){
            MaxHeapNode *maxHeapNode = extractMax(maxHeap);
            int u = maxHeapNode->v;

            for(pid p : graph[u]){
                int v = p.f;
                double w = p.s;
                if(isInMaxHeap(maxHeap, v) && dist[u] != 0 && dist[u]*w > dist[v]){
                    par[v] = u;
                    dist[v] = dist[u]*w;
                    increaseKey(maxHeap, v, dist[v]);
                }
            }
        }
        return dist;
    }

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pid> *graph = new vector<pid>[n];
        int m = edges.size();
        for(int i = 0; i < m; i++){
            graph[edges[i][0]].pb(mp(edges[i][1], succProb[i]));
            graph[edges[i][1]].pb(mp(edges[i][0], succProb[i]));
        }

        double *output = dijkstra(graph, start, n);
        return output[end];
    }
};
