#include<stdio.h>
#include<stdlib.h>
int main()
{
    //Frames
    int nf;
    printf("Enter no of frames:");
    scanf("%d",&nf);
    int frames[nf];
    for(int i=0;i<nf;i++)
        frames[i]=-1;
    
    //Pages
    int np;
    printf("Enter no of pages:");
    scanf("%d",&np);
    int pages[np];
    printf("Enter the page string:");
    for(int i=0;i<np;i++)
        scanf("%d",&pages[i]);
    
    int pf=0,last=0;
    for(int i=0;i<np;i++)
    {
        int found=0;
        int currentpage=pages[i];
        for(int j=0;j<nf;j++)
        {
            if(frames[j]==currentpage)
            {
                found=1;
                break;
            }
        }
        if(found==0)
        {
            frames[last]=currentpage;
            last=(last+1)%nf;
            pf++;
        }
        printf("Page allocation at iteration %d: ",currentpage);
        for(int j=0;j<nf;j++)
        {
            if(frames[j]==-1)
                printf("X ");
            else
                printf("%d ",frames[j]);
        }
        if(found==1)
            printf("  No Page Fault\n");
        else
            printf("  Page Fault\n");
    }
    printf("Total no of page faults: %d\n",pf);
}
