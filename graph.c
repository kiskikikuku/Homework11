#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 10
#define MAX_QUEUE_SIZE 10

int visited[MAX_VERTICES]; // 탐색 시 방문 노드 기록용 배열

typedef struct Node{
    int vertex;                     //도착vertex 
    struct Node* link;              //링크
} Node;

typedef struct graphType{
    int n;                          //그래프에 있는 vertex 수
    Node* adjList[MAX_VERTICES];    //인접리스트 
} graphType;

graphType* initializeGraph();
void insertVertex(graphType* g);
void insertEdge(graphType* g, int startV, int endV);
void printList(graphType* g);
void DFS(graphType* g, int v);
void BFS(graphType* g, int v);
void freeGraph(graphType* g);


/* queue for BFS */
int queue[MAX_VERTICES];            // BFS 에 쓰일 Queue
int front = -1;
int rear = -1;               // 초기화
int deQueue();                      // 큐 
void enQueue(int vertex);           // 큐 삽입

int main()
{   
    int startV, endV;
    char command;
    int d;
    graphType *g = initializeGraph();
    
    do{
    printf("\n---------------[2018068040]--------[Park Taehyun]---------------\n");
    printf("-------------------------Graph Searches-------------------------\n");
    printf("----------------------------------------------------------------\n");
    printf(" Initialize Graph   = z\n");
    printf(" Insert Vertex      = v         Insert Edge             = e\n");
    printf(" Depth Frist Search = d         Breath First Search     = b\n");
    printf(" Print Graph        = p         Quit                    = q\n");
    printf("----------------------------------------------------------------\n");

    scanf(" %c", &command);

    switch (command){

    case 'z' :case 'Z': 
    initializeGraph(g);
    break;
    
    case 'v' : case 'V':
    insertVertex(g);
    break;

    case 'e' : case 'E':
    printf("input your edge (startV, endV) : ");
    scanf(" %d %d", &startV, &endV);
    insertEdge(g, startV, endV);
    break;

    case 'd' : case 'D':
    printf("start vertex : ");
    scanf(" %d", &d);
    DFS(g, d);
    break;

    case 'b' : case 'B':
    printf("start vertex : ");
    scanf(" %d", &d);
    BFS(g, d);
    break;

    case 'p' : case 'P':
    printList(g);
    break;

    case 'q': case'Q':
    freeGraph(g);
    free(g);
    break;


    default:
        printf("<<<Concentration!!!!>>>\n\n");
        break;
}

    } while(command != 'q' && command != 'Q');

    return 0;


}

graphType* initializeGraph(){

    graphType* g = (graphType*)malloc(sizeof(graphType));  // 공간 할당

    g->n=0;                                                //vertex 수 초기화

    for(int i=0;i<MAX_VERTICES;i++)                        //인접리스트 값 초기화
        g->adjList[i]=NULL;

    return g;
}

void insertVertex(graphType* g){

    if(((g->n)+1)>MAX_VERTICES){            // 최대 노드 수 초과

        printf("adjList is full !!! \n"); 
        return;

    }

    g->n++;                                 // 정점 1개 추가
}

void insertEdge(graphType* g, int startV, int endV){
    
    if(startV>=g->n||endV>=g->n){                   // 존재하지 않는 정점 접근
         printf("non-existent vertex!\n");
        return;
    }

    // 시작점 기준
    Node* node = (Node*)malloc(sizeof(Node));       // 추가할 노드 할당 (edge)
    node->vertex = endV;                            // 시작점 -> 도착점
    node->link = g->adjList[startV];                // 노드의 링크 설정
    g->adjList[startV] = node;                  // 노드를 시작정점의 리스트에 추가
        
    
}

void printList(graphType* g){

    if(g->n == 0){                                  // 공백 그래프
        printf("empty graph!!!\n");
    }

    for(int i=0;i<g->n;i++){                        // 존재하는 정점 수만큼 반복                 
        Node* p=g->adjList[i];                      
        printf("vertex [%d]'s edge : ", i);

        while(p!=NULL){
            printf("(%d, %d) ",i, p->vertex);       // edge 목록 출력
            p=p->link;
        }
        printf("\n");
    }

}

void DFS(graphType* g, int v){ // DFS (recursive)
    
    if(v<0 || v> 9 ){                           // 부적절한 vertex 값 입력
        printf("vertex index error !!! \n");
        return;
    }

    Node* d;
    visited[v] = 1;             // 정점 v 방문 기록
    printf("%d -> ", v);        // 방문한 정점 출력

    for (d = g->adjList[v]; d; d = d->link)     
        if(!visited[d->vertex]){                // 모든 노드를 방문할 때 까지
            DFS(g, d->vertex);                  // 순환 호출
    }

}

void freeGraph(graphType* g){
                                                          
    for(int i=0; i<g->n; i++)                        //인접리스트 할당 해제
        free(g->adjList[i]);

}

int deQueue(){

    if (rear == front || front == MAX_VERTICES - 1){
        return -9999; // 공백 큐의 경우 -9999 반환
    }

    return queue[++front]; // 원소 반환
}

void enQueue(int vertex){
    if(rear >= MAX_VERTICES - 1){ // 큐가 꽉찬 경우
        printf("Queue is Full!!!\n");
        return;   
    }

    queue[++rear] = vertex;       // 큐에 원소 삽입
}

void BFS(graphType* g, int v){

    if(v<0 || v> 9 ){                           // 부적절한 vertex 값 입력
        printf("vertex index error !!! \n");
        return;
    }

    Node* p;
    front, rear = -1;                           // queue 초기화
          
    printf(" [ %d ] ", v);                      // 시작 노드 방문하며 시작
    visited[v] = 1;                             // 방문여부 기록
    enQueue(v);                                 // 큐에 v 삽입

    while(1){
        v = deQueue();
        if(v == -9999)
            break;                              // 공백 큐 -> 중단
        
        for(p = g->adjList[v]; p; p->link){      // v의 인접 vertex 전부 방문
            if(!visited[p->vertex]){             // 미방문 노드의 경우
                printf("-> [ %d ] ", p->vertex); // 방문
                enQueue(p->vertex);              // 큐에 삽입
                visited[p->vertex] = 1;          // 방문여부 기록
            }

        }

    }


}