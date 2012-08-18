#include <highgui.h>
#include <cv.h>
#include <string.h>

int main(int argc, char **argv)
{
    if(argc != 4)
    {
        printf("%s <image_in> <image_out> <message>\n",argv[0]);
        return -1;
    }

    IplImage *in = cvLoadImage(argv[1]);

    //Solo immagini RGB
    if(in->nChannels != 3)
    {
        puts("Only RGB images");
        return -1;
    }

    int i,j,k=0,lett;
    int height,width,step,channels;
    uchar *data;
    char *msg=argv[3];

    height = in->height;
    width = in->width;
    step = in->widthStep;
    channels = in->nChannels;
    data = (uchar*)in->imageData;

    for(i=0; i < height; i++)
    {
        for(j=0; j < width; j++)
        {
            if(k < strlen(msg))
            {
                lett = msg[k];
                data[i*step+j*channels] = lett; 
                k++;
            }
            else if(k == strlen(msg))
            {
                lett = '$';
                data[i*step+j*channels] = lett;
                k++;
            }
        }
    }

    
    cvSaveImage(argv[2],in);
    printf("Image %s steganographed correctly to %s\n",argv[1],argv[2]);
    cvReleaseImage(&in);
    return 0;
}

    



            

