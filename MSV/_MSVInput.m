function f(int f_x,int RValue)
{
	frame(f_x) and 
	(
		x:=f_x+1;
		RValue:=f_x
		)
		};
frame(x)and
(
int x<==0 and skip;
x:=f(x,RValue)
)
