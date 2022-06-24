#include<stdio.h>
#include<fcntl.h>
#include<string.h>
int main(){
	FILE* fid;
	char *lexes[100],*keys[20],*sps[50],*id[50];
	char *keywords[]= {"for","while","int","char","float","if","else","void"};
	int lenkey = sizeof(keywords)/sizeof(keywords[0]);
	char *spsym[]={"+","=","-","?",":",";"};
	int lensps = sizeof(spsym)/sizeof(spsym[0]);
	char str[50];
	fid = fopen("simple.c","r");
	int count=0,i;
	while(fgets(str,50,fid)!=NULL){
		lexes[count]= str;
		printf("%s\n",lexes[count]);
		count++;
		}
	for(i=0;i<count;i++){
		int j=0,k=0;
		while(j<lenkey && k<lensps){
			if(lexes[i]==keywords[j]){
				keys[i]=lexes[i];
			}
			else if(lexes[i]==spsym[k]){
				sps[i]=lexes[i];
			}
			else{
				id[i]=lexes[i];
				}
		k++;
		j++;
		}
	}
	printf("Keywords:\n");
	for(i=0;i<=sizeof(keys)/sizeof(keys[0]);i++){
		printf("%s\n",keys[i]);
		}
	} 

