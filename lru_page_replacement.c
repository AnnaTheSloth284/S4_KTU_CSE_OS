#include<stdio.h>

int main()
{
    int position, l;
    int a = 0, b = 0, pf = 0;
    
    int nf;
    printf("Enter  the total no of frames: ");
    scanf("%d",&nf);
    int frames[nf];
    int temp[nf];
   
    int np;
    printf("Enter the total no of pages: ");
    scanf("%d", &np);
    int pages[np];
    printf("Enter the page string: ");
    for (int i=0; i<np; i++)
    {
        scanf("%d", &pages[i]);
    }

    for(int m = 0; m < nf; m++){
            frames[m] = -1;
    }
    
    for(int n = 0; n < np; n++)
    {
            a = 0, b = 0;
            for(int m = 0; m < nf; m++)
            {
                if(frames[m] == pages[n])
                {
                        a = 1;
                        b = 1;
                        break;
                }
            }
            if(a == 0)
            {
                for(int m = 0; m < nf; m++)
                {
                    if(frames[m] == -1)
                    {
                        frames[m] = pages[n];
                        b = 1;
                        pf++;
                        break;
                    }
                }
            }
            if(b == 0)
            {
                for(int m = 0; m < nf; m++)
                {
                    temp[m] = 0;
                }
                for(int k = n - 1, l = 1; l <= nf - 1; l++, k--)
                {
                    for(int m = 0; m < nf; m++)
                    {
                        if(frames[m] == pages[k])
                        {
                            temp[m] = 1;
                        }
                    }
                }
                for(int m = 0; m < nf; m++)
                {
                    if(temp[m] == 0)
                        position = m;
                }
                frames[position] = pages[n];
                pf++;
            }
            
        //Printing the allocation
        printf("Page allocation at iteration %d: ",pages[n]);
        for(int j=0;j<nf;j++)
        {
            if(frames[j]==-1)
                printf("X ");
            else
                printf("%d ",frames[j]);
        }
        if(a==0|b==0)
            printf("  Page Fault\n");
        else
            printf("  No Page Fault\n");
    }
    printf("Total no of page faults: %d\n",pf);
    
    return 0;
}
