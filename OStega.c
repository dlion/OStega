/* Functions to OStega project.
 * thinking and created by Domenico Luciani aka DLion
 */
  
int imgStega(IplImage *img, char *msg)
{
    int wid = img->width;
    uchar *data = (uchar*)img->imageData;
    
    int j,k=0; 
    int len = strlen(msg);
    char *new_str = (char*)malloc((len+2)*sizeof(char));

    new_str[0] = '$';

    for(j=1; j <= len; j++)
        new_str[j] = msg[j-1];

    new_str[len+1] = '$';

    if(img->nChannels != 3)
        return -1;

    for(j=0,k=0; j < wid || k < (len+2); j+=3,k++)
        data[j*3] = new_str[k];

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
