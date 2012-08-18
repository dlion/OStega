#include <highgui.h>
#include <cv.h>
#include <string.h>

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        printf("%s <image_in>\n",argv[0]);
        return -1;
    }

    IplImage *in = cvLoadImage(argv[1]);
    
    if(in->nChannels != 3)
    {
        puts("Only RGB images");
        return -1;
    }

    int i,j,k=0;
    int height,width,step;
    uchar *data;
    char lett;

    height = in->height;
    width = in->width;
    step = in->widthStep;
    data = (uchar*)in->imageData;

    for(i=0; i < height; i++)
    {
        for(j=0; j < width; j++)
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

