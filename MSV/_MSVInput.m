<<<<<<< HEAD
frame(a) and
(
int a[2] and skip;
a[0]<==4 and skip;
a[1]<==1 and skip
)

=======
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
>>>>>>> fed92026bdecb3683e813bc376141e739f7de386
