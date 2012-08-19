int imgStega(IplImage *img, char *msg, int step, char controll)
{
    int wid = img->width;
    int heig = img->height;
    int imgStep = img->widthStep;
    uchar *data = (uchar*)img->imageData;
    
    int i,j,k=0; 
    int len = strlen(msg);
    char lett;


    if(img->nChannels != 3)
        return -1;
    
    if(len > (wid*heig))
        return -2;
    
    if(step > heig || step > wid)
        return -3;
    
    if(len == 0)
        return -4;

    for(i=0; i < heig; i+=step)
    {
        for(j=0; j < wid; j+=step)
        {
            if(k < len)
            {
                lett = msg[k];
                data[i*imgStep+j*3] = lett;
                k++;
            }
            else if(k == len)
            {
                data[i*imgStep+j*3] = controll;
                k++;
            }
            else
                break;
        }
    }

    return 0;
}
    
char *imgDestega(IplImage *img,int step,char controll)
{
    int wid = img->width;
    int heig = img->height;
    int imgStep = img->widthStep;
    uchar *data = (uchar*)img->imageData;
    
    int i,j,k=0;
    char find;
    char *buffer = (char*)malloc(sizeof(char));
    *buffer = '\0';
    
    for(i=0; i < heig; i+=step)
    {
        for(j=0; j < wid; j+=step)
        {
            find = data[i*imgStep+j*3];
            
            if(find == controll)
                return buffer;
            else
            {
                buffer[k] = find;
                k++;
                buffer = (char*)realloc(buffer,k*sizeof(char));

            }
        }
    }
    free(buffer);
    return buffer;
}






                



            









