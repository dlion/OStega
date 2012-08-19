int imgStega(IplImage *img, char *msg)
{
    int wid = img->width;
    uchar *data = (uchar*)img->imageData;
    
    int j,k=0; 
    int len = strlen(msg);
    char lett;


    if(img->nChannels != 3)
        return -1;
    
    if(len > 10)
        return -2;

    if(len == 0)
        return -4;

    for(j=0; j < wid; j+=3)
    {
        if(k < len)
        {
            lett = msg[k];
            data[j*3] = lett;
            k++;
        }
        else if(k == len)
        {
            data[j*3] = '~';
            k++;
        }
        else
            break;
    }

    return 0;
}
    
char *imgDestega(IplImage *img)
{
    int wid = img->width;
    uchar *data = (uchar*)img->imageData;
    
    int j,k=0;
    char find;
    char *buffer = (char*)malloc(sizeof(char));
    *buffer = '\0';
    
    for(j=0; j < wid; j+=3)
    {
        find = data[j*3];
        
        if(k >= 10)
            exit(EXIT_FAILURE);
         if(find == '~')
            return buffer;
        else
        {
            buffer[k] = find;
            k++;
            buffer = (char*)realloc((void*)buffer,k*sizeof(char));
        }
    }
    return buffer;
}






                



            









