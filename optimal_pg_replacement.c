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
    

    int nextOccurrences[10];//An array storing the indices of the next occurrences of each page in the future reference string. Used to find the farthest future reference for each page.
    
    //Pages
    int np;
    printf("Enter no of pages:");
    scanf("%d",&np);
    int pages[np];
    printf("Enter the page string:");
    for(int i=0;i<np;i++)
        scanf("%d",&pages[i]);
    
    //Page faults
    int pf = 0;
    
    //Iterating thru reference string for each page
    for(int i=0;i<np;i++)
    {
        int found=0;
        int currentpage=pages[i];
        for(int j=0;j<nf;j++)
        {
            //If page is found
            if(currentpage==frames[j])
            {
                found=1;
                break;
            }
        }
        
        //If page is not found
        if(found==0)
        {
            int farthestFutureIndex=0;//Keeps track of the farthest future reference index for the current page being evaluated. Helps determine the page in frames with the longest time until the next use.
            int pageToReplaceIndex=0;//Holds the index of the frame to be replaced. Determined based on the farthest future reference, indicating the least needed page.
            for(int j=0;j<nf;j++)
            {
                int nextOccurrenceFound=0;//It indicates whether the next occurrence of the current page is found in the future references. If not found, the page is a candidate for replacement.
                for(int k=i+1;k<np;k++)
                {
                    if(pages[k]==frames[j])
                    {
                        nextOccurrences[j]=k;
                        nextOccurrenceFound=k;
                        break;
                    }
                }
                if(nextOccurrenceFound==0)
                {
                    pageToReplaceIndex=j;
                    break;
                }
                else
                {
                    if(nextOccurrences[j]>farthestFutureIndex)
                    {
                        farthestFutureIndex=nextOccurrences[j];
                        pageToReplaceIndex=j;
                    }
                }

            }
            frames[pageToReplaceIndex]=currentpage;
            pf++;
        }
        
        //Printing the allocation
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
