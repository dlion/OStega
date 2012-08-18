#include <highgui.h>
#include <cv.h>
#include <string.h>

int main(int argc, char **argv)
{
    IplImage *in;
    int i,j,k=0,lett;
    int height,width,step;
    uchar *data;
    char *msg;

    //Controllo argc
    if(argc != 4)
    {
        printf("%s <image_in> <image_out> <message>\n",argv[0]);
        return -1;
    }

    //Carico l'immagine
    in = cvLoadImage(argv[1]);

    //Accetto solo immagini RGB
    if(in->nChannels != 3)
    {
        puts("Only RGB images");
        return -1;
    }

    //Variabili utili
    msg = argv[3];
    height = in->height;
    width = in->width;
    step = in->widthStep;
    data = (uchar*)in->imageData;

    //Scansiono l'intera immagine
    for(i=0; i < height; i+=10)
    {
        for(j=0; j < width; j+=10)
        {
            if(k < strlen(msg))
            {
                lett = msg[k];
                data[i*step+j*3] = lett; 
                k++;
            }
            else if(k == strlen(msg))
            {
                lett = '$';
                data[i*step+j*3] = lett;
                k++;
            }
        }
    }

    //Sembra dare problemi con i formati jpeg a causa della compressione
    cvSaveImage(argv[2],in);
    printf("Image %s steganographed correctly to %s\n",argv[1],argv[2]);
    cvReleaseImage(&in);
    return 0;
}

    



            

