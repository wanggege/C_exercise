
void reverse(int array[32])
{
    int i,j,tmp;

    for (i = 0,j = 31; i < j; i++,j--) 
    {
        tmp = array[i];
        array[i] = arrar[j];
        array[j] = tmp;

    }

    for (i = 0; i < 4; i++) 
    {
        printf("%d",array[i]);
    }

    puchar('\n');
}



