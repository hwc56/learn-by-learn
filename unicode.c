#include <stdio.h>
#include <stdlib.h>
int     main(int  argc,char  *argv[])
{
#if 0
    char hexstr[7]="E5858D";
    char hexstr1[7]="E8B4B9";
    char hz[7];
    int v1,v2,v3;
    sscanf(hexstr,"%2X%2X%2X",&v1,&v2,&v3);
    hz[0]=(char)v1;hz[1]=(char)v2;
    hz[2]=(char)v3;
    //hz[3]=0;

    sscanf(hexstr1,"%2X%2X%2X",&v1,&v2,&v3);
    hz[3]=(char)v1;hz[4]=(char)v2;
    hz[5]=(char)v3;
    hz[6]=0;
    printf("%s\n",hz);//
#endif
    char  hz[7];
    int   v[6];
    char  hexstr[]="360\xE5\x85\x8D\xE8\xB4\xB9WiFi-AP";//"\xE5\x85\x8D\xE8\xB4\xB9";
    printf("%s\n",hexstr);//
    //sscanf(hexstr,"%2X%2X%2X%2X%2X%2X",&v[0],&v[1],&v[2],&v[3],&v[4],&v[5]);
    //hz[6]=0;
    //memcpy(hz,(char *)v,6);
    //printf("%s\n",hz);//

    return  0;
}
