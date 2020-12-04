class twoStacks
{
    int *arr;
    int size;
    int top1, top2;
public:
   twoStacks(int n=100){size = n; arr = new int[n]; top1 = -1; top2 = size;}
 
   void push1(int x);
   void push2(int x);
   int pop1();
   int pop2();
};

void twoStacks :: push1(int x)
{
    arr[++top1] = x;
}
   
void twoStacks ::push2(int x)
{
    arr[--top2];
}

int twoStacks ::pop1()
{
    if(top1!=-1){
        return arr[top1--];
    }
    return -1;
}


int twoStacks :: pop2()
{
    if(top2!=size){
        return arr[top2++];
    }
    return -1;
}