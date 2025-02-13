/*
Algo RBT()
{

if(root==null)
{
root=newnode;
newnode.color=black;
}
else
{
while(newnode!=root&&newnode.color==red && newnode.parent.color==red)
{
father=newnode.parent;
gandfather=father.parent;
if(father==left(grandfather))
{
uncle=right(grandfather);
if(uncle!=null && uncle.color==red)
{
uncle.color=black;
father.color=black;
grandfather.color=red;
newnode=grandfather;
}
else
{
if(newnode==right(father))
{
LR(father);
father=newnode;
}
RR(grandfather);
swap color(father,grandfather);
newnode=father;
}
}
else{
uncle=left(grandfather);
if(uncle!=null && uncle.color==red)
{
uncle.color=black;
father.color=black;
grandfather.color=red;
newnode=grandfather;
}
else
{
if(newnode==left(father))
{
RR(father);
father=newnode;
}
LR(grandfather);
swap color(father,grandfather);
newnode=father;
}
}
}
}

}
*/