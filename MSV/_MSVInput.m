function f(int f_x)
{
	frame(f_x) and 
	(
		f_x:=f_x+1;
		x:=f_x
		)
		};
frame(x,y) and 
(
	int x<==0 and int y<==0 and skip;
	f(x);
	y:=4
		)