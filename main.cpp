#include <stdio.h>
int readFile(const char *fname, char *buffer, int bufferLen)
{
	int retLen = 0;
	FILE *f;
	f = fopen(fname, "r");
	if(f) {
		retLen= fread(buffer, 1, bufferLen, f);
		buffer[retLen] = 0;
		fclose(f);
	}
	if(retLen <= 0){ 
		printf("读取文件错误，或者空文件！");
		return 0;
	}
	return retLen;
}
int main(int argc,char **argv)
{
	char buf[255];
	char *fname = argv[2];
	int retLen = readFile(fname,buf, 255);
	if(argv[1][1] == 'w'){
		int wordCount = 0;
		for(int i = 0;i < retLen;i++){
			if(buf[i] == ',' || buf[i] == ' ' || buf[i] == '.')
				wordCount++; 
		}
		printf("Word count : %d",wordCount);
	}
	if(argv[1][1] == 'c')
		printf("Charactor count : %d",retLen);
	getchar();
	return 0;
}
