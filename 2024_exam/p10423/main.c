#include<stdio.h>
#include"paintSurface.h"

void paintSurface(int *start,int *p1,int *p2,int L,int W,int H);

int main(){
    int i,j,k,L,W,H,n,x1,x2,y1,y2,z1,z2;
    scanf("%d%d%d",&L,&W,&H);
    int cuboid[L][W][H];
    for(i=0;i<L;i++){
        for(j=0;j<W;j++){
            for(k=0;k<H;k++){
                cuboid[i][j][k]=0;
            }
        }
    }
    scanf("%d",&n);
    while(n--){
        scanf("%d%d%d%d%d%d",&x1,&y1,&z1,&x2,&y2,&z2);
        paintSurface(&cuboid[0][0][0],&cuboid[x1][y1][z1],&cuboid[x2][y2][z2],L,W,H);
    }
    for(i=0;i<L;i++){
        for(j=0;j<W;j++){
            for(k=0;k<H;k++){
                printf("%d",cuboid[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
