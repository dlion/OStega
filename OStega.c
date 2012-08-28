int imgStega(IplImage *img, char *msg)
{
    int wid = img->width;
    uchar *data = (uchar*)img->imageData;
    
    int j,k=0; 
    int len = strlen(msg);


    if(img->nChannels != 3)
        return -1;

    for(j=0; j < wid; j+=3)
    {
        if(j == 0)
        {
            data[j*3] = '$';
            continue;
        }
        else
        { 
            if(k < len)
            {
                data[j*3] = msg[k];
                k++;
            }
            else
            {
                data[j*3] = '$';
                break;
            }
        }
    }

    return 0;
}
    
char *imgDestega(IplImage *img)
{
    int wid = img->width;
    uchar *data = (uchar*)img->imageData;
    
    int j,k=0;
    char find;
    char *buffer = NULL;

    for(j=0; j < wid; j+=3)
    {
        find = data[j*3];

        if(j == 0)
        {
            if(find != '$')
                exit(EXIT_FAILURE);
            else
                continue;
        }
        else
        {
            if(find == '$')
                break;
            else
            {
                buffer=(char*)realloc(buffer,(k+1)*sizeof(char));
                buffer[k] = find;
                k++;
            }
        }
    } 
    return buffer;
}
