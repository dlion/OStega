#include <highgui.h>
#include <cv.h>
#include <string.h>

int main(int argc, char **argv)
{
    IplImage *in;
    int i,j,k=0,height,width,step;
    uchar *data;
    char lett;


    if(argc != 2)
    {
        printf("%s <image_in>\n",argv[0]);
        return -1;
    }

    in = cvLoadImage(argv[1]);
    
    if(in->nChannels != 3)
    {
        puts("Only RGB images");
        return -1;
    }

    height = in->height;
    width = in->width;
    step = in->widthStep;
    data = (uchar*)in->imageData;

    for(i=0; i < height; i+=10)
    {
        for(j=0; j < width; j+=10)
        {
            lett = data[i*step+j*3];
            if(lett == '$')
            {
                i = height;
                j = width;
            }
            else
            {
                printf("TROVATA: %c\n",lett);
            }
        }
    }
    cvReleaseImage(&in);

    return 0;
}

