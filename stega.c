#include <highgui.h>
#include <cv.h>
#include <string.h>
#include "OStega.h"
#include <stdlib.h>

int main(int argc, char **argv)
{
    IplImage *in;
    char *img,*message;
    int mode,result;
    
    if(argc <= 2)
    {
        printf("Usage: %s <mode> <image_in> <<message>>\n",argv[0]);
        return -1;
    }

    mode = atoi(argv[1]);

    if(mode != 1 && mode != 2 )
    {
        printf("You can specify what do you do.\n",argv[0]);
        return -1;
    }

    in = cvLoadImage(argv[2],CV_LOAD_IMAGE_COLOR);
    
    if(mode == 1 && argc == 4)
    {
        message = argv[3];

        if(strlen(message) >= (in->width*in->height))
        {
            puts("Message too long\n");
            return -1;
        }
        else
        {
            result = imgStega(in,message);
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
    else if(mode == 2 && argc == 3)
            printf("Il messaggio trovato e': %s\n",imgDestega(in));
    
    cvReleaseImage(&in);
    return 0;
}





            

