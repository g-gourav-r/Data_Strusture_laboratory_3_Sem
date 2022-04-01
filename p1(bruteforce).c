#include<stdio.h>
#include<stdlib.h>

char str[100], pat[50], rep[50], ans[100];
int i,j,c,m,k,flag=0;

void strmat(){
    i=m=c=j=0;
    while(str[c]!='\0'){
        if(str[m]==pat[i]){
            i++;
            m++;
            if(pat[i]=='\0'){
                flag=1;
                for(k=0;rep[k]!='\0';k++,j++){
                    ans[j]=rep[k];
                    i=0;
                    c=m;
                }
            }
        }
        else{
            ans[j]=str[c];
            j++;
            c++;
        }
    }
    ans[j]='\0';
}

void main(){
    printf("Enter the string : ");
gets(str);
printf("Enter the pattern : ");
gets(pat);
printf("Enter the string to be replaced : ");
gets(rep);
strmat();
if(flag==1){
    puts(ans);
}
else{
    printf("String not found");
}
}
