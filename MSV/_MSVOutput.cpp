<<<<<<< HEAD
=======
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int $$state_num=0;
int $$pathNum=1;
int $$len_i=0;
int $$flag[100] = { 0 };
int $$length = 0, $$current = 0,$$firstTime=0;
void $$changeState()
{if ($$current == $$length){
$$length++; $$flag[$$length - 1] = 0;}
$$current++; }
struct aaa{
int x;
int y[10];
}
;

int main() {
while (true){
while ($$length > 0){
if ($$flag[$$length - 1] == 1){
$$length--;}
else {
$$flag[$$length - 1] = 1; break;}}
if ( ($$length == 0 && $$flag[0] == 1) || ($$current == 0 && $$firstTime==1)){break;}
$$current = 0;
printf("Path Number: %d",$$pathNum);
printf("\n");
struct aaa c[10];
c[2].x=1;
printf("state %d:", $$state_num);
printf("Global: ");
printf("\n");
$$state_num++;
printf("state %d:", $$state_num);
printf("Global: ");
printf("\n");
$$state_num++;
$$firstTime=1;
$$state_num=0;
printf("\n");
$$pathNum=$$pathNum+1;
}
return 0;
}
>>>>>>> 8c11ddbe184c7b17e1247683fd0a183b43d86d5d
