#include<stdio.h>

int main()
{
      int reference_string[20], page_faults = 0, m, n, s, pages, frames,old_fault_no=0;

      printf("\nEnter Total Number of Pages:\t");
      scanf("%d", &pages);
      printf("\nEnter values of Reference String:\n");
      for(m = 0; m < pages; m++)
      {
            printf("Value No. [%d]:\t", m + 1);
            scanf("%d", &reference_string[m]);
      }
      printf("\nEnter Total Number of Frames:\t");
      {
            scanf("%d", &frames);
      }
      int temp[frames];
      for(m = 0; m < frames; m++)
      {
            temp[m] = -1;
      }
      for(m = 0; m < pages; m++)
      {
            s = 0;
            old_fault_no=page_faults;

            for(n = 0; n < frames; n++)
            {
                  if(reference_string[m] == temp[n])
                  {
                        s++;
                        page_faults--;//found number in temp
                  }
            }
            page_faults++;

            if((page_faults < frames) && (s == 0))
            {
                  temp[m] = reference_string[m];
            }
            else if(s == 0)
            {
                  temp[(page_faults - 1) % frames] = reference_string[m];
            }
            printf("\n");
            for(n = 0; n < frames; n++)
            {
                  printf("%d\t", temp[n]);
            }
            if(old_fault_no!=page_faults)
            {
              printf("*\n");
            }
            else
              printf("\n");
            //old_fault_no=page_faults;
      }
      printf("\nTotal Page Faults:\t%d\n", page_faults);
      return 0;
}
