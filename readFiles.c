#include <stdio.h>
#include <stdlib.h>

int main(void)
{
   FILE *fp;
   int length;
   char * buffer = 0;

   fp = fopen("inputs.mat", "rb");

   if(fp){
        fseek (fp, 0, SEEK_END);
        length = ftell (fp);
        fseek (fp, 0, SEEK_SET);

        buffer = malloc (length);

        if(buffer){
            fread (buffer, 1, length, fp);

            size_t len = strlen(buffer);
            char * str = malloc(len + 1 + 1);
            strcpy(str, buffer);
            str[len] = '#';
            str[len + 1] = '\0';

            printf("%s\n", str);

            int c = 0;

            do{

                printf("\n----\n");
                const char * p1 = strstr(str, "columns: ")+9;
                const char * p2 = strstr(p1, "#");

                len = p2-p1;
                char *res = (char*)malloc(sizeof(char)*(len+1));
                strncpy(res, p1, len);
                res[len] = '\0';
                printf("%s\n", res);

                char *ftok;
                int count = 0;
                ftok = strtok (res,"\n");
                printf ("%s\n",ftok);

                int n = atoi(ftok);
                printf ("%i\n",n);
                int * arr = malloc(sizeof(int)*n);

                while (ftok != NULL)
                {
                    if(count != 0)
                    {
                        arr[count - 1] = atoi(ftok);
                    }
                    ftok = strtok (NULL, " ");
                    count++;
                }

                printf("O array: \n");

                int j = 0;
                for( j = 0; j < n; j++) {
                    printf("%d ", arr[j]);
                }
                printf("\n");

                strcpy(str, p2);

            } while(strlen(str) > 1);
        }
   }

   fclose(fp);
   return 0;
}
