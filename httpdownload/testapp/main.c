#include "oal.h"
#include<time.h>
#include <windows.h>
int main()
{
    OAL_U32                  nSize_O = 0;
    OAL_U32                  nTotal = 0;
    OAL_S8                   Buffer[10000];
    HTTP_DOWNLOAD_HANDLE *   head;
    OAL_S8                    uri[512];
    clock_t start,finish;
    int i=1;
    char file_name[100];
#ifdef _HTTP_DEBUGGING_
    HTTPClientSetDebugHook(pHTTP, &HTTPDebug);
#endif
    OAL_InitNetwork();
    while(i>0)
    {
      printf("%d\n",i);
    sprintf(file_name,"%d.o",i);
    start=clock();
    strcpy(uri, "http://music.163.com/song/media/outer/url?id=65956&userid=452324232");
    head = OAL_httpDownloadOpen(uri);
    if (!head)
    {
        i--;
        continue;
    }
    nTotal = OAL_httpDownloadSize(head);
    printf("The total length of the file is:%d\n", nTotal);

        if(!OAL_httpDownloadSeek(head,5))
        {
            int toal=0;
            //printf("write");
            // Get the data until we get an error or end of stream code
            //printf("Each dot represents %d bytes:\n",HTTP_BUFFER_SIZE );
            FILE *fp = fopen(file_name, "wb+");
        if (fp) {
            do {
                nSize_O = OAL_httpDownloadRead(head, Buffer, 10000);
                if (nSize_O) {
                    toal+=nSize_O;
                    fwrite(Buffer, nSize_O, 1, fp);
                    printf("write size is : %d\n", nSize_O);
                }
                else {
                    printf("file is end.\n");
                }
            } while (nSize_O > 0);
            fclose(fp);
        }
        else
        {
            printf("open file failed");
        }
     }

    nTotal = OAL_httpDownloadSize(head);
    OAL_httpDownloadClose(head);

    finish=clock();
    OAL_log("The time is %f\n",(double)(finish-start)/CLOCKS_PER_SEC );
    i--;
  }
    OAL_UninitNetwork();

    return 0;
}
