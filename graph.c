#include<stdio.h>
#include<stdlib.h>

#define MAX_VERTICES 10 // 최대 10개의 정점

typedef struct gNode{ 

    int vertex; // edge가 연결된 vertex
    struct gNode* link; // 다음 노드를 연결할 링크

} Node; // 인접리스트의 노드

typedef struct Graph{

    int num_of_vertices; // vertex 수 - search에 이용할 예정
    struct Node* adj_list; // 인접리스트 

} graphType;

void initializeGraph(graphType** g);
void insertVertex();
void insertEdge();
void DFS();
void BFS();
void printGraph();
void freeGraph();

void main(){

    char command;
    graphType* Graph = NULL;

    do{
    printf("---------------[2018068040]--------[Park Taehyun]---------------\n");
    printf("-------------------------Graph Searches-------------------------\n");
    printf("----------------------------------------------------------------\n");
    printf(" Initialize Graph   = z\n");
    printf(" Insert Vertex      = v         Insert Edge             = e\n");
    printf(" Depth Frist Search = d         Breath First Search     = b\n");
    printf(" Print Graph        = p         Quit                    = q\n");
    printf("----------------------------------------------------------------\n");

    scanf(" %c", &command);

    switch (command)
        {
    case 'z' :case 'Z': 
    initializeGraph(&Graph);
    break;
    
    case 'v' : case 'V':
    break;

    case 'e' : case 'E':
    break;

    case 'd' : case 'D':
    break;

    case 'b' : case 'B':
    break;

    case 'p' : case 'P':
    break;

    case 'q': case'Q':


    default:
        printf("<<<Concentration!!!!>>>\n\n");
        break;
        }

    } while(command != 'q' && command != 'Q');


    return;
}

void initializeGraph(graphType** g){
    
    *g = (graphType*) malloc (sizeof(graphType)); // 그래프타입의 공간 할당
    (*g)->num_of_vertices = 0; // 초기 정점 갯수 0개
    (*g)->adj_list = (Node*)malloc(sizeof(Node)*MAX_VERTICES); // 최대 정점 개수만큼 공간 할당
    (*g)->adj_list = NULL; // 초기화

}

void insertVertex(graphType* g){

    if(g->num_of_vertices == MAX_VERTICES){
        printf("adjList is full !!! \n");
        return;
    }

    (g->num_of_vertices)++; // 정점 갯수 1개 증가
}

void insertEdge(graphType*g, int startV, int endV){ // E(startV, endV)를 추가
    if(startV > g->num_of_vertices || endV > g->num_of_vertices){
        printf("non-existent vertex!\n");
    }
 
    // startV 기준 추가
    Node* newEdge1 = (Node*)malloc(sizeof(Node));
    newEdge1 ->link = NULL;
    newEdge1 ->vertex = endV;
    if((g->adj_list)[startV] == NULL){ // edge가 없는 vertex의 경우
        (g->adj_list)[startV] = newEdge1;
    }
    else{
        Node* p = *(g->adj_list[startV])
        while()
        (g->adj_list)[startV]
    }


}
