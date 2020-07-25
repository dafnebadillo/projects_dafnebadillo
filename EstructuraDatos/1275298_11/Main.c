/*
Dafne Linette Badillo Campuzano A01275298
Andrea Munoz Gris A01733058
*/

#include <stdio.h>
#include <stdlib.h>

struct Graph{
    int V;
    struct AdjList* array;
};

struct AdjListNode{
    int dest;
    struct AdjListNode* next;
};

struct AdjList{
    struct AdjListNode *head;   
};

struct AdjListNode* newAdjListNode(int dest){
    struct AdjListNode* newNode = (struct AdjListNode*) malloc(sizeof(struct AdjListNode));
    newNode -> dest = dest;
    newNode -> next = NULL;
    return newNode;
}

struct Graph* createGraph(int V){
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph -> V = V;
    // creacion del array -> V
    graph -> array = (struct AdjList*) malloc(V * sizeof(struct AdjList));
    //recorrido para leer el grafo
    for (int i = 0; i < V; ++i)
        graph -> array[i].head = NULL;
    return graph;
}

//agregar borde al grafo
void addEdge(struct Graph* graph, int src, int dest){
    struct AdjListNode* newNode = newAdjListNode(dest);
    newNode -> next = graph -> array[src].head;
    graph -> array[src].head = newNode;
    newNode = newAdjListNode(src);
    newNode -> next = graph -> array[dest].head;
    graph -> array[dest].head = newNode;
}

//imprimir grafo
void printGraph(struct Graph* graph){
    for (int v = 0; v < graph -> V; ++v){
        struct AdjListNode* pCrawl = graph -> array[v].head;
        printf("\n Adjency list of vertex %d\n head", v);
        while(pCrawl){
            printf("-> %d", pCrawl -> dest);
            pCrawl = pCrawl -> next;
        }
        printf("\n");
    }
}
/// Floyd 

///

// Driver program to test above functions 
int **matrix = NULL;

int main() 
{ 
    
    // create the graph given in above fugure 
    int Vfil = 0; 
    //struct Graph* graph = createGraph(V); 
    scanf("%d", &Vfil);
    matrix = (int **) malloc(Vfil*sizeof(int **));
    int Vcol = 0;
    Vcol = Vfil;
    int dist[Vfil][Vcol];
    
    int cont =0;
    int tmp = 0;
    for (int i = 0; i <= Vfil; ++i){ //asignar memoria a las columnas
        matrix[i] = (int*)malloc(Vcol*sizeof(int)); 
        if(matrix[i] == NULL) perror("ERROR"); //se comprueba si no hay errores
    }
    for (int y = 0; y < Vfil; ++y){ //se mueve por filas
        for (int x = 0; x < Vcol; ++x){ // se mueve por columnas
            fprintf(stdout, "Valor [%d][%d]: \n", y,x);
            scanf("%d", &matrix[y][x]);
        }
    }
    puts("\nADJACENCY MATRIX");
    puts("------");
    // IMPRIMIR MATRIX
    for (int l = 0; l < Vfil; ++l){
        for (int k = 0; k < Vcol; ++k){
            fprintf(stdout, "%d\t", matrix[l][k]);
        }
        puts("\n");
    }
    //free(matrix); //liberar memoria de la matriz
    //matrix = NULL;
    printf("\nEdge List\n");
    printf("\n" );
        for(int i = 0; i < Vfil; i++)
            for(int j = 0; j < Vcol; j++)
                if(matrix[i][j] != -1){
                    printf("Edge %d connects node %d with node %d with a weight: %d\n",cont,i,j,matrix[i][j]);
                    cont++;
                }

    printf("\nAdjacency List\n");
    printf("\n" );
        for(int i = 0; i < Vfil; i++)
            for(int j = 0; j < Vcol; j++)
                if(matrix[i][j] != -1){
                    printf("Node %d connects with node %d(weight: %d)\n",i,j,matrix[i][j]);
            }

    printf("\nDijkstra\n" );
    printf("\n" );
        for(int i = 0; i < Vfil; i++){ 
            for(int j = 0; j < Vcol; j++){
                    if(matrix[i][j] == -1)
                        dist[i][j]= 1024;
                    else
                        dist[i][j] = matrix[i][j];
            } 
        }
        for(int x = 0; x < Vfil; x++)
            for(int y = 0; y < Vcol; y++){ 
                for(int z = 0; z < Vcol&&Vfil; z++){
                    if(dist[y][x] + dist[x][z] < dist[y][z] && dist[y][x]){
                        tmp = dist[y][x] + dist[x][z];
                        dist[y][z] = tmp; 
                    } 
                } 
        }
        for(int i = 0; i < Vfil; i++)
            for(int j = 0; j < Vcol; j++)
                if(i != j){
                    printf("From node %d to node %d: %d\n",i,j,dist[i][j]);
                }

    //prints floyd 
    puts("\nFLOYD MATRIX");
    puts("------");
    for (int i = 0; i < Vfil; i++) 
    { 
        for (int j = 0; j < Vcol; j++) 
        { 
            if(i == j)
                fprintf(stdout, "0\t");
            else
                fprintf(stdout, "%d\t", dist[i][j]);
                
        } 
        puts("\n"); 
    } 
    ///
    int mat[Vfil];
    int var1 = 1,var2 = 0;
    int pos = 1, cont1 = 0;
    mat[0] = 0;
    for(int i = 0; i < Vfil&&Vcol; i++){
        if(matrix[0][i]!=-1){
            mat[var1]=i;
            var1++;
        }
    }printf("BFS from node %d: \nNode 0\n",pos);
    pos++;
    do{
        tmp = mat[var2];
        for(int i=0;i<Vfil&&Vcol;i++){
            if(matrix[tmp][i]!=-1){
                printf("BFS from node %d: \n%d -> %d \n",pos,tmp,i);
                pos++;
                for(int j = 0; j < Vfil&&Vcol; j++){
                    if(i == mat[j])
                        cont1++; 
                    }
                    if(cont1 == 0){
                        mat[var1]=i;
                        var1++; 
                    }
            }
        }
        var2++;
    }while(var2!=Vfil&&Vcol);
    return 0; 
} 



