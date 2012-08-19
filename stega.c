#include <highgui.h>
#include <cv.h>
#include <string.h>
#include "OStega.c"
#include <stdlib.h>

int main(int argc, char **argv)
{
    IplImage *in;
    char *img,*message,*simbol,limit;
    int mode,step,result;
    
    if(argc < 5)
    {
        printf("Usage: %s <mode> <image_in> <step> <simbol> <<message>>\n",argv[0]);
        return -1;
    }

    mode = atoi(argv[1]);

    if(mode != 1 && mode != 2 )
    {
        printf("You can specify what do you do.\n",argv[0]);
        return -1;
    }

    step = atoi(argv[3]);

    simbol = argv[4];
    limit = simbol[0];

    in = cvLoadImage(argv[2],CV_LOAD_IMAGE_COLOR);
    
    if(mode == 1 && argc == 6)
    {
        message = argv[5];

        if(strlen(message) >= (in->width*in->height))
        {
            puts("Message too long\n");
            return -1;
        }
        else
        {
            result = imgStega(in,message,step,limit);
            if(result == 0)
            {
                puts("Message hidden");
                cvSaveImage("ImageHidden.bmp",in,0);
            }
            else
            {
                printf("Error: %d\n",result);
                return -1;
            }
        }
    }
    else if(mode == 2 && argc == 5)
            printf("Il messaggio trovato e': %s\n",imgDestega(in,step,limit));
    
    cvReleaseImage(&in);
    return 0;
}





            

